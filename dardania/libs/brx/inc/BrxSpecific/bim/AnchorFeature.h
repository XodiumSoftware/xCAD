// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

// BRX API for BricsCAD BIM "Blockify" AnchorFeature + interfaces

#include "brx_importexport.h"

#include "Misc/MiscGlobal.h"
#include "AcDb/AcDbObjectId.h"
#include "AcDb/AcDbFullSubentPath.h"

namespace BimApi
{
    // Returns all anchored block-references for the given db
    BRX_IMPORTEXPORT Acad::ErrorStatus getAnchoredBlockReferences(const AcDbDatabase* pDb,
                                                         AcArray<AcDbObjectId>& blockRefIds);

    // Returns true if the given id is a valid block-reference and is anchored.
    BRX_IMPORTEXPORT bool isAnchoredBlockRef(const AcDbObjectId& blockRefId);

    // Returns the anchor-face for a given anchored block-reference
    BRX_IMPORTEXPORT Acad::ErrorStatus getAnchorFace(const AcDbObjectId& anchoredBlockRefId, 
                                                     AcDbFullSubentPath& outHostFaceSubentPath);

    // Queries if point lies on a valid candidate anchor face.
    BRX_IMPORTEXPORT Acad::ErrorStatus queryValidAnchorPt(const AcGePoint3d& point, const AcDbDatabase* pDb, 
                                                          AcDbFullSubentPath& outHostFaceSubentPath);

    // Anchors the given block-reference id to the given 3dSolid face fullsubentpath, at the given point on the face.
    // If keepOrientation == true, the block-reference will not be reoriented (= retains its current orientation).
    // If keepOrientation == false, the block-reference will be reoriented such that its local X-Y plane will be oriented
    // along the parametric u/v directions on the face and its local z-axis is oriented along the face's outward normal
    BRX_IMPORTEXPORT Acad::ErrorStatus createAnchoredBlockReference(const AcDbObjectId& blockRefId,
                                                           const AcDbFullSubentPath& faceSubentPath,
                                                           const AcGePoint3d& pointOnFace,
                                                           bool keepOrientation,
                                                           AcDbObjectId& outFeatureId);

    // Un-anchor a block-reference
    BRX_IMPORTEXPORT Acad::ErrorStatus unAnchorBlockReference(const AcDbObjectId& blockRefId); 

} // end namespace BimApi
