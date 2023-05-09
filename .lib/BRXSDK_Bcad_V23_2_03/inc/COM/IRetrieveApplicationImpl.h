// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "COM/IRetrieveApplication.h"

/** _ */
class ATL_NO_VTABLE IRetrieveApplicationImpl : public IRetrieveApplication
{
public:
    IRetrieveApplicationImpl()
        : m_App(NULL)
    {
    }

    virtual ~IRetrieveApplicationImpl()
    {
        if(m_App)
            m_App->Release(), m_App = NULL;
    }

    virtual HRESULT STDMETHODCALLTYPE SetApplicationObject(LPDISPATCH pApplicationObject)
    {
        if(m_App)
            return E_FAIL;
        m_App = pApplicationObject;
        if(m_App)
            m_App->AddRef();
        return S_OK;
    }

    virtual HRESULT STDMETHODCALLTYPE GetApplicationObject(LPDISPATCH* pApplicationObject)
    {
        *pApplicationObject = m_App;
        if(m_App)
            m_App->AddRef();
        return m_App ? S_OK : E_FAIL;
    }

protected:
    LPDISPATCH m_App;
};
