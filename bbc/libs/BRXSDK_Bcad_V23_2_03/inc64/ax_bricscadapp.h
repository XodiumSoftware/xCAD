

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 03:14:07 2038
 */
/* Compiler settings for D:/dev/release/bricscad/bricscad/src/appx/ax_bricscadapp.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.01.0622 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */


#ifndef __ax_bricscadapp_h__
#define __ax_bricscadapp_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ITransmittalOperation_FWD_DEFINED__
#define __ITransmittalOperation_FWD_DEFINED__
typedef interface ITransmittalOperation ITransmittalOperation;

#endif 	/* __ITransmittalOperation_FWD_DEFINED__ */


#ifndef __ITransmittalFilesGraph_FWD_DEFINED__
#define __ITransmittalFilesGraph_FWD_DEFINED__
typedef interface ITransmittalFilesGraph ITransmittalFilesGraph;

#endif 	/* __ITransmittalFilesGraph_FWD_DEFINED__ */


#ifndef __ITransmittalFile_FWD_DEFINED__
#define __ITransmittalFile_FWD_DEFINED__
typedef interface ITransmittalFile ITransmittalFile;

#endif 	/* __ITransmittalFile_FWD_DEFINED__ */


#ifndef __ITransmittalInfo_FWD_DEFINED__
#define __ITransmittalInfo_FWD_DEFINED__
typedef interface ITransmittalInfo ITransmittalInfo;

#endif 	/* __ITransmittalInfo_FWD_DEFINED__ */


#ifndef __IAcadMenuGroups_FWD_DEFINED__
#define __IAcadMenuGroups_FWD_DEFINED__
typedef interface IAcadMenuGroups IAcadMenuGroups;

#endif 	/* __IAcadMenuGroups_FWD_DEFINED__ */


#ifndef __IAcadMenuGroup_FWD_DEFINED__
#define __IAcadMenuGroup_FWD_DEFINED__
typedef interface IAcadMenuGroup IAcadMenuGroup;

#endif 	/* __IAcadMenuGroup_FWD_DEFINED__ */


#ifndef __IAcadPopupMenus_FWD_DEFINED__
#define __IAcadPopupMenus_FWD_DEFINED__
typedef interface IAcadPopupMenus IAcadPopupMenus;

#endif 	/* __IAcadPopupMenus_FWD_DEFINED__ */


#ifndef __IAcadPopupMenu_FWD_DEFINED__
#define __IAcadPopupMenu_FWD_DEFINED__
typedef interface IAcadPopupMenu IAcadPopupMenu;

#endif 	/* __IAcadPopupMenu_FWD_DEFINED__ */


#ifndef __IAcadPopupMenuItem_FWD_DEFINED__
#define __IAcadPopupMenuItem_FWD_DEFINED__
typedef interface IAcadPopupMenuItem IAcadPopupMenuItem;

#endif 	/* __IAcadPopupMenuItem_FWD_DEFINED__ */


#ifndef __IAcadToolbars_FWD_DEFINED__
#define __IAcadToolbars_FWD_DEFINED__
typedef interface IAcadToolbars IAcadToolbars;

#endif 	/* __IAcadToolbars_FWD_DEFINED__ */


#ifndef __IAcadToolbar_FWD_DEFINED__
#define __IAcadToolbar_FWD_DEFINED__
typedef interface IAcadToolbar IAcadToolbar;

#endif 	/* __IAcadToolbar_FWD_DEFINED__ */


#ifndef __IAcadToolbarItem_FWD_DEFINED__
#define __IAcadToolbarItem_FWD_DEFINED__
typedef interface IAcadToolbarItem IAcadToolbarItem;

#endif 	/* __IAcadToolbarItem_FWD_DEFINED__ */


#ifndef __IAcadMenuBar_FWD_DEFINED__
#define __IAcadMenuBar_FWD_DEFINED__
typedef interface IAcadMenuBar IAcadMenuBar;

#endif 	/* __IAcadMenuBar_FWD_DEFINED__ */


#ifndef __IAcadApplication_FWD_DEFINED__
#define __IAcadApplication_FWD_DEFINED__
typedef interface IAcadApplication IAcadApplication;

#endif 	/* __IAcadApplication_FWD_DEFINED__ */


#ifndef __IAcadUtility_FWD_DEFINED__
#define __IAcadUtility_FWD_DEFINED__
typedef interface IAcadUtility IAcadUtility;

#endif 	/* __IAcadUtility_FWD_DEFINED__ */


#ifndef __IAcadDocument_FWD_DEFINED__
#define __IAcadDocument_FWD_DEFINED__
typedef interface IAcadDocument IAcadDocument;

#endif 	/* __IAcadDocument_FWD_DEFINED__ */


#ifndef __IAcadDocuments_FWD_DEFINED__
#define __IAcadDocuments_FWD_DEFINED__
typedef interface IAcadDocuments IAcadDocuments;

#endif 	/* __IAcadDocuments_FWD_DEFINED__ */


#ifndef __IAcadSelectionSets_FWD_DEFINED__
#define __IAcadSelectionSets_FWD_DEFINED__
typedef interface IAcadSelectionSets IAcadSelectionSets;

#endif 	/* __IAcadSelectionSets_FWD_DEFINED__ */


#ifndef __IAcadSelectionSet_FWD_DEFINED__
#define __IAcadSelectionSet_FWD_DEFINED__
typedef interface IAcadSelectionSet IAcadSelectionSet;

#endif 	/* __IAcadSelectionSet_FWD_DEFINED__ */


#ifndef __IAcadPreferences_FWD_DEFINED__
#define __IAcadPreferences_FWD_DEFINED__
typedef interface IAcadPreferences IAcadPreferences;

#endif 	/* __IAcadPreferences_FWD_DEFINED__ */


#ifndef __IAcadPreferencesFiles_FWD_DEFINED__
#define __IAcadPreferencesFiles_FWD_DEFINED__
typedef interface IAcadPreferencesFiles IAcadPreferencesFiles;

#endif 	/* __IAcadPreferencesFiles_FWD_DEFINED__ */


#ifndef __IAcadPlot_FWD_DEFINED__
#define __IAcadPlot_FWD_DEFINED__
typedef interface IAcadPlot IAcadPlot;

#endif 	/* __IAcadPlot_FWD_DEFINED__ */


#ifndef __IAcadLayerStateManager_FWD_DEFINED__
#define __IAcadLayerStateManager_FWD_DEFINED__
typedef interface IAcadLayerStateManager IAcadLayerStateManager;

#endif 	/* __IAcadLayerStateManager_FWD_DEFINED__ */


#ifndef __IAcadSecurityParams_FWD_DEFINED__
#define __IAcadSecurityParams_FWD_DEFINED__
typedef interface IAcadSecurityParams IAcadSecurityParams;

#endif 	/* __IAcadSecurityParams_FWD_DEFINED__ */


#ifndef __IAcadPreferencesDisplay_FWD_DEFINED__
#define __IAcadPreferencesDisplay_FWD_DEFINED__
typedef interface IAcadPreferencesDisplay IAcadPreferencesDisplay;

#endif 	/* __IAcadPreferencesDisplay_FWD_DEFINED__ */


#ifndef __IAcadPreferencesOpenSave_FWD_DEFINED__
#define __IAcadPreferencesOpenSave_FWD_DEFINED__
typedef interface IAcadPreferencesOpenSave IAcadPreferencesOpenSave;

#endif 	/* __IAcadPreferencesOpenSave_FWD_DEFINED__ */


#ifndef __IAcadPreferencesOutput_FWD_DEFINED__
#define __IAcadPreferencesOutput_FWD_DEFINED__
typedef interface IAcadPreferencesOutput IAcadPreferencesOutput;

#endif 	/* __IAcadPreferencesOutput_FWD_DEFINED__ */


#ifndef __IAcadPreferencesPdfOutput_FWD_DEFINED__
#define __IAcadPreferencesPdfOutput_FWD_DEFINED__
typedef interface IAcadPreferencesPdfOutput IAcadPreferencesPdfOutput;

#endif 	/* __IAcadPreferencesPdfOutput_FWD_DEFINED__ */


#ifndef __IAcadPreferencesSystem_FWD_DEFINED__
#define __IAcadPreferencesSystem_FWD_DEFINED__
typedef interface IAcadPreferencesSystem IAcadPreferencesSystem;

#endif 	/* __IAcadPreferencesSystem_FWD_DEFINED__ */


#ifndef __IAcadPreferencesUser_FWD_DEFINED__
#define __IAcadPreferencesUser_FWD_DEFINED__
typedef interface IAcadPreferencesUser IAcadPreferencesUser;

#endif 	/* __IAcadPreferencesUser_FWD_DEFINED__ */


#ifndef __IAcadPreferencesDrafting_FWD_DEFINED__
#define __IAcadPreferencesDrafting_FWD_DEFINED__
typedef interface IAcadPreferencesDrafting IAcadPreferencesDrafting;

#endif 	/* __IAcadPreferencesDrafting_FWD_DEFINED__ */


#ifndef __IAcadPreferencesSelection_FWD_DEFINED__
#define __IAcadPreferencesSelection_FWD_DEFINED__
typedef interface IAcadPreferencesSelection IAcadPreferencesSelection;

#endif 	/* __IAcadPreferencesSelection_FWD_DEFINED__ */


#ifndef __IAcadPreferencesProfiles_FWD_DEFINED__
#define __IAcadPreferencesProfiles_FWD_DEFINED__
typedef interface IAcadPreferencesProfiles IAcadPreferencesProfiles;

#endif 	/* __IAcadPreferencesProfiles_FWD_DEFINED__ */


#ifndef __IAcadState_FWD_DEFINED__
#define __IAcadState_FWD_DEFINED__
typedef interface IAcadState IAcadState;

#endif 	/* __IAcadState_FWD_DEFINED__ */


#ifndef __IOdaDwfTemplate_FWD_DEFINED__
#define __IOdaDwfTemplate_FWD_DEFINED__
typedef interface IOdaDwfTemplate IOdaDwfTemplate;

#endif 	/* __IOdaDwfTemplate_FWD_DEFINED__ */


#ifndef __IOdaDwfPageData_FWD_DEFINED__
#define __IOdaDwfPageData_FWD_DEFINED__
typedef interface IOdaDwfPageData IOdaDwfPageData;

#endif 	/* __IOdaDwfPageData_FWD_DEFINED__ */


#ifndef __IOdaDwfImporter_FWD_DEFINED__
#define __IOdaDwfImporter_FWD_DEFINED__
typedef interface IOdaDwfImporter IOdaDwfImporter;

#endif 	/* __IOdaDwfImporter_FWD_DEFINED__ */


#ifndef __IOdaDwfImporter2_FWD_DEFINED__
#define __IOdaDwfImporter2_FWD_DEFINED__
typedef interface IOdaDwfImporter2 IOdaDwfImporter2;

#endif 	/* __IOdaDwfImporter2_FWD_DEFINED__ */


#ifndef __IOdaSvgExporter_FWD_DEFINED__
#define __IOdaSvgExporter_FWD_DEFINED__
typedef interface IOdaSvgExporter IOdaSvgExporter;

#endif 	/* __IOdaSvgExporter_FWD_DEFINED__ */


#ifndef __IOdaAuditInfo_FWD_DEFINED__
#define __IOdaAuditInfo_FWD_DEFINED__
typedef interface IOdaAuditInfo IOdaAuditInfo;

#endif 	/* __IOdaAuditInfo_FWD_DEFINED__ */


#ifndef __IOdaBmpOut_FWD_DEFINED__
#define __IOdaBmpOut_FWD_DEFINED__
typedef interface IOdaBmpOut IOdaBmpOut;

#endif 	/* __IOdaBmpOut_FWD_DEFINED__ */


#ifndef __IOdaDwf3dExport_FWD_DEFINED__
#define __IOdaDwf3dExport_FWD_DEFINED__
typedef interface IOdaDwf3dExport IOdaDwf3dExport;

#endif 	/* __IOdaDwf3dExport_FWD_DEFINED__ */


#ifndef __TransmittalOperation_FWD_DEFINED__
#define __TransmittalOperation_FWD_DEFINED__

#ifdef __cplusplus
typedef class TransmittalOperation TransmittalOperation;
#else
typedef struct TransmittalOperation TransmittalOperation;
#endif /* __cplusplus */

#endif 	/* __TransmittalOperation_FWD_DEFINED__ */


#ifndef __TransmittalFilesGraph_FWD_DEFINED__
#define __TransmittalFilesGraph_FWD_DEFINED__

#ifdef __cplusplus
typedef class TransmittalFilesGraph TransmittalFilesGraph;
#else
typedef struct TransmittalFilesGraph TransmittalFilesGraph;
#endif /* __cplusplus */

#endif 	/* __TransmittalFilesGraph_FWD_DEFINED__ */


#ifndef __TransmittalFile_FWD_DEFINED__
#define __TransmittalFile_FWD_DEFINED__

#ifdef __cplusplus
typedef class TransmittalFile TransmittalFile;
#else
typedef struct TransmittalFile TransmittalFile;
#endif /* __cplusplus */

#endif 	/* __TransmittalFile_FWD_DEFINED__ */


#ifndef __TransmittalInfo_FWD_DEFINED__
#define __TransmittalInfo_FWD_DEFINED__

#ifdef __cplusplus
typedef class TransmittalInfo TransmittalInfo;
#else
typedef struct TransmittalInfo TransmittalInfo;
#endif /* __cplusplus */

#endif 	/* __TransmittalInfo_FWD_DEFINED__ */


#ifndef __AcadMenuGroups_FWD_DEFINED__
#define __AcadMenuGroups_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcadMenuGroups AcadMenuGroups;
#else
typedef struct AcadMenuGroups AcadMenuGroups;
#endif /* __cplusplus */

#endif 	/* __AcadMenuGroups_FWD_DEFINED__ */


#ifndef __AcadMenuGroup_FWD_DEFINED__
#define __AcadMenuGroup_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcadMenuGroup AcadMenuGroup;
#else
typedef struct AcadMenuGroup AcadMenuGroup;
#endif /* __cplusplus */

#endif 	/* __AcadMenuGroup_FWD_DEFINED__ */


#ifndef __AcadMenuBar_FWD_DEFINED__
#define __AcadMenuBar_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcadMenuBar AcadMenuBar;
#else
typedef struct AcadMenuBar AcadMenuBar;
#endif /* __cplusplus */

#endif 	/* __AcadMenuBar_FWD_DEFINED__ */


#ifndef __AcadPopupMenus_FWD_DEFINED__
#define __AcadPopupMenus_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcadPopupMenus AcadPopupMenus;
#else
typedef struct AcadPopupMenus AcadPopupMenus;
#endif /* __cplusplus */

#endif 	/* __AcadPopupMenus_FWD_DEFINED__ */


#ifndef __AcadPopupMenu_FWD_DEFINED__
#define __AcadPopupMenu_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcadPopupMenu AcadPopupMenu;
#else
typedef struct AcadPopupMenu AcadPopupMenu;
#endif /* __cplusplus */

#endif 	/* __AcadPopupMenu_FWD_DEFINED__ */


#ifndef __AcadPopupMenuItem_FWD_DEFINED__
#define __AcadPopupMenuItem_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcadPopupMenuItem AcadPopupMenuItem;
#else
typedef struct AcadPopupMenuItem AcadPopupMenuItem;
#endif /* __cplusplus */

#endif 	/* __AcadPopupMenuItem_FWD_DEFINED__ */


#ifndef __AcadToolbars_FWD_DEFINED__
#define __AcadToolbars_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcadToolbars AcadToolbars;
#else
typedef struct AcadToolbars AcadToolbars;
#endif /* __cplusplus */

#endif 	/* __AcadToolbars_FWD_DEFINED__ */


#ifndef __AcadToolbar_FWD_DEFINED__
#define __AcadToolbar_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcadToolbar AcadToolbar;
#else
typedef struct AcadToolbar AcadToolbar;
#endif /* __cplusplus */

#endif 	/* __AcadToolbar_FWD_DEFINED__ */


#ifndef __AcadToolbarItem_FWD_DEFINED__
#define __AcadToolbarItem_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcadToolbarItem AcadToolbarItem;
#else
typedef struct AcadToolbarItem AcadToolbarItem;
#endif /* __cplusplus */

#endif 	/* __AcadToolbarItem_FWD_DEFINED__ */


#ifndef ___DAcadApplicationEvents_FWD_DEFINED__
#define ___DAcadApplicationEvents_FWD_DEFINED__
typedef interface _DAcadApplicationEvents _DAcadApplicationEvents;

#endif 	/* ___DAcadApplicationEvents_FWD_DEFINED__ */


#ifndef ___DAcadDocumentEvents_FWD_DEFINED__
#define ___DAcadDocumentEvents_FWD_DEFINED__
typedef interface _DAcadDocumentEvents _DAcadDocumentEvents;

#endif 	/* ___DAcadDocumentEvents_FWD_DEFINED__ */


#ifndef __IOdaHostApp_FWD_DEFINED__
#define __IOdaHostApp_FWD_DEFINED__
typedef interface IOdaHostApp IOdaHostApp;

#endif 	/* __IOdaHostApp_FWD_DEFINED__ */


#ifndef __IOdaConsole_FWD_DEFINED__
#define __IOdaConsole_FWD_DEFINED__
typedef interface IOdaConsole IOdaConsole;

#endif 	/* __IOdaConsole_FWD_DEFINED__ */


#ifndef __IOdaHostApp2_FWD_DEFINED__
#define __IOdaHostApp2_FWD_DEFINED__
typedef interface IOdaHostApp2 IOdaHostApp2;

#endif 	/* __IOdaHostApp2_FWD_DEFINED__ */


#ifndef __IOdaBagFiler_FWD_DEFINED__
#define __IOdaBagFiler_FWD_DEFINED__
typedef interface IOdaBagFiler IOdaBagFiler;

#endif 	/* __IOdaBagFiler_FWD_DEFINED__ */


#ifndef __AcPePropertyEditorColor_FWD_DEFINED__
#define __AcPePropertyEditorColor_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcPePropertyEditorColor AcPePropertyEditorColor;
#else
typedef struct AcPePropertyEditorColor AcPePropertyEditorColor;
#endif /* __cplusplus */

#endif 	/* __AcPePropertyEditorColor_FWD_DEFINED__ */


#ifndef __AcPePropertyEditorTextStyle_FWD_DEFINED__
#define __AcPePropertyEditorTextStyle_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcPePropertyEditorTextStyle AcPePropertyEditorTextStyle;
#else
typedef struct AcPePropertyEditorTextStyle AcPePropertyEditorTextStyle;
#endif /* __cplusplus */

#endif 	/* __AcPePropertyEditorTextStyle_FWD_DEFINED__ */


#ifndef __AcPePropertyEditorLType_FWD_DEFINED__
#define __AcPePropertyEditorLType_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcPePropertyEditorLType AcPePropertyEditorLType;
#else
typedef struct AcPePropertyEditorLType AcPePropertyEditorLType;
#endif /* __cplusplus */

#endif 	/* __AcPePropertyEditorLType_FWD_DEFINED__ */


#ifndef __AcPePropertyEditorLayer_FWD_DEFINED__
#define __AcPePropertyEditorLayer_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcPePropertyEditorLayer AcPePropertyEditorLayer;
#else
typedef struct AcPePropertyEditorLayer AcPePropertyEditorLayer;
#endif /* __cplusplus */

#endif 	/* __AcPePropertyEditorLayer_FWD_DEFINED__ */


#ifndef __AcPePropertyEditorLWeight_FWD_DEFINED__
#define __AcPePropertyEditorLWeight_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcPePropertyEditorLWeight AcPePropertyEditorLWeight;
#else
typedef struct AcPePropertyEditorLWeight AcPePropertyEditorLWeight;
#endif /* __cplusplus */

#endif 	/* __AcPePropertyEditorLWeight_FWD_DEFINED__ */


#ifndef __AcPePropertyEditorEllipses_FWD_DEFINED__
#define __AcPePropertyEditorEllipses_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcPePropertyEditorEllipses AcPePropertyEditorEllipses;
#else
typedef struct AcPePropertyEditorEllipses AcPePropertyEditorEllipses;
#endif /* __cplusplus */

#endif 	/* __AcPePropertyEditorEllipses_FWD_DEFINED__ */


#ifndef __AcPePick2PointsCtrl_FWD_DEFINED__
#define __AcPePick2PointsCtrl_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcPePick2PointsCtrl AcPePick2PointsCtrl;
#else
typedef struct AcPePick2PointsCtrl AcPePick2PointsCtrl;
#endif /* __cplusplus */

#endif 	/* __AcPePick2PointsCtrl_FWD_DEFINED__ */


#ifndef __AcadApplication_FWD_DEFINED__
#define __AcadApplication_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcadApplication AcadApplication;
#else
typedef struct AcadApplication AcadApplication;
#endif /* __cplusplus */

#endif 	/* __AcadApplication_FWD_DEFINED__ */


#ifndef __AcadDocuments_FWD_DEFINED__
#define __AcadDocuments_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcadDocuments AcadDocuments;
#else
typedef struct AcadDocuments AcadDocuments;
#endif /* __cplusplus */

#endif 	/* __AcadDocuments_FWD_DEFINED__ */


#ifndef __AcadDocument_FWD_DEFINED__
#define __AcadDocument_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcadDocument AcadDocument;
#else
typedef struct AcadDocument AcadDocument;
#endif /* __cplusplus */

#endif 	/* __AcadDocument_FWD_DEFINED__ */


#ifndef ___IOdaHostAppEvents_FWD_DEFINED__
#define ___IOdaHostAppEvents_FWD_DEFINED__
typedef interface _IOdaHostAppEvents _IOdaHostAppEvents;

#endif 	/* ___IOdaHostAppEvents_FWD_DEFINED__ */


#ifndef __OdaHostApp_FWD_DEFINED__
#define __OdaHostApp_FWD_DEFINED__

#ifdef __cplusplus
typedef class OdaHostApp OdaHostApp;
#else
typedef struct OdaHostApp OdaHostApp;
#endif /* __cplusplus */

#endif 	/* __OdaHostApp_FWD_DEFINED__ */


#ifndef __AcadUtility_FWD_DEFINED__
#define __AcadUtility_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcadUtility AcadUtility;
#else
typedef struct AcadUtility AcadUtility;
#endif /* __cplusplus */

#endif 	/* __AcadUtility_FWD_DEFINED__ */


#ifndef __AcadPreferences_FWD_DEFINED__
#define __AcadPreferences_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcadPreferences AcadPreferences;
#else
typedef struct AcadPreferences AcadPreferences;
#endif /* __cplusplus */

#endif 	/* __AcadPreferences_FWD_DEFINED__ */


#ifndef __AcadPreferencesFiles_FWD_DEFINED__
#define __AcadPreferencesFiles_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcadPreferencesFiles AcadPreferencesFiles;
#else
typedef struct AcadPreferencesFiles AcadPreferencesFiles;
#endif /* __cplusplus */

#endif 	/* __AcadPreferencesFiles_FWD_DEFINED__ */


#ifndef __AcadPreferencesDisplay_FWD_DEFINED__
#define __AcadPreferencesDisplay_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcadPreferencesDisplay AcadPreferencesDisplay;
#else
typedef struct AcadPreferencesDisplay AcadPreferencesDisplay;
#endif /* __cplusplus */

#endif 	/* __AcadPreferencesDisplay_FWD_DEFINED__ */


#ifndef __AcadPreferencesOpenSave_FWD_DEFINED__
#define __AcadPreferencesOpenSave_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcadPreferencesOpenSave AcadPreferencesOpenSave;
#else
typedef struct AcadPreferencesOpenSave AcadPreferencesOpenSave;
#endif /* __cplusplus */

#endif 	/* __AcadPreferencesOpenSave_FWD_DEFINED__ */


#ifndef __AcadPreferencesOutput_FWD_DEFINED__
#define __AcadPreferencesOutput_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcadPreferencesOutput AcadPreferencesOutput;
#else
typedef struct AcadPreferencesOutput AcadPreferencesOutput;
#endif /* __cplusplus */

#endif 	/* __AcadPreferencesOutput_FWD_DEFINED__ */


#ifndef __AcadPreferencesPdfOutput_FWD_DEFINED__
#define __AcadPreferencesPdfOutput_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcadPreferencesPdfOutput AcadPreferencesPdfOutput;
#else
typedef struct AcadPreferencesPdfOutput AcadPreferencesPdfOutput;
#endif /* __cplusplus */

#endif 	/* __AcadPreferencesPdfOutput_FWD_DEFINED__ */


#ifndef __AcadPreferencesSystem_FWD_DEFINED__
#define __AcadPreferencesSystem_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcadPreferencesSystem AcadPreferencesSystem;
#else
typedef struct AcadPreferencesSystem AcadPreferencesSystem;
#endif /* __cplusplus */

#endif 	/* __AcadPreferencesSystem_FWD_DEFINED__ */


#ifndef __AcadPreferencesUser_FWD_DEFINED__
#define __AcadPreferencesUser_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcadPreferencesUser AcadPreferencesUser;
#else
typedef struct AcadPreferencesUser AcadPreferencesUser;
#endif /* __cplusplus */

#endif 	/* __AcadPreferencesUser_FWD_DEFINED__ */


#ifndef __AcadPreferencesDrafting_FWD_DEFINED__
#define __AcadPreferencesDrafting_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcadPreferencesDrafting AcadPreferencesDrafting;
#else
typedef struct AcadPreferencesDrafting AcadPreferencesDrafting;
#endif /* __cplusplus */

#endif 	/* __AcadPreferencesDrafting_FWD_DEFINED__ */


#ifndef __AcadPreferencesSelection_FWD_DEFINED__
#define __AcadPreferencesSelection_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcadPreferencesSelection AcadPreferencesSelection;
#else
typedef struct AcadPreferencesSelection AcadPreferencesSelection;
#endif /* __cplusplus */

#endif 	/* __AcadPreferencesSelection_FWD_DEFINED__ */


#ifndef __AcadPreferencesProfiles_FWD_DEFINED__
#define __AcadPreferencesProfiles_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcadPreferencesProfiles AcadPreferencesProfiles;
#else
typedef struct AcadPreferencesProfiles AcadPreferencesProfiles;
#endif /* __cplusplus */

#endif 	/* __AcadPreferencesProfiles_FWD_DEFINED__ */


#ifndef __AcadState_FWD_DEFINED__
#define __AcadState_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcadState AcadState;
#else
typedef struct AcadState AcadState;
#endif /* __cplusplus */

#endif 	/* __AcadState_FWD_DEFINED__ */


#ifndef __AcadSelectionSet_FWD_DEFINED__
#define __AcadSelectionSet_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcadSelectionSet AcadSelectionSet;
#else
typedef struct AcadSelectionSet AcadSelectionSet;
#endif /* __cplusplus */

#endif 	/* __AcadSelectionSet_FWD_DEFINED__ */


#ifndef __AcadSelectionSets_FWD_DEFINED__
#define __AcadSelectionSets_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcadSelectionSets AcadSelectionSets;
#else
typedef struct AcadSelectionSets AcadSelectionSets;
#endif /* __cplusplus */

#endif 	/* __AcadSelectionSets_FWD_DEFINED__ */


#ifndef __AcadPlot_FWD_DEFINED__
#define __AcadPlot_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcadPlot AcadPlot;
#else
typedef struct AcadPlot AcadPlot;
#endif /* __cplusplus */

#endif 	/* __AcadPlot_FWD_DEFINED__ */


#ifndef __OdaDwfTemplate_FWD_DEFINED__
#define __OdaDwfTemplate_FWD_DEFINED__

#ifdef __cplusplus
typedef class OdaDwfTemplate OdaDwfTemplate;
#else
typedef struct OdaDwfTemplate OdaDwfTemplate;
#endif /* __cplusplus */

#endif 	/* __OdaDwfTemplate_FWD_DEFINED__ */


#ifndef __OdaDwf3dExport_FWD_DEFINED__
#define __OdaDwf3dExport_FWD_DEFINED__

#ifdef __cplusplus
typedef class OdaDwf3dExport OdaDwf3dExport;
#else
typedef struct OdaDwf3dExport OdaDwf3dExport;
#endif /* __cplusplus */

#endif 	/* __OdaDwf3dExport_FWD_DEFINED__ */


#ifndef __OdaDwfImporter_FWD_DEFINED__
#define __OdaDwfImporter_FWD_DEFINED__

#ifdef __cplusplus
typedef class OdaDwfImporter OdaDwfImporter;
#else
typedef struct OdaDwfImporter OdaDwfImporter;
#endif /* __cplusplus */

#endif 	/* __OdaDwfImporter_FWD_DEFINED__ */


#ifndef __AcadLayerStateManager_FWD_DEFINED__
#define __AcadLayerStateManager_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcadLayerStateManager AcadLayerStateManager;
#else
typedef struct AcadLayerStateManager AcadLayerStateManager;
#endif /* __cplusplus */

#endif 	/* __AcadLayerStateManager_FWD_DEFINED__ */


#ifndef __AcadSecurityParams_FWD_DEFINED__
#define __AcadSecurityParams_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcadSecurityParams AcadSecurityParams;
#else
typedef struct AcadSecurityParams AcadSecurityParams;
#endif /* __cplusplus */

#endif 	/* __AcadSecurityParams_FWD_DEFINED__ */


#ifndef __OdaSvgExporter_FWD_DEFINED__
#define __OdaSvgExporter_FWD_DEFINED__

#ifdef __cplusplus
typedef class OdaSvgExporter OdaSvgExporter;
#else
typedef struct OdaSvgExporter OdaSvgExporter;
#endif /* __cplusplus */

#endif 	/* __OdaSvgExporter_FWD_DEFINED__ */


#ifndef __OdaBmpOut_FWD_DEFINED__
#define __OdaBmpOut_FWD_DEFINED__

#ifdef __cplusplus
typedef class OdaBmpOut OdaBmpOut;
#else
typedef struct OdaBmpOut OdaBmpOut;
#endif /* __cplusplus */

#endif 	/* __OdaBmpOut_FWD_DEFINED__ */


#ifndef __OdaBagFiler_FWD_DEFINED__
#define __OdaBagFiler_FWD_DEFINED__

#ifdef __cplusplus
typedef class OdaBagFiler OdaBagFiler;
#else
typedef struct OdaBagFiler OdaBagFiler;
#endif /* __cplusplus */

#endif 	/* __OdaBagFiler_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __BricscadApp_LIBRARY_DEFINED__
#define __BricscadApp_LIBRARY_DEFINED__

/* library BricscadApp */
/* [helpstring][version][uuid] */ 





typedef /* [public][public][uuid] */  DECLSPEC_UUID("784D805F-BE7D-4bf7-ADA7-38605684310F") 
enum __MIDL___MIDL_itf_ax_bricscadapp_0000_0000_0001
    {
        eNoType	= -1,
        eDwgFile	= 0,
        eXrefFile	= 1,
        eImageFile	= 2,
        eFontFile	= 3,
        eShxFontFile	= 4,
        ePfbFontFile	= 5,
        eTtfFontFile	= 6,
        eAltFontFile	= 7,
        eShxAltFontFile	= 8,
        ePfbAltFontFile	= 9,
        eTtfAltFontFile	= 10,
        ePlotCfgFile	= 11,
        ePlotStyleTableFile	= 12,
        eFontMapFile	= 13,
        e3rdPartyAddedFile	= 14,
        eUserAddedFile	= 15,
        eXrefAttachFile	= 16,
        eXrefOverlayFile	= 17,
        eSheetSetFile	= 18,
        eSheetSetSupportFile	= 19,
        eDGNUnderlay	= 20,
        eDWFUnderlay	= 21,
        ePDFUnderlay	= 22,
        eMaterialTextureFile	= 23,
        ePhotometricWebFile	= 24,
        eDataLinkFile	= 25,
        eEdgeTextureFile	= 26,
        eGeneratedFile	= 27
    } 	FileType;

typedef /* [public][public][public][uuid] */  DECLSPEC_UUID("6A70811F-6D95-49c1-AEB7-751D6AF649EF") 
enum __MIDL___MIDL_itf_ax_bricscadapp_0000_0000_0002
    {
        eFileAdded	= 0,
        eRelationshipAdded	= 1,
        eFileNotAdded	= 2,
        eFileNotAddedToPreventCycle	= 3,
        eFileNotAddedBadArg	= 4,
        eFileAlreadyAdded	= 5
    } 	AddFileReturnVal;

typedef /* [public][public][public][uuid] */  DECLSPEC_UUID("F40EDE01-6F1C-4987-8CD3-67FEDA1F2C7A") 
enum __MIDL___MIDL_itf_ax_bricscadapp_0000_0000_0003
    {
        eNoConversion	= 0,
        eAutoCADR18	= 1,
        eAutoCAD2000	= 2,
        eAutoCAD14	= 3,
        eAutoCADR21	= 4
    } 	SaveDwgFormat;

typedef /* [public][public][public][uuid] */  DECLSPEC_UUID("81F6DC05-B4B3-4610-BF33-EE26C45DA921") 
enum __MIDL___MIDL_itf_ax_bricscadapp_0000_0000_0004
    {
        eOverwriteNo	= 0,
        eOverwriteYes	= 1,
        eOverwriteYesToAll	= 2,
        eOverwriteCancel	= 3,
        eOverwriteYesToAllReadOnly	= 4
    } 	OverwriteResponseType;






















































typedef /* [uuid] */  DECLSPEC_UUID("84D7DE3C-6588-48de-8BE2-EFD51A55449F") 
enum OdSaveAsType
    {
        odR09_dxf	= -5,
        odR10_dxf	= -4,
        odR12_dwg	= -3,
        odUnknown	= -1,
        odR12_dxf	= 1,
        odR13_dwg	= 4,
        odR13_dxf	= 5,
        odR14_dwg	= 8,
        odR14_dxf	= 9,
        odR15_dwg	= 12,
        odR15_dxf	= 13,
        odR15_Template	= 14,
        od2000_dwg	= odR15_dwg,
        od2000_dxf	= odR15_dxf,
        od2000_Template	= odR15_Template,
        odR18_dwg	= 24,
        odR18_dxf	= 25,
        odR18_Template	= 26,
        od2004_dwg	= odR18_dwg,
        od2004_dxf	= odR18_dxf,
        od2004_Template	= odR18_Template,
        odR21_dwg	= 36,
        odR21_dxf	= 37,
        odR21_Template	= 38,
        od2007_dwg	= odR21_dwg,
        od2007_dxf	= odR21_dxf,
        od2007_Template	= odR21_Template,
        odR24_dwg	= 48,
        odR24_dxf	= 49,
        odR24_Template	= 50,
        od2010_dwg	= odR24_dwg,
        od2010_dxf	= odR24_dxf,
        od2010_Template	= odR24_Template,
        odR27_dwg	= 60,
        odR27_dxf	= 61,
        odR27_Template	= 62,
        od2013_dwg	= odR27_dwg,
        od2013_dxf	= odR27_dxf,
        od2013_Template	= odR27_Template,
        odR32_dwg	= 64,
        odR32_dxf	= 65,
        odR32_Template	= 66,
        od2018_dwg	= odR32_dwg,
        od2018_dxf	= odR32_dxf,
        od2018_Template	= odR32_Template,
        odNative	= od2018_dwg
    } 	OdSaveAsType;

typedef /* [uuid] */  DECLSPEC_UUID("65B5221E-245C-4a96-AC00-F7AFFB6D5484") 
enum AcadSecurityParamsType
    {
        ACADSECURITYPARAMS_ENCRYPT_DATA	= 1,
        ACADSECURITYPARAMS_ENCRYPT_PROPS	= 2,
        ACADSECURITYPARAMS_SIGN_DATA	= 16,
        ACADSECURITYPARAMS_ADD_TIMESTAMP	= 32
    } 	AcadSecurityParamsType;

typedef /* [uuid] */  DECLSPEC_UUID("92EF3441-50E5-4c86-A420-5352EA414E63") 
enum AcadSecurityParamsConstants
    {
        ACADSECURITYPARAMS_ALGID_RC4	= 26625
    } 	AcadSecurityParamsConstants;

typedef /* [uuid] */  DECLSPEC_UUID("ED7ECBBB-07B9-473a-A7AE-105C2E85EFAC") 
enum PdfExportLayerSettingType
    {
        PDFEXPORT_NOLAYER	= 0,
        PDFEXPORT_EXCLUDE_OFFLAYER	= 1,
        PDFEXPORT_INCLUDE_OFFLAYER	= 2
    } 	PdfExportLayerSettingType;

typedef /* [uuid] */  DECLSPEC_UUID("122564DF-C0DD-42bf-9D66-E03BB3487AA0") 
enum PdfExportLayoutSettingType
    {
        PDFEXPORT_LAYOUTS_ACTIVE	= 0,
        PDFEXPORT_LAYOUTS_ALL	= 1
    } 	PdfExportLayoutSettingType;

typedef /* [public][uuid] */  DECLSPEC_UUID("F7C088E7-7CA3-4AD2-BCC4-B6F4DFD59B55") 
enum OdDwfFormat
    {
        odDwfCompressedBinary	= 0,
        odDwfUncompressedBinary	= 1,
        odDwfAscii	= 2
    } 	OdDwfFormat;

typedef /* [public][uuid] */  DECLSPEC_UUID("08A7608E-3AE1-412C-9FF6-6C93EBE9C4C2") 
enum OdDwfVersion
    {
        odDwf_v55	= 55,
        odDwf_v42	= 42,
        odDwf_v60	= 600
    } 	OdDwfVersion;

typedef /* [uuid] */  DECLSPEC_UUID("059B8E04-CBFB-4b23-944A-D299ACA97440") 
enum AcLayerStateMask
    {
        acLsNone	= 0,
        acLsOn	= 1,
        acLsFrozen	= 2,
        acLsLocked	= 4,
        acLsPlot	= 8,
        acLsNewViewport	= 16,
        acLsColor	= 32,
        acLsLineType	= 64,
        acLsLineWeight	= 128,
        acLsPlotStyle	= 256,
        acLsAll	= 65535
    } 	AcLayerStateMask;


EXTERN_C const IID LIBID_BricscadApp;

#ifndef __ITransmittalOperation_INTERFACE_DEFINED__
#define __ITransmittalOperation_INTERFACE_DEFINED__

/* interface ITransmittalOperation */
/* [object][oleautomation][dual][helpstring][uuid] */ 


EXTERN_C const IID IID_ITransmittalOperation;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7EFB484A-0280-4ed6-A73F-6DBE663DB79D")
    ITransmittalOperation : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE addFile( 
            /* [in] */ BSTR bstrFullPath,
            /* [in] */ ITransmittalFile *pIParentFile,
            /* [in] */ long bAddedBy3rdParty,
            /* [out] */ ITransmittalFile **ppIAddedFile,
            /* [retval][out] */ AddFileReturnVal *pRetVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE addToReport( 
            /* [in] */ BSTR bstrTextToAdd,
            /* [in] */ long nIndex,
            /* [retval][out] */ long *pnIndex) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE addDrawingFile( 
            /* [in] */ BSTR fullpathname,
            /* [out] */ ITransmittalFile **ppIAddedFile,
            /* [retval][out] */ AddFileReturnVal *pRetVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE createTransmittalPackage( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE getTransmittalReport( 
            /* [retval][out] */ BSTR *bstrReport) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE getTransmittalInfoInterface( 
            /* [retval][out] */ ITransmittalInfo **ppIInfo) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE getTransmittalGraphInterface( 
            /* [retval][out] */ ITransmittalFilesGraph **ppIGraph) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ITransmittalOperationVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITransmittalOperation * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ITransmittalOperation * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ITransmittalOperation * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ITransmittalOperation * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ITransmittalOperation * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ITransmittalOperation * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ITransmittalOperation * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *addFile )( 
            ITransmittalOperation * This,
            /* [in] */ BSTR bstrFullPath,
            /* [in] */ ITransmittalFile *pIParentFile,
            /* [in] */ long bAddedBy3rdParty,
            /* [out] */ ITransmittalFile **ppIAddedFile,
            /* [retval][out] */ AddFileReturnVal *pRetVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *addToReport )( 
            ITransmittalOperation * This,
            /* [in] */ BSTR bstrTextToAdd,
            /* [in] */ long nIndex,
            /* [retval][out] */ long *pnIndex);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *addDrawingFile )( 
            ITransmittalOperation * This,
            /* [in] */ BSTR fullpathname,
            /* [out] */ ITransmittalFile **ppIAddedFile,
            /* [retval][out] */ AddFileReturnVal *pRetVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *createTransmittalPackage )( 
            ITransmittalOperation * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *getTransmittalReport )( 
            ITransmittalOperation * This,
            /* [retval][out] */ BSTR *bstrReport);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *getTransmittalInfoInterface )( 
            ITransmittalOperation * This,
            /* [retval][out] */ ITransmittalInfo **ppIInfo);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *getTransmittalGraphInterface )( 
            ITransmittalOperation * This,
            /* [retval][out] */ ITransmittalFilesGraph **ppIGraph);
        
        END_INTERFACE
    } ITransmittalOperationVtbl;

    interface ITransmittalOperation
    {
        CONST_VTBL struct ITransmittalOperationVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITransmittalOperation_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITransmittalOperation_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITransmittalOperation_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITransmittalOperation_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ITransmittalOperation_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ITransmittalOperation_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ITransmittalOperation_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ITransmittalOperation_addFile(This,bstrFullPath,pIParentFile,bAddedBy3rdParty,ppIAddedFile,pRetVal)	\
    ( (This)->lpVtbl -> addFile(This,bstrFullPath,pIParentFile,bAddedBy3rdParty,ppIAddedFile,pRetVal) ) 

#define ITransmittalOperation_addToReport(This,bstrTextToAdd,nIndex,pnIndex)	\
    ( (This)->lpVtbl -> addToReport(This,bstrTextToAdd,nIndex,pnIndex) ) 

#define ITransmittalOperation_addDrawingFile(This,fullpathname,ppIAddedFile,pRetVal)	\
    ( (This)->lpVtbl -> addDrawingFile(This,fullpathname,ppIAddedFile,pRetVal) ) 

#define ITransmittalOperation_createTransmittalPackage(This)	\
    ( (This)->lpVtbl -> createTransmittalPackage(This) ) 

#define ITransmittalOperation_getTransmittalReport(This,bstrReport)	\
    ( (This)->lpVtbl -> getTransmittalReport(This,bstrReport) ) 

#define ITransmittalOperation_getTransmittalInfoInterface(This,ppIInfo)	\
    ( (This)->lpVtbl -> getTransmittalInfoInterface(This,ppIInfo) ) 

#define ITransmittalOperation_getTransmittalGraphInterface(This,ppIGraph)	\
    ( (This)->lpVtbl -> getTransmittalGraphInterface(This,ppIGraph) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITransmittalOperation_INTERFACE_DEFINED__ */


#ifndef __ITransmittalFilesGraph_INTERFACE_DEFINED__
#define __ITransmittalFilesGraph_INTERFACE_DEFINED__

/* interface ITransmittalFilesGraph */
/* [object][oleautomation][dual][helpstring][uuid] */ 


EXTERN_C const IID IID_ITransmittalFilesGraph;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DE88EA7C-176A-42c7-BF1A-CFCCDEAB3EDB")
    ITransmittalFilesGraph : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE getRoot( 
            /* [retval][out] */ ITransmittalFile **ppFile) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE addEdge( 
            /* [in] */ ITransmittalFile *pTransmitFileFrom,
            /* [in] */ ITransmittalFile *pTransmitFileTo) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE removeEdge( 
            /* [in] */ ITransmittalFile *pTransmitFile,
            /* [in] */ ITransmittalFile *pParentFile) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE getNumberOfFiles( 
            /* [in] */ long bIncludeMissingFiles,
            /* [in] */ long bIncludeUnselectedFiles,
            /* [retval][out] */ int *pnSize) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE getAt( 
            /* [in] */ int nIndex,
            /* [retval][out] */ ITransmittalFile **ppFile) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE reset( void) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_totalBytes( 
            /* [in] */ long bIncludedFilesOnly,
            /* [retval][out] */ long *pVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ITransmittalFilesGraphVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITransmittalFilesGraph * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ITransmittalFilesGraph * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ITransmittalFilesGraph * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ITransmittalFilesGraph * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ITransmittalFilesGraph * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ITransmittalFilesGraph * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ITransmittalFilesGraph * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *getRoot )( 
            ITransmittalFilesGraph * This,
            /* [retval][out] */ ITransmittalFile **ppFile);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *addEdge )( 
            ITransmittalFilesGraph * This,
            /* [in] */ ITransmittalFile *pTransmitFileFrom,
            /* [in] */ ITransmittalFile *pTransmitFileTo);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *removeEdge )( 
            ITransmittalFilesGraph * This,
            /* [in] */ ITransmittalFile *pTransmitFile,
            /* [in] */ ITransmittalFile *pParentFile);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *getNumberOfFiles )( 
            ITransmittalFilesGraph * This,
            /* [in] */ long bIncludeMissingFiles,
            /* [in] */ long bIncludeUnselectedFiles,
            /* [retval][out] */ int *pnSize);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *getAt )( 
            ITransmittalFilesGraph * This,
            /* [in] */ int nIndex,
            /* [retval][out] */ ITransmittalFile **ppFile);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *reset )( 
            ITransmittalFilesGraph * This);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_totalBytes )( 
            ITransmittalFilesGraph * This,
            /* [in] */ long bIncludedFilesOnly,
            /* [retval][out] */ long *pVal);
        
        END_INTERFACE
    } ITransmittalFilesGraphVtbl;

    interface ITransmittalFilesGraph
    {
        CONST_VTBL struct ITransmittalFilesGraphVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITransmittalFilesGraph_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITransmittalFilesGraph_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITransmittalFilesGraph_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITransmittalFilesGraph_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ITransmittalFilesGraph_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ITransmittalFilesGraph_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ITransmittalFilesGraph_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ITransmittalFilesGraph_getRoot(This,ppFile)	\
    ( (This)->lpVtbl -> getRoot(This,ppFile) ) 

#define ITransmittalFilesGraph_addEdge(This,pTransmitFileFrom,pTransmitFileTo)	\
    ( (This)->lpVtbl -> addEdge(This,pTransmitFileFrom,pTransmitFileTo) ) 

#define ITransmittalFilesGraph_removeEdge(This,pTransmitFile,pParentFile)	\
    ( (This)->lpVtbl -> removeEdge(This,pTransmitFile,pParentFile) ) 

#define ITransmittalFilesGraph_getNumberOfFiles(This,bIncludeMissingFiles,bIncludeUnselectedFiles,pnSize)	\
    ( (This)->lpVtbl -> getNumberOfFiles(This,bIncludeMissingFiles,bIncludeUnselectedFiles,pnSize) ) 

#define ITransmittalFilesGraph_getAt(This,nIndex,ppFile)	\
    ( (This)->lpVtbl -> getAt(This,nIndex,ppFile) ) 

#define ITransmittalFilesGraph_reset(This)	\
    ( (This)->lpVtbl -> reset(This) ) 

#define ITransmittalFilesGraph_get_totalBytes(This,bIncludedFilesOnly,pVal)	\
    ( (This)->lpVtbl -> get_totalBytes(This,bIncludedFilesOnly,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITransmittalFilesGraph_INTERFACE_DEFINED__ */


#ifndef __ITransmittalFile_INTERFACE_DEFINED__
#define __ITransmittalFile_INTERFACE_DEFINED__

/* interface ITransmittalFile */
/* [object][oleautomation][dual][helpstring][uuid] */ 


EXTERN_C const IID IID_ITransmittalFile;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0A107B59-34CE-4f40-9AF2-26060A3C2099")
    ITransmittalFile : public IDispatch
    {
    public:
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_sourcePath( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_fileExists( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_version( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_fileSize( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_lastModifiedTime( 
            /* [retval][out] */ DATE *pVal) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_FileType( 
            /* [retval][out] */ FileType *pVal) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_includeInTransmittal( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_includeInTransmittal( 
            /* [in] */ long pVal) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_numberOfDependents( 
            /* [retval][out] */ int *pVal) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_numberOfDependees( 
            /* [retval][out] */ int *pVal) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_database( 
            /* [retval][out] */ IDispatch **ppDatabase) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE getDependent( 
            /* [in] */ int nIndex,
            /* [retval][out] */ ITransmittalFile **ppFile) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE getDependee( 
            /* [in] */ int nIndex,
            /* [retval][out] */ ITransmittalFile **ppFile) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ITransmittalFileVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITransmittalFile * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ITransmittalFile * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ITransmittalFile * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ITransmittalFile * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ITransmittalFile * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ITransmittalFile * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ITransmittalFile * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_sourcePath )( 
            ITransmittalFile * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_fileExists )( 
            ITransmittalFile * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_version )( 
            ITransmittalFile * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_fileSize )( 
            ITransmittalFile * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_lastModifiedTime )( 
            ITransmittalFile * This,
            /* [retval][out] */ DATE *pVal);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_FileType )( 
            ITransmittalFile * This,
            /* [retval][out] */ FileType *pVal);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_includeInTransmittal )( 
            ITransmittalFile * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_includeInTransmittal )( 
            ITransmittalFile * This,
            /* [in] */ long pVal);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_numberOfDependents )( 
            ITransmittalFile * This,
            /* [retval][out] */ int *pVal);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_numberOfDependees )( 
            ITransmittalFile * This,
            /* [retval][out] */ int *pVal);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_database )( 
            ITransmittalFile * This,
            /* [retval][out] */ IDispatch **ppDatabase);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *getDependent )( 
            ITransmittalFile * This,
            /* [in] */ int nIndex,
            /* [retval][out] */ ITransmittalFile **ppFile);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *getDependee )( 
            ITransmittalFile * This,
            /* [in] */ int nIndex,
            /* [retval][out] */ ITransmittalFile **ppFile);
        
        END_INTERFACE
    } ITransmittalFileVtbl;

    interface ITransmittalFile
    {
        CONST_VTBL struct ITransmittalFileVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITransmittalFile_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITransmittalFile_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITransmittalFile_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITransmittalFile_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ITransmittalFile_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ITransmittalFile_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ITransmittalFile_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ITransmittalFile_get_sourcePath(This,pVal)	\
    ( (This)->lpVtbl -> get_sourcePath(This,pVal) ) 

#define ITransmittalFile_get_fileExists(This,pVal)	\
    ( (This)->lpVtbl -> get_fileExists(This,pVal) ) 

#define ITransmittalFile_get_version(This,pVal)	\
    ( (This)->lpVtbl -> get_version(This,pVal) ) 

#define ITransmittalFile_get_fileSize(This,pVal)	\
    ( (This)->lpVtbl -> get_fileSize(This,pVal) ) 

#define ITransmittalFile_get_lastModifiedTime(This,pVal)	\
    ( (This)->lpVtbl -> get_lastModifiedTime(This,pVal) ) 

#define ITransmittalFile_get_FileType(This,pVal)	\
    ( (This)->lpVtbl -> get_FileType(This,pVal) ) 

#define ITransmittalFile_get_includeInTransmittal(This,pVal)	\
    ( (This)->lpVtbl -> get_includeInTransmittal(This,pVal) ) 

#define ITransmittalFile_put_includeInTransmittal(This,pVal)	\
    ( (This)->lpVtbl -> put_includeInTransmittal(This,pVal) ) 

#define ITransmittalFile_get_numberOfDependents(This,pVal)	\
    ( (This)->lpVtbl -> get_numberOfDependents(This,pVal) ) 

#define ITransmittalFile_get_numberOfDependees(This,pVal)	\
    ( (This)->lpVtbl -> get_numberOfDependees(This,pVal) ) 

#define ITransmittalFile_get_database(This,ppDatabase)	\
    ( (This)->lpVtbl -> get_database(This,ppDatabase) ) 

#define ITransmittalFile_getDependent(This,nIndex,ppFile)	\
    ( (This)->lpVtbl -> getDependent(This,nIndex,ppFile) ) 

#define ITransmittalFile_getDependee(This,nIndex,ppFile)	\
    ( (This)->lpVtbl -> getDependee(This,nIndex,ppFile) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITransmittalFile_INTERFACE_DEFINED__ */


#ifndef __ITransmittalInfo_INTERFACE_DEFINED__
#define __ITransmittalInfo_INTERFACE_DEFINED__

/* interface ITransmittalInfo */
/* [object][oleautomation][dual][helpstring][uuid] */ 


EXTERN_C const IID IID_ITransmittalInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("122D84E7-A507-414c-A517-C33B19AF6BA5")
    ITransmittalInfo : public IDispatch
    {
    public:
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_destinationRoot( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_destinationRoot( 
            /* [in] */ BSTR pVal) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_saveVersion( 
            /* [retval][out] */ SaveDwgFormat *pVal) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_saveVersion( 
            /* [in] */ SaveDwgFormat pVal) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_preserveSubdirs( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_preserveSubdirs( 
            /* [in] */ long pVal) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_defaultOverwriteValue( 
            /* [retval][out] */ OverwriteResponseType *pVal) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_defaultOverwriteValue( 
            /* [in] */ OverwriteResponseType pVal) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_xrefRelativePath( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_xrefRelativePath( 
            /* [in] */ long pVal) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_imageRelativePath( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_imageRelativePath( 
            /* [in] */ long pVal) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_includeXrefDwg( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_includeXrefDwg( 
            /* [in] */ long pVal) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_includeImageFile( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_includeImageFile( 
            /* [in] */ long pVal) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_includeFontFile( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_includeFontFile( 
            /* [in] */ long pVal) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_includePlotFile( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_includePlotFile( 
            /* [in] */ long pVal) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_relativePath( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_relativePath( 
            /* [in] */ BSTR pVal) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_organizedFolder( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_organizedFolder( 
            /* [in] */ long pVal) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_includeMaterialTextureFile( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_includeMaterialTextureFile( 
            /* [in] */ long pVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ITransmittalInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITransmittalInfo * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ITransmittalInfo * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ITransmittalInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ITransmittalInfo * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ITransmittalInfo * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ITransmittalInfo * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ITransmittalInfo * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_destinationRoot )( 
            ITransmittalInfo * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_destinationRoot )( 
            ITransmittalInfo * This,
            /* [in] */ BSTR pVal);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_saveVersion )( 
            ITransmittalInfo * This,
            /* [retval][out] */ SaveDwgFormat *pVal);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_saveVersion )( 
            ITransmittalInfo * This,
            /* [in] */ SaveDwgFormat pVal);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_preserveSubdirs )( 
            ITransmittalInfo * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_preserveSubdirs )( 
            ITransmittalInfo * This,
            /* [in] */ long pVal);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_defaultOverwriteValue )( 
            ITransmittalInfo * This,
            /* [retval][out] */ OverwriteResponseType *pVal);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_defaultOverwriteValue )( 
            ITransmittalInfo * This,
            /* [in] */ OverwriteResponseType pVal);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_xrefRelativePath )( 
            ITransmittalInfo * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_xrefRelativePath )( 
            ITransmittalInfo * This,
            /* [in] */ long pVal);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_imageRelativePath )( 
            ITransmittalInfo * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_imageRelativePath )( 
            ITransmittalInfo * This,
            /* [in] */ long pVal);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_includeXrefDwg )( 
            ITransmittalInfo * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_includeXrefDwg )( 
            ITransmittalInfo * This,
            /* [in] */ long pVal);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_includeImageFile )( 
            ITransmittalInfo * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_includeImageFile )( 
            ITransmittalInfo * This,
            /* [in] */ long pVal);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_includeFontFile )( 
            ITransmittalInfo * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_includeFontFile )( 
            ITransmittalInfo * This,
            /* [in] */ long pVal);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_includePlotFile )( 
            ITransmittalInfo * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_includePlotFile )( 
            ITransmittalInfo * This,
            /* [in] */ long pVal);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_relativePath )( 
            ITransmittalInfo * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_relativePath )( 
            ITransmittalInfo * This,
            /* [in] */ BSTR pVal);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_organizedFolder )( 
            ITransmittalInfo * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_organizedFolder )( 
            ITransmittalInfo * This,
            /* [in] */ long pVal);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_includeMaterialTextureFile )( 
            ITransmittalInfo * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_includeMaterialTextureFile )( 
            ITransmittalInfo * This,
            /* [in] */ long pVal);
        
        END_INTERFACE
    } ITransmittalInfoVtbl;

    interface ITransmittalInfo
    {
        CONST_VTBL struct ITransmittalInfoVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITransmittalInfo_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITransmittalInfo_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITransmittalInfo_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITransmittalInfo_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ITransmittalInfo_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ITransmittalInfo_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ITransmittalInfo_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ITransmittalInfo_get_destinationRoot(This,pVal)	\
    ( (This)->lpVtbl -> get_destinationRoot(This,pVal) ) 

#define ITransmittalInfo_put_destinationRoot(This,pVal)	\
    ( (This)->lpVtbl -> put_destinationRoot(This,pVal) ) 

#define ITransmittalInfo_get_saveVersion(This,pVal)	\
    ( (This)->lpVtbl -> get_saveVersion(This,pVal) ) 

#define ITransmittalInfo_put_saveVersion(This,pVal)	\
    ( (This)->lpVtbl -> put_saveVersion(This,pVal) ) 

#define ITransmittalInfo_get_preserveSubdirs(This,pVal)	\
    ( (This)->lpVtbl -> get_preserveSubdirs(This,pVal) ) 

#define ITransmittalInfo_put_preserveSubdirs(This,pVal)	\
    ( (This)->lpVtbl -> put_preserveSubdirs(This,pVal) ) 

#define ITransmittalInfo_get_defaultOverwriteValue(This,pVal)	\
    ( (This)->lpVtbl -> get_defaultOverwriteValue(This,pVal) ) 

#define ITransmittalInfo_put_defaultOverwriteValue(This,pVal)	\
    ( (This)->lpVtbl -> put_defaultOverwriteValue(This,pVal) ) 

#define ITransmittalInfo_get_xrefRelativePath(This,pVal)	\
    ( (This)->lpVtbl -> get_xrefRelativePath(This,pVal) ) 

#define ITransmittalInfo_put_xrefRelativePath(This,pVal)	\
    ( (This)->lpVtbl -> put_xrefRelativePath(This,pVal) ) 

#define ITransmittalInfo_get_imageRelativePath(This,pVal)	\
    ( (This)->lpVtbl -> get_imageRelativePath(This,pVal) ) 

#define ITransmittalInfo_put_imageRelativePath(This,pVal)	\
    ( (This)->lpVtbl -> put_imageRelativePath(This,pVal) ) 

#define ITransmittalInfo_get_includeXrefDwg(This,pVal)	\
    ( (This)->lpVtbl -> get_includeXrefDwg(This,pVal) ) 

#define ITransmittalInfo_put_includeXrefDwg(This,pVal)	\
    ( (This)->lpVtbl -> put_includeXrefDwg(This,pVal) ) 

#define ITransmittalInfo_get_includeImageFile(This,pVal)	\
    ( (This)->lpVtbl -> get_includeImageFile(This,pVal) ) 

#define ITransmittalInfo_put_includeImageFile(This,pVal)	\
    ( (This)->lpVtbl -> put_includeImageFile(This,pVal) ) 

#define ITransmittalInfo_get_includeFontFile(This,pVal)	\
    ( (This)->lpVtbl -> get_includeFontFile(This,pVal) ) 

#define ITransmittalInfo_put_includeFontFile(This,pVal)	\
    ( (This)->lpVtbl -> put_includeFontFile(This,pVal) ) 

#define ITransmittalInfo_get_includePlotFile(This,pVal)	\
    ( (This)->lpVtbl -> get_includePlotFile(This,pVal) ) 

#define ITransmittalInfo_put_includePlotFile(This,pVal)	\
    ( (This)->lpVtbl -> put_includePlotFile(This,pVal) ) 

#define ITransmittalInfo_get_relativePath(This,pVal)	\
    ( (This)->lpVtbl -> get_relativePath(This,pVal) ) 

#define ITransmittalInfo_put_relativePath(This,pVal)	\
    ( (This)->lpVtbl -> put_relativePath(This,pVal) ) 

#define ITransmittalInfo_get_organizedFolder(This,pVal)	\
    ( (This)->lpVtbl -> get_organizedFolder(This,pVal) ) 

#define ITransmittalInfo_put_organizedFolder(This,pVal)	\
    ( (This)->lpVtbl -> put_organizedFolder(This,pVal) ) 

#define ITransmittalInfo_get_includeMaterialTextureFile(This,pVal)	\
    ( (This)->lpVtbl -> get_includeMaterialTextureFile(This,pVal) ) 

#define ITransmittalInfo_put_includeMaterialTextureFile(This,pVal)	\
    ( (This)->lpVtbl -> put_includeMaterialTextureFile(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITransmittalInfo_INTERFACE_DEFINED__ */


#ifndef __IAcadMenuGroups_INTERFACE_DEFINED__
#define __IAcadMenuGroups_INTERFACE_DEFINED__

/* interface IAcadMenuGroups */
/* [object][oleautomation][dual][helpstring][uuid] */ 


EXTERN_C const IID IID_IAcadMenuGroups;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("798225D3-984D-471e-84F3-D1EC56FA05EA")
    IAcadMenuGroups : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Item( 
            /* [in] */ VARIANT Index,
            /* [retval][out] */ IAcadMenuGroup **pItem) = 0;
        
        virtual /* [hidden][restricted][propget][id] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ IUnknown **pEnumVariant) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long *Count) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Application( 
            /* [retval][out] */ IAcadApplication **pAppObj) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Parent( 
            /* [retval][out] */ IAcadApplication **pParent) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Load( 
            /* [in] */ BSTR MenuFileName,
            /* [optional][in] */ VARIANT BaseMenu,
            /* [retval][out] */ IAcadMenuGroup **pMenuGroup) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAcadMenuGroupsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAcadMenuGroups * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAcadMenuGroups * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAcadMenuGroups * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IAcadMenuGroups * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IAcadMenuGroups * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IAcadMenuGroups * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IAcadMenuGroups * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Item )( 
            IAcadMenuGroups * This,
            /* [in] */ VARIANT Index,
            /* [retval][out] */ IAcadMenuGroup **pItem);
        
        /* [hidden][restricted][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            IAcadMenuGroups * This,
            /* [retval][out] */ IUnknown **pEnumVariant);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IAcadMenuGroups * This,
            /* [retval][out] */ long *Count);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Application )( 
            IAcadMenuGroups * This,
            /* [retval][out] */ IAcadApplication **pAppObj);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Parent )( 
            IAcadMenuGroups * This,
            /* [retval][out] */ IAcadApplication **pParent);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Load )( 
            IAcadMenuGroups * This,
            /* [in] */ BSTR MenuFileName,
            /* [optional][in] */ VARIANT BaseMenu,
            /* [retval][out] */ IAcadMenuGroup **pMenuGroup);
        
        END_INTERFACE
    } IAcadMenuGroupsVtbl;

    interface IAcadMenuGroups
    {
        CONST_VTBL struct IAcadMenuGroupsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAcadMenuGroups_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAcadMenuGroups_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAcadMenuGroups_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAcadMenuGroups_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IAcadMenuGroups_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IAcadMenuGroups_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IAcadMenuGroups_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IAcadMenuGroups_Item(This,Index,pItem)	\
    ( (This)->lpVtbl -> Item(This,Index,pItem) ) 

#define IAcadMenuGroups_get__NewEnum(This,pEnumVariant)	\
    ( (This)->lpVtbl -> get__NewEnum(This,pEnumVariant) ) 

#define IAcadMenuGroups_get_Count(This,Count)	\
    ( (This)->lpVtbl -> get_Count(This,Count) ) 

#define IAcadMenuGroups_get_Application(This,pAppObj)	\
    ( (This)->lpVtbl -> get_Application(This,pAppObj) ) 

#define IAcadMenuGroups_get_Parent(This,pParent)	\
    ( (This)->lpVtbl -> get_Parent(This,pParent) ) 

#define IAcadMenuGroups_Load(This,MenuFileName,BaseMenu,pMenuGroup)	\
    ( (This)->lpVtbl -> Load(This,MenuFileName,BaseMenu,pMenuGroup) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAcadMenuGroups_INTERFACE_DEFINED__ */


#ifndef __IAcadMenuGroup_INTERFACE_DEFINED__
#define __IAcadMenuGroup_INTERFACE_DEFINED__

/* interface IAcadMenuGroup */
/* [object][oleautomation][dual][helpstring][uuid] */ 


EXTERN_C const IID IID_IAcadMenuGroup;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DF14CB14-CDC6-463f-B71C-356149D1F935")
    IAcadMenuGroup : public IDispatch
    {
    public:
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Application( 
            /* [retval][out] */ IAcadApplication **pAppObj) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Parent( 
            /* [retval][out] */ IAcadMenuGroups **pParent) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *Name) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Type( 
            /* [retval][out] */ enum /* external definition not present */ AcMenuGroupType *menuType) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_MenuFileName( 
            /* [retval][out] */ BSTR *Name) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Menus( 
            /* [retval][out] */ IAcadPopupMenus **pMenus) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Toolbars( 
            /* [retval][out] */ IAcadToolbars **pToolbars) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Unload( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Save( 
            /* [in] */ enum /* external definition not present */ AcMenuFileType MenuFileType) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SaveAs( 
            /* [in] */ BSTR MenuFileName,
            /* [in] */ enum /* external definition not present */ AcMenuFileType MenuFileType) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAcadMenuGroupVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAcadMenuGroup * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAcadMenuGroup * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAcadMenuGroup * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IAcadMenuGroup * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IAcadMenuGroup * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IAcadMenuGroup * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IAcadMenuGroup * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Application )( 
            IAcadMenuGroup * This,
            /* [retval][out] */ IAcadApplication **pAppObj);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Parent )( 
            IAcadMenuGroup * This,
            /* [retval][out] */ IAcadMenuGroups **pParent);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IAcadMenuGroup * This,
            /* [retval][out] */ BSTR *Name);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Type )( 
            IAcadMenuGroup * This,
            /* [retval][out] */ enum /* external definition not present */ AcMenuGroupType *menuType);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_MenuFileName )( 
            IAcadMenuGroup * This,
            /* [retval][out] */ BSTR *Name);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Menus )( 
            IAcadMenuGroup * This,
            /* [retval][out] */ IAcadPopupMenus **pMenus);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Toolbars )( 
            IAcadMenuGroup * This,
            /* [retval][out] */ IAcadToolbars **pToolbars);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Unload )( 
            IAcadMenuGroup * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Save )( 
            IAcadMenuGroup * This,
            /* [in] */ enum /* external definition not present */ AcMenuFileType MenuFileType);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SaveAs )( 
            IAcadMenuGroup * This,
            /* [in] */ BSTR MenuFileName,
            /* [in] */ enum /* external definition not present */ AcMenuFileType MenuFileType);
        
        END_INTERFACE
    } IAcadMenuGroupVtbl;

    interface IAcadMenuGroup
    {
        CONST_VTBL struct IAcadMenuGroupVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAcadMenuGroup_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAcadMenuGroup_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAcadMenuGroup_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAcadMenuGroup_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IAcadMenuGroup_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IAcadMenuGroup_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IAcadMenuGroup_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IAcadMenuGroup_get_Application(This,pAppObj)	\
    ( (This)->lpVtbl -> get_Application(This,pAppObj) ) 

#define IAcadMenuGroup_get_Parent(This,pParent)	\
    ( (This)->lpVtbl -> get_Parent(This,pParent) ) 

#define IAcadMenuGroup_get_Name(This,Name)	\
    ( (This)->lpVtbl -> get_Name(This,Name) ) 

#define IAcadMenuGroup_get_Type(This,menuType)	\
    ( (This)->lpVtbl -> get_Type(This,menuType) ) 

#define IAcadMenuGroup_get_MenuFileName(This,Name)	\
    ( (This)->lpVtbl -> get_MenuFileName(This,Name) ) 

#define IAcadMenuGroup_get_Menus(This,pMenus)	\
    ( (This)->lpVtbl -> get_Menus(This,pMenus) ) 

#define IAcadMenuGroup_get_Toolbars(This,pToolbars)	\
    ( (This)->lpVtbl -> get_Toolbars(This,pToolbars) ) 

#define IAcadMenuGroup_Unload(This)	\
    ( (This)->lpVtbl -> Unload(This) ) 

#define IAcadMenuGroup_Save(This,MenuFileType)	\
    ( (This)->lpVtbl -> Save(This,MenuFileType) ) 

#define IAcadMenuGroup_SaveAs(This,MenuFileName,MenuFileType)	\
    ( (This)->lpVtbl -> SaveAs(This,MenuFileName,MenuFileType) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAcadMenuGroup_INTERFACE_DEFINED__ */


#ifndef __IAcadPopupMenus_INTERFACE_DEFINED__
#define __IAcadPopupMenus_INTERFACE_DEFINED__

/* interface IAcadPopupMenus */
/* [object][oleautomation][dual][helpstring][uuid] */ 


EXTERN_C const IID IID_IAcadPopupMenus;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3305CB53-F955-41f3-A47B-B7AA53B22D48")
    IAcadPopupMenus : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Item( 
            /* [in] */ VARIANT Index,
            /* [retval][out] */ IAcadPopupMenu **pItem) = 0;
        
        virtual /* [hidden][restricted][propget][id] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ IUnknown **pEnumVariant) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long *Count) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Application( 
            /* [retval][out] */ IAcadApplication **pAppObj) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Parent( 
            /* [retval][out] */ IAcadMenuGroup **pParent) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [in] */ BSTR MenuName,
            /* [retval][out] */ IAcadPopupMenu **pMenu) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE InsertMenuInMenuBar( 
            /* [in] */ BSTR MenuName,
            /* [in] */ VARIANT Index) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RemoveMenuFromMenuBar( 
            /* [in] */ VARIANT Index) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAcadPopupMenusVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAcadPopupMenus * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAcadPopupMenus * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAcadPopupMenus * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IAcadPopupMenus * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IAcadPopupMenus * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IAcadPopupMenus * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IAcadPopupMenus * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Item )( 
            IAcadPopupMenus * This,
            /* [in] */ VARIANT Index,
            /* [retval][out] */ IAcadPopupMenu **pItem);
        
        /* [hidden][restricted][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            IAcadPopupMenus * This,
            /* [retval][out] */ IUnknown **pEnumVariant);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IAcadPopupMenus * This,
            /* [retval][out] */ long *Count);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Application )( 
            IAcadPopupMenus * This,
            /* [retval][out] */ IAcadApplication **pAppObj);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Parent )( 
            IAcadPopupMenus * This,
            /* [retval][out] */ IAcadMenuGroup **pParent);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Add )( 
            IAcadPopupMenus * This,
            /* [in] */ BSTR MenuName,
            /* [retval][out] */ IAcadPopupMenu **pMenu);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *InsertMenuInMenuBar )( 
            IAcadPopupMenus * This,
            /* [in] */ BSTR MenuName,
            /* [in] */ VARIANT Index);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RemoveMenuFromMenuBar )( 
            IAcadPopupMenus * This,
            /* [in] */ VARIANT Index);
        
        END_INTERFACE
    } IAcadPopupMenusVtbl;

    interface IAcadPopupMenus
    {
        CONST_VTBL struct IAcadPopupMenusVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAcadPopupMenus_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAcadPopupMenus_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAcadPopupMenus_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAcadPopupMenus_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IAcadPopupMenus_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IAcadPopupMenus_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IAcadPopupMenus_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IAcadPopupMenus_Item(This,Index,pItem)	\
    ( (This)->lpVtbl -> Item(This,Index,pItem) ) 

#define IAcadPopupMenus_get__NewEnum(This,pEnumVariant)	\
    ( (This)->lpVtbl -> get__NewEnum(This,pEnumVariant) ) 

#define IAcadPopupMenus_get_Count(This,Count)	\
    ( (This)->lpVtbl -> get_Count(This,Count) ) 

#define IAcadPopupMenus_get_Application(This,pAppObj)	\
    ( (This)->lpVtbl -> get_Application(This,pAppObj) ) 

#define IAcadPopupMenus_get_Parent(This,pParent)	\
    ( (This)->lpVtbl -> get_Parent(This,pParent) ) 

#define IAcadPopupMenus_Add(This,MenuName,pMenu)	\
    ( (This)->lpVtbl -> Add(This,MenuName,pMenu) ) 

#define IAcadPopupMenus_InsertMenuInMenuBar(This,MenuName,Index)	\
    ( (This)->lpVtbl -> InsertMenuInMenuBar(This,MenuName,Index) ) 

#define IAcadPopupMenus_RemoveMenuFromMenuBar(This,Index)	\
    ( (This)->lpVtbl -> RemoveMenuFromMenuBar(This,Index) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAcadPopupMenus_INTERFACE_DEFINED__ */


#ifndef __IAcadPopupMenu_INTERFACE_DEFINED__
#define __IAcadPopupMenu_INTERFACE_DEFINED__

/* interface IAcadPopupMenu */
/* [object][oleautomation][dual][helpstring][uuid] */ 


EXTERN_C const IID IID_IAcadPopupMenu;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E63FD651-4B1B-40be-B7FA-CBAE74D97FE5")
    IAcadPopupMenu : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Item( 
            /* [in] */ VARIANT Index,
            /* [retval][out] */ IAcadPopupMenuItem **pItem) = 0;
        
        virtual /* [hidden][restricted][propget][id] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ IUnknown **pEnumVariant) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long *Count) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Application( 
            /* [retval][out] */ IAcadApplication **pAppObj) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Parent( 
            /* [retval][out] */ IDispatch **pParent) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *bstrName) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Name( 
            /* [in] */ BSTR bstrName) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_NameNoMnemonic( 
            /* [retval][out] */ BSTR *bstrName) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ShortcutMenu( 
            /* [retval][out] */ VARIANT_BOOL *bFlag) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_OnMenuBar( 
            /* [retval][out] */ VARIANT_BOOL *bFlag) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddMenuItem( 
            /* [in] */ VARIANT Index,
            /* [in] */ BSTR Label,
            /* [in] */ BSTR Macro,
            /* [retval][out] */ IAcadPopupMenuItem **pItem) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddSubMenu( 
            /* [in] */ VARIANT Index,
            /* [in] */ BSTR Label,
            /* [retval][out] */ IAcadPopupMenu **pMenu) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddSeparator( 
            /* [in] */ VARIANT Index,
            /* [retval][out] */ IAcadPopupMenuItem **pItem) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE InsertInMenuBar( 
            /* [in] */ VARIANT Index) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RemoveFromMenuBar( void) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_TagString( 
            /* [retval][out] */ BSTR *bstrTag) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAcadPopupMenuVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAcadPopupMenu * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAcadPopupMenu * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAcadPopupMenu * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IAcadPopupMenu * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IAcadPopupMenu * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IAcadPopupMenu * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IAcadPopupMenu * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Item )( 
            IAcadPopupMenu * This,
            /* [in] */ VARIANT Index,
            /* [retval][out] */ IAcadPopupMenuItem **pItem);
        
        /* [hidden][restricted][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            IAcadPopupMenu * This,
            /* [retval][out] */ IUnknown **pEnumVariant);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IAcadPopupMenu * This,
            /* [retval][out] */ long *Count);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Application )( 
            IAcadPopupMenu * This,
            /* [retval][out] */ IAcadApplication **pAppObj);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Parent )( 
            IAcadPopupMenu * This,
            /* [retval][out] */ IDispatch **pParent);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IAcadPopupMenu * This,
            /* [retval][out] */ BSTR *bstrName);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Name )( 
            IAcadPopupMenu * This,
            /* [in] */ BSTR bstrName);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_NameNoMnemonic )( 
            IAcadPopupMenu * This,
            /* [retval][out] */ BSTR *bstrName);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ShortcutMenu )( 
            IAcadPopupMenu * This,
            /* [retval][out] */ VARIANT_BOOL *bFlag);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_OnMenuBar )( 
            IAcadPopupMenu * This,
            /* [retval][out] */ VARIANT_BOOL *bFlag);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddMenuItem )( 
            IAcadPopupMenu * This,
            /* [in] */ VARIANT Index,
            /* [in] */ BSTR Label,
            /* [in] */ BSTR Macro,
            /* [retval][out] */ IAcadPopupMenuItem **pItem);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddSubMenu )( 
            IAcadPopupMenu * This,
            /* [in] */ VARIANT Index,
            /* [in] */ BSTR Label,
            /* [retval][out] */ IAcadPopupMenu **pMenu);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddSeparator )( 
            IAcadPopupMenu * This,
            /* [in] */ VARIANT Index,
            /* [retval][out] */ IAcadPopupMenuItem **pItem);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *InsertInMenuBar )( 
            IAcadPopupMenu * This,
            /* [in] */ VARIANT Index);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RemoveFromMenuBar )( 
            IAcadPopupMenu * This);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_TagString )( 
            IAcadPopupMenu * This,
            /* [retval][out] */ BSTR *bstrTag);
        
        END_INTERFACE
    } IAcadPopupMenuVtbl;

    interface IAcadPopupMenu
    {
        CONST_VTBL struct IAcadPopupMenuVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAcadPopupMenu_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAcadPopupMenu_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAcadPopupMenu_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAcadPopupMenu_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IAcadPopupMenu_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IAcadPopupMenu_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IAcadPopupMenu_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IAcadPopupMenu_Item(This,Index,pItem)	\
    ( (This)->lpVtbl -> Item(This,Index,pItem) ) 

#define IAcadPopupMenu_get__NewEnum(This,pEnumVariant)	\
    ( (This)->lpVtbl -> get__NewEnum(This,pEnumVariant) ) 

#define IAcadPopupMenu_get_Count(This,Count)	\
    ( (This)->lpVtbl -> get_Count(This,Count) ) 

#define IAcadPopupMenu_get_Application(This,pAppObj)	\
    ( (This)->lpVtbl -> get_Application(This,pAppObj) ) 

#define IAcadPopupMenu_get_Parent(This,pParent)	\
    ( (This)->lpVtbl -> get_Parent(This,pParent) ) 

#define IAcadPopupMenu_get_Name(This,bstrName)	\
    ( (This)->lpVtbl -> get_Name(This,bstrName) ) 

#define IAcadPopupMenu_put_Name(This,bstrName)	\
    ( (This)->lpVtbl -> put_Name(This,bstrName) ) 

#define IAcadPopupMenu_get_NameNoMnemonic(This,bstrName)	\
    ( (This)->lpVtbl -> get_NameNoMnemonic(This,bstrName) ) 

#define IAcadPopupMenu_get_ShortcutMenu(This,bFlag)	\
    ( (This)->lpVtbl -> get_ShortcutMenu(This,bFlag) ) 

#define IAcadPopupMenu_get_OnMenuBar(This,bFlag)	\
    ( (This)->lpVtbl -> get_OnMenuBar(This,bFlag) ) 

#define IAcadPopupMenu_AddMenuItem(This,Index,Label,Macro,pItem)	\
    ( (This)->lpVtbl -> AddMenuItem(This,Index,Label,Macro,pItem) ) 

#define IAcadPopupMenu_AddSubMenu(This,Index,Label,pMenu)	\
    ( (This)->lpVtbl -> AddSubMenu(This,Index,Label,pMenu) ) 

#define IAcadPopupMenu_AddSeparator(This,Index,pItem)	\
    ( (This)->lpVtbl -> AddSeparator(This,Index,pItem) ) 

#define IAcadPopupMenu_InsertInMenuBar(This,Index)	\
    ( (This)->lpVtbl -> InsertInMenuBar(This,Index) ) 

#define IAcadPopupMenu_RemoveFromMenuBar(This)	\
    ( (This)->lpVtbl -> RemoveFromMenuBar(This) ) 

#define IAcadPopupMenu_get_TagString(This,bstrTag)	\
    ( (This)->lpVtbl -> get_TagString(This,bstrTag) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAcadPopupMenu_INTERFACE_DEFINED__ */


#ifndef __IAcadPopupMenuItem_INTERFACE_DEFINED__
#define __IAcadPopupMenuItem_INTERFACE_DEFINED__

/* interface IAcadPopupMenuItem */
/* [object][oleautomation][dual][helpstring][uuid] */ 


EXTERN_C const IID IID_IAcadPopupMenuItem;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5B5C5A15-81D2-4360-937A-4F2FA18FB266")
    IAcadPopupMenuItem : public IDispatch
    {
    public:
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Application( 
            /* [retval][out] */ IAcadApplication **pAppObj) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Parent( 
            /* [retval][out] */ IAcadPopupMenu **pParent) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Label( 
            /* [retval][out] */ BSTR *bstrLabel) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Label( 
            /* [in] */ BSTR bstrLabel) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_TagString( 
            /* [retval][out] */ BSTR *bstrTag) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_TagString( 
            /* [in] */ BSTR bstrTag) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Enable( 
            /* [retval][out] */ VARIANT_BOOL *bFlag) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Enable( 
            /* [in] */ VARIANT_BOOL bFlag) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Check( 
            /* [retval][out] */ VARIANT_BOOL *bFlag) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Check( 
            /* [in] */ VARIANT_BOOL bFlag) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Type( 
            /* [retval][out] */ enum /* external definition not present */ AcMenuItemType *itemType) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_SubMenu( 
            /* [retval][out] */ IAcadPopupMenu **pMenu) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Macro( 
            /* [retval][out] */ BSTR *bstrMacro) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Macro( 
            /* [in] */ BSTR bstrMacro) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Index( 
            /* [retval][out] */ int *nIndex) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Caption( 
            /* [retval][out] */ BSTR *bstrCaption) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_HelpString( 
            /* [retval][out] */ BSTR *bstrHelp) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_HelpString( 
            /* [in] */ BSTR bstrHelp) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Delete( void) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_EndSubMenuLevel( 
            /* [retval][out] */ int *Level) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_EndSubMenuLevel( 
            /* [in] */ int Level) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAcadPopupMenuItemVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAcadPopupMenuItem * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAcadPopupMenuItem * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAcadPopupMenuItem * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IAcadPopupMenuItem * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IAcadPopupMenuItem * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IAcadPopupMenuItem * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IAcadPopupMenuItem * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Application )( 
            IAcadPopupMenuItem * This,
            /* [retval][out] */ IAcadApplication **pAppObj);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Parent )( 
            IAcadPopupMenuItem * This,
            /* [retval][out] */ IAcadPopupMenu **pParent);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Label )( 
            IAcadPopupMenuItem * This,
            /* [retval][out] */ BSTR *bstrLabel);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Label )( 
            IAcadPopupMenuItem * This,
            /* [in] */ BSTR bstrLabel);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_TagString )( 
            IAcadPopupMenuItem * This,
            /* [retval][out] */ BSTR *bstrTag);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_TagString )( 
            IAcadPopupMenuItem * This,
            /* [in] */ BSTR bstrTag);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Enable )( 
            IAcadPopupMenuItem * This,
            /* [retval][out] */ VARIANT_BOOL *bFlag);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Enable )( 
            IAcadPopupMenuItem * This,
            /* [in] */ VARIANT_BOOL bFlag);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Check )( 
            IAcadPopupMenuItem * This,
            /* [retval][out] */ VARIANT_BOOL *bFlag);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Check )( 
            IAcadPopupMenuItem * This,
            /* [in] */ VARIANT_BOOL bFlag);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Type )( 
            IAcadPopupMenuItem * This,
            /* [retval][out] */ enum /* external definition not present */ AcMenuItemType *itemType);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_SubMenu )( 
            IAcadPopupMenuItem * This,
            /* [retval][out] */ IAcadPopupMenu **pMenu);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Macro )( 
            IAcadPopupMenuItem * This,
            /* [retval][out] */ BSTR *bstrMacro);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Macro )( 
            IAcadPopupMenuItem * This,
            /* [in] */ BSTR bstrMacro);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Index )( 
            IAcadPopupMenuItem * This,
            /* [retval][out] */ int *nIndex);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Caption )( 
            IAcadPopupMenuItem * This,
            /* [retval][out] */ BSTR *bstrCaption);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_HelpString )( 
            IAcadPopupMenuItem * This,
            /* [retval][out] */ BSTR *bstrHelp);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_HelpString )( 
            IAcadPopupMenuItem * This,
            /* [in] */ BSTR bstrHelp);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IAcadPopupMenuItem * This);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_EndSubMenuLevel )( 
            IAcadPopupMenuItem * This,
            /* [retval][out] */ int *Level);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_EndSubMenuLevel )( 
            IAcadPopupMenuItem * This,
            /* [in] */ int Level);
        
        END_INTERFACE
    } IAcadPopupMenuItemVtbl;

    interface IAcadPopupMenuItem
    {
        CONST_VTBL struct IAcadPopupMenuItemVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAcadPopupMenuItem_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAcadPopupMenuItem_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAcadPopupMenuItem_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAcadPopupMenuItem_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IAcadPopupMenuItem_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IAcadPopupMenuItem_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IAcadPopupMenuItem_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IAcadPopupMenuItem_get_Application(This,pAppObj)	\
    ( (This)->lpVtbl -> get_Application(This,pAppObj) ) 

#define IAcadPopupMenuItem_get_Parent(This,pParent)	\
    ( (This)->lpVtbl -> get_Parent(This,pParent) ) 

#define IAcadPopupMenuItem_get_Label(This,bstrLabel)	\
    ( (This)->lpVtbl -> get_Label(This,bstrLabel) ) 

#define IAcadPopupMenuItem_put_Label(This,bstrLabel)	\
    ( (This)->lpVtbl -> put_Label(This,bstrLabel) ) 

#define IAcadPopupMenuItem_get_TagString(This,bstrTag)	\
    ( (This)->lpVtbl -> get_TagString(This,bstrTag) ) 

#define IAcadPopupMenuItem_put_TagString(This,bstrTag)	\
    ( (This)->lpVtbl -> put_TagString(This,bstrTag) ) 

#define IAcadPopupMenuItem_get_Enable(This,bFlag)	\
    ( (This)->lpVtbl -> get_Enable(This,bFlag) ) 

#define IAcadPopupMenuItem_put_Enable(This,bFlag)	\
    ( (This)->lpVtbl -> put_Enable(This,bFlag) ) 

#define IAcadPopupMenuItem_get_Check(This,bFlag)	\
    ( (This)->lpVtbl -> get_Check(This,bFlag) ) 

#define IAcadPopupMenuItem_put_Check(This,bFlag)	\
    ( (This)->lpVtbl -> put_Check(This,bFlag) ) 

#define IAcadPopupMenuItem_get_Type(This,itemType)	\
    ( (This)->lpVtbl -> get_Type(This,itemType) ) 

#define IAcadPopupMenuItem_get_SubMenu(This,pMenu)	\
    ( (This)->lpVtbl -> get_SubMenu(This,pMenu) ) 

#define IAcadPopupMenuItem_get_Macro(This,bstrMacro)	\
    ( (This)->lpVtbl -> get_Macro(This,bstrMacro) ) 

#define IAcadPopupMenuItem_put_Macro(This,bstrMacro)	\
    ( (This)->lpVtbl -> put_Macro(This,bstrMacro) ) 

#define IAcadPopupMenuItem_get_Index(This,nIndex)	\
    ( (This)->lpVtbl -> get_Index(This,nIndex) ) 

#define IAcadPopupMenuItem_get_Caption(This,bstrCaption)	\
    ( (This)->lpVtbl -> get_Caption(This,bstrCaption) ) 

#define IAcadPopupMenuItem_get_HelpString(This,bstrHelp)	\
    ( (This)->lpVtbl -> get_HelpString(This,bstrHelp) ) 

#define IAcadPopupMenuItem_put_HelpString(This,bstrHelp)	\
    ( (This)->lpVtbl -> put_HelpString(This,bstrHelp) ) 

#define IAcadPopupMenuItem_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#define IAcadPopupMenuItem_get_EndSubMenuLevel(This,Level)	\
    ( (This)->lpVtbl -> get_EndSubMenuLevel(This,Level) ) 

#define IAcadPopupMenuItem_put_EndSubMenuLevel(This,Level)	\
    ( (This)->lpVtbl -> put_EndSubMenuLevel(This,Level) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAcadPopupMenuItem_INTERFACE_DEFINED__ */


#ifndef __IAcadToolbars_INTERFACE_DEFINED__
#define __IAcadToolbars_INTERFACE_DEFINED__

/* interface IAcadToolbars */
/* [object][oleautomation][dual][helpstring][uuid] */ 


EXTERN_C const IID IID_IAcadToolbars;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F7DF12AA-4EF4-4eee-8D00-68BB80D7F092")
    IAcadToolbars : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Item( 
            /* [in] */ VARIANT Index,
            /* [retval][out] */ IAcadToolbar **pItem) = 0;
        
        virtual /* [hidden][restricted][propget][id] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ IUnknown **pEnumVariant) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long *Count) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Application( 
            /* [retval][out] */ IAcadApplication **pAppObj) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Parent( 
            /* [retval][out] */ IAcadMenuGroup **pParent) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_LargeButtons( 
            /* [retval][out] */ VARIANT_BOOL *bFlag) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_LargeButtons( 
            /* [in] */ VARIANT_BOOL bFlag) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [in] */ BSTR ToolbarName,
            /* [retval][out] */ IAcadToolbar **pTlbar) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAcadToolbarsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAcadToolbars * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAcadToolbars * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAcadToolbars * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IAcadToolbars * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IAcadToolbars * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IAcadToolbars * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IAcadToolbars * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Item )( 
            IAcadToolbars * This,
            /* [in] */ VARIANT Index,
            /* [retval][out] */ IAcadToolbar **pItem);
        
        /* [hidden][restricted][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            IAcadToolbars * This,
            /* [retval][out] */ IUnknown **pEnumVariant);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IAcadToolbars * This,
            /* [retval][out] */ long *Count);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Application )( 
            IAcadToolbars * This,
            /* [retval][out] */ IAcadApplication **pAppObj);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Parent )( 
            IAcadToolbars * This,
            /* [retval][out] */ IAcadMenuGroup **pParent);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_LargeButtons )( 
            IAcadToolbars * This,
            /* [retval][out] */ VARIANT_BOOL *bFlag);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_LargeButtons )( 
            IAcadToolbars * This,
            /* [in] */ VARIANT_BOOL bFlag);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Add )( 
            IAcadToolbars * This,
            /* [in] */ BSTR ToolbarName,
            /* [retval][out] */ IAcadToolbar **pTlbar);
        
        END_INTERFACE
    } IAcadToolbarsVtbl;

    interface IAcadToolbars
    {
        CONST_VTBL struct IAcadToolbarsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAcadToolbars_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAcadToolbars_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAcadToolbars_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAcadToolbars_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IAcadToolbars_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IAcadToolbars_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IAcadToolbars_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IAcadToolbars_Item(This,Index,pItem)	\
    ( (This)->lpVtbl -> Item(This,Index,pItem) ) 

#define IAcadToolbars_get__NewEnum(This,pEnumVariant)	\
    ( (This)->lpVtbl -> get__NewEnum(This,pEnumVariant) ) 

#define IAcadToolbars_get_Count(This,Count)	\
    ( (This)->lpVtbl -> get_Count(This,Count) ) 

#define IAcadToolbars_get_Application(This,pAppObj)	\
    ( (This)->lpVtbl -> get_Application(This,pAppObj) ) 

#define IAcadToolbars_get_Parent(This,pParent)	\
    ( (This)->lpVtbl -> get_Parent(This,pParent) ) 

#define IAcadToolbars_get_LargeButtons(This,bFlag)	\
    ( (This)->lpVtbl -> get_LargeButtons(This,bFlag) ) 

#define IAcadToolbars_put_LargeButtons(This,bFlag)	\
    ( (This)->lpVtbl -> put_LargeButtons(This,bFlag) ) 

#define IAcadToolbars_Add(This,ToolbarName,pTlbar)	\
    ( (This)->lpVtbl -> Add(This,ToolbarName,pTlbar) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAcadToolbars_INTERFACE_DEFINED__ */


#ifndef __IAcadToolbar_INTERFACE_DEFINED__
#define __IAcadToolbar_INTERFACE_DEFINED__

/* interface IAcadToolbar */
/* [object][oleautomation][dual][helpstring][uuid] */ 


EXTERN_C const IID IID_IAcadToolbar;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("618F1FE3-4CF9-41d4-A070-387C8560D4EC")
    IAcadToolbar : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Item( 
            /* [in] */ VARIANT Index,
            /* [retval][out] */ IAcadToolbarItem **pItem) = 0;
        
        virtual /* [hidden][restricted][propget][id] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ IUnknown **pEnumVariant) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long *Count) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Application( 
            /* [retval][out] */ IAcadApplication **pAppObj) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Parent( 
            /* [retval][out] */ IDispatch **pParent) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *bstrName) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Name( 
            /* [in] */ BSTR bstrName) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Visible( 
            /* [retval][out] */ VARIANT_BOOL *bFlag) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Visible( 
            /* [in] */ VARIANT_BOOL bFlag) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_DockStatus( 
            /* [retval][out] */ enum /* external definition not present */ AcToolbarDockStatus *nStatus) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_LargeButtons( 
            /* [retval][out] */ VARIANT_BOOL *bFlag) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_left( 
            /* [retval][out] */ int *nLeft) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_left( 
            /* [in] */ int nLeft) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_top( 
            /* [retval][out] */ int *nTop) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_top( 
            /* [in] */ int nTop) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Width( 
            /* [retval][out] */ int *nWidth) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Height( 
            /* [retval][out] */ int *nHeight) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_FloatingRows( 
            /* [retval][out] */ int *nRows) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_FloatingRows( 
            /* [in] */ int nRows) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_HelpString( 
            /* [retval][out] */ BSTR *bstrHelp) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_HelpString( 
            /* [in] */ BSTR bstrHelp) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddToolbarButton( 
            /* [in] */ VARIANT Index,
            /* [in] */ BSTR Name,
            /* [in] */ BSTR HelpString,
            /* [in] */ BSTR Macro,
            /* [optional][in] */ VARIANT FlyoutButton,
            /* [retval][out] */ IAcadToolbarItem **pItem) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddSeparator( 
            /* [in] */ VARIANT Index,
            /* [retval][out] */ IAcadToolbarItem **pItem) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Dock( 
            /* [in] */ enum /* external definition not present */ AcToolbarDockStatus Side) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Float( 
            /* [in] */ int top,
            /* [in] */ int left,
            /* [in] */ int NumberFloatRows) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Delete( void) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_TagString( 
            /* [retval][out] */ BSTR *bstrTag) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAcadToolbarVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAcadToolbar * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAcadToolbar * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAcadToolbar * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IAcadToolbar * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IAcadToolbar * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IAcadToolbar * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IAcadToolbar * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Item )( 
            IAcadToolbar * This,
            /* [in] */ VARIANT Index,
            /* [retval][out] */ IAcadToolbarItem **pItem);
        
        /* [hidden][restricted][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            IAcadToolbar * This,
            /* [retval][out] */ IUnknown **pEnumVariant);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IAcadToolbar * This,
            /* [retval][out] */ long *Count);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Application )( 
            IAcadToolbar * This,
            /* [retval][out] */ IAcadApplication **pAppObj);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Parent )( 
            IAcadToolbar * This,
            /* [retval][out] */ IDispatch **pParent);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IAcadToolbar * This,
            /* [retval][out] */ BSTR *bstrName);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Name )( 
            IAcadToolbar * This,
            /* [in] */ BSTR bstrName);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Visible )( 
            IAcadToolbar * This,
            /* [retval][out] */ VARIANT_BOOL *bFlag);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Visible )( 
            IAcadToolbar * This,
            /* [in] */ VARIANT_BOOL bFlag);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_DockStatus )( 
            IAcadToolbar * This,
            /* [retval][out] */ enum /* external definition not present */ AcToolbarDockStatus *nStatus);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_LargeButtons )( 
            IAcadToolbar * This,
            /* [retval][out] */ VARIANT_BOOL *bFlag);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_left )( 
            IAcadToolbar * This,
            /* [retval][out] */ int *nLeft);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_left )( 
            IAcadToolbar * This,
            /* [in] */ int nLeft);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_top )( 
            IAcadToolbar * This,
            /* [retval][out] */ int *nTop);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_top )( 
            IAcadToolbar * This,
            /* [in] */ int nTop);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Width )( 
            IAcadToolbar * This,
            /* [retval][out] */ int *nWidth);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Height )( 
            IAcadToolbar * This,
            /* [retval][out] */ int *nHeight);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_FloatingRows )( 
            IAcadToolbar * This,
            /* [retval][out] */ int *nRows);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_FloatingRows )( 
            IAcadToolbar * This,
            /* [in] */ int nRows);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_HelpString )( 
            IAcadToolbar * This,
            /* [retval][out] */ BSTR *bstrHelp);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_HelpString )( 
            IAcadToolbar * This,
            /* [in] */ BSTR bstrHelp);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddToolbarButton )( 
            IAcadToolbar * This,
            /* [in] */ VARIANT Index,
            /* [in] */ BSTR Name,
            /* [in] */ BSTR HelpString,
            /* [in] */ BSTR Macro,
            /* [optional][in] */ VARIANT FlyoutButton,
            /* [retval][out] */ IAcadToolbarItem **pItem);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddSeparator )( 
            IAcadToolbar * This,
            /* [in] */ VARIANT Index,
            /* [retval][out] */ IAcadToolbarItem **pItem);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Dock )( 
            IAcadToolbar * This,
            /* [in] */ enum /* external definition not present */ AcToolbarDockStatus Side);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Float )( 
            IAcadToolbar * This,
            /* [in] */ int top,
            /* [in] */ int left,
            /* [in] */ int NumberFloatRows);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IAcadToolbar * This);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_TagString )( 
            IAcadToolbar * This,
            /* [retval][out] */ BSTR *bstrTag);
        
        END_INTERFACE
    } IAcadToolbarVtbl;

    interface IAcadToolbar
    {
        CONST_VTBL struct IAcadToolbarVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAcadToolbar_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAcadToolbar_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAcadToolbar_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAcadToolbar_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IAcadToolbar_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IAcadToolbar_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IAcadToolbar_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IAcadToolbar_Item(This,Index,pItem)	\
    ( (This)->lpVtbl -> Item(This,Index,pItem) ) 

#define IAcadToolbar_get__NewEnum(This,pEnumVariant)	\
    ( (This)->lpVtbl -> get__NewEnum(This,pEnumVariant) ) 

#define IAcadToolbar_get_Count(This,Count)	\
    ( (This)->lpVtbl -> get_Count(This,Count) ) 

#define IAcadToolbar_get_Application(This,pAppObj)	\
    ( (This)->lpVtbl -> get_Application(This,pAppObj) ) 

#define IAcadToolbar_get_Parent(This,pParent)	\
    ( (This)->lpVtbl -> get_Parent(This,pParent) ) 

#define IAcadToolbar_get_Name(This,bstrName)	\
    ( (This)->lpVtbl -> get_Name(This,bstrName) ) 

#define IAcadToolbar_put_Name(This,bstrName)	\
    ( (This)->lpVtbl -> put_Name(This,bstrName) ) 

#define IAcadToolbar_get_Visible(This,bFlag)	\
    ( (This)->lpVtbl -> get_Visible(This,bFlag) ) 

#define IAcadToolbar_put_Visible(This,bFlag)	\
    ( (This)->lpVtbl -> put_Visible(This,bFlag) ) 

#define IAcadToolbar_get_DockStatus(This,nStatus)	\
    ( (This)->lpVtbl -> get_DockStatus(This,nStatus) ) 

#define IAcadToolbar_get_LargeButtons(This,bFlag)	\
    ( (This)->lpVtbl -> get_LargeButtons(This,bFlag) ) 

#define IAcadToolbar_get_left(This,nLeft)	\
    ( (This)->lpVtbl -> get_left(This,nLeft) ) 

#define IAcadToolbar_put_left(This,nLeft)	\
    ( (This)->lpVtbl -> put_left(This,nLeft) ) 

#define IAcadToolbar_get_top(This,nTop)	\
    ( (This)->lpVtbl -> get_top(This,nTop) ) 

#define IAcadToolbar_put_top(This,nTop)	\
    ( (This)->lpVtbl -> put_top(This,nTop) ) 

#define IAcadToolbar_get_Width(This,nWidth)	\
    ( (This)->lpVtbl -> get_Width(This,nWidth) ) 

#define IAcadToolbar_get_Height(This,nHeight)	\
    ( (This)->lpVtbl -> get_Height(This,nHeight) ) 

#define IAcadToolbar_get_FloatingRows(This,nRows)	\
    ( (This)->lpVtbl -> get_FloatingRows(This,nRows) ) 

#define IAcadToolbar_put_FloatingRows(This,nRows)	\
    ( (This)->lpVtbl -> put_FloatingRows(This,nRows) ) 

#define IAcadToolbar_get_HelpString(This,bstrHelp)	\
    ( (This)->lpVtbl -> get_HelpString(This,bstrHelp) ) 

#define IAcadToolbar_put_HelpString(This,bstrHelp)	\
    ( (This)->lpVtbl -> put_HelpString(This,bstrHelp) ) 

#define IAcadToolbar_AddToolbarButton(This,Index,Name,HelpString,Macro,FlyoutButton,pItem)	\
    ( (This)->lpVtbl -> AddToolbarButton(This,Index,Name,HelpString,Macro,FlyoutButton,pItem) ) 

#define IAcadToolbar_AddSeparator(This,Index,pItem)	\
    ( (This)->lpVtbl -> AddSeparator(This,Index,pItem) ) 

#define IAcadToolbar_Dock(This,Side)	\
    ( (This)->lpVtbl -> Dock(This,Side) ) 

#define IAcadToolbar_Float(This,top,left,NumberFloatRows)	\
    ( (This)->lpVtbl -> Float(This,top,left,NumberFloatRows) ) 

#define IAcadToolbar_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#define IAcadToolbar_get_TagString(This,bstrTag)	\
    ( (This)->lpVtbl -> get_TagString(This,bstrTag) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAcadToolbar_INTERFACE_DEFINED__ */


#ifndef __IAcadToolbarItem_INTERFACE_DEFINED__
#define __IAcadToolbarItem_INTERFACE_DEFINED__

/* interface IAcadToolbarItem */
/* [object][oleautomation][dual][helpstring][uuid] */ 


EXTERN_C const IID IID_IAcadToolbarItem;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("EBCED992-0BB7-4165-B4D6-44261F377565")
    IAcadToolbarItem : public IDispatch
    {
    public:
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Application( 
            /* [retval][out] */ IAcadApplication **pAppObj) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Parent( 
            /* [retval][out] */ IAcadToolbar **pParent) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *bstrName) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Name( 
            /* [in] */ BSTR bstrName) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_TagString( 
            /* [retval][out] */ BSTR *bstrTag) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_TagString( 
            /* [in] */ BSTR bstrTag) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Type( 
            /* [retval][out] */ enum /* external definition not present */ AcToolbarItemType *itemType) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Flyout( 
            /* [retval][out] */ IAcadToolbar **pTlbar) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Macro( 
            /* [retval][out] */ BSTR *bstrMacro) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Macro( 
            /* [in] */ BSTR bstrMacro) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Index( 
            /* [retval][out] */ int *nIndex) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_HelpString( 
            /* [retval][out] */ BSTR *bstrHelp) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_HelpString( 
            /* [in] */ BSTR bstrHelp) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetBitmaps( 
            /* [out] */ BSTR *SmallIconName,
            /* [out] */ BSTR *LargeIconName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetBitmaps( 
            /* [in] */ BSTR SmallIconName,
            /* [in] */ BSTR LargeIconName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AttachToolbarToFlyout( 
            /* [in] */ BSTR MenuGroupName,
            /* [in] */ BSTR ToolbarName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Delete( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAcadToolbarItemVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAcadToolbarItem * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAcadToolbarItem * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAcadToolbarItem * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IAcadToolbarItem * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IAcadToolbarItem * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IAcadToolbarItem * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IAcadToolbarItem * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Application )( 
            IAcadToolbarItem * This,
            /* [retval][out] */ IAcadApplication **pAppObj);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Parent )( 
            IAcadToolbarItem * This,
            /* [retval][out] */ IAcadToolbar **pParent);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IAcadToolbarItem * This,
            /* [retval][out] */ BSTR *bstrName);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Name )( 
            IAcadToolbarItem * This,
            /* [in] */ BSTR bstrName);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_TagString )( 
            IAcadToolbarItem * This,
            /* [retval][out] */ BSTR *bstrTag);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_TagString )( 
            IAcadToolbarItem * This,
            /* [in] */ BSTR bstrTag);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Type )( 
            IAcadToolbarItem * This,
            /* [retval][out] */ enum /* external definition not present */ AcToolbarItemType *itemType);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Flyout )( 
            IAcadToolbarItem * This,
            /* [retval][out] */ IAcadToolbar **pTlbar);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Macro )( 
            IAcadToolbarItem * This,
            /* [retval][out] */ BSTR *bstrMacro);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Macro )( 
            IAcadToolbarItem * This,
            /* [in] */ BSTR bstrMacro);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Index )( 
            IAcadToolbarItem * This,
            /* [retval][out] */ int *nIndex);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_HelpString )( 
            IAcadToolbarItem * This,
            /* [retval][out] */ BSTR *bstrHelp);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_HelpString )( 
            IAcadToolbarItem * This,
            /* [in] */ BSTR bstrHelp);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetBitmaps )( 
            IAcadToolbarItem * This,
            /* [out] */ BSTR *SmallIconName,
            /* [out] */ BSTR *LargeIconName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetBitmaps )( 
            IAcadToolbarItem * This,
            /* [in] */ BSTR SmallIconName,
            /* [in] */ BSTR LargeIconName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AttachToolbarToFlyout )( 
            IAcadToolbarItem * This,
            /* [in] */ BSTR MenuGroupName,
            /* [in] */ BSTR ToolbarName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IAcadToolbarItem * This);
        
        END_INTERFACE
    } IAcadToolbarItemVtbl;

    interface IAcadToolbarItem
    {
        CONST_VTBL struct IAcadToolbarItemVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAcadToolbarItem_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAcadToolbarItem_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAcadToolbarItem_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAcadToolbarItem_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IAcadToolbarItem_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IAcadToolbarItem_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IAcadToolbarItem_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IAcadToolbarItem_get_Application(This,pAppObj)	\
    ( (This)->lpVtbl -> get_Application(This,pAppObj) ) 

#define IAcadToolbarItem_get_Parent(This,pParent)	\
    ( (This)->lpVtbl -> get_Parent(This,pParent) ) 

#define IAcadToolbarItem_get_Name(This,bstrName)	\
    ( (This)->lpVtbl -> get_Name(This,bstrName) ) 

#define IAcadToolbarItem_put_Name(This,bstrName)	\
    ( (This)->lpVtbl -> put_Name(This,bstrName) ) 

#define IAcadToolbarItem_get_TagString(This,bstrTag)	\
    ( (This)->lpVtbl -> get_TagString(This,bstrTag) ) 

#define IAcadToolbarItem_put_TagString(This,bstrTag)	\
    ( (This)->lpVtbl -> put_TagString(This,bstrTag) ) 

#define IAcadToolbarItem_get_Type(This,itemType)	\
    ( (This)->lpVtbl -> get_Type(This,itemType) ) 

#define IAcadToolbarItem_get_Flyout(This,pTlbar)	\
    ( (This)->lpVtbl -> get_Flyout(This,pTlbar) ) 

#define IAcadToolbarItem_get_Macro(This,bstrMacro)	\
    ( (This)->lpVtbl -> get_Macro(This,bstrMacro) ) 

#define IAcadToolbarItem_put_Macro(This,bstrMacro)	\
    ( (This)->lpVtbl -> put_Macro(This,bstrMacro) ) 

#define IAcadToolbarItem_get_Index(This,nIndex)	\
    ( (This)->lpVtbl -> get_Index(This,nIndex) ) 

#define IAcadToolbarItem_get_HelpString(This,bstrHelp)	\
    ( (This)->lpVtbl -> get_HelpString(This,bstrHelp) ) 

#define IAcadToolbarItem_put_HelpString(This,bstrHelp)	\
    ( (This)->lpVtbl -> put_HelpString(This,bstrHelp) ) 

#define IAcadToolbarItem_GetBitmaps(This,SmallIconName,LargeIconName)	\
    ( (This)->lpVtbl -> GetBitmaps(This,SmallIconName,LargeIconName) ) 

#define IAcadToolbarItem_SetBitmaps(This,SmallIconName,LargeIconName)	\
    ( (This)->lpVtbl -> SetBitmaps(This,SmallIconName,LargeIconName) ) 

#define IAcadToolbarItem_AttachToolbarToFlyout(This,MenuGroupName,ToolbarName)	\
    ( (This)->lpVtbl -> AttachToolbarToFlyout(This,MenuGroupName,ToolbarName) ) 

#define IAcadToolbarItem_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAcadToolbarItem_INTERFACE_DEFINED__ */


#ifndef __IAcadMenuBar_INTERFACE_DEFINED__
#define __IAcadMenuBar_INTERFACE_DEFINED__

/* interface IAcadMenuBar */
/* [object][oleautomation][dual][helpstring][uuid] */ 


EXTERN_C const IID IID_IAcadMenuBar;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A174CCC8-D19F-421f-8F4E-65C2E4F43167")
    IAcadMenuBar : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Item( 
            /* [in] */ VARIANT Index,
            /* [retval][out] */ IAcadPopupMenu **pItem) = 0;
        
        virtual /* [hidden][restricted][propget][id] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ IUnknown **pEnumVariant) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long *Count) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Application( 
            /* [retval][out] */ IAcadApplication **pAppObj) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Parent( 
            /* [retval][out] */ IAcadApplication **pParent) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAcadMenuBarVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAcadMenuBar * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAcadMenuBar * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAcadMenuBar * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IAcadMenuBar * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IAcadMenuBar * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IAcadMenuBar * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IAcadMenuBar * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Item )( 
            IAcadMenuBar * This,
            /* [in] */ VARIANT Index,
            /* [retval][out] */ IAcadPopupMenu **pItem);
        
        /* [hidden][restricted][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            IAcadMenuBar * This,
            /* [retval][out] */ IUnknown **pEnumVariant);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IAcadMenuBar * This,
            /* [retval][out] */ long *Count);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Application )( 
            IAcadMenuBar * This,
            /* [retval][out] */ IAcadApplication **pAppObj);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Parent )( 
            IAcadMenuBar * This,
            /* [retval][out] */ IAcadApplication **pParent);
        
        END_INTERFACE
    } IAcadMenuBarVtbl;

    interface IAcadMenuBar
    {
        CONST_VTBL struct IAcadMenuBarVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAcadMenuBar_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAcadMenuBar_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAcadMenuBar_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAcadMenuBar_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IAcadMenuBar_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IAcadMenuBar_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IAcadMenuBar_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IAcadMenuBar_Item(This,Index,pItem)	\
    ( (This)->lpVtbl -> Item(This,Index,pItem) ) 

#define IAcadMenuBar_get__NewEnum(This,pEnumVariant)	\
    ( (This)->lpVtbl -> get__NewEnum(This,pEnumVariant) ) 

#define IAcadMenuBar_get_Count(This,Count)	\
    ( (This)->lpVtbl -> get_Count(This,Count) ) 

#define IAcadMenuBar_get_Application(This,pAppObj)	\
    ( (This)->lpVtbl -> get_Application(This,pAppObj) ) 

#define IAcadMenuBar_get_Parent(This,pParent)	\
    ( (This)->lpVtbl -> get_Parent(This,pParent) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAcadMenuBar_INTERFACE_DEFINED__ */


#ifndef __IAcadApplication_INTERFACE_DEFINED__
#define __IAcadApplication_INTERFACE_DEFINED__

/* interface IAcadApplication */
/* [oleautomation][dual][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IAcadApplication;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D48F17B7-773E-4238-A6C6-B2BBEBAA9A1E")
    IAcadApplication : public IDispatch
    {
    public:
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Visible( 
            /* [retval][out] */ VARIANT_BOOL *Visible) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Visible( 
            /* [in] */ VARIANT_BOOL Visible) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *pAppName) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Caption( 
            /* [retval][out] */ BSTR *bstrCaption) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Application( 
            /* [retval][out] */ IAcadApplication **pAppObj) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ActiveDocument( 
            /* [retval][out] */ IAcadDocument **pActiveDoc) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_ActiveDocument( 
            /* [in] */ IAcadDocument *pActiveDoc) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_FullName( 
            /* [retval][out] */ BSTR *FullName) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Height( 
            /* [retval][out] */ int *Height) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Height( 
            /* [in] */ int Height) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_WindowLeft( 
            /* [retval][out] */ int *left) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_WindowLeft( 
            /* [in] */ int left) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Path( 
            /* [retval][out] */ BSTR *bstrPath) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_LocaleId( 
            /* [retval][out] */ long *lcid) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_WindowTop( 
            /* [retval][out] */ int *top) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_WindowTop( 
            /* [in] */ int top) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Version( 
            /* [retval][out] */ BSTR *bstrVer) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Width( 
            /* [retval][out] */ int *Width) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Width( 
            /* [in] */ int Width) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Preferences( 
            /* [retval][out] */ IAcadPreferences **pPreferences) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_StatusId( 
            /* [in] */ IDispatch *VportObj,
            /* [retval][out] */ VARIANT_BOOL *bStatus) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ListArx( 
            /* [retval][out] */ VARIANT *pVarListArray) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LoadArx( 
            /* [in] */ BSTR Name) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetInterfaceObject( 
            /* [in] */ BSTR ProgID,
            /* [retval][out] */ IDispatch **pObj) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE UnloadArx( 
            /* [in] */ BSTR Name) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Update( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Quit( void) = 0;
        
        virtual /* [helpstring][hidden][id] */ HRESULT STDMETHODCALLTYPE Zoom( 
            /* [in] */ int Type,
            /* [in] */ VARIANT *vParams) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_VBE( 
            /* [retval][out] */ IDispatch **pDispVBE) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_MenuGroups( 
            /* [retval][out] */ IAcadMenuGroups **pMenuGroups) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_MenuBar( 
            /* [retval][out] */ IAcadMenuBar **pMenuBar) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LoadDVB( 
            /* [in] */ BSTR Name) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE UnloadDVB( 
            /* [in] */ BSTR Name) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Documents( 
            /* [retval][out] */ IAcadDocuments **pDocuments) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Eval( 
            /* [in] */ BSTR Expression) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_WindowState( 
            /* [retval][out] */ enum /* external definition not present */ AcWindowState *eWinState) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_WindowState( 
            /* [in] */ enum /* external definition not present */ AcWindowState eWinState) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RunMacro( 
            /* [in] */ BSTR MacroPath) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ZoomExtents( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ZoomAll( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ZoomCenter( 
            /* [in] */ VARIANT Center,
            /* [in] */ double Magnify) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ZoomScaled( 
            /* [in] */ double scale,
            /* [in] */ enum /* external definition not present */ AcZoomScaleType ScaleType) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ZoomWindow( 
            /* [in] */ VARIANT LowerLeft,
            /* [in] */ VARIANT UpperRight) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ZoomPickWindow( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetAcadState( 
            /* [retval][out] */ IAcadState **pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ZoomPrevious( void) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_HWND( 
            /* [retval][out] */ LONG_PTR *hWnd) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DefineFunction( 
            /* [in] */ BSTR FunctionName,
            /* [in] */ VARIANT FunctionPointer) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE UndefineFunction( 
            /* [in] */ BSTR FunctionName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RunCommand( 
            /* [in] */ BSTR Command) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RunScript( 
            /* [in] */ BSTR Script) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAcadApplicationVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAcadApplication * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAcadApplication * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAcadApplication * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IAcadApplication * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IAcadApplication * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IAcadApplication * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IAcadApplication * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Visible )( 
            IAcadApplication * This,
            /* [retval][out] */ VARIANT_BOOL *Visible);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Visible )( 
            IAcadApplication * This,
            /* [in] */ VARIANT_BOOL Visible);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IAcadApplication * This,
            /* [retval][out] */ BSTR *pAppName);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Caption )( 
            IAcadApplication * This,
            /* [retval][out] */ BSTR *bstrCaption);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Application )( 
            IAcadApplication * This,
            /* [retval][out] */ IAcadApplication **pAppObj);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ActiveDocument )( 
            IAcadApplication * This,
            /* [retval][out] */ IAcadDocument **pActiveDoc);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_ActiveDocument )( 
            IAcadApplication * This,
            /* [in] */ IAcadDocument *pActiveDoc);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_FullName )( 
            IAcadApplication * This,
            /* [retval][out] */ BSTR *FullName);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Height )( 
            IAcadApplication * This,
            /* [retval][out] */ int *Height);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Height )( 
            IAcadApplication * This,
            /* [in] */ int Height);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_WindowLeft )( 
            IAcadApplication * This,
            /* [retval][out] */ int *left);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_WindowLeft )( 
            IAcadApplication * This,
            /* [in] */ int left);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Path )( 
            IAcadApplication * This,
            /* [retval][out] */ BSTR *bstrPath);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_LocaleId )( 
            IAcadApplication * This,
            /* [retval][out] */ long *lcid);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_WindowTop )( 
            IAcadApplication * This,
            /* [retval][out] */ int *top);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_WindowTop )( 
            IAcadApplication * This,
            /* [in] */ int top);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Version )( 
            IAcadApplication * This,
            /* [retval][out] */ BSTR *bstrVer);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Width )( 
            IAcadApplication * This,
            /* [retval][out] */ int *Width);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Width )( 
            IAcadApplication * This,
            /* [in] */ int Width);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Preferences )( 
            IAcadApplication * This,
            /* [retval][out] */ IAcadPreferences **pPreferences);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_StatusId )( 
            IAcadApplication * This,
            /* [in] */ IDispatch *VportObj,
            /* [retval][out] */ VARIANT_BOOL *bStatus);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ListArx )( 
            IAcadApplication * This,
            /* [retval][out] */ VARIANT *pVarListArray);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LoadArx )( 
            IAcadApplication * This,
            /* [in] */ BSTR Name);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetInterfaceObject )( 
            IAcadApplication * This,
            /* [in] */ BSTR ProgID,
            /* [retval][out] */ IDispatch **pObj);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UnloadArx )( 
            IAcadApplication * This,
            /* [in] */ BSTR Name);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Update )( 
            IAcadApplication * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Quit )( 
            IAcadApplication * This);
        
        /* [helpstring][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *Zoom )( 
            IAcadApplication * This,
            /* [in] */ int Type,
            /* [in] */ VARIANT *vParams);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_VBE )( 
            IAcadApplication * This,
            /* [retval][out] */ IDispatch **pDispVBE);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_MenuGroups )( 
            IAcadApplication * This,
            /* [retval][out] */ IAcadMenuGroups **pMenuGroups);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_MenuBar )( 
            IAcadApplication * This,
            /* [retval][out] */ IAcadMenuBar **pMenuBar);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LoadDVB )( 
            IAcadApplication * This,
            /* [in] */ BSTR Name);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UnloadDVB )( 
            IAcadApplication * This,
            /* [in] */ BSTR Name);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Documents )( 
            IAcadApplication * This,
            /* [retval][out] */ IAcadDocuments **pDocuments);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Eval )( 
            IAcadApplication * This,
            /* [in] */ BSTR Expression);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_WindowState )( 
            IAcadApplication * This,
            /* [retval][out] */ enum /* external definition not present */ AcWindowState *eWinState);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_WindowState )( 
            IAcadApplication * This,
            /* [in] */ enum /* external definition not present */ AcWindowState eWinState);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RunMacro )( 
            IAcadApplication * This,
            /* [in] */ BSTR MacroPath);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ZoomExtents )( 
            IAcadApplication * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ZoomAll )( 
            IAcadApplication * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ZoomCenter )( 
            IAcadApplication * This,
            /* [in] */ VARIANT Center,
            /* [in] */ double Magnify);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ZoomScaled )( 
            IAcadApplication * This,
            /* [in] */ double scale,
            /* [in] */ enum /* external definition not present */ AcZoomScaleType ScaleType);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ZoomWindow )( 
            IAcadApplication * This,
            /* [in] */ VARIANT LowerLeft,
            /* [in] */ VARIANT UpperRight);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ZoomPickWindow )( 
            IAcadApplication * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetAcadState )( 
            IAcadApplication * This,
            /* [retval][out] */ IAcadState **pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ZoomPrevious )( 
            IAcadApplication * This);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_HWND )( 
            IAcadApplication * This,
            /* [retval][out] */ LONG_PTR *hWnd);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DefineFunction )( 
            IAcadApplication * This,
            /* [in] */ BSTR FunctionName,
            /* [in] */ VARIANT FunctionPointer);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UndefineFunction )( 
            IAcadApplication * This,
            /* [in] */ BSTR FunctionName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RunCommand )( 
            IAcadApplication * This,
            /* [in] */ BSTR Command);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RunScript )( 
            IAcadApplication * This,
            /* [in] */ BSTR Script);
        
        END_INTERFACE
    } IAcadApplicationVtbl;

    interface IAcadApplication
    {
        CONST_VTBL struct IAcadApplicationVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAcadApplication_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAcadApplication_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAcadApplication_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAcadApplication_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IAcadApplication_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IAcadApplication_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IAcadApplication_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IAcadApplication_get_Visible(This,Visible)	\
    ( (This)->lpVtbl -> get_Visible(This,Visible) ) 

#define IAcadApplication_put_Visible(This,Visible)	\
    ( (This)->lpVtbl -> put_Visible(This,Visible) ) 

#define IAcadApplication_get_Name(This,pAppName)	\
    ( (This)->lpVtbl -> get_Name(This,pAppName) ) 

#define IAcadApplication_get_Caption(This,bstrCaption)	\
    ( (This)->lpVtbl -> get_Caption(This,bstrCaption) ) 

#define IAcadApplication_get_Application(This,pAppObj)	\
    ( (This)->lpVtbl -> get_Application(This,pAppObj) ) 

#define IAcadApplication_get_ActiveDocument(This,pActiveDoc)	\
    ( (This)->lpVtbl -> get_ActiveDocument(This,pActiveDoc) ) 

#define IAcadApplication_put_ActiveDocument(This,pActiveDoc)	\
    ( (This)->lpVtbl -> put_ActiveDocument(This,pActiveDoc) ) 

#define IAcadApplication_get_FullName(This,FullName)	\
    ( (This)->lpVtbl -> get_FullName(This,FullName) ) 

#define IAcadApplication_get_Height(This,Height)	\
    ( (This)->lpVtbl -> get_Height(This,Height) ) 

#define IAcadApplication_put_Height(This,Height)	\
    ( (This)->lpVtbl -> put_Height(This,Height) ) 

#define IAcadApplication_get_WindowLeft(This,left)	\
    ( (This)->lpVtbl -> get_WindowLeft(This,left) ) 

#define IAcadApplication_put_WindowLeft(This,left)	\
    ( (This)->lpVtbl -> put_WindowLeft(This,left) ) 

#define IAcadApplication_get_Path(This,bstrPath)	\
    ( (This)->lpVtbl -> get_Path(This,bstrPath) ) 

#define IAcadApplication_get_LocaleId(This,lcid)	\
    ( (This)->lpVtbl -> get_LocaleId(This,lcid) ) 

#define IAcadApplication_get_WindowTop(This,top)	\
    ( (This)->lpVtbl -> get_WindowTop(This,top) ) 

#define IAcadApplication_put_WindowTop(This,top)	\
    ( (This)->lpVtbl -> put_WindowTop(This,top) ) 

#define IAcadApplication_get_Version(This,bstrVer)	\
    ( (This)->lpVtbl -> get_Version(This,bstrVer) ) 

#define IAcadApplication_get_Width(This,Width)	\
    ( (This)->lpVtbl -> get_Width(This,Width) ) 

#define IAcadApplication_put_Width(This,Width)	\
    ( (This)->lpVtbl -> put_Width(This,Width) ) 

#define IAcadApplication_get_Preferences(This,pPreferences)	\
    ( (This)->lpVtbl -> get_Preferences(This,pPreferences) ) 

#define IAcadApplication_get_StatusId(This,VportObj,bStatus)	\
    ( (This)->lpVtbl -> get_StatusId(This,VportObj,bStatus) ) 

#define IAcadApplication_ListArx(This,pVarListArray)	\
    ( (This)->lpVtbl -> ListArx(This,pVarListArray) ) 

#define IAcadApplication_LoadArx(This,Name)	\
    ( (This)->lpVtbl -> LoadArx(This,Name) ) 

#define IAcadApplication_GetInterfaceObject(This,ProgID,pObj)	\
    ( (This)->lpVtbl -> GetInterfaceObject(This,ProgID,pObj) ) 

#define IAcadApplication_UnloadArx(This,Name)	\
    ( (This)->lpVtbl -> UnloadArx(This,Name) ) 

#define IAcadApplication_Update(This)	\
    ( (This)->lpVtbl -> Update(This) ) 

#define IAcadApplication_Quit(This)	\
    ( (This)->lpVtbl -> Quit(This) ) 

#define IAcadApplication_Zoom(This,Type,vParams)	\
    ( (This)->lpVtbl -> Zoom(This,Type,vParams) ) 

#define IAcadApplication_get_VBE(This,pDispVBE)	\
    ( (This)->lpVtbl -> get_VBE(This,pDispVBE) ) 

#define IAcadApplication_get_MenuGroups(This,pMenuGroups)	\
    ( (This)->lpVtbl -> get_MenuGroups(This,pMenuGroups) ) 

#define IAcadApplication_get_MenuBar(This,pMenuBar)	\
    ( (This)->lpVtbl -> get_MenuBar(This,pMenuBar) ) 

#define IAcadApplication_LoadDVB(This,Name)	\
    ( (This)->lpVtbl -> LoadDVB(This,Name) ) 

#define IAcadApplication_UnloadDVB(This,Name)	\
    ( (This)->lpVtbl -> UnloadDVB(This,Name) ) 

#define IAcadApplication_get_Documents(This,pDocuments)	\
    ( (This)->lpVtbl -> get_Documents(This,pDocuments) ) 

#define IAcadApplication_Eval(This,Expression)	\
    ( (This)->lpVtbl -> Eval(This,Expression) ) 

#define IAcadApplication_get_WindowState(This,eWinState)	\
    ( (This)->lpVtbl -> get_WindowState(This,eWinState) ) 

#define IAcadApplication_put_WindowState(This,eWinState)	\
    ( (This)->lpVtbl -> put_WindowState(This,eWinState) ) 

#define IAcadApplication_RunMacro(This,MacroPath)	\
    ( (This)->lpVtbl -> RunMacro(This,MacroPath) ) 

#define IAcadApplication_ZoomExtents(This)	\
    ( (This)->lpVtbl -> ZoomExtents(This) ) 

#define IAcadApplication_ZoomAll(This)	\
    ( (This)->lpVtbl -> ZoomAll(This) ) 

#define IAcadApplication_ZoomCenter(This,Center,Magnify)	\
    ( (This)->lpVtbl -> ZoomCenter(This,Center,Magnify) ) 

#define IAcadApplication_ZoomScaled(This,scale,ScaleType)	\
    ( (This)->lpVtbl -> ZoomScaled(This,scale,ScaleType) ) 

#define IAcadApplication_ZoomWindow(This,LowerLeft,UpperRight)	\
    ( (This)->lpVtbl -> ZoomWindow(This,LowerLeft,UpperRight) ) 

#define IAcadApplication_ZoomPickWindow(This)	\
    ( (This)->lpVtbl -> ZoomPickWindow(This) ) 

#define IAcadApplication_GetAcadState(This,pVal)	\
    ( (This)->lpVtbl -> GetAcadState(This,pVal) ) 

#define IAcadApplication_ZoomPrevious(This)	\
    ( (This)->lpVtbl -> ZoomPrevious(This) ) 

#define IAcadApplication_get_HWND(This,hWnd)	\
    ( (This)->lpVtbl -> get_HWND(This,hWnd) ) 

#define IAcadApplication_DefineFunction(This,FunctionName,FunctionPointer)	\
    ( (This)->lpVtbl -> DefineFunction(This,FunctionName,FunctionPointer) ) 

#define IAcadApplication_UndefineFunction(This,FunctionName)	\
    ( (This)->lpVtbl -> UndefineFunction(This,FunctionName) ) 

#define IAcadApplication_RunCommand(This,Command)	\
    ( (This)->lpVtbl -> RunCommand(This,Command) ) 

#define IAcadApplication_RunScript(This,Script)	\
    ( (This)->lpVtbl -> RunScript(This,Script) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAcadApplication_INTERFACE_DEFINED__ */


#ifndef __IAcadUtility_INTERFACE_DEFINED__
#define __IAcadUtility_INTERFACE_DEFINED__

/* interface IAcadUtility */
/* [object][oleautomation][dual][helpstring][uuid] */ 


EXTERN_C const IID IID_IAcadUtility;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5046A00A-7C22-4d39-ADE0-FB1AE3709B4D")
    IAcadUtility : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AngleToReal( 
            /* [in] */ BSTR Angle,
            /* [in] */ enum /* external definition not present */ AcAngleUnits Unit,
            /* [retval][out] */ double *Value) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AngleToString( 
            /* [in] */ double Angle,
            /* [in] */ enum /* external definition not present */ AcAngleUnits Unit,
            /* [in] */ int precision,
            /* [retval][out] */ BSTR *bstrValue) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DistanceToReal( 
            /* [in] */ BSTR Distance,
            /* [in] */ enum /* external definition not present */ AcUnits Unit,
            /* [retval][out] */ double *Value) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RealToString( 
            /* [in] */ double Value,
            /* [in] */ enum /* external definition not present */ AcUnits Unit,
            /* [in] */ int precision,
            /* [retval][out] */ BSTR *bstrValue) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE TranslateCoordinates( 
            /* [in] */ VARIANT Point,
            /* [in] */ enum /* external definition not present */ AcCoordinateSystem FromCoordSystem,
            /* [in] */ enum /* external definition not present */ AcCoordinateSystem ToCoordSystem,
            /* [in] */ int Displacement,
            /* [optional][in] */ VARIANT OCSNormal,
            /* [retval][out] */ VARIANT *transPt) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE InitializeUserInput( 
            /* [in] */ int Bits,
            /* [optional][in] */ VARIANT KeyWordList) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetInteger( 
            /* [optional][in] */ VARIANT Prompt,
            /* [retval][out] */ int *Value) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetReal( 
            /* [optional][in] */ VARIANT Prompt,
            /* [retval][out] */ double *Value) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetInput( 
            /* [retval][out] */ BSTR *Value) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetKeyword( 
            /* [optional][in] */ VARIANT Prompt,
            /* [retval][out] */ BSTR *bstrKeyword) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetString( 
            /* [in] */ int HasSpaces,
            /* [optional][in] */ VARIANT Prompt,
            /* [retval][out] */ BSTR *bstrValue) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetAngle( 
            /* [optional][in] */ VARIANT Point,
            /* [optional][in] */ VARIANT Prompt,
            /* [retval][out] */ double *Angle) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AngleFromXAxis( 
            /* [in] */ VARIANT StartPoint,
            /* [in] */ VARIANT EndPoint,
            /* [retval][out] */ double *Angle) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetCorner( 
            /* [in] */ VARIANT Point,
            /* [optional][in] */ VARIANT Prompt,
            /* [retval][out] */ VARIANT *corner) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDistance( 
            /* [optional][in] */ VARIANT Point,
            /* [optional][in] */ VARIANT Prompt,
            /* [retval][out] */ double *dist) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetOrientation( 
            /* [optional][in] */ VARIANT Point,
            /* [optional][in] */ VARIANT Prompt,
            /* [retval][out] */ double *Angle) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetPoint( 
            /* [optional][in] */ VARIANT Point,
            /* [optional][in] */ VARIANT Prompt,
            /* [retval][out] */ VARIANT *inputPoint) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PolarPoint( 
            /* [in] */ VARIANT Point,
            /* [in] */ double Angle,
            /* [in] */ double Distance,
            /* [retval][out] */ VARIANT *inputPoint) = 0;
        
        virtual /* [helpstring][vararg][id] */ HRESULT STDMETHODCALLTYPE CreateTypedArray( 
            /* [out] */ VARIANT *varArr,
            /* [in] */ int Type,
            /* [in] */ SAFEARRAY * inArgs) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetEntity( 
            /* [out] */ IDispatch **Object,
            /* [out] */ VARIANT *PickedPoint,
            /* [optional][in] */ VARIANT Prompt) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Prompt( 
            /* [in] */ BSTR Message) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetSubEntity( 
            /* [out] */ IDispatch **Object,
            /* [out] */ VARIANT *PickedPoint,
            /* [out] */ VARIANT *transMatrix,
            /* [out] */ VARIANT *ContextData,
            /* [optional][in] */ VARIANT Prompt) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsURL( 
            /* [in] */ BSTR URL,
            /* [retval][out] */ VARIANT_BOOL *IsValidURL) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetRemoteFile( 
            /* [in] */ BSTR URL,
            /* [out] */ BSTR *LocalFile,
            /* [in] */ VARIANT_BOOL IgnoreCache) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PutRemoteFile( 
            /* [in] */ BSTR URL,
            /* [in] */ BSTR LocalFile) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsRemoteFile( 
            /* [in] */ BSTR LocalFile,
            /* [out] */ BSTR *URL,
            /* [retval][out] */ VARIANT_BOOL *IsDownloadedFile) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LaunchBrowserDialog( 
            /* [out] */ BSTR *SelectedURL,
            /* [in] */ BSTR DialogTitle,
            /* [in] */ BSTR OpenButtonCaption,
            /* [in] */ BSTR StartPageURL,
            /* [in] */ BSTR RegistryRootKey,
            /* [in] */ VARIANT_BOOL OpenButtonAlwaysEnabled,
            /* [retval][out] */ VARIANT_BOOL *success) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SendModelessOperationStart( 
            BSTR operation) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SendModelessOperationEnded( 
            BSTR operation) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ObjectId32ToObjectIdString( 
            /* [in] */ long objectId32,
            /* [retval][out] */ BSTR *idString) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetObjectIdString( 
            /* [in] */ IDispatch *object,
            /* [in] */ VARIANT_BOOL asHex,
            /* [retval][out] */ BSTR *idString) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LogMessage( 
            /* [in] */ BSTR msg) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAcadUtilityVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAcadUtility * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAcadUtility * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAcadUtility * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IAcadUtility * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IAcadUtility * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IAcadUtility * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IAcadUtility * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AngleToReal )( 
            IAcadUtility * This,
            /* [in] */ BSTR Angle,
            /* [in] */ enum /* external definition not present */ AcAngleUnits Unit,
            /* [retval][out] */ double *Value);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AngleToString )( 
            IAcadUtility * This,
            /* [in] */ double Angle,
            /* [in] */ enum /* external definition not present */ AcAngleUnits Unit,
            /* [in] */ int precision,
            /* [retval][out] */ BSTR *bstrValue);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DistanceToReal )( 
            IAcadUtility * This,
            /* [in] */ BSTR Distance,
            /* [in] */ enum /* external definition not present */ AcUnits Unit,
            /* [retval][out] */ double *Value);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RealToString )( 
            IAcadUtility * This,
            /* [in] */ double Value,
            /* [in] */ enum /* external definition not present */ AcUnits Unit,
            /* [in] */ int precision,
            /* [retval][out] */ BSTR *bstrValue);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *TranslateCoordinates )( 
            IAcadUtility * This,
            /* [in] */ VARIANT Point,
            /* [in] */ enum /* external definition not present */ AcCoordinateSystem FromCoordSystem,
            /* [in] */ enum /* external definition not present */ AcCoordinateSystem ToCoordSystem,
            /* [in] */ int Displacement,
            /* [optional][in] */ VARIANT OCSNormal,
            /* [retval][out] */ VARIANT *transPt);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *InitializeUserInput )( 
            IAcadUtility * This,
            /* [in] */ int Bits,
            /* [optional][in] */ VARIANT KeyWordList);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetInteger )( 
            IAcadUtility * This,
            /* [optional][in] */ VARIANT Prompt,
            /* [retval][out] */ int *Value);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetReal )( 
            IAcadUtility * This,
            /* [optional][in] */ VARIANT Prompt,
            /* [retval][out] */ double *Value);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetInput )( 
            IAcadUtility * This,
            /* [retval][out] */ BSTR *Value);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetKeyword )( 
            IAcadUtility * This,
            /* [optional][in] */ VARIANT Prompt,
            /* [retval][out] */ BSTR *bstrKeyword);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetString )( 
            IAcadUtility * This,
            /* [in] */ int HasSpaces,
            /* [optional][in] */ VARIANT Prompt,
            /* [retval][out] */ BSTR *bstrValue);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetAngle )( 
            IAcadUtility * This,
            /* [optional][in] */ VARIANT Point,
            /* [optional][in] */ VARIANT Prompt,
            /* [retval][out] */ double *Angle);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AngleFromXAxis )( 
            IAcadUtility * This,
            /* [in] */ VARIANT StartPoint,
            /* [in] */ VARIANT EndPoint,
            /* [retval][out] */ double *Angle);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetCorner )( 
            IAcadUtility * This,
            /* [in] */ VARIANT Point,
            /* [optional][in] */ VARIANT Prompt,
            /* [retval][out] */ VARIANT *corner);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetDistance )( 
            IAcadUtility * This,
            /* [optional][in] */ VARIANT Point,
            /* [optional][in] */ VARIANT Prompt,
            /* [retval][out] */ double *dist);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetOrientation )( 
            IAcadUtility * This,
            /* [optional][in] */ VARIANT Point,
            /* [optional][in] */ VARIANT Prompt,
            /* [retval][out] */ double *Angle);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetPoint )( 
            IAcadUtility * This,
            /* [optional][in] */ VARIANT Point,
            /* [optional][in] */ VARIANT Prompt,
            /* [retval][out] */ VARIANT *inputPoint);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PolarPoint )( 
            IAcadUtility * This,
            /* [in] */ VARIANT Point,
            /* [in] */ double Angle,
            /* [in] */ double Distance,
            /* [retval][out] */ VARIANT *inputPoint);
        
        /* [helpstring][vararg][id] */ HRESULT ( STDMETHODCALLTYPE *CreateTypedArray )( 
            IAcadUtility * This,
            /* [out] */ VARIANT *varArr,
            /* [in] */ int Type,
            /* [in] */ SAFEARRAY * inArgs);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetEntity )( 
            IAcadUtility * This,
            /* [out] */ IDispatch **Object,
            /* [out] */ VARIANT *PickedPoint,
            /* [optional][in] */ VARIANT Prompt);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Prompt )( 
            IAcadUtility * This,
            /* [in] */ BSTR Message);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetSubEntity )( 
            IAcadUtility * This,
            /* [out] */ IDispatch **Object,
            /* [out] */ VARIANT *PickedPoint,
            /* [out] */ VARIANT *transMatrix,
            /* [out] */ VARIANT *ContextData,
            /* [optional][in] */ VARIANT Prompt);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsURL )( 
            IAcadUtility * This,
            /* [in] */ BSTR URL,
            /* [retval][out] */ VARIANT_BOOL *IsValidURL);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetRemoteFile )( 
            IAcadUtility * This,
            /* [in] */ BSTR URL,
            /* [out] */ BSTR *LocalFile,
            /* [in] */ VARIANT_BOOL IgnoreCache);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PutRemoteFile )( 
            IAcadUtility * This,
            /* [in] */ BSTR URL,
            /* [in] */ BSTR LocalFile);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsRemoteFile )( 
            IAcadUtility * This,
            /* [in] */ BSTR LocalFile,
            /* [out] */ BSTR *URL,
            /* [retval][out] */ VARIANT_BOOL *IsDownloadedFile);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LaunchBrowserDialog )( 
            IAcadUtility * This,
            /* [out] */ BSTR *SelectedURL,
            /* [in] */ BSTR DialogTitle,
            /* [in] */ BSTR OpenButtonCaption,
            /* [in] */ BSTR StartPageURL,
            /* [in] */ BSTR RegistryRootKey,
            /* [in] */ VARIANT_BOOL OpenButtonAlwaysEnabled,
            /* [retval][out] */ VARIANT_BOOL *success);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SendModelessOperationStart )( 
            IAcadUtility * This,
            BSTR operation);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SendModelessOperationEnded )( 
            IAcadUtility * This,
            BSTR operation);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ObjectId32ToObjectIdString )( 
            IAcadUtility * This,
            /* [in] */ long objectId32,
            /* [retval][out] */ BSTR *idString);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetObjectIdString )( 
            IAcadUtility * This,
            /* [in] */ IDispatch *object,
            /* [in] */ VARIANT_BOOL asHex,
            /* [retval][out] */ BSTR *idString);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LogMessage )( 
            IAcadUtility * This,
            /* [in] */ BSTR msg);
        
        END_INTERFACE
    } IAcadUtilityVtbl;

    interface IAcadUtility
    {
        CONST_VTBL struct IAcadUtilityVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAcadUtility_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAcadUtility_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAcadUtility_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAcadUtility_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IAcadUtility_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IAcadUtility_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IAcadUtility_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IAcadUtility_AngleToReal(This,Angle,Unit,Value)	\
    ( (This)->lpVtbl -> AngleToReal(This,Angle,Unit,Value) ) 

#define IAcadUtility_AngleToString(This,Angle,Unit,precision,bstrValue)	\
    ( (This)->lpVtbl -> AngleToString(This,Angle,Unit,precision,bstrValue) ) 

#define IAcadUtility_DistanceToReal(This,Distance,Unit,Value)	\
    ( (This)->lpVtbl -> DistanceToReal(This,Distance,Unit,Value) ) 

#define IAcadUtility_RealToString(This,Value,Unit,precision,bstrValue)	\
    ( (This)->lpVtbl -> RealToString(This,Value,Unit,precision,bstrValue) ) 

#define IAcadUtility_TranslateCoordinates(This,Point,FromCoordSystem,ToCoordSystem,Displacement,OCSNormal,transPt)	\
    ( (This)->lpVtbl -> TranslateCoordinates(This,Point,FromCoordSystem,ToCoordSystem,Displacement,OCSNormal,transPt) ) 

#define IAcadUtility_InitializeUserInput(This,Bits,KeyWordList)	\
    ( (This)->lpVtbl -> InitializeUserInput(This,Bits,KeyWordList) ) 

#define IAcadUtility_GetInteger(This,Prompt,Value)	\
    ( (This)->lpVtbl -> GetInteger(This,Prompt,Value) ) 

#define IAcadUtility_GetReal(This,Prompt,Value)	\
    ( (This)->lpVtbl -> GetReal(This,Prompt,Value) ) 

#define IAcadUtility_GetInput(This,Value)	\
    ( (This)->lpVtbl -> GetInput(This,Value) ) 

#define IAcadUtility_GetKeyword(This,Prompt,bstrKeyword)	\
    ( (This)->lpVtbl -> GetKeyword(This,Prompt,bstrKeyword) ) 

#define IAcadUtility_GetString(This,HasSpaces,Prompt,bstrValue)	\
    ( (This)->lpVtbl -> GetString(This,HasSpaces,Prompt,bstrValue) ) 

#define IAcadUtility_GetAngle(This,Point,Prompt,Angle)	\
    ( (This)->lpVtbl -> GetAngle(This,Point,Prompt,Angle) ) 

#define IAcadUtility_AngleFromXAxis(This,StartPoint,EndPoint,Angle)	\
    ( (This)->lpVtbl -> AngleFromXAxis(This,StartPoint,EndPoint,Angle) ) 

#define IAcadUtility_GetCorner(This,Point,Prompt,corner)	\
    ( (This)->lpVtbl -> GetCorner(This,Point,Prompt,corner) ) 

#define IAcadUtility_GetDistance(This,Point,Prompt,dist)	\
    ( (This)->lpVtbl -> GetDistance(This,Point,Prompt,dist) ) 

#define IAcadUtility_GetOrientation(This,Point,Prompt,Angle)	\
    ( (This)->lpVtbl -> GetOrientation(This,Point,Prompt,Angle) ) 

#define IAcadUtility_GetPoint(This,Point,Prompt,inputPoint)	\
    ( (This)->lpVtbl -> GetPoint(This,Point,Prompt,inputPoint) ) 

#define IAcadUtility_PolarPoint(This,Point,Angle,Distance,inputPoint)	\
    ( (This)->lpVtbl -> PolarPoint(This,Point,Angle,Distance,inputPoint) ) 

#define IAcadUtility_CreateTypedArray(This,varArr,Type,inArgs)	\
    ( (This)->lpVtbl -> CreateTypedArray(This,varArr,Type,inArgs) ) 

#define IAcadUtility_GetEntity(This,Object,PickedPoint,Prompt)	\
    ( (This)->lpVtbl -> GetEntity(This,Object,PickedPoint,Prompt) ) 

#define IAcadUtility_Prompt(This,Message)	\
    ( (This)->lpVtbl -> Prompt(This,Message) ) 

#define IAcadUtility_GetSubEntity(This,Object,PickedPoint,transMatrix,ContextData,Prompt)	\
    ( (This)->lpVtbl -> GetSubEntity(This,Object,PickedPoint,transMatrix,ContextData,Prompt) ) 

#define IAcadUtility_IsURL(This,URL,IsValidURL)	\
    ( (This)->lpVtbl -> IsURL(This,URL,IsValidURL) ) 

#define IAcadUtility_GetRemoteFile(This,URL,LocalFile,IgnoreCache)	\
    ( (This)->lpVtbl -> GetRemoteFile(This,URL,LocalFile,IgnoreCache) ) 

#define IAcadUtility_PutRemoteFile(This,URL,LocalFile)	\
    ( (This)->lpVtbl -> PutRemoteFile(This,URL,LocalFile) ) 

#define IAcadUtility_IsRemoteFile(This,LocalFile,URL,IsDownloadedFile)	\
    ( (This)->lpVtbl -> IsRemoteFile(This,LocalFile,URL,IsDownloadedFile) ) 

#define IAcadUtility_LaunchBrowserDialog(This,SelectedURL,DialogTitle,OpenButtonCaption,StartPageURL,RegistryRootKey,OpenButtonAlwaysEnabled,success)	\
    ( (This)->lpVtbl -> LaunchBrowserDialog(This,SelectedURL,DialogTitle,OpenButtonCaption,StartPageURL,RegistryRootKey,OpenButtonAlwaysEnabled,success) ) 

#define IAcadUtility_SendModelessOperationStart(This,operation)	\
    ( (This)->lpVtbl -> SendModelessOperationStart(This,operation) ) 

#define IAcadUtility_SendModelessOperationEnded(This,operation)	\
    ( (This)->lpVtbl -> SendModelessOperationEnded(This,operation) ) 

#define IAcadUtility_ObjectId32ToObjectIdString(This,objectId32,idString)	\
    ( (This)->lpVtbl -> ObjectId32ToObjectIdString(This,objectId32,idString) ) 

#define IAcadUtility_GetObjectIdString(This,object,asHex,idString)	\
    ( (This)->lpVtbl -> GetObjectIdString(This,object,asHex,idString) ) 

#define IAcadUtility_LogMessage(This,msg)	\
    ( (This)->lpVtbl -> LogMessage(This,msg) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAcadUtility_INTERFACE_DEFINED__ */


#ifndef __IAcadDocument_INTERFACE_DEFINED__
#define __IAcadDocument_INTERFACE_DEFINED__

/* interface IAcadDocument */
/* [oleautomation][dual][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IAcadDocument;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5896DFEB-2488-49f7-8A9D-CF0DEA5AC6FB")
    IAcadDocument : public IAcadDatabase
    {
    public:
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Plot( 
            /* [retval][out] */ IAcadPlot **pPlot) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ActiveLayer( 
            /* [retval][out] */ /* external definition not present */ IAcadLayer **pActLayer) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_ActiveLayer( 
            /* [in] */ /* external definition not present */ IAcadLayer *pActLayer) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ActiveLinetype( 
            /* [retval][out] */ /* external definition not present */ IAcadLineType **pActLinetype) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_ActiveLinetype( 
            /* [in] */ /* external definition not present */ IAcadLineType *pActLinetype) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ActiveDimStyle( 
            /* [retval][out] */ /* external definition not present */ IAcadDimStyle **pActDimStyle) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_ActiveDimStyle( 
            /* [in] */ /* external definition not present */ IAcadDimStyle *pActDimStyle) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ActiveTextStyle( 
            /* [retval][out] */ /* external definition not present */ IAcadTextStyle **pActTextStyle) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_ActiveTextStyle( 
            /* [in] */ /* external definition not present */ IAcadTextStyle *pActTextStyle) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ActiveUCS( 
            /* [retval][out] */ /* external definition not present */ IAcadUCS **pActUCS) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_ActiveUCS( 
            /* [in] */ /* external definition not present */ IAcadUCS *pActUCS) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ActiveViewport( 
            /* [retval][out] */ /* external definition not present */ IAcadViewport **pActView) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_ActiveViewport( 
            /* [in] */ /* external definition not present */ IAcadViewport *pActView) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ActivePViewport( 
            /* [retval][out] */ /* external definition not present */ IAcadPViewport **pActView) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_ActivePViewport( 
            /* [in] */ /* external definition not present */ IAcadPViewport *pActView) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ActiveSpace( 
            /* [retval][out] */ enum /* external definition not present */ AcActiveSpace *ActSpace) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_ActiveSpace( 
            /* [in] */ enum /* external definition not present */ AcActiveSpace ActSpace) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_SelectionSets( 
            /* [retval][out] */ IAcadSelectionSets **pSelSets) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ActiveSelectionSet( 
            /* [retval][out] */ IAcadSelectionSet **pSelSet) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_FullName( 
            /* [retval][out] */ BSTR *FullName) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *Name) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Path( 
            /* [retval][out] */ BSTR *Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ObjectSnapMode( 
            /* [retval][out] */ VARIANT_BOOL *fSnapMode) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_ObjectSnapMode( 
            /* [in] */ VARIANT_BOOL fSnapMode) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ReadOnly( 
            /* [retval][out] */ VARIANT_BOOL *bReadOnly) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Saved( 
            /* [retval][out] */ VARIANT_BOOL *bSaved) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_MSpace( 
            /* [retval][out] */ VARIANT_BOOL *Mode) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_MSpace( 
            /* [in] */ VARIANT_BOOL Mode) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Utility( 
            /* [retval][out] */ IAcadUtility **pUtil) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Open( 
            /* [in] */ BSTR FullName,
            /* [optional][in] */ VARIANT Password,
            /* [retval][out] */ IAcadDocument **pDocObj) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AuditInfo( 
            /* [in] */ VARIANT_BOOL FixErr) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Import( 
            /* [in] */ BSTR FileName,
            /* [in] */ VARIANT InsertionPoint,
            /* [in] */ double ScaleFactor,
            /* [retval][out] */ IDispatch **pObj) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Export( 
            /* [in] */ BSTR FileName,
            /* [in] */ BSTR Extension,
            /* [in] */ IAcadSelectionSet *SelectionSet) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE New( 
            /* [in] */ BSTR TemplateFileName,
            /* [retval][out] */ IAcadDocument **pDocObj) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Save( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SaveAs( 
            /* [in] */ BSTR FullFileName,
            /* [optional][in] */ VARIANT SaveAsType,
            /* [optional][in] */ VARIANT vSecurityParams) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Wblock( 
            /* [in] */ BSTR FileName,
            /* [in] */ IAcadSelectionSet *SelectionSet) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PurgeAll( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetVariable( 
            /* [in] */ BSTR Name,
            /* [retval][out] */ VARIANT *Value) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetVariable( 
            /* [in] */ BSTR Name,
            /* [in] */ VARIANT Value) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LoadShapeFile( 
            /* [in] */ BSTR FullName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Regen( 
            /* [in] */ enum /* external definition not present */ AcRegenType WhichViewports) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_PickfirstSelectionSet( 
            /* [retval][out] */ IDispatch **pSelSet) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Active( 
            /* [retval][out] */ VARIANT_BOOL *pvbActive) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Activate( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Close( 
            /* [optional][in] */ VARIANT SaveChanges,
            /* [optional][in] */ VARIANT FileName) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_WindowState( 
            /* [in] */ enum /* external definition not present */ AcWindowState pWinState) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_WindowState( 
            /* [retval][out] */ enum /* external definition not present */ AcWindowState *pWinState) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Width( 
            /* [in] */ int pWidth) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Width( 
            /* [retval][out] */ int *pWidth) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Height( 
            /* [in] */ int pHeight) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Height( 
            /* [retval][out] */ int *pHeight) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_ActiveLayout( 
            /* [in] */ /* external definition not present */ IAcadLayout *pLayout) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ActiveLayout( 
            /* [retval][out] */ /* external definition not present */ IAcadLayout **pLayout) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SendCommand( 
            /* [in] */ BSTR Command) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_HWND( 
            /* [retval][out] */ LONG_PTR *hWnd) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_WindowTitle( 
            /* [retval][out] */ BSTR *Title) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Application( 
            /* [retval][out] */ IAcadApplication **pAppObj) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Database( 
            /* [retval][out] */ /* external definition not present */ IAcadDatabase **pDatabase) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE StartUndoMark( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EndUndoMark( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE getTransmittalOperationInterface( 
            /* [retval][out] */ ITransmittalOperation **ppITrmOp) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EvaluateLisp( 
            /* [in] */ BSTR lispString,
            /* [retval][out] */ VARIANT *pvResult) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ActiveMaterial( 
            /* [retval][out] */ /* external definition not present */ IAcadMaterial **pActMaterial) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_ActiveMaterial( 
            /* [in] */ /* external definition not present */ IAcadMaterial *pActMaterial) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_NumTransactions( 
            /* [retval][out] */ int *pNumTransactions) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE StartTransaction( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EndTransaction( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AbortTransaction( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAcadDocumentVtbl
    {
        BEGIN_INTERFACE
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAcadDocument * This,
            /* [in][idldescattr] */ struct GUID *riid,
            /* [out][idldescattr] */ void **ppvObj,
            /* [retval][out] */ void *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *AddRef )( 
            IAcadDocument * This,
            /* [retval][out] */ unsigned long *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Release )( 
            IAcadDocument * This,
            /* [retval][out] */ unsigned long *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IAcadDocument * This,
            /* [out][idldescattr] */ unsigned UINT *pctinfo,
            /* [retval][out] */ void *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IAcadDocument * This,
            /* [in][idldescattr] */ unsigned UINT itinfo,
            /* [in][idldescattr] */ unsigned long lcid,
            /* [out][idldescattr] */ void **pptinfo,
            /* [retval][out] */ void *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IAcadDocument * This,
            /* [in][idldescattr] */ struct GUID *riid,
            /* [in][idldescattr] */ signed char **rgszNames,
            /* [in][idldescattr] */ unsigned UINT cNames,
            /* [in][idldescattr] */ unsigned long lcid,
            /* [out][idldescattr] */ signed long *rgdispid,
            /* [retval][out] */ void *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IAcadDocument * This,
            /* [in][idldescattr] */ signed long dispidMember,
            /* [in][idldescattr] */ struct GUID *riid,
            /* [in][idldescattr] */ unsigned long lcid,
            /* [in][idldescattr] */ unsigned short wFlags,
            /* [in][idldescattr] */ struct DISPPARAMS *pdispparams,
            /* [out][idldescattr] */ VARIANT *pvarResult,
            /* [out][idldescattr] */ struct EXCEPINFO *pexcepinfo,
            /* [out][idldescattr] */ unsigned UINT *puArgErr,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_ModelSpace )( 
            IAcadDocument * This,
            /* [retval][out] */ IAcadModelSpace **retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_PaperSpace )( 
            IAcadDocument * This,
            /* [retval][out] */ IAcadPaperSpace **retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Blocks )( 
            IAcadDocument * This,
            /* [retval][out] */ IAcadBlocks **retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *CopyObjects )( 
            IAcadDocument * This,
            /* [in][idldescattr] */ VARIANT Objects,
            /* [optional][in][idldescattr] */ VARIANT Owner,
            /* [optional][out][in][idldescattr] */ VARIANT *IdPairs,
            /* [retval][out] */ VARIANT *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Groups )( 
            IAcadDocument * This,
            /* [retval][out] */ IAcadGroups **retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_DimStyles )( 
            IAcadDocument * This,
            /* [retval][out] */ IAcadDimStyles **retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Layers )( 
            IAcadDocument * This,
            /* [retval][out] */ IAcadLayers **retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Linetypes )( 
            IAcadDocument * This,
            /* [retval][out] */ IAcadLineTypes **retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Dictionaries )( 
            IAcadDocument * This,
            /* [retval][out] */ IAcadDictionaries **retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_RegisteredApplications )( 
            IAcadDocument * This,
            /* [retval][out] */ IAcadRegisteredApplications **retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_TextStyles )( 
            IAcadDocument * This,
            /* [retval][out] */ IAcadTextStyles **retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_UserCoordinateSystems )( 
            IAcadDocument * This,
            /* [retval][out] */ IAcadUCSs **retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Views )( 
            IAcadDocument * This,
            /* [retval][out] */ IAcadViews **retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Viewports )( 
            IAcadDocument * This,
            /* [retval][out] */ IAcadViewports **retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_ElevationModelSpace )( 
            IAcadDocument * This,
            /* [retval][out] */ double *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_ElevationModelSpace )( 
            IAcadDocument * This,
            /* [in][idldescattr] */ double noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_ElevationPaperSpace )( 
            IAcadDocument * This,
            /* [retval][out] */ double *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_ElevationPaperSpace )( 
            IAcadDocument * This,
            /* [in][idldescattr] */ double noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Limits )( 
            IAcadDocument * This,
            /* [retval][out] */ VARIANT *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_Limits )( 
            IAcadDocument * This,
            /* [in][idldescattr] */ VARIANT noname,
            /* [retval][out] */ void *retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *HandleToObject )( 
            IAcadDocument * This,
            /* [in][idldescattr] */ BSTR Handle,
            /* [retval][out] */ IDispatch **retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *ObjectIdToObject )( 
            IAcadDocument * This,
            /* [in][idldescattr] */ LONG_PTR ObjectID,
            /* [retval][out] */ IDispatch **retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Layouts )( 
            IAcadDocument * This,
            /* [retval][out] */ IAcadLayouts **retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_PlotConfigurations )( 
            IAcadDocument * This,
            /* [retval][out] */ IAcadPlotConfigurations **retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Preferences )( 
            IAcadDocument * This,
            /* [retval][out] */ IAcadDatabasePreferences **retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_FileDependencies )( 
            IAcadDocument * This,
            /* [retval][out] */ IAcadFileDependencies **retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_SummaryInfo )( 
            IAcadDocument * This,
            /* [retval][out] */ IAcadSummaryInfo **retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_SectionManager )( 
            IAcadDocument * This,
            /* [retval][out] */ IAcadSectionManager **retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Materials )( 
            IAcadDocument * This,
            /* [retval][out] */ IAcadMaterials **retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *ObjectIdToObject32 )( 
            IAcadDocument * This,
            /* [in][idldescattr] */ signed long ObjectID,
            /* [retval][out] */ IDispatch **retval);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Plot )( 
            IAcadDocument * This,
            /* [retval][out] */ IAcadPlot **pPlot);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ActiveLayer )( 
            IAcadDocument * This,
            /* [retval][out] */ /* external definition not present */ IAcadLayer **pActLayer);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_ActiveLayer )( 
            IAcadDocument * This,
            /* [in] */ /* external definition not present */ IAcadLayer *pActLayer);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ActiveLinetype )( 
            IAcadDocument * This,
            /* [retval][out] */ /* external definition not present */ IAcadLineType **pActLinetype);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_ActiveLinetype )( 
            IAcadDocument * This,
            /* [in] */ /* external definition not present */ IAcadLineType *pActLinetype);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ActiveDimStyle )( 
            IAcadDocument * This,
            /* [retval][out] */ /* external definition not present */ IAcadDimStyle **pActDimStyle);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_ActiveDimStyle )( 
            IAcadDocument * This,
            /* [in] */ /* external definition not present */ IAcadDimStyle *pActDimStyle);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ActiveTextStyle )( 
            IAcadDocument * This,
            /* [retval][out] */ /* external definition not present */ IAcadTextStyle **pActTextStyle);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_ActiveTextStyle )( 
            IAcadDocument * This,
            /* [in] */ /* external definition not present */ IAcadTextStyle *pActTextStyle);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ActiveUCS )( 
            IAcadDocument * This,
            /* [retval][out] */ /* external definition not present */ IAcadUCS **pActUCS);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_ActiveUCS )( 
            IAcadDocument * This,
            /* [in] */ /* external definition not present */ IAcadUCS *pActUCS);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ActiveViewport )( 
            IAcadDocument * This,
            /* [retval][out] */ /* external definition not present */ IAcadViewport **pActView);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_ActiveViewport )( 
            IAcadDocument * This,
            /* [in] */ /* external definition not present */ IAcadViewport *pActView);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ActivePViewport )( 
            IAcadDocument * This,
            /* [retval][out] */ /* external definition not present */ IAcadPViewport **pActView);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_ActivePViewport )( 
            IAcadDocument * This,
            /* [in] */ /* external definition not present */ IAcadPViewport *pActView);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ActiveSpace )( 
            IAcadDocument * This,
            /* [retval][out] */ enum /* external definition not present */ AcActiveSpace *ActSpace);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_ActiveSpace )( 
            IAcadDocument * This,
            /* [in] */ enum /* external definition not present */ AcActiveSpace ActSpace);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_SelectionSets )( 
            IAcadDocument * This,
            /* [retval][out] */ IAcadSelectionSets **pSelSets);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ActiveSelectionSet )( 
            IAcadDocument * This,
            /* [retval][out] */ IAcadSelectionSet **pSelSet);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_FullName )( 
            IAcadDocument * This,
            /* [retval][out] */ BSTR *FullName);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IAcadDocument * This,
            /* [retval][out] */ BSTR *Name);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Path )( 
            IAcadDocument * This,
            /* [retval][out] */ BSTR *Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ObjectSnapMode )( 
            IAcadDocument * This,
            /* [retval][out] */ VARIANT_BOOL *fSnapMode);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_ObjectSnapMode )( 
            IAcadDocument * This,
            /* [in] */ VARIANT_BOOL fSnapMode);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ReadOnly )( 
            IAcadDocument * This,
            /* [retval][out] */ VARIANT_BOOL *bReadOnly);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Saved )( 
            IAcadDocument * This,
            /* [retval][out] */ VARIANT_BOOL *bSaved);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_MSpace )( 
            IAcadDocument * This,
            /* [retval][out] */ VARIANT_BOOL *Mode);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_MSpace )( 
            IAcadDocument * This,
            /* [in] */ VARIANT_BOOL Mode);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Utility )( 
            IAcadDocument * This,
            /* [retval][out] */ IAcadUtility **pUtil);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Open )( 
            IAcadDocument * This,
            /* [in] */ BSTR FullName,
            /* [optional][in] */ VARIANT Password,
            /* [retval][out] */ IAcadDocument **pDocObj);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AuditInfo )( 
            IAcadDocument * This,
            /* [in] */ VARIANT_BOOL FixErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Import )( 
            IAcadDocument * This,
            /* [in] */ BSTR FileName,
            /* [in] */ VARIANT InsertionPoint,
            /* [in] */ double ScaleFactor,
            /* [retval][out] */ IDispatch **pObj);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Export )( 
            IAcadDocument * This,
            /* [in] */ BSTR FileName,
            /* [in] */ BSTR Extension,
            /* [in] */ IAcadSelectionSet *SelectionSet);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *New )( 
            IAcadDocument * This,
            /* [in] */ BSTR TemplateFileName,
            /* [retval][out] */ IAcadDocument **pDocObj);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Save )( 
            IAcadDocument * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SaveAs )( 
            IAcadDocument * This,
            /* [in] */ BSTR FullFileName,
            /* [optional][in] */ VARIANT SaveAsType,
            /* [optional][in] */ VARIANT vSecurityParams);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Wblock )( 
            IAcadDocument * This,
            /* [in] */ BSTR FileName,
            /* [in] */ IAcadSelectionSet *SelectionSet);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PurgeAll )( 
            IAcadDocument * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetVariable )( 
            IAcadDocument * This,
            /* [in] */ BSTR Name,
            /* [retval][out] */ VARIANT *Value);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetVariable )( 
            IAcadDocument * This,
            /* [in] */ BSTR Name,
            /* [in] */ VARIANT Value);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LoadShapeFile )( 
            IAcadDocument * This,
            /* [in] */ BSTR FullName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Regen )( 
            IAcadDocument * This,
            /* [in] */ enum /* external definition not present */ AcRegenType WhichViewports);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_PickfirstSelectionSet )( 
            IAcadDocument * This,
            /* [retval][out] */ IDispatch **pSelSet);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Active )( 
            IAcadDocument * This,
            /* [retval][out] */ VARIANT_BOOL *pvbActive);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Activate )( 
            IAcadDocument * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Close )( 
            IAcadDocument * This,
            /* [optional][in] */ VARIANT SaveChanges,
            /* [optional][in] */ VARIANT FileName);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_WindowState )( 
            IAcadDocument * This,
            /* [in] */ enum /* external definition not present */ AcWindowState pWinState);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_WindowState )( 
            IAcadDocument * This,
            /* [retval][out] */ enum /* external definition not present */ AcWindowState *pWinState);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Width )( 
            IAcadDocument * This,
            /* [in] */ int pWidth);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Width )( 
            IAcadDocument * This,
            /* [retval][out] */ int *pWidth);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Height )( 
            IAcadDocument * This,
            /* [in] */ int pHeight);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Height )( 
            IAcadDocument * This,
            /* [retval][out] */ int *pHeight);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_ActiveLayout )( 
            IAcadDocument * This,
            /* [in] */ /* external definition not present */ IAcadLayout *pLayout);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ActiveLayout )( 
            IAcadDocument * This,
            /* [retval][out] */ /* external definition not present */ IAcadLayout **pLayout);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SendCommand )( 
            IAcadDocument * This,
            /* [in] */ BSTR Command);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_HWND )( 
            IAcadDocument * This,
            /* [retval][out] */ LONG_PTR *hWnd);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_WindowTitle )( 
            IAcadDocument * This,
            /* [retval][out] */ BSTR *Title);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Application )( 
            IAcadDocument * This,
            /* [retval][out] */ IAcadApplication **pAppObj);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Database )( 
            IAcadDocument * This,
            /* [retval][out] */ /* external definition not present */ IAcadDatabase **pDatabase);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *StartUndoMark )( 
            IAcadDocument * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EndUndoMark )( 
            IAcadDocument * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *getTransmittalOperationInterface )( 
            IAcadDocument * This,
            /* [retval][out] */ ITransmittalOperation **ppITrmOp);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EvaluateLisp )( 
            IAcadDocument * This,
            /* [in] */ BSTR lispString,
            /* [retval][out] */ VARIANT *pvResult);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ActiveMaterial )( 
            IAcadDocument * This,
            /* [retval][out] */ /* external definition not present */ IAcadMaterial **pActMaterial);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_ActiveMaterial )( 
            IAcadDocument * This,
            /* [in] */ /* external definition not present */ IAcadMaterial *pActMaterial);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_NumTransactions )( 
            IAcadDocument * This,
            /* [retval][out] */ int *pNumTransactions);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *StartTransaction )( 
            IAcadDocument * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EndTransaction )( 
            IAcadDocument * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AbortTransaction )( 
            IAcadDocument * This);
        
        END_INTERFACE
    } IAcadDocumentVtbl;

    interface IAcadDocument
    {
        CONST_VTBL struct IAcadDocumentVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAcadDocument_QueryInterface(This,riid,ppvObj,retval)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObj,retval) ) 

#define IAcadDocument_AddRef(This,retval)	\
    ( (This)->lpVtbl -> AddRef(This,retval) ) 

#define IAcadDocument_Release(This,retval)	\
    ( (This)->lpVtbl -> Release(This,retval) ) 

#define IAcadDocument_GetTypeInfoCount(This,pctinfo,retval)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo,retval) ) 

#define IAcadDocument_GetTypeInfo(This,itinfo,lcid,pptinfo,retval)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,itinfo,lcid,pptinfo,retval) ) 

#define IAcadDocument_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgdispid,retval)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgdispid,retval) ) 

#define IAcadDocument_Invoke(This,dispidMember,riid,lcid,wFlags,pdispparams,pvarResult,pexcepinfo,puArgErr,retval)	\
    ( (This)->lpVtbl -> Invoke(This,dispidMember,riid,lcid,wFlags,pdispparams,pvarResult,pexcepinfo,puArgErr,retval) ) 

#define IAcadDocument_get_ModelSpace(This,retval)	\
    ( (This)->lpVtbl -> get_ModelSpace(This,retval) ) 

#define IAcadDocument_get_PaperSpace(This,retval)	\
    ( (This)->lpVtbl -> get_PaperSpace(This,retval) ) 

#define IAcadDocument_get_Blocks(This,retval)	\
    ( (This)->lpVtbl -> get_Blocks(This,retval) ) 

#define IAcadDocument_CopyObjects(This,Objects,Owner,IdPairs,retval)	\
    ( (This)->lpVtbl -> CopyObjects(This,Objects,Owner,IdPairs,retval) ) 

#define IAcadDocument_get_Groups(This,retval)	\
    ( (This)->lpVtbl -> get_Groups(This,retval) ) 

#define IAcadDocument_get_DimStyles(This,retval)	\
    ( (This)->lpVtbl -> get_DimStyles(This,retval) ) 

#define IAcadDocument_get_Layers(This,retval)	\
    ( (This)->lpVtbl -> get_Layers(This,retval) ) 

#define IAcadDocument_get_Linetypes(This,retval)	\
    ( (This)->lpVtbl -> get_Linetypes(This,retval) ) 

#define IAcadDocument_get_Dictionaries(This,retval)	\
    ( (This)->lpVtbl -> get_Dictionaries(This,retval) ) 

#define IAcadDocument_get_RegisteredApplications(This,retval)	\
    ( (This)->lpVtbl -> get_RegisteredApplications(This,retval) ) 

#define IAcadDocument_get_TextStyles(This,retval)	\
    ( (This)->lpVtbl -> get_TextStyles(This,retval) ) 

#define IAcadDocument_get_UserCoordinateSystems(This,retval)	\
    ( (This)->lpVtbl -> get_UserCoordinateSystems(This,retval) ) 

#define IAcadDocument_get_Views(This,retval)	\
    ( (This)->lpVtbl -> get_Views(This,retval) ) 

#define IAcadDocument_get_Viewports(This,retval)	\
    ( (This)->lpVtbl -> get_Viewports(This,retval) ) 

#define IAcadDocument_get_ElevationModelSpace(This,retval)	\
    ( (This)->lpVtbl -> get_ElevationModelSpace(This,retval) ) 

#define IAcadDocument_put_ElevationModelSpace(This,noname,retval)	\
    ( (This)->lpVtbl -> put_ElevationModelSpace(This,noname,retval) ) 

#define IAcadDocument_get_ElevationPaperSpace(This,retval)	\
    ( (This)->lpVtbl -> get_ElevationPaperSpace(This,retval) ) 

#define IAcadDocument_put_ElevationPaperSpace(This,noname,retval)	\
    ( (This)->lpVtbl -> put_ElevationPaperSpace(This,noname,retval) ) 

#define IAcadDocument_get_Limits(This,retval)	\
    ( (This)->lpVtbl -> get_Limits(This,retval) ) 

#define IAcadDocument_put_Limits(This,noname,retval)	\
    ( (This)->lpVtbl -> put_Limits(This,noname,retval) ) 

#define IAcadDocument_HandleToObject(This,Handle,retval)	\
    ( (This)->lpVtbl -> HandleToObject(This,Handle,retval) ) 

#define IAcadDocument_ObjectIdToObject(This,ObjectID,retval)	\
    ( (This)->lpVtbl -> ObjectIdToObject(This,ObjectID,retval) ) 

#define IAcadDocument_get_Layouts(This,retval)	\
    ( (This)->lpVtbl -> get_Layouts(This,retval) ) 

#define IAcadDocument_get_PlotConfigurations(This,retval)	\
    ( (This)->lpVtbl -> get_PlotConfigurations(This,retval) ) 

#define IAcadDocument_get_Preferences(This,retval)	\
    ( (This)->lpVtbl -> get_Preferences(This,retval) ) 

#define IAcadDocument_get_FileDependencies(This,retval)	\
    ( (This)->lpVtbl -> get_FileDependencies(This,retval) ) 

#define IAcadDocument_get_SummaryInfo(This,retval)	\
    ( (This)->lpVtbl -> get_SummaryInfo(This,retval) ) 

#define IAcadDocument_get_SectionManager(This,retval)	\
    ( (This)->lpVtbl -> get_SectionManager(This,retval) ) 

#define IAcadDocument_get_Materials(This,retval)	\
    ( (This)->lpVtbl -> get_Materials(This,retval) ) 

#define IAcadDocument_ObjectIdToObject32(This,ObjectID,retval)	\
    ( (This)->lpVtbl -> ObjectIdToObject32(This,ObjectID,retval) ) 


#define IAcadDocument_get_Plot(This,pPlot)	\
    ( (This)->lpVtbl -> get_Plot(This,pPlot) ) 

#define IAcadDocument_get_ActiveLayer(This,pActLayer)	\
    ( (This)->lpVtbl -> get_ActiveLayer(This,pActLayer) ) 

#define IAcadDocument_put_ActiveLayer(This,pActLayer)	\
    ( (This)->lpVtbl -> put_ActiveLayer(This,pActLayer) ) 

#define IAcadDocument_get_ActiveLinetype(This,pActLinetype)	\
    ( (This)->lpVtbl -> get_ActiveLinetype(This,pActLinetype) ) 

#define IAcadDocument_put_ActiveLinetype(This,pActLinetype)	\
    ( (This)->lpVtbl -> put_ActiveLinetype(This,pActLinetype) ) 

#define IAcadDocument_get_ActiveDimStyle(This,pActDimStyle)	\
    ( (This)->lpVtbl -> get_ActiveDimStyle(This,pActDimStyle) ) 

#define IAcadDocument_put_ActiveDimStyle(This,pActDimStyle)	\
    ( (This)->lpVtbl -> put_ActiveDimStyle(This,pActDimStyle) ) 

#define IAcadDocument_get_ActiveTextStyle(This,pActTextStyle)	\
    ( (This)->lpVtbl -> get_ActiveTextStyle(This,pActTextStyle) ) 

#define IAcadDocument_put_ActiveTextStyle(This,pActTextStyle)	\
    ( (This)->lpVtbl -> put_ActiveTextStyle(This,pActTextStyle) ) 

#define IAcadDocument_get_ActiveUCS(This,pActUCS)	\
    ( (This)->lpVtbl -> get_ActiveUCS(This,pActUCS) ) 

#define IAcadDocument_put_ActiveUCS(This,pActUCS)	\
    ( (This)->lpVtbl -> put_ActiveUCS(This,pActUCS) ) 

#define IAcadDocument_get_ActiveViewport(This,pActView)	\
    ( (This)->lpVtbl -> get_ActiveViewport(This,pActView) ) 

#define IAcadDocument_put_ActiveViewport(This,pActView)	\
    ( (This)->lpVtbl -> put_ActiveViewport(This,pActView) ) 

#define IAcadDocument_get_ActivePViewport(This,pActView)	\
    ( (This)->lpVtbl -> get_ActivePViewport(This,pActView) ) 

#define IAcadDocument_put_ActivePViewport(This,pActView)	\
    ( (This)->lpVtbl -> put_ActivePViewport(This,pActView) ) 

#define IAcadDocument_get_ActiveSpace(This,ActSpace)	\
    ( (This)->lpVtbl -> get_ActiveSpace(This,ActSpace) ) 

#define IAcadDocument_put_ActiveSpace(This,ActSpace)	\
    ( (This)->lpVtbl -> put_ActiveSpace(This,ActSpace) ) 

#define IAcadDocument_get_SelectionSets(This,pSelSets)	\
    ( (This)->lpVtbl -> get_SelectionSets(This,pSelSets) ) 

#define IAcadDocument_get_ActiveSelectionSet(This,pSelSet)	\
    ( (This)->lpVtbl -> get_ActiveSelectionSet(This,pSelSet) ) 

#define IAcadDocument_get_FullName(This,FullName)	\
    ( (This)->lpVtbl -> get_FullName(This,FullName) ) 

#define IAcadDocument_get_Name(This,Name)	\
    ( (This)->lpVtbl -> get_Name(This,Name) ) 

#define IAcadDocument_get_Path(This,Path)	\
    ( (This)->lpVtbl -> get_Path(This,Path) ) 

#define IAcadDocument_get_ObjectSnapMode(This,fSnapMode)	\
    ( (This)->lpVtbl -> get_ObjectSnapMode(This,fSnapMode) ) 

#define IAcadDocument_put_ObjectSnapMode(This,fSnapMode)	\
    ( (This)->lpVtbl -> put_ObjectSnapMode(This,fSnapMode) ) 

#define IAcadDocument_get_ReadOnly(This,bReadOnly)	\
    ( (This)->lpVtbl -> get_ReadOnly(This,bReadOnly) ) 

#define IAcadDocument_get_Saved(This,bSaved)	\
    ( (This)->lpVtbl -> get_Saved(This,bSaved) ) 

#define IAcadDocument_get_MSpace(This,Mode)	\
    ( (This)->lpVtbl -> get_MSpace(This,Mode) ) 

#define IAcadDocument_put_MSpace(This,Mode)	\
    ( (This)->lpVtbl -> put_MSpace(This,Mode) ) 

#define IAcadDocument_get_Utility(This,pUtil)	\
    ( (This)->lpVtbl -> get_Utility(This,pUtil) ) 

#define IAcadDocument_Open(This,FullName,Password,pDocObj)	\
    ( (This)->lpVtbl -> Open(This,FullName,Password,pDocObj) ) 

#define IAcadDocument_AuditInfo(This,FixErr)	\
    ( (This)->lpVtbl -> AuditInfo(This,FixErr) ) 

#define IAcadDocument_Import(This,FileName,InsertionPoint,ScaleFactor,pObj)	\
    ( (This)->lpVtbl -> Import(This,FileName,InsertionPoint,ScaleFactor,pObj) ) 

#define IAcadDocument_Export(This,FileName,Extension,SelectionSet)	\
    ( (This)->lpVtbl -> Export(This,FileName,Extension,SelectionSet) ) 

#define IAcadDocument_New(This,TemplateFileName,pDocObj)	\
    ( (This)->lpVtbl -> New(This,TemplateFileName,pDocObj) ) 

#define IAcadDocument_Save(This)	\
    ( (This)->lpVtbl -> Save(This) ) 

#define IAcadDocument_SaveAs(This,FullFileName,SaveAsType,vSecurityParams)	\
    ( (This)->lpVtbl -> SaveAs(This,FullFileName,SaveAsType,vSecurityParams) ) 

#define IAcadDocument_Wblock(This,FileName,SelectionSet)	\
    ( (This)->lpVtbl -> Wblock(This,FileName,SelectionSet) ) 

#define IAcadDocument_PurgeAll(This)	\
    ( (This)->lpVtbl -> PurgeAll(This) ) 

#define IAcadDocument_GetVariable(This,Name,Value)	\
    ( (This)->lpVtbl -> GetVariable(This,Name,Value) ) 

#define IAcadDocument_SetVariable(This,Name,Value)	\
    ( (This)->lpVtbl -> SetVariable(This,Name,Value) ) 

#define IAcadDocument_LoadShapeFile(This,FullName)	\
    ( (This)->lpVtbl -> LoadShapeFile(This,FullName) ) 

#define IAcadDocument_Regen(This,WhichViewports)	\
    ( (This)->lpVtbl -> Regen(This,WhichViewports) ) 

#define IAcadDocument_get_PickfirstSelectionSet(This,pSelSet)	\
    ( (This)->lpVtbl -> get_PickfirstSelectionSet(This,pSelSet) ) 

#define IAcadDocument_get_Active(This,pvbActive)	\
    ( (This)->lpVtbl -> get_Active(This,pvbActive) ) 

#define IAcadDocument_Activate(This)	\
    ( (This)->lpVtbl -> Activate(This) ) 

#define IAcadDocument_Close(This,SaveChanges,FileName)	\
    ( (This)->lpVtbl -> Close(This,SaveChanges,FileName) ) 

#define IAcadDocument_put_WindowState(This,pWinState)	\
    ( (This)->lpVtbl -> put_WindowState(This,pWinState) ) 

#define IAcadDocument_get_WindowState(This,pWinState)	\
    ( (This)->lpVtbl -> get_WindowState(This,pWinState) ) 

#define IAcadDocument_put_Width(This,pWidth)	\
    ( (This)->lpVtbl -> put_Width(This,pWidth) ) 

#define IAcadDocument_get_Width(This,pWidth)	\
    ( (This)->lpVtbl -> get_Width(This,pWidth) ) 

#define IAcadDocument_put_Height(This,pHeight)	\
    ( (This)->lpVtbl -> put_Height(This,pHeight) ) 

#define IAcadDocument_get_Height(This,pHeight)	\
    ( (This)->lpVtbl -> get_Height(This,pHeight) ) 

#define IAcadDocument_put_ActiveLayout(This,pLayout)	\
    ( (This)->lpVtbl -> put_ActiveLayout(This,pLayout) ) 

#define IAcadDocument_get_ActiveLayout(This,pLayout)	\
    ( (This)->lpVtbl -> get_ActiveLayout(This,pLayout) ) 

#define IAcadDocument_SendCommand(This,Command)	\
    ( (This)->lpVtbl -> SendCommand(This,Command) ) 

#define IAcadDocument_get_HWND(This,hWnd)	\
    ( (This)->lpVtbl -> get_HWND(This,hWnd) ) 

#define IAcadDocument_get_WindowTitle(This,Title)	\
    ( (This)->lpVtbl -> get_WindowTitle(This,Title) ) 

#define IAcadDocument_get_Application(This,pAppObj)	\
    ( (This)->lpVtbl -> get_Application(This,pAppObj) ) 

#define IAcadDocument_get_Database(This,pDatabase)	\
    ( (This)->lpVtbl -> get_Database(This,pDatabase) ) 

#define IAcadDocument_StartUndoMark(This)	\
    ( (This)->lpVtbl -> StartUndoMark(This) ) 

#define IAcadDocument_EndUndoMark(This)	\
    ( (This)->lpVtbl -> EndUndoMark(This) ) 

#define IAcadDocument_getTransmittalOperationInterface(This,ppITrmOp)	\
    ( (This)->lpVtbl -> getTransmittalOperationInterface(This,ppITrmOp) ) 

#define IAcadDocument_EvaluateLisp(This,lispString,pvResult)	\
    ( (This)->lpVtbl -> EvaluateLisp(This,lispString,pvResult) ) 

#define IAcadDocument_get_ActiveMaterial(This,pActMaterial)	\
    ( (This)->lpVtbl -> get_ActiveMaterial(This,pActMaterial) ) 

#define IAcadDocument_put_ActiveMaterial(This,pActMaterial)	\
    ( (This)->lpVtbl -> put_ActiveMaterial(This,pActMaterial) ) 

#define IAcadDocument_get_NumTransactions(This,pNumTransactions)	\
    ( (This)->lpVtbl -> get_NumTransactions(This,pNumTransactions) ) 

#define IAcadDocument_StartTransaction(This)	\
    ( (This)->lpVtbl -> StartTransaction(This) ) 

#define IAcadDocument_EndTransaction(This)	\
    ( (This)->lpVtbl -> EndTransaction(This) ) 

#define IAcadDocument_AbortTransaction(This)	\
    ( (This)->lpVtbl -> AbortTransaction(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAcadDocument_INTERFACE_DEFINED__ */


#ifndef __IAcadDocuments_INTERFACE_DEFINED__
#define __IAcadDocuments_INTERFACE_DEFINED__

/* interface IAcadDocuments */
/* [oleautomation][dual][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IAcadDocuments;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("CFFD1390-466A-49d9-9EE0-1884E930DFF9")
    IAcadDocuments : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Item( 
            /* [in] */ VARIANT Index,
            /* [retval][out] */ IAcadDocument **pItem) = 0;
        
        virtual /* [hidden][restricted][propget][id] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ IUnknown **pEnumVariant) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long *Count) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Application( 
            /* [retval][out] */ IAcadApplication **pAppObj) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [optional][in] */ VARIANT TemplateName,
            /* [retval][out] */ IAcadDocument **pDispDoc) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Open( 
            /* [in] */ BSTR Name,
            /* [optional][in] */ VARIANT ReadOnly,
            /* [optional][in] */ VARIANT Password,
            /* [retval][out] */ IAcadDocument **pDispDoc) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Close( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAcadDocumentsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAcadDocuments * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAcadDocuments * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAcadDocuments * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IAcadDocuments * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IAcadDocuments * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IAcadDocuments * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IAcadDocuments * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Item )( 
            IAcadDocuments * This,
            /* [in] */ VARIANT Index,
            /* [retval][out] */ IAcadDocument **pItem);
        
        /* [hidden][restricted][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            IAcadDocuments * This,
            /* [retval][out] */ IUnknown **pEnumVariant);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IAcadDocuments * This,
            /* [retval][out] */ long *Count);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Application )( 
            IAcadDocuments * This,
            /* [retval][out] */ IAcadApplication **pAppObj);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Add )( 
            IAcadDocuments * This,
            /* [optional][in] */ VARIANT TemplateName,
            /* [retval][out] */ IAcadDocument **pDispDoc);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Open )( 
            IAcadDocuments * This,
            /* [in] */ BSTR Name,
            /* [optional][in] */ VARIANT ReadOnly,
            /* [optional][in] */ VARIANT Password,
            /* [retval][out] */ IAcadDocument **pDispDoc);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Close )( 
            IAcadDocuments * This);
        
        END_INTERFACE
    } IAcadDocumentsVtbl;

    interface IAcadDocuments
    {
        CONST_VTBL struct IAcadDocumentsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAcadDocuments_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAcadDocuments_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAcadDocuments_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAcadDocuments_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IAcadDocuments_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IAcadDocuments_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IAcadDocuments_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IAcadDocuments_Item(This,Index,pItem)	\
    ( (This)->lpVtbl -> Item(This,Index,pItem) ) 

#define IAcadDocuments_get__NewEnum(This,pEnumVariant)	\
    ( (This)->lpVtbl -> get__NewEnum(This,pEnumVariant) ) 

#define IAcadDocuments_get_Count(This,Count)	\
    ( (This)->lpVtbl -> get_Count(This,Count) ) 

#define IAcadDocuments_get_Application(This,pAppObj)	\
    ( (This)->lpVtbl -> get_Application(This,pAppObj) ) 

#define IAcadDocuments_Add(This,TemplateName,pDispDoc)	\
    ( (This)->lpVtbl -> Add(This,TemplateName,pDispDoc) ) 

#define IAcadDocuments_Open(This,Name,ReadOnly,Password,pDispDoc)	\
    ( (This)->lpVtbl -> Open(This,Name,ReadOnly,Password,pDispDoc) ) 

#define IAcadDocuments_Close(This)	\
    ( (This)->lpVtbl -> Close(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAcadDocuments_INTERFACE_DEFINED__ */


#ifndef __IAcadSelectionSets_INTERFACE_DEFINED__
#define __IAcadSelectionSets_INTERFACE_DEFINED__

/* interface IAcadSelectionSets */
/* [object][oleautomation][dual][helpstring][uuid] */ 


EXTERN_C const IID IID_IAcadSelectionSets;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("37E34D42-8CD8-4e25-83BF-80C791AFEADE")
    IAcadSelectionSets : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Item( 
            /* [in] */ VARIANT Index,
            /* [retval][out] */ IAcadSelectionSet **pItem) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [hidden][restricted][propget][id] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ IUnknown **pVal) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Application( 
            /* [retval][out] */ IAcadApplication **pAppObj) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [in] */ BSTR Name,
            /* [retval][out] */ IAcadSelectionSet **pSet) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAcadSelectionSetsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAcadSelectionSets * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAcadSelectionSets * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAcadSelectionSets * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IAcadSelectionSets * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IAcadSelectionSets * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IAcadSelectionSets * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IAcadSelectionSets * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Item )( 
            IAcadSelectionSets * This,
            /* [in] */ VARIANT Index,
            /* [retval][out] */ IAcadSelectionSet **pItem);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IAcadSelectionSets * This,
            /* [retval][out] */ long *pVal);
        
        /* [hidden][restricted][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            IAcadSelectionSets * This,
            /* [retval][out] */ IUnknown **pVal);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Application )( 
            IAcadSelectionSets * This,
            /* [retval][out] */ IAcadApplication **pAppObj);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Add )( 
            IAcadSelectionSets * This,
            /* [in] */ BSTR Name,
            /* [retval][out] */ IAcadSelectionSet **pSet);
        
        END_INTERFACE
    } IAcadSelectionSetsVtbl;

    interface IAcadSelectionSets
    {
        CONST_VTBL struct IAcadSelectionSetsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAcadSelectionSets_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAcadSelectionSets_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAcadSelectionSets_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAcadSelectionSets_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IAcadSelectionSets_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IAcadSelectionSets_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IAcadSelectionSets_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IAcadSelectionSets_Item(This,Index,pItem)	\
    ( (This)->lpVtbl -> Item(This,Index,pItem) ) 

#define IAcadSelectionSets_get_Count(This,pVal)	\
    ( (This)->lpVtbl -> get_Count(This,pVal) ) 

#define IAcadSelectionSets_get__NewEnum(This,pVal)	\
    ( (This)->lpVtbl -> get__NewEnum(This,pVal) ) 

#define IAcadSelectionSets_get_Application(This,pAppObj)	\
    ( (This)->lpVtbl -> get_Application(This,pAppObj) ) 

#define IAcadSelectionSets_Add(This,Name,pSet)	\
    ( (This)->lpVtbl -> Add(This,Name,pSet) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAcadSelectionSets_INTERFACE_DEFINED__ */


#ifndef __IAcadSelectionSet_INTERFACE_DEFINED__
#define __IAcadSelectionSet_INTERFACE_DEFINED__

/* interface IAcadSelectionSet */
/* [object][oleautomation][dual][helpstring][uuid] */ 


EXTERN_C const IID IID_IAcadSelectionSet;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("01374CB7-5D3B-4556-800C-9BFC71BBEC42")
    IAcadSelectionSet : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Item( 
            /* [in] */ VARIANT Index,
            /* [retval][out] */ /* external definition not present */ IAcadEntity **pEntity) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [hidden][restricted][propget][id] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ IUnknown **pVal) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *bstrName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Highlight( 
            /* [in] */ VARIANT_BOOL bFlag) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Erase( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Update( void) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Application( 
            /* [retval][out] */ IAcadApplication **pAppObj) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddItems( 
            /* [in] */ VARIANT pSelSet) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RemoveItems( 
            /* [in] */ VARIANT Objects) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Clear( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Select( 
            /* [in] */ enum /* external definition not present */ AcSelect Mode,
            /* [optional][in] */ VARIANT Point1,
            /* [optional][in] */ VARIANT Point2,
            /* [optional][in] */ VARIANT FilterType,
            /* [optional][in] */ VARIANT FilterData) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SelectAtPoint( 
            /* [in] */ VARIANT Point,
            /* [optional][in] */ VARIANT FilterType,
            /* [optional][in] */ VARIANT FilterData) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SelectByPolygon( 
            /* [in] */ enum /* external definition not present */ AcSelect Mode,
            /* [in] */ VARIANT PointsList,
            /* [optional][in] */ VARIANT FilterType,
            /* [optional][in] */ VARIANT FilterData) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SelectOnScreen( 
            /* [optional][in] */ VARIANT FilterType,
            /* [optional][in] */ VARIANT FilterData) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Delete( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAcadSelectionSetVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAcadSelectionSet * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAcadSelectionSet * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAcadSelectionSet * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IAcadSelectionSet * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IAcadSelectionSet * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IAcadSelectionSet * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IAcadSelectionSet * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Item )( 
            IAcadSelectionSet * This,
            /* [in] */ VARIANT Index,
            /* [retval][out] */ /* external definition not present */ IAcadEntity **pEntity);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IAcadSelectionSet * This,
            /* [retval][out] */ long *pVal);
        
        /* [hidden][restricted][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            IAcadSelectionSet * This,
            /* [retval][out] */ IUnknown **pVal);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IAcadSelectionSet * This,
            /* [retval][out] */ BSTR *bstrName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Highlight )( 
            IAcadSelectionSet * This,
            /* [in] */ VARIANT_BOOL bFlag);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Erase )( 
            IAcadSelectionSet * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Update )( 
            IAcadSelectionSet * This);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Application )( 
            IAcadSelectionSet * This,
            /* [retval][out] */ IAcadApplication **pAppObj);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddItems )( 
            IAcadSelectionSet * This,
            /* [in] */ VARIANT pSelSet);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RemoveItems )( 
            IAcadSelectionSet * This,
            /* [in] */ VARIANT Objects);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Clear )( 
            IAcadSelectionSet * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Select )( 
            IAcadSelectionSet * This,
            /* [in] */ enum /* external definition not present */ AcSelect Mode,
            /* [optional][in] */ VARIANT Point1,
            /* [optional][in] */ VARIANT Point2,
            /* [optional][in] */ VARIANT FilterType,
            /* [optional][in] */ VARIANT FilterData);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SelectAtPoint )( 
            IAcadSelectionSet * This,
            /* [in] */ VARIANT Point,
            /* [optional][in] */ VARIANT FilterType,
            /* [optional][in] */ VARIANT FilterData);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SelectByPolygon )( 
            IAcadSelectionSet * This,
            /* [in] */ enum /* external definition not present */ AcSelect Mode,
            /* [in] */ VARIANT PointsList,
            /* [optional][in] */ VARIANT FilterType,
            /* [optional][in] */ VARIANT FilterData);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SelectOnScreen )( 
            IAcadSelectionSet * This,
            /* [optional][in] */ VARIANT FilterType,
            /* [optional][in] */ VARIANT FilterData);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IAcadSelectionSet * This);
        
        END_INTERFACE
    } IAcadSelectionSetVtbl;

    interface IAcadSelectionSet
    {
        CONST_VTBL struct IAcadSelectionSetVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAcadSelectionSet_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAcadSelectionSet_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAcadSelectionSet_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAcadSelectionSet_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IAcadSelectionSet_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IAcadSelectionSet_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IAcadSelectionSet_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IAcadSelectionSet_Item(This,Index,pEntity)	\
    ( (This)->lpVtbl -> Item(This,Index,pEntity) ) 

#define IAcadSelectionSet_get_Count(This,pVal)	\
    ( (This)->lpVtbl -> get_Count(This,pVal) ) 

#define IAcadSelectionSet_get__NewEnum(This,pVal)	\
    ( (This)->lpVtbl -> get__NewEnum(This,pVal) ) 

#define IAcadSelectionSet_get_Name(This,bstrName)	\
    ( (This)->lpVtbl -> get_Name(This,bstrName) ) 

#define IAcadSelectionSet_Highlight(This,bFlag)	\
    ( (This)->lpVtbl -> Highlight(This,bFlag) ) 

#define IAcadSelectionSet_Erase(This)	\
    ( (This)->lpVtbl -> Erase(This) ) 

#define IAcadSelectionSet_Update(This)	\
    ( (This)->lpVtbl -> Update(This) ) 

#define IAcadSelectionSet_get_Application(This,pAppObj)	\
    ( (This)->lpVtbl -> get_Application(This,pAppObj) ) 

#define IAcadSelectionSet_AddItems(This,pSelSet)	\
    ( (This)->lpVtbl -> AddItems(This,pSelSet) ) 

#define IAcadSelectionSet_RemoveItems(This,Objects)	\
    ( (This)->lpVtbl -> RemoveItems(This,Objects) ) 

#define IAcadSelectionSet_Clear(This)	\
    ( (This)->lpVtbl -> Clear(This) ) 

#define IAcadSelectionSet_Select(This,Mode,Point1,Point2,FilterType,FilterData)	\
    ( (This)->lpVtbl -> Select(This,Mode,Point1,Point2,FilterType,FilterData) ) 

#define IAcadSelectionSet_SelectAtPoint(This,Point,FilterType,FilterData)	\
    ( (This)->lpVtbl -> SelectAtPoint(This,Point,FilterType,FilterData) ) 

#define IAcadSelectionSet_SelectByPolygon(This,Mode,PointsList,FilterType,FilterData)	\
    ( (This)->lpVtbl -> SelectByPolygon(This,Mode,PointsList,FilterType,FilterData) ) 

#define IAcadSelectionSet_SelectOnScreen(This,FilterType,FilterData)	\
    ( (This)->lpVtbl -> SelectOnScreen(This,FilterType,FilterData) ) 

#define IAcadSelectionSet_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAcadSelectionSet_INTERFACE_DEFINED__ */


#ifndef __IAcadPreferences_INTERFACE_DEFINED__
#define __IAcadPreferences_INTERFACE_DEFINED__

/* interface IAcadPreferences */
/* [object][oleautomation][dual][helpstring][uuid] */ 


EXTERN_C const IID IID_IAcadPreferences;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("03CE46C1-93A9-4e5c-B7F5-7AC7E2D48948")
    IAcadPreferences : public IDispatch
    {
    public:
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Application( 
            /* [retval][out] */ IAcadApplication **pAppObj) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Files( 
            /* [retval][out] */ IAcadPreferencesFiles **pObj) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Display( 
            /* [retval][out] */ IAcadPreferencesDisplay **pObj) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_OpenSave( 
            /* [retval][out] */ IAcadPreferencesOpenSave **pObj) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Output( 
            /* [retval][out] */ IAcadPreferencesOutput **pObj) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_System( 
            /* [retval][out] */ IAcadPreferencesSystem **pObj) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_User( 
            /* [retval][out] */ IAcadPreferencesUser **pObj) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Drafting( 
            /* [retval][out] */ IAcadPreferencesDrafting **pObj) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Selection( 
            /* [retval][out] */ IAcadPreferencesSelection **pObj) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Profiles( 
            /* [retval][out] */ IAcadPreferencesProfiles **pObj) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAcadPreferencesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAcadPreferences * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAcadPreferences * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAcadPreferences * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IAcadPreferences * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IAcadPreferences * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IAcadPreferences * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IAcadPreferences * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Application )( 
            IAcadPreferences * This,
            /* [retval][out] */ IAcadApplication **pAppObj);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Files )( 
            IAcadPreferences * This,
            /* [retval][out] */ IAcadPreferencesFiles **pObj);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Display )( 
            IAcadPreferences * This,
            /* [retval][out] */ IAcadPreferencesDisplay **pObj);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_OpenSave )( 
            IAcadPreferences * This,
            /* [retval][out] */ IAcadPreferencesOpenSave **pObj);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Output )( 
            IAcadPreferences * This,
            /* [retval][out] */ IAcadPreferencesOutput **pObj);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_System )( 
            IAcadPreferences * This,
            /* [retval][out] */ IAcadPreferencesSystem **pObj);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_User )( 
            IAcadPreferences * This,
            /* [retval][out] */ IAcadPreferencesUser **pObj);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Drafting )( 
            IAcadPreferences * This,
            /* [retval][out] */ IAcadPreferencesDrafting **pObj);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Selection )( 
            IAcadPreferences * This,
            /* [retval][out] */ IAcadPreferencesSelection **pObj);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Profiles )( 
            IAcadPreferences * This,
            /* [retval][out] */ IAcadPreferencesProfiles **pObj);
        
        END_INTERFACE
    } IAcadPreferencesVtbl;

    interface IAcadPreferences
    {
        CONST_VTBL struct IAcadPreferencesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAcadPreferences_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAcadPreferences_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAcadPreferences_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAcadPreferences_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IAcadPreferences_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IAcadPreferences_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IAcadPreferences_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IAcadPreferences_get_Application(This,pAppObj)	\
    ( (This)->lpVtbl -> get_Application(This,pAppObj) ) 

#define IAcadPreferences_get_Files(This,pObj)	\
    ( (This)->lpVtbl -> get_Files(This,pObj) ) 

#define IAcadPreferences_get_Display(This,pObj)	\
    ( (This)->lpVtbl -> get_Display(This,pObj) ) 

#define IAcadPreferences_get_OpenSave(This,pObj)	\
    ( (This)->lpVtbl -> get_OpenSave(This,pObj) ) 

#define IAcadPreferences_get_Output(This,pObj)	\
    ( (This)->lpVtbl -> get_Output(This,pObj) ) 

#define IAcadPreferences_get_System(This,pObj)	\
    ( (This)->lpVtbl -> get_System(This,pObj) ) 

#define IAcadPreferences_get_User(This,pObj)	\
    ( (This)->lpVtbl -> get_User(This,pObj) ) 

#define IAcadPreferences_get_Drafting(This,pObj)	\
    ( (This)->lpVtbl -> get_Drafting(This,pObj) ) 

#define IAcadPreferences_get_Selection(This,pObj)	\
    ( (This)->lpVtbl -> get_Selection(This,pObj) ) 

#define IAcadPreferences_get_Profiles(This,pObj)	\
    ( (This)->lpVtbl -> get_Profiles(This,pObj) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAcadPreferences_INTERFACE_DEFINED__ */


#ifndef __IAcadPreferencesFiles_INTERFACE_DEFINED__
#define __IAcadPreferencesFiles_INTERFACE_DEFINED__

/* interface IAcadPreferencesFiles */
/* [object][oleautomation][dual][helpstring][uuid] */ 


EXTERN_C const IID IID_IAcadPreferencesFiles;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("125FA500-9ABC-4f98-87AD-869AEFA4AD72")
    IAcadPreferencesFiles : public IDispatch
    {
    public:
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Application( 
            /* [retval][out] */ IAcadApplication **pAppObj) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_SupportPath( 
            /* [in] */ BSTR orient) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_SupportPath( 
            /* [retval][out] */ BSTR *orient) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_DriversPath( 
            /* [in] */ BSTR Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_DriversPath( 
            /* [retval][out] */ BSTR *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_MenuFile( 
            /* [in] */ BSTR Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_MenuFile( 
            /* [retval][out] */ BSTR *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_HelpFilePath( 
            /* [in] */ BSTR Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_HelpFilePath( 
            /* [retval][out] */ BSTR *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_DefaultInternetURL( 
            /* [in] */ BSTR Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_DefaultInternetURL( 
            /* [retval][out] */ BSTR *Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ConfigFile( 
            /* [retval][out] */ BSTR *ConfigFile) = 0;
        
        virtual /* [helpstring][hidden][propget][id] */ HRESULT STDMETHODCALLTYPE get_LicenseServer( 
            /* [retval][out] */ BSTR *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_TextEditor( 
            /* [in] */ BSTR Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_TextEditor( 
            /* [retval][out] */ BSTR *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_MainDictionary( 
            /* [in] */ BSTR Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_MainDictionary( 
            /* [retval][out] */ BSTR *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_CustomDictionary( 
            /* [in] */ BSTR Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_CustomDictionary( 
            /* [retval][out] */ BSTR *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_AltFontFile( 
            /* [in] */ BSTR fontFile) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_AltFontFile( 
            /* [retval][out] */ BSTR *fontFile) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_FontFileMap( 
            /* [in] */ BSTR Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_FontFileMap( 
            /* [retval][out] */ BSTR *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_PrintFile( 
            /* [in] */ BSTR Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_PrintFile( 
            /* [retval][out] */ BSTR *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_PrintSpoolExecutable( 
            /* [in] */ BSTR Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_PrintSpoolExecutable( 
            /* [retval][out] */ BSTR *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_PostScriptPrologFile( 
            /* [in] */ BSTR Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_PostScriptPrologFile( 
            /* [retval][out] */ BSTR *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_PrintSpoolerPath( 
            /* [in] */ BSTR Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_PrintSpoolerPath( 
            /* [retval][out] */ BSTR *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_AutoSavePath( 
            /* [in] */ BSTR AutoSavePath) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_AutoSavePath( 
            /* [retval][out] */ BSTR *AutoSavePath) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_TemplateDwgPath( 
            /* [in] */ BSTR Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_TemplateDwgPath( 
            /* [retval][out] */ BSTR *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_LogFilePath( 
            /* [in] */ BSTR Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_LogFilePath( 
            /* [retval][out] */ BSTR *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_TempFilePath( 
            /* [in] */ BSTR Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_TempFilePath( 
            /* [retval][out] */ BSTR *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_TempXrefPath( 
            /* [in] */ BSTR Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_TempXrefPath( 
            /* [retval][out] */ BSTR *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_TextureMapPath( 
            /* [in] */ BSTR Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_TextureMapPath( 
            /* [retval][out] */ BSTR *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_AltTabletMenuFile( 
            /* [in] */ BSTR MenuFile) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_AltTabletMenuFile( 
            /* [retval][out] */ BSTR *MenuFile) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetProjectFilePath( 
            /* [in] */ BSTR ProjectName,
            /* [in] */ BSTR ProjectFilePath) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetProjectFilePath( 
            /* [in] */ BSTR ProjectName,
            /* [retval][out] */ BSTR *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_PrinterConfigPath( 
            /* [in] */ BSTR Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_PrinterConfigPath( 
            /* [retval][out] */ BSTR *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_PrinterDescPath( 
            /* [in] */ BSTR Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_PrinterDescPath( 
            /* [retval][out] */ BSTR *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_PrinterStyleSheetPath( 
            /* [in] */ BSTR Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_PrinterStyleSheetPath( 
            /* [retval][out] */ BSTR *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_WorkspacePath( 
            /* [in] */ BSTR Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_WorkspacePath( 
            /* [retval][out] */ BSTR *Path) = 0;
        
        virtual /* [helpstring][hidden][propput][id] */ HRESULT STDMETHODCALLTYPE put_ObjectARXPath( 
            /* [in] */ BSTR Path) = 0;
        
        virtual /* [helpstring][hidden][propget][id] */ HRESULT STDMETHODCALLTYPE get_ObjectARXPath( 
            /* [retval][out] */ BSTR *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_ColorBookPath( 
            /* [in] */ BSTR Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ColorBookPath( 
            /* [retval][out] */ BSTR *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_ToolPalettePath( 
            /* [in] */ BSTR Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ToolPalettePath( 
            /* [retval][out] */ BSTR *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_QNewTemplateFile( 
            /* [in] */ BSTR Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_QNewTemplateFile( 
            /* [retval][out] */ BSTR *Path) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAcadPreferencesFilesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAcadPreferencesFiles * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAcadPreferencesFiles * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAcadPreferencesFiles * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IAcadPreferencesFiles * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IAcadPreferencesFiles * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IAcadPreferencesFiles * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IAcadPreferencesFiles * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Application )( 
            IAcadPreferencesFiles * This,
            /* [retval][out] */ IAcadApplication **pAppObj);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_SupportPath )( 
            IAcadPreferencesFiles * This,
            /* [in] */ BSTR orient);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_SupportPath )( 
            IAcadPreferencesFiles * This,
            /* [retval][out] */ BSTR *orient);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_DriversPath )( 
            IAcadPreferencesFiles * This,
            /* [in] */ BSTR Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_DriversPath )( 
            IAcadPreferencesFiles * This,
            /* [retval][out] */ BSTR *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_MenuFile )( 
            IAcadPreferencesFiles * This,
            /* [in] */ BSTR Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_MenuFile )( 
            IAcadPreferencesFiles * This,
            /* [retval][out] */ BSTR *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_HelpFilePath )( 
            IAcadPreferencesFiles * This,
            /* [in] */ BSTR Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_HelpFilePath )( 
            IAcadPreferencesFiles * This,
            /* [retval][out] */ BSTR *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultInternetURL )( 
            IAcadPreferencesFiles * This,
            /* [in] */ BSTR Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultInternetURL )( 
            IAcadPreferencesFiles * This,
            /* [retval][out] */ BSTR *Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ConfigFile )( 
            IAcadPreferencesFiles * This,
            /* [retval][out] */ BSTR *ConfigFile);
        
        /* [helpstring][hidden][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_LicenseServer )( 
            IAcadPreferencesFiles * This,
            /* [retval][out] */ BSTR *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_TextEditor )( 
            IAcadPreferencesFiles * This,
            /* [in] */ BSTR Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_TextEditor )( 
            IAcadPreferencesFiles * This,
            /* [retval][out] */ BSTR *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_MainDictionary )( 
            IAcadPreferencesFiles * This,
            /* [in] */ BSTR Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_MainDictionary )( 
            IAcadPreferencesFiles * This,
            /* [retval][out] */ BSTR *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_CustomDictionary )( 
            IAcadPreferencesFiles * This,
            /* [in] */ BSTR Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_CustomDictionary )( 
            IAcadPreferencesFiles * This,
            /* [retval][out] */ BSTR *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_AltFontFile )( 
            IAcadPreferencesFiles * This,
            /* [in] */ BSTR fontFile);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_AltFontFile )( 
            IAcadPreferencesFiles * This,
            /* [retval][out] */ BSTR *fontFile);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_FontFileMap )( 
            IAcadPreferencesFiles * This,
            /* [in] */ BSTR Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_FontFileMap )( 
            IAcadPreferencesFiles * This,
            /* [retval][out] */ BSTR *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_PrintFile )( 
            IAcadPreferencesFiles * This,
            /* [in] */ BSTR Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_PrintFile )( 
            IAcadPreferencesFiles * This,
            /* [retval][out] */ BSTR *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_PrintSpoolExecutable )( 
            IAcadPreferencesFiles * This,
            /* [in] */ BSTR Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_PrintSpoolExecutable )( 
            IAcadPreferencesFiles * This,
            /* [retval][out] */ BSTR *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_PostScriptPrologFile )( 
            IAcadPreferencesFiles * This,
            /* [in] */ BSTR Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_PostScriptPrologFile )( 
            IAcadPreferencesFiles * This,
            /* [retval][out] */ BSTR *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_PrintSpoolerPath )( 
            IAcadPreferencesFiles * This,
            /* [in] */ BSTR Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_PrintSpoolerPath )( 
            IAcadPreferencesFiles * This,
            /* [retval][out] */ BSTR *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_AutoSavePath )( 
            IAcadPreferencesFiles * This,
            /* [in] */ BSTR AutoSavePath);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_AutoSavePath )( 
            IAcadPreferencesFiles * This,
            /* [retval][out] */ BSTR *AutoSavePath);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_TemplateDwgPath )( 
            IAcadPreferencesFiles * This,
            /* [in] */ BSTR Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_TemplateDwgPath )( 
            IAcadPreferencesFiles * This,
            /* [retval][out] */ BSTR *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_LogFilePath )( 
            IAcadPreferencesFiles * This,
            /* [in] */ BSTR Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_LogFilePath )( 
            IAcadPreferencesFiles * This,
            /* [retval][out] */ BSTR *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_TempFilePath )( 
            IAcadPreferencesFiles * This,
            /* [in] */ BSTR Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_TempFilePath )( 
            IAcadPreferencesFiles * This,
            /* [retval][out] */ BSTR *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_TempXrefPath )( 
            IAcadPreferencesFiles * This,
            /* [in] */ BSTR Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_TempXrefPath )( 
            IAcadPreferencesFiles * This,
            /* [retval][out] */ BSTR *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_TextureMapPath )( 
            IAcadPreferencesFiles * This,
            /* [in] */ BSTR Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_TextureMapPath )( 
            IAcadPreferencesFiles * This,
            /* [retval][out] */ BSTR *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_AltTabletMenuFile )( 
            IAcadPreferencesFiles * This,
            /* [in] */ BSTR MenuFile);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_AltTabletMenuFile )( 
            IAcadPreferencesFiles * This,
            /* [retval][out] */ BSTR *MenuFile);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetProjectFilePath )( 
            IAcadPreferencesFiles * This,
            /* [in] */ BSTR ProjectName,
            /* [in] */ BSTR ProjectFilePath);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetProjectFilePath )( 
            IAcadPreferencesFiles * This,
            /* [in] */ BSTR ProjectName,
            /* [retval][out] */ BSTR *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_PrinterConfigPath )( 
            IAcadPreferencesFiles * This,
            /* [in] */ BSTR Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_PrinterConfigPath )( 
            IAcadPreferencesFiles * This,
            /* [retval][out] */ BSTR *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_PrinterDescPath )( 
            IAcadPreferencesFiles * This,
            /* [in] */ BSTR Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_PrinterDescPath )( 
            IAcadPreferencesFiles * This,
            /* [retval][out] */ BSTR *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_PrinterStyleSheetPath )( 
            IAcadPreferencesFiles * This,
            /* [in] */ BSTR Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_PrinterStyleSheetPath )( 
            IAcadPreferencesFiles * This,
            /* [retval][out] */ BSTR *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_WorkspacePath )( 
            IAcadPreferencesFiles * This,
            /* [in] */ BSTR Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_WorkspacePath )( 
            IAcadPreferencesFiles * This,
            /* [retval][out] */ BSTR *Path);
        
        /* [helpstring][hidden][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_ObjectARXPath )( 
            IAcadPreferencesFiles * This,
            /* [in] */ BSTR Path);
        
        /* [helpstring][hidden][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ObjectARXPath )( 
            IAcadPreferencesFiles * This,
            /* [retval][out] */ BSTR *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_ColorBookPath )( 
            IAcadPreferencesFiles * This,
            /* [in] */ BSTR Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ColorBookPath )( 
            IAcadPreferencesFiles * This,
            /* [retval][out] */ BSTR *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_ToolPalettePath )( 
            IAcadPreferencesFiles * This,
            /* [in] */ BSTR Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ToolPalettePath )( 
            IAcadPreferencesFiles * This,
            /* [retval][out] */ BSTR *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_QNewTemplateFile )( 
            IAcadPreferencesFiles * This,
            /* [in] */ BSTR Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_QNewTemplateFile )( 
            IAcadPreferencesFiles * This,
            /* [retval][out] */ BSTR *Path);
        
        END_INTERFACE
    } IAcadPreferencesFilesVtbl;

    interface IAcadPreferencesFiles
    {
        CONST_VTBL struct IAcadPreferencesFilesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAcadPreferencesFiles_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAcadPreferencesFiles_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAcadPreferencesFiles_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAcadPreferencesFiles_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IAcadPreferencesFiles_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IAcadPreferencesFiles_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IAcadPreferencesFiles_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IAcadPreferencesFiles_get_Application(This,pAppObj)	\
    ( (This)->lpVtbl -> get_Application(This,pAppObj) ) 

#define IAcadPreferencesFiles_put_SupportPath(This,orient)	\
    ( (This)->lpVtbl -> put_SupportPath(This,orient) ) 

#define IAcadPreferencesFiles_get_SupportPath(This,orient)	\
    ( (This)->lpVtbl -> get_SupportPath(This,orient) ) 

#define IAcadPreferencesFiles_put_DriversPath(This,Path)	\
    ( (This)->lpVtbl -> put_DriversPath(This,Path) ) 

#define IAcadPreferencesFiles_get_DriversPath(This,Path)	\
    ( (This)->lpVtbl -> get_DriversPath(This,Path) ) 

#define IAcadPreferencesFiles_put_MenuFile(This,Path)	\
    ( (This)->lpVtbl -> put_MenuFile(This,Path) ) 

#define IAcadPreferencesFiles_get_MenuFile(This,Path)	\
    ( (This)->lpVtbl -> get_MenuFile(This,Path) ) 

#define IAcadPreferencesFiles_put_HelpFilePath(This,Path)	\
    ( (This)->lpVtbl -> put_HelpFilePath(This,Path) ) 

#define IAcadPreferencesFiles_get_HelpFilePath(This,Path)	\
    ( (This)->lpVtbl -> get_HelpFilePath(This,Path) ) 

#define IAcadPreferencesFiles_put_DefaultInternetURL(This,Path)	\
    ( (This)->lpVtbl -> put_DefaultInternetURL(This,Path) ) 

#define IAcadPreferencesFiles_get_DefaultInternetURL(This,Path)	\
    ( (This)->lpVtbl -> get_DefaultInternetURL(This,Path) ) 

#define IAcadPreferencesFiles_get_ConfigFile(This,ConfigFile)	\
    ( (This)->lpVtbl -> get_ConfigFile(This,ConfigFile) ) 

#define IAcadPreferencesFiles_get_LicenseServer(This,Path)	\
    ( (This)->lpVtbl -> get_LicenseServer(This,Path) ) 

#define IAcadPreferencesFiles_put_TextEditor(This,Path)	\
    ( (This)->lpVtbl -> put_TextEditor(This,Path) ) 

#define IAcadPreferencesFiles_get_TextEditor(This,Path)	\
    ( (This)->lpVtbl -> get_TextEditor(This,Path) ) 

#define IAcadPreferencesFiles_put_MainDictionary(This,Path)	\
    ( (This)->lpVtbl -> put_MainDictionary(This,Path) ) 

#define IAcadPreferencesFiles_get_MainDictionary(This,Path)	\
    ( (This)->lpVtbl -> get_MainDictionary(This,Path) ) 

#define IAcadPreferencesFiles_put_CustomDictionary(This,Path)	\
    ( (This)->lpVtbl -> put_CustomDictionary(This,Path) ) 

#define IAcadPreferencesFiles_get_CustomDictionary(This,Path)	\
    ( (This)->lpVtbl -> get_CustomDictionary(This,Path) ) 

#define IAcadPreferencesFiles_put_AltFontFile(This,fontFile)	\
    ( (This)->lpVtbl -> put_AltFontFile(This,fontFile) ) 

#define IAcadPreferencesFiles_get_AltFontFile(This,fontFile)	\
    ( (This)->lpVtbl -> get_AltFontFile(This,fontFile) ) 

#define IAcadPreferencesFiles_put_FontFileMap(This,Path)	\
    ( (This)->lpVtbl -> put_FontFileMap(This,Path) ) 

#define IAcadPreferencesFiles_get_FontFileMap(This,Path)	\
    ( (This)->lpVtbl -> get_FontFileMap(This,Path) ) 

#define IAcadPreferencesFiles_put_PrintFile(This,Path)	\
    ( (This)->lpVtbl -> put_PrintFile(This,Path) ) 

#define IAcadPreferencesFiles_get_PrintFile(This,Path)	\
    ( (This)->lpVtbl -> get_PrintFile(This,Path) ) 

#define IAcadPreferencesFiles_put_PrintSpoolExecutable(This,Path)	\
    ( (This)->lpVtbl -> put_PrintSpoolExecutable(This,Path) ) 

#define IAcadPreferencesFiles_get_PrintSpoolExecutable(This,Path)	\
    ( (This)->lpVtbl -> get_PrintSpoolExecutable(This,Path) ) 

#define IAcadPreferencesFiles_put_PostScriptPrologFile(This,Path)	\
    ( (This)->lpVtbl -> put_PostScriptPrologFile(This,Path) ) 

#define IAcadPreferencesFiles_get_PostScriptPrologFile(This,Path)	\
    ( (This)->lpVtbl -> get_PostScriptPrologFile(This,Path) ) 

#define IAcadPreferencesFiles_put_PrintSpoolerPath(This,Path)	\
    ( (This)->lpVtbl -> put_PrintSpoolerPath(This,Path) ) 

#define IAcadPreferencesFiles_get_PrintSpoolerPath(This,Path)	\
    ( (This)->lpVtbl -> get_PrintSpoolerPath(This,Path) ) 

#define IAcadPreferencesFiles_put_AutoSavePath(This,AutoSavePath)	\
    ( (This)->lpVtbl -> put_AutoSavePath(This,AutoSavePath) ) 

#define IAcadPreferencesFiles_get_AutoSavePath(This,AutoSavePath)	\
    ( (This)->lpVtbl -> get_AutoSavePath(This,AutoSavePath) ) 

#define IAcadPreferencesFiles_put_TemplateDwgPath(This,Path)	\
    ( (This)->lpVtbl -> put_TemplateDwgPath(This,Path) ) 

#define IAcadPreferencesFiles_get_TemplateDwgPath(This,Path)	\
    ( (This)->lpVtbl -> get_TemplateDwgPath(This,Path) ) 

#define IAcadPreferencesFiles_put_LogFilePath(This,Path)	\
    ( (This)->lpVtbl -> put_LogFilePath(This,Path) ) 

#define IAcadPreferencesFiles_get_LogFilePath(This,Path)	\
    ( (This)->lpVtbl -> get_LogFilePath(This,Path) ) 

#define IAcadPreferencesFiles_put_TempFilePath(This,Path)	\
    ( (This)->lpVtbl -> put_TempFilePath(This,Path) ) 

#define IAcadPreferencesFiles_get_TempFilePath(This,Path)	\
    ( (This)->lpVtbl -> get_TempFilePath(This,Path) ) 

#define IAcadPreferencesFiles_put_TempXrefPath(This,Path)	\
    ( (This)->lpVtbl -> put_TempXrefPath(This,Path) ) 

#define IAcadPreferencesFiles_get_TempXrefPath(This,Path)	\
    ( (This)->lpVtbl -> get_TempXrefPath(This,Path) ) 

#define IAcadPreferencesFiles_put_TextureMapPath(This,Path)	\
    ( (This)->lpVtbl -> put_TextureMapPath(This,Path) ) 

#define IAcadPreferencesFiles_get_TextureMapPath(This,Path)	\
    ( (This)->lpVtbl -> get_TextureMapPath(This,Path) ) 

#define IAcadPreferencesFiles_put_AltTabletMenuFile(This,MenuFile)	\
    ( (This)->lpVtbl -> put_AltTabletMenuFile(This,MenuFile) ) 

#define IAcadPreferencesFiles_get_AltTabletMenuFile(This,MenuFile)	\
    ( (This)->lpVtbl -> get_AltTabletMenuFile(This,MenuFile) ) 

#define IAcadPreferencesFiles_SetProjectFilePath(This,ProjectName,ProjectFilePath)	\
    ( (This)->lpVtbl -> SetProjectFilePath(This,ProjectName,ProjectFilePath) ) 

#define IAcadPreferencesFiles_GetProjectFilePath(This,ProjectName,Path)	\
    ( (This)->lpVtbl -> GetProjectFilePath(This,ProjectName,Path) ) 

#define IAcadPreferencesFiles_put_PrinterConfigPath(This,Path)	\
    ( (This)->lpVtbl -> put_PrinterConfigPath(This,Path) ) 

#define IAcadPreferencesFiles_get_PrinterConfigPath(This,Path)	\
    ( (This)->lpVtbl -> get_PrinterConfigPath(This,Path) ) 

#define IAcadPreferencesFiles_put_PrinterDescPath(This,Path)	\
    ( (This)->lpVtbl -> put_PrinterDescPath(This,Path) ) 

#define IAcadPreferencesFiles_get_PrinterDescPath(This,Path)	\
    ( (This)->lpVtbl -> get_PrinterDescPath(This,Path) ) 

#define IAcadPreferencesFiles_put_PrinterStyleSheetPath(This,Path)	\
    ( (This)->lpVtbl -> put_PrinterStyleSheetPath(This,Path) ) 

#define IAcadPreferencesFiles_get_PrinterStyleSheetPath(This,Path)	\
    ( (This)->lpVtbl -> get_PrinterStyleSheetPath(This,Path) ) 

#define IAcadPreferencesFiles_put_WorkspacePath(This,Path)	\
    ( (This)->lpVtbl -> put_WorkspacePath(This,Path) ) 

#define IAcadPreferencesFiles_get_WorkspacePath(This,Path)	\
    ( (This)->lpVtbl -> get_WorkspacePath(This,Path) ) 

#define IAcadPreferencesFiles_put_ObjectARXPath(This,Path)	\
    ( (This)->lpVtbl -> put_ObjectARXPath(This,Path) ) 

#define IAcadPreferencesFiles_get_ObjectARXPath(This,Path)	\
    ( (This)->lpVtbl -> get_ObjectARXPath(This,Path) ) 

#define IAcadPreferencesFiles_put_ColorBookPath(This,Path)	\
    ( (This)->lpVtbl -> put_ColorBookPath(This,Path) ) 

#define IAcadPreferencesFiles_get_ColorBookPath(This,Path)	\
    ( (This)->lpVtbl -> get_ColorBookPath(This,Path) ) 

#define IAcadPreferencesFiles_put_ToolPalettePath(This,Path)	\
    ( (This)->lpVtbl -> put_ToolPalettePath(This,Path) ) 

#define IAcadPreferencesFiles_get_ToolPalettePath(This,Path)	\
    ( (This)->lpVtbl -> get_ToolPalettePath(This,Path) ) 

#define IAcadPreferencesFiles_put_QNewTemplateFile(This,Path)	\
    ( (This)->lpVtbl -> put_QNewTemplateFile(This,Path) ) 

#define IAcadPreferencesFiles_get_QNewTemplateFile(This,Path)	\
    ( (This)->lpVtbl -> get_QNewTemplateFile(This,Path) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAcadPreferencesFiles_INTERFACE_DEFINED__ */


#ifndef __IAcadPlot_INTERFACE_DEFINED__
#define __IAcadPlot_INTERFACE_DEFINED__

/* interface IAcadPlot */
/* [object][oleautomation][dual][helpstring][uuid] */ 


EXTERN_C const IID IID_IAcadPlot;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("445545BB-394E-481a-AC4F-F073E53030E8")
    IAcadPlot : public IDispatch
    {
    public:
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Application( 
            /* [retval][out] */ IAcadApplication **pAppObj) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_QuietErrorMode( 
            /* [in] */ VARIANT_BOOL QuietErrorMode) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_QuietErrorMode( 
            /* [retval][out] */ VARIANT_BOOL *pQuietErrorMode) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_NumberOfCopies( 
            /* [in] */ long NumberOfCopies) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_NumberOfCopies( 
            /* [retval][out] */ long *pNumberOfCopies) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_BatchPlotProgress( 
            /* [in] */ VARIANT_BOOL BatchPlotProgress) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_BatchPlotProgress( 
            /* [retval][out] */ VARIANT_BOOL *pBatchPlotProgress) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DisplayPlotPreview( 
            /* [in] */ enum /* external definition not present */ AcPreviewMode PreviewMode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetLayoutsToPlot( 
            /* [in] */ VARIANT layoutList) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE StartBatchMode( 
            /* [in] */ long entryCount) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PlotToDevice( 
            /* [optional][in] */ VARIANT plotConfig,
            /* [retval][out] */ VARIANT_BOOL *pResult) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PlotToFile( 
            /* [in] */ BSTR plotFile,
            /* [optional][in] */ VARIANT plotConfig,
            /* [retval][out] */ VARIANT_BOOL *pResult) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAcadPlotVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAcadPlot * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAcadPlot * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAcadPlot * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IAcadPlot * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IAcadPlot * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IAcadPlot * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IAcadPlot * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Application )( 
            IAcadPlot * This,
            /* [retval][out] */ IAcadApplication **pAppObj);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_QuietErrorMode )( 
            IAcadPlot * This,
            /* [in] */ VARIANT_BOOL QuietErrorMode);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_QuietErrorMode )( 
            IAcadPlot * This,
            /* [retval][out] */ VARIANT_BOOL *pQuietErrorMode);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_NumberOfCopies )( 
            IAcadPlot * This,
            /* [in] */ long NumberOfCopies);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_NumberOfCopies )( 
            IAcadPlot * This,
            /* [retval][out] */ long *pNumberOfCopies);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_BatchPlotProgress )( 
            IAcadPlot * This,
            /* [in] */ VARIANT_BOOL BatchPlotProgress);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_BatchPlotProgress )( 
            IAcadPlot * This,
            /* [retval][out] */ VARIANT_BOOL *pBatchPlotProgress);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DisplayPlotPreview )( 
            IAcadPlot * This,
            /* [in] */ enum /* external definition not present */ AcPreviewMode PreviewMode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetLayoutsToPlot )( 
            IAcadPlot * This,
            /* [in] */ VARIANT layoutList);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *StartBatchMode )( 
            IAcadPlot * This,
            /* [in] */ long entryCount);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PlotToDevice )( 
            IAcadPlot * This,
            /* [optional][in] */ VARIANT plotConfig,
            /* [retval][out] */ VARIANT_BOOL *pResult);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PlotToFile )( 
            IAcadPlot * This,
            /* [in] */ BSTR plotFile,
            /* [optional][in] */ VARIANT plotConfig,
            /* [retval][out] */ VARIANT_BOOL *pResult);
        
        END_INTERFACE
    } IAcadPlotVtbl;

    interface IAcadPlot
    {
        CONST_VTBL struct IAcadPlotVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAcadPlot_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAcadPlot_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAcadPlot_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAcadPlot_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IAcadPlot_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IAcadPlot_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IAcadPlot_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IAcadPlot_get_Application(This,pAppObj)	\
    ( (This)->lpVtbl -> get_Application(This,pAppObj) ) 

#define IAcadPlot_put_QuietErrorMode(This,QuietErrorMode)	\
    ( (This)->lpVtbl -> put_QuietErrorMode(This,QuietErrorMode) ) 

#define IAcadPlot_get_QuietErrorMode(This,pQuietErrorMode)	\
    ( (This)->lpVtbl -> get_QuietErrorMode(This,pQuietErrorMode) ) 

#define IAcadPlot_put_NumberOfCopies(This,NumberOfCopies)	\
    ( (This)->lpVtbl -> put_NumberOfCopies(This,NumberOfCopies) ) 

#define IAcadPlot_get_NumberOfCopies(This,pNumberOfCopies)	\
    ( (This)->lpVtbl -> get_NumberOfCopies(This,pNumberOfCopies) ) 

#define IAcadPlot_put_BatchPlotProgress(This,BatchPlotProgress)	\
    ( (This)->lpVtbl -> put_BatchPlotProgress(This,BatchPlotProgress) ) 

#define IAcadPlot_get_BatchPlotProgress(This,pBatchPlotProgress)	\
    ( (This)->lpVtbl -> get_BatchPlotProgress(This,pBatchPlotProgress) ) 

#define IAcadPlot_DisplayPlotPreview(This,PreviewMode)	\
    ( (This)->lpVtbl -> DisplayPlotPreview(This,PreviewMode) ) 

#define IAcadPlot_SetLayoutsToPlot(This,layoutList)	\
    ( (This)->lpVtbl -> SetLayoutsToPlot(This,layoutList) ) 

#define IAcadPlot_StartBatchMode(This,entryCount)	\
    ( (This)->lpVtbl -> StartBatchMode(This,entryCount) ) 

#define IAcadPlot_PlotToDevice(This,plotConfig,pResult)	\
    ( (This)->lpVtbl -> PlotToDevice(This,plotConfig,pResult) ) 

#define IAcadPlot_PlotToFile(This,plotFile,plotConfig,pResult)	\
    ( (This)->lpVtbl -> PlotToFile(This,plotFile,plotConfig,pResult) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAcadPlot_INTERFACE_DEFINED__ */


#ifndef __IAcadLayerStateManager_INTERFACE_DEFINED__
#define __IAcadLayerStateManager_INTERFACE_DEFINED__

/* interface IAcadLayerStateManager */
/* [object][oleautomation][dual][helpstring][uuid] */ 


EXTERN_C const IID IID_IAcadLayerStateManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("65CDCC9F-F651-4dc4-A361-A8307F08AEE3")
    IAcadLayerStateManager : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetDatabase( 
            /* [in] */ /* external definition not present */ IAcadDatabase *iHostDb) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Mask( 
            /* [in] */ BSTR bsName,
            /* [in] */ AcLayerStateMask eMask) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Mask( 
            /* [in] */ BSTR bsName,
            /* [retval][out] */ AcLayerStateMask *eMask) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Save( 
            /* [in] */ BSTR bsName,
            /* [in] */ AcLayerStateMask eMask) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Restore( 
            /* [in] */ BSTR bsName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Delete( 
            /* [in] */ BSTR bsName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Rename( 
            /* [in] */ BSTR bsName,
            /* [in] */ BSTR bsNewName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Import( 
            /* [in] */ BSTR bsFilename) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Export( 
            /* [in] */ BSTR bsName,
            /* [in] */ BSTR bsFilename) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAcadLayerStateManagerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAcadLayerStateManager * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAcadLayerStateManager * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAcadLayerStateManager * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IAcadLayerStateManager * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IAcadLayerStateManager * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IAcadLayerStateManager * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IAcadLayerStateManager * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetDatabase )( 
            IAcadLayerStateManager * This,
            /* [in] */ /* external definition not present */ IAcadDatabase *iHostDb);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Mask )( 
            IAcadLayerStateManager * This,
            /* [in] */ BSTR bsName,
            /* [in] */ AcLayerStateMask eMask);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Mask )( 
            IAcadLayerStateManager * This,
            /* [in] */ BSTR bsName,
            /* [retval][out] */ AcLayerStateMask *eMask);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Save )( 
            IAcadLayerStateManager * This,
            /* [in] */ BSTR bsName,
            /* [in] */ AcLayerStateMask eMask);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Restore )( 
            IAcadLayerStateManager * This,
            /* [in] */ BSTR bsName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IAcadLayerStateManager * This,
            /* [in] */ BSTR bsName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Rename )( 
            IAcadLayerStateManager * This,
            /* [in] */ BSTR bsName,
            /* [in] */ BSTR bsNewName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Import )( 
            IAcadLayerStateManager * This,
            /* [in] */ BSTR bsFilename);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Export )( 
            IAcadLayerStateManager * This,
            /* [in] */ BSTR bsName,
            /* [in] */ BSTR bsFilename);
        
        END_INTERFACE
    } IAcadLayerStateManagerVtbl;

    interface IAcadLayerStateManager
    {
        CONST_VTBL struct IAcadLayerStateManagerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAcadLayerStateManager_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAcadLayerStateManager_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAcadLayerStateManager_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAcadLayerStateManager_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IAcadLayerStateManager_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IAcadLayerStateManager_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IAcadLayerStateManager_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IAcadLayerStateManager_SetDatabase(This,iHostDb)	\
    ( (This)->lpVtbl -> SetDatabase(This,iHostDb) ) 

#define IAcadLayerStateManager_put_Mask(This,bsName,eMask)	\
    ( (This)->lpVtbl -> put_Mask(This,bsName,eMask) ) 

#define IAcadLayerStateManager_get_Mask(This,bsName,eMask)	\
    ( (This)->lpVtbl -> get_Mask(This,bsName,eMask) ) 

#define IAcadLayerStateManager_Save(This,bsName,eMask)	\
    ( (This)->lpVtbl -> Save(This,bsName,eMask) ) 

#define IAcadLayerStateManager_Restore(This,bsName)	\
    ( (This)->lpVtbl -> Restore(This,bsName) ) 

#define IAcadLayerStateManager_Delete(This,bsName)	\
    ( (This)->lpVtbl -> Delete(This,bsName) ) 

#define IAcadLayerStateManager_Rename(This,bsName,bsNewName)	\
    ( (This)->lpVtbl -> Rename(This,bsName,bsNewName) ) 

#define IAcadLayerStateManager_Import(This,bsFilename)	\
    ( (This)->lpVtbl -> Import(This,bsFilename) ) 

#define IAcadLayerStateManager_Export(This,bsName,bsFilename)	\
    ( (This)->lpVtbl -> Export(This,bsName,bsFilename) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAcadLayerStateManager_INTERFACE_DEFINED__ */


#ifndef __IAcadSecurityParams_INTERFACE_DEFINED__
#define __IAcadSecurityParams_INTERFACE_DEFINED__

/* interface IAcadSecurityParams */
/* [object][oleautomation][dual][helpstring][uuid] */ 


EXTERN_C const IID IID_IAcadSecurityParams;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A058E098-4DCF-4e3b-93BC-EF0FA19B718A")
    IAcadSecurityParams : public IDispatch
    {
    public:
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Action( 
            /* [in] */ long pOperations) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Action( 
            /* [retval][out] */ long *pOperations) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Password( 
            /* [in] */ BSTR pSecret) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Password( 
            /* [retval][out] */ BSTR *pSecret) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_ProviderType( 
            /* [in] */ long pProvType) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ProviderType( 
            /* [retval][out] */ long *pProvType) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_ProviderName( 
            /* [in] */ BSTR pProvName) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ProviderName( 
            /* [retval][out] */ BSTR *pProvName) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Algorithm( 
            /* [in] */ long pAlgId) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Algorithm( 
            /* [retval][out] */ long *pAlgId) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_KeyLength( 
            /* [in] */ long pKeyLen) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_KeyLength( 
            /* [retval][out] */ long *pKeyLen) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Subject( 
            /* [in] */ BSTR pCertSubject) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Subject( 
            /* [retval][out] */ BSTR *pCertSubject) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Issuer( 
            /* [in] */ BSTR pCertIssuer) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Issuer( 
            /* [retval][out] */ BSTR *pCertIssuer) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_SerialNumber( 
            /* [in] */ BSTR pSerialNum) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_SerialNumber( 
            /* [retval][out] */ BSTR *pSerialNum) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Comment( 
            /* [in] */ BSTR pText) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Comment( 
            /* [retval][out] */ BSTR *pText) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_TimeServer( 
            /* [in] */ BSTR pTimeServerName) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_TimeServer( 
            /* [retval][out] */ BSTR *pTimeServerName) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAcadSecurityParamsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAcadSecurityParams * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAcadSecurityParams * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAcadSecurityParams * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IAcadSecurityParams * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IAcadSecurityParams * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IAcadSecurityParams * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IAcadSecurityParams * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Action )( 
            IAcadSecurityParams * This,
            /* [in] */ long pOperations);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Action )( 
            IAcadSecurityParams * This,
            /* [retval][out] */ long *pOperations);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Password )( 
            IAcadSecurityParams * This,
            /* [in] */ BSTR pSecret);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Password )( 
            IAcadSecurityParams * This,
            /* [retval][out] */ BSTR *pSecret);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_ProviderType )( 
            IAcadSecurityParams * This,
            /* [in] */ long pProvType);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ProviderType )( 
            IAcadSecurityParams * This,
            /* [retval][out] */ long *pProvType);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_ProviderName )( 
            IAcadSecurityParams * This,
            /* [in] */ BSTR pProvName);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ProviderName )( 
            IAcadSecurityParams * This,
            /* [retval][out] */ BSTR *pProvName);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Algorithm )( 
            IAcadSecurityParams * This,
            /* [in] */ long pAlgId);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Algorithm )( 
            IAcadSecurityParams * This,
            /* [retval][out] */ long *pAlgId);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_KeyLength )( 
            IAcadSecurityParams * This,
            /* [in] */ long pKeyLen);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_KeyLength )( 
            IAcadSecurityParams * This,
            /* [retval][out] */ long *pKeyLen);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Subject )( 
            IAcadSecurityParams * This,
            /* [in] */ BSTR pCertSubject);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Subject )( 
            IAcadSecurityParams * This,
            /* [retval][out] */ BSTR *pCertSubject);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Issuer )( 
            IAcadSecurityParams * This,
            /* [in] */ BSTR pCertIssuer);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Issuer )( 
            IAcadSecurityParams * This,
            /* [retval][out] */ BSTR *pCertIssuer);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_SerialNumber )( 
            IAcadSecurityParams * This,
            /* [in] */ BSTR pSerialNum);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_SerialNumber )( 
            IAcadSecurityParams * This,
            /* [retval][out] */ BSTR *pSerialNum);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Comment )( 
            IAcadSecurityParams * This,
            /* [in] */ BSTR pText);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Comment )( 
            IAcadSecurityParams * This,
            /* [retval][out] */ BSTR *pText);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_TimeServer )( 
            IAcadSecurityParams * This,
            /* [in] */ BSTR pTimeServerName);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_TimeServer )( 
            IAcadSecurityParams * This,
            /* [retval][out] */ BSTR *pTimeServerName);
        
        END_INTERFACE
    } IAcadSecurityParamsVtbl;

    interface IAcadSecurityParams
    {
        CONST_VTBL struct IAcadSecurityParamsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAcadSecurityParams_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAcadSecurityParams_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAcadSecurityParams_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAcadSecurityParams_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IAcadSecurityParams_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IAcadSecurityParams_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IAcadSecurityParams_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IAcadSecurityParams_put_Action(This,pOperations)	\
    ( (This)->lpVtbl -> put_Action(This,pOperations) ) 

#define IAcadSecurityParams_get_Action(This,pOperations)	\
    ( (This)->lpVtbl -> get_Action(This,pOperations) ) 

#define IAcadSecurityParams_put_Password(This,pSecret)	\
    ( (This)->lpVtbl -> put_Password(This,pSecret) ) 

#define IAcadSecurityParams_get_Password(This,pSecret)	\
    ( (This)->lpVtbl -> get_Password(This,pSecret) ) 

#define IAcadSecurityParams_put_ProviderType(This,pProvType)	\
    ( (This)->lpVtbl -> put_ProviderType(This,pProvType) ) 

#define IAcadSecurityParams_get_ProviderType(This,pProvType)	\
    ( (This)->lpVtbl -> get_ProviderType(This,pProvType) ) 

#define IAcadSecurityParams_put_ProviderName(This,pProvName)	\
    ( (This)->lpVtbl -> put_ProviderName(This,pProvName) ) 

#define IAcadSecurityParams_get_ProviderName(This,pProvName)	\
    ( (This)->lpVtbl -> get_ProviderName(This,pProvName) ) 

#define IAcadSecurityParams_put_Algorithm(This,pAlgId)	\
    ( (This)->lpVtbl -> put_Algorithm(This,pAlgId) ) 

#define IAcadSecurityParams_get_Algorithm(This,pAlgId)	\
    ( (This)->lpVtbl -> get_Algorithm(This,pAlgId) ) 

#define IAcadSecurityParams_put_KeyLength(This,pKeyLen)	\
    ( (This)->lpVtbl -> put_KeyLength(This,pKeyLen) ) 

#define IAcadSecurityParams_get_KeyLength(This,pKeyLen)	\
    ( (This)->lpVtbl -> get_KeyLength(This,pKeyLen) ) 

#define IAcadSecurityParams_put_Subject(This,pCertSubject)	\
    ( (This)->lpVtbl -> put_Subject(This,pCertSubject) ) 

#define IAcadSecurityParams_get_Subject(This,pCertSubject)	\
    ( (This)->lpVtbl -> get_Subject(This,pCertSubject) ) 

#define IAcadSecurityParams_put_Issuer(This,pCertIssuer)	\
    ( (This)->lpVtbl -> put_Issuer(This,pCertIssuer) ) 

#define IAcadSecurityParams_get_Issuer(This,pCertIssuer)	\
    ( (This)->lpVtbl -> get_Issuer(This,pCertIssuer) ) 

#define IAcadSecurityParams_put_SerialNumber(This,pSerialNum)	\
    ( (This)->lpVtbl -> put_SerialNumber(This,pSerialNum) ) 

#define IAcadSecurityParams_get_SerialNumber(This,pSerialNum)	\
    ( (This)->lpVtbl -> get_SerialNumber(This,pSerialNum) ) 

#define IAcadSecurityParams_put_Comment(This,pText)	\
    ( (This)->lpVtbl -> put_Comment(This,pText) ) 

#define IAcadSecurityParams_get_Comment(This,pText)	\
    ( (This)->lpVtbl -> get_Comment(This,pText) ) 

#define IAcadSecurityParams_put_TimeServer(This,pTimeServerName)	\
    ( (This)->lpVtbl -> put_TimeServer(This,pTimeServerName) ) 

#define IAcadSecurityParams_get_TimeServer(This,pTimeServerName)	\
    ( (This)->lpVtbl -> get_TimeServer(This,pTimeServerName) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAcadSecurityParams_INTERFACE_DEFINED__ */


#ifndef __IAcadPreferencesDisplay_INTERFACE_DEFINED__
#define __IAcadPreferencesDisplay_INTERFACE_DEFINED__

/* interface IAcadPreferencesDisplay */
/* [object][oleautomation][dual][helpstring][uuid] */ 


EXTERN_C const IID IID_IAcadPreferencesDisplay;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0D71BC3C-9854-4076-BD32-D545259AB752")
    IAcadPreferencesDisplay : public IDispatch
    {
    public:
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Application( 
            /* [retval][out] */ IAcadApplication **pAppObj) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_LayoutDisplayMargins( 
            /* [in] */ VARIANT_BOOL Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_LayoutDisplayMargins( 
            /* [retval][out] */ VARIANT_BOOL *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_LayoutDisplayPaper( 
            /* [in] */ VARIANT_BOOL Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_LayoutDisplayPaper( 
            /* [retval][out] */ VARIANT_BOOL *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_LayoutDisplayPaperShadow( 
            /* [in] */ VARIANT_BOOL Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_LayoutDisplayPaperShadow( 
            /* [retval][out] */ VARIANT_BOOL *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_LayoutShowPlotSetup( 
            /* [in] */ VARIANT_BOOL Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_LayoutShowPlotSetup( 
            /* [retval][out] */ VARIANT_BOOL *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_LayoutCreateViewport( 
            /* [in] */ VARIANT_BOOL Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_LayoutCreateViewport( 
            /* [retval][out] */ VARIANT_BOOL *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_DisplayScrollBars( 
            /* [in] */ VARIANT_BOOL Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_DisplayScrollBars( 
            /* [retval][out] */ VARIANT_BOOL *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_DisplayScreenMenu( 
            /* [in] */ VARIANT_BOOL Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_DisplayScreenMenu( 
            /* [retval][out] */ VARIANT_BOOL *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_CursorSize( 
            /* [in] */ int Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_CursorSize( 
            /* [retval][out] */ int *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_DockedVisibleLines( 
            /* [in] */ int Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_DockedVisibleLines( 
            /* [retval][out] */ int *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_ShowRasterImage( 
            /* [in] */ VARIANT_BOOL Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ShowRasterImage( 
            /* [retval][out] */ VARIANT_BOOL *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_GraphicsWinModelBackgrndColor( 
            /* [in] */ OLE_COLOR color) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_GraphicsWinModelBackgrndColor( 
            /* [retval][out] */ OLE_COLOR *color) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_ModelCrosshairColor( 
            /* [in] */ OLE_COLOR crossHairColor) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ModelCrosshairColor( 
            /* [retval][out] */ OLE_COLOR *crossHairColor) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_GraphicsWinLayoutBackgrndColor( 
            /* [in] */ OLE_COLOR color) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_GraphicsWinLayoutBackgrndColor( 
            /* [retval][out] */ OLE_COLOR *color) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_TextWinBackgrndColor( 
            /* [in] */ OLE_COLOR Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_TextWinBackgrndColor( 
            /* [retval][out] */ OLE_COLOR *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_TextWinTextColor( 
            /* [in] */ OLE_COLOR Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_TextWinTextColor( 
            /* [retval][out] */ OLE_COLOR *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_LayoutCrosshairColor( 
            /* [in] */ OLE_COLOR crossHairColor) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_LayoutCrosshairColor( 
            /* [retval][out] */ OLE_COLOR *crossHairColor) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_AutoTrackingVecColor( 
            /* [in] */ OLE_COLOR AutoTrackingVecColor) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_AutoTrackingVecColor( 
            /* [retval][out] */ OLE_COLOR *AutoTrackingVecColor) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_TextFont( 
            /* [in] */ BSTR Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_TextFont( 
            /* [retval][out] */ BSTR *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_TextFontStyle( 
            /* [in] */ enum /* external definition not present */ AcTextFontStyle Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_TextFontStyle( 
            /* [retval][out] */ enum /* external definition not present */ AcTextFontStyle *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_TextFontSize( 
            /* [in] */ int Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_TextFontSize( 
            /* [retval][out] */ int *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_HistoryLines( 
            /* [in] */ int Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_HistoryLines( 
            /* [retval][out] */ int *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_MaxAutoCADWindow( 
            /* [in] */ VARIANT_BOOL Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_MaxAutoCADWindow( 
            /* [retval][out] */ VARIANT_BOOL *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_DisplayLayoutTabs( 
            /* [in] */ VARIANT_BOOL Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_DisplayLayoutTabs( 
            /* [retval][out] */ VARIANT_BOOL *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_ImageFrameHighlight( 
            /* [in] */ VARIANT_BOOL Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ImageFrameHighlight( 
            /* [retval][out] */ VARIANT_BOOL *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_TrueColorImages( 
            /* [in] */ VARIANT_BOOL Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_TrueColorImages( 
            /* [retval][out] */ VARIANT_BOOL *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_XRefFadeIntensity( 
            /* [in] */ long Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_XRefFadeIntensity( 
            /* [retval][out] */ long *Path) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAcadPreferencesDisplayVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAcadPreferencesDisplay * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAcadPreferencesDisplay * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAcadPreferencesDisplay * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IAcadPreferencesDisplay * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IAcadPreferencesDisplay * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IAcadPreferencesDisplay * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IAcadPreferencesDisplay * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Application )( 
            IAcadPreferencesDisplay * This,
            /* [retval][out] */ IAcadApplication **pAppObj);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_LayoutDisplayMargins )( 
            IAcadPreferencesDisplay * This,
            /* [in] */ VARIANT_BOOL Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_LayoutDisplayMargins )( 
            IAcadPreferencesDisplay * This,
            /* [retval][out] */ VARIANT_BOOL *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_LayoutDisplayPaper )( 
            IAcadPreferencesDisplay * This,
            /* [in] */ VARIANT_BOOL Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_LayoutDisplayPaper )( 
            IAcadPreferencesDisplay * This,
            /* [retval][out] */ VARIANT_BOOL *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_LayoutDisplayPaperShadow )( 
            IAcadPreferencesDisplay * This,
            /* [in] */ VARIANT_BOOL Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_LayoutDisplayPaperShadow )( 
            IAcadPreferencesDisplay * This,
            /* [retval][out] */ VARIANT_BOOL *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_LayoutShowPlotSetup )( 
            IAcadPreferencesDisplay * This,
            /* [in] */ VARIANT_BOOL Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_LayoutShowPlotSetup )( 
            IAcadPreferencesDisplay * This,
            /* [retval][out] */ VARIANT_BOOL *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_LayoutCreateViewport )( 
            IAcadPreferencesDisplay * This,
            /* [in] */ VARIANT_BOOL Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_LayoutCreateViewport )( 
            IAcadPreferencesDisplay * This,
            /* [retval][out] */ VARIANT_BOOL *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_DisplayScrollBars )( 
            IAcadPreferencesDisplay * This,
            /* [in] */ VARIANT_BOOL Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_DisplayScrollBars )( 
            IAcadPreferencesDisplay * This,
            /* [retval][out] */ VARIANT_BOOL *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_DisplayScreenMenu )( 
            IAcadPreferencesDisplay * This,
            /* [in] */ VARIANT_BOOL Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_DisplayScreenMenu )( 
            IAcadPreferencesDisplay * This,
            /* [retval][out] */ VARIANT_BOOL *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_CursorSize )( 
            IAcadPreferencesDisplay * This,
            /* [in] */ int Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_CursorSize )( 
            IAcadPreferencesDisplay * This,
            /* [retval][out] */ int *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_DockedVisibleLines )( 
            IAcadPreferencesDisplay * This,
            /* [in] */ int Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_DockedVisibleLines )( 
            IAcadPreferencesDisplay * This,
            /* [retval][out] */ int *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_ShowRasterImage )( 
            IAcadPreferencesDisplay * This,
            /* [in] */ VARIANT_BOOL Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ShowRasterImage )( 
            IAcadPreferencesDisplay * This,
            /* [retval][out] */ VARIANT_BOOL *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_GraphicsWinModelBackgrndColor )( 
            IAcadPreferencesDisplay * This,
            /* [in] */ OLE_COLOR color);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_GraphicsWinModelBackgrndColor )( 
            IAcadPreferencesDisplay * This,
            /* [retval][out] */ OLE_COLOR *color);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_ModelCrosshairColor )( 
            IAcadPreferencesDisplay * This,
            /* [in] */ OLE_COLOR crossHairColor);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ModelCrosshairColor )( 
            IAcadPreferencesDisplay * This,
            /* [retval][out] */ OLE_COLOR *crossHairColor);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_GraphicsWinLayoutBackgrndColor )( 
            IAcadPreferencesDisplay * This,
            /* [in] */ OLE_COLOR color);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_GraphicsWinLayoutBackgrndColor )( 
            IAcadPreferencesDisplay * This,
            /* [retval][out] */ OLE_COLOR *color);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_TextWinBackgrndColor )( 
            IAcadPreferencesDisplay * This,
            /* [in] */ OLE_COLOR Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_TextWinBackgrndColor )( 
            IAcadPreferencesDisplay * This,
            /* [retval][out] */ OLE_COLOR *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_TextWinTextColor )( 
            IAcadPreferencesDisplay * This,
            /* [in] */ OLE_COLOR Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_TextWinTextColor )( 
            IAcadPreferencesDisplay * This,
            /* [retval][out] */ OLE_COLOR *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_LayoutCrosshairColor )( 
            IAcadPreferencesDisplay * This,
            /* [in] */ OLE_COLOR crossHairColor);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_LayoutCrosshairColor )( 
            IAcadPreferencesDisplay * This,
            /* [retval][out] */ OLE_COLOR *crossHairColor);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_AutoTrackingVecColor )( 
            IAcadPreferencesDisplay * This,
            /* [in] */ OLE_COLOR AutoTrackingVecColor);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_AutoTrackingVecColor )( 
            IAcadPreferencesDisplay * This,
            /* [retval][out] */ OLE_COLOR *AutoTrackingVecColor);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_TextFont )( 
            IAcadPreferencesDisplay * This,
            /* [in] */ BSTR Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_TextFont )( 
            IAcadPreferencesDisplay * This,
            /* [retval][out] */ BSTR *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_TextFontStyle )( 
            IAcadPreferencesDisplay * This,
            /* [in] */ enum /* external definition not present */ AcTextFontStyle Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_TextFontStyle )( 
            IAcadPreferencesDisplay * This,
            /* [retval][out] */ enum /* external definition not present */ AcTextFontStyle *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_TextFontSize )( 
            IAcadPreferencesDisplay * This,
            /* [in] */ int Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_TextFontSize )( 
            IAcadPreferencesDisplay * This,
            /* [retval][out] */ int *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_HistoryLines )( 
            IAcadPreferencesDisplay * This,
            /* [in] */ int Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_HistoryLines )( 
            IAcadPreferencesDisplay * This,
            /* [retval][out] */ int *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_MaxAutoCADWindow )( 
            IAcadPreferencesDisplay * This,
            /* [in] */ VARIANT_BOOL Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_MaxAutoCADWindow )( 
            IAcadPreferencesDisplay * This,
            /* [retval][out] */ VARIANT_BOOL *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_DisplayLayoutTabs )( 
            IAcadPreferencesDisplay * This,
            /* [in] */ VARIANT_BOOL Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_DisplayLayoutTabs )( 
            IAcadPreferencesDisplay * This,
            /* [retval][out] */ VARIANT_BOOL *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_ImageFrameHighlight )( 
            IAcadPreferencesDisplay * This,
            /* [in] */ VARIANT_BOOL Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ImageFrameHighlight )( 
            IAcadPreferencesDisplay * This,
            /* [retval][out] */ VARIANT_BOOL *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_TrueColorImages )( 
            IAcadPreferencesDisplay * This,
            /* [in] */ VARIANT_BOOL Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_TrueColorImages )( 
            IAcadPreferencesDisplay * This,
            /* [retval][out] */ VARIANT_BOOL *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_XRefFadeIntensity )( 
            IAcadPreferencesDisplay * This,
            /* [in] */ long Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_XRefFadeIntensity )( 
            IAcadPreferencesDisplay * This,
            /* [retval][out] */ long *Path);
        
        END_INTERFACE
    } IAcadPreferencesDisplayVtbl;

    interface IAcadPreferencesDisplay
    {
        CONST_VTBL struct IAcadPreferencesDisplayVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAcadPreferencesDisplay_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAcadPreferencesDisplay_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAcadPreferencesDisplay_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAcadPreferencesDisplay_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IAcadPreferencesDisplay_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IAcadPreferencesDisplay_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IAcadPreferencesDisplay_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IAcadPreferencesDisplay_get_Application(This,pAppObj)	\
    ( (This)->lpVtbl -> get_Application(This,pAppObj) ) 

#define IAcadPreferencesDisplay_put_LayoutDisplayMargins(This,Path)	\
    ( (This)->lpVtbl -> put_LayoutDisplayMargins(This,Path) ) 

#define IAcadPreferencesDisplay_get_LayoutDisplayMargins(This,Path)	\
    ( (This)->lpVtbl -> get_LayoutDisplayMargins(This,Path) ) 

#define IAcadPreferencesDisplay_put_LayoutDisplayPaper(This,Path)	\
    ( (This)->lpVtbl -> put_LayoutDisplayPaper(This,Path) ) 

#define IAcadPreferencesDisplay_get_LayoutDisplayPaper(This,Path)	\
    ( (This)->lpVtbl -> get_LayoutDisplayPaper(This,Path) ) 

#define IAcadPreferencesDisplay_put_LayoutDisplayPaperShadow(This,Path)	\
    ( (This)->lpVtbl -> put_LayoutDisplayPaperShadow(This,Path) ) 

#define IAcadPreferencesDisplay_get_LayoutDisplayPaperShadow(This,Path)	\
    ( (This)->lpVtbl -> get_LayoutDisplayPaperShadow(This,Path) ) 

#define IAcadPreferencesDisplay_put_LayoutShowPlotSetup(This,Path)	\
    ( (This)->lpVtbl -> put_LayoutShowPlotSetup(This,Path) ) 

#define IAcadPreferencesDisplay_get_LayoutShowPlotSetup(This,Path)	\
    ( (This)->lpVtbl -> get_LayoutShowPlotSetup(This,Path) ) 

#define IAcadPreferencesDisplay_put_LayoutCreateViewport(This,Path)	\
    ( (This)->lpVtbl -> put_LayoutCreateViewport(This,Path) ) 

#define IAcadPreferencesDisplay_get_LayoutCreateViewport(This,Path)	\
    ( (This)->lpVtbl -> get_LayoutCreateViewport(This,Path) ) 

#define IAcadPreferencesDisplay_put_DisplayScrollBars(This,Path)	\
    ( (This)->lpVtbl -> put_DisplayScrollBars(This,Path) ) 

#define IAcadPreferencesDisplay_get_DisplayScrollBars(This,Path)	\
    ( (This)->lpVtbl -> get_DisplayScrollBars(This,Path) ) 

#define IAcadPreferencesDisplay_put_DisplayScreenMenu(This,Path)	\
    ( (This)->lpVtbl -> put_DisplayScreenMenu(This,Path) ) 

#define IAcadPreferencesDisplay_get_DisplayScreenMenu(This,Path)	\
    ( (This)->lpVtbl -> get_DisplayScreenMenu(This,Path) ) 

#define IAcadPreferencesDisplay_put_CursorSize(This,Path)	\
    ( (This)->lpVtbl -> put_CursorSize(This,Path) ) 

#define IAcadPreferencesDisplay_get_CursorSize(This,Path)	\
    ( (This)->lpVtbl -> get_CursorSize(This,Path) ) 

#define IAcadPreferencesDisplay_put_DockedVisibleLines(This,Path)	\
    ( (This)->lpVtbl -> put_DockedVisibleLines(This,Path) ) 

#define IAcadPreferencesDisplay_get_DockedVisibleLines(This,Path)	\
    ( (This)->lpVtbl -> get_DockedVisibleLines(This,Path) ) 

#define IAcadPreferencesDisplay_put_ShowRasterImage(This,Path)	\
    ( (This)->lpVtbl -> put_ShowRasterImage(This,Path) ) 

#define IAcadPreferencesDisplay_get_ShowRasterImage(This,Path)	\
    ( (This)->lpVtbl -> get_ShowRasterImage(This,Path) ) 

#define IAcadPreferencesDisplay_put_GraphicsWinModelBackgrndColor(This,color)	\
    ( (This)->lpVtbl -> put_GraphicsWinModelBackgrndColor(This,color) ) 

#define IAcadPreferencesDisplay_get_GraphicsWinModelBackgrndColor(This,color)	\
    ( (This)->lpVtbl -> get_GraphicsWinModelBackgrndColor(This,color) ) 

#define IAcadPreferencesDisplay_put_ModelCrosshairColor(This,crossHairColor)	\
    ( (This)->lpVtbl -> put_ModelCrosshairColor(This,crossHairColor) ) 

#define IAcadPreferencesDisplay_get_ModelCrosshairColor(This,crossHairColor)	\
    ( (This)->lpVtbl -> get_ModelCrosshairColor(This,crossHairColor) ) 

#define IAcadPreferencesDisplay_put_GraphicsWinLayoutBackgrndColor(This,color)	\
    ( (This)->lpVtbl -> put_GraphicsWinLayoutBackgrndColor(This,color) ) 

#define IAcadPreferencesDisplay_get_GraphicsWinLayoutBackgrndColor(This,color)	\
    ( (This)->lpVtbl -> get_GraphicsWinLayoutBackgrndColor(This,color) ) 

#define IAcadPreferencesDisplay_put_TextWinBackgrndColor(This,Path)	\
    ( (This)->lpVtbl -> put_TextWinBackgrndColor(This,Path) ) 

#define IAcadPreferencesDisplay_get_TextWinBackgrndColor(This,Path)	\
    ( (This)->lpVtbl -> get_TextWinBackgrndColor(This,Path) ) 

#define IAcadPreferencesDisplay_put_TextWinTextColor(This,Path)	\
    ( (This)->lpVtbl -> put_TextWinTextColor(This,Path) ) 

#define IAcadPreferencesDisplay_get_TextWinTextColor(This,Path)	\
    ( (This)->lpVtbl -> get_TextWinTextColor(This,Path) ) 

#define IAcadPreferencesDisplay_put_LayoutCrosshairColor(This,crossHairColor)	\
    ( (This)->lpVtbl -> put_LayoutCrosshairColor(This,crossHairColor) ) 

#define IAcadPreferencesDisplay_get_LayoutCrosshairColor(This,crossHairColor)	\
    ( (This)->lpVtbl -> get_LayoutCrosshairColor(This,crossHairColor) ) 

#define IAcadPreferencesDisplay_put_AutoTrackingVecColor(This,AutoTrackingVecColor)	\
    ( (This)->lpVtbl -> put_AutoTrackingVecColor(This,AutoTrackingVecColor) ) 

#define IAcadPreferencesDisplay_get_AutoTrackingVecColor(This,AutoTrackingVecColor)	\
    ( (This)->lpVtbl -> get_AutoTrackingVecColor(This,AutoTrackingVecColor) ) 

#define IAcadPreferencesDisplay_put_TextFont(This,Path)	\
    ( (This)->lpVtbl -> put_TextFont(This,Path) ) 

#define IAcadPreferencesDisplay_get_TextFont(This,Path)	\
    ( (This)->lpVtbl -> get_TextFont(This,Path) ) 

#define IAcadPreferencesDisplay_put_TextFontStyle(This,Path)	\
    ( (This)->lpVtbl -> put_TextFontStyle(This,Path) ) 

#define IAcadPreferencesDisplay_get_TextFontStyle(This,Path)	\
    ( (This)->lpVtbl -> get_TextFontStyle(This,Path) ) 

#define IAcadPreferencesDisplay_put_TextFontSize(This,Path)	\
    ( (This)->lpVtbl -> put_TextFontSize(This,Path) ) 

#define IAcadPreferencesDisplay_get_TextFontSize(This,Path)	\
    ( (This)->lpVtbl -> get_TextFontSize(This,Path) ) 

#define IAcadPreferencesDisplay_put_HistoryLines(This,Path)	\
    ( (This)->lpVtbl -> put_HistoryLines(This,Path) ) 

#define IAcadPreferencesDisplay_get_HistoryLines(This,Path)	\
    ( (This)->lpVtbl -> get_HistoryLines(This,Path) ) 

#define IAcadPreferencesDisplay_put_MaxAutoCADWindow(This,Path)	\
    ( (This)->lpVtbl -> put_MaxAutoCADWindow(This,Path) ) 

#define IAcadPreferencesDisplay_get_MaxAutoCADWindow(This,Path)	\
    ( (This)->lpVtbl -> get_MaxAutoCADWindow(This,Path) ) 

#define IAcadPreferencesDisplay_put_DisplayLayoutTabs(This,Path)	\
    ( (This)->lpVtbl -> put_DisplayLayoutTabs(This,Path) ) 

#define IAcadPreferencesDisplay_get_DisplayLayoutTabs(This,Path)	\
    ( (This)->lpVtbl -> get_DisplayLayoutTabs(This,Path) ) 

#define IAcadPreferencesDisplay_put_ImageFrameHighlight(This,Path)	\
    ( (This)->lpVtbl -> put_ImageFrameHighlight(This,Path) ) 

#define IAcadPreferencesDisplay_get_ImageFrameHighlight(This,Path)	\
    ( (This)->lpVtbl -> get_ImageFrameHighlight(This,Path) ) 

#define IAcadPreferencesDisplay_put_TrueColorImages(This,Path)	\
    ( (This)->lpVtbl -> put_TrueColorImages(This,Path) ) 

#define IAcadPreferencesDisplay_get_TrueColorImages(This,Path)	\
    ( (This)->lpVtbl -> get_TrueColorImages(This,Path) ) 

#define IAcadPreferencesDisplay_put_XRefFadeIntensity(This,Path)	\
    ( (This)->lpVtbl -> put_XRefFadeIntensity(This,Path) ) 

#define IAcadPreferencesDisplay_get_XRefFadeIntensity(This,Path)	\
    ( (This)->lpVtbl -> get_XRefFadeIntensity(This,Path) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAcadPreferencesDisplay_INTERFACE_DEFINED__ */


#ifndef __IAcadPreferencesOpenSave_INTERFACE_DEFINED__
#define __IAcadPreferencesOpenSave_INTERFACE_DEFINED__

/* interface IAcadPreferencesOpenSave */
/* [object][oleautomation][dual][helpstring][uuid] */ 


EXTERN_C const IID IID_IAcadPreferencesOpenSave;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5E24ED87-DC43-4771-B7E6-7FE35C21CAB1")
    IAcadPreferencesOpenSave : public IDispatch
    {
    public:
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Application( 
            /* [retval][out] */ IAcadApplication **pAppObj) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_SavePreviewThumbnail( 
            /* [in] */ VARIANT_BOOL Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_SavePreviewThumbnail( 
            /* [retval][out] */ VARIANT_BOOL *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_IncrementalSavePercent( 
            /* [in] */ int Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_IncrementalSavePercent( 
            /* [retval][out] */ int *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_AutoSaveInterval( 
            /* [in] */ int Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_AutoSaveInterval( 
            /* [retval][out] */ int *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_CreateBackup( 
            /* [in] */ VARIANT_BOOL CreateBackup) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_CreateBackup( 
            /* [retval][out] */ VARIANT_BOOL *CreateBackup) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_FullCRCValidation( 
            /* [in] */ VARIANT_BOOL Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_FullCRCValidation( 
            /* [retval][out] */ VARIANT_BOOL *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_LogFileOn( 
            /* [in] */ VARIANT_BOOL Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_LogFileOn( 
            /* [retval][out] */ VARIANT_BOOL *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_TempFileExtension( 
            /* [in] */ BSTR Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_TempFileExtension( 
            /* [retval][out] */ BSTR *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_XrefDemandLoad( 
            /* [in] */ enum /* external definition not present */ AcXRefDemandLoad Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_XrefDemandLoad( 
            /* [retval][out] */ enum /* external definition not present */ AcXRefDemandLoad *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_DemandLoadARXApp( 
            /* [in] */ enum /* external definition not present */ AcARXDemandLoad Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_DemandLoadARXApp( 
            /* [retval][out] */ enum /* external definition not present */ AcARXDemandLoad *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_ProxyImage( 
            /* [in] */ enum /* external definition not present */ AcProxyImage Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ProxyImage( 
            /* [retval][out] */ enum /* external definition not present */ AcProxyImage *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_ShowProxyDialogBox( 
            /* [in] */ VARIANT_BOOL Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ShowProxyDialogBox( 
            /* [retval][out] */ VARIANT_BOOL *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_AutoAudit( 
            /* [in] */ VARIANT_BOOL bAudit) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_AutoAudit( 
            /* [retval][out] */ VARIANT_BOOL *bAudit) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_SaveAsType( 
            /* [in] */ enum /* external definition not present */ AcSaveAsType Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_SaveAsType( 
            /* [retval][out] */ enum /* external definition not present */ AcSaveAsType *Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_MRUNumber( 
            /* [retval][out] */ long *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_DWFFormat( 
            /* [in] */ int Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_DWFFormat( 
            /* [retval][out] */ int *Path) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAcadPreferencesOpenSaveVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAcadPreferencesOpenSave * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAcadPreferencesOpenSave * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAcadPreferencesOpenSave * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IAcadPreferencesOpenSave * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IAcadPreferencesOpenSave * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IAcadPreferencesOpenSave * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IAcadPreferencesOpenSave * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Application )( 
            IAcadPreferencesOpenSave * This,
            /* [retval][out] */ IAcadApplication **pAppObj);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_SavePreviewThumbnail )( 
            IAcadPreferencesOpenSave * This,
            /* [in] */ VARIANT_BOOL Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_SavePreviewThumbnail )( 
            IAcadPreferencesOpenSave * This,
            /* [retval][out] */ VARIANT_BOOL *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_IncrementalSavePercent )( 
            IAcadPreferencesOpenSave * This,
            /* [in] */ int Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_IncrementalSavePercent )( 
            IAcadPreferencesOpenSave * This,
            /* [retval][out] */ int *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_AutoSaveInterval )( 
            IAcadPreferencesOpenSave * This,
            /* [in] */ int Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_AutoSaveInterval )( 
            IAcadPreferencesOpenSave * This,
            /* [retval][out] */ int *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_CreateBackup )( 
            IAcadPreferencesOpenSave * This,
            /* [in] */ VARIANT_BOOL CreateBackup);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_CreateBackup )( 
            IAcadPreferencesOpenSave * This,
            /* [retval][out] */ VARIANT_BOOL *CreateBackup);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_FullCRCValidation )( 
            IAcadPreferencesOpenSave * This,
            /* [in] */ VARIANT_BOOL Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_FullCRCValidation )( 
            IAcadPreferencesOpenSave * This,
            /* [retval][out] */ VARIANT_BOOL *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_LogFileOn )( 
            IAcadPreferencesOpenSave * This,
            /* [in] */ VARIANT_BOOL Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_LogFileOn )( 
            IAcadPreferencesOpenSave * This,
            /* [retval][out] */ VARIANT_BOOL *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_TempFileExtension )( 
            IAcadPreferencesOpenSave * This,
            /* [in] */ BSTR Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_TempFileExtension )( 
            IAcadPreferencesOpenSave * This,
            /* [retval][out] */ BSTR *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_XrefDemandLoad )( 
            IAcadPreferencesOpenSave * This,
            /* [in] */ enum /* external definition not present */ AcXRefDemandLoad Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_XrefDemandLoad )( 
            IAcadPreferencesOpenSave * This,
            /* [retval][out] */ enum /* external definition not present */ AcXRefDemandLoad *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_DemandLoadARXApp )( 
            IAcadPreferencesOpenSave * This,
            /* [in] */ enum /* external definition not present */ AcARXDemandLoad Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_DemandLoadARXApp )( 
            IAcadPreferencesOpenSave * This,
            /* [retval][out] */ enum /* external definition not present */ AcARXDemandLoad *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_ProxyImage )( 
            IAcadPreferencesOpenSave * This,
            /* [in] */ enum /* external definition not present */ AcProxyImage Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ProxyImage )( 
            IAcadPreferencesOpenSave * This,
            /* [retval][out] */ enum /* external definition not present */ AcProxyImage *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_ShowProxyDialogBox )( 
            IAcadPreferencesOpenSave * This,
            /* [in] */ VARIANT_BOOL Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ShowProxyDialogBox )( 
            IAcadPreferencesOpenSave * This,
            /* [retval][out] */ VARIANT_BOOL *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_AutoAudit )( 
            IAcadPreferencesOpenSave * This,
            /* [in] */ VARIANT_BOOL bAudit);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_AutoAudit )( 
            IAcadPreferencesOpenSave * This,
            /* [retval][out] */ VARIANT_BOOL *bAudit);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_SaveAsType )( 
            IAcadPreferencesOpenSave * This,
            /* [in] */ enum /* external definition not present */ AcSaveAsType Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_SaveAsType )( 
            IAcadPreferencesOpenSave * This,
            /* [retval][out] */ enum /* external definition not present */ AcSaveAsType *Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_MRUNumber )( 
            IAcadPreferencesOpenSave * This,
            /* [retval][out] */ long *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_DWFFormat )( 
            IAcadPreferencesOpenSave * This,
            /* [in] */ int Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_DWFFormat )( 
            IAcadPreferencesOpenSave * This,
            /* [retval][out] */ int *Path);
        
        END_INTERFACE
    } IAcadPreferencesOpenSaveVtbl;

    interface IAcadPreferencesOpenSave
    {
        CONST_VTBL struct IAcadPreferencesOpenSaveVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAcadPreferencesOpenSave_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAcadPreferencesOpenSave_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAcadPreferencesOpenSave_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAcadPreferencesOpenSave_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IAcadPreferencesOpenSave_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IAcadPreferencesOpenSave_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IAcadPreferencesOpenSave_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IAcadPreferencesOpenSave_get_Application(This,pAppObj)	\
    ( (This)->lpVtbl -> get_Application(This,pAppObj) ) 

#define IAcadPreferencesOpenSave_put_SavePreviewThumbnail(This,Path)	\
    ( (This)->lpVtbl -> put_SavePreviewThumbnail(This,Path) ) 

#define IAcadPreferencesOpenSave_get_SavePreviewThumbnail(This,Path)	\
    ( (This)->lpVtbl -> get_SavePreviewThumbnail(This,Path) ) 

#define IAcadPreferencesOpenSave_put_IncrementalSavePercent(This,Path)	\
    ( (This)->lpVtbl -> put_IncrementalSavePercent(This,Path) ) 

#define IAcadPreferencesOpenSave_get_IncrementalSavePercent(This,Path)	\
    ( (This)->lpVtbl -> get_IncrementalSavePercent(This,Path) ) 

#define IAcadPreferencesOpenSave_put_AutoSaveInterval(This,Path)	\
    ( (This)->lpVtbl -> put_AutoSaveInterval(This,Path) ) 

#define IAcadPreferencesOpenSave_get_AutoSaveInterval(This,Path)	\
    ( (This)->lpVtbl -> get_AutoSaveInterval(This,Path) ) 

#define IAcadPreferencesOpenSave_put_CreateBackup(This,CreateBackup)	\
    ( (This)->lpVtbl -> put_CreateBackup(This,CreateBackup) ) 

#define IAcadPreferencesOpenSave_get_CreateBackup(This,CreateBackup)	\
    ( (This)->lpVtbl -> get_CreateBackup(This,CreateBackup) ) 

#define IAcadPreferencesOpenSave_put_FullCRCValidation(This,Path)	\
    ( (This)->lpVtbl -> put_FullCRCValidation(This,Path) ) 

#define IAcadPreferencesOpenSave_get_FullCRCValidation(This,Path)	\
    ( (This)->lpVtbl -> get_FullCRCValidation(This,Path) ) 

#define IAcadPreferencesOpenSave_put_LogFileOn(This,Path)	\
    ( (This)->lpVtbl -> put_LogFileOn(This,Path) ) 

#define IAcadPreferencesOpenSave_get_LogFileOn(This,Path)	\
    ( (This)->lpVtbl -> get_LogFileOn(This,Path) ) 

#define IAcadPreferencesOpenSave_put_TempFileExtension(This,Path)	\
    ( (This)->lpVtbl -> put_TempFileExtension(This,Path) ) 

#define IAcadPreferencesOpenSave_get_TempFileExtension(This,Path)	\
    ( (This)->lpVtbl -> get_TempFileExtension(This,Path) ) 

#define IAcadPreferencesOpenSave_put_XrefDemandLoad(This,Path)	\
    ( (This)->lpVtbl -> put_XrefDemandLoad(This,Path) ) 

#define IAcadPreferencesOpenSave_get_XrefDemandLoad(This,Path)	\
    ( (This)->lpVtbl -> get_XrefDemandLoad(This,Path) ) 

#define IAcadPreferencesOpenSave_put_DemandLoadARXApp(This,Path)	\
    ( (This)->lpVtbl -> put_DemandLoadARXApp(This,Path) ) 

#define IAcadPreferencesOpenSave_get_DemandLoadARXApp(This,Path)	\
    ( (This)->lpVtbl -> get_DemandLoadARXApp(This,Path) ) 

#define IAcadPreferencesOpenSave_put_ProxyImage(This,Path)	\
    ( (This)->lpVtbl -> put_ProxyImage(This,Path) ) 

#define IAcadPreferencesOpenSave_get_ProxyImage(This,Path)	\
    ( (This)->lpVtbl -> get_ProxyImage(This,Path) ) 

#define IAcadPreferencesOpenSave_put_ShowProxyDialogBox(This,Path)	\
    ( (This)->lpVtbl -> put_ShowProxyDialogBox(This,Path) ) 

#define IAcadPreferencesOpenSave_get_ShowProxyDialogBox(This,Path)	\
    ( (This)->lpVtbl -> get_ShowProxyDialogBox(This,Path) ) 

#define IAcadPreferencesOpenSave_put_AutoAudit(This,bAudit)	\
    ( (This)->lpVtbl -> put_AutoAudit(This,bAudit) ) 

#define IAcadPreferencesOpenSave_get_AutoAudit(This,bAudit)	\
    ( (This)->lpVtbl -> get_AutoAudit(This,bAudit) ) 

#define IAcadPreferencesOpenSave_put_SaveAsType(This,Path)	\
    ( (This)->lpVtbl -> put_SaveAsType(This,Path) ) 

#define IAcadPreferencesOpenSave_get_SaveAsType(This,Path)	\
    ( (This)->lpVtbl -> get_SaveAsType(This,Path) ) 

#define IAcadPreferencesOpenSave_get_MRUNumber(This,Path)	\
    ( (This)->lpVtbl -> get_MRUNumber(This,Path) ) 

#define IAcadPreferencesOpenSave_put_DWFFormat(This,Path)	\
    ( (This)->lpVtbl -> put_DWFFormat(This,Path) ) 

#define IAcadPreferencesOpenSave_get_DWFFormat(This,Path)	\
    ( (This)->lpVtbl -> get_DWFFormat(This,Path) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAcadPreferencesOpenSave_INTERFACE_DEFINED__ */


#ifndef __IAcadPreferencesOutput_INTERFACE_DEFINED__
#define __IAcadPreferencesOutput_INTERFACE_DEFINED__

/* interface IAcadPreferencesOutput */
/* [object][oleautomation][dual][helpstring][uuid] */ 


EXTERN_C const IID IID_IAcadPreferencesOutput;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1560A14A-D97B-4b3b-BF95-D0F703723442")
    IAcadPreferencesOutput : public IDispatch
    {
    public:
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Application( 
            /* [retval][out] */ IAcadApplication **pAppObj) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_DefaultOutputDevice( 
            /* [in] */ BSTR Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_DefaultOutputDevice( 
            /* [retval][out] */ BSTR *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_PrinterSpoolAlert( 
            /* [in] */ enum /* external definition not present */ AcPrinterSpoolAlert Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_PrinterSpoolAlert( 
            /* [retval][out] */ enum /* external definition not present */ AcPrinterSpoolAlert *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_PrinterPaperSizeAlert( 
            /* [in] */ VARIANT_BOOL Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_PrinterPaperSizeAlert( 
            /* [retval][out] */ VARIANT_BOOL *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_PlotLegacy( 
            /* [in] */ VARIANT_BOOL Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_PlotLegacy( 
            /* [retval][out] */ VARIANT_BOOL *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_OLEQuality( 
            /* [in] */ enum /* external definition not present */ AcOleQuality Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_OLEQuality( 
            /* [retval][out] */ enum /* external definition not present */ AcOleQuality *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_UseLastPlotSettings( 
            /* [in] */ VARIANT_BOOL Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_UseLastPlotSettings( 
            /* [retval][out] */ VARIANT_BOOL *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_PlotPolicy( 
            /* [in] */ enum /* external definition not present */ AcPlotPolicy Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_PlotPolicy( 
            /* [retval][out] */ enum /* external definition not present */ AcPlotPolicy *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_DefaultPlotStyleTable( 
            /* [in] */ BSTR Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_DefaultPlotStyleTable( 
            /* [retval][out] */ BSTR *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_DefaultPlotStyleForObjects( 
            /* [in] */ BSTR Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_DefaultPlotStyleForObjects( 
            /* [retval][out] */ BSTR *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_DefaultPlotStyleForLayer( 
            /* [in] */ BSTR Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_DefaultPlotStyleForLayer( 
            /* [retval][out] */ BSTR *Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Pdf( 
            /* [retval][out] */ IAcadPreferencesPdfOutput **pObj) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAcadPreferencesOutputVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAcadPreferencesOutput * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAcadPreferencesOutput * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAcadPreferencesOutput * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IAcadPreferencesOutput * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IAcadPreferencesOutput * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IAcadPreferencesOutput * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IAcadPreferencesOutput * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Application )( 
            IAcadPreferencesOutput * This,
            /* [retval][out] */ IAcadApplication **pAppObj);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultOutputDevice )( 
            IAcadPreferencesOutput * This,
            /* [in] */ BSTR Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultOutputDevice )( 
            IAcadPreferencesOutput * This,
            /* [retval][out] */ BSTR *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_PrinterSpoolAlert )( 
            IAcadPreferencesOutput * This,
            /* [in] */ enum /* external definition not present */ AcPrinterSpoolAlert Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_PrinterSpoolAlert )( 
            IAcadPreferencesOutput * This,
            /* [retval][out] */ enum /* external definition not present */ AcPrinterSpoolAlert *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_PrinterPaperSizeAlert )( 
            IAcadPreferencesOutput * This,
            /* [in] */ VARIANT_BOOL Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_PrinterPaperSizeAlert )( 
            IAcadPreferencesOutput * This,
            /* [retval][out] */ VARIANT_BOOL *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_PlotLegacy )( 
            IAcadPreferencesOutput * This,
            /* [in] */ VARIANT_BOOL Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_PlotLegacy )( 
            IAcadPreferencesOutput * This,
            /* [retval][out] */ VARIANT_BOOL *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_OLEQuality )( 
            IAcadPreferencesOutput * This,
            /* [in] */ enum /* external definition not present */ AcOleQuality Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_OLEQuality )( 
            IAcadPreferencesOutput * This,
            /* [retval][out] */ enum /* external definition not present */ AcOleQuality *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_UseLastPlotSettings )( 
            IAcadPreferencesOutput * This,
            /* [in] */ VARIANT_BOOL Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_UseLastPlotSettings )( 
            IAcadPreferencesOutput * This,
            /* [retval][out] */ VARIANT_BOOL *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_PlotPolicy )( 
            IAcadPreferencesOutput * This,
            /* [in] */ enum /* external definition not present */ AcPlotPolicy Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_PlotPolicy )( 
            IAcadPreferencesOutput * This,
            /* [retval][out] */ enum /* external definition not present */ AcPlotPolicy *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultPlotStyleTable )( 
            IAcadPreferencesOutput * This,
            /* [in] */ BSTR Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultPlotStyleTable )( 
            IAcadPreferencesOutput * This,
            /* [retval][out] */ BSTR *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultPlotStyleForObjects )( 
            IAcadPreferencesOutput * This,
            /* [in] */ BSTR Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultPlotStyleForObjects )( 
            IAcadPreferencesOutput * This,
            /* [retval][out] */ BSTR *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultPlotStyleForLayer )( 
            IAcadPreferencesOutput * This,
            /* [in] */ BSTR Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultPlotStyleForLayer )( 
            IAcadPreferencesOutput * This,
            /* [retval][out] */ BSTR *Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Pdf )( 
            IAcadPreferencesOutput * This,
            /* [retval][out] */ IAcadPreferencesPdfOutput **pObj);
        
        END_INTERFACE
    } IAcadPreferencesOutputVtbl;

    interface IAcadPreferencesOutput
    {
        CONST_VTBL struct IAcadPreferencesOutputVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAcadPreferencesOutput_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAcadPreferencesOutput_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAcadPreferencesOutput_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAcadPreferencesOutput_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IAcadPreferencesOutput_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IAcadPreferencesOutput_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IAcadPreferencesOutput_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IAcadPreferencesOutput_get_Application(This,pAppObj)	\
    ( (This)->lpVtbl -> get_Application(This,pAppObj) ) 

#define IAcadPreferencesOutput_put_DefaultOutputDevice(This,Path)	\
    ( (This)->lpVtbl -> put_DefaultOutputDevice(This,Path) ) 

#define IAcadPreferencesOutput_get_DefaultOutputDevice(This,Path)	\
    ( (This)->lpVtbl -> get_DefaultOutputDevice(This,Path) ) 

#define IAcadPreferencesOutput_put_PrinterSpoolAlert(This,Path)	\
    ( (This)->lpVtbl -> put_PrinterSpoolAlert(This,Path) ) 

#define IAcadPreferencesOutput_get_PrinterSpoolAlert(This,Path)	\
    ( (This)->lpVtbl -> get_PrinterSpoolAlert(This,Path) ) 

#define IAcadPreferencesOutput_put_PrinterPaperSizeAlert(This,Path)	\
    ( (This)->lpVtbl -> put_PrinterPaperSizeAlert(This,Path) ) 

#define IAcadPreferencesOutput_get_PrinterPaperSizeAlert(This,Path)	\
    ( (This)->lpVtbl -> get_PrinterPaperSizeAlert(This,Path) ) 

#define IAcadPreferencesOutput_put_PlotLegacy(This,Path)	\
    ( (This)->lpVtbl -> put_PlotLegacy(This,Path) ) 

#define IAcadPreferencesOutput_get_PlotLegacy(This,Path)	\
    ( (This)->lpVtbl -> get_PlotLegacy(This,Path) ) 

#define IAcadPreferencesOutput_put_OLEQuality(This,Path)	\
    ( (This)->lpVtbl -> put_OLEQuality(This,Path) ) 

#define IAcadPreferencesOutput_get_OLEQuality(This,Path)	\
    ( (This)->lpVtbl -> get_OLEQuality(This,Path) ) 

#define IAcadPreferencesOutput_put_UseLastPlotSettings(This,Path)	\
    ( (This)->lpVtbl -> put_UseLastPlotSettings(This,Path) ) 

#define IAcadPreferencesOutput_get_UseLastPlotSettings(This,Path)	\
    ( (This)->lpVtbl -> get_UseLastPlotSettings(This,Path) ) 

#define IAcadPreferencesOutput_put_PlotPolicy(This,Path)	\
    ( (This)->lpVtbl -> put_PlotPolicy(This,Path) ) 

#define IAcadPreferencesOutput_get_PlotPolicy(This,Path)	\
    ( (This)->lpVtbl -> get_PlotPolicy(This,Path) ) 

#define IAcadPreferencesOutput_put_DefaultPlotStyleTable(This,Path)	\
    ( (This)->lpVtbl -> put_DefaultPlotStyleTable(This,Path) ) 

#define IAcadPreferencesOutput_get_DefaultPlotStyleTable(This,Path)	\
    ( (This)->lpVtbl -> get_DefaultPlotStyleTable(This,Path) ) 

#define IAcadPreferencesOutput_put_DefaultPlotStyleForObjects(This,Path)	\
    ( (This)->lpVtbl -> put_DefaultPlotStyleForObjects(This,Path) ) 

#define IAcadPreferencesOutput_get_DefaultPlotStyleForObjects(This,Path)	\
    ( (This)->lpVtbl -> get_DefaultPlotStyleForObjects(This,Path) ) 

#define IAcadPreferencesOutput_put_DefaultPlotStyleForLayer(This,Path)	\
    ( (This)->lpVtbl -> put_DefaultPlotStyleForLayer(This,Path) ) 

#define IAcadPreferencesOutput_get_DefaultPlotStyleForLayer(This,Path)	\
    ( (This)->lpVtbl -> get_DefaultPlotStyleForLayer(This,Path) ) 

#define IAcadPreferencesOutput_get_Pdf(This,pObj)	\
    ( (This)->lpVtbl -> get_Pdf(This,pObj) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAcadPreferencesOutput_INTERFACE_DEFINED__ */


#ifndef __IAcadPreferencesPdfOutput_INTERFACE_DEFINED__
#define __IAcadPreferencesPdfOutput_INTERFACE_DEFINED__

/* interface IAcadPreferencesPdfOutput */
/* [object][oleautomation][dual][helpstring][uuid] */ 


EXTERN_C const IID IID_IAcadPreferencesPdfOutput;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("21F2EB66-F27E-40af-A3F5-7F2E7D6F6AA6")
    IAcadPreferencesPdfOutput : public IDispatch
    {
    public:
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Application( 
            /* [retval][out] */ IAcadApplication **pAppObj) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_ZoomToExtents( 
            /* [in] */ VARIANT_BOOL Flag) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ZoomToExtents( 
            /* [retval][out] */ VARIANT_BOOL *Flag) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_PaperSizeOverride( 
            /* [in] */ VARIANT_BOOL Flag) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_PaperSizeOverride( 
            /* [retval][out] */ VARIANT_BOOL *Flag) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_ShxTextAsGeometry( 
            /* [in] */ VARIANT_BOOL Flag) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ShxTextAsGeometry( 
            /* [retval][out] */ VARIANT_BOOL *Flag) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_SimpleGeomOptimization( 
            /* [in] */ VARIANT_BOOL Flag) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_SimpleGeomOptimization( 
            /* [retval][out] */ VARIANT_BOOL *Flag) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_TtfTextAsGeometry( 
            /* [in] */ VARIANT_BOOL Flag) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_TtfTextAsGeometry( 
            /* [retval][out] */ VARIANT_BOOL *Flag) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_EmbeddedTtf( 
            /* [in] */ VARIANT_BOOL Flag) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_EmbeddedTtf( 
            /* [retval][out] */ VARIANT_BOOL *Flag) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_LayersSetting( 
            /* [in] */ PdfExportLayerSettingType Value) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_LayersSetting( 
            /* [retval][out] */ PdfExportLayerSettingType *Value) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_LayoutsToExport( 
            /* [in] */ PdfExportLayoutSettingType Value) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_LayoutsToExport( 
            /* [retval][out] */ PdfExportLayoutSettingType *Value) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_PaperHeight( 
            /* [in] */ long Value) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_PaperHeight( 
            /* [retval][out] */ long *Value) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_PaperWidth( 
            /* [in] */ long Value) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_PaperWidth( 
            /* [retval][out] */ long *Value) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_UsePlotStyles( 
            /* [in] */ VARIANT_BOOL Value) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_UsePlotStyles( 
            /* [retval][out] */ VARIANT_BOOL *Value) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_ExportHyperlinks( 
            /* [in] */ VARIANT_BOOL Value) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ExportHyperlinks( 
            /* [retval][out] */ VARIANT_BOOL *Value) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAcadPreferencesPdfOutputVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAcadPreferencesPdfOutput * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAcadPreferencesPdfOutput * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAcadPreferencesPdfOutput * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IAcadPreferencesPdfOutput * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IAcadPreferencesPdfOutput * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IAcadPreferencesPdfOutput * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IAcadPreferencesPdfOutput * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Application )( 
            IAcadPreferencesPdfOutput * This,
            /* [retval][out] */ IAcadApplication **pAppObj);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_ZoomToExtents )( 
            IAcadPreferencesPdfOutput * This,
            /* [in] */ VARIANT_BOOL Flag);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ZoomToExtents )( 
            IAcadPreferencesPdfOutput * This,
            /* [retval][out] */ VARIANT_BOOL *Flag);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_PaperSizeOverride )( 
            IAcadPreferencesPdfOutput * This,
            /* [in] */ VARIANT_BOOL Flag);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_PaperSizeOverride )( 
            IAcadPreferencesPdfOutput * This,
            /* [retval][out] */ VARIANT_BOOL *Flag);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_ShxTextAsGeometry )( 
            IAcadPreferencesPdfOutput * This,
            /* [in] */ VARIANT_BOOL Flag);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ShxTextAsGeometry )( 
            IAcadPreferencesPdfOutput * This,
            /* [retval][out] */ VARIANT_BOOL *Flag);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_SimpleGeomOptimization )( 
            IAcadPreferencesPdfOutput * This,
            /* [in] */ VARIANT_BOOL Flag);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_SimpleGeomOptimization )( 
            IAcadPreferencesPdfOutput * This,
            /* [retval][out] */ VARIANT_BOOL *Flag);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_TtfTextAsGeometry )( 
            IAcadPreferencesPdfOutput * This,
            /* [in] */ VARIANT_BOOL Flag);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_TtfTextAsGeometry )( 
            IAcadPreferencesPdfOutput * This,
            /* [retval][out] */ VARIANT_BOOL *Flag);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_EmbeddedTtf )( 
            IAcadPreferencesPdfOutput * This,
            /* [in] */ VARIANT_BOOL Flag);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_EmbeddedTtf )( 
            IAcadPreferencesPdfOutput * This,
            /* [retval][out] */ VARIANT_BOOL *Flag);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_LayersSetting )( 
            IAcadPreferencesPdfOutput * This,
            /* [in] */ PdfExportLayerSettingType Value);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_LayersSetting )( 
            IAcadPreferencesPdfOutput * This,
            /* [retval][out] */ PdfExportLayerSettingType *Value);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_LayoutsToExport )( 
            IAcadPreferencesPdfOutput * This,
            /* [in] */ PdfExportLayoutSettingType Value);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_LayoutsToExport )( 
            IAcadPreferencesPdfOutput * This,
            /* [retval][out] */ PdfExportLayoutSettingType *Value);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_PaperHeight )( 
            IAcadPreferencesPdfOutput * This,
            /* [in] */ long Value);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_PaperHeight )( 
            IAcadPreferencesPdfOutput * This,
            /* [retval][out] */ long *Value);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_PaperWidth )( 
            IAcadPreferencesPdfOutput * This,
            /* [in] */ long Value);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_PaperWidth )( 
            IAcadPreferencesPdfOutput * This,
            /* [retval][out] */ long *Value);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_UsePlotStyles )( 
            IAcadPreferencesPdfOutput * This,
            /* [in] */ VARIANT_BOOL Value);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_UsePlotStyles )( 
            IAcadPreferencesPdfOutput * This,
            /* [retval][out] */ VARIANT_BOOL *Value);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_ExportHyperlinks )( 
            IAcadPreferencesPdfOutput * This,
            /* [in] */ VARIANT_BOOL Value);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ExportHyperlinks )( 
            IAcadPreferencesPdfOutput * This,
            /* [retval][out] */ VARIANT_BOOL *Value);
        
        END_INTERFACE
    } IAcadPreferencesPdfOutputVtbl;

    interface IAcadPreferencesPdfOutput
    {
        CONST_VTBL struct IAcadPreferencesPdfOutputVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAcadPreferencesPdfOutput_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAcadPreferencesPdfOutput_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAcadPreferencesPdfOutput_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAcadPreferencesPdfOutput_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IAcadPreferencesPdfOutput_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IAcadPreferencesPdfOutput_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IAcadPreferencesPdfOutput_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IAcadPreferencesPdfOutput_get_Application(This,pAppObj)	\
    ( (This)->lpVtbl -> get_Application(This,pAppObj) ) 

#define IAcadPreferencesPdfOutput_put_ZoomToExtents(This,Flag)	\
    ( (This)->lpVtbl -> put_ZoomToExtents(This,Flag) ) 

#define IAcadPreferencesPdfOutput_get_ZoomToExtents(This,Flag)	\
    ( (This)->lpVtbl -> get_ZoomToExtents(This,Flag) ) 

#define IAcadPreferencesPdfOutput_put_PaperSizeOverride(This,Flag)	\
    ( (This)->lpVtbl -> put_PaperSizeOverride(This,Flag) ) 

#define IAcadPreferencesPdfOutput_get_PaperSizeOverride(This,Flag)	\
    ( (This)->lpVtbl -> get_PaperSizeOverride(This,Flag) ) 

#define IAcadPreferencesPdfOutput_put_ShxTextAsGeometry(This,Flag)	\
    ( (This)->lpVtbl -> put_ShxTextAsGeometry(This,Flag) ) 

#define IAcadPreferencesPdfOutput_get_ShxTextAsGeometry(This,Flag)	\
    ( (This)->lpVtbl -> get_ShxTextAsGeometry(This,Flag) ) 

#define IAcadPreferencesPdfOutput_put_SimpleGeomOptimization(This,Flag)	\
    ( (This)->lpVtbl -> put_SimpleGeomOptimization(This,Flag) ) 

#define IAcadPreferencesPdfOutput_get_SimpleGeomOptimization(This,Flag)	\
    ( (This)->lpVtbl -> get_SimpleGeomOptimization(This,Flag) ) 

#define IAcadPreferencesPdfOutput_put_TtfTextAsGeometry(This,Flag)	\
    ( (This)->lpVtbl -> put_TtfTextAsGeometry(This,Flag) ) 

#define IAcadPreferencesPdfOutput_get_TtfTextAsGeometry(This,Flag)	\
    ( (This)->lpVtbl -> get_TtfTextAsGeometry(This,Flag) ) 

#define IAcadPreferencesPdfOutput_put_EmbeddedTtf(This,Flag)	\
    ( (This)->lpVtbl -> put_EmbeddedTtf(This,Flag) ) 

#define IAcadPreferencesPdfOutput_get_EmbeddedTtf(This,Flag)	\
    ( (This)->lpVtbl -> get_EmbeddedTtf(This,Flag) ) 

#define IAcadPreferencesPdfOutput_put_LayersSetting(This,Value)	\
    ( (This)->lpVtbl -> put_LayersSetting(This,Value) ) 

#define IAcadPreferencesPdfOutput_get_LayersSetting(This,Value)	\
    ( (This)->lpVtbl -> get_LayersSetting(This,Value) ) 

#define IAcadPreferencesPdfOutput_put_LayoutsToExport(This,Value)	\
    ( (This)->lpVtbl -> put_LayoutsToExport(This,Value) ) 

#define IAcadPreferencesPdfOutput_get_LayoutsToExport(This,Value)	\
    ( (This)->lpVtbl -> get_LayoutsToExport(This,Value) ) 

#define IAcadPreferencesPdfOutput_put_PaperHeight(This,Value)	\
    ( (This)->lpVtbl -> put_PaperHeight(This,Value) ) 

#define IAcadPreferencesPdfOutput_get_PaperHeight(This,Value)	\
    ( (This)->lpVtbl -> get_PaperHeight(This,Value) ) 

#define IAcadPreferencesPdfOutput_put_PaperWidth(This,Value)	\
    ( (This)->lpVtbl -> put_PaperWidth(This,Value) ) 

#define IAcadPreferencesPdfOutput_get_PaperWidth(This,Value)	\
    ( (This)->lpVtbl -> get_PaperWidth(This,Value) ) 

#define IAcadPreferencesPdfOutput_put_UsePlotStyles(This,Value)	\
    ( (This)->lpVtbl -> put_UsePlotStyles(This,Value) ) 

#define IAcadPreferencesPdfOutput_get_UsePlotStyles(This,Value)	\
    ( (This)->lpVtbl -> get_UsePlotStyles(This,Value) ) 

#define IAcadPreferencesPdfOutput_put_ExportHyperlinks(This,Value)	\
    ( (This)->lpVtbl -> put_ExportHyperlinks(This,Value) ) 

#define IAcadPreferencesPdfOutput_get_ExportHyperlinks(This,Value)	\
    ( (This)->lpVtbl -> get_ExportHyperlinks(This,Value) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAcadPreferencesPdfOutput_INTERFACE_DEFINED__ */


#ifndef __IAcadPreferencesSystem_INTERFACE_DEFINED__
#define __IAcadPreferencesSystem_INTERFACE_DEFINED__

/* interface IAcadPreferencesSystem */
/* [object][oleautomation][dual][helpstring][uuid] */ 


EXTERN_C const IID IID_IAcadPreferencesSystem;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("408546BA-FF59-4aa8-98C5-A1DBA4B730F8")
    IAcadPreferencesSystem : public IDispatch
    {
    public:
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Application( 
            /* [retval][out] */ IAcadApplication **pAppObj) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_SingleDocumentMode( 
            /* [in] */ VARIANT_BOOL Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_SingleDocumentMode( 
            /* [retval][out] */ VARIANT_BOOL *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_DisplayOLEScale( 
            /* [in] */ VARIANT_BOOL Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_DisplayOLEScale( 
            /* [retval][out] */ VARIANT_BOOL *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_StoreSQLIndex( 
            /* [in] */ VARIANT_BOOL Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_StoreSQLIndex( 
            /* [retval][out] */ VARIANT_BOOL *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_TablesReadOnly( 
            /* [in] */ VARIANT_BOOL Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_TablesReadOnly( 
            /* [retval][out] */ VARIANT_BOOL *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_EnableStartupDialog( 
            /* [in] */ VARIANT_BOOL Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_EnableStartupDialog( 
            /* [retval][out] */ VARIANT_BOOL *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_BeepOnError( 
            /* [in] */ VARIANT_BOOL BeepOnError) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_BeepOnError( 
            /* [retval][out] */ VARIANT_BOOL *BeepOnError) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_ShowWarningMessages( 
            /* [in] */ VARIANT_BOOL Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ShowWarningMessages( 
            /* [retval][out] */ VARIANT_BOOL *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_LoadAcadLspInAllDocuments( 
            /* [in] */ VARIANT_BOOL pALID) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_LoadAcadLspInAllDocuments( 
            /* [retval][out] */ VARIANT_BOOL *pALID) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAcadPreferencesSystemVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAcadPreferencesSystem * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAcadPreferencesSystem * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAcadPreferencesSystem * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IAcadPreferencesSystem * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IAcadPreferencesSystem * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IAcadPreferencesSystem * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IAcadPreferencesSystem * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Application )( 
            IAcadPreferencesSystem * This,
            /* [retval][out] */ IAcadApplication **pAppObj);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_SingleDocumentMode )( 
            IAcadPreferencesSystem * This,
            /* [in] */ VARIANT_BOOL Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_SingleDocumentMode )( 
            IAcadPreferencesSystem * This,
            /* [retval][out] */ VARIANT_BOOL *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_DisplayOLEScale )( 
            IAcadPreferencesSystem * This,
            /* [in] */ VARIANT_BOOL Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_DisplayOLEScale )( 
            IAcadPreferencesSystem * This,
            /* [retval][out] */ VARIANT_BOOL *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_StoreSQLIndex )( 
            IAcadPreferencesSystem * This,
            /* [in] */ VARIANT_BOOL Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_StoreSQLIndex )( 
            IAcadPreferencesSystem * This,
            /* [retval][out] */ VARIANT_BOOL *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_TablesReadOnly )( 
            IAcadPreferencesSystem * This,
            /* [in] */ VARIANT_BOOL Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_TablesReadOnly )( 
            IAcadPreferencesSystem * This,
            /* [retval][out] */ VARIANT_BOOL *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_EnableStartupDialog )( 
            IAcadPreferencesSystem * This,
            /* [in] */ VARIANT_BOOL Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_EnableStartupDialog )( 
            IAcadPreferencesSystem * This,
            /* [retval][out] */ VARIANT_BOOL *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_BeepOnError )( 
            IAcadPreferencesSystem * This,
            /* [in] */ VARIANT_BOOL BeepOnError);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_BeepOnError )( 
            IAcadPreferencesSystem * This,
            /* [retval][out] */ VARIANT_BOOL *BeepOnError);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_ShowWarningMessages )( 
            IAcadPreferencesSystem * This,
            /* [in] */ VARIANT_BOOL Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ShowWarningMessages )( 
            IAcadPreferencesSystem * This,
            /* [retval][out] */ VARIANT_BOOL *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_LoadAcadLspInAllDocuments )( 
            IAcadPreferencesSystem * This,
            /* [in] */ VARIANT_BOOL pALID);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_LoadAcadLspInAllDocuments )( 
            IAcadPreferencesSystem * This,
            /* [retval][out] */ VARIANT_BOOL *pALID);
        
        END_INTERFACE
    } IAcadPreferencesSystemVtbl;

    interface IAcadPreferencesSystem
    {
        CONST_VTBL struct IAcadPreferencesSystemVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAcadPreferencesSystem_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAcadPreferencesSystem_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAcadPreferencesSystem_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAcadPreferencesSystem_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IAcadPreferencesSystem_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IAcadPreferencesSystem_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IAcadPreferencesSystem_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IAcadPreferencesSystem_get_Application(This,pAppObj)	\
    ( (This)->lpVtbl -> get_Application(This,pAppObj) ) 

#define IAcadPreferencesSystem_put_SingleDocumentMode(This,Path)	\
    ( (This)->lpVtbl -> put_SingleDocumentMode(This,Path) ) 

#define IAcadPreferencesSystem_get_SingleDocumentMode(This,Path)	\
    ( (This)->lpVtbl -> get_SingleDocumentMode(This,Path) ) 

#define IAcadPreferencesSystem_put_DisplayOLEScale(This,Path)	\
    ( (This)->lpVtbl -> put_DisplayOLEScale(This,Path) ) 

#define IAcadPreferencesSystem_get_DisplayOLEScale(This,Path)	\
    ( (This)->lpVtbl -> get_DisplayOLEScale(This,Path) ) 

#define IAcadPreferencesSystem_put_StoreSQLIndex(This,Path)	\
    ( (This)->lpVtbl -> put_StoreSQLIndex(This,Path) ) 

#define IAcadPreferencesSystem_get_StoreSQLIndex(This,Path)	\
    ( (This)->lpVtbl -> get_StoreSQLIndex(This,Path) ) 

#define IAcadPreferencesSystem_put_TablesReadOnly(This,Path)	\
    ( (This)->lpVtbl -> put_TablesReadOnly(This,Path) ) 

#define IAcadPreferencesSystem_get_TablesReadOnly(This,Path)	\
    ( (This)->lpVtbl -> get_TablesReadOnly(This,Path) ) 

#define IAcadPreferencesSystem_put_EnableStartupDialog(This,Path)	\
    ( (This)->lpVtbl -> put_EnableStartupDialog(This,Path) ) 

#define IAcadPreferencesSystem_get_EnableStartupDialog(This,Path)	\
    ( (This)->lpVtbl -> get_EnableStartupDialog(This,Path) ) 

#define IAcadPreferencesSystem_put_BeepOnError(This,BeepOnError)	\
    ( (This)->lpVtbl -> put_BeepOnError(This,BeepOnError) ) 

#define IAcadPreferencesSystem_get_BeepOnError(This,BeepOnError)	\
    ( (This)->lpVtbl -> get_BeepOnError(This,BeepOnError) ) 

#define IAcadPreferencesSystem_put_ShowWarningMessages(This,Path)	\
    ( (This)->lpVtbl -> put_ShowWarningMessages(This,Path) ) 

#define IAcadPreferencesSystem_get_ShowWarningMessages(This,Path)	\
    ( (This)->lpVtbl -> get_ShowWarningMessages(This,Path) ) 

#define IAcadPreferencesSystem_put_LoadAcadLspInAllDocuments(This,pALID)	\
    ( (This)->lpVtbl -> put_LoadAcadLspInAllDocuments(This,pALID) ) 

#define IAcadPreferencesSystem_get_LoadAcadLspInAllDocuments(This,pALID)	\
    ( (This)->lpVtbl -> get_LoadAcadLspInAllDocuments(This,pALID) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAcadPreferencesSystem_INTERFACE_DEFINED__ */


#ifndef __IAcadPreferencesUser_INTERFACE_DEFINED__
#define __IAcadPreferencesUser_INTERFACE_DEFINED__

/* interface IAcadPreferencesUser */
/* [object][oleautomation][dual][helpstring][uuid] */ 


EXTERN_C const IID IID_IAcadPreferencesUser;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("689AE380-B75C-430e-8A70-D116D8B4FA63")
    IAcadPreferencesUser : public IDispatch
    {
    public:
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Application( 
            /* [retval][out] */ IAcadApplication **pAppObj) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_KeyboardAccelerator( 
            /* [in] */ enum /* external definition not present */ AcKeyboardAccelerator Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_KeyboardAccelerator( 
            /* [retval][out] */ enum /* external definition not present */ AcKeyboardAccelerator *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_KeyboardPriority( 
            /* [in] */ enum /* external definition not present */ AcKeyboardPriority Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_KeyboardPriority( 
            /* [retval][out] */ enum /* external definition not present */ AcKeyboardPriority *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_HyperlinkDisplayCursor( 
            /* [in] */ VARIANT_BOOL Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_HyperlinkDisplayCursor( 
            /* [retval][out] */ VARIANT_BOOL *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_HyperlinkDisplayTooltip( 
            /* [in] */ VARIANT_BOOL Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_HyperlinkDisplayTooltip( 
            /* [retval][out] */ VARIANT_BOOL *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_ADCInsertUnitsDefaultSource( 
            /* [in] */ enum /* external definition not present */ AcInsertUnits pIU) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ADCInsertUnitsDefaultSource( 
            /* [retval][out] */ enum /* external definition not present */ AcInsertUnits *pIU) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_ADCInsertUnitsDefaultTarget( 
            /* [in] */ enum /* external definition not present */ AcInsertUnits pSUunits) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ADCInsertUnitsDefaultTarget( 
            /* [retval][out] */ enum /* external definition not present */ AcInsertUnits *pSUunits) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_ShortCutMenuDisplay( 
            /* [in] */ VARIANT_BOOL pSCM) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ShortCutMenuDisplay( 
            /* [retval][out] */ VARIANT_BOOL *pSCM) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_SCMDefaultMode( 
            /* [in] */ enum /* external definition not present */ AcDrawingAreaSCMDefault pSCM) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_SCMDefaultMode( 
            /* [retval][out] */ enum /* external definition not present */ AcDrawingAreaSCMDefault *pSCM) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_SCMEditMode( 
            /* [in] */ enum /* external definition not present */ AcDrawingAreaSCMEdit pSCM) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_SCMEditMode( 
            /* [retval][out] */ enum /* external definition not present */ AcDrawingAreaSCMEdit *pSCM) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_SCMCommandMode( 
            /* [in] */ enum /* external definition not present */ AcDrawingAreaSCMCommand pSCM) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_SCMCommandMode( 
            /* [retval][out] */ enum /* external definition not present */ AcDrawingAreaSCMCommand *pSCM) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_SCMTimeMode( 
            /* [in] */ VARIANT_BOOL time) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_SCMTimeMode( 
            /* [retval][out] */ VARIANT_BOOL *time) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_SCMTimeValue( 
            /* [in] */ int time) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_SCMTimeValue( 
            /* [retval][out] */ int *time) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAcadPreferencesUserVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAcadPreferencesUser * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAcadPreferencesUser * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAcadPreferencesUser * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IAcadPreferencesUser * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IAcadPreferencesUser * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IAcadPreferencesUser * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IAcadPreferencesUser * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Application )( 
            IAcadPreferencesUser * This,
            /* [retval][out] */ IAcadApplication **pAppObj);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_KeyboardAccelerator )( 
            IAcadPreferencesUser * This,
            /* [in] */ enum /* external definition not present */ AcKeyboardAccelerator Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_KeyboardAccelerator )( 
            IAcadPreferencesUser * This,
            /* [retval][out] */ enum /* external definition not present */ AcKeyboardAccelerator *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_KeyboardPriority )( 
            IAcadPreferencesUser * This,
            /* [in] */ enum /* external definition not present */ AcKeyboardPriority Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_KeyboardPriority )( 
            IAcadPreferencesUser * This,
            /* [retval][out] */ enum /* external definition not present */ AcKeyboardPriority *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_HyperlinkDisplayCursor )( 
            IAcadPreferencesUser * This,
            /* [in] */ VARIANT_BOOL Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_HyperlinkDisplayCursor )( 
            IAcadPreferencesUser * This,
            /* [retval][out] */ VARIANT_BOOL *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_HyperlinkDisplayTooltip )( 
            IAcadPreferencesUser * This,
            /* [in] */ VARIANT_BOOL Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_HyperlinkDisplayTooltip )( 
            IAcadPreferencesUser * This,
            /* [retval][out] */ VARIANT_BOOL *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_ADCInsertUnitsDefaultSource )( 
            IAcadPreferencesUser * This,
            /* [in] */ enum /* external definition not present */ AcInsertUnits pIU);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ADCInsertUnitsDefaultSource )( 
            IAcadPreferencesUser * This,
            /* [retval][out] */ enum /* external definition not present */ AcInsertUnits *pIU);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_ADCInsertUnitsDefaultTarget )( 
            IAcadPreferencesUser * This,
            /* [in] */ enum /* external definition not present */ AcInsertUnits pSUunits);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ADCInsertUnitsDefaultTarget )( 
            IAcadPreferencesUser * This,
            /* [retval][out] */ enum /* external definition not present */ AcInsertUnits *pSUunits);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_ShortCutMenuDisplay )( 
            IAcadPreferencesUser * This,
            /* [in] */ VARIANT_BOOL pSCM);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ShortCutMenuDisplay )( 
            IAcadPreferencesUser * This,
            /* [retval][out] */ VARIANT_BOOL *pSCM);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_SCMDefaultMode )( 
            IAcadPreferencesUser * This,
            /* [in] */ enum /* external definition not present */ AcDrawingAreaSCMDefault pSCM);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_SCMDefaultMode )( 
            IAcadPreferencesUser * This,
            /* [retval][out] */ enum /* external definition not present */ AcDrawingAreaSCMDefault *pSCM);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_SCMEditMode )( 
            IAcadPreferencesUser * This,
            /* [in] */ enum /* external definition not present */ AcDrawingAreaSCMEdit pSCM);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_SCMEditMode )( 
            IAcadPreferencesUser * This,
            /* [retval][out] */ enum /* external definition not present */ AcDrawingAreaSCMEdit *pSCM);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_SCMCommandMode )( 
            IAcadPreferencesUser * This,
            /* [in] */ enum /* external definition not present */ AcDrawingAreaSCMCommand pSCM);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_SCMCommandMode )( 
            IAcadPreferencesUser * This,
            /* [retval][out] */ enum /* external definition not present */ AcDrawingAreaSCMCommand *pSCM);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_SCMTimeMode )( 
            IAcadPreferencesUser * This,
            /* [in] */ VARIANT_BOOL time);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_SCMTimeMode )( 
            IAcadPreferencesUser * This,
            /* [retval][out] */ VARIANT_BOOL *time);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_SCMTimeValue )( 
            IAcadPreferencesUser * This,
            /* [in] */ int time);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_SCMTimeValue )( 
            IAcadPreferencesUser * This,
            /* [retval][out] */ int *time);
        
        END_INTERFACE
    } IAcadPreferencesUserVtbl;

    interface IAcadPreferencesUser
    {
        CONST_VTBL struct IAcadPreferencesUserVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAcadPreferencesUser_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAcadPreferencesUser_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAcadPreferencesUser_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAcadPreferencesUser_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IAcadPreferencesUser_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IAcadPreferencesUser_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IAcadPreferencesUser_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IAcadPreferencesUser_get_Application(This,pAppObj)	\
    ( (This)->lpVtbl -> get_Application(This,pAppObj) ) 

#define IAcadPreferencesUser_put_KeyboardAccelerator(This,Path)	\
    ( (This)->lpVtbl -> put_KeyboardAccelerator(This,Path) ) 

#define IAcadPreferencesUser_get_KeyboardAccelerator(This,Path)	\
    ( (This)->lpVtbl -> get_KeyboardAccelerator(This,Path) ) 

#define IAcadPreferencesUser_put_KeyboardPriority(This,Path)	\
    ( (This)->lpVtbl -> put_KeyboardPriority(This,Path) ) 

#define IAcadPreferencesUser_get_KeyboardPriority(This,Path)	\
    ( (This)->lpVtbl -> get_KeyboardPriority(This,Path) ) 

#define IAcadPreferencesUser_put_HyperlinkDisplayCursor(This,Path)	\
    ( (This)->lpVtbl -> put_HyperlinkDisplayCursor(This,Path) ) 

#define IAcadPreferencesUser_get_HyperlinkDisplayCursor(This,Path)	\
    ( (This)->lpVtbl -> get_HyperlinkDisplayCursor(This,Path) ) 

#define IAcadPreferencesUser_put_HyperlinkDisplayTooltip(This,Path)	\
    ( (This)->lpVtbl -> put_HyperlinkDisplayTooltip(This,Path) ) 

#define IAcadPreferencesUser_get_HyperlinkDisplayTooltip(This,Path)	\
    ( (This)->lpVtbl -> get_HyperlinkDisplayTooltip(This,Path) ) 

#define IAcadPreferencesUser_put_ADCInsertUnitsDefaultSource(This,pIU)	\
    ( (This)->lpVtbl -> put_ADCInsertUnitsDefaultSource(This,pIU) ) 

#define IAcadPreferencesUser_get_ADCInsertUnitsDefaultSource(This,pIU)	\
    ( (This)->lpVtbl -> get_ADCInsertUnitsDefaultSource(This,pIU) ) 

#define IAcadPreferencesUser_put_ADCInsertUnitsDefaultTarget(This,pSUunits)	\
    ( (This)->lpVtbl -> put_ADCInsertUnitsDefaultTarget(This,pSUunits) ) 

#define IAcadPreferencesUser_get_ADCInsertUnitsDefaultTarget(This,pSUunits)	\
    ( (This)->lpVtbl -> get_ADCInsertUnitsDefaultTarget(This,pSUunits) ) 

#define IAcadPreferencesUser_put_ShortCutMenuDisplay(This,pSCM)	\
    ( (This)->lpVtbl -> put_ShortCutMenuDisplay(This,pSCM) ) 

#define IAcadPreferencesUser_get_ShortCutMenuDisplay(This,pSCM)	\
    ( (This)->lpVtbl -> get_ShortCutMenuDisplay(This,pSCM) ) 

#define IAcadPreferencesUser_put_SCMDefaultMode(This,pSCM)	\
    ( (This)->lpVtbl -> put_SCMDefaultMode(This,pSCM) ) 

#define IAcadPreferencesUser_get_SCMDefaultMode(This,pSCM)	\
    ( (This)->lpVtbl -> get_SCMDefaultMode(This,pSCM) ) 

#define IAcadPreferencesUser_put_SCMEditMode(This,pSCM)	\
    ( (This)->lpVtbl -> put_SCMEditMode(This,pSCM) ) 

#define IAcadPreferencesUser_get_SCMEditMode(This,pSCM)	\
    ( (This)->lpVtbl -> get_SCMEditMode(This,pSCM) ) 

#define IAcadPreferencesUser_put_SCMCommandMode(This,pSCM)	\
    ( (This)->lpVtbl -> put_SCMCommandMode(This,pSCM) ) 

#define IAcadPreferencesUser_get_SCMCommandMode(This,pSCM)	\
    ( (This)->lpVtbl -> get_SCMCommandMode(This,pSCM) ) 

#define IAcadPreferencesUser_put_SCMTimeMode(This,time)	\
    ( (This)->lpVtbl -> put_SCMTimeMode(This,time) ) 

#define IAcadPreferencesUser_get_SCMTimeMode(This,time)	\
    ( (This)->lpVtbl -> get_SCMTimeMode(This,time) ) 

#define IAcadPreferencesUser_put_SCMTimeValue(This,time)	\
    ( (This)->lpVtbl -> put_SCMTimeValue(This,time) ) 

#define IAcadPreferencesUser_get_SCMTimeValue(This,time)	\
    ( (This)->lpVtbl -> get_SCMTimeValue(This,time) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAcadPreferencesUser_INTERFACE_DEFINED__ */


#ifndef __IAcadPreferencesDrafting_INTERFACE_DEFINED__
#define __IAcadPreferencesDrafting_INTERFACE_DEFINED__

/* interface IAcadPreferencesDrafting */
/* [object][oleautomation][dual][helpstring][uuid] */ 


EXTERN_C const IID IID_IAcadPreferencesDrafting;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("35D9C296-C2E9-4dab-93CA-4A62F71C9FC1")
    IAcadPreferencesDrafting : public IDispatch
    {
    public:
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Application( 
            /* [retval][out] */ IAcadApplication **pAppObj) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_AutoSnapMarker( 
            /* [in] */ VARIANT_BOOL Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_AutoSnapMarker( 
            /* [retval][out] */ VARIANT_BOOL *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_AutoSnapMagnet( 
            /* [in] */ VARIANT_BOOL Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_AutoSnapMagnet( 
            /* [retval][out] */ VARIANT_BOOL *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_AutoSnapTooltip( 
            /* [in] */ VARIANT_BOOL Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_AutoSnapTooltip( 
            /* [retval][out] */ VARIANT_BOOL *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_AutoSnapAperture( 
            /* [in] */ VARIANT_BOOL Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_AutoSnapAperture( 
            /* [retval][out] */ VARIANT_BOOL *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_AutoSnapApertureSize( 
            /* [in] */ long Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_AutoSnapApertureSize( 
            /* [retval][out] */ long *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_AutoSnapMarkerColor( 
            /* [in] */ enum /* external definition not present */ AcColor Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_AutoSnapMarkerColor( 
            /* [retval][out] */ enum /* external definition not present */ AcColor *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_AutoSnapMarkerSize( 
            /* [in] */ long Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_AutoSnapMarkerSize( 
            /* [retval][out] */ long *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_PolarTrackingVector( 
            /* [in] */ VARIANT_BOOL Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_PolarTrackingVector( 
            /* [retval][out] */ VARIANT_BOOL *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_FullScreenTrackingVector( 
            /* [in] */ VARIANT_BOOL Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_FullScreenTrackingVector( 
            /* [retval][out] */ VARIANT_BOOL *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_AutoTrackTooltip( 
            /* [in] */ VARIANT_BOOL Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_AutoTrackTooltip( 
            /* [retval][out] */ VARIANT_BOOL *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_AlignmentPointAcquisition( 
            /* [in] */ enum /* external definition not present */ AcAlignmentPointAcquisition Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_AlignmentPointAcquisition( 
            /* [retval][out] */ enum /* external definition not present */ AcAlignmentPointAcquisition *Path) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAcadPreferencesDraftingVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAcadPreferencesDrafting * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAcadPreferencesDrafting * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAcadPreferencesDrafting * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IAcadPreferencesDrafting * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IAcadPreferencesDrafting * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IAcadPreferencesDrafting * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IAcadPreferencesDrafting * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Application )( 
            IAcadPreferencesDrafting * This,
            /* [retval][out] */ IAcadApplication **pAppObj);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_AutoSnapMarker )( 
            IAcadPreferencesDrafting * This,
            /* [in] */ VARIANT_BOOL Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_AutoSnapMarker )( 
            IAcadPreferencesDrafting * This,
            /* [retval][out] */ VARIANT_BOOL *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_AutoSnapMagnet )( 
            IAcadPreferencesDrafting * This,
            /* [in] */ VARIANT_BOOL Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_AutoSnapMagnet )( 
            IAcadPreferencesDrafting * This,
            /* [retval][out] */ VARIANT_BOOL *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_AutoSnapTooltip )( 
            IAcadPreferencesDrafting * This,
            /* [in] */ VARIANT_BOOL Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_AutoSnapTooltip )( 
            IAcadPreferencesDrafting * This,
            /* [retval][out] */ VARIANT_BOOL *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_AutoSnapAperture )( 
            IAcadPreferencesDrafting * This,
            /* [in] */ VARIANT_BOOL Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_AutoSnapAperture )( 
            IAcadPreferencesDrafting * This,
            /* [retval][out] */ VARIANT_BOOL *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_AutoSnapApertureSize )( 
            IAcadPreferencesDrafting * This,
            /* [in] */ long Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_AutoSnapApertureSize )( 
            IAcadPreferencesDrafting * This,
            /* [retval][out] */ long *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_AutoSnapMarkerColor )( 
            IAcadPreferencesDrafting * This,
            /* [in] */ enum /* external definition not present */ AcColor Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_AutoSnapMarkerColor )( 
            IAcadPreferencesDrafting * This,
            /* [retval][out] */ enum /* external definition not present */ AcColor *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_AutoSnapMarkerSize )( 
            IAcadPreferencesDrafting * This,
            /* [in] */ long Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_AutoSnapMarkerSize )( 
            IAcadPreferencesDrafting * This,
            /* [retval][out] */ long *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_PolarTrackingVector )( 
            IAcadPreferencesDrafting * This,
            /* [in] */ VARIANT_BOOL Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_PolarTrackingVector )( 
            IAcadPreferencesDrafting * This,
            /* [retval][out] */ VARIANT_BOOL *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_FullScreenTrackingVector )( 
            IAcadPreferencesDrafting * This,
            /* [in] */ VARIANT_BOOL Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_FullScreenTrackingVector )( 
            IAcadPreferencesDrafting * This,
            /* [retval][out] */ VARIANT_BOOL *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_AutoTrackTooltip )( 
            IAcadPreferencesDrafting * This,
            /* [in] */ VARIANT_BOOL Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_AutoTrackTooltip )( 
            IAcadPreferencesDrafting * This,
            /* [retval][out] */ VARIANT_BOOL *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_AlignmentPointAcquisition )( 
            IAcadPreferencesDrafting * This,
            /* [in] */ enum /* external definition not present */ AcAlignmentPointAcquisition Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_AlignmentPointAcquisition )( 
            IAcadPreferencesDrafting * This,
            /* [retval][out] */ enum /* external definition not present */ AcAlignmentPointAcquisition *Path);
        
        END_INTERFACE
    } IAcadPreferencesDraftingVtbl;

    interface IAcadPreferencesDrafting
    {
        CONST_VTBL struct IAcadPreferencesDraftingVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAcadPreferencesDrafting_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAcadPreferencesDrafting_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAcadPreferencesDrafting_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAcadPreferencesDrafting_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IAcadPreferencesDrafting_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IAcadPreferencesDrafting_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IAcadPreferencesDrafting_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IAcadPreferencesDrafting_get_Application(This,pAppObj)	\
    ( (This)->lpVtbl -> get_Application(This,pAppObj) ) 

#define IAcadPreferencesDrafting_put_AutoSnapMarker(This,Path)	\
    ( (This)->lpVtbl -> put_AutoSnapMarker(This,Path) ) 

#define IAcadPreferencesDrafting_get_AutoSnapMarker(This,Path)	\
    ( (This)->lpVtbl -> get_AutoSnapMarker(This,Path) ) 

#define IAcadPreferencesDrafting_put_AutoSnapMagnet(This,Path)	\
    ( (This)->lpVtbl -> put_AutoSnapMagnet(This,Path) ) 

#define IAcadPreferencesDrafting_get_AutoSnapMagnet(This,Path)	\
    ( (This)->lpVtbl -> get_AutoSnapMagnet(This,Path) ) 

#define IAcadPreferencesDrafting_put_AutoSnapTooltip(This,Path)	\
    ( (This)->lpVtbl -> put_AutoSnapTooltip(This,Path) ) 

#define IAcadPreferencesDrafting_get_AutoSnapTooltip(This,Path)	\
    ( (This)->lpVtbl -> get_AutoSnapTooltip(This,Path) ) 

#define IAcadPreferencesDrafting_put_AutoSnapAperture(This,Path)	\
    ( (This)->lpVtbl -> put_AutoSnapAperture(This,Path) ) 

#define IAcadPreferencesDrafting_get_AutoSnapAperture(This,Path)	\
    ( (This)->lpVtbl -> get_AutoSnapAperture(This,Path) ) 

#define IAcadPreferencesDrafting_put_AutoSnapApertureSize(This,Path)	\
    ( (This)->lpVtbl -> put_AutoSnapApertureSize(This,Path) ) 

#define IAcadPreferencesDrafting_get_AutoSnapApertureSize(This,Path)	\
    ( (This)->lpVtbl -> get_AutoSnapApertureSize(This,Path) ) 

#define IAcadPreferencesDrafting_put_AutoSnapMarkerColor(This,Path)	\
    ( (This)->lpVtbl -> put_AutoSnapMarkerColor(This,Path) ) 

#define IAcadPreferencesDrafting_get_AutoSnapMarkerColor(This,Path)	\
    ( (This)->lpVtbl -> get_AutoSnapMarkerColor(This,Path) ) 

#define IAcadPreferencesDrafting_put_AutoSnapMarkerSize(This,Path)	\
    ( (This)->lpVtbl -> put_AutoSnapMarkerSize(This,Path) ) 

#define IAcadPreferencesDrafting_get_AutoSnapMarkerSize(This,Path)	\
    ( (This)->lpVtbl -> get_AutoSnapMarkerSize(This,Path) ) 

#define IAcadPreferencesDrafting_put_PolarTrackingVector(This,Path)	\
    ( (This)->lpVtbl -> put_PolarTrackingVector(This,Path) ) 

#define IAcadPreferencesDrafting_get_PolarTrackingVector(This,Path)	\
    ( (This)->lpVtbl -> get_PolarTrackingVector(This,Path) ) 

#define IAcadPreferencesDrafting_put_FullScreenTrackingVector(This,Path)	\
    ( (This)->lpVtbl -> put_FullScreenTrackingVector(This,Path) ) 

#define IAcadPreferencesDrafting_get_FullScreenTrackingVector(This,Path)	\
    ( (This)->lpVtbl -> get_FullScreenTrackingVector(This,Path) ) 

#define IAcadPreferencesDrafting_put_AutoTrackTooltip(This,Path)	\
    ( (This)->lpVtbl -> put_AutoTrackTooltip(This,Path) ) 

#define IAcadPreferencesDrafting_get_AutoTrackTooltip(This,Path)	\
    ( (This)->lpVtbl -> get_AutoTrackTooltip(This,Path) ) 

#define IAcadPreferencesDrafting_put_AlignmentPointAcquisition(This,Path)	\
    ( (This)->lpVtbl -> put_AlignmentPointAcquisition(This,Path) ) 

#define IAcadPreferencesDrafting_get_AlignmentPointAcquisition(This,Path)	\
    ( (This)->lpVtbl -> get_AlignmentPointAcquisition(This,Path) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAcadPreferencesDrafting_INTERFACE_DEFINED__ */


#ifndef __IAcadPreferencesSelection_INTERFACE_DEFINED__
#define __IAcadPreferencesSelection_INTERFACE_DEFINED__

/* interface IAcadPreferencesSelection */
/* [object][oleautomation][dual][helpstring][uuid] */ 


EXTERN_C const IID IID_IAcadPreferencesSelection;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("CE512178-E98E-4225-800E-0A29DEE39BCD")
    IAcadPreferencesSelection : public IDispatch
    {
    public:
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Application( 
            /* [retval][out] */ IAcadApplication **pAppObj) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_PickFirst( 
            /* [in] */ VARIANT_BOOL Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_PickFirst( 
            /* [retval][out] */ VARIANT_BOOL *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_PickAdd( 
            /* [in] */ VARIANT_BOOL Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_PickAdd( 
            /* [retval][out] */ VARIANT_BOOL *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_PickDrag( 
            /* [in] */ VARIANT_BOOL Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_PickDrag( 
            /* [retval][out] */ VARIANT_BOOL *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_PickAuto( 
            /* [in] */ VARIANT_BOOL Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_PickAuto( 
            /* [retval][out] */ VARIANT_BOOL *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_PickBoxSize( 
            /* [in] */ long Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_PickBoxSize( 
            /* [retval][out] */ long *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_DisplayGrips( 
            /* [in] */ long Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_DisplayGrips( 
            /* [retval][out] */ long *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_DisplayGripsWithinBlocks( 
            /* [in] */ VARIANT_BOOL Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_DisplayGripsWithinBlocks( 
            /* [retval][out] */ VARIANT_BOOL *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_GripColorSelected( 
            /* [in] */ enum /* external definition not present */ AcColor Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_GripColorSelected( 
            /* [retval][out] */ enum /* external definition not present */ AcColor *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_GripColorUnselected( 
            /* [in] */ enum /* external definition not present */ AcColor Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_GripColorUnselected( 
            /* [retval][out] */ enum /* external definition not present */ AcColor *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_GripSize( 
            /* [in] */ long Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_GripSize( 
            /* [retval][out] */ long *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_PickGroup( 
            /* [in] */ VARIANT_BOOL pick) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_PickGroup( 
            /* [retval][out] */ VARIANT_BOOL *pick) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAcadPreferencesSelectionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAcadPreferencesSelection * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAcadPreferencesSelection * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAcadPreferencesSelection * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IAcadPreferencesSelection * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IAcadPreferencesSelection * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IAcadPreferencesSelection * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IAcadPreferencesSelection * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Application )( 
            IAcadPreferencesSelection * This,
            /* [retval][out] */ IAcadApplication **pAppObj);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_PickFirst )( 
            IAcadPreferencesSelection * This,
            /* [in] */ VARIANT_BOOL Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_PickFirst )( 
            IAcadPreferencesSelection * This,
            /* [retval][out] */ VARIANT_BOOL *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_PickAdd )( 
            IAcadPreferencesSelection * This,
            /* [in] */ VARIANT_BOOL Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_PickAdd )( 
            IAcadPreferencesSelection * This,
            /* [retval][out] */ VARIANT_BOOL *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_PickDrag )( 
            IAcadPreferencesSelection * This,
            /* [in] */ VARIANT_BOOL Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_PickDrag )( 
            IAcadPreferencesSelection * This,
            /* [retval][out] */ VARIANT_BOOL *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_PickAuto )( 
            IAcadPreferencesSelection * This,
            /* [in] */ VARIANT_BOOL Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_PickAuto )( 
            IAcadPreferencesSelection * This,
            /* [retval][out] */ VARIANT_BOOL *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_PickBoxSize )( 
            IAcadPreferencesSelection * This,
            /* [in] */ long Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_PickBoxSize )( 
            IAcadPreferencesSelection * This,
            /* [retval][out] */ long *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_DisplayGrips )( 
            IAcadPreferencesSelection * This,
            /* [in] */ long Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_DisplayGrips )( 
            IAcadPreferencesSelection * This,
            /* [retval][out] */ long *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_DisplayGripsWithinBlocks )( 
            IAcadPreferencesSelection * This,
            /* [in] */ VARIANT_BOOL Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_DisplayGripsWithinBlocks )( 
            IAcadPreferencesSelection * This,
            /* [retval][out] */ VARIANT_BOOL *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_GripColorSelected )( 
            IAcadPreferencesSelection * This,
            /* [in] */ enum /* external definition not present */ AcColor Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_GripColorSelected )( 
            IAcadPreferencesSelection * This,
            /* [retval][out] */ enum /* external definition not present */ AcColor *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_GripColorUnselected )( 
            IAcadPreferencesSelection * This,
            /* [in] */ enum /* external definition not present */ AcColor Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_GripColorUnselected )( 
            IAcadPreferencesSelection * This,
            /* [retval][out] */ enum /* external definition not present */ AcColor *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_GripSize )( 
            IAcadPreferencesSelection * This,
            /* [in] */ long Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_GripSize )( 
            IAcadPreferencesSelection * This,
            /* [retval][out] */ long *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_PickGroup )( 
            IAcadPreferencesSelection * This,
            /* [in] */ VARIANT_BOOL pick);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_PickGroup )( 
            IAcadPreferencesSelection * This,
            /* [retval][out] */ VARIANT_BOOL *pick);
        
        END_INTERFACE
    } IAcadPreferencesSelectionVtbl;

    interface IAcadPreferencesSelection
    {
        CONST_VTBL struct IAcadPreferencesSelectionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAcadPreferencesSelection_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAcadPreferencesSelection_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAcadPreferencesSelection_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAcadPreferencesSelection_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IAcadPreferencesSelection_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IAcadPreferencesSelection_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IAcadPreferencesSelection_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IAcadPreferencesSelection_get_Application(This,pAppObj)	\
    ( (This)->lpVtbl -> get_Application(This,pAppObj) ) 

#define IAcadPreferencesSelection_put_PickFirst(This,Path)	\
    ( (This)->lpVtbl -> put_PickFirst(This,Path) ) 

#define IAcadPreferencesSelection_get_PickFirst(This,Path)	\
    ( (This)->lpVtbl -> get_PickFirst(This,Path) ) 

#define IAcadPreferencesSelection_put_PickAdd(This,Path)	\
    ( (This)->lpVtbl -> put_PickAdd(This,Path) ) 

#define IAcadPreferencesSelection_get_PickAdd(This,Path)	\
    ( (This)->lpVtbl -> get_PickAdd(This,Path) ) 

#define IAcadPreferencesSelection_put_PickDrag(This,Path)	\
    ( (This)->lpVtbl -> put_PickDrag(This,Path) ) 

#define IAcadPreferencesSelection_get_PickDrag(This,Path)	\
    ( (This)->lpVtbl -> get_PickDrag(This,Path) ) 

#define IAcadPreferencesSelection_put_PickAuto(This,Path)	\
    ( (This)->lpVtbl -> put_PickAuto(This,Path) ) 

#define IAcadPreferencesSelection_get_PickAuto(This,Path)	\
    ( (This)->lpVtbl -> get_PickAuto(This,Path) ) 

#define IAcadPreferencesSelection_put_PickBoxSize(This,Path)	\
    ( (This)->lpVtbl -> put_PickBoxSize(This,Path) ) 

#define IAcadPreferencesSelection_get_PickBoxSize(This,Path)	\
    ( (This)->lpVtbl -> get_PickBoxSize(This,Path) ) 

#define IAcadPreferencesSelection_put_DisplayGrips(This,Path)	\
    ( (This)->lpVtbl -> put_DisplayGrips(This,Path) ) 

#define IAcadPreferencesSelection_get_DisplayGrips(This,Path)	\
    ( (This)->lpVtbl -> get_DisplayGrips(This,Path) ) 

#define IAcadPreferencesSelection_put_DisplayGripsWithinBlocks(This,Path)	\
    ( (This)->lpVtbl -> put_DisplayGripsWithinBlocks(This,Path) ) 

#define IAcadPreferencesSelection_get_DisplayGripsWithinBlocks(This,Path)	\
    ( (This)->lpVtbl -> get_DisplayGripsWithinBlocks(This,Path) ) 

#define IAcadPreferencesSelection_put_GripColorSelected(This,Path)	\
    ( (This)->lpVtbl -> put_GripColorSelected(This,Path) ) 

#define IAcadPreferencesSelection_get_GripColorSelected(This,Path)	\
    ( (This)->lpVtbl -> get_GripColorSelected(This,Path) ) 

#define IAcadPreferencesSelection_put_GripColorUnselected(This,Path)	\
    ( (This)->lpVtbl -> put_GripColorUnselected(This,Path) ) 

#define IAcadPreferencesSelection_get_GripColorUnselected(This,Path)	\
    ( (This)->lpVtbl -> get_GripColorUnselected(This,Path) ) 

#define IAcadPreferencesSelection_put_GripSize(This,Path)	\
    ( (This)->lpVtbl -> put_GripSize(This,Path) ) 

#define IAcadPreferencesSelection_get_GripSize(This,Path)	\
    ( (This)->lpVtbl -> get_GripSize(This,Path) ) 

#define IAcadPreferencesSelection_put_PickGroup(This,pick)	\
    ( (This)->lpVtbl -> put_PickGroup(This,pick) ) 

#define IAcadPreferencesSelection_get_PickGroup(This,pick)	\
    ( (This)->lpVtbl -> get_PickGroup(This,pick) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAcadPreferencesSelection_INTERFACE_DEFINED__ */


#ifndef __IAcadPreferencesProfiles_INTERFACE_DEFINED__
#define __IAcadPreferencesProfiles_INTERFACE_DEFINED__

/* interface IAcadPreferencesProfiles */
/* [object][oleautomation][dual][helpcontext][helpstring][uuid] */ 


EXTERN_C const IID IID_IAcadPreferencesProfiles;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("52F0656B-9D63-4c67-ADBF-E9C732ED271B")
    IAcadPreferencesProfiles : public IDispatch
    {
    public:
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Application( 
            /* [retval][out] */ IAcadApplication **pAppObj) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_ActiveProfile( 
            /* [in] */ BSTR Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ActiveProfile( 
            /* [retval][out] */ BSTR *Path) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ImportProfile( 
            /* [in] */ BSTR ProfileName,
            /* [in] */ BSTR RegFile,
            /* [in] */ VARIANT_BOOL IncludePathInfo) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ExportProfile( 
            /* [in] */ BSTR ProfileName,
            /* [in] */ BSTR RegFile) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DeleteProfile( 
            /* [in] */ BSTR ProfileName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ResetProfile( 
            /* [in] */ BSTR Profile) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RenameProfile( 
            /* [in] */ BSTR origProfileName,
            /* [in] */ BSTR newProfileName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CopyProfile( 
            /* [in] */ BSTR oldProfileName,
            /* [in] */ BSTR newProfileName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetAllProfileNames( 
            /* [out] */ VARIANT *pNames) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAcadPreferencesProfilesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAcadPreferencesProfiles * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAcadPreferencesProfiles * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAcadPreferencesProfiles * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IAcadPreferencesProfiles * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IAcadPreferencesProfiles * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IAcadPreferencesProfiles * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IAcadPreferencesProfiles * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Application )( 
            IAcadPreferencesProfiles * This,
            /* [retval][out] */ IAcadApplication **pAppObj);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_ActiveProfile )( 
            IAcadPreferencesProfiles * This,
            /* [in] */ BSTR Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ActiveProfile )( 
            IAcadPreferencesProfiles * This,
            /* [retval][out] */ BSTR *Path);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ImportProfile )( 
            IAcadPreferencesProfiles * This,
            /* [in] */ BSTR ProfileName,
            /* [in] */ BSTR RegFile,
            /* [in] */ VARIANT_BOOL IncludePathInfo);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ExportProfile )( 
            IAcadPreferencesProfiles * This,
            /* [in] */ BSTR ProfileName,
            /* [in] */ BSTR RegFile);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DeleteProfile )( 
            IAcadPreferencesProfiles * This,
            /* [in] */ BSTR ProfileName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ResetProfile )( 
            IAcadPreferencesProfiles * This,
            /* [in] */ BSTR Profile);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RenameProfile )( 
            IAcadPreferencesProfiles * This,
            /* [in] */ BSTR origProfileName,
            /* [in] */ BSTR newProfileName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CopyProfile )( 
            IAcadPreferencesProfiles * This,
            /* [in] */ BSTR oldProfileName,
            /* [in] */ BSTR newProfileName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetAllProfileNames )( 
            IAcadPreferencesProfiles * This,
            /* [out] */ VARIANT *pNames);
        
        END_INTERFACE
    } IAcadPreferencesProfilesVtbl;

    interface IAcadPreferencesProfiles
    {
        CONST_VTBL struct IAcadPreferencesProfilesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAcadPreferencesProfiles_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAcadPreferencesProfiles_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAcadPreferencesProfiles_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAcadPreferencesProfiles_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IAcadPreferencesProfiles_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IAcadPreferencesProfiles_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IAcadPreferencesProfiles_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IAcadPreferencesProfiles_get_Application(This,pAppObj)	\
    ( (This)->lpVtbl -> get_Application(This,pAppObj) ) 

#define IAcadPreferencesProfiles_put_ActiveProfile(This,Path)	\
    ( (This)->lpVtbl -> put_ActiveProfile(This,Path) ) 

#define IAcadPreferencesProfiles_get_ActiveProfile(This,Path)	\
    ( (This)->lpVtbl -> get_ActiveProfile(This,Path) ) 

#define IAcadPreferencesProfiles_ImportProfile(This,ProfileName,RegFile,IncludePathInfo)	\
    ( (This)->lpVtbl -> ImportProfile(This,ProfileName,RegFile,IncludePathInfo) ) 

#define IAcadPreferencesProfiles_ExportProfile(This,ProfileName,RegFile)	\
    ( (This)->lpVtbl -> ExportProfile(This,ProfileName,RegFile) ) 

#define IAcadPreferencesProfiles_DeleteProfile(This,ProfileName)	\
    ( (This)->lpVtbl -> DeleteProfile(This,ProfileName) ) 

#define IAcadPreferencesProfiles_ResetProfile(This,Profile)	\
    ( (This)->lpVtbl -> ResetProfile(This,Profile) ) 

#define IAcadPreferencesProfiles_RenameProfile(This,origProfileName,newProfileName)	\
    ( (This)->lpVtbl -> RenameProfile(This,origProfileName,newProfileName) ) 

#define IAcadPreferencesProfiles_CopyProfile(This,oldProfileName,newProfileName)	\
    ( (This)->lpVtbl -> CopyProfile(This,oldProfileName,newProfileName) ) 

#define IAcadPreferencesProfiles_GetAllProfileNames(This,pNames)	\
    ( (This)->lpVtbl -> GetAllProfileNames(This,pNames) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAcadPreferencesProfiles_INTERFACE_DEFINED__ */


#ifndef __IAcadState_INTERFACE_DEFINED__
#define __IAcadState_INTERFACE_DEFINED__

/* interface IAcadState */
/* [oleautomation][dual][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IAcadState;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C2016470-443B-40d0-AD93-231ACFDCF594")
    IAcadState : public IDispatch
    {
    public:
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Application( 
            /* [retval][out] */ IAcadApplication **pAppObj) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_IsQuiescent( 
            /* [retval][out] */ VARIANT_BOOL *bQuiescent) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAcadStateVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAcadState * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAcadState * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAcadState * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IAcadState * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IAcadState * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IAcadState * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IAcadState * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Application )( 
            IAcadState * This,
            /* [retval][out] */ IAcadApplication **pAppObj);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_IsQuiescent )( 
            IAcadState * This,
            /* [retval][out] */ VARIANT_BOOL *bQuiescent);
        
        END_INTERFACE
    } IAcadStateVtbl;

    interface IAcadState
    {
        CONST_VTBL struct IAcadStateVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAcadState_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAcadState_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAcadState_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAcadState_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IAcadState_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IAcadState_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IAcadState_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IAcadState_get_Application(This,pAppObj)	\
    ( (This)->lpVtbl -> get_Application(This,pAppObj) ) 

#define IAcadState_get_IsQuiescent(This,bQuiescent)	\
    ( (This)->lpVtbl -> get_IsQuiescent(This,bQuiescent) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAcadState_INTERFACE_DEFINED__ */


#ifndef __IOdaDwfTemplate_INTERFACE_DEFINED__
#define __IOdaDwfTemplate_INTERFACE_DEFINED__

/* interface IOdaDwfTemplate */
/* [object][oleautomation][dual][helpstring][uuid] */ 


EXTERN_C const IID IID_IOdaDwfTemplate;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8F2A46C2-4D8A-46D5-8BBE-B06A4027BE10")
    IOdaDwfTemplate : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteFile( 
            /* [in] */ /* external definition not present */ IAcadDatabase *Database,
            /* [in] */ BSTR FileName,
            /* [in] */ OdDwfFormat FileType,
            /* [in] */ OdDwfVersion Version) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddPage( 
            /* [in] */ BSTR LayoutName,
            /* [retval][out] */ long *PageIndex) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PageCount( 
            /* [retval][out] */ long *pCount) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Page( 
            /* [in] */ VARIANT Index,
            /* [retval][out] */ IOdaDwfPageData **PageData) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RemovePage( 
            /* [in] */ VARIANT Index) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RemoveAllPages( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Background( 
            /* [retval][out] */ /* external definition not present */ IAcadAcCmColor **pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Background( 
            /* [in] */ /* external definition not present */ IAcadAcCmColor *newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ExportInvisibleLayers( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ExportInvisibleLayers( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ForceInitialViewToExtents( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ForceInitialViewToExtents( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SkipLayerInfo( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SkipLayerInfo( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SkipNamedViewsInfo( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SkipNamedViewsInfo( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Password( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Password( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Publisher( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Publisher( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_WideComments( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_WideComments( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SourceProductName( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SourceProductName( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Palette( 
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Palette( 
            /* [in] */ VARIANT pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_xSize( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_xSize( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ySize( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ySize( 
            /* [in] */ long newVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IOdaDwfTemplateVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IOdaDwfTemplate * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IOdaDwfTemplate * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IOdaDwfTemplate * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IOdaDwfTemplate * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IOdaDwfTemplate * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IOdaDwfTemplate * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IOdaDwfTemplate * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *WriteFile )( 
            IOdaDwfTemplate * This,
            /* [in] */ /* external definition not present */ IAcadDatabase *Database,
            /* [in] */ BSTR FileName,
            /* [in] */ OdDwfFormat FileType,
            /* [in] */ OdDwfVersion Version);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddPage )( 
            IOdaDwfTemplate * This,
            /* [in] */ BSTR LayoutName,
            /* [retval][out] */ long *PageIndex);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PageCount )( 
            IOdaDwfTemplate * This,
            /* [retval][out] */ long *pCount);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Page )( 
            IOdaDwfTemplate * This,
            /* [in] */ VARIANT Index,
            /* [retval][out] */ IOdaDwfPageData **PageData);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RemovePage )( 
            IOdaDwfTemplate * This,
            /* [in] */ VARIANT Index);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RemoveAllPages )( 
            IOdaDwfTemplate * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Background )( 
            IOdaDwfTemplate * This,
            /* [retval][out] */ /* external definition not present */ IAcadAcCmColor **pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Background )( 
            IOdaDwfTemplate * This,
            /* [in] */ /* external definition not present */ IAcadAcCmColor *newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ExportInvisibleLayers )( 
            IOdaDwfTemplate * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ExportInvisibleLayers )( 
            IOdaDwfTemplate * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ForceInitialViewToExtents )( 
            IOdaDwfTemplate * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ForceInitialViewToExtents )( 
            IOdaDwfTemplate * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SkipLayerInfo )( 
            IOdaDwfTemplate * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SkipLayerInfo )( 
            IOdaDwfTemplate * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SkipNamedViewsInfo )( 
            IOdaDwfTemplate * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SkipNamedViewsInfo )( 
            IOdaDwfTemplate * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Password )( 
            IOdaDwfTemplate * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Password )( 
            IOdaDwfTemplate * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Publisher )( 
            IOdaDwfTemplate * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Publisher )( 
            IOdaDwfTemplate * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_WideComments )( 
            IOdaDwfTemplate * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_WideComments )( 
            IOdaDwfTemplate * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SourceProductName )( 
            IOdaDwfTemplate * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SourceProductName )( 
            IOdaDwfTemplate * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Palette )( 
            IOdaDwfTemplate * This,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Palette )( 
            IOdaDwfTemplate * This,
            /* [in] */ VARIANT pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_xSize )( 
            IOdaDwfTemplate * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_xSize )( 
            IOdaDwfTemplate * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ySize )( 
            IOdaDwfTemplate * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ySize )( 
            IOdaDwfTemplate * This,
            /* [in] */ long newVal);
        
        END_INTERFACE
    } IOdaDwfTemplateVtbl;

    interface IOdaDwfTemplate
    {
        CONST_VTBL struct IOdaDwfTemplateVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOdaDwfTemplate_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IOdaDwfTemplate_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IOdaDwfTemplate_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IOdaDwfTemplate_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IOdaDwfTemplate_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IOdaDwfTemplate_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IOdaDwfTemplate_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IOdaDwfTemplate_WriteFile(This,Database,FileName,FileType,Version)	\
    ( (This)->lpVtbl -> WriteFile(This,Database,FileName,FileType,Version) ) 

#define IOdaDwfTemplate_AddPage(This,LayoutName,PageIndex)	\
    ( (This)->lpVtbl -> AddPage(This,LayoutName,PageIndex) ) 

#define IOdaDwfTemplate_get_PageCount(This,pCount)	\
    ( (This)->lpVtbl -> get_PageCount(This,pCount) ) 

#define IOdaDwfTemplate_get_Page(This,Index,PageData)	\
    ( (This)->lpVtbl -> get_Page(This,Index,PageData) ) 

#define IOdaDwfTemplate_RemovePage(This,Index)	\
    ( (This)->lpVtbl -> RemovePage(This,Index) ) 

#define IOdaDwfTemplate_RemoveAllPages(This)	\
    ( (This)->lpVtbl -> RemoveAllPages(This) ) 

#define IOdaDwfTemplate_get_Background(This,pVal)	\
    ( (This)->lpVtbl -> get_Background(This,pVal) ) 

#define IOdaDwfTemplate_put_Background(This,newVal)	\
    ( (This)->lpVtbl -> put_Background(This,newVal) ) 

#define IOdaDwfTemplate_get_ExportInvisibleLayers(This,pVal)	\
    ( (This)->lpVtbl -> get_ExportInvisibleLayers(This,pVal) ) 

#define IOdaDwfTemplate_put_ExportInvisibleLayers(This,newVal)	\
    ( (This)->lpVtbl -> put_ExportInvisibleLayers(This,newVal) ) 

#define IOdaDwfTemplate_get_ForceInitialViewToExtents(This,pVal)	\
    ( (This)->lpVtbl -> get_ForceInitialViewToExtents(This,pVal) ) 

#define IOdaDwfTemplate_put_ForceInitialViewToExtents(This,newVal)	\
    ( (This)->lpVtbl -> put_ForceInitialViewToExtents(This,newVal) ) 

#define IOdaDwfTemplate_get_SkipLayerInfo(This,pVal)	\
    ( (This)->lpVtbl -> get_SkipLayerInfo(This,pVal) ) 

#define IOdaDwfTemplate_put_SkipLayerInfo(This,newVal)	\
    ( (This)->lpVtbl -> put_SkipLayerInfo(This,newVal) ) 

#define IOdaDwfTemplate_get_SkipNamedViewsInfo(This,pVal)	\
    ( (This)->lpVtbl -> get_SkipNamedViewsInfo(This,pVal) ) 

#define IOdaDwfTemplate_put_SkipNamedViewsInfo(This,newVal)	\
    ( (This)->lpVtbl -> put_SkipNamedViewsInfo(This,newVal) ) 

#define IOdaDwfTemplate_get_Password(This,pVal)	\
    ( (This)->lpVtbl -> get_Password(This,pVal) ) 

#define IOdaDwfTemplate_put_Password(This,newVal)	\
    ( (This)->lpVtbl -> put_Password(This,newVal) ) 

#define IOdaDwfTemplate_get_Publisher(This,pVal)	\
    ( (This)->lpVtbl -> get_Publisher(This,pVal) ) 

#define IOdaDwfTemplate_put_Publisher(This,newVal)	\
    ( (This)->lpVtbl -> put_Publisher(This,newVal) ) 

#define IOdaDwfTemplate_get_WideComments(This,pVal)	\
    ( (This)->lpVtbl -> get_WideComments(This,pVal) ) 

#define IOdaDwfTemplate_put_WideComments(This,newVal)	\
    ( (This)->lpVtbl -> put_WideComments(This,newVal) ) 

#define IOdaDwfTemplate_get_SourceProductName(This,pVal)	\
    ( (This)->lpVtbl -> get_SourceProductName(This,pVal) ) 

#define IOdaDwfTemplate_put_SourceProductName(This,newVal)	\
    ( (This)->lpVtbl -> put_SourceProductName(This,newVal) ) 

#define IOdaDwfTemplate_get_Palette(This,pVal)	\
    ( (This)->lpVtbl -> get_Palette(This,pVal) ) 

#define IOdaDwfTemplate_put_Palette(This,pVal)	\
    ( (This)->lpVtbl -> put_Palette(This,pVal) ) 

#define IOdaDwfTemplate_get_xSize(This,pVal)	\
    ( (This)->lpVtbl -> get_xSize(This,pVal) ) 

#define IOdaDwfTemplate_put_xSize(This,newVal)	\
    ( (This)->lpVtbl -> put_xSize(This,newVal) ) 

#define IOdaDwfTemplate_get_ySize(This,pVal)	\
    ( (This)->lpVtbl -> get_ySize(This,pVal) ) 

#define IOdaDwfTemplate_put_ySize(This,newVal)	\
    ( (This)->lpVtbl -> put_ySize(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IOdaDwfTemplate_INTERFACE_DEFINED__ */


#ifndef __IOdaDwfPageData_INTERFACE_DEFINED__
#define __IOdaDwfPageData_INTERFACE_DEFINED__

/* interface IOdaDwfPageData */
/* [object][oleautomation][dual][helpstring][uuid] */ 


EXTERN_C const IID IID_IOdaDwfPageData;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6C2751B5-A21F-46d8-8EBE-59F0A15288D9")
    IOdaDwfPageData : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_LayoutName( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Author( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Author( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Title( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Title( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Subject( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Subject( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Company( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Company( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Comments( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Comments( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Reviewers( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Reviewers( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Keywords( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Keywords( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Description( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Description( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Copyright( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Copyright( 
            /* [in] */ BSTR newVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IOdaDwfPageDataVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IOdaDwfPageData * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IOdaDwfPageData * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IOdaDwfPageData * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IOdaDwfPageData * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IOdaDwfPageData * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IOdaDwfPageData * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IOdaDwfPageData * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LayoutName )( 
            IOdaDwfPageData * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Author )( 
            IOdaDwfPageData * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Author )( 
            IOdaDwfPageData * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Title )( 
            IOdaDwfPageData * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Title )( 
            IOdaDwfPageData * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Subject )( 
            IOdaDwfPageData * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Subject )( 
            IOdaDwfPageData * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Company )( 
            IOdaDwfPageData * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Company )( 
            IOdaDwfPageData * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Comments )( 
            IOdaDwfPageData * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Comments )( 
            IOdaDwfPageData * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Reviewers )( 
            IOdaDwfPageData * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Reviewers )( 
            IOdaDwfPageData * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Keywords )( 
            IOdaDwfPageData * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Keywords )( 
            IOdaDwfPageData * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Description )( 
            IOdaDwfPageData * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Description )( 
            IOdaDwfPageData * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Copyright )( 
            IOdaDwfPageData * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Copyright )( 
            IOdaDwfPageData * This,
            /* [in] */ BSTR newVal);
        
        END_INTERFACE
    } IOdaDwfPageDataVtbl;

    interface IOdaDwfPageData
    {
        CONST_VTBL struct IOdaDwfPageDataVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOdaDwfPageData_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IOdaDwfPageData_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IOdaDwfPageData_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IOdaDwfPageData_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IOdaDwfPageData_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IOdaDwfPageData_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IOdaDwfPageData_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IOdaDwfPageData_get_LayoutName(This,pVal)	\
    ( (This)->lpVtbl -> get_LayoutName(This,pVal) ) 

#define IOdaDwfPageData_get_Author(This,pVal)	\
    ( (This)->lpVtbl -> get_Author(This,pVal) ) 

#define IOdaDwfPageData_put_Author(This,newVal)	\
    ( (This)->lpVtbl -> put_Author(This,newVal) ) 

#define IOdaDwfPageData_get_Title(This,pVal)	\
    ( (This)->lpVtbl -> get_Title(This,pVal) ) 

#define IOdaDwfPageData_put_Title(This,newVal)	\
    ( (This)->lpVtbl -> put_Title(This,newVal) ) 

#define IOdaDwfPageData_get_Subject(This,pVal)	\
    ( (This)->lpVtbl -> get_Subject(This,pVal) ) 

#define IOdaDwfPageData_put_Subject(This,newVal)	\
    ( (This)->lpVtbl -> put_Subject(This,newVal) ) 

#define IOdaDwfPageData_get_Company(This,pVal)	\
    ( (This)->lpVtbl -> get_Company(This,pVal) ) 

#define IOdaDwfPageData_put_Company(This,newVal)	\
    ( (This)->lpVtbl -> put_Company(This,newVal) ) 

#define IOdaDwfPageData_get_Comments(This,pVal)	\
    ( (This)->lpVtbl -> get_Comments(This,pVal) ) 

#define IOdaDwfPageData_put_Comments(This,newVal)	\
    ( (This)->lpVtbl -> put_Comments(This,newVal) ) 

#define IOdaDwfPageData_get_Reviewers(This,pVal)	\
    ( (This)->lpVtbl -> get_Reviewers(This,pVal) ) 

#define IOdaDwfPageData_put_Reviewers(This,newVal)	\
    ( (This)->lpVtbl -> put_Reviewers(This,newVal) ) 

#define IOdaDwfPageData_get_Keywords(This,pVal)	\
    ( (This)->lpVtbl -> get_Keywords(This,pVal) ) 

#define IOdaDwfPageData_put_Keywords(This,newVal)	\
    ( (This)->lpVtbl -> put_Keywords(This,newVal) ) 

#define IOdaDwfPageData_get_Description(This,pVal)	\
    ( (This)->lpVtbl -> get_Description(This,pVal) ) 

#define IOdaDwfPageData_put_Description(This,newVal)	\
    ( (This)->lpVtbl -> put_Description(This,newVal) ) 

#define IOdaDwfPageData_get_Copyright(This,pVal)	\
    ( (This)->lpVtbl -> get_Copyright(This,pVal) ) 

#define IOdaDwfPageData_put_Copyright(This,newVal)	\
    ( (This)->lpVtbl -> put_Copyright(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IOdaDwfPageData_INTERFACE_DEFINED__ */


#ifndef __IOdaDwfImporter_INTERFACE_DEFINED__
#define __IOdaDwfImporter_INTERFACE_DEFINED__

/* interface IOdaDwfImporter */
/* [object][oleautomation][dual][helpstring][uuid] */ 


EXTERN_C const IID IID_IOdaDwfImporter;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C5631279-833D-4fe0-8965-B06E2FEC0E9C")
    IOdaDwfImporter : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Import( 
            /* [in] */ /* external definition not present */ IAcadDatabase *Database,
            /* [in] */ BSTR FileName,
            /* [defaultvalue][in] */ BSTR password = 0,
            /* [defaultvalue][in] */ double wPaper = 297,
            /* [defaultvalue][in] */ double hPaper = 210) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IOdaDwfImporterVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IOdaDwfImporter * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IOdaDwfImporter * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IOdaDwfImporter * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IOdaDwfImporter * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IOdaDwfImporter * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IOdaDwfImporter * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IOdaDwfImporter * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Import )( 
            IOdaDwfImporter * This,
            /* [in] */ /* external definition not present */ IAcadDatabase *Database,
            /* [in] */ BSTR FileName,
            /* [defaultvalue][in] */ BSTR password,
            /* [defaultvalue][in] */ double wPaper,
            /* [defaultvalue][in] */ double hPaper);
        
        END_INTERFACE
    } IOdaDwfImporterVtbl;

    interface IOdaDwfImporter
    {
        CONST_VTBL struct IOdaDwfImporterVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOdaDwfImporter_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IOdaDwfImporter_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IOdaDwfImporter_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IOdaDwfImporter_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IOdaDwfImporter_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IOdaDwfImporter_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IOdaDwfImporter_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IOdaDwfImporter_Import(This,Database,FileName,password,wPaper,hPaper)	\
    ( (This)->lpVtbl -> Import(This,Database,FileName,password,wPaper,hPaper) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IOdaDwfImporter_INTERFACE_DEFINED__ */


#ifndef __IOdaDwfImporter2_INTERFACE_DEFINED__
#define __IOdaDwfImporter2_INTERFACE_DEFINED__

/* interface IOdaDwfImporter2 */
/* [object][oleautomation][dual][helpstring][uuid] */ 


EXTERN_C const IID IID_IOdaDwfImporter2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7E8D21F1-6343-4ccc-9F7D-0B270A05DC12")
    IOdaDwfImporter2 : public IOdaDwfImporter
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Properties( 
            /* [in] */ BSTR Name,
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Properties( 
            /* [in] */ BSTR Name,
            /* [in] */ VARIANT NewVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Close( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IOdaDwfImporter2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IOdaDwfImporter2 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IOdaDwfImporter2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IOdaDwfImporter2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IOdaDwfImporter2 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IOdaDwfImporter2 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IOdaDwfImporter2 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IOdaDwfImporter2 * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Import )( 
            IOdaDwfImporter2 * This,
            /* [in] */ /* external definition not present */ IAcadDatabase *Database,
            /* [in] */ BSTR FileName,
            /* [defaultvalue][in] */ BSTR password,
            /* [defaultvalue][in] */ double wPaper,
            /* [defaultvalue][in] */ double hPaper);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Properties )( 
            IOdaDwfImporter2 * This,
            /* [in] */ BSTR Name,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Properties )( 
            IOdaDwfImporter2 * This,
            /* [in] */ BSTR Name,
            /* [in] */ VARIANT NewVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Close )( 
            IOdaDwfImporter2 * This);
        
        END_INTERFACE
    } IOdaDwfImporter2Vtbl;

    interface IOdaDwfImporter2
    {
        CONST_VTBL struct IOdaDwfImporter2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOdaDwfImporter2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IOdaDwfImporter2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IOdaDwfImporter2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IOdaDwfImporter2_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IOdaDwfImporter2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IOdaDwfImporter2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IOdaDwfImporter2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IOdaDwfImporter2_Import(This,Database,FileName,password,wPaper,hPaper)	\
    ( (This)->lpVtbl -> Import(This,Database,FileName,password,wPaper,hPaper) ) 


#define IOdaDwfImporter2_get_Properties(This,Name,pVal)	\
    ( (This)->lpVtbl -> get_Properties(This,Name,pVal) ) 

#define IOdaDwfImporter2_put_Properties(This,Name,NewVal)	\
    ( (This)->lpVtbl -> put_Properties(This,Name,NewVal) ) 

#define IOdaDwfImporter2_Close(This)	\
    ( (This)->lpVtbl -> Close(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IOdaDwfImporter2_INTERFACE_DEFINED__ */


#ifndef __IOdaSvgExporter_INTERFACE_DEFINED__
#define __IOdaSvgExporter_INTERFACE_DEFINED__

/* interface IOdaSvgExporter */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IOdaSvgExporter;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("FDAF1115-5A20-4D16-A509-01012B71E4F7")
    IOdaSvgExporter : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Properties( 
            /* [in] */ BSTR Name,
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Properties( 
            /* [in] */ BSTR Name,
            /* [in] */ VARIANT NewVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Export( 
            /* [in] */ /* external definition not present */ IAcadDatabase *Database,
            /* [in] */ BSTR FilePath) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IOdaSvgExporterVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IOdaSvgExporter * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IOdaSvgExporter * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IOdaSvgExporter * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IOdaSvgExporter * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IOdaSvgExporter * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IOdaSvgExporter * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IOdaSvgExporter * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Properties )( 
            IOdaSvgExporter * This,
            /* [in] */ BSTR Name,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Properties )( 
            IOdaSvgExporter * This,
            /* [in] */ BSTR Name,
            /* [in] */ VARIANT NewVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Export )( 
            IOdaSvgExporter * This,
            /* [in] */ /* external definition not present */ IAcadDatabase *Database,
            /* [in] */ BSTR FilePath);
        
        END_INTERFACE
    } IOdaSvgExporterVtbl;

    interface IOdaSvgExporter
    {
        CONST_VTBL struct IOdaSvgExporterVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOdaSvgExporter_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IOdaSvgExporter_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IOdaSvgExporter_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IOdaSvgExporter_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IOdaSvgExporter_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IOdaSvgExporter_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IOdaSvgExporter_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IOdaSvgExporter_get_Properties(This,Name,pVal)	\
    ( (This)->lpVtbl -> get_Properties(This,Name,pVal) ) 

#define IOdaSvgExporter_put_Properties(This,Name,NewVal)	\
    ( (This)->lpVtbl -> put_Properties(This,Name,NewVal) ) 

#define IOdaSvgExporter_Export(This,Database,FilePath)	\
    ( (This)->lpVtbl -> Export(This,Database,FilePath) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IOdaSvgExporter_INTERFACE_DEFINED__ */


#ifndef __IOdaAuditInfo_INTERFACE_DEFINED__
#define __IOdaAuditInfo_INTERFACE_DEFINED__

/* interface IOdaAuditInfo */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IOdaAuditInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("56B202FE-BE71-43b4-B504-1902EDE89644")
    IOdaAuditInfo : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_numFixes( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_numErrors( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_fixErrors( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IOdaAuditInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IOdaAuditInfo * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IOdaAuditInfo * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IOdaAuditInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IOdaAuditInfo * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IOdaAuditInfo * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IOdaAuditInfo * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IOdaAuditInfo * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_numFixes )( 
            IOdaAuditInfo * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_numErrors )( 
            IOdaAuditInfo * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_fixErrors )( 
            IOdaAuditInfo * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        END_INTERFACE
    } IOdaAuditInfoVtbl;

    interface IOdaAuditInfo
    {
        CONST_VTBL struct IOdaAuditInfoVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOdaAuditInfo_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IOdaAuditInfo_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IOdaAuditInfo_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IOdaAuditInfo_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IOdaAuditInfo_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IOdaAuditInfo_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IOdaAuditInfo_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IOdaAuditInfo_get_numFixes(This,pVal)	\
    ( (This)->lpVtbl -> get_numFixes(This,pVal) ) 

#define IOdaAuditInfo_get_numErrors(This,pVal)	\
    ( (This)->lpVtbl -> get_numErrors(This,pVal) ) 

#define IOdaAuditInfo_get_fixErrors(This,pVal)	\
    ( (This)->lpVtbl -> get_fixErrors(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IOdaAuditInfo_INTERFACE_DEFINED__ */


#ifndef __IOdaBmpOut_INTERFACE_DEFINED__
#define __IOdaBmpOut_INTERFACE_DEFINED__

/* interface IOdaBmpOut */
/* [object][oleautomation][dual][helpstring][uuid] */ 


EXTERN_C const IID IID_IOdaBmpOut;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("11c4f7aa-d8cc-4762-8c7c-3064e65eedbd")
    IOdaBmpOut : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteFile( 
            /* [in] */ /* external definition not present */ IAcadDatabase *Database,
            /* [in] */ BSTR BitmapName) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Background( 
            /* [retval][out] */ /* external definition not present */ IAcadAcCmColor **pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Background( 
            /* [in] */ /* external definition not present */ IAcadAcCmColor *newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Palette( 
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Palette( 
            /* [in] */ VARIANT pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Height( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Height( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Width( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Width( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_BitPerPixel( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_BitPerPixel( 
            /* [in] */ long newVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IOdaBmpOutVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IOdaBmpOut * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IOdaBmpOut * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IOdaBmpOut * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IOdaBmpOut * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IOdaBmpOut * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IOdaBmpOut * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IOdaBmpOut * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *WriteFile )( 
            IOdaBmpOut * This,
            /* [in] */ /* external definition not present */ IAcadDatabase *Database,
            /* [in] */ BSTR BitmapName);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Background )( 
            IOdaBmpOut * This,
            /* [retval][out] */ /* external definition not present */ IAcadAcCmColor **pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Background )( 
            IOdaBmpOut * This,
            /* [in] */ /* external definition not present */ IAcadAcCmColor *newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Palette )( 
            IOdaBmpOut * This,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Palette )( 
            IOdaBmpOut * This,
            /* [in] */ VARIANT pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Height )( 
            IOdaBmpOut * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Height )( 
            IOdaBmpOut * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Width )( 
            IOdaBmpOut * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Width )( 
            IOdaBmpOut * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BitPerPixel )( 
            IOdaBmpOut * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BitPerPixel )( 
            IOdaBmpOut * This,
            /* [in] */ long newVal);
        
        END_INTERFACE
    } IOdaBmpOutVtbl;

    interface IOdaBmpOut
    {
        CONST_VTBL struct IOdaBmpOutVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOdaBmpOut_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IOdaBmpOut_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IOdaBmpOut_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IOdaBmpOut_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IOdaBmpOut_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IOdaBmpOut_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IOdaBmpOut_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IOdaBmpOut_WriteFile(This,Database,BitmapName)	\
    ( (This)->lpVtbl -> WriteFile(This,Database,BitmapName) ) 

#define IOdaBmpOut_get_Background(This,pVal)	\
    ( (This)->lpVtbl -> get_Background(This,pVal) ) 

#define IOdaBmpOut_put_Background(This,newVal)	\
    ( (This)->lpVtbl -> put_Background(This,newVal) ) 

#define IOdaBmpOut_get_Palette(This,pVal)	\
    ( (This)->lpVtbl -> get_Palette(This,pVal) ) 

#define IOdaBmpOut_put_Palette(This,pVal)	\
    ( (This)->lpVtbl -> put_Palette(This,pVal) ) 

#define IOdaBmpOut_get_Height(This,pVal)	\
    ( (This)->lpVtbl -> get_Height(This,pVal) ) 

#define IOdaBmpOut_put_Height(This,newVal)	\
    ( (This)->lpVtbl -> put_Height(This,newVal) ) 

#define IOdaBmpOut_get_Width(This,pVal)	\
    ( (This)->lpVtbl -> get_Width(This,pVal) ) 

#define IOdaBmpOut_put_Width(This,newVal)	\
    ( (This)->lpVtbl -> put_Width(This,newVal) ) 

#define IOdaBmpOut_get_BitPerPixel(This,pVal)	\
    ( (This)->lpVtbl -> get_BitPerPixel(This,pVal) ) 

#define IOdaBmpOut_put_BitPerPixel(This,newVal)	\
    ( (This)->lpVtbl -> put_BitPerPixel(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IOdaBmpOut_INTERFACE_DEFINED__ */


#ifndef __IOdaDwf3dExport_INTERFACE_DEFINED__
#define __IOdaDwf3dExport_INTERFACE_DEFINED__

/* interface IOdaDwf3dExport */
/* [object][oleautomation][dual][helpstring][uuid] */ 


EXTERN_C const IID IID_IOdaDwf3dExport;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4e99c4a8-afc0-45e9-b312-61d7db4f2ee6")
    IOdaDwf3dExport : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Export3dDwf( 
            /* [in] */ /* external definition not present */ IAcadDatabase *Database,
            /* [in] */ BSTR FileName) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Background( 
            /* [retval][out] */ /* external definition not present */ IAcadAcCmColor **pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Background( 
            /* [in] */ /* external definition not present */ IAcadAcCmColor *newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Title( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Title( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Palette( 
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Palette( 
            /* [in] */ VARIANT pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_xSize( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_xSize( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ySize( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ySize( 
            /* [in] */ long newVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IOdaDwf3dExportVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IOdaDwf3dExport * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IOdaDwf3dExport * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IOdaDwf3dExport * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IOdaDwf3dExport * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IOdaDwf3dExport * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IOdaDwf3dExport * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IOdaDwf3dExport * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Export3dDwf )( 
            IOdaDwf3dExport * This,
            /* [in] */ /* external definition not present */ IAcadDatabase *Database,
            /* [in] */ BSTR FileName);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Background )( 
            IOdaDwf3dExport * This,
            /* [retval][out] */ /* external definition not present */ IAcadAcCmColor **pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Background )( 
            IOdaDwf3dExport * This,
            /* [in] */ /* external definition not present */ IAcadAcCmColor *newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Title )( 
            IOdaDwf3dExport * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Title )( 
            IOdaDwf3dExport * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Palette )( 
            IOdaDwf3dExport * This,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Palette )( 
            IOdaDwf3dExport * This,
            /* [in] */ VARIANT pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_xSize )( 
            IOdaDwf3dExport * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_xSize )( 
            IOdaDwf3dExport * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ySize )( 
            IOdaDwf3dExport * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ySize )( 
            IOdaDwf3dExport * This,
            /* [in] */ long newVal);
        
        END_INTERFACE
    } IOdaDwf3dExportVtbl;

    interface IOdaDwf3dExport
    {
        CONST_VTBL struct IOdaDwf3dExportVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOdaDwf3dExport_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IOdaDwf3dExport_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IOdaDwf3dExport_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IOdaDwf3dExport_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IOdaDwf3dExport_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IOdaDwf3dExport_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IOdaDwf3dExport_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IOdaDwf3dExport_Export3dDwf(This,Database,FileName)	\
    ( (This)->lpVtbl -> Export3dDwf(This,Database,FileName) ) 

#define IOdaDwf3dExport_get_Background(This,pVal)	\
    ( (This)->lpVtbl -> get_Background(This,pVal) ) 

#define IOdaDwf3dExport_put_Background(This,newVal)	\
    ( (This)->lpVtbl -> put_Background(This,newVal) ) 

#define IOdaDwf3dExport_get_Title(This,pVal)	\
    ( (This)->lpVtbl -> get_Title(This,pVal) ) 

#define IOdaDwf3dExport_put_Title(This,newVal)	\
    ( (This)->lpVtbl -> put_Title(This,newVal) ) 

#define IOdaDwf3dExport_get_Palette(This,pVal)	\
    ( (This)->lpVtbl -> get_Palette(This,pVal) ) 

#define IOdaDwf3dExport_put_Palette(This,pVal)	\
    ( (This)->lpVtbl -> put_Palette(This,pVal) ) 

#define IOdaDwf3dExport_get_xSize(This,pVal)	\
    ( (This)->lpVtbl -> get_xSize(This,pVal) ) 

#define IOdaDwf3dExport_put_xSize(This,newVal)	\
    ( (This)->lpVtbl -> put_xSize(This,newVal) ) 

#define IOdaDwf3dExport_get_ySize(This,pVal)	\
    ( (This)->lpVtbl -> get_ySize(This,pVal) ) 

#define IOdaDwf3dExport_put_ySize(This,newVal)	\
    ( (This)->lpVtbl -> put_ySize(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IOdaDwf3dExport_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_TransmittalOperation;

#ifdef __cplusplus

class DECLSPEC_UUID("90E28445-A9C6-4CFB-8A61-E1CA489987B8")
TransmittalOperation;
#endif

EXTERN_C const CLSID CLSID_TransmittalFilesGraph;

#ifdef __cplusplus

class DECLSPEC_UUID("DBBD2B70-4EC1-4E25-8587-CCD82BDFE567")
TransmittalFilesGraph;
#endif

EXTERN_C const CLSID CLSID_TransmittalFile;

#ifdef __cplusplus

class DECLSPEC_UUID("76613406-3C1E-4E3D-8672-290C3679EFE2")
TransmittalFile;
#endif

EXTERN_C const CLSID CLSID_TransmittalInfo;

#ifdef __cplusplus

class DECLSPEC_UUID("E5D9AAFD-4748-4B77-B7B7-707992F78250")
TransmittalInfo;
#endif

EXTERN_C const CLSID CLSID_AcadMenuGroups;

#ifdef __cplusplus

class DECLSPEC_UUID("3C8594D3-2898-4B07-BCB2-91FBDE35D148")
AcadMenuGroups;
#endif

EXTERN_C const CLSID CLSID_AcadMenuGroup;

#ifdef __cplusplus

class DECLSPEC_UUID("FDAF94F0-224C-422F-A972-D36803018972")
AcadMenuGroup;
#endif

EXTERN_C const CLSID CLSID_AcadMenuBar;

#ifdef __cplusplus

class DECLSPEC_UUID("CA0CD0D5-917D-46F7-A6D4-A72ED08B1F98")
AcadMenuBar;
#endif

EXTERN_C const CLSID CLSID_AcadPopupMenus;

#ifdef __cplusplus

class DECLSPEC_UUID("4364A21D-F5AA-4EE3-8FD1-7D044E1A6799")
AcadPopupMenus;
#endif

EXTERN_C const CLSID CLSID_AcadPopupMenu;

#ifdef __cplusplus

class DECLSPEC_UUID("1037231F-1762-4C18-84A2-1B496039EC5F")
AcadPopupMenu;
#endif

EXTERN_C const CLSID CLSID_AcadPopupMenuItem;

#ifdef __cplusplus

class DECLSPEC_UUID("BD3D0D76-F070-4448-965B-7506DB93AFCD")
AcadPopupMenuItem;
#endif

EXTERN_C const CLSID CLSID_AcadToolbars;

#ifdef __cplusplus

class DECLSPEC_UUID("83F261BA-D8A3-4B3E-BEDA-08F0DD6D377D")
AcadToolbars;
#endif

EXTERN_C const CLSID CLSID_AcadToolbar;

#ifdef __cplusplus

class DECLSPEC_UUID("F3F29EF3-1ADF-47CC-8979-8CC7C005AA5B")
AcadToolbar;
#endif

EXTERN_C const CLSID CLSID_AcadToolbarItem;

#ifdef __cplusplus

class DECLSPEC_UUID("520C6D71-CFF7-4FCB-BAD9-3DACC536489E")
AcadToolbarItem;
#endif

#ifndef ___DAcadApplicationEvents_DISPINTERFACE_DEFINED__
#define ___DAcadApplicationEvents_DISPINTERFACE_DEFINED__

/* dispinterface _DAcadApplicationEvents */
/* [hidden][helpstring][uuid] */ 


EXTERN_C const IID DIID__DAcadApplicationEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("93E291E9-BB72-429b-B4DE-DF76B88603EB")
    _DAcadApplicationEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _DAcadApplicationEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _DAcadApplicationEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _DAcadApplicationEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _DAcadApplicationEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _DAcadApplicationEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _DAcadApplicationEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _DAcadApplicationEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _DAcadApplicationEvents * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } _DAcadApplicationEventsVtbl;

    interface _DAcadApplicationEvents
    {
        CONST_VTBL struct _DAcadApplicationEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _DAcadApplicationEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _DAcadApplicationEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _DAcadApplicationEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _DAcadApplicationEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _DAcadApplicationEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _DAcadApplicationEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _DAcadApplicationEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___DAcadApplicationEvents_DISPINTERFACE_DEFINED__ */


#ifndef ___DAcadDocumentEvents_DISPINTERFACE_DEFINED__
#define ___DAcadDocumentEvents_DISPINTERFACE_DEFINED__

/* dispinterface _DAcadDocumentEvents */
/* [hidden][helpstring][uuid] */ 


EXTERN_C const IID DIID__DAcadDocumentEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("63A90E32-CB8B-4a3b-ADFF-EF94A35278B2")
    _DAcadDocumentEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _DAcadDocumentEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _DAcadDocumentEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _DAcadDocumentEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _DAcadDocumentEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _DAcadDocumentEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _DAcadDocumentEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _DAcadDocumentEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _DAcadDocumentEvents * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } _DAcadDocumentEventsVtbl;

    interface _DAcadDocumentEvents
    {
        CONST_VTBL struct _DAcadDocumentEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _DAcadDocumentEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _DAcadDocumentEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _DAcadDocumentEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _DAcadDocumentEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _DAcadDocumentEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _DAcadDocumentEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _DAcadDocumentEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___DAcadDocumentEvents_DISPINTERFACE_DEFINED__ */


#ifndef __IOdaHostApp_INTERFACE_DEFINED__
#define __IOdaHostApp_INTERFACE_DEFINED__

/* interface IOdaHostApp */
/* [oleautomation][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IOdaHostApp;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E789E253-BEDC-44ff-B228-AD3A17D9AB3A")
    IOdaHostApp : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Application( 
            /* [retval][out] */ IAcadApplication **pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE BrowseForOpenFileName( 
            BSTR rootFolder,
            BSTR fileFilter,
            VARIANT_BOOL *bOk,
            BSTR *filename) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AuditDatabase( 
            IAcadDocument *pDoc,
            VARIANT_BOOL bFixErrors) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AuditInfo( 
            /* [retval][out] */ IOdaAuditInfo **pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OriginalFileType( 
            IAcadDocument *pDoc,
            VARIANT *FileType) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Recover( 
            /* [in] */ BSTR fileName,
            /* [optional][in] */ VARIANT Password,
            /* [retval][out] */ IAcadDocument **pDoc) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OpenDbPartially( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_OpenDbPartially( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IOdaHostAppVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IOdaHostApp * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IOdaHostApp * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IOdaHostApp * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IOdaHostApp * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IOdaHostApp * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IOdaHostApp * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IOdaHostApp * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Application )( 
            IOdaHostApp * This,
            /* [retval][out] */ IAcadApplication **pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *BrowseForOpenFileName )( 
            IOdaHostApp * This,
            BSTR rootFolder,
            BSTR fileFilter,
            VARIANT_BOOL *bOk,
            BSTR *filename);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AuditDatabase )( 
            IOdaHostApp * This,
            IAcadDocument *pDoc,
            VARIANT_BOOL bFixErrors);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AuditInfo )( 
            IOdaHostApp * This,
            /* [retval][out] */ IOdaAuditInfo **pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OriginalFileType )( 
            IOdaHostApp * This,
            IAcadDocument *pDoc,
            VARIANT *FileType);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Recover )( 
            IOdaHostApp * This,
            /* [in] */ BSTR fileName,
            /* [optional][in] */ VARIANT Password,
            /* [retval][out] */ IAcadDocument **pDoc);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OpenDbPartially )( 
            IOdaHostApp * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_OpenDbPartially )( 
            IOdaHostApp * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        END_INTERFACE
    } IOdaHostAppVtbl;

    interface IOdaHostApp
    {
        CONST_VTBL struct IOdaHostAppVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOdaHostApp_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IOdaHostApp_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IOdaHostApp_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IOdaHostApp_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IOdaHostApp_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IOdaHostApp_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IOdaHostApp_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IOdaHostApp_get_Application(This,pVal)	\
    ( (This)->lpVtbl -> get_Application(This,pVal) ) 

#define IOdaHostApp_BrowseForOpenFileName(This,rootFolder,fileFilter,bOk,filename)	\
    ( (This)->lpVtbl -> BrowseForOpenFileName(This,rootFolder,fileFilter,bOk,filename) ) 

#define IOdaHostApp_AuditDatabase(This,pDoc,bFixErrors)	\
    ( (This)->lpVtbl -> AuditDatabase(This,pDoc,bFixErrors) ) 

#define IOdaHostApp_get_AuditInfo(This,pVal)	\
    ( (This)->lpVtbl -> get_AuditInfo(This,pVal) ) 

#define IOdaHostApp_OriginalFileType(This,pDoc,FileType)	\
    ( (This)->lpVtbl -> OriginalFileType(This,pDoc,FileType) ) 

#define IOdaHostApp_Recover(This,fileName,Password,pDoc)	\
    ( (This)->lpVtbl -> Recover(This,fileName,Password,pDoc) ) 

#define IOdaHostApp_get_OpenDbPartially(This,pVal)	\
    ( (This)->lpVtbl -> get_OpenDbPartially(This,pVal) ) 

#define IOdaHostApp_put_OpenDbPartially(This,newVal)	\
    ( (This)->lpVtbl -> put_OpenDbPartially(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IOdaHostApp_INTERFACE_DEFINED__ */


#ifndef __IOdaConsole_INTERFACE_DEFINED__
#define __IOdaConsole_INTERFACE_DEFINED__

/* interface IOdaConsole */
/* [oleautomation][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IOdaConsole;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9DFDB619-A15D-43cd-92D5-7987D452B9F1")
    IOdaConsole : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PutString( 
            /* [in] */ BSTR text) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetString( 
            /* [in] */ VARIANT_BOOL bAllowSpaces,
            /* [retval][out] */ BSTR *result) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IOdaConsoleVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IOdaConsole * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IOdaConsole * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IOdaConsole * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IOdaConsole * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IOdaConsole * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IOdaConsole * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IOdaConsole * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PutString )( 
            IOdaConsole * This,
            /* [in] */ BSTR text);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetString )( 
            IOdaConsole * This,
            /* [in] */ VARIANT_BOOL bAllowSpaces,
            /* [retval][out] */ BSTR *result);
        
        END_INTERFACE
    } IOdaConsoleVtbl;

    interface IOdaConsole
    {
        CONST_VTBL struct IOdaConsoleVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOdaConsole_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IOdaConsole_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IOdaConsole_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IOdaConsole_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IOdaConsole_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IOdaConsole_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IOdaConsole_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IOdaConsole_PutString(This,text)	\
    ( (This)->lpVtbl -> PutString(This,text) ) 

#define IOdaConsole_GetString(This,bAllowSpaces,result)	\
    ( (This)->lpVtbl -> GetString(This,bAllowSpaces,result) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IOdaConsole_INTERFACE_DEFINED__ */


#ifndef __IOdaHostApp2_INTERFACE_DEFINED__
#define __IOdaHostApp2_INTERFACE_DEFINED__

/* interface IOdaHostApp2 */
/* [oleautomation][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IOdaHostApp2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("CFE29DD1-2A1B-49f9-853E-11918A789C6D")
    IOdaHostApp2 : public IOdaHostApp
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Console( 
            /* [retval][out] */ IOdaConsole **pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Console( 
            /* [in] */ IOdaConsole *newVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IOdaHostApp2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IOdaHostApp2 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IOdaHostApp2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IOdaHostApp2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IOdaHostApp2 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IOdaHostApp2 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IOdaHostApp2 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IOdaHostApp2 * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Application )( 
            IOdaHostApp2 * This,
            /* [retval][out] */ IAcadApplication **pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *BrowseForOpenFileName )( 
            IOdaHostApp2 * This,
            BSTR rootFolder,
            BSTR fileFilter,
            VARIANT_BOOL *bOk,
            BSTR *filename);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AuditDatabase )( 
            IOdaHostApp2 * This,
            IAcadDocument *pDoc,
            VARIANT_BOOL bFixErrors);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AuditInfo )( 
            IOdaHostApp2 * This,
            /* [retval][out] */ IOdaAuditInfo **pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OriginalFileType )( 
            IOdaHostApp2 * This,
            IAcadDocument *pDoc,
            VARIANT *FileType);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Recover )( 
            IOdaHostApp2 * This,
            /* [in] */ BSTR fileName,
            /* [optional][in] */ VARIANT Password,
            /* [retval][out] */ IAcadDocument **pDoc);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OpenDbPartially )( 
            IOdaHostApp2 * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_OpenDbPartially )( 
            IOdaHostApp2 * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Console )( 
            IOdaHostApp2 * This,
            /* [retval][out] */ IOdaConsole **pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Console )( 
            IOdaHostApp2 * This,
            /* [in] */ IOdaConsole *newVal);
        
        END_INTERFACE
    } IOdaHostApp2Vtbl;

    interface IOdaHostApp2
    {
        CONST_VTBL struct IOdaHostApp2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOdaHostApp2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IOdaHostApp2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IOdaHostApp2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IOdaHostApp2_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IOdaHostApp2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IOdaHostApp2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IOdaHostApp2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IOdaHostApp2_get_Application(This,pVal)	\
    ( (This)->lpVtbl -> get_Application(This,pVal) ) 

#define IOdaHostApp2_BrowseForOpenFileName(This,rootFolder,fileFilter,bOk,filename)	\
    ( (This)->lpVtbl -> BrowseForOpenFileName(This,rootFolder,fileFilter,bOk,filename) ) 

#define IOdaHostApp2_AuditDatabase(This,pDoc,bFixErrors)	\
    ( (This)->lpVtbl -> AuditDatabase(This,pDoc,bFixErrors) ) 

#define IOdaHostApp2_get_AuditInfo(This,pVal)	\
    ( (This)->lpVtbl -> get_AuditInfo(This,pVal) ) 

#define IOdaHostApp2_OriginalFileType(This,pDoc,FileType)	\
    ( (This)->lpVtbl -> OriginalFileType(This,pDoc,FileType) ) 

#define IOdaHostApp2_Recover(This,fileName,Password,pDoc)	\
    ( (This)->lpVtbl -> Recover(This,fileName,Password,pDoc) ) 

#define IOdaHostApp2_get_OpenDbPartially(This,pVal)	\
    ( (This)->lpVtbl -> get_OpenDbPartially(This,pVal) ) 

#define IOdaHostApp2_put_OpenDbPartially(This,newVal)	\
    ( (This)->lpVtbl -> put_OpenDbPartially(This,newVal) ) 


#define IOdaHostApp2_get_Console(This,pVal)	\
    ( (This)->lpVtbl -> get_Console(This,pVal) ) 

#define IOdaHostApp2_put_Console(This,newVal)	\
    ( (This)->lpVtbl -> put_Console(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IOdaHostApp2_INTERFACE_DEFINED__ */


#ifndef __IOdaBagFiler_INTERFACE_DEFINED__
#define __IOdaBagFiler_INTERFACE_DEFINED__

/* interface IOdaBagFiler */
/* [object][oleautomation][dual][helpstring][uuid] */ 


EXTERN_C const IID IID_IOdaBagFiler;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6eba6b5a-1d9f-4b21-bc0b-35efdbab543d")
    IOdaBagFiler : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ObjectToBuffer( 
            /* [in] */ /* external definition not present */ IAcadObject *pObj,
            /* [out] */ VARIANT *ResType,
            /* [out] */ VARIANT *ResValue) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE BufferToObject( 
            /* [in] */ /* external definition not present */ IAcadObject *pObj,
            /* [in] */ VARIANT ResType,
            /* [in] */ VARIANT ResValue) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IOdaBagFilerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IOdaBagFiler * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IOdaBagFiler * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IOdaBagFiler * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IOdaBagFiler * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IOdaBagFiler * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IOdaBagFiler * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IOdaBagFiler * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ObjectToBuffer )( 
            IOdaBagFiler * This,
            /* [in] */ /* external definition not present */ IAcadObject *pObj,
            /* [out] */ VARIANT *ResType,
            /* [out] */ VARIANT *ResValue);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *BufferToObject )( 
            IOdaBagFiler * This,
            /* [in] */ /* external definition not present */ IAcadObject *pObj,
            /* [in] */ VARIANT ResType,
            /* [in] */ VARIANT ResValue);
        
        END_INTERFACE
    } IOdaBagFilerVtbl;

    interface IOdaBagFiler
    {
        CONST_VTBL struct IOdaBagFilerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOdaBagFiler_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IOdaBagFiler_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IOdaBagFiler_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IOdaBagFiler_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IOdaBagFiler_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IOdaBagFiler_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IOdaBagFiler_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IOdaBagFiler_ObjectToBuffer(This,pObj,ResType,ResValue)	\
    ( (This)->lpVtbl -> ObjectToBuffer(This,pObj,ResType,ResValue) ) 

#define IOdaBagFiler_BufferToObject(This,pObj,ResType,ResValue)	\
    ( (This)->lpVtbl -> BufferToObject(This,pObj,ResType,ResValue) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IOdaBagFiler_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_AcPePropertyEditorColor;

#ifdef __cplusplus

class DECLSPEC_UUID("9EAF472F-A6A0-4289-8286-50C50C5AAFCD")
AcPePropertyEditorColor;
#endif

EXTERN_C const CLSID CLSID_AcPePropertyEditorTextStyle;

#ifdef __cplusplus

class DECLSPEC_UUID("1001C4DD-801C-4819-A566-02E293C2BA86")
AcPePropertyEditorTextStyle;
#endif

EXTERN_C const CLSID CLSID_AcPePropertyEditorLType;

#ifdef __cplusplus

class DECLSPEC_UUID("336167B1-10F3-4E59-A22A-A7A92FA367A4")
AcPePropertyEditorLType;
#endif

EXTERN_C const CLSID CLSID_AcPePropertyEditorLayer;

#ifdef __cplusplus

class DECLSPEC_UUID("FD6A8531-FB29-423A-ACF5-FE00DB1E5EB8")
AcPePropertyEditorLayer;
#endif

EXTERN_C const CLSID CLSID_AcPePropertyEditorLWeight;

#ifdef __cplusplus

class DECLSPEC_UUID("4C0E9D71-1F85-4048-9E17-3D3F4F1F2391")
AcPePropertyEditorLWeight;
#endif

EXTERN_C const CLSID CLSID_AcPePropertyEditorEllipses;

#ifdef __cplusplus

class DECLSPEC_UUID("46FC79C1-B4D8-47DB-B593-02ACB2668F62")
AcPePropertyEditorEllipses;
#endif

EXTERN_C const CLSID CLSID_AcPePick2PointsCtrl;

#ifdef __cplusplus

class DECLSPEC_UUID("85C8628A-E84D-431A-B0B5-D0B142C1B67B")
AcPePick2PointsCtrl;
#endif

EXTERN_C const CLSID CLSID_AcadApplication;

#ifdef __cplusplus

class DECLSPEC_UUID("BC27895B-1197-40D7-9C9A-C94EB52B1F48")
AcadApplication;
#endif

EXTERN_C const CLSID CLSID_AcadDocuments;

#ifdef __cplusplus

class DECLSPEC_UUID("80893A4A-712F-4404-AE88-66D7664B5003")
AcadDocuments;
#endif

EXTERN_C const CLSID CLSID_AcadDocument;

#ifdef __cplusplus

class DECLSPEC_UUID("4F626FA0-3C33-49D9-B1B1-CF0BEF14B331")
AcadDocument;
#endif

#ifndef ___IOdaHostAppEvents_DISPINTERFACE_DEFINED__
#define ___IOdaHostAppEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IOdaHostAppEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IOdaHostAppEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("5FA75E80-D112-4186-AD8E-0992D7F13475")
    _IOdaHostAppEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IOdaHostAppEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IOdaHostAppEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IOdaHostAppEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IOdaHostAppEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IOdaHostAppEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IOdaHostAppEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IOdaHostAppEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IOdaHostAppEvents * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } _IOdaHostAppEventsVtbl;

    interface _IOdaHostAppEvents
    {
        CONST_VTBL struct _IOdaHostAppEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IOdaHostAppEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _IOdaHostAppEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _IOdaHostAppEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _IOdaHostAppEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _IOdaHostAppEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _IOdaHostAppEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _IOdaHostAppEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IOdaHostAppEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_OdaHostApp;

#ifdef __cplusplus

class DECLSPEC_UUID("43C3A6C8-6BD0-4AF0-B326-0EFE59779D74")
OdaHostApp;
#endif

EXTERN_C const CLSID CLSID_AcadUtility;

#ifdef __cplusplus

class DECLSPEC_UUID("CA2C73B7-B493-4C3C-9A1C-E5D488EFA9F8")
AcadUtility;
#endif

EXTERN_C const CLSID CLSID_AcadPreferences;

#ifdef __cplusplus

class DECLSPEC_UUID("EAF56FFE-EE84-41B1-9526-06B50881D266")
AcadPreferences;
#endif

EXTERN_C const CLSID CLSID_AcadPreferencesFiles;

#ifdef __cplusplus

class DECLSPEC_UUID("02B6D693-202E-465E-8B06-7803983FD249")
AcadPreferencesFiles;
#endif

EXTERN_C const CLSID CLSID_AcadPreferencesDisplay;

#ifdef __cplusplus

class DECLSPEC_UUID("B6FCE2E9-D455-493C-BDB6-306843FE1E38")
AcadPreferencesDisplay;
#endif

EXTERN_C const CLSID CLSID_AcadPreferencesOpenSave;

#ifdef __cplusplus

class DECLSPEC_UUID("EFDD44D0-34AC-41BE-AA6D-3B339F44C68D")
AcadPreferencesOpenSave;
#endif

EXTERN_C const CLSID CLSID_AcadPreferencesOutput;

#ifdef __cplusplus

class DECLSPEC_UUID("299D00E6-D6D1-4D38-81E2-017EA80BB919")
AcadPreferencesOutput;
#endif

EXTERN_C const CLSID CLSID_AcadPreferencesPdfOutput;

#ifdef __cplusplus

class DECLSPEC_UUID("72E369C3-6DD9-486C-9B56-87C0A42583CB")
AcadPreferencesPdfOutput;
#endif

EXTERN_C const CLSID CLSID_AcadPreferencesSystem;

#ifdef __cplusplus

class DECLSPEC_UUID("1EF574F7-D6DD-44DC-995E-5BBC4F0274FD")
AcadPreferencesSystem;
#endif

EXTERN_C const CLSID CLSID_AcadPreferencesUser;

#ifdef __cplusplus

class DECLSPEC_UUID("98F09E3D-80E5-42AA-8C88-D1D5F4CAD7C9")
AcadPreferencesUser;
#endif

EXTERN_C const CLSID CLSID_AcadPreferencesDrafting;

#ifdef __cplusplus

class DECLSPEC_UUID("F99EEC2C-749E-4F86-BFEA-0D8BCC355404")
AcadPreferencesDrafting;
#endif

EXTERN_C const CLSID CLSID_AcadPreferencesSelection;

#ifdef __cplusplus

class DECLSPEC_UUID("14C9A247-BE9F-47A4-9427-156A6BDC80E4")
AcadPreferencesSelection;
#endif

EXTERN_C const CLSID CLSID_AcadPreferencesProfiles;

#ifdef __cplusplus

class DECLSPEC_UUID("3D38B082-D0C2-4C7F-8CED-D0F58078389C")
AcadPreferencesProfiles;
#endif

EXTERN_C const CLSID CLSID_AcadState;

#ifdef __cplusplus

class DECLSPEC_UUID("BF3D0EB4-EDFC-4265-9439-DD5E96157F25")
AcadState;
#endif

EXTERN_C const CLSID CLSID_AcadSelectionSet;

#ifdef __cplusplus

class DECLSPEC_UUID("B920B495-3B8D-4C6E-ABDF-953E2D98B283")
AcadSelectionSet;
#endif

EXTERN_C const CLSID CLSID_AcadSelectionSets;

#ifdef __cplusplus

class DECLSPEC_UUID("9B5C4472-7F02-4AC2-81F1-BABAA9A8A1CF")
AcadSelectionSets;
#endif

EXTERN_C const CLSID CLSID_AcadPlot;

#ifdef __cplusplus

class DECLSPEC_UUID("76792DF9-426B-478F-AE4E-FA010467884D")
AcadPlot;
#endif

EXTERN_C const CLSID CLSID_OdaDwfTemplate;

#ifdef __cplusplus

class DECLSPEC_UUID("42B88772-290A-44BD-8F2B-75A33575431D")
OdaDwfTemplate;
#endif

EXTERN_C const CLSID CLSID_OdaDwf3dExport;

#ifdef __cplusplus

class DECLSPEC_UUID("0D9B5D8B-D7C6-4821-AE5C-6B07E91C8EE2")
OdaDwf3dExport;
#endif

EXTERN_C const CLSID CLSID_OdaDwfImporter;

#ifdef __cplusplus

class DECLSPEC_UUID("DF0316BA-2E05-481C-99E2-4C3BB9314D4A")
OdaDwfImporter;
#endif

EXTERN_C const CLSID CLSID_AcadLayerStateManager;

#ifdef __cplusplus

class DECLSPEC_UUID("6A719532-C7A1-4EAA-AC12-07DA9277B2A4")
AcadLayerStateManager;
#endif

EXTERN_C const CLSID CLSID_AcadSecurityParams;

#ifdef __cplusplus

class DECLSPEC_UUID("A8D627D8-C61D-44A9-BF0F-D4A03B851073")
AcadSecurityParams;
#endif

EXTERN_C const CLSID CLSID_OdaSvgExporter;

#ifdef __cplusplus

class DECLSPEC_UUID("3C8C6839-45AD-4C0F-A629-44B784D5AA4F")
OdaSvgExporter;
#endif

EXTERN_C const CLSID CLSID_OdaBmpOut;

#ifdef __cplusplus

class DECLSPEC_UUID("7AEB9EC4-CAC0-4808-B8F0-FFEB704A5D13")
OdaBmpOut;
#endif

EXTERN_C const CLSID CLSID_OdaBagFiler;

#ifdef __cplusplus

class DECLSPEC_UUID("593E1179-2DB2-4185-B70B-3F7EA2EE5CBC")
OdaBagFiler;
#endif
#endif /* __BricscadApp_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


