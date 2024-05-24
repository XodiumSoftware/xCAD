// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#ifdef _WIN32
#pragma warning(disable:4786)
#endif

#ifdef __cplusplus

/** _ */
template<class T> class AcArrayObjectCopyReallocator
{
public:
    static void reallocateArray(T* pDest,const T* pSource,int num)
    {
        for (int i = 0; i < num; ++i)
        {
            pDest[i] = pSource[i];
        }
    }
};

#endif //__cplusplus
