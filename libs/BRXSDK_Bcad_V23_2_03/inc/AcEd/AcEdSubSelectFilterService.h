// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "Ads/AdsGlobal.h"

class AcDbFullSubentPath;

/** _ */
class AcEdSubSelectFilterService
{
public:
    virtual Acad::ErrorStatus add(resbuf*,const AcDbFullSubentPath&) = 0;
    virtual Acad::ErrorStatus remove(bool,int) = 0;
    virtual Acad::ErrorStatus ssNameX(bool,int,resbuf*&) = 0;
};