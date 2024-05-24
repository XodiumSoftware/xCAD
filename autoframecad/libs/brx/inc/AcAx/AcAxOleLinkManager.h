// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbDatabase.h"

/** _ */
class AcAxOleLinkManager
{
public:
    virtual Adesk::Boolean SetDocIDispatch(AcDbDatabase*,IDispatch*) = 0;
    virtual Adesk::Boolean SetIUnknown(AcDbDatabase*,IUnknown*) = 0;
    virtual Adesk::Boolean SetIUnknown(AcDbObject*,const AcDbSubentId&,IUnknown*) = 0;
    virtual Adesk::Boolean SetIUnknown(AcDbObject*,IUnknown*) = 0;
    virtual IDispatch* GetDocIDispatch(AcDbDatabase*) = 0;
    virtual IUnknown* GetIUnknown(AcDbDatabase*) = 0;
    virtual IUnknown* GetIUnknown(AcDbObject*) = 0;
    virtual IUnknown* GetIUnknown(AcDbObject*,const AcDbSubentId&) = 0;
};