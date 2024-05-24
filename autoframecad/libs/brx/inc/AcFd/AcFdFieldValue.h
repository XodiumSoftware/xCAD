// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbGlobal.h"
#include "AcGe/AcGeGlobal.h"
#include "Misc/AcValue.h"

typedef struct tagVARIANT VARIANT;

/** _ */
class AcFdFieldValue: public AcValue
{
public:
    ACRX_DECLARE_MEMBERS(AcFdFieldValue);

    AcFdFieldValue();

    AcFdFieldValue(const AcDbEvalVariant&);
    AcFdFieldValue(const AcDbObjectId&);
    AcFdFieldValue(const AcFdFieldValue&);
    AcFdFieldValue(const AcGePoint2d&);
    AcFdFieldValue(const AcGePoint3d&);
    AcFdFieldValue(const ACHAR*);
    AcFdFieldValue(const resbuf&);
    AcFdFieldValue(const SYSTEMTIME&);
    AcFdFieldValue(const VARIANT&);
    AcFdFieldValue(const void*,DWORD);
    AcFdFieldValue(DataType);
    AcFdFieldValue(double);
    AcFdFieldValue(double,double);
    AcFdFieldValue(double,double,double);
    AcFdFieldValue(long);

#ifndef _LINUXMAC64
    AcFdFieldValue(const __time64_t&);
#endif //!_LINUXMAC64
};
