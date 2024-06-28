// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////

#include "StdAfx.h"

#include "civil_utils.h"
#include "BrxSpecific/civil/BrxCvDbTinSurface.h"

Acad::ErrorStatus addEntityToModelSpace(AcDbEntity* pEnt,
                                        AcDbObjectId& entityId,
                                        bool closeEnt)
{
    if (!pEnt)
        return Acad::eNullPtr;

    AcDbDatabase* pDb = acdbHostApplicationServices()->workingDatabase();

    AcDbBlockTable* pBlockTable = NULL;
    Acad::ErrorStatus es = pDb->getSymbolTable(pBlockTable, AcDb::kForRead);
    if (es != Acad::eOk)
        return es;

    AcDbBlockTableRecord* pBlockTableRecord = NULL;
    es = pBlockTable->getAt(ACDB_MODEL_SPACE, pBlockTableRecord, AcDb::kForWrite);
    if (es != Acad::eOk)
        return es;
    pBlockTable->close();
    es = pBlockTableRecord->appendAcDbEntity(pEnt);
    if (es != Acad::eOk)
        return es;
    else
        entityId = pEnt->objectId();
    pBlockTableRecord->close();
    if (closeEnt)
        pEnt->close();
    return Acad::eOk;
}

void addEntitiesToModelSpace(AcDbEntityPtrArray& pEntities)
{
    if (pEntities.isEmpty())
        return;
    AcDbDatabase* pDb = acdbHostApplicationServices()->workingDatabase();
    AcDbBlockTable* pBlockTable = nullptr;
    Acad::ErrorStatus es = pDb->getSymbolTable(pBlockTable, AcDb::kForRead);
    if (es != Acad::eOk)
        return;
    AcDbBlockTableRecord* pBlockTableRecord = nullptr;
    es = pBlockTable->getAt(ACDB_MODEL_SPACE, pBlockTableRecord, AcDb::kForWrite);
    if (es != Acad::eOk)
        return;
    pBlockTable->close();

    for (auto pEntity : pEntities)
    {
        es = pBlockTableRecord->appendAcDbEntity(pEntity);
        if (es != Acad::eOk)
            continue;
        pEntity->close();
    }
    pBlockTableRecord->close();
}

AcDbObjectId selectEntityPrompt(const AcString& prompt, AcRxClass* pClassDesc, bool acceptDerived)
{
    Acad::ErrorStatus es;
    ads_point pickPnt;
    ads_name ent_name;

    while (true)
    {
        int ret = acedEntSel(prompt, ent_name, pickPnt);
        if (ret != RTNORM)
            return AcDbObjectId::kNull;
        AcDbObjectId entityId;
        es = acdbGetObjectId(entityId, ent_name);
        if (es != Acad::eOk)
            return AcDbObjectId::kNull;
        if (acceptDerived ? entityId.objectClass()->isDerivedFrom(pClassDesc) : entityId.objectClass() == pClassDesc)
            return entityId;
    }
    return AcDbObjectId::kNull;
}

AcDbObjectId getActiveViewportTableRecordId()
{
    AcDbDatabase* pDb = acdbHostApplicationServices()->workingDatabase();
    AcDbViewportTable* pVT = nullptr;
    Acad::ErrorStatus es = pDb->getViewportTable(pVT, AcDb::kForRead);
    if (es != Acad::eOk)
        return nullptr;

    AcDbObjectId viewTableRecordId;
    es = pVT->getAt(_T("*ACTIVE"), viewTableRecordId);
    if (es != Acad::eOk)
        return nullptr;
    return viewTableRecordId;
}

AcGeMatrix3d worldToViewport(const AcDbViewportTableRecordPointer & pVTR)
{
    assert(pVTR != nullptr);
    if (pVTR == nullptr)
        return AcGeMatrix3d::kIdentity;

    return AcGeMatrix3d().setToWorldToPlane(pVTR->viewDirection()) *
        AcGeMatrix3d().setTranslation(AcGePoint3d::kOrigin - pVTR->target()) *
        AcGeMatrix3d().setToRotation(pVTR->viewTwist(),
                                     pVTR->viewDirection(),
                                     pVTR->target());
}

