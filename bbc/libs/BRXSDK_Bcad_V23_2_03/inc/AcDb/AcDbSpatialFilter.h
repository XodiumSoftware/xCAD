// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbFilter.h"

/** _ */
class BRX_EXPORT AcDbSpatialFilter: public AcDbFilter
{
public:
    ACDB_DECLARE_MEMBERS(AcDbSpatialFilter);

    AcDbSpatialFilter();
    AcDbSpatialFilter(const AcGePoint2dArray&,const AcGeVector3d&,double,double,double,Adesk::Boolean);
    virtual ~AcDbSpatialFilter();

    virtual AcRxClass* indexClass() const;
    virtual void queryBounds(AcDbExtents&,const AcDbBlockReference*) const;

    Acad::ErrorStatus getDefinition(AcGePoint2dArray&,AcGeVector3d&,double&,double&,double&,Adesk::Boolean&) const;
    Acad::ErrorStatus getVolume(AcGePoint3d&,AcGePoint3d&,AcGeVector3d&,AcGeVector2d&) const;
    Acad::ErrorStatus setDefinition(const AcGePoint2dArray&,const AcGeVector3d&,double,double,double,Adesk::Boolean);
    Acad::ErrorStatus setPerspectiveCamera(const AcGePoint3d&);
    Adesk::Boolean clipVolumeIntersectsExtents(const AcDbExtents&) const;
    Adesk::Boolean hasPerspectiveCamera() const;
    void queryBounds(AcDbExtents&) const;
    AcGeMatrix3d& getOriginalInverseBlockXform(AcGeMatrix3d&) const;

    AcGeMatrix3d& getClipSpaceToWCSMatrix(AcGeMatrix3d&) const;
    bool isInverted() const;
    Acad::ErrorStatus setInverted(bool);
};
