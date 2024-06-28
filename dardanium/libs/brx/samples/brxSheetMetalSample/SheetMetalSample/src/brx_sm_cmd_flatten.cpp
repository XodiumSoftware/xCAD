// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////

// Implementation of SMFLATTEN

#include "stdafx.h"
#include "brx_sm_utils.h"


namespace BrxSheetMetalSample {

void cmdSmFlatten()
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

    // Simplify geometry
    int rt = ads_command(RTSTR, ACRX_T("_DmSimplify"), RTSTR, ACRX_T("Entire"), RTNONE);
    bool isFailed = isCommandFailed(rt);
    if (isFailed)
    {
        acutPrintf(ACRX_T("\nCommand DmSimplify failed. Line %d\n"), (int)__LINE__);
        return;
    }

    bool isFinishedWithWarnings = isCommandFinishedWithWarnings(rt);
    if (isFinishedWithWarnings)
    {
        acutPrintf(ACRX_T("\nCommand DmSimplify finished with warnings. Line %d\n"), (int)__LINE__);
    }

    AcDbObjectId modelSpaceId;
    res = getModelSpaceId(pDb, modelSpaceId);
    if (res != Acad::eOk)
    {
        acutPrintf(ACRX_T("\nError occurred while extracting model space id from current database. %d\n"), (int)__LINE__);
        return;
    }

    double yInsertionCoordinate = 0.0;
    double gap = -1.0;
    for (const AcDbObjectId & solidId : aSolidIds)
    {
        auto solidNameStr = getSolidName(solidId);

        // Dissolves all existing sheet metal features
        res = dissolveAllSheetMetalFeatures(modelSpaceId, solidId);
        if (res != Acad::eOk)
        {
            acutPrintf(ACRX_T("\nFeatures dissolving failed for solid %ls. Line %d\n"), solidNameStr.constPtr(), (int)__LINE__);
            continue;
        }

        // Recognize features on solid
        res = recognizeFeatures(solidId);
        if (res != Acad::eOk)
        {
            acutPrintf(ACRX_T("\nFeatures recognition failed for solid %ls. Line %d\n"), solidNameStr.constPtr(), (int)__LINE__);
            continue;
        }

        // Repair solid
        res = repairModel(modelSpaceId, solidId);
        if (res != Acad::eOk)
        {
            acutPrintf(ACRX_T("\nRepairing failed for solid %ls. Line %d\n"), solidNameStr.constPtr(), (int)__LINE__);
            continue;
        }

        // Create bends on solid
        res = createBends(modelSpaceId, solidId);
        if (res != Acad::eOk)
        {
            acutPrintf(ACRX_T("\nBend creating failed for solid %ls. Line %d\n"), solidNameStr.constPtr(), (int)__LINE__);
            continue;
        }

        // Unfold solid
        AcGePoint3d insertionPoint(0.0, yInsertionCoordinate, 0.0);
        double unfoldedBlockYDim = 0.0;
        res = unfoldModel(modelSpaceId, solidId, insertionPoint, unfoldedBlockYDim);
        if (res != Acad::eOk)
        {
            acutPrintf(ACRX_T("\nUnfold failed for solid %ls. Line %d\n"), solidNameStr.constPtr(), (int)__LINE__);
            continue;
        }

        if (gap < 0.0)
            gap = 0.15 * unfoldedBlockYDim;
        yInsertionCoordinate += unfoldedBlockYDim + gap;
    }

    // Dissolves all sheet metal features and context after the last iteration
    dissolveAllSheetMetalFeatures(modelSpaceId, AcDbObjectId::kNull);
}

}
