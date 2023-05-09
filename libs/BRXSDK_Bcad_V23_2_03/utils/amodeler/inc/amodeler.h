// Copyright (C) 2006-2009 Menhirs NV. All rights reserved.
#pragma once

#ifndef _WIN32 // Linux,Mac
  #include "brx_platform_linux.h"
#endif

#include "./BModeler/BmBody.h"
#include "./BModeler/BmCircle3d.h"
#include "./BModeler/BmCircleCurve.h"
#include "./BModeler/BmConeSurface.h"
#include "./BModeler/BmCylinderSurface.h"
#include "./BModeler/BmDarray.h"
#include "./BModeler/BmEdge.h"
#include "./BModeler/BmFace.h"
#include "./BModeler/BmInterval1d.h"
#include "./BModeler/BmInterval2d.h"
#include "./BModeler/BmInterval3d.h"
#include "./BModeler/BmIntInterval1d.h"
#include "./BModeler/BmIntInterval2d.h"
#include "./BModeler/BmIntInterval3d.h"
#include "./BModeler/BmIntPoint3d.h"
#include "./BModeler/BmIntVector2d.h"
#include "./BModeler/BmIntVector3d.h"
#include "./BModeler/BmLine3d.h"
#include "./BModeler/BmOutputPolylineCallback.h"
#include "./BModeler/BmOutputTriangleCallback.h"
#include "./BModeler/BmPlane.h"
#include "./BModeler/BmPoint2d.h"
#include "./BModeler/BmPoint3d.h"
#include "./BModeler/BmPolygonVertexData.h"
#include "./BModeler/BmSaveRestoreCallback.h"
#include "./BModeler/BmSaveToSatCallback.h"
#include "./BModeler/BmSphereSurface.h"
#include "./BModeler/BmTopologyChangeCallback.h"
#include "./BModeler/BmTorusSurface.h"
#include "./BModeler/BmTransf3d.h"
#include "./BModeler/BmUnspecifiedCurve.h"
#include "./BModeler/BmUnspecifiedSurface.h"
#include "./BModeler/BmVector2d.h"
#include "./BModeler/BmVector3d.h"
#include "./BModeler/BmVertex.h"
#include "./BModeler/BmVertexSurfaceData.h"

// the BMODELER API module provided by Bricscad
#ifndef BMODELER_API_MODULE
  #ifdef _WIN32 // Windows
    #define BMODELER_API_MODULE  _T("bmodeler23.dbx")
  #else         // Linux, Mac
    #define BMODELER_API_MODULE  _T("libbmodeler23.so")
  #endif
#endif
// and AModeler alias ...
#ifndef AMODELER_API_MODULE
  #define AMODELER_API_MODULE BMODELER_API_MODULE
#endif
