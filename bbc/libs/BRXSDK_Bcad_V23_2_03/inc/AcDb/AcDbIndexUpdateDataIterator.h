// Copyright (C) Menhirs NV. All rights reserved.
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
