// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbXrecord.h"

/** _ */
class BRX_IMPORTEXPORT AcDbXrecordIterator: public AcRxObject
{
public:
    ACRX_DECLARE_MEMBERS(AcDbXrecordIterator);

protected:
    AcDbXrecordIterator() {}
public:
    AcDbXrecordIterator(const AcDbXrecord*);
    virtual ~AcDbXrecordIterator();

    Acad::ErrorStatus getCurResbuf(resbuf&,AcDbDatabase*) const;
    Acad::ErrorStatus next();
    bool done() const;
    int curRestype() const;
    void start();
};
