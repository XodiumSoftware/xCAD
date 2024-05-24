// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "brx_importexport.h"  // BRX_IMPORTEXPORT

#if !defined(__ax_bricscaddb_h__) || !defined(__ax_bricscaddb_h__)
  #include "PropertyPalette/COMWrapperBegin.h"
  #include "ax_bricscaddb.h"   // defines __ax_bricscaddb_h__
  #include "ax_bricscadapp.h"  // defines __ax_bricscaddb_h__
  #include "PropertyPalette/COMWrapperEnd.h"
#endif // !__ax_bricscaddb_h__ || !__ax_bricscaddb_h__

//The following aliases are provided for comaptibility and code readability
//Note: commented aliases are for controls not yet implemented in BRX

//#define CLSID_PropertyEditorText CLSID_AcPePropertyEditorText
#define CLSID_PropertyEditorLWeight CLSID_AcPePropertyEditorLWeight
#define CLSID_PropertyEditorLayer CLSID_AcPePropertyEditorLayer
//#define CLSID_PropertyEditorMaterial CLSID_AcPePropertyEditorMaterial
#define CLSID_PropertyEditorColor CLSID_AcPePropertyEditorColor
#define CLSID_PropertyEditorLType CLSID_AcPePropertyEditorLType
//#define CLSID_PropertyEditorNumeric CLSID_AcPePropertyEditorNumeric
//#define CLSID_PropertyEditorBool CLSID_AcPePropertyEditorBool
//#define CLSID_PropertyEditorACADNumeric CLSID_AcPePropertyEditorACADNumeric
//#define CLSID_PropertyEditorNumericArea CLSID_AcPePropertyEditorNumericArea
#define CLSID_PropertyEditorEllipses CLSID_AcPePropertyEditorEllipses
//#define CLSID_PropertyEditorEditButton CLSID_AcPePropertyEditorEditButton
//#define CLSID_PropertyEditorEnum CLSID_AcPePropertyEditorEnum
//#define CLSID_PropertyEditorSpinnerEnum CLSID_AcPePropertyEditorSpinnerEnum
//#define CLSID_PropertyEditorHatchEnum CLSID_AcPePropertyEditorHatchEnum
//#define CLSID_PropertyEditorMTextDir CLSID_AcPePropertyEditorMTextDir
//#define CLSID_PropertyEditorHatchISOPenWidth CLSID_AcPePropertyEditorHatchISOPenWidth
//#define CLSID_PropertyEditorHatchPatternName CLSID_AcPePropertyEditorHatchPatternName
//#define CLSID_PropertyEditorEllipsisHatchPatternType CLSID_AcPePropertyEditorEllipsisHatchPatternType
//#define CLSID_PropertyEditorVariant CLSID_AcPePropertyEditorVariant
//#define CLSID_PropertyEditorEllipsesHyperlinks CLSID_AcPePropertyEditorEllipsesHyperlinks
//#define CLSID_PropertyEditorSpin CLSID_AcPePropertyEditorSpin
//#define CLSID_PropertyEditorDimArrowHead CLSID_AcPePropertyEditorDimArrowHead
//#define CLSID_PropertyEditorGradientPattern CLSID_AcPePropertyEditorGradientPattern
//#define CLSID_PropertyEditorPlotStyleName CLSID_AcPePropertyEditorPlotStyleName
//#define CLSID_PropertyEditorPlotStyleTable CLSID_AcPePropertyEditorPlotStyleTable
//#define CLSID_PropertyEditorNoPickVariant CLSID_AcPePropertyEditorNoPickVariant
//#define CLSID_PropertyEditorRasterImageHeight CLSID_AcPePropertyEditorRasterImageHeight
//#define CLSID_PropertyEditorRasterImageWidth CLSID_AcPePropertyEditorRasterImageWidth
//#define CLSID_PropertyEditorTextJustify CLSID_AcPePropertyEditorTextJustify
//#define CLSID_PropertyEditorEllipseEndAngle CLSID_AcPePropertyEditorEllipseEndAngle
//#define CLSID_PropertyEditorDimStyle CLSID_AcPePropertyEditorDimStyle
#define CLSID_PropertyEditorTextStyle CLSID_AcPePropertyEditorTextStyle
//#define CLSID_PropertyEditorMTextStyle CLSID_AcPePropertyEditorMTextStyle
//#define CLSID_PropertyEditorPwdText CLSID_AcPePropertyEditorPwdText
//#define CLSID_PropertyEditorVisualStyle CLSID_AcPePropertyEditorVisualStyle
//#define CLSID_PropertyEditorLightLampColor CLSID_AcPePropertyEditorLightLampColor
//#define CLSID_PropertyEditorIntensityScheme CLSID_AcPePropertyEditorIntensityScheme
//#define CLSID_PropertyEditorLightWebPreview CLSID_AcPePropertyEditorLightWebPreview
//#define CLSID_PropertyEditorLightIntensity CLSID_AcPePropertyEditorLightIntensity
//#define CLSID_PropertyEditorTableStyle CLSID_AcPePropertyEditorTableStyle
//#define CLSID_PropertyEditorAttributeValue CLSID_AcPePropertyEditorAttributeValue
//#define CLSID_PropertyEditorPredefBlock CLSID_AcPePropertyEditorPredefBlock
//#define CLSID_PropertyEditorMLeaderStyle CLSID_AcPePropertyEditorMLeaderStyle
//#define CLSID_PropertySectionLayerCombo CLSID_AcPePropertySectionLayerCombo

//BRX-specific
#define CLSID_PropertyEditorDistance CLSID_AcPePick2PointsCtrl
