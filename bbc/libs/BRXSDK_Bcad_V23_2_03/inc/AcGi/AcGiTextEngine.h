// Copyright (C) Menhirs NV. All rights reserved.
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