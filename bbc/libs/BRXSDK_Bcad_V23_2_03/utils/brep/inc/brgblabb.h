// Copyright (C) 2010-2011 Menhirs NV. All rights reserved.
#pragma once

#include "AcBr/AcBrGlobal.h"

typedef AcBr::Element2dShape AcBrElement2dShape;
typedef AcBr::ErrorStatus AcBrErrorStatus;
typedef AcBr::LoopType AcBrLoopType;
typedef AcBr::Relation AcBrRelation;
typedef AcBr::ShellType AcBrShellType;
typedef AcBr::ValidationLevel AcBrValidationLevel;

const AcBrErrorStatus eAmbiguousOutput = AcBr::eAmbiguousOutput;
const AcBrErrorStatus eBrepChanged = AcBr::eBrepChanged;
const AcBrErrorStatus eDegenerateTopology = AcBr::eDegenerateTopology;
const AcBrErrorStatus eInvalidInput = AcBr::eInvalidInput;
const AcBrErrorStatus eInvalidObject = AcBr::eInvalidObject;
const AcBrErrorStatus eMissingGeometry = AcBr::eMissingGeometry;
const AcBrErrorStatus eMissingSubentity	= AcBr::eMissingSubentity;
const AcBrErrorStatus eNotApplicable = AcBr::eNotApplicable;
const AcBrErrorStatus eNotImplementedYet = AcBr::eNotImplementedYet;
const AcBrErrorStatus eNullObjectId = AcBr::eNullObjectId;
const AcBrErrorStatus eNullObjectPointer = AcBr::eNullObjectPointer;
const AcBrErrorStatus eNullSubentityId = AcBr::eNullSubentityId;
const AcBrErrorStatus eObjectIdMismatch	= AcBr::eObjectIdMismatch;
const AcBrErrorStatus eOk = AcBr::eOk;
const AcBrErrorStatus eOutOfMemory = AcBr::eOutOfMemory;
const AcBrErrorStatus eTopologyMismatch	= AcBr::eTopologyMismatch;
const AcBrErrorStatus eUninitialisedObject = AcBr::eUninitialisedObject;
const AcBrErrorStatus eUnsuitableGeometry = AcBr::eUnsuitableGeometry;
const AcBrErrorStatus eUnsuitableTopology = AcBr::eUnsuitableTopology;
const AcBrErrorStatus eWrongObjectType = AcBr::eWrongObjectType;
const AcBrErrorStatus eWrongSubentityType = AcBr::eWrongSubentityType;
