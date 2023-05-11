// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbObject.h"
#include "AcGe/AcGePoint2d.h"
#include "AcGe/AcGePoint3d.h"

class AcDbDatabase;
class AcGeVector2d;
class AcGeVector3d;
class AcDbObjectId;


class BRX_IMPORTEXPORT AcDbGeoData : public AcDbObject
{
public:
    enum TypeOfCoordinates
    {
        kCoordTypUnknown = 0,
        kCoordTypLocal = 1,
        kCoordTypGrid = 2,
        kCoordTypGeographic = 3
    };

    enum ScaleEstimationMethod
    {
        kScaleEstMethodUnity = 1,
        kScaleEstMethodUserDefined = 2,
        kScaleEstMethodReferencePoint = 3,
        kScaleEstMethodPrismoidal = 4
    };

    typedef Acad::ErrorStatus(*ACDBGEODATA_DWGTOGEOGRAPHIC)(const AcDbGeoData*, const double&, const double&, const double&, double&, double&, double&);
    typedef Acad::ErrorStatus(*ACDBGEODATA_GEOGRAPHICTODWG)(const AcDbGeoData*, const double&, const double&, const double&, double&, double&, double&);
    typedef bool (*ACDBGEODATA_VALIDATE_CS)(const ACHAR*);

    ACDB_DECLARE_MEMBERS(AcDbGeoData);

    AcDbGeoData();
    ~AcDbGeoData();

    static Acad::ErrorStatus setTransformCallbacks(const ACHAR*, ACDBGEODATA_GEOGRAPHICTODWG, ACDBGEODATA_DWGTOGEOGRAPHIC);
    static Acad::ErrorStatus setValidateCoordinateSystemCallback(ACDBGEODATA_VALIDATE_CS pncValidateCs);
    static ACDBGEODATA_VALIDATE_CS getValidateCoordinateSystemCallback();
    static const ACHAR* getTransformCallbacks(ACDBGEODATA_GEOGRAPHICTODWG&, ACDBGEODATA_DWGTOGEOGRAPHIC&);

    Acad::ErrorStatus addMeshFace(int, int, int, int);
    Acad::ErrorStatus addMeshPointMap(int, const AcGePoint2d&, const AcGePoint2d&);
    Acad::ErrorStatus eraseFromDb(void);
    Acad::ErrorStatus getMeshFace(int, int&, int&, int&) const;
    Acad::ErrorStatus getMeshPointMap(int, AcGePoint2d&, AcGePoint2d&) const;
    Acad::ErrorStatus getMeshPointMaps(AcGePoint2dArray&, AcGePoint2dArray&) const;
    Acad::ErrorStatus postToDb(AcDbObjectId&);
    Acad::ErrorStatus resetMeshPointMaps();
    Acad::ErrorStatus setBlockTableRecordId(const AcDbObjectId&);
    Acad::ErrorStatus setCoordinateProjectionRadius(double);
    Acad::ErrorStatus setCoordinateSystem(const ACHAR*);
    Acad::ErrorStatus setCoordinateType(TypeOfCoordinates);
    Acad::ErrorStatus setDesignPoint(const AcGePoint3d&);
    Acad::ErrorStatus setDoSeaLevelCorrection(bool);
    Acad::ErrorStatus setGeoRSSTag(const ACHAR*);
    Acad::ErrorStatus setHorizontalUnits(AcDb::UnitsValue);
    Acad::ErrorStatus setHorizontalUnitScale(double);
    Acad::ErrorStatus setMeshPointMaps(const AcGePoint2dArray&, const AcGePoint2dArray&);
    Acad::ErrorStatus setNorthDirectionVector(const AcGeVector2d&);
    Acad::ErrorStatus setObservationCoverage(const ACHAR*);
    Acad::ErrorStatus setObservationFrom(const ACHAR*);
    Acad::ErrorStatus setObservationTo(const ACHAR*);
    Acad::ErrorStatus setReferencePoint(const AcGePoint3d&);
    Acad::ErrorStatus setScaleEstimationMethod(ScaleEstimationMethod);
    Acad::ErrorStatus setScaleFactor(double);
    Acad::ErrorStatus setSeaLevelElevation(double);
    Acad::ErrorStatus setUpDirection(const AcGeVector3d&);
    Acad::ErrorStatus setVerticalUnits(AcDb::UnitsValue);
    Acad::ErrorStatus setVerticalUnitScale(double);
    Acad::ErrorStatus transformFromLonLatAlt(const AcGePoint3d&, AcGePoint3d&) const;
    Acad::ErrorStatus transformFromLonLatAlt(double, double, double, double&, double&, double&) const;
    Acad::ErrorStatus transformToLonLatAlt(const AcGePoint3d&, AcGePoint3d&) const;
    Acad::ErrorStatus transformToLonLatAlt(double, double, double, double&, double&, double&) const;
    Acad::ErrorStatus updateTransformationMatrix();
    AcDb::UnitsValue horizontalUnits() const;
    AcDb::UnitsValue verticalUnits() const;
    AcDbObjectId blockTableRecordId() const;
    AcGePoint3d designPoint() const;
    AcGePoint3d referencePoint() const;
    AcGeVector2d northDirectionVector() const;
    AcGeVector3d upDirection() const;
    bool doSeaLevelCorrection() const;
    const ACHAR* coordinateSystem() const;
    const ACHAR* geoRSSTag() const;
    const ACHAR* observationCoverage() const;
    const ACHAR* observationFrom() const;
    const ACHAR* observationTo() const;
    double coordinateProjectionRadius() const;
    double horizontalUnitScale() const;
    double northDirection() const;
    double scaleFactor() const;
    double seaLevelElevation() const;
    double verticalUnitScale() const;
    int numMeshFaces() const;
    int numMeshPoints() const;
    ScaleEstimationMethod scaleEstimationMethod() const;
    TypeOfCoordinates coordinateType() const;
};

Acad::ErrorStatus acdbGetGeoDataObjId(AcDbDatabase*, AcDbObjectId&);

Acad::ErrorStatus acdbGetGeoDataTransform(AcDbDatabase*, AcDbDatabase*, AcGePoint3d&, double&, double&);
