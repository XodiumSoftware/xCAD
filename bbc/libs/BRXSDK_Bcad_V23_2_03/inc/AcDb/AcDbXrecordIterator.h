// Copyright (C) Menhirs NV. All rights reserved.
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
