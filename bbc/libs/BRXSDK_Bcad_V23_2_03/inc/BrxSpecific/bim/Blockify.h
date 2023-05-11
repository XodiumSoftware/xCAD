// Copyright (C) 2019 Bricsys NV. All rights reserved.

// Blockify.h

// BRX API for BricsCAD "Blockify" functionality + interfaces

//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH

#pragma once
                 
#include <vector>
#include <utility>

#include "Misc/MiscGlobal.h"
#include "AcDb/AcDbObjectId.h"
#include "AcGe/AcGePoint3d.h"
#include "AcGe/AcGeMatrix3d.h"

class AcDbDatabase;

namespace BimApi
{

typedef std::vector<AcDbObjectId>           ObjectIds;
typedef std::pair<ObjectIds, AcGeMatrix3d>  GeomObjectIds;
typedef ObjectIds                           BlockifyResult;

struct MatchingGeomSets
{
    std::vector< GeomObjectIds > m_entitySets;
    AcGePoint3d                  m_insertionPoint;
};


// Verifies whether 2 entity sets 'firstSet' and 'secondSet' share the same geometry;
// returns the transformation matrix 'transform' (from 'firstSet' to 'secondSet'), if both
// entity sets match with their geometry, indicated by bool return status;
// if input 'tolerance' is NULL, a tolerance is determined automatically;
// returns Acad::eOk if a match is found, error status otherwise.

BRX_IMPORTEXPORT Acad::ErrorStatus isSimilarGeometry(AcGeMatrix3d& transform,
                                                     const ObjectIds& firstSet, const ObjectIds& secondSet,
                                                     double* tolerance = nullptr);


// Find the set of entities in 'searchSet' matching the geometry of entities in 'matchSet';
// returns 'matchingGeometry' entity set, if such similar geometry exists in 'searchSet',
// indicated by bool return status;
// if input 'tolerance' is NULL, a tolerance is determined automatically.
// returns Acad::eOk if a match entity set is found, error status otherwise.

BRX_IMPORTEXPORT Acad::ErrorStatus findSimilarGeometry(MatchingGeomSets& matchingGeometry,
                                                       const ObjectIds& matchSet, const ObjectIds& searchSet,
                                                       double* tolerance = nullptr);


// Find all sets of similar 3DSolids in provided 'entitySet' (can also contain other entity types);
// similar 3dSolid entity sets are returned in 'matchingSolids', if found, and indicated by 'true';
// returns Acad::eOk if at least 1 match entity set is found, error status otherwise.

BRX_IMPORTEXPORT Acad::ErrorStatus findSimilar3dSolids(std::vector<MatchingGeomSets>& matchingSolids,
                                                       const ObjectIds& entitySet, double tolerance = 3.0e-04);


// Verifies whether any of the BlockTableRecords from 'db' database matches the specified 'entitySet';
// if 'db' argument is NULL, the database of provided entities is used; for NDBR entities, the
// "current database" (in BricsCAD editor) is used.
// returns Acad::eOk if a matching BlockTableRecord is found, error status otherwise.

BRX_IMPORTEXPORT Acad::ErrorStatus findMatchingBlockDefinition(AcDbObjectId& matchingBtr, AcGeMatrix3d& transform,
                                                               const ObjectIds& entitySet, AcDbDatabase* db = nullptr);


// Verifies all existing BlockTableRecords if their geometry matches any subset of 'entitySet',
// and replace those by BlockReferences or Arrays;
// returns the ids of the created BlockReferences or Arrays in 'resultRefs';
// returns Acad::eOk if any BlockReferences and/or Arrays were created, error status otherwise.

BRX_IMPORTEXPORT Acad::ErrorStatus matchEntitiesToBlockDefinitions(std::vector<BlockifyResult>& resultRefs,
                                                                   const ObjectIds& entitySet,
                                                                   bool only3dSolids = false);


// Replaces 'similarGroups' by BlockReferences or Arrays.

// 'similarGroups' input definition data, created by former analysis runs;
// 'useDefPoint' (optionally) specifies whether or not to use the 'm_insertionPoint' member for BlockDefinition insertion point;
//               if 'false', an insertion point is calcualted;
// if 'blockName' (optionally) is NULL or empty, an automatically generated BlockDefinition name is used;
// 'createArrays' (optionally) defines whether normal BlockReference(s) or Array(s) are created;
// 'blockId' (optionally) defines the BlockTableRecord used to create the BlockReferences; if 'kNull', a new BlockTableRecord is created;
// 'blockTrans' (optionally) is the block transformation matrix used when b'lockId' is valid; otherwise the block transformation
//              defines the translation matrix to the block insertion point
// returns Acad::eOk if a matching BlockTableRecord is found, error status otherwise.

BRX_IMPORTEXPORT Acad::ErrorStatus replaceGeometryByBlocks(BlockifyResult& createdRefs,
                                                           const MatchingGeomSets& similarGroups,
                                                           bool useDefPoint = false,
                                                           const ACHAR* blockName = nullptr,
                                                           const AcDbObjectId& blockId = AcDbObjectId::kNull,
                                                           const AcGeMatrix3d& blockTrans = AcGeMatrix3d::kIdentity);


}; // namespace BimApi
