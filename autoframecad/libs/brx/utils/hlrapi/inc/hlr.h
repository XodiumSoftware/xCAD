// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

// the HLR API module provided by Bricscad
#ifndef HLR_API_MODULE
  #ifdef _WIN32 // Windows
    #define HLR_API_MODULE  _T("BrxHlrApi24.dbx")
  #else         // Linux, Mac
    #define HLR_API_MODULE  _T("libbrxhlrapi24.so")
  #endif
#endif

#include "./HLR/AsdkHlrCollector.h"
#include "./HLR/AsdkHlrData.h"
#include "./HLR/AsdkHlrEngine.h"
