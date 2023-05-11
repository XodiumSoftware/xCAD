// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbNamedPath.h"

/** _ */
class BRX_EXPORT AcDbPointPath: public AcDbNamedPath
{
public:
    ACRX_DECLARE_MEMBERS(AcDbPointPath);

    AcDbPointPath();
    virtual ~AcDbPointPath();

    virtual Acad::ErrorStatus dwgInFields(AcDbDwgFiler*);
    virtual Acad::ErrorStatus dwgOutFields(AcDbDwgFiler*) const;
    virtual Acad::ErrorStatus dxfInFields(AcDbDxfFiler*);
    virtual Acad::ErrorStatus dxfOutFields(AcDbDxfFiler*) const;
    virtual Acad::ErrorStatus getGeometry(AcGeCurve3d*&) const;

    Acad::ErrorStatus setGeometry(const AcGePoint3d&);

protected:
    virtual Adesk::UInt32 subSetAttributes(AcGiDrawableTraits*);
};
