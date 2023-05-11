// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#ifdef _RENDER_SUPPORT_
#error Render API is not supported. If your project does not require this API, please undefine _RENDER_SUPPORT_
#endif

#ifdef _ASE_SUPPORT_
#error ASI/ASE API is not supported. If your project does not require this API, please undefine _ASE_SUPPORT_
#endif

//Tool Palette API is currently not supported
//Field GUI API is currently not supported

#ifdef _WIN32 // _WIN32
#pragma warning(disable:4996)
#endif // _WIN32

#pragma pack(push, 8)

// Include's for C++
#if defined(__cplusplus)

#include "dbxHeaders.h"

#include "AcAp/AcApDataManager.h"
#include "AcAp/AcApDocManager.h"
#include "AcAp/AcApLayoutManager.h"
#include "AcAp/AcApLongTransactionManager.h"

//#include "AcCm/AcCmComplexColor.h"

#include "AcAx/AcAxDocLock.h"

#include "AcEd/AcEdGlobal.h"
#include "AcEd/AcEdCommandStack.h"
#include "AcEd/AcEdCommandStruc.h"
//#include "AcEd/AcEdInputContextReactor.h"
#include "AcEd/AcEdInputPointFilter.h"
#include "AcEd/AcEdInputPointManager.h"
#include "AcEd/AcEdInputPointMonitor.h"
#include "AcEd/AcEditor.h"
#include "AcEd/AcEditorReactor2.h"
#include "AcEd/AcEdJig.h"
#include "AcEd/AcEdServices.h"
#include "AcEd/AcEdSolidSubentitySelector.h"
#include "AcEd/AcEdSSGetFilter2.h"
#include "AcEd/AcEdSSGetSubSelectFilter.h"
#include "AcEd/AcEdUIContext.h"
#include "AcEd/AcEdXrefFileLock.h"
#include "AcEd/AcEdSysVarIterator.h"

//#include "AcPl/AcPlDSDData.h"
//#include "AcPl/AcPlDSDEntry.h"
//#include "AcPl/AcPlGlobal.h"
#include "AcPl/AcPlHostAppServices.h"
//#include "AcPl/AcPlObject.h"
#include "AcPl/AcPlPlotConfig.h"
#include "AcPl/AcPlPlotConfigInfo.h"
#include "AcPl/AcPlPlotConfigManager.h"
#include "AcPl/AcPlPlotEngine.h"
//#include "AcPl/AcPlPlotErrorHandler.h"
#include "AcPl/AcPlPlotErrorHandlerLock.h"
#include "AcPl/AcPlPlotFactory.h"
#include "AcPl/AcPlPlotInfo.h"
#include "AcPl/AcPlPlotInfoValidator.h"
//#include "AcPl/AcPlPlotLogger.h"
#include "AcPl/AcPlPlotLoggingErrorHandler.h"
#include "AcPl/AcPlPlotPageInfo.h"
#include "AcPl/AcPlPlotProgressDialog.h"
#include "AcPl/AcPlPlotReactor.h"
#include "AcPl/AcPlPlotReactorMgr.h"
#include "AcPubl/AcPublishReactor.h"
#include "AcPubl/AcPublishUIReactor.h"

#include "AcRx/AcRxArxApp.h"
#include "Ads/AdsGlobal.h"
#include "AcRx/AcRxVariable.h"
//#include "Ads/AdsMigrate.h"

#include "DMM/AcDMMEntityReactorInfo.h"
//#include "DMM/AcDMMEPlotProperties.h"
//#include "DMM/AcDMMEPlotProperty.h"
//#include "DMM/AcDMMNode.h"
#include "DMM/AcDMMReactor.h"
//#include "DMM/AcDMMResourceInfo.h"
#include "DMM/AcDMMSheetReactorInfo.h"
//#include "DMM/AcDMMWideString.h"
//#include "Misc/AcDmUtil.h"


