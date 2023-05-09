// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbFullSubentPath.h"
#include "AcEd/AcEdInputContextReactor.h"
#include "AcEd/AcEdSubSelectFilterService.h"

/** _ */
class AcEdSSGetSubSelectFilter: public AcEdInputContextReactor
{
public:
    virtual Acad::ErrorStatus getSubentPathsAtGsMarker(AcDbEntity*,bool,const AcDbFullSubentPathArray&,AcDb::SubentType,Adesk::GsMarker,const AcGePoint3d&,const AcGeMatrix3d&,int&,AcDbFullSubentPath*&,int,AcDbObjectId*) = 0;
    virtual Acad::ErrorStatus subSelectClassList(AcArray<AcRxClass*>&) = 0;
    virtual void ssgetAddFilter(int,AcEdSubSelectFilterService&,const AcDbObjectId&,const AcDbFullSubentPathArray&,const AcDbFullSubentPathArray&) = 0;
    virtual void ssgetRemoveFilter(int,AcEdSubSelectFilterService&,const AcDbObjectId&,const AcDbFullSubentPathArray&,const AcDbFullSubentPathArray&) = 0;
};
