///////////////////////////////////////////////////////////////////////////////
//
// Copyright (c) 2018 Menhirs NV
// All rights reserved.
//
// Purpose: declares high-level API to associative drawing views
//
///////////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef od_assoc_views_h
#define od_assoc_views_h

#include "OdaCommon.h"
#include "DbDatabase.h"
#include "DbObjectId.h"
#include "DbEntity.h"

#include "od_api_exports.h"

namespace OdAssocViews {

/**
 * Retrieve a path to source 3d entity given a part of its 2d projection.
 * @param productEntId
 *   id of 2d entity inside VIEWBASE geometry block generated with GENERATEASSOCVIEWS=On
 * @param sourceFsp
 *   Full subent path to original entity. Subentity is set whenever possible.
 * @param pSourceDb
 *   A pointer to database in which source entity dwells. If this pointer is set to nullptr or not passed
 *   the database of 2d projection is used.
 * @return
 *   eOk if no errors occurred and source entity are obtained, error code otherwise.
 */
ODAPI OdResult getSourcePath(const OdDbObjectId& productEntId, OdDbFullSubentPath& sourcePath);

/**
 * Retrieve an array of paths to source VEIEWBASE geometry lying under the given paper space point.
 * @param productPoint
 *   a point in paper space pointing to VIEWBASE projection
 * @param aFullSubentPath
 *   an array of paths to source VIEWBASE entities lying under the given point. It is sorted by depth from the nearest to the farthest
 * @return
 *   eOk if no errors occurred and source entities is obtained, error code otherwise.
 */
ODAPI OdResult getSourcePath(const OdGePoint3d& productPoint, OdDbFullSubentPathArray& aFullSubentPath);

/**
 * Get VIEWBASE geometry block attached to given viewport.
 */
ODAPI OdResult getDrawingViewGeometryBlock(const OdDbObjectId& viewportId, OdDbObjectId& blockId);


} // OdAssocViews namespace


#endif // od_assoc_views_h

