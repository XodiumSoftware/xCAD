// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbNamedPath.h"

/** _ */
class BRX_EXPORT AcDbCurvePath: public AcDbNamedPath
{
public:
    ACRX_DECLARE_MEMBERS(AcDbCurvePath);

    AcDbCurvePath();
    virtual ~AcDbCurvePath();

    virtual Acad::ErrorStatus dwgInFields(AcDbDwgFiler*);
    virtual Acad::ErrorStatus dwgOutFields(AcDbDwgFiler*) const;
    virtual Acad::ErrorStatus dxfInFields(AcDbDxfFiler*);
    virtual Acad::ErrorStatus dxfOutFields(AcDbDxfFiler*) const;
    virtual Acad::ErrorStatus getGeometry(AcGeCurve3d*&) const;

    Acad::ErrorStatus setGeometry(const AcDbObjectId&);
    AcDbObjectId entityId() const;

protected:
    virtual Adesk::UInt32 subSetAttributes(AcGiDrawableTraits*);
};