#if defined(_AFXEXT) && defined(_WIN32)
  #include <winreg.h>

  // MFC - other stuff
  #include "AcAp/AcApStatusBar.h"  
  #include "AcEd/AcEdGlobalMfc.h"
  #include "MFC/CAcModuleResourceOverride.h"
  #include "Misc/CAcGradientThumbnailEngine.h"
  #include "Misc/ClipboardInfo.h"
  #include "Misc/AcPane.h"
  #include "Misc/AcTrayItem.h"

  //MFC - AdUi
  #include "MFC/CAdUi/CAdUiGlobal.h"
  //#include "MFC/CAdUi/CAdUiBaseDialog.h"
  //#include "MFC/CAdUi/CAdUiCDFSVolumeDescriptor.h"
  //#include "MFC/CAdUi/CAdUiComboBox.h"
  #include "MFC/CAdUi/CAdUiCoupledGroupCtrl.h"
  //#include "MFC/CAdUi/CAdUiDialog.h"
  //#include "MFC/CAdUi/CAdUiDockControlBar.h"
  //#include "MFC/CAdUi/CAdUiDrawTipText.h"
  //#include "MFC/CAdUi/CAdUiDropSite.h"
  //#include "MFC/CAdUi/CAdUiDropTarget.h"
  //#include "MFC/CAdUi/CAdUiEdit.h"
  //#include "MFC/CAdUi/CAdUiFATVolumeDescriptor.h"
  //#include "MFC/CAdUi/CAdUiFileDialog.h"
  #include "MFC/CAdUi/CAdUiGroupCtrl.h"
  //#include "MFC/CAdUi/CAdUiHeaderCtrl.h"
  //#include "MFC/CAdUi/CAdUiHPFSVolumeDescriptor.h"
  //#include "MFC/CAdUi/CAdUiListBox.h"
  //#include "MFC/CAdUi/CAdUiListCtrl.h"
  //#include "MFC/CAdUi/CAdUiNOFSVolumeDescriptor.h"
  //#include "MFC/CAdUi/CAdUiNTFSVolumeDescriptor.h"
  #include "MFC/CAdUi/CAdUiPalette.h"
  #include "MFC/CAdUi/CAdUiPaletteSet.h"
  //#include "MFC/CAdUi/CAdUiPathEnums.h"
  //#include "MFC/CAdUi/CAdUiPathname.h"
  //#include "MFC/CAdUi/CAdUiTab.h"
  //#include "MFC/CAdUi/CAdUiTabChildDialog.h"
  //#include "MFC/CAdUi/CAdUiTabExtensionManager.h"
  //#include "MFC/CAdUi/CAdUiTabMainDialog.h"
  //#include "MFC/CAdUi/CAdUiTextTip.h"
  //#include "MFC/CAdUi/CAdUiToolButton.h"
  #include "MFC/CAdUi/CAdUiTrackButton.h"
  //#include "MFC/CAdUi/CAdUiUFSVolumeDescriptor.h"
  //#include "MFC/CAdUi/CAdUiVFATVolumeDescriptor.h"

  //MFC - AcUi
  #include "MFC/CAcUi/CAcUiGlobal.h"
  #include "MFC/CAcUi/CAcUiAngleComboBox.h"
  #include "MFC/CAcUi/CAcUiAngleEdit.h"
  #include "MFC/CAcUi/CAcUiArrowHeadComboBox.h"
  #include "MFC/CAcUi/CAcUiBitmapButton.h"
  #include "MFC/CAcUi/CAcUiBitmapStatic.h"
  #include "MFC/CAcUi/CAcUiColorComboBox.h"
  #include "MFC/CAcUi/CAcUiDialog.h"
  #include "MFC/CAcUi/CAcUiDockControlBar.h"
  #include "MFC/CAcUi/CAcUiDropSite.h"
  #include "MFC/CAcUi/CAcUiFileDialog.h"
  #include "MFC/CAcUi/CAcUiHeaderCtrl.h"
  #include "MFC/CAcUi/CAcUiLineTypeComboBox.h"
  #include "MFC/CAcUi/CAcUiLineWeightComboBox.h"
  //#include "MFC/CAcUi/CAcUiListBox.h"
  #include "MFC/CAcUi/CAcUiListCtrl.h"
  #include "MFC/CAcUi/CAcUiMRUListBox.h"
  #include "MFC/CAcUi/CAcUiNavDialog.h"
  #include "MFC/CAcUi/CAcUiNumericComboBox.h"
  #include "MFC/CAcUi/CAcUiNumericEdit.h"
  #include "MFC/CAcUi/CAcUiOwnerDrawButton.h"
  #include "MFC/CAcUi/CAcUiPathname.h"
  #include "MFC/CAcUi/CAcUiPlotStyleNamesComboBox.h"
  #include "MFC/CAcUi/CAcUiPlotStyleTablesComboBox.h"
  #include "MFC/CAcUi/CAcUiSelectButton.h"
  #include "MFC/CAcUi/CAcUiStringComboBox.h"
  #include "MFC/CAcUi/CAcUiStringEdit.h"
  #include "MFC/CAcUi/CAcUiStringExp.h"
  #include "MFC/CAcUi/CAcUiSymbolComboBox.h"
  #include "MFC/CAcUi/CAcUiSymbolEdit.h"
  #include "MFC/CAcUi/CAcUiTab.h"
  //#include "MFC/CAcUi/CAcUiTabChildDialog.h"
  #include "MFC/CAcUi/CAcUiTabExtension.h"
  #include "MFC/CAcUi/CAcUiTabMainDialog.h"
  #include "MFC/CAcUi/CAcUiToolButton.h"
  #include "MFC/CAcUi/CAcUiTrueColorComboBox.h"

  //MFC - Nav
  //#include "MFC/CNav/CNavArray.h"
  //#include "MFC/CNav/CNavData.h"
  //#include "MFC/CNav/CNavDataArray.h"
  //#include "MFC/CNav/CNavDialog.h"
  //#include "MFC/CNav/CNavFilter.h"
  //#include "MFC/CNav/CNavFilterArray.h"
  //#include "MFC/CNav/CNavListCtrl.h"