BrxCvDbTinSurface* createSampleTinSurface()
{
    const double INNER_SURF_POINTS_OFFSET = 10;
    const double OUTER_SURF_POINTS_OFFSET = 50;
    AcGePoint3dArray points;

    points.append(AcGePoint3d(-INNER_SURF_POINTS_OFFSET, -INNER_SURF_POINTS_OFFSET, 0));
    points.append(AcGePoint3d(INNER_SURF_POINTS_OFFSET, -INNER_SURF_POINTS_OFFSET, 0));
    points.append(AcGePoint3d(INNER_SURF_POINTS_OFFSET, INNER_SURF_POINTS_OFFSET, 0));
    points.append(AcGePoint3d(-INNER_SURF_POINTS_OFFSET, INNER_SURF_POINTS_OFFSET, 0));

    points.append(AcGePoint3d(-OUTER_SURF_POINTS_OFFSET, -OUTER_SURF_POINTS_OFFSET, -10));
    points.append(AcGePoint3d(OUTER_SURF_POINTS_OFFSET, -OUTER_SURF_POINTS_OFFSET, -10));
    points.append(AcGePoint3d(OUTER_SURF_POINTS_OFFSET, OUTER_SURF_POINTS_OFFSET, 10));
    points.append(AcGePoint3d(-OUTER_SURF_POINTS_OFFSET, OUTER_SURF_POINTS_OFFSET, 10));

    BrxCvDbTinSurface* pSurface = new BrxCvDbTinSurface();
    pSurface->setDatabaseDefaults();
    pSurface->initialize(AcGePoint3d(-OUTER_SURF_POINTS_OFFSET, -OUTER_SURF_POINTS_OFFSET, 0),
                         AcGePoint3d(OUTER_SURF_POINTS_OFFSET, OUTER_SURF_POINTS_OFFSET, 10),
                         100);
    bool successful = pSurface->addPoints(points);
    pSurface->updateObjectData();

    if (successful)
        return pSurface;
    else
    {
        delete pSurface;
        return nullptr;
    }
}

Acad::ErrorStatus getModelSpaceId(AcDbDatabase * pDb, AcDbObjectId & blockId)
{
    AcDbObjectPointer<AcDbBlockTable> pBT(pDb->blockTableId(), AcDb::kForRead);
    if (!pBT)
        return Acad::eInvalidInput;

    return pBT->getAt(ACDB_MODEL_SPACE, blockId);
}

Acad::ErrorStatus getBlockTableRecordIterator(const AcDbBlockTableRecord * pBTR, std::unique_ptr<AcDbBlockTableRecordIterator>& pUniqueBTRIter)
{
    AcDbBlockTableRecordIterator * pBTRIter = nullptr;
    Acad::ErrorStatus res = pBTR->newIterator(pBTRIter);
    if (res != Acad::eOk)
        return res;

    pUniqueBTRIter.reset(pBTRIter);
    return Acad::eOk;
}

Acad::ErrorStatus getGsMarker(AcDbObjectId& objId, int& marker)
{
    ads_name sset;
    if (acedSSGet(L"_:S", NULL, NULL, NULL, sset) != RTNORM)
        return Acad::eInvalidAdsName;
    struct resbuf* pRb;
    int res = acedSSNameX(&pRb, sset, 0);
    acedSSFree(sset);
    if (res != RTNORM)
        return Acad::eAmbiguousOutput;
    struct resbuf* pTemp = pRb;
    for (int i = 1; i < 3; i++)
        pTemp = pTemp->rbnext;
    ads_name ename;
    ads_name_set(pTemp->resval.rlname, ename);
    pTemp = pTemp->rbnext;
    marker = pTemp->resval.rint;
    acutRelRb(pRb);
    acdbGetObjectId(objId, ename);
    return Acad::eOk;
}
