// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbHyperlink.h"

/** _ */
class BRX_IMPORTEXPORT AcDbHyperlinkCollection
{
public:
    AcDbHyperlinkCollection() {}
    virtual ~AcDbHyperlinkCollection() {}

    virtual AcDbHyperlink* item(const int) const = 0;
    virtual int count() const = 0;
    virtual void addAt(const int,const ACHAR*,const ACHAR*,const ACHAR* = NULL) = 0;
    virtual void addHead(const ACHAR*,const ACHAR*,const ACHAR* = NULL) = 0;
    virtual void addTail(const ACHAR*,const ACHAR*,const ACHAR* = NULL) = 0;
    virtual void removeAt(const int) = 0;
    virtual void removeHead() = 0;
    virtual void removeTail() = 0;
};
