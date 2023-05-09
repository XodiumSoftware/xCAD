// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbIndexUpdateData.h"

/** _ */
class BRX_IMPORTEXPORT AcDbBlockChangeIterator
{
private:
    AcDbBlockChangeIterator();
    AcDbBlockChangeIterator(const AcDbBlockChangeIterator&);
    ~AcDbBlockChangeIterator();

public:
    Acad::ErrorStatus curIdInfo(AcDbObjectId&,Adesk::UInt8&,Adesk::UInt32&) const;
    Acad::ErrorStatus setCurIdInfo(Adesk::UInt8,Adesk::UInt32);
    AcDbIndexUpdateData* updateData() const;
    AcDbObjectId id() const;
    bool done();
    void clearProcessedFlags();
    void next();
    void start();
};