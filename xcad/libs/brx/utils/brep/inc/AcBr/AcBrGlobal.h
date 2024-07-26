// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "Misc/MiscGlobal.h"
#include "AcRx/AcRxBoiler.h"
#include "AcRx/AcRxClass.h"
#include "AcRx/AcRxDictionary.h"
#include "AcGe/AcGeGlobal.h"

class AcBrBrep;
class AcBrBrepComplexTraverser;
class AcBrComplex;
class AcBrComplexShellTraverser;
class AcBrEdge;
class AcBrEdgeLoopTraverser;
class AcBrElement;
class AcBrElement2d;
class AcBrEntity;
class AcBrFace;
class AcBrFaceLoopTraverser;
class AcBrHit;
class AcBrHitPath;
class AcBrLoop;
class AcBrLoopEdgeTraverser;
class AcBrLoopVertexTraverser;
class AcBrMesh;
class AcBrMesh2d;
class AcBrMesh2dControl;
class AcBrMesh2dElement2dTraverser;
class AcBrMesh2dFilter;
class AcBrMeshControl;
class AcBrMeshEntity;
class AcBrNode;
class AcBrShell;
class AcBrShellFaceTraverser;
class AcBrVertex;
class AcBrVertexEdgeTraverser;
class AcBrVertexLoopTraverser;
class AcDb3dSolid;
class AcDbEntity;
class AcDbFullSubentPath;

struct AcBr
{
    enum Element2dShape
    {
        kDefault = 0,
        kAllPolygons,
        kAllQuadrilaterals,
        kAllTriangles
    };

    enum ErrorStatus
    {
        eAmbiguousOutput = Acad::eAmbiguousOutput,
        eBrepChanged = 3008,
        eDegenerateTopology = 3020,
        eInvalidInput = Acad::eInvalidInput,
        eInvalidObject = Acad::eUnrecoverableErrors,
        eMissingGeometry = Acad::eDegenerateGeometry,
        eMissingSubentity = Acad::eNotInDatabase,
        eNotApplicable = Acad::eNotApplicable,
        eNotImplementedYet = Acad::eNotImplementedYet,
        eNullObjectId = Acad::eNullObjectId,
        eNullObjectPointer = Acad::eUnrecoverableErrors,
        eNullSubentityId = Acad::eInvalidIndex,
        eObjectIdMismatch = Acad::eWrongDatabase,
        eOk = 0,
        eOutOfMemory = Acad::eOutOfMemory,
        eTopologyMismatch = Acad::eWrongDatabase,
        eUninitialisedObject = 3021,
        eUnsuitableGeometry = Acad::eAmbiguousOutput,
        eUnsuitableTopology = 3013,
        eWrongObjectType = Acad::eWrongObjectType,
        eWrongSubentityType = Acad::eWrongSubentityType
    };

    enum LoopType
    {
        kUnclassified = 0,
        kExterior,
        kInterior,
        kWinding,
        kLoopUnclassified = 0,
        kLoopExterior,
        kLoopInterior,
        kLoopWinding
    };

    enum Relation
    {
        kUnknown = 0,
        kOutside,
        kInside,
        kBoundary,
        kCoincident,
        kTangent,
        kIntersect
    };

    enum ShellType
    {
        kShellUnclassified= 0,
        kShellExterior,
        kShellInterior
    };

    enum ValidationLevel
    {
        kFullValidation = 0,
        kNoValidation
    };
};

//BRX START
// default result arguments as used by several AcBr member functions
BRX_IMPORTEXPORT extern double defaultDoubleNull;
BRX_IMPORTEXPORT extern AcDbFullSubentPath defaultNullFSP;
//BRX END
