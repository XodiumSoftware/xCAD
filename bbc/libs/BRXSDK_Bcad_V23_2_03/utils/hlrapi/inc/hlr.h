// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

// the HLR API module provided by Bricscad
#ifndef HLR_API_MODULE
  #ifdef _WIN32 // Windows
    #define HLR_API_MODULE  _T("BrxHlrApi23.dbx")
  #else         // Linux, Mac
    #define HLR_API_MODULE  _T("libbrxhlrapi23.so")
  #endif
#endif

#include "./HLR/AsdkHlrCollector.h"
#include "./HLR/AsdkHlrData.h"
#include "./HLR/AsdkHlrEngine.h"
