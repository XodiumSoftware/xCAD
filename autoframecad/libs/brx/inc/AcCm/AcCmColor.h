// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcCm/AcCmColorBase.h"
#include "AcCm/AcCmGlobal.h"
#include "AcDb/AcDbDwgFiler.h"
#include "AcDb/AcDbDxfFiler.h"

class BrxCmColorImp;

/** _ */
class BRX_IMPORTEXPORT AcCmColor : public AcCmColorBase
{
private:
    //BRX START
    friend class AcCmColorHelper;
    BrxCmColorImp* m_pBrxImp;
    //BRX END

public:
    static const Adesk::UInt16 MaxColorIndex;

    AcCmColor();
    AcCmColor(const AcCmColorBase&);
    AcCmColor(const AcCmColor&);
    ~AcCmColor();

    virtual Acad::ErrorStatus setBlue(Adesk::UInt8); //deprecated
    virtual Acad::ErrorStatus setColor(Adesk::UInt32); //deprecated
    virtual Acad::ErrorStatus setColorIndex(Adesk::UInt16);
    virtual Acad::ErrorStatus setColorMethod(AcCmEntityColor::ColorMethod); //deprecated
    virtual Acad::ErrorStatus setGreen(Adesk::UInt8); //deprecated
    virtual Acad::ErrorStatus setNames(const ACHAR*,const ACHAR* = NULL);
    virtual Acad::ErrorStatus setPenIndex(Adesk::UInt16);
    virtual Acad::ErrorStatus setRed(Adesk::UInt8); //deprecated
    virtual Acad::ErrorStatus setRGB(Adesk::UInt8,Adesk::UInt8,Adesk::UInt8);
    virtual AcCmEntityColor::ColorMethod colorMethod() const;
    virtual Adesk::UInt16 colorIndex() const;
    virtual Adesk::UInt16 penIndex() const;
    virtual Adesk::UInt32 color() const; //deprecated
    virtual Adesk::UInt8 blue() const;
    virtual Adesk::UInt8 green() const;
    virtual Adesk::UInt8 red() const;
    virtual bool hasBookName() const;
    virtual bool hasColorName() const;
    virtual bool isByACI() const;
    virtual bool isByBlock() const;
    virtual bool isByColor() const;
    virtual bool isByLayer() const;
    virtual bool isByPen () const;
    virtual bool isForeground() const;
    virtual const ACHAR* bookName() const;
    virtual const ACHAR* colorName() const;
    virtual const ACHAR* colorNameForDisplay();

    Acad::ErrorStatus audit(AcDbAuditInfo*);
    Acad::ErrorStatus dwgIn(AcDbDwgFiler*);
    Acad::ErrorStatus dwgInAsTrueColor(AcDbDwgFiler*);
    Acad::ErrorStatus dwgOut(AcDbDwgFiler*) const;
    Acad::ErrorStatus dwgOutAsTrueColor(AcDbDwgFiler*) const;
    Acad::ErrorStatus dxfIn(AcDbDxfFiler*,int = 0);
    Acad::ErrorStatus dxfOut(AcDbDxfFiler*,int = 0) const;
    Acad::ErrorStatus getDescription(ACHAR*&) const;
    Acad::ErrorStatus getExplanation(ACHAR*&) const;
    Acad::ErrorStatus getDescription(AcString&) const;
    Acad::ErrorStatus getExplanation(AcString&) const;

    Acad::ErrorStatus serializeIn(const void*,int*);
    Acad::ErrorStatus serializeOut(void*,int*,AcDb::AcDbDwgVersion = AcDb::kDHL_CURRENT) const;
    Acad::ErrorStatus setNamesFromDictionaryKey(const ACHAR*);
    AcCmComplexColor* complexColor() const;
    AcCmEntityColor entityColor() const;
    bool isNone() const;
    int dictionaryKeyLength() const;
    void getDictionaryKey(ACHAR*) const;
    void setComplexColor(AcCmComplexColor*);

    AcCmColor& operator=(const AcCmColor&);
    AcCmColor& operator=(const AcCmColorBase&);
    bool operator!=(const AcCmColor&) const;
    bool operator!=(const AcCmColorBase&) const;
    bool operator==(const AcCmColor&) const;
    bool operator==(const AcCmColorBase&) const;

    //ObjectArx 2021
    virtual void setNone();
    virtual void setByBlock();
    virtual void setForeground();
    virtual void setLayerOff();
    virtual void setByLayer();

    virtual Acad::ErrorStatus setCOLORREF(Adesk::ColorRef);
    virtual Adesk::ColorRef getCOLORREF() const;

    virtual Acad::ErrorStatus setRGB(Adesk::RGBQuad);
    virtual Adesk::RGBQuad getRGB() const;

    virtual Acad::ErrorStatus setRGBM(Adesk::UInt32);
    virtual Adesk::UInt32 getRGBM() const;
};