#endif // _AFXEXT && _WIN32


// under Linux,Mac we include all MFC stuff ahead
#ifndef _WIN32
  // MFC - other stuff
  #include "AcEd/AcEdGlobalMfc.h"
  #include "MFC/CAcModuleResourceOverride.h"
  #include "Misc/CAcGradientThumbnailEngine.h"
  #include "Misc/ClipboardInfo.h"
  #include "Misc/AcPane.h"
  #include "Misc/AcTrayItem.h"
  // MFC - AdUi+AcUi
  #include "MFC/CAcModuleResourceOverride.h"
  #include "MFC/CAdUi/CAdUiGlobal.h"
  #include "MFC/CAcUi/CAcUiGlobal.h"
#endif // !_WIN32

// ADS C++
#include "adsrxdef.h"


//========================= BRX specific headers =========================

// OPM C++ interface
#include "BrxSpecific/AcOpmExtensions.h"
#include "BrxSpecific/AcEdQuad.h"

// Ribbon C++ interface
#include "BrxSpecific/ribbon/AcRibbonBase.h"
#include "BrxSpecific/ribbon/AcRibbonUtils.h"
#include "BrxSpecific/ribbon/AcRibbonServices.h"
#include "BrxSpecific/ribbon/AcRibbonControl.h"
#include "BrxSpecific/ribbon/AcRibbonPaletteSet.h"
#include "BrxSpecific/ribbon/AcRibbonTab.h"
#include "BrxSpecific/ribbon/AcRibbonPanel.h"
#include "BrxSpecific/ribbon/AcRibbonPanelBreak.h"
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

//========================= BRX specific headers =========================


#endif // __cplusplus

//----- ADS
#include "adsdlg.h"
#include "adslib.h"

#pragma pack(pop)
