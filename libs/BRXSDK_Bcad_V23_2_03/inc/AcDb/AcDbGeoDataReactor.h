// Copyright (C) Menhirs NV. All rights reserved.
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
