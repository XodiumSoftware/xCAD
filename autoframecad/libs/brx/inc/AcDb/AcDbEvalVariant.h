// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbGlobal.h"
#include "AcGe/AcGePoint2d.h"
#include "AcGe/AcGePoint3d.h"
#include "AcRx/AcRxObject.h"

/** _ */
class AcDbEvalVariant: public resbuf, public AcRxObject
{
public:
    ACRX_DECLARE_MEMBERS(AcDbEvalVariant);

    AcDbEvalVariant();
    AcDbEvalVariant(const AcDbEvalVariant&);
    AcDbEvalVariant(const AcDbEvalVariant*);
    AcDbEvalVariant(const AcDbObjectId&);
    AcDbEvalVariant(const AcGePoint2d&);
    AcDbEvalVariant(const AcGePoint3d&);
    AcDbEvalVariant(const ACHAR*);
    AcDbEvalVariant(double);
    AcDbEvalVariant(Adesk::Int32);
    AcDbEvalVariant(short);
    AcDbEvalVariant(const resbuf&);
    ~AcDbEvalVariant();

    virtual Acad::ErrorStatus copyFrom(const AcRxObject*);

    void clear();
protected:
    void init();

public:
    AcDbEvalVariant& operator=(const AcDbEvalVariant&);
    AcDbEvalVariant& operator=(const AcDbObjectId&);
    AcDbEvalVariant& operator=(const AcGePoint2d&);
    AcDbEvalVariant& operator=(const AcGePoint3d&);
    AcDbEvalVariant& operator=(const ACHAR*);
    AcDbEvalVariant& operator=(double);
    AcDbEvalVariant& operator=(Adesk::Int32);
    AcDbEvalVariant& operator=(short);
    AcDbEvalVariant& operator=(const resbuf&);

    AcDb::DwgDataType getType() const;

    /* AcRxValue + AcRxValueType not yet available with BRX
    Acad::ErrorStatus fromAcRxValue(const AcRxValue&);
    Acad::ErrorStatus toAcRxValue(const AcRxValueType&, AcRxValue&) const;
    */

    Acad::ErrorStatus dxfInFields(AcDbDxfFiler*);
    Acad::ErrorStatus dxfOutFields(AcDbDxfFiler*) const;

    Acad::ErrorStatus dwgInFields(AcDbDwgFiler*);
    Acad::ErrorStatus dwgOutFields(AcDbDwgFiler*) const;

    Acad::ErrorStatus getValue(AcGePoint2d&) const;
    Acad::ErrorStatus getValue(AcGePoint3d&) const;
    Acad::ErrorStatus getValue(AcDbObjectId&, AcDbDatabase* = NULL) const;
    Acad::ErrorStatus getValue(AcString&) const;
    Acad::ErrorStatus getValue(Adesk::Int32&) const;
    Acad::ErrorStatus getValue(short&) const;
    Acad::ErrorStatus getValue(double&) const;

    Acad::ErrorStatus setValue(AcDb::DxfCode, const AcGePoint2d&);
    Acad::ErrorStatus setValue(AcDb::DxfCode, const AcGePoint3d&);
    Acad::ErrorStatus setValue(AcDb::DxfCode, const AcDbObjectId&);
    Acad::ErrorStatus setValue(AcDb::DxfCode, const AcString&);
    Acad::ErrorStatus setValue(AcDb::DxfCode, const Adesk::Int32);
    Acad::ErrorStatus setValue(AcDb::DxfCode, const short);
    Acad::ErrorStatus setValue(AcDb::DxfCode, const double);

    bool operator== (const AcDbEvalVariant&) const;
    bool operator!= (const AcDbEvalVariant&) const;
    bool operator<  (const AcDbEvalVariant&) const;
    bool operator<= (const AcDbEvalVariant&) const;
    bool operator>  (const AcDbEvalVariant&) const;
    bool operator>= (const AcDbEvalVariant&) const;
};
