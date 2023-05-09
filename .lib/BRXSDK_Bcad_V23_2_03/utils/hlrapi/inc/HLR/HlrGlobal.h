// Copyright (C) 2006-2009 Menhirs NV. All rights reserved.
#pragma once

#include "AcGe/AcGePoint3d.h"

#ifdef HLR_API
  #ifdef _WIN32
    #define HLR_IMPORTEXPORT __declspec(dllexport)
    #define HLR_IMPORTEXPORT_UX
  #else  // !_WIN32
    #define HLR_IMPORTEXPORT    __attribute__((visibility("default")))
    #define HLR_IMPORTEXPORT_UX __attribute__((visibility("default")))
  #endif // !_WIN32
#else // !HLR_API
  #ifdef _WIN32
    #define HLR_IMPORTEXPORT __declspec(dllimport)
    #define HLR_IMPORTEXPORT_UX
  #else  // !_WIN32
    #define HLR_IMPORTEXPORT
    #define HLR_IMPORTEXPORT_UX
  #endif // !_WIN32
#endif // !HLR_API

class AcDbEntity;
class AcDbViewport;
class AsdkHlrCollector;
class AsdkHlrData;

enum AsdkHlrControl
{
    kProject         = 1,     // project the resulting 3D curves onto the projection plane
    kShowAll         = 2,     // HLR provides all curves, visible and invisible, if this flag is specified
    kEntity          = 4,     // keeps the source entity tracked in results, along with HLR curve entity
    kBlock           = 8,     // also keep source the nested entities tracked in results
    kSubentity       = 16,    // also keep subentity specifications tracked in results
    kHideTangents    = 32,    // suppresses tangent edges in results
    kCleanup         = 64,    // clear temporary data after HLR process
    kIsolines        = 128,   // include isolines in output results
    kUnite           = 256,   // unite ACIS entities before HLR processing (slower, might be more precise)
    kReuse           = 512,   // not supported
    kProgress        = 1024,  // use progress and abort callbacks, if provided
    kHandlePoints    = 2048,  // include point entities in HLR processing
    kProcessAll      = 4096,  // include invisible entities as well (on frozen/off layers, invisible by state)
    kHonorInternals  = 8192,  // respect internal edges of ACIS, Meshes, etc.; slower, might be more precise)
    kMeshSilhouettes = 16384, // also generate silhouette lines for AcDbPolyFaceMesh entities
    kSingleCacheVp   = 32768  // use a single cache for all viewports (not supported)
};

#define AsdkHlrApiServiceName _T("ASDK_HLR_API_SERVICES")

typedef void (*_AbortCallbackFct)(bool*);
typedef void (*_ProgressCallbackFct)(int);

extern "C"
{
    void* createBodyFromTriangles(AcGePoint3dArray&,AcGeIntArray&);
}
