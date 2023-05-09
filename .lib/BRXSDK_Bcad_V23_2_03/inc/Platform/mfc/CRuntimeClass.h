// Copyright (C) 2010-2014 Menhirs NV. All rights reserved.

// Windows MFC CObject type and functions

#pragma once

#ifndef _BS_MFC_CRUNTIMECLASS_INCLUDED_
#define _BS_MFC_CRUNTIMECLASS_INCLUDED_

#ifndef BRXEXPORT // for client build : import
#define BRXEXPORT
#endif

// ========== Platform independent ==========

#ifdef _WIN32
namespace Mfc
{
#endif

class CObject;

struct BRXEXPORT CRuntimeClass
{

    LPCSTR m_lpszClassName;
    int m_nObjectSize;

    /* PASCAL has multiple macros : #define PASCAL NULL or _stdcall or __pascal or
    pascal */

    #ifdef _AFXDLL
        CRuntimeClass * ( /* PASCAL */ * m_pfnGetBaseClass )();
    #else
        CRuntimeClass * m_pBaseClass;
    #endif

    CRuntimeClass * ( /* PASCAL */ * m_pfnCreateObject )(); // !!!
    UINT m_wSchema;

    CObject * CreateObject();
    static CObject * /* PASCAL */ CreateObject( LPCSTR className );
    static CObject * /* PASCAL */ CreateObject( LPCWSTR className );

    static CRuntimeClass * /* PASCAL */ FromName( LPCSTR className );
    static CRuntimeClass * /* PASCAL */ FromName( LPCWSTR className );
    BOOL IsDerivedFrom( const CRuntimeClass * pBaseClassOf ) const;
};

#ifdef _WIN32
} // namespace Mfc
#endif

// ========== Platform specific ==========

#ifdef _WIN32
    typedef Mfc::CRuntimeClass      CMfcRuntimeClass;
#else
    typedef      CRuntimeClass      CMfcRuntimeClass;
#endif

#endif // _BS_MFC_CRUNTIMECLASS_INCLUDED_
