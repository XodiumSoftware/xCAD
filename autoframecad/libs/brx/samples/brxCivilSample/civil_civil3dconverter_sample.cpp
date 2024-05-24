// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////

#include "StdAfx.h"

#include "civil_civil3dconverter_sample.h"
#include "civil_utils.h"

#include "BrxSpecific/civil/BrxCvCivil3dConverter.h"
#include "BrxSpecific/civil/BrxCvDbAlignments.h"
#include "BrxSpecific/civil/BrxCvDbTinSurface.h"

void cmdCivil3DConvertAll()
{
    //initialize constructor with source and target database 
    BrxCvCivil3dConverter converter(curDoc()->database(), 
        curDoc()->database(), BrxCvCivil3dConverter::eAllLabels);

    //iterate thrue Civil3D entities in the drawing
    auto allCivil3DEntities = converter.getCivilEntities();
    BrxCvCivil3dEntityInfos infoSurface;
    BrxCvCivil3dEntityInfos infoAlignment;
    BrxCvCivil3dEntityInfos infProfileView;
    BrxCvCivil3dEntityInfos infProfile;
    //iterate thrue Civil3D entities in the drawing
    for (auto& civil3DEntity : allCivil3DEntities)
    {
        if (civil3DEntity.type() == BrxCvCivil3dEntityInfo::eTinSurface)
        {
            infoSurface.push_back(civil3DEntity);
        }
        else if (civil3DEntity.type() == BrxCvCivil3dEntityInfo::eAlignment)
        {
            infoAlignment.push_back(civil3DEntity);
        }
        else if (civil3DEntity.type() == BrxCvCivil3dEntityInfo::eProfileView)
        {
            infProfileView.push_back(civil3DEntity);
        }
        else if (civil3DEntity.type() == BrxCvCivil3dEntityInfo::eProfile)
        {
            infProfile.push_back(civil3DEntity);
        }
    }

    //you can select enities you want to convert
    allCivil3DEntities.clear();
    allCivil3DEntities.insert(allCivil3DEntities.end(), infoAlignment.begin(), infoAlignment.end());
    allCivil3DEntities.insert(allCivil3DEntities.end(), infoSurface.begin(), infoSurface.end());
    allCivil3DEntities.insert(allCivil3DEntities.end(), infProfileView.begin(), infProfileView.end());
    allCivil3DEntities.insert(allCivil3DEntities.end(), infProfile.begin(), infProfile.end());

    auto results = converter.convert(allCivil3DEntities);

    //check result entities
    //if converted element is horizontal alignment get length
    //if converted element is tin surface get number of points
    //if converted element is alignment vertical view get base elevation
    //if converted element is vertical alignment get its elements count
    for (auto& result : results)
    {
        //Civil3D entity was not converted successfully
        if (!result.second.isValid())
            continue;
        if (result.first.type() == BrxCvCivil3dEntityInfo::eAlignment)
        {
            AcDbObjectPointer<BrxCvDbHAlignment> pAlignment(result.second, AcDb::kForRead);
            if (pAlignment == nullptr)
                continue;
            acutPrintf(_T("\nLength of Alignment %s is %f."), pAlignment->name(), pAlignment->length());
        }
        else if (result.first.type() == BrxCvCivil3dEntityInfo::eTinSurface)
        {
            AcDbObjectPointer<BrxCvDbTinSurface> pTinSurface(result.second, AcDb::kForRead);
            if (pTinSurface == nullptr)
                continue;
            acutPrintf(_T("\nTinSurface %s has %d points."), pTinSurface->name(), pTinSurface->pointsCount(true));
        }
        else if (result.first.type() == BrxCvCivil3dEntityInfo::eProfileView)
        {
            AcDbObjectPointer<BrxCvDbVAlignmentView> pVAlignmentView(result.second, AcDb::kForRead);
            if (pVAlignmentView == nullptr)
                continue;
            acutPrintf(_T("\nVerticalView %s base elevation is %f."), pVAlignmentView->name(), pVAlignmentView->baseElevation());
        }
        else if (result.first.type() == BrxCvCivil3dEntityInfo::eProfile)
        {
            AcDbObjectPointer<BrxCvDbVAlignment> pVAlignment(result.second, AcDb::kForRead);
            if (pVAlignment == nullptr)
                continue;
            acutPrintf(_T("\nVerticalAlignment %s has %d elements."), pVAlignment->name(), pVAlignment->elementCount());
        }
    }
}
