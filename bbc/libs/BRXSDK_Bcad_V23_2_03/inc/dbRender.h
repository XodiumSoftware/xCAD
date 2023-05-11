// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "brx_importexport.h"  // BRX_IMPORTEXPORT

#include "AcDb/AcDbGlobal.h"
#include "AcDb/AcDbMentalRayRenderSettings.h"
#include "AcDb/AcDbRenderEnvironment.h"
#include "AcDb/AcDbRenderGlobal.h"

#include "AcGi/AcGiContext.h"
#include "AcGi/AcGiContextualColors.h"
#include "AcGi/AcGiEdgeData.h"
#include "AcGi/AcGiFaceData.h"
#include "AcGi/AcGiGradientBackgroundTraits.h"
#include "AcGi/AcGiGroundPlaneBackgroundTraits.h"
#include "AcGi/AcGiImageBackgroundTraits.h"
#include "AcGi/AcGiMentalRayRenderSettingsTraits.h"
#include "AcGi/AcGiRenderEnvironmentTraits.h"
#include "AcGi/AcGiRequestScanLines.h"
#include "AcGi/AcGiSentScanLines.h"
#include "AcGi/AcGiSolidBackgroundTraits.h"
#include "AcGi/AcGiTextStyle.h"
#include "AcGi/AcGiVertexData.h"
#include "AcGi/AcGiViewport.h"
#include "AcGi/AcGiViewportDraw.h"
#include "AcGi/AcGiViewportGeometry.h"
#include "AcGi/AcGiWorldDraw.h"
#include "AcGi/AcGiWorldGeometry.h"