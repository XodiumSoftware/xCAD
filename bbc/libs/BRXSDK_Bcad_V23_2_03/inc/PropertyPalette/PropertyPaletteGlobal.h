// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include <comdef.h>
#include <vector>
#include "Misc/MiscGlobal.h"
#include "OPMStructs.h"
#include "COM/wxg_property_interfaces.h"

//common forward declarations
interface IAcPiCategorizeProperties;
interface IAcPiCommandButton;
interface IAcPiPropCommandButtons;
interface IAcPiPropertyDisplay;
interface ICategorizeProperties;
interface IDynamicDialogProperty;
interface IDynamicEnumProperty;
interface IDynamicProperty2;
interface IDynamicPropertyNotify;
interface IDynamicPropertyNotify2;
interface IOPMPropertyDialog;
interface IOPMPropertyDialog2;
interface IOPMPropertyExpander2;
interface IPropertyManager2;
interface IRetrieveApplication;

#define GET_OPMEXTENSION_CREATE_PROTOCOL() OPMPropertyExtensionFactory::cast(AcDbDatabase::desc()->queryX(OPMPropertyExtensionFactory::desc()))
// Note: The caller is responsible for release IPropertyManager 
#define GET_OPMPROPERTY_MANAGER(Class) GET_OPMEXTENSION_CREATE_PROTOCOL()->CreateOPMObjectProtocol(Class)->GetPropertyManager()
#define GET_OPM_COMMAND_PROPERTY_MANAGER(CmdName) GET_OPMEXTENSION_CREATE_PROTOCOL()->CreateOPMCommandProtocol(CmdName)->GetPropertyManager()
#define GET_OPM_PERINSTANCE_CREATE_PROTOCOL() OPMPerInstancePropertyExtensionFactory::cast(AcDbDatabase::desc()->queryX(OPMPerInstancePropertyExtensionFactory::desc()))
#define GET_OPM_PERINSTANCE_EXTENSION_PROTOCOL(Class) GET_OPM_PERINSTANCE_CREATE_PROTOCOL()->CreateOPMPerInstancePropertyExtension(Class)
#define GET_OPM_PERINSTANCE_PROPERTY_SOURCES() OPMPerInstancePropertySources::cast(AcDbDatabase::desc()->queryX(OPMPerInstancePropertySources::desc()))


typedef int PROPCAT;

// category ID: negative values are 'standard' categories,  positive are control-specific
#define PROPCAT_Nil                    ((int) -1)
#define PROPCAT_Misc                   ((int) -2)
#define PROPCAT_Font                   ((int) -3)
#define PROPCAT_Position               ((int) -4)
#define PROPCAT_Appearance             ((int) -5)
#define PROPCAT_Behavior               ((int) -6)
#define PROPCAT_Data                   ((int) -7)
#define PROPCAT_List                   ((int) -8)
#define PROPCAT_Text                   ((int) -9)
#define PROPCAT_Scale                  ((int)-10)
#define PROPCAT_DDE                    ((int)-11)
#define PROPCAT_General                ((int)-12)
#define PROPCAT_Mass                   ((int)-13)
#define PROPCAT_Pattern                ((int)-14)
#define PROPCAT_DataPoints             ((int)-15)
#define PROPCAT_Mesh                   ((int)-16)
#define PROPCAT_ImageAdjust            ((int)-17)
#define PROPCAT_ControlPoints          ((int)-18)
#define PROPCAT_PrimaryUnits           ((int)-19)
#define PROPCAT_AltUnits               ((int)-20)
#define PROPCAT_Fit                    ((int)-21)
#define PROPCAT_LinesArrows            ((int)-22)
#define PROPCAT_Tolerances             ((int)-23)
#define PROPCAT_Table                  ((int)-24)
#define PROPCAT_Geometry               ((int)-25)
#define PROPCAT_Section                ((int)-26)
#define PROPCAT_UnderlayAdjust         ((int)-27)
#define PROPCAT_Solid_History          ((int)-28)
#define PROPCAT_Fillet                 ((int)-29)
#define PROPCAT_Chamfer                ((int)-30)
#define PROPCAT_3DVisualization        ((int)-31)
#define PROPCAT_Table_Breaks           ((int)-32)
#define PROPCAT_SURFACE_ASSOCIATIVITY  ((int)-33)
#define PROPCAT_SURFACE_TRIM           ((int)-34)
#define PROPCAT_ViewDefinition         ((int)-35)
#define PROPCAT_Annotation             ((int)-36)
#define PROPCAT_ReferenceData          ((int)-37)
#define PROPCAT_Representation         ((int)-38)
#define PROPCAT_PointcloudAdjust       ((int)-39)
#define PROPCAT_GeomapImageAdjust      ((int)-40)


