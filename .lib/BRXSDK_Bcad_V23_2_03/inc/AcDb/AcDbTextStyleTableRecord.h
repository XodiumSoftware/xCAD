// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbSymbolTableRecord.h"
#include "PAL/api/FontPitchAndFamily.h"

/** _ */
class BRX_EXPORT AcDbTextStyleTableRecord: public AcDbSymbolTableRecord
{
public:
    typedef AcDbTextStyleTable TableType;

    ACDB_DECLARE_MEMBERS(AcDbTextStyleTableRecord);

    AcDbTextStyleTableRecord();
    virtual ~AcDbTextStyleTableRecord();

    Acad::ErrorStatus bigFontFileName(ACHAR*&) const;
    Acad::ErrorStatus bigFontFileName(const ACHAR*&) const;
    Acad::ErrorStatus bigFontFileName(AcString&) const;
    Acad::ErrorStatus fileName(ACHAR*&) const;
    Acad::ErrorStatus fileName(const ACHAR*&) const;
    Acad::ErrorStatus font(ACHAR*&, Adesk::Boolean&, Adesk::Boolean&, int&, int&) const; //deprecated
    Acad::ErrorStatus font(ACHAR*&, Adesk::Boolean&, Adesk::Boolean&, Charset&,
        Bricsys::BRX::PAL::FontUtils::FontPitch&, Bricsys::BRX::PAL::FontUtils::FontFamily&) const; //deprecated
    Acad::ErrorStatus font(AcString&, Adesk::Boolean&, Adesk::Boolean&, Charset&, Bricsys::BRX::PAL::FontUtils::FontPitch&,
        Bricsys::BRX::PAL::FontUtils::FontFamily&) const;
    Acad::ErrorStatus setBigFontFileName(const ACHAR*);
    Acad::ErrorStatus setFileName(const ACHAR*);
    Acad::ErrorStatus setFont(const ACHAR*, Adesk::Boolean,Adesk::Boolean,int,int); //deprecated
    Acad::ErrorStatus setFont(const ACHAR*, Adesk::Boolean, Adesk::Boolean,
        Charset, Bricsys::BRX::PAL::FontUtils::FontPitch,
        Bricsys::BRX::PAL::FontUtils::FontFamily, Adesk::Boolean = Adesk::kFalse);
    Acad::ErrorStatus setObliquingAngle(double);
    Acad::ErrorStatus setPriorSize(double);
    Acad::ErrorStatus setTextSize(double);
    Acad::ErrorStatus setXScale(double);
    Adesk::Boolean isShapeFile() const;
    Adesk::Boolean isVertical() const;
    Adesk::UInt8 flagBits() const;
    double obliquingAngle() const;
    double priorSize() const;
    double textSize() const;
    double xScale() const;
    void setFlagBits(Adesk::UInt8);
    void setIsShapeFile(Adesk::Boolean);
    void setIsVertical(Adesk::Boolean);
};
