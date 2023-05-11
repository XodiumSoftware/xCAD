// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbEntity.h"

class AcGePoint3d;
class AcGeVector3d;
class AcString;
class AcDbMText;
class AcDbObjectId;


class BRX_IMPORTEXPORT AcDbGeoPositionMarker : public AcDbEntity
{
public:
    enum TextAlignmentType
    {
        kLeftAlignment = 0,
        kCenterAlignment = 1,
        kRightAlignment = 2
    };

    ACDB_DECLARE_MEMBERS(AcDbGeoPositionMarker);

    AcDbGeoPositionMarker();
    AcDbGeoPositionMarker(const AcGePoint3d&, double, double);
    ~AcDbGeoPositionMarker();

    Acad::ErrorStatus latLonAlt(double&, double&, double&) const;
    Acad::ErrorStatus setEnableFrameText(bool);
    Acad::ErrorStatus setGeoPosition(const AcGePoint3d&);
    Acad::ErrorStatus setLandingGap(double);
    Acad::ErrorStatus setLatLonAlt(double, double, double);
    Acad::ErrorStatus setMText(const AcDbMText*);
    Acad::ErrorStatus setMTextVisible(bool);
    Acad::ErrorStatus setNotes(const AcString&);
    Acad::ErrorStatus setPosition(const AcGePoint3d&);
    Acad::ErrorStatus setRadius(double);
    Acad::ErrorStatus setText(const AcString&);
    Acad::ErrorStatus setTextAlignmentType(TextAlignmentType);
    AcDbMText* mtext() const;
    AcDbObjectId textStyle() const;
    AcGePoint3d geoPosition() const;
    AcGePoint3d position() const;
    AcGeVector3d normal() const;
    AcString notes() const;
    AcString text() const;
    bool enableFrameText() const;
    bool mtextVisible() const;
    double landingGap() const;
    double radius() const;
    TextAlignmentType textAlignmentType() const;
};
