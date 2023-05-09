// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcRx/AcRxObject.h"

#ifdef __cplusplus

/** _ */
class BRX_IMPORTEXPORT AcRxClass: public AcRxObject
{
public:
    ACRX_DECLARE_MEMBERS(AcRxClass);

public:
    virtual AcRx::Ordering comparedTo(const AcRxObject*) const = 0;
    virtual AcRxClass* myParent() const = 0;
    virtual AcRxObject* addX(AcRxClass*,AcRxObject*) = 0;
    virtual AcRxObject* create() = 0;
    virtual AcRxObject* delX(AcRxClass*) = 0;
    virtual AcRxObject* getX(const AcRxClass*) = 0;
    virtual AcRxObject* queryX(const AcRxClass*) = 0;
    virtual AppNameChangeFuncPtr appNameCallbackPtr() const = 0;
    virtual bool isDerivedFrom(const AcRxClass*) const = 0;
    virtual const ACHAR* appName() const = 0;
    virtual const ACHAR* dxfName() const = 0;
    virtual const ACHAR* name() const = 0;
    virtual int proxyFlags() const = 0;
    virtual void getClassVersion(int&,int&) const = 0;

    //V13
    virtual Adesk::UInt32 customFlags() const = 0;

    //V19
private:
    void isKindOf(void*); //link error indicates incorrect usage (isDerivedFrom intended?)
public:
    static bool isDerivedFrom(const AcRxClass*, const AcRxClass*);
};

#endif //__cplusplus
