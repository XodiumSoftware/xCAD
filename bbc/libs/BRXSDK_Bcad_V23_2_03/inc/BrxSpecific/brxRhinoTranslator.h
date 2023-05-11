// brxRhinoTranslator.h
//
// Copyright © Menhirs NV. All rights reserved.

//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH

#pragma once

#include "Misc/MiscGlobal.h"
#include "Misc/AcArray.h"
#include "AcDb/AcDbObjectId.h"
#include "AcDb/AcDbGlobal.h"


// imports a Rhino (3dm) file and creates a set of NDBR entities.
BRX_IMPORTEXPORT Acad::ErrorStatus importRhinoFile(AcDbVoidPtrArray& entities, const ACHAR* fileName, bool simplifyGeometry = false);

// exports the specified (database-resident) entity set to a Rhino (3dm) file
BRX_IMPORTEXPORT Acad::ErrorStatus exportRhinoFile(const AcDbObjectIdArray& entitySet, const ACHAR* fileName);

// exports the specified entity set to a Rhino (3dm) file (also supports non-database-resident entities)
BRX_IMPORTEXPORT Acad::ErrorStatus exportRhinoFile(const AcDbVoidPtrArray& entitySet, const ACHAR* fileName);
