// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbSurface.h"

/** _ */
class BRX_EXPORT AcDbPlaneSurface: public AcDbSurface
{
public:
    ACDB_DECLARE_MEMBERS(AcDbPlaneSurface);

    AcDbPlaneSurface();
    virtual ~AcDbPlaneSurface();

    virtual Acad::ErrorStatus createFromRegion(AcDbRegion*);
    virtual Acad::ErrorStatus dwgInFields(AcDbDwgFiler*);
    virtual Acad::ErrorStatus dwgOutFields(AcDbDwgFiler*) const;
    virtual Acad::ErrorStatus dxfInFields(AcDbDxfFiler*);
    virtual Acad::ErrorStatus dxfOutFields(AcDbDxfFiler*) const;
    virtual bool isDependent() const;

protected:
    virtual Acad::ErrorStatus subGetGripPoints(AcDbGripDataPtrArray&,const double,const int,const AcGeVector3d&,const int) const;
    virtual Acad::ErrorStatus subGetGripPoints(AcGePoint3dArray&,AcDbIntArray&,AcDbIntArray&) const;
    virtual void subList() const;
    virtual Acad::ErrorStatus subMoveGripPointsAt(const AcDbIntArray&,const AcGeVector3d&);
    virtual Acad::ErrorStatus subMoveStretchPointsAt(const AcDbIntArray&,const AcGeVector3d&);
};
