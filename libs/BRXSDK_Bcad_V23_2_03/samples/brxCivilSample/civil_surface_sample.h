// Copyright (C) Menhirs NV. All rights reserved.

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
