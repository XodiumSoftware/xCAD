// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
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
