// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbSurface.h"
#include "AcDb/AcDbSweepOptions.h"

/** _ */
class BRX_EXPORT AcDbExtrudedSurface: public AcDbSurface
{
public:
    ACDB_DECLARE_MEMBERS(AcDbExtrudedSurface);

    AcDbExtrudedSurface();
    virtual ~AcDbExtrudedSurface();

    virtual Acad::ErrorStatus createExtrudedSurface(AcDbEntity*,const AcGeVector3d&,AcDbSweepOptions&);
    virtual Acad::ErrorStatus dwgInFields(AcDbDwgFiler*);
    virtual Acad::ErrorStatus dwgOutFields(AcDbDwgFiler*) const;
    virtual Acad::ErrorStatus dxfInFields(AcDbDxfFiler*);
    virtual Acad::ErrorStatus dxfOutFields(AcDbDxfFiler*) const;
    virtual bool isDependent() const;

    Acad::ErrorStatus setExtrude(const AcGeVector3d&,const AcDbSweepOptions&);
    Acad::ErrorStatus setHeight(double);
    Acad::ErrorStatus setSweepOptions(const AcDbSweepOptions&);
    Acad::ErrorStatus setSweepVec(const AcGeVector3d&);
    AcDbEntity* getSweepEntity() const;
    AcGeVector3d getSweepVec() const;
    double getHeight() const;
    void getSweepOptions(AcDbSweepOptions&) const;

protected:
    virtual Acad::ErrorStatus subGetGripEntityUCS(const void*,AcGeVector3d&,AcGePoint3d&,AcGeVector3d&) const;
    virtual Acad::ErrorStatus subGetGripPoints(AcDbGripDataPtrArray&,const double,const int,const AcGeVector3d&,const int) const;
    virtual Acad::ErrorStatus subGetGripPoints(AcGePoint3dArray&,AcDbIntArray&,AcDbIntArray&) const;
    virtual Acad::ErrorStatus subMoveGripPointsAt(const AcDbIntArray&,const AcGeVector3d&);
    virtual Acad::ErrorStatus subMoveStretchPointsAt(const AcDbIntArray&,const AcGeVector3d&);
    virtual void subList() const;
};
