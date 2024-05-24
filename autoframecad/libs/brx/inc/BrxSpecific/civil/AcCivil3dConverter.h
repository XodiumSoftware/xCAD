// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

// BRX API for BricsCAD Civil3d Import functionality + interfaces

/*
* In BRX SDK V24, many classes and enums in the Civil API were renamed to
* improve consistency and readability.
*
* This old header file remains so that BRX client code based on BRX SDK V23
* continues to compile and run without error in later versions of the SDK.
* Starting with V24, all new BRX client code should directly include only
* the new header file(s).
*/

// forward to new headers
#include "BrxCvCivil3dConverter.h"

// define aliases for old type names that have been renamed
typedef BrxCvCivil3dEntityInfo BrxCivil3dEntityInfo;
typedef BrxCvCivil3dConverter BrxCivil3dConverter;

#define BrxCivil3dEntityInfos BrxCvCivil3dEntityInfos
#define BrxCivil3dEntityInfoMap BrxCvCivil3dEntityInfoMap

// redefine enum names
#define ECivil3dEntityType Civil3dEntityType
#define ECivil3dAlignmentType Civil3dAlignmentType
#define ECivil3dProfileType Civil3dProfileType
