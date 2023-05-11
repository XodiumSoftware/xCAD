// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "Misc/AcArray.h"

class AcApProfileStorage;
class AcApProfileManagerReactor;
typedef AcArray<ACHAR*> AcApProfileNameArray;

/** _ */
class AcApProfileManager
{
public:
    virtual Acad::ErrorStatus FixedProfileStorage(AcApProfileStorage*&,BOOL = TRUE) = 0;
    virtual Acad::ErrorStatus ProfileCopy(const ACHAR*,const ACHAR*,const ACHAR*) = 0;
    virtual Acad::ErrorStatus ProfileDelete(const ACHAR*) = 0;
    virtual Acad::ErrorStatus ProfileExport(const ACHAR*,const ACHAR*) = 0;
    virtual Acad::ErrorStatus ProfileImport(const ACHAR*,const ACHAR*,const ACHAR*,Adesk::Boolean) = 0;
    virtual Acad::ErrorStatus ProfileRename(const ACHAR*,const ACHAR*,const ACHAR*) = 0;
    virtual Acad::ErrorStatus ProfileReset(const ACHAR*) = 0;
    virtual Acad::ErrorStatus ProfileSetCurrent(const ACHAR*) = 0;
    virtual Acad::ErrorStatus ProfileStorage(AcApProfileStorage*&,const ACHAR*,BOOL = TRUE) = 0;
    virtual int ProfileListNames(AcApProfileNameArray&) = 0;
    virtual void addReactor(AcApProfileManagerReactor*) = 0;
    virtual void ProfileRegistryKey(ACHAR*&,const ACHAR*) = 0;
    virtual void removeReactor(AcApProfileManagerReactor*) = 0;
};
