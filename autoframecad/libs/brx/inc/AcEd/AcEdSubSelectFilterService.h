// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
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