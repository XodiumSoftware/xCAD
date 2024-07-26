// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbRevolveOptions.h"
#include "AcDb/AcDbSurface.h"

/** _ */
class BRX_EXPORT AcDbRevolvedSurface: public AcDbSurface
{
public:
    ACDB_DECLARE_MEMBERS(AcDbRevolvedSurface);

    AcDbRevolvedSurface();
    virtual ~AcDbRevolvedSurface();

    virtual Acad::ErrorStatus createRevolvedSurface(AcDbEntity*,const AcGePoint3d&,const AcGeVector3d&,double,double,AcDbRevolveOptions&);
    virtual Acad::ErrorStatus dwgInFields(AcDbDwgFiler*);
    virtual Acad::ErrorStatus dwgOutFields(AcDbDwgFiler*) const;
    virtual Acad::ErrorStatus dxfInFields(AcDbDxfFiler*);
    virtual Acad::ErrorStatus dxfOutFields(AcDbDxfFiler*) const;
    virtual bool isDependent() const;

    Acad::ErrorStatus setAxisPnt(const AcGePoint3d&);
    Acad::ErrorStatus setAxisVec(const AcGeVector3d&);
    Acad::ErrorStatus setRevolve(const AcGePoint3d&,const AcGeVector3d&,double,const AcDbRevolveOptions&);
    Acad::ErrorStatus setRevolveAngle(double);
    Acad::ErrorStatus setRevolveOptions(const AcDbRevolveOptions&);
    AcDbEntity* getRevolveEntity() const;
    AcGePoint3d getAxisPnt() const;
    AcGeVector3d getAxisVec() const;
    double getRevolveAngle() const;
    double getStartAngle() const;
    void getRevolveOptions(AcDbRevolveOptions&) const;

protected:
    virtual Acad::ErrorStatus subGetGripEntityUCS(const void*,AcGeVector3d&,AcGePoint3d&,AcGeVector3d&) const;
    virtual Acad::ErrorStatus subGetGripPoints(AcDbGripDataPtrArray&,const double,const int,const AcGeVector3d&,const int) const;
    virtual Acad::ErrorStatus subGetGripPoints(AcGePoint3dArray&,AcDbIntArray&,AcDbIntArray&) const;
    virtual void subList() const;
    virtual Acad::ErrorStatus subMoveGripPointsAt(const AcDbIntArray&,const AcGeVector3d&);
    virtual Acad::ErrorStatus subMoveStretchPointsAt(const AcDbIntArray&,const AcGeVector3d&);
};
