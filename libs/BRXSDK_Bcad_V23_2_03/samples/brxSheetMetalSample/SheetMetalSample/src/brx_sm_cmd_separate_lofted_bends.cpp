// Implementation of SMFLATTEN

/////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "brx_sm_utils.h"

#ifdef max
#undef max
#endif

#ifdef min
#undef min
#endif

namespace BrxSheetMetalSample {

// Point is suggested point for split line
struct SplitLine
{
    AcGePoint3d m_splitPoint;
    AcGePoint3d m_generatrixStartPoint;
    AcGePoint3d m_generatrixEndPoint;
};
using SplitLineMap = std::map<AcDbObjectId, SplitLine>;
using PossibleSplitLineMap = std::map<AcDbObjectId, AcArray<SplitLine>>;

using FeatureSet = std::set<AcDbObjectId>;

Acad::ErrorStatus findPossibleSplitLines(
    const AcDbObjectId & solidId,
    const AcDbObjectId & loftedBendId,
    const BrxSheetMetal::BrxFeatureAdjacencyArray & aAdj, // Faces are taken exactly from same side
    AcArray<SplitLine> & aPossibleSplitLines)
{
    const int nbSamplePointPerEdge = 5;

    // We expect that part has only lofted bend features
    BrxSmLoftedBendFeature loftedBendFeature(loftedBendId);
    if (loftedBendFeature.isNull())
        return Acad::eInvalidInput;

    // Rely that all the edges are adjacent to lofted bend
    for (const auto & adj : aAdj)
    {
        auto edgeFsp = adj.m_commonEdgeFsp;
        AcBrEdge brEdge;
        brEdge.set(edgeFsp);
        if ((AcBr::ErrorStatus::eOk != brEdge.set(edgeFsp)) ||
            (AcBr::ErrorStatus::eOk != brEdge.setSubentPath(edgeFsp)))
            return Acad::eGeneralModelingFailure;

        AcGeCurve3d * pEdgeCurve = nullptr;
        brEdge.getCurve(pEdgeCurve);
        std::auto_ptr<AcGeCurve3d> pEdgeCurveHolder(pEdgeCurve);

        AcGePoint3dArray aSamplePoints;
        pEdgeCurve->getSamplePoints(nbSamplePointPerEdge, aSamplePoints);

        for (const auto & samplePoint : aSamplePoints)
        {
            BrxSmLoftedBendFeature::ProjectionResult projResult;
            if (Acad::ErrorStatus::eOk != loftedBendFeature.projectPoint(samplePoint, projResult))
                continue;
            SplitLine splitLine;
            splitLine.m_splitPoint = projResult.m_projectionPoint;
            splitLine.m_generatrixStartPoint = projResult.m_generatrixLineStartPoint;
            splitLine.m_generatrixEndPoint = projResult.m_generatrixLineEndPoint;
            aPossibleSplitLines.append(splitLine);
        }
    }

    if (aPossibleSplitLines.isEmpty())
        return Acad::ErrorStatus::eInvalidInput;

    // Find free edges for lofted bend from given faces side
    return Acad::ErrorStatus::eOk;
}

using FeatureAdjacencyMapSolid = std::map<AcDbObjectId, FeatureAdjacencyMap>;

// Finds split lines on lofted bends so adjacent lofted bends don't have matching splits
Acad::ErrorStatus findSplitLines(const AcDbObjectId & blockId,
    const AcDbObjectIdArray & aSolidIds,
    LoftedBendToSideMap & loftedBendToSideMap,
    SplitLineMap & splitLineMap)
{ 

    for (const AcDbObjectId & solidId : aSolidIds)
    {
        AcDbObjectIdArray aLoftedBendIds = getFeatures<BrxSmLoftedBendFeature>(blockId, solidId);
        if (aLoftedBendIds.length() <= 1)
            continue;

        FeatureAdjacencyMap featureAdjacencyMap;
        Acad::ErrorStatus res = buildAdjacencyMap(blockId, solidId, featureAdjacencyMap);
        if (Acad::ErrorStatus::eOk != res)
        {
            return res;
        }

        PossibleSplitLineMap possibleSplitLineMap;
        std::map<AcDbObjectId, FeatureSet> adjFeatureMap;
     
        for (const auto & adj : featureAdjacencyMap)
        {
            const AcDbObjectId featureId = adj.first;
        
            // We expect that part has only lofted bend features
            BrxSmLoftedBendFeature loftedBendFeature(featureId);
            if (loftedBendFeature.isNull())
                return Acad::eInvalidInput;

            if (adj.second.isEmpty())
                return Acad::eInvalidInput;

            // Ensure adjacency is from same side
            for (const auto & adjData : adj.second)
            {
                if (loftedBendFeature.getFaces(
                    BrxSmLoftedBendFeature::ELoftedBendFaceType::eTopFaces).contains(adjData.m_thisFeatureFaceFsp))
                {
                    auto it = loftedBendToSideMap.find(featureId);
                    if (it != loftedBendToSideMap.end())
                    {
                        if (it->second != BrxSmLoftedBendFeature::ELoftedBendFaceType::eTopFaces)
                        {
                            acutPrintf(ACRX_T("\nLogical error. Side is already selected and is different. %d\n"), (int)__LINE__);
                            return Acad::eInvalidInput;
                        }
                    }
                    loftedBendToSideMap[featureId] = BrxSmLoftedBendFeature::ELoftedBendFaceType::eTopFaces;
                }
                else if (loftedBendFeature.getFaces(
                    BrxSmLoftedBendFeature::ELoftedBendFaceType::eBottomFaces).contains(adjData.m_thisFeatureFaceFsp))
                {
                    auto it = loftedBendToSideMap.find(featureId);
                    if (it != loftedBendToSideMap.end())
                    {
                        if (it->second != BrxSmLoftedBendFeature::ELoftedBendFaceType::eBottomFaces)
                        {
                            acutPrintf(ACRX_T("\nLogical error. Side is already selected and is different. %d\n"), (int)__LINE__);
                            return Acad::eInvalidInput;
                        }
                    }
                    loftedBendToSideMap[featureId] = BrxSmLoftedBendFeature::ELoftedBendFaceType::eBottomFaces;
                }
                else
                    return Acad::eInvalidInput;
            }

            // We need the edges where feature is adjacent with other feature
            AcArray<SplitLine> aPossibleSplitLines;
            if (Acad::ErrorStatus::eOk != findPossibleSplitLines(solidId, featureId,
                adj.second, aPossibleSplitLines))
                return Acad::eGeneralModelingFailure;

            possibleSplitLineMap[featureId] = aPossibleSplitLines;

            FeatureSet adjacentFeatures;
            for (const auto & a : adj.second)
            {
                std::copy(a.m_aOtherFeatureIds.begin(), a.m_aOtherFeatureIds.end(),
                    std::inserter(adjacentFeatures, adjacentFeatures.end()));
            }
           
            adjFeatureMap[featureId] = adjacentFeatures;
        } // for (const auto & adj : featureAdjacencyMap)

        // Now we have all the variants of split points (lines) for each lofted bend
        // And have the adjacency map - know what are adjacent features for each lofted bend

        for (const auto & adj : adjFeatureMap)
        {
            const auto & featureId = adj.first;
            const auto & adjacentFeatures = adj.second;

            // Find split line
            auto splitLineIt = possibleSplitLineMap.find(featureId);
            if (possibleSplitLineMap.end() == splitLineIt)
                return Acad::eInvalidInput;

            // Find split line which doesn't have conflicts with other already added
            const auto & aPossibleSplitLines = splitLineIt->second;

            // This split line data allows to choose split line even when scores are equal
            struct SplitLineData
            {
                bool operator < (const SplitLineData & other) const
                {
                    if (m_score < other.m_score)
                        return true;
                    if (m_score > other.m_score)
                        return false;
                    std::tuple<double, double, double> thisPoint{m_splitLine.m_splitPoint.x,
                                                                 m_splitLine.m_splitPoint.y,
                                                                 m_splitLine.m_splitPoint.z};

                    std::tuple<double, double, double> otherPoint{other.m_splitLine.m_splitPoint.x,
                                                                  other.m_splitLine.m_splitPoint.y,
                                                                  other.m_splitLine.m_splitPoint.z};
                    return thisPoint < otherPoint;
                }

                double m_score{};
                SplitLine m_splitLine;
            };

            auto getLineScore = [](const SplitLine & splitLine,
                const SplitLine & otherSplitLine) -> double
            {
                AcGeLine3d thisLine(splitLine.m_generatrixStartPoint, splitLine.m_generatrixEndPoint);
                AcGeLine3d otherLine(otherSplitLine.m_generatrixStartPoint, otherSplitLine.m_generatrixEndPoint);
                return thisLine.distanceTo(otherLine);
            };

            // Score is the minimal distance of given line to other lines already added
            auto getScore = [getLineScore, &splitLineMap](const SplitLine & splitLine,
                const FeatureSet & adjacentFeatures) -> double
            {
                double minDist = std::numeric_limits<double>::max();
                for (const auto &f : adjacentFeatures)
                {
                    auto it = splitLineMap.find(f);
                    if (splitLineMap.end() == it)
                        continue;
                    const auto d = getLineScore(splitLine, it->second);
                    minDist = std::min(minDist, d);
                }
                return minDist;
            };

            std::multiset<SplitLineData> lineScore;
            for (const auto & splitLine : aPossibleSplitLines)
            {
                const auto score = getScore(splitLine, adjacentFeatures);
                lineScore.insert({score, splitLine});
            }

            if (lineScore.empty())
                return Acad::eInvalidInput;

            // Take the highest score
            splitLineMap[featureId] = lineScore.rbegin()->m_splitLine;

        } // for (const auto & adj : adjFeatureMap)
    }

    return Acad::ErrorStatus::eOk;
}

Acad::ErrorStatus splitLoftedBend(
    const AcDbObjectId & loftedBendId,
    AcGePoint3d & splitPoint)
{
    AcDbFullSubentPath fsp;
    {
        BrxSmLoftedBendFeature loftedBendFeature(loftedBendId);
        if (loftedBendFeature.isNull())
            return Acad::eInvalidInput;

        if (!loftedBendFeature.isClosed())
            return Acad::ErrorStatus::eOk;

        // Find face to split again since repairing could flip sides
        BrxSmLoftedBendFeature::ProjectionResult projResult;
        if (Acad::ErrorStatus::eOk != loftedBendFeature.projectPoint(splitPoint, projResult))
            return Acad::ErrorStatus::eGeneralModelingFailure;

        fsp = projResult.m_loftedFace;
    }

    if (1 != fsp.objectIds().length())
        return Acad::eInvalidInput;

    const auto solidId = fsp.objectIds()[0];

    AcDbObjectPointer<AcDb3dSolid> pSolid(solidId, AcDb::kForWrite);
    if (!pSolid)
        return Acad::eInvalidInput;

    BrxSmSplit splitOperation;

    // Provide exactly one face for lofted bend split else it will fail
    AcDbFullSubentPathArray aTheOnlyFace;
    aTheOnlyFace.append(fsp);
    auto res = splitOperation.setFeatureFaces(aTheOnlyFace);
    if (Acad::ErrorStatus::eOk != res)
        return res;

    res = splitOperation.setLoftSplitPoint(splitPoint);
    if (Acad::ErrorStatus::eOk != res)
        return res;

    res = splitOperation.run();
    if (Acad::ErrorStatus::eOk != res)
        return res;

    res = splitOperation.applyResult(pSolid);
    if (Acad::ErrorStatus::eOk != res)
        return res;

    res = splitOperation.applyFeatures(pSolid);
    if (Acad::ErrorStatus::eOk != res)
        return res;

    pSolid.close();

    return Acad::ErrorStatus::eOk;
}

void cmdSmSeparateLoftedBends()
{
    if (!isLicenseAvailable(BricsCAD::eSheetMetalLicense)) // requires Platinum/SheetMetal
    {
        acutPrintf(ACRX_T("\nError! SheetMetal component is not available!\nPlease verify your BricsCAD License and 'RunAsLevel' setting.\n"));
        return;
    }

    AcDbDatabase* pDb = acdbCurDwg();
    if (!pDb)
    {
        acutPrintf(ACRX_T("\nError! No current database was found. %d\n"), (int)__LINE__);
        return;
    }

    AcDbObjectIdArray aSolidIds;
    Acad::ErrorStatus res = getSolidIdsFromDatabase(pDb, aSolidIds);
    if (res != Acad::eOk)
    {
        acutPrintf(ACRX_T("\nError occurred while extracting solid ids from current database. %d\n"), (int)__LINE__);
        return;
    }

    if (aSolidIds.isEmpty())
    {
        acutPrintf(ACRX_T("\nSolids were not found for current database. %d\n"), (int)__LINE__);
        return;
    }

    AcDbObjectId modelSpaceId;
    res = getModelSpaceId(pDb, modelSpaceId);
    if (res != Acad::eOk)
    {
        acutPrintf(ACRX_T("\nError occurred while extracting model space id from current database. %d\n"), (int)__LINE__);
        return;
    }

    SplitLineMap splitLineMap;
    LoftedBendToSideMap loftedBendToSideMap;
    res = findSplitLines(modelSpaceId, aSolidIds, loftedBendToSideMap, splitLineMap);
    if (res != Acad::eOk)
    {
        acutPrintf(ACRX_T("\nError occurred while building split lines. %d\n"), (int)__LINE__);
        return;
    }

    constexpr bool bDebugDrawSplitLines = false;
    if (bDebugDrawSplitLines)
    {
        AcDbObjectPointer<AcDbBlockTableRecord> pMS(modelSpaceId, AcDb::kForWrite);
        if (!pMS)
            return;
        for (const auto & splitLine : splitLineMap)
        {
            AcDbLine * pLine = new AcDbLine();
            pLine->setDatabaseDefaults(pDb);
            pLine->setStartPoint(splitLine.second.m_generatrixStartPoint);
            pLine->setEndPoint(splitLine.second.m_generatrixEndPoint);
            pLine->setColorIndex(1);
            pMS->appendAcDbEntity(pLine);
            pLine->close();

            AcDb3dSolid * pSphere = new AcDb3dSolid();
            pSphere->setDatabaseDefaults(pDb);
            pSphere->createSphere(3.0);
            AcGeMatrix3d transf;
            transf.setTranslation(splitLine.second.m_splitPoint - AcGePoint3d());
            pSphere->transformBy(transf);
            pSphere->setColorIndex(2);
            pMS->appendAcDbEntity(pSphere);
            pSphere->close();
        }
    }

    for (const AcDbObjectId & solidId : aSolidIds)
    {
        AcDbObjectIdArray aOriginalLoftedBendIds = getFeatures<BrxSmLoftedBendFeature>(modelSpaceId, solidId);
        if (aOriginalLoftedBendIds.length() <= 1)
            continue;

        auto solidNameStr = getSolidName(solidId);

        // Create bends on solid
        std::map<AcDbObjectId, AcDbObjectId> oldToNewFeatureMap;

        res = separateLoftedBends(modelSpaceId, solidId, loftedBendToSideMap, oldToNewFeatureMap);
        if (res != Acad::eOk)
        {
            acutPrintf(ACRX_T("\nLofted bend separation failed for solid %ls. Line %d\n"), solidNameStr.constPtr(), (int)__LINE__);
            return;
        }

        for (const auto & originalFeatureId : aOriginalLoftedBendIds)
        {
            auto cloneFeatureIt = oldToNewFeatureMap.find(originalFeatureId);
            if (oldToNewFeatureMap.end() == cloneFeatureIt)
            {
                acutPrintf(ACRX_T("\nLofted bend separation failed for solid %ls. Line %d\n"), solidNameStr.constPtr(), (int)__LINE__);
                return;
            }

            auto featureNameStr = getSolidName(cloneFeatureIt->second);

            auto splitLineIt = splitLineMap.find(originalFeatureId);
            if (splitLineMap.end() == splitLineIt)
            {
                acutPrintf(ACRX_T("\nLofted bend separation failed for feature %ls. Line %d\n"), featureNameStr.constPtr(), (int)__LINE__);
                return;
            }

            if (Acad::eOk != splitLoftedBend(cloneFeatureIt->second, splitLineIt->second.m_splitPoint))
            {
                acutPrintf(ACRX_T("\nLofted bend separation failed for feature %ls. Line %d\n"), featureNameStr.constPtr(), (int)__LINE__);
                return;
            }
        }
    }

}

}
