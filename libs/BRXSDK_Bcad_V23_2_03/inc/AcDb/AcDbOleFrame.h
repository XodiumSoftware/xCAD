// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbFrame.h"

/** _ */
class BRX_EXPORT AcDbOleFrame: public AcDbFrame
{
public:
    ACDB_DECLARE_MEMBERS(AcDbOleFrame);

    AcDbOleFrame();
    virtual ~AcDbOleFrame();

    virtual Acad::ErrorStatus dwgInFields(AcDbDwgFiler*);
    virtual Acad::ErrorStatus dwgOutFields(AcDbDwgFiler*) const;
    virtual Acad::ErrorStatus dxfInFields(AcDbDxfFiler*);
    virtual Acad::ErrorStatus dxfOutFields(AcDbDxfFiler*) const;
    virtual void setOleObject(const void*);
    virtual void* getOleObject() const;

protected:
    virtual Acad::ErrorStatus subGetGeomExtents(AcDbExtents&) const;
    virtual void subViewportDraw(AcGiViewportDraw*);
    virtual Adesk::Boolean subWorldDraw(AcGiWorldDraw*);
};
