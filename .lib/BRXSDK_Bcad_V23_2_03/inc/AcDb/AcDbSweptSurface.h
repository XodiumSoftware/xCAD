// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbSurface.h"
#include "AcDb/AcDbSweepOptions.h"

/** _ */
class BRX_EXPORT AcDbSweptSurface: public AcDbSurface
{
public:
    ACDB_DECLARE_MEMBERS(AcDbSweptSurface);

    AcDbSweptSurface();
    virtual ~AcDbSweptSurface();

    virtual Acad::ErrorStatus createSweptSurface(AcDbEntity*,AcDbEntity*,AcDbSweepOptions&);
    virtual Acad::ErrorStatus dwgInFields(AcDbDwgFiler*);
    virtual Acad::ErrorStatus dwgOutFields(AcDbDwgFiler*) const;
    virtual Acad::ErrorStatus dxfInFields(AcDbDxfFiler*);
    virtual Acad::ErrorStatus dxfOutFields(AcDbDxfFiler*) const;
    virtual bool isDependent() const;

    Acad::ErrorStatus getPathLength(double&) const;
    Acad::ErrorStatus setSweepOptions(const AcDbSweepOptions&);
    AcDbEntity* getPathEntity() const;
    AcDbEntity* getSweepEntity() const;
    void getSweepOptions(AcDbSweepOptions&) const;

protected:
    virtual Acad::ErrorStatus subGetGripEntityUCS(const void*,AcGeVector3d&,AcGePoint3d&,AcGeVector3d&) const;
    virtual Acad::ErrorStatus subGetGripPoints(AcDbGripDataPtrArray&,const double,const int,const AcGeVector3d&,const int) const;
    virtual Acad::ErrorStatus subGetGripPoints(AcGePoint3dArray&,AcDbIntArray&,AcDbIntArray&) const;
    virtual void subList() const;
    virtual Acad::ErrorStatus subMoveGripPointsAt(const AcDbIntArray&,const AcGeVector3d&);
    virtual Acad::ErrorStatus subMoveStretchPointsAt(const AcDbIntArray&,const AcGeVector3d&);
};
