// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "Misc/MiscGlobal.h"

namespace AcDmUtil
{
    Acad::ErrorStatus findArrowId(const ACHAR*,AcDbObjectId&,AcDbDatabase* = NULL);
    Acad::ErrorStatus getArrowId(const ACHAR*,AcDbObjectId&,AcDbDatabase* = NULL);
    bool isBuiltInArrow(const ACHAR*);
    bool isZeroLengthArrow(const ACHAR*);
    const ACHAR* arrowName(AcDbObjectId);
    const ACHAR* arrowName(const ACHAR*);
    const ACHAR* globalArrowName(AcDbObjectId);
    const ACHAR* globalArrowName(const ACHAR*);
    int dimatfit(int);
    int dimfit(int,int);
    int dimfrac(int);
    int dimlunit(int);
    int dimtmove(int);
    int dimunit(int,int);
};