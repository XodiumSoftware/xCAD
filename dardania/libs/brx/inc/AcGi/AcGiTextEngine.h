// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcGi/AcGiTextStyle.h"

typedef void (*PolylineCallback)(int,const int*,const AcGePoint3d*,void*);
typedef void (*UnicodeCallback)(Adesk::LongPtr,const wchar_t*,int,void*);

/** _ */
class BRX_IMPORTEXPORT AcGiTextEngine
{
public:
    virtual ~AcGiTextEngine() {}

    virtual void getExtents(AcGiTextStyle&,const ACHAR*,int,bool,bool,AcGePoint2d&) = 0;
    virtual void tessellate(AcGiTextStyle&,ACHAR const*,int,bool,double,void*,PolylineCallback) = 0;
    virtual void tessellate(AcGiTextStyle&,ACHAR const*,int,bool,void*,UnicodeCallback,PolylineCallback) = 0;

    static AcGiTextEngine* create();
};