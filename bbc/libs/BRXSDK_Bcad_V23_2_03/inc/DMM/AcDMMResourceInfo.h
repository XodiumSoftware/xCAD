// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include <vector>

/** _ */
class BRX_IMPORTEXPORT AcDMMResourceInfo
{
public:
    AcDMMResourceInfo();
    AcDMMResourceInfo(const wchar_t*,const wchar_t*,const wchar_t*);
    AcDMMResourceInfo(const AcDMMResourceInfo&);
    ~AcDMMResourceInfo();

    const wchar_t* GetMime();
    const wchar_t* GetPath();
    const wchar_t* GetRole();
    void SetMime(wchar_t*);
    void SetPath(wchar_t*);
    void SetRole(wchar_t*);

    AcDMMResourceInfo& operator=(const AcDMMResourceInfo&);
};

typedef AcArray<AcDMMResourceInfo, AcArrayObjectCopyReallocator<AcDMMResourceInfo> > AcDMMResourceVec;
