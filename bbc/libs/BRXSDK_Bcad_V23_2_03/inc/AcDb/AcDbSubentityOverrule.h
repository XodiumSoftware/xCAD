// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcRx/AcRxOverrule.h"


/** _ */
class BRX_IMPORTEXPORT AcDbSubentityOverrule : public AcRxOverrule
{
public:
    ACRX_DECLARE_MEMBERS(AcDbSubentityOverrule);

    AcDbSubentityOverrule();

    virtual Acad::ErrorStatus addSubentPaths(AcDbEntity*, const AcDbFullSubentPathArray&);
    virtual Acad::ErrorStatus deleteSubentPaths(AcDbEntity*, const AcDbFullSubentPathArray&);
    virtual Acad::ErrorStatus getCompoundObjectTransform(const AcDbEntity*, AcGeMatrix3d&);
    virtual Acad::ErrorStatus getGripPointsAtSubentPath(const AcDbEntity*, const AcDbFullSubentPath&, AcDbGripDataPtrArray&,
        const double, const int, const AcGeVector3d&, const int);
    virtual Acad::ErrorStatus getGsMarkersAtSubentPath(const AcDbEntity*, const AcDbFullSubentPath&, AcArray<Adesk::GsMarker>&);
    virtual Acad::ErrorStatus getSubentClassId(const AcDbEntity*, const AcDbFullSubentPath&, CLSID*);
    virtual Acad::ErrorStatus getSubentPathGeomExtents(const AcDbEntity*, const AcDbFullSubentPath&, AcDbExtents&);
    virtual Acad::ErrorStatus getSubentPathsAtGsMarker(const AcDbEntity*, AcDb::SubentType, Adesk::GsMarker, const AcGePoint3d&,
        const AcGeMatrix3d&, int&, AcDbFullSubentPath*&, int = 0, AcDbObjectId* = NULL);
    virtual Acad::ErrorStatus moveGripPointsAtSubentPaths(AcDbEntity*, const AcDbFullSubentPathArray&, const AcDbVoidPtrArray&,
        const AcGeVector3d&, const int);
    virtual void subentGripStatus(AcDbEntity*, const AcDb::GripStat, const AcDbFullSubentPath&);
    virtual AcDbEntity* subentPtr(const AcDbEntity*, const AcDbFullSubentPath&);
    virtual Acad::ErrorStatus transformSubentPathsBy(AcDbEntity*, const AcDbFullSubentPathArray&, const AcGeMatrix3d&);
};
