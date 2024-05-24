// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "Misc/MiscGlobal.h"

/** _ */
class BRX_IMPORTEXPORT AcDbClassIterator
{
public:
    enum
    {
        kAllClasses = 1,
        kCustomClasses = 2,
        kProxyClasses = 4
    };

protected:
    AcDbClassIterator();
    ~AcDbClassIterator();

public:
    virtual Acad::ErrorStatus start(AcDbDatabase*,int) = 0;
    virtual Adesk::UInt32 numInstances() const = 0;
    virtual bool done() const = 0;
    virtual bool isEntity() const = 0;
    virtual bool isProxy() const = 0;
    virtual bool next() = 0;
    virtual const ACHAR* appName() const = 0;
    virtual const ACHAR* dxfName() const = 0;
    virtual const ACHAR* name() const = 0;
    virtual void detach() = 0;

    static AcDbClassIterator* __stdcall newIterator();
    static void __stdcall deleteIterator(AcDbClassIterator*);
};
