// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

void cmdCivilCreateSurface();
void cmdCivilSurfaceList();
void cmdCivilListAllSurfaces();

void cmdCivilAddBreakline();
void cmdCivilAddBoundary();
void cmdCivilAddBreaklineDBRO();
void cmdCivilAddBoundaryDBRO();

void cmdCivilRemoveBreakline();
void cmdCivilRemoveBoundary();

void cmdCivilChangeStyle();
void cmdCivilSurfaceMapElevations();
void cmdCivilSurfaceMapSlope();

void cmdCivilSurfaceMerge();
void cmdCivilSurfaceMesh();

void cmdCivilSurfaceDrape();
void cmdCivilSurfaceJig();


//volume surface
void cmdCivilVolumeSurfaceCreate();
void cmdCivilVolumeSurfaceCreateElev();
void cmdCivilVolumeSurfaceBounded();
