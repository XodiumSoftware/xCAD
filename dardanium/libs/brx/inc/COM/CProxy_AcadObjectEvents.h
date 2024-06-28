// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#ifdef _WIN32

#include <atlcom.h>

/** _ */
template <class T>
class CProxy_AcadObjectEvents 
    : public IConnectionPointImpl<T, &IID_IAcadObjectEvents, CComDynamicUnkArray>
{
public:
    void Fire_Modified()
    {
        T* pT = static_cast<T*>(this);
        pT->Lock();
        for(IUnknown** pI = this->m_vec.begin(); pI < this->m_vec.end(); pI++)
            if(*pI) reinterpret_cast<IAcadObjectEvents*>(*pI)->Modified(static_cast<IAcadObject*>(pT));
        pT->Unlock();
    }
};

#endif // _WIN32
