
#pragma once

#ifndef _ARX_UNDOCUMENTED_H_
#define _ARX_UNDOCUMENTED_H_

#include "AcDb/AcDbObject.h"
#include "AcDb/AcDbWipeoutVariables.h"

class AcDbDatabase;
class AcDbViewTableRecord;
class AcApStatusBar;


//------ C-Style exports ------
extern "C"  int    ads_queueexpr      (const ACHAR * lispcmd);


extern "C"  void   acrxGetApiVersion  (int & nMajor, int & nMinor, int & nMajorBuild, int & nMinorBuild);



//----- CPP-Style exports -----
void               ads_regen          ();
int                acedPostCommand    (const ACHAR * arg);
int                acedEvaluateLisp   (const ACHAR * lispexpr, struct resbuf * & rbResult);
Acad::ErrorStatus  acedMspace         (AcDbDatabase * pDb);
Acad::ErrorStatus  acedPspace         (AcDbDatabase * pDb);

int                acdbSetDbmod       (AcDbDatabase* pDb, int newDbModFlags);

int                acedAcadInQuiescentState ();

// this is not existing in ARX
int                acdbLoadHatchPattern    (LPCTSTR szPattern, LPCTSTR szPatternFile);

bool               getCurrentActivePlotStyleTable    (CString & sPlotStyleTable);
//bool             setCurrentActivePlotStyleTable    (const CString & sCurrTable);
Acad::ErrorStatus  getCurrentPlotStyleName           (CString & sPlotStyle, bool what);

Acad::ErrorStatus  acedGetCurrentView      (AcDbViewTableRecord & currentView);

bool               acedHatchPalletteDialog (const ACHAR * szPresetHatch, bool bShowCustomHatches, ACHAR * & szSelectedHatch);
bool               acedPlotstyleDialog     (const ACHAR * szPresetPlotStyle, bool bAllowByLayerByBlock, ACHAR * & szSelectedPlotStyle);

int                acedGetSysvarList  (const ACHAR * mask, CStringArray & sysvars);

int                GetListOfPlotStyleTables  (CStringList & plotStyleTables, bool bRespectPSTYLEMODE, bool bListSTB);
int                GetListOfPlotStyles       (CStringList & plotStyles, CString & sPlotStyleTable, CString & sLayout, bool bHideMetaStyles);
int                GetListOfPlotStylesFromDictionary (CStringList & plotStyles);

Adesk::Boolean     acedRegenPending();
bool               acedIsCommandActive(const ACHAR* command);
int                acedIsCommandNameInUse(const ACHAR* command);
bool               acedExecuteCommand(const ACHAR* command);
bool               acedZoomExtents();
void               acedRegenLayers(const AcDbObjectIdArray& layers, Adesk::Boolean regenPending, Adesk::Boolean regenRequired);

bool               acedLineWeightDialog(AcDb::LineWeight presetLweight, bool allowByBlockByLayer, AcDb::LineWeight& resultLWeight);

#ifdef _WIN32 // not yet under Linux

  bool             acedLinetypeDialog      (AcDbObjectId presetLineTypeId, bool bAllowByLayerByBlock, wchar_t * & selectedLineTypeName, class AcDbObjectId & selectedLineTypeId);
  HWND             acedGetStatusBarHwnd    (AcApStatusBar* ptr);

#endif // _WIN32

#endif  // _ARX_UNDOCUMENTED_H_

