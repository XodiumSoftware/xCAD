// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

// BRX API for BricsCAD Civil Alignments + Civil Views interfaces

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
#include "BrxCvDbAlignments.h"

// define aliases for old type names that have been renamed
typedef BrxCvDbHAlignment AcDbCivilDbHAlignment;
typedef BrxCvDbHAlignmentElement AcDbCivilHAlignmentElement;
typedef BrxCvDbHAlignmentPI AcDbCivilHAlignmentPI;
typedef BrxCvDbHAlignmentCurve AcDbCivilHAlignmentCurve;
typedef BrxCvDbHAlignmentLine AcDbCivilHAlignmentLine;
typedef BrxCvDbHAlignmentArc AcDbCivilHAlignmentArc;
typedef BrxCvDbHAlignmentSpiral AcDbCivilHAlignmentSpiral;
typedef BrxCvDbHAlignmentSCS AcDbCivilHAlignmentSCS;
typedef BrxCvDbHAlignmentSTS AcDbCivilHAlignmentSTS;
typedef BrxCvDbHAlignmentSSCSS AcDbCivilHAlignmentSSCSS;
typedef BrxCvDbVAlignment AcDbCivilDbVAlignment;
typedef BrxCvDbVAlignmentElement AcDbCivilVAlignmentElement;
typedef BrxCvDbVAlignmentPVI AcDbCivilVAlignmentPVI;
typedef BrxCvDbVAlignmentCurve AcDbCivilVAlignmentCurve;
typedef BrxCvDbVAlignmentTangent AcDbCivilVAlignmentTangent;
typedef BrxCvDbVAlignmentArc AcDbCivilVAlignmentArc;
typedef BrxCvDbVAlignmentParabola AcDbCivilVAlignmentParabola;
typedef BrxCvDb3dAlignment AcDbCivilDb3dAlignment;
typedef BrxCvDbView AcDbCivilView;
typedef BrxCvDbVAlignmentView AcDbCivilVAlignmentView;
typedef BrxCvStationEquation AcCivilStationEquation;
typedef BrxCvStationEquations AcCivilStationEquations;

#define AcDbCivilHAlignmentElementPtr BrxCvDbHAlignmentElementPtr
#define AcDbCivilHAlignmentPIArray BrxCvDbHAlignmentPIArray
#define AcDbCivilHAlignmentPIPtr BrxCvDbHAlignmentPIPtr
#define AcDbCivilHAlignmentPIPtrArray BrxCvDbHAlignmentPIPtrArray
#define AcDbCivilHAlignmentCurvePtr BrxCvDbHAlignmentCurvePtr
#define AcDbCivilHAlignmentLinePtr BrxCvDbHAlignmentLinePtr
#define AcDbCivilHAlignmentArcPtr BrxCvDbHAlignmentArcPtr
#define AcDbCivilHAlignmentSpiralPtr BrxCvDbHAlignmentSpiralPtr
#define AcDbCivilHAlignmentSCSPtr BrxCvDbHAlignmentSCSPtr
#define AcDbCivilHAlignmentSTSPtr BrxCvDbHAlignmentSTSPtr
#define AcDbCivilHAlignmentSSCSSPtr BrxCvDbHAlignmentSSCSSPtr
#define AcDbCivilVAlignmentElementPtr BrxCvDbVAlignmentElementPtr
#define AcDbCivilVAlignmentPVIPtr BrxCvDbVAlignmentPVIPtr
#define AcDbCivilVAlignmentPVIArray BrxCvDbVAlignmentPVIArray
#define AcDbCivilVAlignmentPVIPtrArray BrxCvDbVAlignmentPVIPtrArray
#define AcDbCivilVAlignmentCurvePtr BrxCvDbVAlignmentCurvePtr
#define AcDbCivilVAlignmentTangentPtr BrxCvDbVAlignmentTangentPtr
#define AcDbCivilVAlignmentArcPtr BrxCvDbVAlignmentArcPtr
#define AcDbCivilVAlignmentParabolaPtr BrxCvDbVAlignmentParabolaPtr
#define AcDbCivil3dAlignmentElementPtr BrxCvDb3dAlignmentElementPtr
#define AcDbCivil3dAlignmentPIPtr BrxCvDb3dAlignmentPIPtr

// redefine enum names
#define StationEquationType EStationEquationType
