// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#ifdef _WIN32
#pragma warning(disable:4786)
#endif

#include <memory.h>

#ifdef __cplusplus

/** _ */
template<class T> class AcArrayMemCopyReallocator
{
public:
    static void reallocateArray(T* pDest, const T* pSource, int num)
    {
        if (num <= 0)
            return;
        memcpy(pDest,pSource,sizeof(T)*num);
    }
};

#endif //__cplusplus
