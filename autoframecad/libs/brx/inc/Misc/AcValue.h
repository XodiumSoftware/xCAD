// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcRx/AcRxObject.h"

class AcDbDwgFiler;
class AcDbDxfFiler;
class AcDbEvalVariant;
class AcGePoint2d;
class AcGePoint3d;
struct resbuf;

/** _ */
class AcValue: public AcRxObject
{
public:
    enum DataType
    {
        kUnknown = 0,
        kLong = 1,
        kDouble = 2,
        kString = 4,
        kDate = 8,
        kPoint = 16,
        k3dPoint = 32,
        kObjectId = 64,
        kBuffer = 128,
        kResbuf = 256,
        kGeneral = 512,
        kColor = 1024,
    };

    //V10

    enum FormatOption
    {
        kFormatOptionNone = 0,
        kForEditing = 1,
        kForExpression = 2,
        kUseMaximumPrecision = 4,
        kIgnoreMtextFormat = 8
    };

    enum ParseOption
    {
        kParseOptionNone = 0,
        kSetDefaultFormat = 1,
        kPreserveMtextFormat = 2,
        kConvertTextToValue = 4,
        kChangeDataType = 8,
        kParseTextForFieldCode = 16,
    };

    enum UnitType
    {
        kUnitless = 0,
        kDistance = 1,
        kAngle = 2,
        kArea = 4,
        kVolume = 8,
        kCurrency = 16,
        kPercentage = 32,
        kAngleNotTransformed = 64,
    };

public:
    ACRX_DECLARE_MEMBERS(AcValue);

    AcValue();
    ~AcValue();

    AcValue(const AcDbEvalVariant&);
    AcValue(const AcDbObjectId&);
    AcValue(const AcGePoint2d&);
    AcValue(const AcGePoint3d&);
    AcValue(const ACHAR*);
    AcValue(const AcValue&);
    AcValue(const resbuf&);
    AcValue(const SYSTEMTIME&);
    AcValue(const VARIANT&);
    AcValue(const void*,DWORD);
    AcValue(const AcCmColor&);
    AcValue(DataType);
    AcValue(double);
    AcValue(double,double);
    AcValue(double,double,double);
    AcValue(Adesk::Int32);
    AcValue(const __time64_t&);
    AcValue(bool); // BRX only

    virtual Adesk::Boolean isEqualTo(const AcRxObject*) const;

    Acad::ErrorStatus dwgInFields(AcDbDwgFiler*);
    Acad::ErrorStatus dwgOutFields(AcDbDwgFiler*) const;
    Acad::ErrorStatus dxfInFields(AcDbDxfFiler*);
    Acad::ErrorStatus dxfOutFields(AcDbDxfFiler*) const;
    AcString format(const ACHAR*,FormatOption);
    AcString format(FormatOption);
    bool convertTo(DataType,UnitType);
    bool convertTo(DataType,UnitType,bool);
    bool format(ACHAR*&) const; //deprecated
    bool format(const ACHAR*,ACHAR*&) const; //deprecated
    bool get(AcDbEvalVariant&) const;
    bool get(AcDbObjectId&) const;
    bool get(AcGePoint2d&) const;
    bool get(AcGePoint3d&) const;
    bool get(ACHAR*&) const;
    bool get(const ACHAR*&) const;
    bool get(double&) const;
    bool get(double&,double&) const;
    bool get(double&,double&,double&) const;
    bool get(Adesk::Int32&) const;
    bool get(resbuf**) const;
    bool get(SYSTEMTIME&) const;
    bool get(VARIANT&) const;
    bool get(void*&,DWORD&) const;
    bool get(AcCmColor&) const;
    bool get(bool&) const; // BRX only
    bool isValid() const;
    bool parse(const ACHAR*,DataType,UnitType,const ACHAR*,ParseOption,const AcDbObjectId*);
    bool reset();
    bool reset(DataType);
    bool resetValue();
    bool set(const AcDbEvalVariant&);
    bool set(const AcDbObjectId&);
    bool set(const AcGePoint2d&);
    bool set(const AcGePoint3d&);
    bool set(const ACHAR*);
    bool set(const AcValue&);
    bool set(const resbuf&);
    bool set(const SYSTEMTIME&);
    bool set(const VARIANT&);
    bool set(const void*,DWORD);
    bool set(DataType,const ACHAR*);
    bool set(double);
    bool set(double,double);
    bool set(double,double,double);
    bool set(Adesk::Int32);
    bool set(const AcCmColor&);
    bool set(bool); // BRX only
    bool setFormat(const ACHAR*);
    bool setUnitType(UnitType);
    const ACHAR* format() const;
    const ACHAR* getFormat() const;
    DataType dataType() const;
    UnitType unitType() const;
    AcString format(const ACHAR*) const;
    bool format(AcString&) const;
    bool format(const ACHAR*, AcString&) const;

    bool get(__time64_t&) const;
    bool set(const __time64_t&);

    AcValue& operator=(const AcDbEvalVariant&);
    AcValue& operator=(const AcDbObjectId&);
    AcValue& operator=(const AcGePoint2d&);
    AcValue& operator=(const AcGePoint3d&);
    AcValue& operator=(const ACHAR*);
    AcValue& operator=(const AcValue&);
    AcValue& operator=(const resbuf&);
    AcValue& operator=(const VARIANT&);
    AcValue& operator=(double);
    AcValue& operator=(Adesk::Int32);
    AcValue& operator=(__time64_t);
    AcValue& operator=(const AcCmColor&);
    bool operator!=(const AcValue&) const;
    bool operator==(const AcValue&) const;
    operator AcDbObjectId() const;
    operator AcGePoint2d() const;
    operator AcGePoint3d() const;
    operator const ACHAR*() const;
    operator double() const;
    operator Adesk::Int32() const;
    operator __time64_t() const;

    static bool isValidDataType(const VARIANT&);
};
