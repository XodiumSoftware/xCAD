// SheetMetalSample.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "brx_sm_utils.h"


namespace BrxSheetMetalSample {

bool FspComparator::operator()(const AcDbFullSubentPath & lhs, const AcDbFullSubentPath & rhs) const
{
    assert(lhs.objectIds().length() == 1 && rhs.objectIds().length() == 1);
    if (lhs.objectIds().length() != 1 || rhs.objectIds().length() != 1)
        return false;

    std::tuple<AcDbObjectId, int> lhsTuple(lhs.objectIds().first(), static_cast<int>(lhs.subentId().index()));
    std::tuple<AcDbObjectId, int> rhsTuple(rhs.objectIds().first(), static_cast<int>(rhs.subentId().index()));
    return lhsTuple < rhsTuple;
}

bool isCommandFailed(int rt)
{
    static int g_errorCode = 79;
    resbuf sym;
    acedGetVar(_T("ERRNO"), &sym);
    int errNo = sym.resval.rint;
    return rt != RTNORM || errNo == g_errorCode;
}

bool isCommandFinishedWithWarnings(int rt)
{
    static int g_warningCode = 1;
    resbuf sym;
    acedGetVar(_T("ERRNO"), &sym);
    int errNo = sym.resval.rint;
    return rt == RTNORM && errNo == g_warningCode;
}

AcString getSolidName(const AcDbObjectId & solidId)
{
    constexpr size_t nameLength = 255;
    ACHAR solidName[nameLength];

    if (!solidId.handle().getIntoAsciiBuffer(solidName, nameLength))
    {
        return {};
    }

    return {solidName};
}

Acad::ErrorStatus getSideFaces(const AcDbFullSubentPath & sideFaceFsp,
                               AcDbFullSubentPathArray & aSideFacesFsp)
{
    aSideFacesFsp.removeAll();
    BrxSmSideSelection sideSelector;
    Acad::ErrorStatus res = sideSelector.setFace(sideFaceFsp);
    if (res != Acad::eOk)
        return res;

    res = sideSelector.run();
    if (res != Acad::eOk)
        return res;

    return sideSelector.getSideFaces(aSideFacesFsp);
}

Acad::ErrorStatus getExternalSideFaces(const AcDbObjectId & blockId,
                                       const AcDbObjectId & solidId,
                                       AcDbFullSubentPathArray & aSideFacesFsp)
{
    AcDbFullSubentPath externalSideFace;
    auto res = getExternalSideFace(blockId, solidId, externalSideFace);
    if (Acad::ErrorStatus::eOk != res)
        return res;
    return getSideFaces(externalSideFace, aSideFacesFsp);
}

Acad::ErrorStatus getSideBottomFlangeFaces(const AcDbFullSubentPath & sideFaceFsp,
                                           const AcDbObjectIdArray & aFlangeIds,
                                           AcDbFullSubentPathArray & aSideBottomFlangeFaces)
{
    aSideBottomFlangeFaces.removeAll();
    AcDbFullSubentPathArray aSideFacesFsp;
    Acad::ErrorStatus res = getSideFaces(sideFaceFsp, aSideFacesFsp);
    if (res != Acad::eOk)
        return res;

    std::set<AcDbFullSubentPath, FspComparator> bottomFlangeFaces;
    for (const AcDbObjectId & flangeId : aFlangeIds)
    {
        BrxSmFlangeFeature flangeFeature(flangeId);
        if (flangeFeature.isNull())
            return Acad::eInvalidInput;

        AcDbFullSubentPathArray aBottomFaces = flangeFeature.getFaces(BrxSmFlangeFeature::eBottomFaces);
        for (const AcDbFullSubentPath & bottomFace : aBottomFaces)
        {
            bottomFlangeFaces.insert(bottomFace);
        }
    }

    for (const AcDbFullSubentPath & sideFace : aSideFacesFsp)
    {
        if (bottomFlangeFaces.find(sideFace) != bottomFlangeFaces.end())
            aSideBottomFlangeFaces.append(sideFace);
    }

    return Acad::eOk;
}

Acad::ErrorStatus buildAdjacencyMap(const AcDbObjectId & blockId,
                                    const AcDbObjectId & solidId,
                                    FeatureAdjacencyMap & featureAdjacencyMap)
{
    featureAdjacencyMap.clear();

    AcDbFullSubentPathArray aSideFacesFsp;
    auto res = getExternalSideFaces(blockId, solidId, aSideFacesFsp);
    if (Acad::ErrorStatus::eOk != res)
        return res;

    for (const auto & faceFsp : aSideFacesFsp)
    {
        const auto aFeaturesOnFace = BrxIFeature::getAllFeatures(faceFsp);

        BrxSheetMetal::BrxFaceFeatureAdjacencyArray aFaceFeatureAdjacency;
        res = BrxSheetMetal::getAdjacentFeatures(faceFsp, aFaceFeatureAdjacency);
        if (Acad::ErrorStatus::eOk != res)
            return res;

        for (const auto & featureId : aFeaturesOnFace)
        {
            for (const auto & adj : aFaceFeatureAdjacency)
            {
                // if feature equals to adjacent feature it means that edge is internal
                // and belongs to two adjacent faces of same feature,
                // we are not interested in such
                AcDbObjectIdArray aFilteredAdjacentFeatures;
                for (const auto & adjFeature : adj.m_aOtherFeatureIds)
                {
                    if (featureId != adjFeature)
                        aFilteredAdjacentFeatures.append(adjFeature);
                }

                if (aFilteredAdjacentFeatures.isEmpty())
                    continue;

                BrxSheetMetal::BrxFeatureAdjacency filteredAdj(adj, faceFsp);
                filteredAdj.m_aOtherFeatureIds = aFilteredAdjacentFeatures;
                featureAdjacencyMap[featureId].append(filteredAdj);
            }
        }
    }

    return Acad::ErrorStatus::eOk;
}

Acad::ErrorStatus getArea(AcDbFullSubentPath faceFsp, double & surfaceArea)
{
    AcBrFace face;
    AcBr::ErrorStatus res = face.setSubentPath(faceFsp);
    if (res != AcBr::eOk)
    {
        surfaceArea = -1.0;
        return Acad::eInvalidInput;
    }

    res = face.getSurfaceArea(surfaceArea);
    if (res != AcBr::eOk)
    {
        surfaceArea = -1.0;
        return Acad::eInvalidInput;
    }
    return Acad::eOk;
}

Acad::ErrorStatus getSideArea(const AcDbFullSubentPathArray & aFacesFsp, double & sideSurfaceArea)
{
    sideSurfaceArea = 0.0;
    for (const AcDbFullSubentPath & faceFsp : aFacesFsp)
    {
        double partialSurfaceArea = 0.0;
        Acad::ErrorStatus res = getArea(faceFsp, partialSurfaceArea);
        if (res != Acad::eOk)
        {
            sideSurfaceArea = -1.0;
            return Acad::eInvalidInput;
        }
        sideSurfaceArea += partialSurfaceArea;
    }
    return Acad::eOk;
}

Acad::ErrorStatus getModelSpaceId(AcDbDatabase * pDb, AcDbObjectId & blockId)
{
    AcDbObjectPointer<AcDbBlockTable> pBT(pDb->blockTableId(), AcDb::kForRead);
    if (!pBT)
        return Acad::eInvalidInput;

    return pBT->getAt(ACDB_MODEL_SPACE, blockId);
}

Acad::ErrorStatus getBlockTableRecordIterator(const AcDbBlockTableRecord * pBTR,
                                              std::unique_ptr<AcDbBlockTableRecordIterator> & pUniqueBTRIter)
{
    AcDbBlockTableRecordIterator * pBTRIter = nullptr;
    Acad::ErrorStatus res = pBTR->newIterator(pBTRIter);
    if (res != Acad::eOk)
        return res;

    pUniqueBTRIter.reset(pBTRIter);
    return Acad::eOk;
}

Acad::ErrorStatus getSolidIdsFromDatabase(AcDbDatabase * pDb, AcDbObjectIdArray & aSolidIds)
{
    aSolidIds.removeAll();
    AcDbObjectId modelSpaceId;
    Acad::ErrorStatus res = getModelSpaceId(pDb, modelSpaceId);
    if (res != Acad::eOk)
        return res;

    AcDbObjectPointer<AcDbBlockTableRecord> pModelSpace(modelSpaceId, AcDb::kForRead);
    if (!pModelSpace)
        return Acad::eInvalidInput;

    std::unique_ptr<AcDbBlockTableRecordIterator> pBtrIter;
    res = getBlockTableRecordIterator(pModelSpace, pBtrIter);
    if (res != Acad::eOk)
        return res;

    if (!pBtrIter)
        return Acad::eInvalidInput;

    for (pBtrIter->start(); !pBtrIter->done(); pBtrIter->step())
    {
        AcDbObjectId entId;
        pBtrIter->getEntityId(entId);
        AcDbObjectPointer<AcDbEntity> pEnt(entId, AcDb::kForRead);
        AcDb3dSolid * pSolid = AcDb3dSolid::cast(pEnt);
        if (pSolid)
            aSolidIds.append(pEnt->objectId());
    }

    return Acad::eOk;
}

Acad::ErrorStatus getHardEdges(const AcDbObjectId & blockId,
    const AcDbObjectId & solidId,
    AcDbFullSubentPathArray & aHardEdges)
{
    aHardEdges.removeAll();
    AcDbObjectIdArray aFlangeIds = getFeatures<BrxSmFlangeFeature>(blockId, solidId);
    if (aFlangeIds.isEmpty())
        return Acad::eOk;

    std::map<AcDbFullSubentPath, AcDbObjectId, FspComparator> faceFlangeIdMap;
    for (const AcDbObjectId & flangeId : aFlangeIds)
    {
        BrxSmFlangeFeature flange(flangeId);
        if (flange.isNull())
            return Acad::eInvalidInput;

        AcDbFullSubentPathArray aFlangeFaces = flange.getFeatureEntities();
        for (const AcDbFullSubentPath & flangeFace : aFlangeFaces)
        {
            faceFlangeIdMap[flangeFace] = flangeId;
        }
    }

    // Edge is supposed to be thickness if its adjacent faces belong to different flanges.
    // That is if the edge is already in edgeFlangeIdMap with its corresponding flange id
    // and we extract the same edge from iterating over the loop of traversed face then 
    // extracted edge is hard edge if traversed face belongs to different flange than the 
    // one that is already in edgeFlangeIdMap for extracted edge
    std::map<AcDbFullSubentPath, AcDbObjectId, FspComparator> edgeFlangeIdMap;
    for (const std::pair<AcDbFullSubentPath, AcDbObjectId> & flangeFaceFlangeId : faceFlangeIdMap)
    {
        AcBrFace face;
        AcBr::ErrorStatus res = face.set(flangeFaceFlangeId.first);
        if (res != AcBr::eOk)
            return Acad::eInvalidInput;

        AcBrFaceLoopTraverser faceLoopTraverser;
        for (faceLoopTraverser.setFace(face); !faceLoopTraverser.done(); faceLoopTraverser.next())
        {
            AcBrLoopEdgeTraverser loopEdgeTraverser;
            for (loopEdgeTraverser.setLoop(faceLoopTraverser); !loopEdgeTraverser.done(); loopEdgeTraverser.next())
            {
                AcBrEdge edge;
                res = loopEdgeTraverser.getEdge(edge);
                if (res != AcBr::eOk)
                    return Acad::eInvalidInput;

                AcDbFullSubentPath edgeFsp;
                res = edge.get(edgeFsp);
                if (res != AcBr::eOk)
                    return Acad::eInvalidInput;

                // if the edge is already in edgeFlangeIdMap with its corresponding flange id 
                // and is extracted by iterating over a loop of traversed face that belongs to 
                // another flange then this is hard edge 
                std::map<AcDbFullSubentPath, AcDbObjectId, FspComparator>::iterator foundEdgeFeatureIdIter =
                    edgeFlangeIdMap.find(edgeFsp);
                if (foundEdgeFeatureIdIter != edgeFlangeIdMap.end() && foundEdgeFeatureIdIter->second != flangeFaceFlangeId.second)
                    aHardEdges.append(edgeFsp);
                else
                    edgeFlangeIdMap[edgeFsp] = flangeFaceFlangeId.second;
            }
        }
    }

    return Acad::eOk;
}

Acad::ErrorStatus dissolveAllSheetMetalFeatures(const AcDbObjectId & blockId,
    const AcDbObjectId & solidId)
{
    AcDbObjectIdArray aFeatureIds = BrxIFeature::getAllFeatures(blockId);
    for (const AcDbObjectId & featureId : aFeatureIds)
    {

        BrxIFeature feature(featureId);
        if (!feature.isSheetMetalFeature())
            continue;

        AcDbObjectPointer<AcDbObject> pObj(featureId, AcDb::kForWrite);
        if (pObj)
            pObj->erase();
    }

    // Possible Sheet Metal context per solid, erase it first
    {
        AcDbObjectId smSolidId = BrxSmSheetMetalContext::getInstance(solidId).objectId();
        AcDbObjectPointer<AcDbObject> pSmSolid(smSolidId, AcDb::kForWrite);
        if (pSmSolid)
            pSmSolid->erase();
    }

    // Then erase global context
    {
        AcDbObjectId smId = BrxSmSheetMetalContext::getInstance(blockId).objectId();
        AcDbObjectPointer<AcDbObject> pSm(smId, AcDb::kForWrite);
        if (pSm)
            pSm->erase();
    }

    return Acad::eOk;
}

Acad::ErrorStatus dissolveSheetMetalFeatures(const AcDbObjectId & blockId,
    const AcDbObjectId & solidId,
    const AcDbObjectIdArray & aKeepTheseFeatures)
{
    AcDbObjectIdArray aFeatureIds = getFeatures<BrxIFeature>(blockId, solidId);
    for (const AcDbObjectId & featureId : aFeatureIds)
    {
        if (aKeepTheseFeatures.contains(featureId))
            continue;

        BrxIFeature feature(featureId);
        if (!feature.isSheetMetalFeature())
            continue;

        AcDbObjectPointer<AcDbObject> pObj(featureId, AcDb::kForWrite);
        if (pObj)
            pObj->erase();
    }

    return Acad::eOk;
}

Acad::ErrorStatus recognizeFeatures(const AcDbObjectId & solidId)
{
    BrxSmConverter smConverter;
    Acad::ErrorStatus res = smConverter.setSolid(solidId);
    if (res != Acad::eOk)
        return res;

    res = smConverter.setPreferFormFeatureRecognition(true);
    if (res != Acad::eOk)
        return res;

    return smConverter.run();
}

Acad::ErrorStatus getExternalSideFace(const AcDbObjectId & blockId,
    const AcDbObjectId & solidId,
    AcDbFullSubentPath & externalSideFaceFsp)
{
    AcDbObjectIdArray aFlangeIds = getFeatures<BrxSmFlangeFeature>(blockId, solidId);
    if (!aFlangeIds.isEmpty())
    {
        BrxSmFlangeFeature flangeFeature(aFlangeIds.first());
        if (flangeFeature.isNull())
            return Acad::eInvalidInput;

        AcDbFullSubentPathArray aTopFlangeFaces = flangeFeature.getFeatureEntities(BrxSmFlangeFeature::eTopFaces);
        AcDbFullSubentPathArray aBottomFlangeFaces = flangeFeature.getFeatureEntities(BrxSmFlangeFeature::eBottomFaces);
        if (aTopFlangeFaces.isEmpty() || aBottomFlangeFaces.isEmpty())
            return Acad::eInvalidInput;

        AcDbFullSubentPathArray aFirstSideBottomFlangeFaces;
        AcDbFullSubentPathArray aSecondSideBottomFlangeFaces;
        Acad::ErrorStatus res = getSideBottomFlangeFaces(aTopFlangeFaces.first(), aFlangeIds, aFirstSideBottomFlangeFaces);
        if (res != Acad::eOk)
            return res;

        res = getSideBottomFlangeFaces(aBottomFlangeFaces.first(), aFlangeIds, aSecondSideBottomFlangeFaces);
        if (res != Acad::eOk)
            return res;

        if (aFirstSideBottomFlangeFaces.isEmpty() && aSecondSideBottomFlangeFaces.isEmpty())
            return Acad::eInvalidInput;

        double topSideArea = 0.0;
        double bottomSideArea = 0.0;
        res = getSideArea(aFirstSideBottomFlangeFaces, topSideArea);
        if (res != Acad::eOk)
            return res;

        res = getSideArea(aSecondSideBottomFlangeFaces, bottomSideArea);
        if (res != Acad::eOk)
            return res;

        if (topSideArea > bottomSideArea)
            externalSideFaceFsp = aTopFlangeFaces.first();
        else
            externalSideFaceFsp = aBottomFlangeFaces.first();
    }
    else
    {
        AcDbObjectIdArray aLoftedBendIds = getFeatures<BrxSmLoftedBendFeature>(blockId, solidId);
        if (aLoftedBendIds.isEmpty())
        {
            externalSideFaceFsp = AcDbFullSubentPath();
            return Acad::eOk;
        }

        BrxSmLoftedBendFeature loftedBendFeature(aLoftedBendIds.first());
        if (loftedBendFeature.isNull())
            return Acad::eInvalidInput;

        AcDbFullSubentPathArray aTopLoftedBendFaces = loftedBendFeature.getFeatureEntities(BrxSmLoftedBendFeature::eTopFaces);
        AcDbFullSubentPathArray aBottomLoftedBendFaces = loftedBendFeature.getFeatureEntities(BrxSmLoftedBendFeature::eBottomFaces);
        if (aTopLoftedBendFaces.isEmpty() || aBottomLoftedBendFaces.isEmpty())
            return Acad::eInvalidInput;

        AcDbFullSubentPathArray aFirstSideLoftedBendFaces;
        AcDbFullSubentPathArray aSecondSideLoftedBendFaces;
        Acad::ErrorStatus res = getSideFaces(aTopLoftedBendFaces.first(), aFirstSideLoftedBendFaces);
        if (res != Acad::eOk)
            return res;

        res = getSideFaces(aBottomLoftedBendFaces.first(), aSecondSideLoftedBendFaces);
        if (res != Acad::eOk)
            return res;

        if (aFirstSideLoftedBendFaces.isEmpty() || aSecondSideLoftedBendFaces.isEmpty())
            return Acad::eInvalidInput;

        double topSideArea = 0.0;
        double bottomSideArea = 0.0;
        res = getSideArea(aFirstSideLoftedBendFaces, topSideArea);
        if (res != Acad::eOk)
            return res;

        res = getSideArea(aSecondSideLoftedBendFaces, bottomSideArea);
        if (res != Acad::eOk)
            return res;

        if (topSideArea > bottomSideArea)
            externalSideFaceFsp = aTopLoftedBendFaces.first();
        else
            externalSideFaceFsp = aBottomLoftedBendFaces.first();
    }

    return Acad::eOk;
}

Acad::ErrorStatus repairModel(const AcDbObjectId & blockId, const AcDbObjectId & solidId,
    AcDbFullSubentPath * pDesiredFSP)
{
    AcDbFullSubentPath externalSideFace;
    if (!pDesiredFSP)
    {
        Acad::ErrorStatus res = getExternalSideFace(blockId, solidId, externalSideFace);
        if (res != Acad::eOk)
            return res;
        if (externalSideFace == AcDbFullSubentPath())
            return Acad::eInvalidInput;
    }
    else
        externalSideFace = *pDesiredFSP;

    BrxSmRepair repairOperation;
    Acad::ErrorStatus res = repairOperation.setSideFace(externalSideFace);
    if (res != Acad::eOk)
        return res;

    return repairOperation.run();
}

Acad::ErrorStatus createBends(const AcDbObjectId & blockId, const AcDbObjectId & solidId)
{
    AcDbFullSubentPathArray aHardEdges;
    Acad::ErrorStatus res = getHardEdges(blockId, solidId, aHardEdges);
    if (res != Acad::eOk || aHardEdges.isEmpty())
        return res;

    AcDbObjectIdArray aFlangeIds = getFeatures<BrxSmFlangeFeature>(blockId, solidId);
    if (aFlangeIds.isEmpty())
        return Acad::eOk;

    BrxSmBendCreator bendCreator;
    res = bendCreator.setFlanges(aFlangeIds);
    if (res != Acad::eOk)
        return res;

    BrxSmSheetMetalContext smContext = BrxSmSheetMetalContext::getInstance(blockId);
    if (smContext.isNull())
        return Acad::eInvalidInput;

    res = bendCreator.setBendRadius(smContext.bendRadiusAbsoluteValue());
    if (res != Acad::eOk)
        return res;

    return bendCreator.run();
}

Acad::ErrorStatus unfoldModel(const AcDbObjectId & blockId,
                                     const AcDbObjectId & solidId,
                                     const AcGePoint3d & insertionPoint,
                                     double & unfoldedBlockYDim)
{
    std::unique_ptr<BrxIUnfoldAppearance> pUnfoldAppearance = std::make_unique<BrxIUnfoldAppearance>();
    const AcString * pUnitsAbbreviatureString = acedGetUnitsValueString(blockId.database()->insunits());
    if (!pUnitsAbbreviatureString)
        return Acad::eNullPtr;

    Acad::ErrorStatus res = pUnfoldAppearance->setSheetMetalDefaults(blockId, pUnitsAbbreviatureString->constPtr());
    if (res != Acad::eOk)
        return res;

    BrxSmUnfoldOperation unfolder;
    res = unfolder.setUnfoldAppearance(*pUnfoldAppearance);
    if (res != Acad::eOk)
        return res;

    res = unfolder.unfoldAppearance().setAddAttributeText(true);
    if (res != Acad::eOk)
        return res;

    AcDbFullSubentPath externalSideFace;
    res = getExternalSideFace(blockId, solidId, externalSideFace);
    if (res != Acad::eOk)
        return res;
    if (externalSideFace == AcDbFullSubentPath())
        return Acad::eInvalidInput;

    res = unfolder.setStartFace(externalSideFace);
    if (res != Acad::eOk)
        return res;

    res = unfolder.run();
    if (res != Acad::eOk)
        return res;

    AcDbObjectId resultBlockId = unfolder.resultBlock();
    if (resultBlockId.isNull())
        return Acad::eInvalidInput;

    AcDbObjectPointer<AcDbBlockReference> pRef;
    res = pRef.create();
    if (res != Acad::eOk)
        return res;

    res = pRef->setBlockTableRecord(resultBlockId);
    if (res != Acad::eOk)
        return res;

    pRef->setDatabaseDefaults(blockId.database());

    AcDbObjectId resultSolidId = unfolder.resultSolid();
    if (resultSolidId.isNull())
        return Acad::eInvalidInput;

    // visualize result solid
    {
        AcDbObjectPointer<AcDbEntity> pEnt(resultSolidId, AcDb::kForWrite);
        if (!pEnt)
            return Acad::eInvalidInput;

        res = pEnt->setVisibility(AcDb::kVisible);
        if (res != Acad::eOk)
            return res;
    }

    // convert to 2D
    res = unfolder.convertTo2D();
    if (res != Acad::eOk)
        return res;

    // translate block reference
    {
        AcDbObjectPointer<AcDbBlockTableRecord> pBTR(resultBlockId);
        if (!pBTR)
            return Acad::eInvalidInput;

        AcDbExtents ext;
        ext.addBlockExt(pBTR);
        unfoldedBlockYDim = ext.maxPoint().asVector().y - ext.minPoint().asVector().y;
        AcGePoint3d lastPoint = ext.minPoint();

        AcGeVector3d resultTranslationVector = insertionPoint - lastPoint;
        AcGeMatrix3d matrix;
        matrix.setToTranslation(resultTranslationVector);
        pRef->transformBy(matrix);
    }

    // erase preview solids
    {
        AcDbObjectPointer<AcDbBlockTableRecord> pBTR(unfolder.resultBlock());
        if (!pBTR)
            return Acad::eInvalidInput;

        std::unique_ptr<AcDbBlockTableRecordIterator> pBTRIt;
        res = getBlockTableRecordIterator(pBTR, pBTRIt);
        if (res != Acad::eOk)
            return res;

        for (pBTRIt; !pBTRIt->done(); pBTRIt->step())
        {
            AcDbObjectId entId;
            res = pBTRIt->getEntityId(entId);
            if (res != Acad::eOk)
                continue;

            AcDbObjectPointer<AcDbEntity> pEnt(entId);
            if (!pEnt || !pEnt->isKindOf(AcDb3dSolid::desc()))
                continue;
            pEnt->upgradeOpen();
            pEnt->erase();
        }
    }

    // add block to database
    AcDbObjectPointer<AcDbBlockTableRecord> pMS(blockId, AcDb::kForWrite);
    return pMS->appendAcDbEntity(pRef);
}

Acad::ErrorStatus addToDatabase(AcDbDatabase * pDb, AcDbEntity* pEnt, AcDbObjectId& objId)
{
    Acad::ErrorStatus es = Acad::ErrorStatus::eOk;
    if (pEnt == nullptr)
        return Acad::eInvalidInput;

    AcDbObjectId msId;
    es = getModelSpaceId(pDb, msId);
    if (Acad::ErrorStatus::eOk != es)
        return Acad::eInvalidInput;

    AcDbBlockTableRecord* pMS = nullptr;;    
    if (acdbOpenObject(pMS, msId, AcDb::kForWrite) != Acad::eOk)
        return Acad::eInvalidInput;

    es = pMS->appendAcDbEntity(objId, pEnt);
    if (es != Acad::eOk)
    {
        acutPrintf(_T("*Error* Object not added to the database.\n"));
        pMS->close();
        return es;
    }

    pMS->close();

    return es;
}

Acad::ErrorStatus cloneEntity(const AcDbObjectId& blockId,
    const AcDbObjectId& entId, AcDbObjectId& cloneId,
    std::map<AcDbObjectId, AcDbObjectId> & featureMap)
{
    AcDbObjectIdArray aFeatureIds = getFeatures<BrxSmLoftedBendFeature>(blockId, entId);
    AcDbObjectIdArray aFeatureToSearchIds;
    for (const AcDbObjectId & featureId : aFeatureIds)
    {
        BrxIFeature feature(featureId);
        if (!feature.isSheetMetalFeature())
            continue;
        aFeatureToSearchIds.append(featureId);
    }

    auto pDb = blockId.database();

    AcDbIdMapping cloneMap;
    {
        BrxIUpdateFeatureScope updateScope(pDb, false);
        AcDbObjectIdArray aEntToClone;
        aEntToClone.append(entId);
        
        AcDbObjectId bId = blockId;
        if (Acad::ErrorStatus::eOk != pDb->deepCloneObjects(aEntToClone, bId, cloneMap))
            return Acad::eInvalidInput;
    }

    AcDbIdPair entSearch;
    entSearch.setKey(entId);
    if (!cloneMap.compute(entSearch))
        return Acad::eInvalidInput;
    cloneId = entSearch.value();

    for (const AcDbObjectId & featureId : aFeatureToSearchIds)
    {
        AcDbIdPair featureSearch;
        featureSearch.setKey(featureId);
        if (!cloneMap.compute(featureSearch))
            return Acad::eInvalidInput;
        featureMap.emplace(featureId, featureSearch.value());
    }

    return Acad::ErrorStatus::eOk;
}

Acad::ErrorStatus separateLoftedBends(const AcDbObjectId & blockId, const AcDbObjectId & solidId,
    const LoftedBendToSideMap & loftedBendToSideMap,
    std::map<AcDbObjectId, AcDbObjectId> & oldToNewFeatureMap)
{
    AcDbObjectIdArray aLoftedBendIds = getFeatures<BrxSmLoftedBendFeature>(blockId, solidId);
    if (aLoftedBendIds.length() <= 1)
        return Acad::eOk;

    for (const auto & loftedBendId : aLoftedBendIds)
    {
        BrxSmLoftedBendFeature loftedBendFeature(loftedBendId);
        if (loftedBendFeature.isNull())
            return Acad::eInvalidInput;

        // Find clone entity and feature

        AcDbObjectId cloneSolidId;
        std::map<AcDbObjectId, AcDbObjectId> featureMap;
        if (Acad::eOk != cloneEntity(blockId, solidId, cloneSolidId, featureMap))
            return Acad::eInvalidInput;

        auto featureIt = featureMap.find(loftedBendId);
        if (featureIt == featureMap.end())
            return Acad::eInvalidInput;

        auto cloneFeatureId = featureIt->second;

        oldToNewFeatureMap[loftedBendId] = cloneFeatureId;

        // Remap FSP for face to repair

        auto sideIt = loftedBendToSideMap.find(loftedBendId);
        if (loftedBendToSideMap.end() == sideIt)
            return Acad::eInvalidInput;

        AcDbFullSubentPathArray aSideFaces;
        {
            BrxSmLoftedBendFeature clonedLoftedBendFeature(cloneFeatureId);
            if (clonedLoftedBendFeature.isNull())
                return Acad::eInvalidInput;
            aSideFaces = clonedLoftedBendFeature.getFaces(sideIt->second);
        }

        if (aSideFaces.isEmpty())
            return Acad::eInvalidInput;

        AcDbFullSubentPath clonedFeatureFsp = aSideFaces[0];

        AcDbObjectIdArray aKeepFeatures;
        aKeepFeatures.append(cloneFeatureId);

        if (Acad::eOk != dissolveSheetMetalFeatures(blockId, cloneSolidId, aKeepFeatures))
            return Acad::eInvalidInput;

        if (Acad::eOk != repairModel(blockId, cloneSolidId, &clonedFeatureFsp))
            return Acad::eInvalidInput;
    }

    AcDbObjectPointer<AcDbEntity> pEnt(solidId, AcDb::kForWrite);
    pEnt->erase();

    return Acad::ErrorStatus::eOk;
}

}
