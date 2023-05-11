// AcAssocView.h
//
// API to retrieve the source entities, associated to 2d entities generated
// by VIEWBASE and BIMSECTION commands, with associativity GENERATEASSOCVIEWS=On

// Copyright © Menhirs NV. All rights reserved.

//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH

#pragma once

#ifndef _AcAssocView_h_Included
#define _AcAssocView_h_Included

#include "brx_importexport.h"
#include "Misc/MiscGlobal.h"
#include "AcDb/AcDbObjectId.h"
#include "AcDb/AcDbFullSubentPath.h"
#include "AcGe/AcGePoint3d.h"


class AcAssocViewBase
{
public:
    // get the VIEWBASE geometry block attached to given viewport;
    // viewportId - the AcDbObjectId of the viewport, to get the associated VIEWBASE block, if any
    // viewbaseBlockId - returns the AcDbObjectId of the associated VIEWBASE block
    // returns Acad::eOk if the geometry block is successfully retrieved;
    // argument 'viewbaseBlockId' is reset to kNull by default
    // returns Acad::eOk if the associated source entity is successfully retrieved
    static Acad::ErrorStatus getDrawingViewGeometryBlock(const AcDbObjectId& viewportId, AcDbObjectId& viewbaseBlockId);

    // retrieves the path to the source 3d entity fir the given part of its 2d projection.
    // entityId - the 2d entity inside VIEWBASE geometry block
    // sourcePath - the AcDbFullSubentPath of the source entity, associated with the input 2d entity;
    //              the "subentity" part of 'sourcePath' object is initialised whenever possible
    // argument 'sourcePath' is reset by default
    // returns Acad::eOk if the associated source entity is successfully retrieved
    // NOTE : this function only works with MCAD generated section entities, *NOT* with BIM generated sections;
    //        more API support to also cover BIM generated sections will follow in dedicated API
    static Acad::ErrorStatus getAssociatedSourceEntity(const AcDbObjectId& entityId, AcDbFullSubentPath& sourcePath);

    // retrieve an array of paths to all associated source entities, located at the point on 2d projection,
    // sorted by distance from the camera position.
    // productPoint - a 3d point inside VIEWBASE geometry block generated with GENERATEASSOCVIEWS=On
    // sourceEntitiesArray - array of entities located at the original point
    //                       the "subentity" part of the AcDbFullSubentPath objects is initialised whenever possible
    // argument 'sourceEntitiesArray' is reset by default
    // returns Acad::eOk if the associated source entities are successfully retrieved
    // NOTE : this function only works with MCAD generated section entities, *NOT* with BIM generated sections;
    //        more API support to also cover BIM generated sections will follow in dedicated API
    static Acad::ErrorStatus getAssociatedSourceEntity(const AcGePoint3d& productPoint, AcDbFullSubentPathArray& sourceEntitiesArray);
};


#endif // _AcAssocView_h_Included
