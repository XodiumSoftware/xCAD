// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbObjectId.h"

// IOPMPropertyDialog interface
// {6A4EF964-9028-45F8-AE76-EBFAB6BC53C5}
DEFINE_GUID(IID_IOPMPropertyDialog, 0x6a4ef964, 0x9028, 0x45f8, 0xae, 0x76, 0xeb, 0xfa, 0xb6, 0xbc, 0x53, 0xc5);

interface DECLSPEC_UUID("6A4EF964-9028-45F8-AE76-EBFAB6BC53C5")
IOPMPropertyDialog : public IUnknown
{
    BEGIN_INTERFACE

    STDMETHOD(QueryInterface)(REFIID riid, void** ppvObj) = 0;
    STDMETHOD_(ULONG, AddRef)() = 0;
    STDMETHOD_(ULONG, Release)() = 0;

    STDMETHOD(DoModal)(BSTR* propValueString, AcDbObjectIdArray * ObjectIdArray) = 0;
};
typedef IOPMPropertyDialog FAR* LPPROPERTYDIALOG;


// IOPMPropertyDialog2 interface
// {544E10CC-ACD9-4799-90E4-8E80E2EC38E2}
DEFINE_GUID(IID_IOPMPropertyDialog2, 0x544e10cc, 0xacd9, 0x4799, 0x90, 0xe4, 0x8e, 0x80, 0xe2, 0xec, 0x38, 0xe2);

interface DECLSPEC_UUID("544E10CC-ACD9-4799-90E4-8E80E2EC38E2")
IOPMPropertyDialog2 : public IUnknown
{
    BEGIN_INTERFACE

    STDMETHOD(QueryInterface)(REFIID riid, void** ppvObj) = 0;
    STDMETHOD_(ULONG, AddRef)() = 0;
    STDMETHOD_(ULONG, Release)() = 0;

    STDMETHOD(DoModal)(BSTR* propValueString, VARIANT ObjectUnknownArray) = 0;
};
typedef IOPMPropertyDialog2 FAR* LPPROPERTYDIALOG2;
