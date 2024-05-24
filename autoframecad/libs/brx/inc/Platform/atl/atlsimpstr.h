// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

// Windows ATL SimpleString and associated types and functions

#ifndef _BS_ATL_ATLSIMPSTR_INCLUDED_
#define _BS_ATL_ATLSIMPSTR_INCLUDED_

//namespace ATL{

#ifndef _WIN32

#include "Platform/win/win_defs.h"

#define _AtlInterlockedIncrement _InterlockedIncrement
#define _AtlInterlockedDecrement _InterlockedDecrement

#else

typedef unsigned int uint32_t;

#if( defined( _UNICODE ) || defined( UNICODE ) )
    typedef wchar_t XCHAR;
    typedef LPWSTR PXSTR;
    typedef LPCWSTR PCXSTR;
    typedef char YCHAR;
    typedef LPSTR PYSTR;
    typedef LPCSTR PCYSTR;
#else
    typedef char XCHAR;
    typedef LPSTR PXSTR;
    typedef LPCSTR PCXSTR;
    typedef wchar_t YCHAR;
    typedef LPWSTR PYSTR;
    typedef LPCWSTR PCYSTR;
#endif

#endif //!_WIN32

#ifndef BRXEXPORT // for client build : import
#define BRXEXPORT
#endif

#ifdef _WIN32
namespace Mfc
{
#endif

BRXEXPORT int alignUp8( int valueToAlign );

struct CStringData;
class CNilStringData;

class BRXEXPORT IAtlStringMgr
{
public:
    virtual ~IAtlStringMgr() {}
    virtual CStringData* Allocate( int , int ) noexcept(false) = 0;
    virtual void Free( CStringData* ) noexcept(false) = 0;
    virtual CStringData* Reallocate( CStringData* , int ,int ) noexcept(false) = 0;
    virtual CStringData* GetNilString() noexcept(false) = 0;
    virtual IAtlStringMgr* Clone() noexcept(false) = 0;
};

struct BRXEXPORT CStringDataRefCounter
{
  volatile int _ref_count;
  CStringDataRefCounter& operator = (int n);
  operator int () const;

  int operator ++ ();
  int operator -- ();
  int operator ++ (int);
  int operator -- (int);
  int operator == (int n);
  int operator < (int n);
  int operator > (int n);
};

struct BRXEXPORT CStringData
{
    IAtlStringMgr* pStringMgr;
    int nDataLength;
    int nAllocLength;
    CStringDataRefCounter nRefs;
    PXSTR m_pData;

    void* data() noexcept(false);

    void AddRef() noexcept(false);
    bool IsLocked() const noexcept(false);
    bool IsShared() const noexcept(false);
    void Lock() noexcept(false);
    void Release() noexcept(false);
    void Unlock() noexcept(false);
};

class BRXEXPORT CNilStringData : public CStringData
{
public:
    CNilStringData() noexcept(false);
    void SetManager( IAtlStringMgr* pMgr ) noexcept(false);
public:
    wchar_t charNil[2];
};

class BRXEXPORT IAtlMemMgr
{
public:
    virtual ~IAtlMemMgr() {}
    virtual void* Allocate( size_t nBytes ) noexcept(false) = 0;
    virtual void Free( void* p ) noexcept(false) = 0;
    virtual void* Reallocate( void* p, size_t nBytes ) noexcept(false) = 0;
    virtual size_t GetSize( void* p ) noexcept(false) = 0;
};

class BRXEXPORT CCRTHeap : public IAtlMemMgr
{
public:
    virtual void* Allocate( size_t nBytes ) noexcept(false);
    virtual void Free( void* p ) noexcept(false);
    virtual void* Reallocate( void* p, size_t nBytes ) noexcept(false);
    virtual size_t GetSize( void* p ) noexcept(false);

public:
};

class BRXEXPORT CCRTAllocator
{
public:
    static void* Reallocate(void* , size_t ) noexcept(false);
    static void* Allocate(size_t ) noexcept(false);
    static void Free(void* ) noexcept(false);
};

class BRXEXPORT CAtlStringMgr : public IAtlStringMgr
{
public:

    CAtlStringMgr( IAtlMemMgr* = NULL ) noexcept(false);
    virtual ~CAtlStringMgr() noexcept;
    void SetMemoryManager( IAtlMemMgr* ) noexcept(false);

    //inherited
public:
    CStringData* Allocate( int , int ) noexcept(false);
    void Free( CStringData* ) noexcept(false);
    CStringData* Reallocate( CStringData* , int ,int ) noexcept(false);
    CStringData* GetNilString() noexcept(false);
    virtual IAtlStringMgr* Clone() noexcept(false);

protected:
    IAtlMemMgr*          m_pMemAllocator;
    CNilStringData       m_nilStringData;
};

#ifdef _WIN32
}  // namespace Mfc
#endif

//} //namespace ATL

// ========== Platform specific ==========

#ifdef _WIN32

    #define CMfcStringData      Mfc::CStringData
    #define CMfcNilStringData   Mfc::CNilStringData
    #define CMfcCRTHeap         Mfc::CCRTHeap
    #define CMfcCRTAllocator    Mfc::CCRTAllocator
    #define IMfcAtlMemMgr       Mfc::IAtlMemMgr
    #define CMfcAtlMemMgr       Mfc::CAtlMemMgr
    #define IMfcAtlStringMgr    Mfc::IAtlStringMgr
    #define CMfcAtlStringMgr    Mfc::CAtlStringMgr

#else   // on Linux/Mac

    #define CMfcStringData      CStringData
    #define CMfcNilStringData   CNilStringData
    #define CMfcCRTHeap         CCRTHeap
    #define CMfcCRTAllocator    CCRTAllocator
    #define IMfcAtlMemMgr       IAtlMemMgr
    #define CMfcAtlMemMgr       CAtlMemMgr
    #define IMfcAtlStringMgr    IAtlStringMgr
    #define CMfcAtlStringMgr    CAtlStringMgr
    
#endif

#endif // _BS_ATL_ATLSIMPSTR_INCLUDED_