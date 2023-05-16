// drx.h: exports for DRX apps
 
// Copyright © Menhirs NV. All rights reserved.

//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH

#pragma once

#include "sds_types.h"

class OdDbObjectId;
class OdDbObject;
class OdDbSelectionSet;
class OdEdLispEngine;
class OdEdUIContext;
class OdEdCommand;
class wxWindow;
class wxBitmap;

struct IUnknown;
struct IDispatch;

#ifdef DRX_NAMESPACE
#define NS_DRX_START namespace DRX_NAMESPACE {
#define NS_DRX_END };
#else
#define NS_DRX_START
#define NS_DRX_END
#endif //DRX_NAMESPACE

NS_DRX_START

typedef void (*DrxCommandFunction) ();

extern "C"
{

#ifdef _WIN32 // COM based interface only under Win32
  IUnknown* drx_getIUnknownOfObject(const sds_name objName, IDispatch* pApp, bool allowErased = false);
  IUnknown* drx_getIUnknownOfObjectId(OdDbObjectId& objId, IDispatch* pApp, bool allowErased = false);
  IUnknown* drx_getIUnknownOfOpenObject(OdDbObject * pObject, IDispatch* pApp, bool allowErased = false);
#endif // _WIN32

enum DrxDockType
{
    eDockTop = 0,
    eDockBottom,
    eDockLeft,
    eDockRight,
    eDockFloat,
    nDockTypes
};
enum DrxDockShowFlags
{
    eShowPanel   = 0x01,
    eHidePanel   = 0x02,
    eWithCaption = 0x04,
    eAutoCollapse = 0x08,
    eNoCloseBtn =  0x10,
};
struct DrxDockState
{
    DrxDockState() :
        m_flags(0), m_dock(0),
        m_row(0), m_col(0),
        m_width(0), m_height(0), m_stack_z(-1),
        m_opacity(0) { }
    DrxDockState(int flags, int dock, int row, int col, int width, int height) :
        m_flags(flags), m_dock(dock),
        m_row(row), m_col(col),
        m_width(width), m_height(height), m_stack_z(-1),
        m_opacity(0) { }
    DrxDockState(int flags, int dock, const OdChar* stack_id, int stack_z,
                    int width, int height, unsigned char opacity = 0) :
        m_flags(flags), m_dock(dock),
        m_row(0), m_col(0),
        m_width(width), m_height(height),
        m_stack_id(stack_id), m_stack_z(stack_z),
        m_opacity(opacity) { }
    DrxDockState(const DrxDockState& ds) :
        m_flags(ds.m_flags), m_dock(ds.m_dock),
        m_row(ds.m_row), m_col(ds.m_col),
        m_width(ds.m_width), m_height(ds.m_height),
        m_stack_id(ds.m_stack_id), m_stack_z(ds.m_stack_z),
        m_opacity(ds.m_opacity) { }
    int m_flags;
    int m_dock;
    int m_row;
    int m_col;
    int m_width;
    int m_height;
    OdString m_stack_id;
    int m_stack_z;
    unsigned char m_opacity;
};

// interface for requesting a panel icon of desired size
struct DrxPanelIcon { virtual wxBitmap GetIcon(int size) const = 0; virtual ~DrxPanelIcon() noexcept = default; };

// translate between sds_name and OdDbObjectId
bool drx_getSdsName(sds_name objName, OdDbObjectId& objId);
bool drx_getObjectId(OdDbObjectId& objId, const sds_name objName);
// translate between SDS selection set name and OdDbSelectionSet
bool drx_sSetToSds(sds_name sdsSSet, OdDbSelectionSet* pSSet);
bool drx_sdsToSSet(OdDbSelectionSet*& pSSet, const sds_name sdsSSet);
const TCHAR * drx_ProductKey ();
const TCHAR * drx_ObjectDRXRegistryKey ();
int  drx_EvaluateLisp (LPCTSTR lispString, struct sds_resbuf * & rbResult);
void drx_logMessage(const TCHAR* s);
OdEdLispEngine* drx_getLispEngine();
bool drx_hatchPalletteDialog (LPCTSTR pSelectedHatch, bool bShowCustomHatches,
                              LPTSTR pNewSelection);
bool drx_linetypeDialog(OdDbObjectId& selectedLineTypeId, bool bShowByLayerByBlock, 
                        OdDbObjectId& newSelectionId);
bool drx_lineweightDialog(const OdDb::LineWeight presetLweight, bool bShowByLayerByBlock, 
                          OdDb::LineWeight& resultLWeight);
bool drx_plotStyleDialog(LPCTSTR pSelectedStyle, bool bShowByLayerByBlock, 
                         LPTSTR pNewSelection);
void drx_dockPanel(wxWindow* panel, const OdString& name, const OdString& title,
                        const DrxDockState& defaultState, const DrxPanelIcon* iconSrc = 0);
bool drx_detachPanel(wxWindow* panel);
void drx_showPanel(const OdString& name, bool show);
bool drx_isPanelActive(const OdString& name); //a stacked panel can be active while not visible
bool drx_isPanelVisible(const OdString& name);
OdEdCommand* drx_addCommand(const OdString& sGroupName,
    const OdString& sGlobalName, const OdString& sLocalName,
    OdUInt32 commandFlags, DrxCommandFunction pFunction, OdRxModule* pModule = 0,
    OdEdUIContext* uiContext = 0, int funCode = -1, HINSTANCE hResource = 0);
void drx_removeCmd(const OdString& sGroupName, const OdString& sGlobalName);

}

////////////////////////////////////////////////////////////////////////////////////////////////
//         Deprecated function and type names, defined here for legacy client code
inline void drx_dockControlBar(wxWindow* pWnd, const OdString& name, const OdString& title,
        const DrxDockState& defaultState, const DrxPanelIcon* iconSrc = 0)
    { drx_dockPanel(pWnd, name, title, defaultState, iconSrc); }
extern "C" bool drx_destroyPanel(wxWindow* panel); //for legacy support only
inline bool drx_freeControlBar(wxWindow* pWnd)
    { if (!drx_detachPanel(pWnd)) return false; return drx_destroyPanel(pWnd); }
inline void drx_showControlBar(const OdString& name, bool show) { drx_showPanel(name, show); }
inline bool drx_isControlBarVisible(const OdString& name) { return drx_isPanelVisible(name); }
enum DrxDockStateFlags
{
    eShowDockBar = eShowPanel,
    eHideDockBar = eHidePanel,
    eShowCaption = eWithCaption,
};
////////////////////////////////////////////////////////////////////////////////////////////////

NS_DRX_END
