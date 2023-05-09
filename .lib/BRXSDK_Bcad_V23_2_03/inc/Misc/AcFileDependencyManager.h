// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "Misc/AcFileDependencyInfo.h"

/** _ */
class BRX_IMPORTEXPORT AcFileDependencyManager
{
public:
    virtual ~AcFileDependencyManager() {}

    virtual Acad::ErrorStatus eraseEntry(const ACHAR*,const ACHAR*,const bool = false) = 0;
    virtual Acad::ErrorStatus eraseEntry(const Adesk::Int32,const bool = false) = 0;
    virtual Acad::ErrorStatus getEntry(const ACHAR*,const ACHAR*,AcFileDependencyInfo*&,const bool = false) = 0;
    virtual Acad::ErrorStatus getEntry(const Adesk::Int32,AcFileDependencyInfo*&,const bool = false) = 0;
    virtual Acad::ErrorStatus updateEntry(const ACHAR*,const ACHAR*) = 0;
    virtual Acad::ErrorStatus updateEntry(const Adesk::Int32) = 0;
    virtual Adesk::Int32 countEntries() = 0;
    virtual Adesk::Int32 createEntry(const ACHAR*,const ACHAR*,const bool = false,const bool = false) = 0;
    virtual Adesk::Int32 iteratorNext() = 0;
    virtual void iteratorInitialize(const ACHAR* = NULL,const bool = false,const bool = false,const bool = false) = 0;
};