// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbIndexUpdateData.h"

/** _ */
class BRX_IMPORTEXPORT AcDbIndexUpdateDataIterator
{
public:
    AcDbIndexUpdateDataIterator(const AcDbIndexUpdateData*);
    ~AcDbIndexUpdateDataIterator();

    Acad::ErrorStatus currentData(AcDbObjectId&,Adesk::UInt8&,Adesk::UInt32&) const;
    bool done();
    void next();
    void start();
};
