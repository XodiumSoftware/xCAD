// Implementation of SMREBUILDBENDS

/////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "brx_sm_utils.h"


namespace BrxSheetMetalSample {

// This is a rework map
// First element of pair is bend internal angle
// Second element of pair is bend radius to assign
// The command will run through all bends and will assign new radius to bends
// Corresponding to new angle
static const std::map<double, double> s_bendsToRework = { {90.0, 1.0}, {45.0, 0.5} };
static constexpr double s_angleTolerance = 0.5;

/**
 * Rebuilds bends from hard edges on existing sheet metal body
 * @param blockId
 *   id of block table record
 * @return
 *   Acad::eOk if bend creation succeeded
 */
Acad::ErrorStatus rebuildBends(const AcDbObjectId & blockId, const AcDbObjectId & solidId)
{
    auto solidNameStr = getSolidName(solidId);

    acutPrintf(ACRX_T("\nWorking with solid %ls\n"), solidNameStr.constPtr());

    for (const auto & task : s_bendsToRework)
    {
        AcDbObjectIdArray aBendIds = getFeatures<BrxSmBendFeature>(blockId, solidId);
        if (aBendIds.isEmpty())
        {
            acutPrintf(ACRX_T("Solid has no bend features\n"));
            continue;
        }

        const double targetAngle = task.first;
        const double targetRadius = task.second;
        AcDbObjectIdArray aFilteredBends;
        for (const auto & bendId : aBendIds)
        {
            BrxSmBendFeature bendFeature(bendId);
            if (bendFeature.isNull())
            {
                return Acad::eInvalidObjectId;
            }

            const auto internalAngle = 180.0*std::abs(bendFeature.getInternalAngle()) / BRX_PI;
            if (std::abs(internalAngle - targetAngle) < s_angleTolerance)
            {
                aFilteredBends.append(bendId);
            }
        }
    
        acutPrintf(ACRX_T("Found %d bends with angle %f\n"), static_cast<int>(aFilteredBends.length()), targetAngle);
        if (aFilteredBends.isEmpty())
        {
            continue;
        }

        acutPrintf(ACRX_T("Deleting bends\n"));

        BrxSmDelete deleter;
        auto res = deleter.setFeatures(aFilteredBends);
        if (res != Acad::eOk)
            return res;
        res = deleter.run();
        if (res != Acad::eOk)
            return res;

        acutPrintf(ACRX_T("Creating bends angle %f radius %f\n"), targetAngle, targetRadius);

        AcDbObjectIdArray aFlangeIds = getFeatures<BrxSmFlangeFeature>(blockId, solidId);
        if (aFlangeIds.isEmpty())
            return Acad::eOk;

        BrxSmBendCreator bendCreator;
        res = bendCreator.setFlanges(aFlangeIds);
        if (res != Acad::eOk)
            return res;

        bendCreator.setBendRadius(targetRadius);

        res = bendCreator.run();
        if (res != Acad::eOk)
            return res;

        acutPrintf(ACRX_T("Succeeded\n"));
    }

    return Acad::eOk;
}

void cmdSmRebuildBends()
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

    for (const AcDbObjectId & solidId : aSolidIds)
    {
        auto solidNameStr = getSolidName(solidId);

        // Create bends on solid
        res = rebuildBends(modelSpaceId, solidId);
        if (res != Acad::eOk)
        {
            acutPrintf(ACRX_T("\nBend rebuilding failed for solid %ls. Line %d\n"), solidNameStr.constPtr(), (int)__LINE__);
        }
    }

}

}
