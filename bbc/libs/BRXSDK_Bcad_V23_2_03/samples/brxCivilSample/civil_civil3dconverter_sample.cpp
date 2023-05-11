// Copyright (C) Menhirs NV. All rights reserved.

#include "StdAfx.h"

#include "civil_civil3dconverter_sample.h"
#include "civil_utils.h"

#include "BrxSpecific/civil/AcCivil3dConverter.h"
#include "BrxSpecific/civil/AcDbCivilAlignments.h"
#include "BrxSpecific/civil/AcDbCivilTinSurface.h"

void cmdCivil3DConvertAll()
{
    //initialize constructor with source and target database 
    BrxCivil3dConverter converter(curDoc()->database(), 
        curDoc()->database(), BrxCivil3dConverter::eAllLabels);

    //iterate thrue Civil3D entities in the drawing
    auto allCivil3DEntities = converter.getCivilEntities();
    BrxCivil3dEntityInfos infoSurface;
    BrxCivil3dEntityInfos infoAlignment;
    BrxCivil3dEntityInfos infProfileView;
    BrxCivil3dEntityInfos infProfile;
    //iterate thrue Civil3D entities in the drawing
    for (auto& civil3DEntity : allCivil3DEntities)
    {
        if (civil3DEntity.type() == BrxCivil3dEntityInfo::eTinSurface)
        {
            infoSurface.push_back(civil3DEntity);
        }
        else if (civil3DEntity.type() == BrxCivil3dEntityInfo::eAlignment)
        {
            infoAlignment.push_back(civil3DEntity);
        }
        else if (civil3DEntity.type() == BrxCivil3dEntityInfo::eProfileView)
        {
            infProfileView.push_back(civil3DEntity);
        }
        else if (civil3DEntity.type() == BrxCivil3dEntityInfo::eProfile)
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
        if (result.first.type() == BrxCivil3dEntityInfo::eAlignment)
        {
            AcDbObjectPointer<AcDbCivilDbHAlignment> pAlignment(result.second, AcDb::kForRead);
            if (pAlignment == nullptr)
                continue;
            acutPrintf(_T("\nLength of Alignment %s is %f."), pAlignment->name(), pAlignment->length());
        }
        else if (result.first.type() == BrxCivil3dEntityInfo::eTinSurface)
        {
            AcDbObjectPointer<AcDbCivilTinSurface> pTinSurface(result.second, AcDb::kForRead);
            if (pTinSurface == nullptr)
                continue;
            acutPrintf(_T("\nTinSurface %s has %d points."), pTinSurface->name(), pTinSurface->pointsCount(true));
        }
        else if (result.first.type() == BrxCivil3dEntityInfo::eProfileView)
        {
            AcDbObjectPointer<AcDbCivilVAlignmentView> pVAlignmentView(result.second, AcDb::kForRead);
            if (pVAlignmentView == nullptr)
                continue;
            acutPrintf(_T("\nVerticalView %s base elevation is %f."), pVAlignmentView->name(), pVAlignmentView->baseElevation());
        }
        else if (result.first.type() == BrxCivil3dEntityInfo::eProfile)
        {
            AcDbObjectPointer<AcDbCivilDbVAlignment> pVAlignment(result.second, AcDb::kForRead);
            if (pVAlignment == nullptr)
                continue;
            acutPrintf(_T("\nVerticalAlignment %s has %d elements."), pVAlignment->name(), pVAlignment->elementCount());
        }
    }
}