struct ACAD_OPMPROPMAP_ENTRY
{
    UINT nDescID;
    DISPID dispid;
    PROPCAT catid;
    UINT nCatNameID;
    UINT nElementStrID;
    UINT nPredefinedStrID;
    const TCHAR* predefinedValues;
    unsigned short grouping;
    bool editable;
    const CLSID* pclsidOther;
    const CLSID* pclsidPropPage;
    const IID* piidDispatch;
    LPCOLESTR szEllipsesTxt;
};

#define BEGIN_OPMPROP_MAP() \
static ACAD_OPMPROPMAP_ENTRY* GetOPMPropertyMap() \
{ \
    static ACAD_OPMPROPMAP_ENTRY pPropMap[] = \
    {

#define END_OPMPROP_MAP() \
        {0, 0, 0, 0, 0, 0, NULL, 0, 0, NULL, NULL, &IID_NULL, NULL} \
    };\
    return pPropMap;\
}

#define OPMPROP_ENTRY(descId, dispId, categoryId, catNameId, elementsId, predefsId, predefVals, grouping, editable, ext, classId, text) \
        {descId, dispId, categoryId, catNameId, elementsId, predefsId, predefVals, \
            grouping, editable, &ext, &classId, &IID_IDispatch, OLESTR(text)},

#define OPMPROP_CAT_ENTRY(descId, dispId, categoryId, catNameId) \
        {descId, dispId, categoryId, catNameId, 0, 0, _ACRX_T(""), 0, 1, &IID_NULL, &IID_NULL, &IID_IDispatch, OLESTR("")},

#define OPMPROP_DESC_ENTRY(descId, dispId) \
        {descId, dispId, -2, 0, 0, 0, _ACRX_T(""), 0, 1, &IID_NULL, &IID_NULL, &IID_IDispatch, OLESTR("")},

#define OPMPROP_PREDEFINED_ENTRY(descId, dispId, predefsId, predefVals, ext) \
        {descId, dispId, -2, 0, 0, predefsId, predefVals, 0, 1, &ext, &IID_NULL, &IID_IDispatch, OLESTR("")},

#define OPMPROP_ELEMENT_ENTRY(dispId, categoryId, catNameId, elementsId, grouping) \
        {0, dispId, categoryId, catNameId, elementsId, 0, _ACRX_T(""), grouping, 1, &IID_NULL, &IID_NULL, &IID_IDispatch, OLESTR("")},

#define OPMPROP_PAGE(descId, dispId, categoryId, catNameId, clsid) \
        {descId, dispId, categoryId, catNameId, 0, 0, _ACRX_T(""), 0, 1, &IID_NULL, &clsid, &IID_IDispatch, OLESTR("")},


/*--------------------------------------------------------------------------------------*/

typedef int PROPCAT;

struct PER_PROP_DISP_ENTRY
{
    DISPID m_dispid;
    const ACHAR* m_ProgID;
    const ACHAR* m_lpLeftIconRes;
    UINT m_nLeftIconType;
    const ACHAR* m_lpEllipsisBmpRes;
    UINT m_nEllipsisBmpType;
    COLORREF m_TextColor;
    bool m_bFullView;
    DWORD m_dwIntegralHeight;
    long m_nWeight;
};

