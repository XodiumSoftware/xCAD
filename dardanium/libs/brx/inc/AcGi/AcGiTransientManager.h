// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "Misc/AcArray.h"

class AcGiDrawable;

enum AcGiTransientDrawingMode
{
    kAcGiMain             = 0,
    kAcGiSprite           = 1,
    kAcGiDirectShortTerm  = 2,
    kAcGiHighlight        = 3,
    kAcGiDirectTopmost    = 4,
    kAcGiContrast         = 5,
    kAcGiDrawingModeCount = 6,
};

/** _ */
class BRX_IMPORTEXPORT AcGiTransientManager
{
public:
    virtual ~AcGiTransientManager();

    virtual bool addTransient(AcGiDrawable*, AcGiTransientDrawingMode, int, const AcArray<int>&) = 0;
    virtual void updateTransient(AcGiDrawable*, const AcArray<int>&) = 0;
    virtual bool eraseTransient(AcGiDrawable*, const AcArray<int>&) = 0;

    virtual bool addChildTransient(AcGiDrawable*, AcGiDrawable*) = 0;
    virtual void updateChildTransient(AcGiDrawable*, AcGiDrawable*) = 0; 
    virtual bool eraseChildTransient(AcGiDrawable*, AcGiDrawable*) = 0;    

    virtual bool eraseTransients(AcGiTransientDrawingMode, int, const AcArray<int>&) = 0;
    virtual int  getFreeSubDrawingMode(AcGiTransientDrawingMode, int&, const AcArray<int>&) = 0;
};

void acgiSetTransientManager(AcGiTransientManager*);

BRX_IMPORTEXPORT AcGiTransientManager* acgiGetTransientManager();
