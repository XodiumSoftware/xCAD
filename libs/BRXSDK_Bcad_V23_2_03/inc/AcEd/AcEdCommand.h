// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcEd/AcEdGlobal.h"

/** _ */
class BRX_IMPORTEXPORT AcEdCommand: public AcRxObject
{
public:
    ACRX_DECLARE_MEMBERS(AcEdCommand);

    virtual AcEdUIContext* UIContext() const = 0;
    virtual AcRxFunctionPtr functionAddr() const = 0;
    virtual Adesk::Int32 commandFlags() const = 0;
    virtual const ACHAR* globalName() const = 0;
    virtual const ACHAR* localName() const = 0;
    virtual const HINSTANCE resourceHandle() const = 0;
    virtual int functionCode() const = 0;
    virtual void commandUndef(bool) = 0;
    virtual void functionAddr(AcRxFunctionPtr) = 0;
    virtual void functionCode(int) = 0;
    virtual void* commandApp() const = 0;
};
