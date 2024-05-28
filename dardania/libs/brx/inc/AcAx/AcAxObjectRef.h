// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbObjectId.h"

/** _ */
class BRX_IMPORTEXPORT AcAxObjectRef
{
public:
    AcAxObjectRef();
    AcAxObjectRef(AcDbObject*&);
    AcAxObjectRef(AcDbObjectId);
private:
    AcAxObjectRef(AcAxObjectRef&);
public:
    ~AcAxObjectRef();

    Acad::ErrorStatus acquire(AcDbObjectId);
    Acad::ErrorStatus acquire(AcDbObject*&);
    Acad::ErrorStatus release(AcDbObjectId&,AcDbObject*&);
    bool isNull();
    AcDbObjectId objectId();

private:
    AcAxObjectRef& operator=(AcAxObjectRef&);

private:
    void * m_pImp;
};