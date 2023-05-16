// sds_hostapp.h : declares helper functions that need to be implemented by the host app

// Copyright © Menhirs NV. All rights reserved.

//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH

#pragma once
#ifndef _SDS_HOSTAPP_H_
#define _SDS_HOSTAPP_H_

#include "sds_platform.h"

#ifdef SDSAPI_PRJ
#define SDS_HOSTAPP_EXPORT
#else
#ifdef _MSC_VER
#define SDS_HOSTAPP_EXPORT __declspec(dllexport)
#else
#define SDS_HOSTAPP_EXPORT __attribute__((visibility("default")))
#endif
#endif

extern "C"
{;

SDS_HOSTAPP_EXPORT void* sds_ha_on_function_entry(void);
SDS_HOSTAPP_EXPORT void sds_ha_on_function_exit(void* context);
SDS_HOSTAPP_EXPORT class CWinApp* sds_ha_getwinapp(void);
SDS_HOSTAPP_EXPORT class CWnd* sds_ha_getmainwnd(void);
SDS_HOSTAPP_EXPORT class CView* sds_ha_getviewwnd(void);
SDS_HOSTAPP_EXPORT class CDocument* sds_ha_getviewdoc(void);

} //extern "C"

#endif //_SDS_HOSTAPP_H_
