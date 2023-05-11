// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "Misc/AcArray.h"
#include "Ads/AdsGlobal.h"
#include "AcDb/AcDbFullSubentPath.h"
#include "AcGe/AcGePoint3d.h"

class AcDbObjectId;

/** _ */
class AcEdSelectionSetService
{
public:
    virtual Acad::ErrorStatus add(resbuf*,const AcDbFullSubentPath* = NULL,const AcDbObjectId* = NULL) = 0;
    virtual Acad::ErrorStatus addSubentity(resbuf*,const AcDbFullSubentPath&) = 0;
    virtual Acad::ErrorStatus highlight(int,const AcDbFullSubentPath&) = 0;
    virtual Acad::ErrorStatus remove(int) = 0;
    virtual Acad::ErrorStatus removeSubentity(int,int) = 0;
    virtual Acad::ErrorStatus ssNameSubentities(bool,int,AcDbFullSubentPathArray&) = 0;
    virtual Acad::ErrorStatus ssNameSubentityX(bool,int,int,resbuf*&) = 0;
    virtual Acad::ErrorStatus ssNameX(bool,int,resbuf*&) = 0;
    virtual Acad::ErrorStatus add(const AcArray<resbuf*>&, const AcArray<AcDbFullSubentPath*>*, bool ) = 0;
    virtual Acad::ErrorStatus addSubentities(resbuf*, const AcDbFullSubentPathArray&, bool) = 0;
    virtual Acad::ErrorStatus remove(const AcArray<int>&) = 0;
    virtual Acad::ErrorStatus removeSubentities(int, const AcArray<int>&) = 0;
    virtual int subSelectionMode() = 0;
    virtual Acad::ErrorStatus getSubSelectionPoints(AcGePoint3dArray&) = 0;
};
