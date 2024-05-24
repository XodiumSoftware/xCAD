// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

// This is an example how to use the C++ Ribbon API from BRX.

#ifdef BRX_APP  // not available with ARX

#include "Misc/MiscGlobal.h"

#include "BrxSpecific/ribbon/AcRibbonBase.h"
#include "BrxSpecific/ribbon/AcRibbonUtils.h"
#include "BrxSpecific/ribbon/AcRibbonServices.h"
#include "BrxSpecific/ribbon/AcRibbonControl.h"
#include "BrxSpecific/ribbon/AcRibbonPaletteSet.h"
#include "BrxSpecific/ribbon/AcRibbonTab.h"
#include "BrxSpecific/ribbon/AcRibbonPanel.h"
#include "BrxSpecific/ribbon/AcRibbonPanelSource.h"
#include "BrxSpecific/ribbon/AcRibbonRowPanel.h"
#include "BrxSpecific/ribbon/AcRibbonReactor.h"
#include "BrxSpecific/ribbon/AcRibbonReactorMgr.h"
#include "BrxSpecific/ribbon/AcRibbonItem.h"
#include "BrxSpecific/ribbon/AcRibbonButton.h"
#include "BrxSpecific/ribbon/AcRibbonToggleButton.h"
#include "BrxSpecific/ribbon/AcRibbonSplitButton.h"
#include "BrxSpecific/ribbon/AcRibbonSeparator.h"
#include "BrxSpecific/ribbon/AcRibbonCombo.h"
#include "BrxSpecific/ribbon/AcRibbonTextBox.h"

bool addRibbonContent();

#endif
