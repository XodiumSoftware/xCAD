// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcGe/AcGeGlobal.h"
#include "AcGi/AcGiGlobal.h"
#include "AcGi/AcGiParameter.h"
#include "PAL/api/FontPitchAndFamily.h"


class AcGiTextStyleImp;

/** _ */
class BRX_IMPORTEXPORT AcGiTextStyle: public AcGiParameter
{
public:
    ACRX_DECLARE_MEMBERS_READWRITE(AcGiTextStyle, AcGiTextStyleImp);

    AcGiTextStyle();
    AcGiTextStyle(const ACHAR*,const ACHAR*,const double,const double,const double,const double,const Adesk::Boolean,const Adesk::Boolean,const Adesk::Boolean,const Adesk::Boolean,const Adesk::Boolean,const ACHAR* = NULL);
    ~AcGiTextStyle();

    virtual Acad::ErrorStatus extentsBox(const ACHAR*,const Adesk::Boolean,const int,const Adesk::Boolean,AcGePoint2d&,AcGePoint2d&,AcGiWorldDraw* = NULL) const;
    virtual Acad::ErrorStatus setStyleName(const ACHAR*);
    virtual AcGePoint2d extents(const ACHAR*,const Adesk::Boolean,const int,const Adesk::Boolean,AcGiWorldDraw* = NULL) const;
    virtual Adesk::Boolean isBackward() const;
    virtual Adesk::Boolean isOverlined() const;
    virtual Adesk::Boolean isUnderlined() const;
    virtual Adesk::Boolean isUpsideDown() const;
    virtual Adesk::Boolean isVertical() const;
    virtual const ACHAR* bigFontFileName() const;
    virtual const ACHAR* fileName() const;
    virtual const ACHAR* styleName() const;
    virtual double obliquingAngle() const;
    virtual double textSize() const;
    virtual double trackingPercent() const;
    virtual double xScale() const;
    virtual int loadStyleRec(AcDbDatabase* = NULL) const;
    virtual void setBackward(const Adesk::Boolean);
    virtual void setBigFontFileName(const ACHAR*);
    virtual void setFileName(const ACHAR*);
    virtual void setObliquingAngle(const double);
    virtual void setOverlined(const Adesk::Boolean);
    virtual void setTextSize(const double);
    virtual void setTrackingPercent(const double);
    virtual void setUnderlined(const Adesk::Boolean);
    virtual void setUpsideDown(const Adesk::Boolean);
    virtual void setVertical(const Adesk::Boolean);
    virtual void setXScale(const double);

    //V10
    virtual bool preLoaded() const;
    virtual void setPreLoaded(bool);

    //V14
    virtual void setStrikethrough(const Adesk::Boolean);
    virtual Adesk::Boolean isStrikethrough() const;

    //V24
    Acad::ErrorStatus font(ACHAR*&,Adesk::Boolean&,Adesk::Boolean&,int&,int&) const; //deprecated
    Acad::ErrorStatus setFont(const ACHAR*,Adesk::Boolean,Adesk::Boolean,int,int); //deprecated
    Acad::ErrorStatus font(ACHAR*&,  bool&, bool&,  Charset&, Bricsys::BRX::PAL::FontUtils::FontPitch&, Bricsys::BRX::PAL::FontUtils::FontFamily&) const; // deprecated

    virtual Acad::ErrorStatus font(AcString&, bool&, bool&, Charset&, Bricsys::BRX::PAL::FontUtils::FontPitch&, Bricsys::BRX::PAL::FontUtils::FontFamily&) const;
    virtual Acad::ErrorStatus setFont(const ACHAR*, Adesk::Boolean, Adesk::Boolean, Charset, Bricsys::BRX::PAL::FontUtils::FontPitch, Bricsys::BRX::PAL::FontUtils::FontFamily);
};
