// Copyright (C) Menhirs NV. All rights reserved.
#pragma once
#include "COM/IAcadBaseDatabase.h"

/** _ */
template <const CLSID* pClsId>
class ATL_NO_VTABLE IAcadBaseDatabaseImpl :
    public IAcadBaseDatabase
{
public:
    IAcadBaseDatabaseImpl()
        : m_Database(NULL)
    {
    }

    virtual HRESULT STDMETHODCALLTYPE GetClassID(CLSID& clsId)
    {
        clsId = *pClsId;
        return S_OK;
    }

    virtual HRESULT STDMETHODCALLTYPE GetDatabase(AcDbDatabase** pDatabase)
    {
        if(NULL == pDatabase) {
            return E_POINTER;
        }
        *pDatabase = m_Database;
        return S_OK;
    }

    virtual HRESULT STDMETHODCALLTYPE SetDatabase(AcDbDatabase*& pDatabase)
    {
        m_Database = pDatabase;
        return S_OK;
    }

protected:
    AcDbDatabase* m_Database;
};

