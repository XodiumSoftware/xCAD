// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbLoftOptions.h"
#include "AcDb/AcDbSurface.h"

/** _ */
class BRX_EXPORT AcDbLoftedSurface: public AcDbSurface
{
public:
    ACDB_DECLARE_MEMBERS(AcDbLoftedSurface);

    AcDbLoftedSurface();
    virtual ~AcDbLoftedSurface();

    virtual Acad::ErrorStatus createLoftedSurface(AcArray<AcDbEntity*>&,AcArray<AcDbEntity*>&,AcDbEntity*,AcDbLoftOptions&);
    virtual Acad::ErrorStatus dwgInFields(AcDbDwgFiler*);
    virtual Acad::ErrorStatus dwgOutFields(AcDbDwgFiler*) const;
    virtual Acad::ErrorStatus dxfInFields(AcDbDxfFiler*);
    virtual Acad::ErrorStatus dxfOutFields(AcDbDxfFiler*) const;
    virtual bool isDependent() const;

    Acad::ErrorStatus setLoftOptions(const AcDbLoftOptions&);
    AcDbEntity* getCrossSection(int) const;
    AcDbEntity* getGuideCurve(int) const;
    AcDbEntity* getPathEntity() const;
    int numCrossSections() const;
    int numGuideCurves() const;
    void getLoftOptions(AcDbLoftOptions&) const;

protected:
    virtual Acad::ErrorStatus subGetGripEntityUCS(const void*,AcGeVector3d&,AcGePoint3d&,AcGeVector3d&) const;
    virtual Acad::ErrorStatus subGetGripPoints(AcDbGripDataPtrArray&,const double,const int,const AcGeVector3d&,const int) const;
    virtual Acad::ErrorStatus subGetGripPoints(AcGePoint3dArray&,AcDbIntArray&,AcDbIntArray&) const;
    virtual void subList() const;
    virtual Acad::ErrorStatus subMoveGripPointsAt(const AcDbIntArray&,const AcGeVector3d&);
    virtual Acad::ErrorStatus subMoveStretchPointsAt(const AcDbIntArray&,const AcGeVector3d&);
};
