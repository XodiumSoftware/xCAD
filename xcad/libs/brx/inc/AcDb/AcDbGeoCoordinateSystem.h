// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "Misc/AcString.h"

class AcDbGeoCoordinateSystemCategory;
class BrxDbGeoCoordinateSystemImp;

struct AcDbGeoDatum
{
    AcString id;
    AcString desc;
};

struct AcDbGeoEllipsoid
{
    AcString id;
    AcString desc;
    double polarRadius;
    double eccentricity;
};

struct AcDbGeoProjectionParameter
{
    AcString name;
    double value;
};

class BRX_IMPORTEXPORT AcDbGeoCoordinateSystem
{
public:
    enum Type
    {
        kTypeUnknown = 0,
        kTypeArbitrary = 1,
        kTypeGeographic = 2,
        kTypeProjected = 3
    };

    enum ProjectionCode
    {
        kProjectionCodeUnknown = 0,
        kProjectionCodeLL = 1,
        kProjectionCodeTm = 3,
        kProjectionCodeAlber = 4,
        kProjectionCodeOblqM = 5,
        kProjectionCodeMrcat = 6,
        kProjectionCodeAzmed = 7,
        kProjectionCodeLmtan = 8,
        kProjectionCodePlycn = 9,
        kProjectionCodeModpc = 10,
        kProjectionCodeAzmea = 11,
        kProjectionCodeEdcnc = 12,
        kProjectionCodeMiller = 13,
        kProjectionCodeMstero = 15,
        kProjectionCodeNzealand = 16,
        kProjectionCodeSinus = 17,
        kProjectionCodeOrtho = 18,
        kProjectionCodeGnomonic = 19,
        kProjectionCodeEdcyl = 20,
        kProjectionCodeVdgrntn = 21,
        kProjectionCodeCassini = 22,
        kProjectionCodeRobinson = 23,
        kProjectionCodeBonne = 24,
        kProjectionCodeEckert4 = 25,
        kProjectionCodeEckert6 = 26,
        kProjectionCodeMollweid = 27,
        kProjectionCodeGoode = 28,
        kProjectionCodeNeacyl = 29,
        kProjectionCodeTeacyl = 30,
        kProjectionCodeBipolar = 31,
        kProjectionCodePstro = 33,
        kProjectionCodeSwiss = 32,
        kProjectionCodeOstro = 34,
        kProjectionCodeSstro = 35,
        kProjectionCodeLm1sp = 36,
        kProjectionCodeLm2sp = 37,
        kProjectionCodeLmblg = 38,
        kProjectionCodeWccsl = 39,
        kProjectionCodeWccst = 40,
        kProjectionCodeMndotl = 41,
        kProjectionCodeMndott = 42,
        kProjectionCodeSotrm = 43,
        kProjectionCodeUtm = 44,
        kProjectionCodeTrmrs = 45,
        kProjectionCodeGaussK = 46,
        kProjectionCodeKrovak = 47,
        kProjectionCodeMrcatK = 49,
        kProjectionCodeKrvk95 = 51,
        kProjectionCodePstrosl = 53,
        kProjectionCodeTrmeraf = 54,
        kProjectionCodeNerth = 55,
        kProjectionCodeObqcyl = 56,
        kProjectionCodeSys34 = 57,
        kProjectionCodeOstn97 = 58,
        kProjectionCodeAzede = 59,
        kProjectionCodeOstn02 = 60,
        kProjectionCodeSys34_99 = 61,
        kProjectionCodeTrmrkrg = 62,
        kProjectionCodeWinkl = 63,
        kProjectionCodeNrthsrt = 64,
        kProjectionCodeLmbrtaf = 65,
        kProjectionCodeSys34_01 = 66,
        kProjectionCodeEdcylE = 67,
        kProjectionCodePlateCarree = 68,
        kProjectionCodePvMercator = 69,
        kProjectionCodeHom1uv = 1281,
        kProjectionCodeHom1xy = 1282,
        kProjectionCodeHom2uv = 1283,
        kProjectionCodeHom2xy = 1284,
        kProjectionCodeRskew = 1285,
        kProjectionCodeRskewc = 1286,
        kProjectionCodeRskewo = 1287,
    };

