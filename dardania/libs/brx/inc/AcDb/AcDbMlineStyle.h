// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcCm/AcCmColor.h"
#include "AcDb/AcDbObject.h"

#define MLINE_MAX_ELEMENTS 16
#define MSTYLE_DESCRIPTION_LENGTH 256
#define MSTYLE_NAME_LENGTH 32

#if !defined(BRX_API) // define for client builds
#define MSTYLE_DXF_FILL_ON           1
#define MSTYLE_DXF_SHOW_MITERS       2
#define MSTYLE_DXF_START_SQUARE_CAP  16
#define MSTYLE_DXF_START_INNER_ARCS  32
#define MSTYLE_DXF_START_ROUND_CAP   64
#define MSTYLE_DXF_END_SQUARE_CAP    256
#define MSTYLE_DXF_END_INNER_ARCS    512
#define MSTYLE_DXF_END_ROUND_CAP     1024
#define MSTYLE_DXF_JUST_TOP          4096
#define MSTYLE_DXF_JUST_ZERO         8192
#define MSTYLE_DXF_JUST_BOT          16384
#endif

// min 10 degrees / max 170 degeress
#define MIN_ANGLE 0.1745329251994329577
#define MAX_ANGLE 2.9670597283903602808

/** _ */
class BRX_EXPORT AcDbMlineStyle: public AcDbObject
{
public:
    ACDB_DECLARE_MEMBERS(AcDbMlineStyle);

    AcDbMlineStyle();
    virtual ~AcDbMlineStyle();

    virtual Acad::ErrorStatus copyFrom(const AcRxObject*);
    virtual Acad::ErrorStatus dwgInFields(AcDbDwgFiler*);
    virtual Acad::ErrorStatus dwgOutFields(AcDbDwgFiler*) const;
    virtual Acad::ErrorStatus dxfInFields(AcDbDxfFiler*);
    virtual Acad::ErrorStatus dxfOutFields(AcDbDxfFiler*) const;
    virtual Acad::ErrorStatus subErase(Adesk::Boolean = Adesk::kTrue);

    Acad::ErrorStatus addElement(int&,double,const AcCmColor&,AcDbObjectId,bool = true);
    Acad::ErrorStatus getElementAt(int,double&,AcCmColor&,AcDbObjectId&) const;
    Acad::ErrorStatus removeElementAt(int);
    Acad::ErrorStatus setDescription(const ACHAR*);
    Acad::ErrorStatus setElement(int&,double,const AcCmColor&,AcDbObjectId);
    Acad::ErrorStatus setEndAngle(double);
    Acad::ErrorStatus setFillColor(const AcCmColor&);
    Acad::ErrorStatus setName(const ACHAR*);
    Acad::ErrorStatus setStartAngle(double);
    bool endInnerArcs() const;
    bool endRoundCap() const;
    bool endSquareCap() const;
    bool filled() const;
    bool showMiters() const;
    bool startInnerArcs() const;
    bool startRoundCap() const;
    bool startSquareCap() const;
    const AcCmColor& fillColor() const;
    const ACHAR* description() const;
    const ACHAR* name() const;
    double endAngle() const;
    double startAngle() const;
    int numElements() const;
    void initMlineStyle();
    void set(const AcDbMlineStyle&,bool = true);
    void setEndInnerArcs(bool);
    void setEndRoundCap(bool);
    void setEndSquareCap(bool);
    void setFilled(bool);
    void setShowMiters(bool);
    void setStartInnerArcs(bool);
    void setStartRoundCap(bool);
    void setStartSquareCap(bool);
};
