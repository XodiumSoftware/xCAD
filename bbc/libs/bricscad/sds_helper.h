// sds_helper.h : Declares sds utility functions and data structures

// Copyright © Menhirs NV. All rights reserved.

//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH

#pragma once
#ifndef _SDS_HELPER_H_
#define _SDS_HELPER_H_


#include "sds_hostapp.h"

class SDS_ManageEntry
{
    void* m_ctxt;
public:
    SDS_ManageEntry() : m_ctxt(sds_ha_on_function_entry()) {}
    ~SDS_ManageEntry() { sds_ha_on_function_exit(m_ctxt); }
};

#define SDS_MANAGE_ENTRY() SDS_ManageEntry __sds_entry_state;


// Support for user callbacks from main thread
struct SDS_UserMainThreadArgs
    {
    int userMainThreadFuncRet;
    void *userMainThreadFuncData;
    int (*pfnUserMainThreadFunc)(void *);
    HANDLE syncEvent;

    SDS_UserMainThreadArgs(): userMainThreadFuncRet(0), userMainThreadFuncData(NULL), pfnUserMainThreadFunc(NULL), syncEvent(0){}
    };

// sds utilities 

#ifdef _WIN32
  #if (!defined(CMAKE_ENABLED) && defined(DDCAD_PRJ)) || sdsapi_EXPORTS
    #define	SDSUTILS_API __declspec(dllexport)
  #else
    #define	SDSUTILS_API __declspec(dllimport)
  #endif
#else
    #define	SDSUTILS_API  
#endif

namespace sdsut
{;
SDSUTILS_API resbuf* entget(const OdDbObject* pObj, const resbuf *apps);
SDSUTILS_API resbuf* assoc(resbuf* argp, int restype);
SDSUTILS_API const resbuf* assoc(const resbuf* argp, int restype);
SDSUTILS_API bool entmod(oa::ApDoc* pDoc, OdDbObject* pObj, const resbuf *rb, int& errorCode);
SDSUTILS_API int  entmake(oa::ApDoc* pDoc, const resbuf *rb, OdDbObjectId& objId);
SDSUTILS_API bool regapp(oa::ApDoc* pDoc, const TCHAR* appName);

SDSUTILS_API int sds_cmdC(std::function<int(void*)> pCallback, void* pCallbackData, const struct sds_resbuf *prbCmdList);
SDSUTILS_API int sds_commandC(std::function<int(void*)> pCallback, void* pCallbackData, int nRType, ...);
}

#endif
