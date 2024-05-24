// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "brx_platform_3264.h"

class CAdUiBaseDialog;
class CAdUiComboBox;
class CAdUiDialog;
class CAdUiDropTarget;
class CAdUiFileDialog;
class CAdUiPalette;
class CAdUiPaletteSet;
class CAdUiTab;
class CAdUiTabChildDialog;
class CAdUiTabExtensionManager;
class CAdUiTabMainDialog;

#define MOVEX 1
#define MOVEY 2
#define MOVEXY 3
#define ELASTICX 16
#define ELASTICY 32
#define ELASTICXY 48

struct DLGCTLINFO
{
    DWORD id;
    DWORD flags;
    DWORD pct;
};

typedef struct DLGCTLINFO* PDLGCTLINFO;

enum ADUI_COMMAND_STATE
{
    kAdUiCommand_Cancelled = -1,
    kAdUiCommand_Completed,
    kAdUiCommand_Begun
};

enum ADUI_NOTIFY
{
    kAdUiNotify_Nothing = 0,
    kAdUiNotify_Generic,
    kAdUiNotify_AppMainWindow,
    kAdUiNotify_AppResourceInstance,
    kAdUiNotify_AutoLoad,
    kAdUiNotify_Reload,
    kAdUiNotify_GetTipSupport,
    kAdUiNotify_GetTipText,
    kAdUiNotify_GetTipRect,
    kAdUiNotify_HitTipRect,
    kAdUiNotify_DrawTip,
    kAdUiNotify_DrawTipText,
    kAdUiNotify_UpdateTip,
    kAdUiNotify_HideWindow,
    kAdUiNotify_ShowWindow,
    kAdUiNotify_RestoreFocus,
    kAdUiNotify_Change,
    kAdUiNotify_NotValid,
    kAdUiNotify_Valid,
    kAdUiNotify_Validate,
    kAdUiNotify_CommandState
};

enum ADUI_REPLY
{
    kAdUiReply_Nothing = 0,
    kAdUiReply_Ok,
    kAdUiReply_NotValid,
    kAdUiReply_Valid,
    kAdUiReply_TextTip,
    kAdUiReply_ToolTip,
    kAdUiReply_DrawTip
};

//V10
enum AdUiThemeElement
{
    kUnknownElements = -1,
    kPaletteFontCaption,
    kPaletteFontTab,
    kPaletteFontToolTip,
    kPaletteFont,
    kWorksheetFont,
    kWorksheetFontCaption,
    kInspectorItemFont,
    kInspectorRootFont,
    kPaletteBackground,
    kPaletteCaptionBackground,
    kPaletteCaptionInactive,
    kPaletteCaptionText,
    kPaletteCaptionInactiveText,
    kPaletteTabText,
    kPaletteTabBackground,
    kPaletteBorder,
    kPaletteTabShadow,
    kPaletteTabHighlight,
    kPaletteTabTextHilite,
    kPaletteTabSelectHilite,
    kPaletteToolTip,
    kPaletteToolTipText,
    kPaletteButtonText,
    kPaletteButtonTextDisabled,
    kPaletteButtonBorder,
    kPaletteItemText,
    kPaletteScrollBackground,
    kPaletteScrollThumb,
    kPaletteScrollArrow,
    kWorksheetBackground,
    kWorksheetCaptionBackground,
    kWorksheetCaptionText,
    kWorksheet3DBtnShadow,
    kWorksheetButtonText,
    kWorksheetButtonTextDisabled,
    kWorksheetScrollBackground,
    kWorksheetScrollThumb,
    kWorksheetBorder,
    kWorksheetGripHighlight,
    kInspector,
    kInspectorTop,
    kInspectorCat,
    kInspectorItem,
    kInspectorBorder,
    kInspectorBorderItem,
    kInspectorTextTop,
    kInspectorTextCat,
    kInspectorTextItem,
    kInspectorFGHighlight,
    kInspectorBGHighlight,
    kInspector3dShadow,
    kInspectorControl,
    kInspectorCatChevron1,
    kInspectorCatChevron2,
    kInspectorSubChevron,
    kPanelBackground,
    kPanelSashBackground,
    kPanelBorder,
    kControlBorder,
    kControlBackground,
    kDisabledControlBorder,
    kControlSupport
};

#define DESIGN_CENTER_THEME ACRX_T("DesignCenter")
#define DIALOG_WORKSHEET_THEME ACRX_T("DialogWorksheet")
#define OWNDERDRAW_BUTTON_THEME ACRX_T("OwnerDrawButton")
#define PALETTE_SET_THEME ACRX_T("PaletteSet")
#define PROPERTY_PALETTE_THEME ACRX_T("PropertyPalette")
#define TOOL_PALETTE_THEME ACRX_T("ToolPalette")
#define TOOL_PANEL_THEME ACRX_T("ToolPanel")

void InitAdUiDLL();
ADUI_NOTIFY AdUiNotification(WPARAM);
const UINT AdUiMessage();
UINT AdUiNotifyId(WPARAM);

//BRX START
BOOL AdUiEnableCoolControls(BOOL);
//BRX END

#ifdef _WIN32 // currently only under Windows

BOOL AdUiFindContextHelpFullPath(LPCTSTR,CString&);
int AdUiAlertDialog(LPCTSTR,LPCTSTR,LPCTSTR,LPCTSTR,UINT = 0);

ADUI_REPLY AdUiNotify(CWnd&,UINT,ADUI_NOTIFY,LPARAM);
ADUI_REPLY AdUiNotify(CWnd*,UINT,ADUI_NOTIFY,LPARAM);
BOOL AdUiPostNotify(CWnd&,UINT,ADUI_NOTIFY,LPARAM);
BOOL AdUiPostNotify(CWnd*,UINT,ADUI_NOTIFY,LPARAM);

void AdUiSubstituteShellFont(CWnd&,CFont&);

#endif // _WIN32