    enum Unit
    {
        kUnitUnknown = 0,
        kUnitMeter = 1,
        kUnitFoot = 2,
        kUnitInch = 3,
        kUnitIFoot = 4,
        kUnitClarkeFoot = 5,
        kUnitIInch = 6,
        kUnitCentimeter = 7,
        kUnitKilometer = 8,
        kUnitYard = 9,
        kUnitSearsYard = 10,
        kUnitMile = 11,
        kUnitIYard = 12,
        kUnitIMile = 13,
        kUnitKnot = 14,
        kUnitNautM = 15,
        kUnitLat66 = 16,
        kUnitLat83 = 17,
        kUnitDecimeter = 18,
        kUnitMillimeter = 19,
        kUnitDekameter = 20,
        kUnitHectometer = 21,
        kUnitGermanMeter = 22,
        kUnitCaGrid = 23,
        kUnitClarkeChain = 24,
        kUnitGunterChain = 25,
        kUnitBenoitChain = 26,
        kUnitSearsChain = 27,
        kUnitClarkeLink = 28,
        kUnitGunterLink = 29,
        kUnitBenoitLink = 30,
        kUnitSearsLink = 31,
        kUnitRod = 32,
        kUnitPerch = 33,
        kUnitPole = 34,
        kUnitFurlong = 35,
        kUnitRood = 36,
        kUnitCapeFoot = 37,
        kUnitBrealey = 38,
        kUnitSearsFoot = 39,
        kUnitGoldCoastFoot = 40,
        kUnitMicroInch = 41,
        kUnitIndianYard = 42,
        kUnitIndianFoot = 43,
        kUnitIndianFt37 = 44,
        kUnitIndianFt62 = 45,
        kUnitIndianFt75 = 46,
        kUnitIndianYd37 = 47,
        kUnitDecameter = 48,
        kUnitInternationalChain = 49,
        kUnitInternationalLink = 50,
        kUnitDegree = 1001,
        kUnitGrad = 1002,
        kUnitGrade = 1003,
        kUnitMapInfo = 1004,
        kUnitMil = 1005,
        kUnitMinute = 1006,
        kUnitRadian = 1007,
        kUnitSecond = 1008,
        kUnitDecisec = 1009,
        kUnitCentisec = 1010,
        kUnitMillisec = 1011,
    };

public:
    AcDbGeoCoordinateSystem();
    virtual ~AcDbGeoCoordinateSystem();

    static Acad::ErrorStatus create(const AcString&, AcDbGeoCoordinateSystem*&);
    static Acad::ErrorStatus createAll(AcArray<AcDbGeoCoordinateSystem*>&, const AcDbGeoCoordinateSystemCategory* = NULL);
    static Acad::ErrorStatus createAll(const AcGePoint3d&, AcArray<AcDbGeoCoordinateSystem*>&);

    virtual Acad::ErrorStatus getCartesianExtents(AcDbExtents2d&) const = 0;
    virtual Acad::ErrorStatus getDatum(AcDbGeoDatum&) const = 0;
    virtual Acad::ErrorStatus getDescription(AcString&) const = 0;
    virtual Acad::ErrorStatus getEllipsoid(AcDbGeoEllipsoid&) const = 0;
    virtual Acad::ErrorStatus getEpsgCode(int&) const = 0;
    virtual Acad::ErrorStatus getGeodeticExtents(AcDbExtents2d&) const = 0;
    virtual Acad::ErrorStatus getId(AcString&) const = 0;
    virtual Acad::ErrorStatus getOffset(AcGeVector2d&) const = 0;
    virtual Acad::ErrorStatus getProjectionCode(AcDbGeoCoordinateSystem::ProjectionCode&) const = 0;
    virtual Acad::ErrorStatus getProjectionParameters(AcArray<AcDbGeoProjectionParameter>&, bool) const = 0;
    virtual Acad::ErrorStatus getSource(AcString&) const = 0;
    virtual Acad::ErrorStatus getType(AcDbGeoCoordinateSystem::Type&) const = 0;
    virtual Acad::ErrorStatus getUnit(AcDb::UnitsValue&) const = 0;
    virtual Acad::ErrorStatus getUnit(AcDbGeoCoordinateSystem::Unit&) const = 0;
    virtual Acad::ErrorStatus getUnitScale(double&) const = 0;
    virtual Acad::ErrorStatus getWktRepresentation(AcString&) const = 0;
    virtual Acad::ErrorStatus getXmlRepresentation(AcString&) const = 0;

private:
    friend BrxDbGeoCoordinateSystemImp;
    BrxDbGeoCoordinateSystemImp* m_pBrxImp;
};