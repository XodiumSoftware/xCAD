// oa_sel_options.h: Defines the SelectionOptions enumumerated data type. This enum specifies options for selection 
// preview and user input commands, when solid subents are to be specified. Note that earlier OdDb::kFaceSubentType and 
// such were used, which is no longer desirable as there are many more options now, especially because of MCAD applications.

// Copyright © Menhirs NV. All rights reserved.

//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH

#pragma once

namespace OdUI
{;

// IMPORTANT: The values of the enums below can change. Please use enums instead of hardcoded values.
enum SelectionOptions
{
    eSelectNone = 0,
    eSelectFaces = 1, // OdDb::kFaceSubentType for entities that have acis representation
    eSelectEdges = 2, // OdDb::kEdgeSubentType for entities that have acis representation
    eSelectVertices = 4, // OdDb::kVertexSubentType
    eSelectFromNestedBlocks = 8,
    eSelectEntities =  16,
    eSubentsLast = 32, // OFF = edges,faces,solids; ON = solids,edges,faces 
    eBlockNestedEntsTopDown = 64, // ON = topmost block first; OFF = innermost nested block first
    eDontIncludeBlockrefChain = 128, // This should ideally be eIncludeBlockRefChain, change if possible
    eSelectBoundaries = 256, // Select OdBoundary
    eSelectNonAcisSubents = 512, // Select subents for entities that do not have an acis representation (polylines, dimensions, etc)
    eSelectVisibleEdgesOnly = 1024,  // Will select only visible edges in shaded mode
    eSelectDrawableNodes = 2048, // Select OdDrawableNode
    eSelectFromViewRepBlocks = 4096, // Select geometry from block representation
    eSelectEdgesAuxFilter = 8192 // Will select only edges that allowed by a specific auxiliary post-filter
};

} // namespace ::OdUI
