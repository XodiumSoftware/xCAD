// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

class AcString;
class AcDbDatabase;


class BRX_IMPORTEXPORT AcDbGeoDataReactor
{
public:
    virtual ~AcDbGeoDataReactor();

    virtual Acad::ErrorStatus geoCoordinateSystemWillChange(AcDbDatabase*, const AcString&, const AcString&);
    virtual void geoCoordinateSystemChanged(AcDbDatabase*, const AcString&, const AcString&);
};

Acad::ErrorStatus acdbRegisterGeoDataReactor(AcDbGeoDataReactor*);

void acdbRemoveGeoDataReactor(AcDbGeoDataReactor*);