#define BEGIN_PERPROPDISPLAY_MAP() \
static PER_PROP_DISP_ENTRY* GetPerPropDisplayArray() \
{ \
    static PER_PROP_DISP_ENTRY pPerPropDisplayArray[] = \
    {

#define END_PERPROPDISPLAY_MAP() \
        {(DISPID)-1, NULL, NULL, (UINT)-1, NULL, (UINT)-1, 0x80000008, false, (DWORD)-1, -1} \
    }; \
    return pPerPropDisplayArray; \
}

#define PROP_DISP_ENTRY(dispId, progId, iconRes, iconType, bmpRes, bmpType, color, fullView, height, weight) \
        {dispId, progId, iconRes, iconType, bmpRes, bmpType, color, fullView, height, weight}, \


typedef BOOL (*BUTTONPROC)(IAcPiCommandButton* pButton, VARIANT Objects);

struct CATCMDBTN_ENTRY
{
    PROPCAT m_CatID;
    UINT m_nBtnNameId;
    const ACHAR* m_lpEnBtnBmpRes;
    UINT m_nEnBtnBmpType;
    const ACHAR* m_lpDisBtnBmpRes;
    UINT m_nDisBtnBmpType;
    long m_nStyle;
    BUTTONPROC m_pfnBtnProc;
};

#define BEGIN_CATCMDBTN_MAP() \
static CATCMDBTN_ENTRY * GetCmdBtnArray() \
{ \
    static CATCMDBTN_ENTRY pCatCmdBtnArray[] = \
    {

#define END_CATCMDBTN_MAP() \
        {(PROPCAT)-1, 0, NULL, (UINT)PICTYPE_UNINITIALIZED, NULL, (UINT)PICTYPE_UNINITIALIZED, NULL, NULL} \
    }; \
    return pCatCmdBtnArray; \
}

#define CATCMDBTN_MAP_ENTRY(catId, btnId, bmp1Res, bmp1Type, bmp2Res, bmp2Type, style, pFunc) \
        {catId, btnId, bmp1Res, bmp1Type, bmp2Res, bmp2Type, style, pFunc},                        


struct CMDBTN_ENTRY
{
    UINT m_nBtnNameId;
    const ACHAR* m_lpEnBtnBmpRes;
    UINT m_nEnBtnBmpType;
    const ACHAR* m_lpDisBtnBmpRes;
    UINT m_nDisBtnBmpType;
    long m_nStyle;
    BUTTONPROC m_pfnBtnProc;
};

#define BEGIN_CMDBTN_MAP() \
static CMDBTN_ENTRY * GetPropCmdBtnArray() \
{ \
    static CMDBTN_ENTRY pCmdBtnArray[] = \
    {

#define END_CMDBTN_MAP() \
        {0, NULL, (UINT)-1, NULL, (UINT)-1, NULL, NULL} \
    }; \
    return pCmdBtnArray; \
}

#define CMDBTN_MAP_ENTRY(nameId,  bmp1Res, bmp1Type, bmp2Res, bmp2Type, style, pFunc) \
        {nameId, bmp1Res, bmp1Type, bmp2Res, bmp2Type, style, pFunc},                        

struct CATEGORY_ENTRY
{
    PROPCAT m_CatID;
    UINT m_nNameId;
    UINT m_nDescId;
    PROPCAT m_ParentCatID;
    long m_nWeight;
};

#define BEGIN_CAT_MAP() \
static CATEGORY_ENTRY*  GetCatArray() \
{ \
    static CATEGORY_ENTRY pCatArray[] = \
    {

#define END_CAT_MAP() \
        {(PROPCAT)-1, 0, 0, (PROPCAT)-1, -1} \
    }; \
    return pCatArray; \
}

#define CATEGORY_MAP_ENTRY(catId, nameId, descId, parentId, weight) \
        {catId, nameId, descId, parentId, weight}, 

typedef std::vector<PER_PROP_DISP_ENTRY> PROP_DISP_VECTOR;
typedef std::vector<CATCMDBTN_ENTRY> CATCMDBTN_VECTOR;
typedef std::vector<CATEGORY_ENTRY> CATEGORY_VECTOR;
typedef std::vector<CMDBTN_ENTRY> CMDBTN_VECTOR;
