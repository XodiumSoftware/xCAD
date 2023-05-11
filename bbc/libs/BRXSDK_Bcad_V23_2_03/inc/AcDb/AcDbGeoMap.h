// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbRasterImage.h"
#include "AcDb/AcDbGeoTypes.h"

class AcDbGeoMapImp;


class BRX_IMPORTEXPORT AcDbGeoMap : public AcDbRasterImage
{
public:
    ACDB_DECLARE_MEMBERS(AcDbGeoMap);

    AcDbGeoMap();
    AcDbGeoMap(AcGeoMapType, AcGeoMapResolution, unsigned int);
    AcDbGeoMap(AcDbObjectId, bool);
    ~AcDbGeoMap();

    Acad::ErrorStatus setMapType(AcGeoMapType);
    Acad::ErrorStatus setResolution(AcGeoMapResolution);
    AcGeoMapResolution resolution() const;
    AcGeoMapType mapType() const;
    AcGePoint3d bottomLeftPt() const;
    AcGePoint3d imageBottomLeftPt() const;
    Adesk::Boolean isOutOfDate() const;
    Adesk::Boolean updateMapImage(Adesk::Boolean = Adesk::kFalse);
    double height() const;
    double imageHeight() const;
    double imageWidth() const;
    double width() const;
    unsigned int LOD() const;
};
