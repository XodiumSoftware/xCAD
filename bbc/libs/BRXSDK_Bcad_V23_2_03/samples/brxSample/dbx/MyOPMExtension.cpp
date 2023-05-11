// Copyright (C) Menhirs NV. All rights reserved.
//
// This is an example how to use the C++ OPM Extension API,
// a BricsCAD specific PropertiesPanel interface

#include "StdAfx.h"
#include <tchar.h>
#include "MyEntity.h"

#ifndef BRX_APP  // // dummy implemented for ARX build
bool registerMyOPMExtension()
{
    return false;
}
bool unregisterMyOPMExtension()
{
    return false;
}
#endif // !BRX_APP


#ifdef BRX_APP  // not available with ARX

#include "AcDb/AcDbEntity.h"
#include "AcDb/AcDbLine.h"
#include "AcDb/AcDbCircle.h"
#include "MyOPMExtension.h"

// some OPM features are only available with V17 and higher
#if (__BRXTARGET < 17)
#define opmVertexSubentType 0
#define opmEdgeSubentType   0
#define opmFaceSubentType   0
#define opmFlagReloadPanelOnModify 0
#endif

static CMyOPMClientExtension*  s_myOPMExtension  = NULL;
static CMyOPMClientExtension2* s_myOPMExtension2 = NULL; // special handler for subentity support

static LPCTSTR s_strClientDataDyn = _T("_Sample_DYN_Client_Data_");
static LPCTSTR s_strClientDataPIP = _T("_Sample_PIP_Client_Data_");
static size_t  s_intClientData = 123456;

static ACHAR* s_guiEntityName = _T("Circle+Triangle");

const int s_offset_Opm2 = 500;


// client Callback function (AcOPMPropertyDialogProc)
bool clientCallbackFunction(const AcDbObjectIdArray& pickSet,
                            AcOPMPropertyId propertyId, const AcString& propertyName,
                            const AcString& childName, AcOPMVariant& value);


bool registerMyOPMExtension()
{
    // example to demonstrate all capabilities of C++ OPM API
    s_myOPMExtension = new CMyOPMClientExtension();
    // register the properties for target entity type
    AcOpmResult res = acRegisterEntityExtension(s_myOPMExtension, CMyEntity::desc(), true);
    // register the "NO SELECTION" properties
    res = acRegisterGeneralExtension(s_myOPMExtension);

    // small example to demonstrate subentity handling
    s_myOPMExtension2 = new CMyOPMClientExtension2();
    // register the properties for target + derived entity type + all supported subentity types
#if (__BRXTARGET < 17) // registration extended with V17
    res = acRegisterEntityExtension(s_myOPMExtension2, AcDb3dSolid::desc(), true);
#else
    res = acRegisterEntityExtension(s_myOPMExtension2, AcDb3dSolid::desc(), true,
                                    opmVertexSubentType | opmEdgeSubentType | opmFaceSubentType);
#endif

    return (res == opmNoError);
}

bool unregisterMyOPMExtension()
{
    //bool res = acUnregisterEntityExtension(myOPMExtension, CMyEntity::desc());
    bool res = acRemoveOPMExtension(s_myOPMExtension);
    delete s_myOPMExtension, s_myOPMExtension = NULL;

    res = acRemoveOPMExtension(s_myOPMExtension2);
    delete s_myOPMExtension2, s_myOPMExtension2 = NULL;

    return true;
}


// =======================================================================================
// client-side handler class CMyOPMClientExtension2
// =======================================================================================
// particular sample to show "main" entity and "subentity" support for OdDb3dSolid

CMyOPMClientExtension2::CMyOPMClientExtension2()
{
    // test data
    m_mainStr    = _T("'static' main string");
    m_mainDynStr = _T("'dynamic' main string");;
    m_mainPipStr = _T("'dynamic PIP' main string");;

    m_intSubentVertex = 6;
    m_intSubentEdge   = 7;
    m_intSubentFace   = 8;

    m_dblDynSubentVertex = 66.0;
    m_dblDynSubentEdge   = 77.0;
    m_dblDynSubentFace   = 88.0;

    m_dblPipSubentVertex = 666.0;
    m_dblPipSubentEdge   = 777.0;
    m_dblPipSubentFace   = 888.0;
}

CMyOPMClientExtension2::~CMyOPMClientExtension2()
{
    bool res = acRemoveOPMExtension(s_myOPMExtension2);
}

#if (__BRXTARGET >= 17) // only available with BRX >= V17
bool CMyOPMClientExtension2::getApplicationName(AcString& name) const
{
    name = _T("BRX Sample App : Extension #2");
    return true;
}

void CMyOPMClientExtension2::beginPropertiesUpdate(const AcDbObjectIdArray& selectionSet) const
{
}

void CMyOPMClientExtension2::endPropertiesUpdate() const
{
}
#endif // __BRXTARGET

// dynamic properties for "target entity type"
bool CMyOPMClientExtension2::supportsDynamicProperties() const
{
    return true;
}

// properties for "target entity type" ("main" entity)
bool CMyOPMClientExtension2::getPropertyMap(const AcRxClass* entityClass,
                                            AcOPMPropertyArray& properties) const
{
    // 1 general property for OdDb3dSolid : text string (m_mainStr)
    AcOPMPropertyEntry property(_T("3dSolid Extension"), _T("Property String"),
                                AcOPMPROP_FirstUserProp + s_offset_Opm2 + 1, opmTypeString);

// some OPM features are only available with V17 and higher
#if (__BRXTARGET >= 17)
    property.m_pClientData  = (void*)&s_intClientData;
#endif
    properties.append(property);

    return true;
}

#if (__BRXTARGET >= 17) // only available with BRX >= V17
// properties for "target entity type" ("subentity" entity)
bool CMyOPMClientExtension2::getPropertyMap(const AcRxClass* entityClass,
                                            const AcOpmSubEntityType subentType,
                                            AcOPMPropertyArray& properties) const
{
    // 3 general properties for OdDb3dSolid (vertex, edge, face) : integers
    switch(subentType)
    {
        case opmVertexSubentType :
             {   // m_intSubentVertex
                 AcOPMPropertyEntry property(_T("3dSolid Extension"), _T("Property Integer (Vertex)"),
                                             AcOPMPROP_FirstUserProp + s_offset_Opm2 + 2, opmTypeInteger);
                 properties.append(property);
             }
             break;
        case opmEdgeSubentType :
             {   // m_intSubentEdge;
                 AcOPMPropertyEntry property(_T("3dSolid Extension"), _T("Property Integer (Edge)"),
                                             AcOPMPROP_FirstUserProp + s_offset_Opm2 + 3, opmTypeInteger);
                 properties.append(property);
             }
             break;
        case opmFaceSubentType :
             {   // m_intSubentFace;
                 AcOPMPropertyEntry property(_T("3dSolid Extension"), _T("Property Integer (Face)"),
                                             AcOPMPROP_FirstUserProp + s_offset_Opm2 + 4, opmTypeInteger);
                 properties.append(property);
             }
             break;
        default :
            return false;
    }

    return true;
}
#endif // __BRXTARGET

// dynamic properties for "target entity type" ("main" entity)
bool CMyOPMClientExtension2::getDynamicPropertyMap(const AcDbEntity* entity,
                                                   AcOPMPropertyArray& properties) const
{
    // 1 general property for OdDb3dSolid : text string (m_mainDynStr)
    AcOPMPropertyEntry propertyDyn(_T("3dSolid Dynamic"), _T("DYN String"),
                                   AcOPMPROP_FirstUserProp + s_offset_Opm2 + 5, opmTypeString, false);
// some OPM features are only available with V17 and higher
#if (__BRXTARGET >= 17)
    propertyDyn.m_pClientData = (void*)s_strClientDataDyn;
#endif
    properties.append(propertyDyn);

    // 1 general per-instance-property for OdDb3dSolid : text string (m_mainPipStr)
    AcOPMPropertyEntry propertyPIP(_T("3dSolid Dynamic"), _T("PIP String"),
                                   AcOPMPROP_FirstUserProp + s_offset_Opm2 + 6, opmTypeString, true); // per-instance
// some OPM features are only available with V17 and higher
#if (__BRXTARGET >= 17)
    propertyPIP.m_pClientData = (void*)s_strClientDataPIP;
#endif
    properties.append(propertyPIP);

    return true;
}

#if (__BRXTARGET >= 17) // only available with BRX >= V17
// dynamic properties for "target entity type" ("subentity" entity)
bool CMyOPMClientExtension2::getDynamicPropertyMap(const AcDbEntity* entity,
                                                   const AcOpmSubEntityType subentType, 
                                                   const AcDbFullSubentPathArray& fspArray,
                                                   AcOPMPropertyArray& properties) const
{
    // 3 dynamic PIP properties for OdDb3dSolid (vertex, edge, face) : doubles
    switch(subentType)
    {
        case opmVertexSubentType :
             {
                 // m_dblDynSubentVertex
                 AcOPMPropertyEntry propertyDYN(_T("3dSolid Dynamic"), _T("DYN Point (Vertex)"),
                                                AcOPMPROP_FirstUserProp + s_offset_Opm2 + 7, opmTypePoint3d, false);
                 properties.append(propertyDYN);
                 // m_dblPipSubentVertex
                 AcOPMPropertyEntry propertyPIP(_T("3dSolid Dynamic"), _T("PIP Point (Vertex)"),
                                                AcOPMPROP_FirstUserProp + s_offset_Opm2 + 8, opmTypePoint3d, true); // per-instance
                 properties.append(propertyPIP);
             }
             break;
        case opmEdgeSubentType :
             {
                 // m_dblDynSubentEdge;
                 AcOPMPropertyEntry propertyDYN(_T("3dSolid Dynamic"), _T("DYN Distance (Edge)"),
                                                AcOPMPROP_FirstUserProp + s_offset_Opm2 + 9, opmTypeDistance, false);
                 properties.append(propertyDYN);
                 // m_dblPipSubentEdge;
                 AcOPMPropertyEntry propertyPIP(_T("3dSolid Dynamic"), _T("PIP Distance (Edge)"),
                                                AcOPMPROP_FirstUserProp + s_offset_Opm2 + 10, opmTypeDistance, true); // per-instance
                 properties.append(propertyPIP);
             }
             break;
        case opmFaceSubentType :
             {
                 // m_dblDynSubentFace;
                 AcOPMPropertyEntry propertyDYN(_T("3dSolid Dynamic"), _T("DYN Angle (Face)"),
                                                AcOPMPROP_FirstUserProp + s_offset_Opm2 + 11, opmTypeAngle, false);
                 properties.append(propertyDYN);
                 // m_dblPipSubentFace;
                 AcOPMPropertyEntry propertyPIP(_T("3dSolid Dynamic"), _T("PIP Angle (Face)"),
                                                AcOPMPROP_FirstUserProp + s_offset_Opm2 + 12, opmTypeAngle, true); // per-instance
                 properties.append(propertyPIP);
             }
             break;
        default :
            return false;
    }

    return true;
}
#endif // __BRXTARGET

bool CMyOPMClientExtension2::getPropertyValue(const AcDbEntity* entity,
                                              AcOPMPropertyId propertyId,
                                              const AcString& childName,
                                              AcOPMVariant& value) const
{
    // check clientData
// some OPM features are only available with V17 and higher
#if (__BRXTARGET >= 17)
    void* pClientData = acOPMExtensionManager()->getActiveOPMPropertyClientData();
    LPCTSTR szClientData = LPCTSTR(pClientData);
    size_t* intClientData = (size_t*)pClientData;
#endif

    // normal entity properties + PerInstance entity properties
    switch (propertyId)
    {
        case AcOPMPROP_FirstUserProp + s_offset_Opm2 + 1 : // opmTypeString
             value = m_mainStr;
             return true;
        case AcOPMPROP_FirstUserProp + s_offset_Opm2 + 5 : // opmTypeString (DYN)
             value = m_mainDynStr;
             return true;
        case AcOPMPROP_FirstUserProp + s_offset_Opm2 + 6 : // opmTypeString (PIP)
             value = m_mainPipStr;
             return true;
    }

    return false;
}

#if (__BRXTARGET >= 17) // only available with BRX >= V17
// get property value for "target entity type" ("subentity" entity)
bool CMyOPMClientExtension2::getPropertyValue(const AcDbEntity* entity,
                                              const AcOpmSubEntityType subentType,
                                              const AcDbFullSubentPathArray& fspArray,
                                              const AcOPMPropertyId propertyId,
                                              const AcString& childName,
                                              AcOPMVariant& value) const
{
    // check clientData
    void* pClientData = acOPMExtensionManager()->getActiveOPMPropertyClientData();
    LPCTSTR szClientData = LPCTSTR(pClientData);
    size_t* intClientData = (size_t*)pClientData;

    // normal subentity properties + PerInstance subentity properties
    switch(subentType)
    {
        case opmVertexSubentType :
             if (propertyId == AcOPMPROP_FirstUserProp + s_offset_Opm2 + 2)
             {
                 value = m_intSubentVertex;
                 return true;
             }
             if (propertyId == AcOPMPROP_FirstUserProp + s_offset_Opm2 + 7)
             {
                 value = m_dblDynSubentVertex;
                 return true;
             }
             if (propertyId == AcOPMPROP_FirstUserProp + s_offset_Opm2 + 8)
             {
                 value = m_dblPipSubentVertex;
                 return true;
             }
             break;
        case opmEdgeSubentType :
             if (propertyId == AcOPMPROP_FirstUserProp + s_offset_Opm2 + 3)
             {
                 value = m_intSubentEdge;
                 return true;
             }
             if (propertyId == AcOPMPROP_FirstUserProp + s_offset_Opm2 + 9)
             {
                 value = m_dblDynSubentEdge;
                 return true;
             }
             if (propertyId == AcOPMPROP_FirstUserProp + s_offset_Opm2 + 10)
             {
                 value = m_dblPipSubentEdge;
                 return true;
             }
             break;
        case opmFaceSubentType :
             if (propertyId == AcOPMPROP_FirstUserProp + s_offset_Opm2 + 4)
             {
                 value = m_intSubentFace;
                 return true;
             }
             if (propertyId == AcOPMPROP_FirstUserProp + s_offset_Opm2 + 11)
             {
                 value = m_dblDynSubentFace;
                 return true;
             }
             if (propertyId == AcOPMPROP_FirstUserProp + s_offset_Opm2 + 12)
             {
                 value = m_dblPipSubentFace;
                 return true;
             }
             break;
    }

    return false;
}
#endif // __BRXTARGET

// set property value for "target entity type" ("main" entity)
bool CMyOPMClientExtension2::setPropertyValue(AcDbEntity* entity,
                                              AcOPMPropertyId propertyId, 
                                              const AcString& childName,
                                              const AcOPMVariant& value)
{
    // check clientData
#if (__BRXTARGET >= 17) // only available with BRX >= V17
    void* pClientData = acOPMExtensionManager()->getActiveOPMPropertyClientData();
    LPCTSTR szClientData = LPCTSTR(pClientData);
    size_t* intClientData = (size_t*)pClientData;
#endif

    // normal entity properties + PerInstance entity properties
    switch (propertyId)
    {
        case AcOPMPROP_FirstUserProp + s_offset_Opm2 + 1 : // opmTypeString
             return value.get(m_mainStr);
        case AcOPMPROP_FirstUserProp + s_offset_Opm2 + 5 : // opmTypeString
             return value.get(m_mainDynStr);
        case AcOPMPROP_FirstUserProp + s_offset_Opm2 + 6 : // opmTypeString
             return value.get(m_mainPipStr);
    }

    return false;
}

#if (__BRXTARGET >= 17) // only available with BRX >= V17
// set property value for "target entity type" ("subentity" entity)
bool CMyOPMClientExtension2::setPropertyValue(AcDbEntity* entity,
                                              const AcOpmSubEntityType subentType,
                                              const AcDbFullSubentPathArray& fspArray,
                                              const AcOPMPropertyId propertyId,
                                              const AcString& childName,
                                              const AcOPMVariant& value)
{
    // check clientData
    void* pClientData = acOPMExtensionManager()->getActiveOPMPropertyClientData();
    LPCTSTR szClientData = LPCTSTR(pClientData);
    size_t* intClientData = (size_t*)pClientData;

    // normal subentity properties + PerInstance subentity properties
    switch(subentType)
    {
        case opmVertexSubentType :
             if (propertyId == AcOPMPROP_FirstUserProp + s_offset_Opm2 + 2)
                 return value.get(m_intSubentVertex);
             if (propertyId == AcOPMPROP_FirstUserProp + s_offset_Opm2 + 7)
                 return value.get(m_dblDynSubentVertex);
             if (propertyId == AcOPMPROP_FirstUserProp + s_offset_Opm2 + 8)
                 return value.get(m_dblPipSubentVertex);
             break;
        case opmEdgeSubentType :
             if (propertyId == AcOPMPROP_FirstUserProp + s_offset_Opm2 + 3)
                 return value.get(m_intSubentEdge);
             if (propertyId == AcOPMPROP_FirstUserProp + s_offset_Opm2 + 9)
                 return value.get(m_dblDynSubentEdge);
             if (propertyId == AcOPMPROP_FirstUserProp + s_offset_Opm2 + 10)
                 return value.get(m_dblPipSubentEdge);
             break;
        case opmFaceSubentType :
             if (propertyId == AcOPMPROP_FirstUserProp + s_offset_Opm2 + 4)
                 return value.get(m_intSubentFace);
             if (propertyId == AcOPMPROP_FirstUserProp + s_offset_Opm2 + 11)
                 return value.get(m_dblDynSubentFace);
             if (propertyId == AcOPMPROP_FirstUserProp + s_offset_Opm2 + 12)
                 return value.get(m_dblPipSubentFace);
             break;
    }

    return false;
}
#endif // __BRXTARGET

#if __BRXTARGET >= 22  // since V22
// this function is called to retrieve all possible entity names, specific for this AcOPMClientExtension;
bool CMyOPMClientExtension2::allEntityNames(AcOPMEntityTypeNames& names) const
{
    // does not handle a custom entity, but AcDb3dSolid sub-entitiy types
    return false;
}
#endif // __BRXTARGET


// =======================================================================================
// client-side handler class
// =======================================================================================
// sample to show all mechanisms supported by API

CMyOPMClientExtension::CMyOPMClientExtension()
{
    // test data
    m_bool0 = true;
    m_checkBox1 = false;
    m_integer2 = 1234;

    m_comboStr3 = _T("List Value 2");
    m_double4 = 234.5678;

    m_color5.setRGB(50, 100, 150);

    m_sub5idx0  = _T("Test ");
    m_sub5idx1  = AcGePoint2d(10,20);
    m_sub5idx2  = AcGePoint3d(11,21,31);
    m_sub5idx3  = AcGePoint2d(10,20);
    m_sub5idx4  = AcGePoint3d(11,21,31);
    m_sub5idx5  = _T("0");
    m_sub5idx6  = _T("TestBlock");
    m_sub5idx7  = _T("Test");
    m_sub5idx8  = _T("Test");
    m_sub5idx9  = _T("ByLayer");
    m_sub5idx10 = 100;
    m_sub5idx11 = _T("Closed");
    m_sub5idx12 = _T("C:\\Windows");
    m_sub5idx13 = _T("bricscad.exe");

    m_vec2d     = AcGeVector2d(11,21);
    m_vec3d     = AcGeVector3d(12,22,32);
    m_vec2dUcs  = AcGeVector2d(13,23);
    m_vec3dUcs  = AcGeVector3d(14,24,34);

    m_range = 20;

    m_textstyle    = _T("Standard");
    m_dimstyle     = _T("ISO-25");
    m_tablestyle   = _T("Standard");
    m_mlstyle      = _T("Standard");
    m_mleaderstyle = _T("Standard");
    m_material     = _T("Global");
    m_layout       = _T("Layout1");
    m_plotstyle    = _T("ByLayer");
    m_gradient     = _T("Linear");
    m_pattern      = _T("P|Ansi31");
    m_annoscale    = _T("1:10");

    m_childStr23a  = _T("child string A");
    m_childStr23b  = _T("child string B");
    m_parentStr23  = _T("");  // shall be calculated during getProeprtyValue()

    m_comboStr24   = _T("Combo Value 2");

    m_comboPredefined24.append(_T("Combo Value 1"));
    m_comboPredefined24.append(_T("Combo Value 2"));
    m_comboPredefined24.append(_T("Combo Value 3"));

    m_string25     = _T("Sample String");

    // Callback property
    m_string26     = _T("callback property value");

    // enum combo
    m_enumStr27    = _T("Enum Value 2");

    m_enumPredefined27.append(_T("Enum Value 1"));
    m_enumPredefined27.append(_T("Enum Value 2"));
    m_enumPredefined27.append(_T("Enum Value 3"));

    m_enumPredefined27_2.append(_T("Enum Value 0"));
    m_enumPredefined27_2.append(_T("Enum Value 1"));
    m_enumPredefined27_2.append(_T("Enum Value 2"));
    m_enumPredefined27_2.append(_T("Enum Value 3"));
    m_enumPredefined27_2.append(_T("Enum Value 4"));

    // Per-Instance properties
    m_pipString    = _T("a PIP string value");
    m_pipDouble    = -1234.5678;

    // dynamic Per-Instance properties
    m_dynPipString1  = _T("dynamic PIP string value #1");
    m_dynPipDouble1  = 222.555;
    m_dynPipInteger1 = 998877;

    m_dynPipString2  = _T("dynamic PIP string value #2");
    m_dynPipDouble2  = 333.666;
    m_dynPipInteger2 = 665544;

    m_dynPipString3  = _T("dynamic PIP string value #3");
    m_dynPipDouble3  = 444.777;
    m_dynPipInteger3 = 332211;

    // NoSelection properties
    m_appSettings1  = _T("Application Mode");
    m_appSettings2  = 1234.5678;
    m_docSettings1  = true;
    m_docSettings2  = 22;
    m_docSettings2a = _T("setting A");
    m_docSettings2b = 789;
}

CMyOPMClientExtension::~CMyOPMClientExtension()
{
    //bool res = acUnregisterEntityExtension(myOPMExtension, CMyEntity::desc());
    bool res = acRemoveOPMExtension(s_myOPMExtension);
}

#if (__BRXTARGET >= 17) // only available with BRX >= V17
bool CMyOPMClientExtension::getApplicationName(AcString& name) const
{
    name = _T("BRX Sample App : Extension #1");
    return true;
}

void CMyOPMClientExtension::beginPropertiesUpdate(const AcDbObjectIdArray& selectionSet) const
{
}

void CMyOPMClientExtension::endPropertiesUpdate() const
{
}
#endif // __BRXTARGET

// fill the properties array for target entity class
bool CMyOPMClientExtension::getPropertyMap(const AcRxClass* entityClass,
                                           AcOPMPropertyArray& properties) const
{
    AcOPMPropertyEntry property1(AcOPMCAT_General, _T("Test Property Bool"), AcOPMPROP_FirstUserProp,
                                                   AcOpmDataType(opmTypeBool | opmFlagReloadPanelOnModify));
    properties.append(property1);

    AcOPMPropertyEntry property2(AcOPMCAT_General, _T("Property 1 CheckBox"), AcOPMPROP_FirstUserProp + 1, opmTypeCheckBox);
    properties.append(property2);

    AcOPMPropertyEntry property3; // = property1;
    property3.m_categoryName = _T("Test Category");
    property3.m_categoryId   = AcOPMCAT_FirstUserCat;
    property3.m_propertyName = _T("Property 2 Int");
    property3.m_propertyId   = AcOPMPROP_FirstUserProp + 2;
    property3.m_propertyType = opmTypeInteger;

    properties.append(property3);

    AcStringArray predefinedStrings;
    predefinedStrings.append(_T("List Value 1"));
    predefinedStrings.append(_T("List Value 2"));
    predefinedStrings.append(_T("List Value 3"));
    predefinedStrings.append(_T("List Value 4"));
    predefinedStrings.append(_T("List Value 5"));

    properties.append(AcOPMPropertyEntry(_T("Test Category"), _T("Property 3 Enum/Combo"),
                                         AcOPMPROP_FirstUserProp + 3, opmTypeString, false, predefinedStrings));

    // to test automatic assign of new category ID
    properties.append(AcOPMPropertyEntry(_T("Extra Category"), _T("Property 4 Angle"),
                                         AcOPMPROP_FirstUserProp + 4, opmTypeAngle));

    // to test child items
    AcOPMPropertyEntry property5(_T("Extra Category"), _T("Property 5 Color + SubProps"),
                                 AcOPMPROP_FirstUserProp + 5, opmTypeColor);

    property5.m_childNames.append(_T("String"));     property5.m_childTypes.append(opmTypeString);
    property5.m_childNames.append(_T("Pnt 2d"));     property5.m_childTypes.append(opmTypePoint2d);
    property5.m_childNames.append(_T("Pnt 3d"));     property5.m_childTypes.append(opmTypePoint3d);
    property5.m_childNames.append(_T("Pnt 2d Ucs")); property5.m_childTypes.append(opmTypePoint2dUcs);
    property5.m_childNames.append(_T("Pnt 3d Ucs")); property5.m_childTypes.append(opmTypePoint3dUcs);
    property5.m_childNames.append(_T("Layer"));      property5.m_childTypes.append(opmTypeLayer);
    property5.m_childNames.append(_T("Block"));      property5.m_childTypes.append(opmTypeBlock);
    property5.m_childNames.append(_T("Ucs"));        property5.m_childTypes.append(opmTypeUcs);
    property5.m_childNames.append(_T("View"));       property5.m_childTypes.append(opmTypeView);
    property5.m_childNames.append(_T("Linetype"));   property5.m_childTypes.append(opmTypeLinetype);
    property5.m_childNames.append(_T("Lineweight")); property5.m_childTypes.append(opmTypeLineweight);
    property5.m_childNames.append(_T("ArrowHead"));  property5.m_childTypes.append(opmTypeArrowhead);
    property5.m_childNames.append(_T("Folder"));     property5.m_childTypes.append(opmTypeFolder);
    property5.m_childNames.append(_T("File"));       property5.m_childTypes.append(opmTypeFile);

    properties.append(property5);

    properties.append(AcOPMPropertyEntry(_T("More Properties ..."), _T("Property 6 Vec2d (disabled+show)"),
                                         AcOPMPROP_FirstUserProp + 6, opmTypeVector2d));

    properties.append(AcOPMPropertyEntry(_T("More Properties ..."), _T("Property 7 Vec3d (disabled+show)"),
                                         AcOPMPROP_FirstUserProp + 7, opmTypeVector3d));

    properties.append(AcOPMPropertyEntry(_T("More Properties ..."), _T("Property 8 Vec2d Ucs (read-only)"),
                                         AcOPMPROP_FirstUserProp + 8, opmTypeVector2dUcs));

    properties.append(AcOPMPropertyEntry(_T("More Properties ..."), _T("Property 9 Vec3d Ucs"),
                                         AcOPMPROP_FirstUserProp + 9, opmTypeVector3dUcs));

    properties.append(AcOPMPropertyEntry(_T("More Properties ..."), _T("Property 10 Range"),
                                         AcOPMPROP_FirstUserProp + 10, opmTypeRange));

    properties.append(AcOPMPropertyEntry(_T("More Properties ..."), _T("Property 11 TextStyle"),
                                         AcOPMPROP_FirstUserProp + 11, opmTypeTextstyle));

    properties.append(AcOPMPropertyEntry(_T("More Properties ..."), _T("Property 12 DimStyle"),
                                         AcOPMPROP_FirstUserProp + 12, opmTypeDimstyle));

    properties.append(AcOPMPropertyEntry(_T("More Properties ..."), _T("Property 13 Tablestyle"),
                                         AcOPMPROP_FirstUserProp + 13, opmTypeTablestyle));

    properties.append(AcOPMPropertyEntry(_T("More Properties ..."), _T("Property 14 Mlinestyle"),
                                         AcOPMPROP_FirstUserProp + 14, opmTypeMlinestyle));

    properties.append(AcOPMPropertyEntry(_T("More Properties ..."), _T("Property 15 Mleaderstyle"),
                                         AcOPMPROP_FirstUserProp + 15, opmTypeMleaderstyle));

    properties.append(AcOPMPropertyEntry(_T("More Properties ..."), _T("Property 16 Material"),
                                         AcOPMPROP_FirstUserProp + 16, opmTypeMaterial));

    properties.append(AcOPMPropertyEntry(_T("More Properties ..."), _T("Property 17 Layout"),
                                         AcOPMPROP_FirstUserProp + 17, opmTypeLayout));

    properties.append(AcOPMPropertyEntry(_T("More Properties ..."), _T("Property 18 PlotStyleName"),
                                         AcOPMPROP_FirstUserProp + 18, opmTypePlotStyleName));

    properties.append(AcOPMPropertyEntry(_T("More Properties ..."), _T("Property 19 GradientName"),
                                         AcOPMPROP_FirstUserProp + 19, opmTypeGradientName));

    properties.append(AcOPMPropertyEntry(_T("More Properties ..."), _T("Property 20 PatternType"),
                                         AcOPMPROP_FirstUserProp + 20, opmTypePatternType));

    properties.append(AcOPMPropertyEntry(_T("More Properties ..."), _T("Property 21 PatternName"),
                                         AcOPMPROP_FirstUserProp + 21, opmTypePatternName));

    properties.append(AcOPMPropertyEntry(_T("More Properties ..."), _T("Property 22 AnnotativeScale"),
                                         AcOPMPROP_FirstUserProp + 22, opmTypeAnnotativeScale));

    // parentString + subString
    AcOPMPropertyEntry property6(_T("More Properties ..."), _T("Property 23 Parent + Child Strings"),
                                 AcOPMPROP_FirstUserProp + 23, opmTypeString);
    property6.m_childNames.append(_T("Child String A")); property6.m_childTypes.append(opmTypeString);
    property6.m_childNames.append(_T("Child String B")); property6.m_childTypes.append(opmTypeString);

    properties.append(property6);

    properties.append(AcOPMPropertyEntry(_T("More Properties ..."), _T("Property 24 Combo"),
                                         AcOPMPROP_FirstUserProp + 24, opmTypeCombo, false, m_comboPredefined24));

    properties.append(AcOPMPropertyEntry(_T("More Properties ..."), _T("Property 26 String"),
                                         AcOPMPROP_FirstUserProp + 25, opmTypeString));

    // Callback property
    AcOPMPropertyEntry property7(_T("More Properties ..."), _T("Property 26 Callback"), AcOPMPROP_FirstUserProp + 26, opmTypeCallback);
    property7.m_callbackFunc = clientCallbackFunction;
    properties.append(property7);

    // enum
    properties.append(AcOPMPropertyEntry(_T("More Properties ..."), _T("Property 27 Enum"),
                                         AcOPMPROP_FirstUserProp + 27, opmTypeEnum, false, m_enumPredefined27));

    // Per-Instance properties
    properties.append(AcOPMPropertyEntry(_T("PIP"), _T("PIP String"),
                                         AcOPMPROP_FirstUserProp + 100, opmTypeString, true));

    properties.append(AcOPMPropertyEntry(_T("PIP"), _T("PIP Distance"),
                                         AcOPMPROP_FirstUserProp + 101, opmTypeDistance, true));

    return true;
}

// dynamic PerInstance properties
bool CMyOPMClientExtension::supportsDynamicProperties() const
{
     return true;
}
bool CMyOPMClientExtension::getDynamicPropertyMap(const AcDbEntity* entity, AcOPMPropertyArray& properties) const
{
    if (entity == NULL)  // should never happen
        return false;

    const AcRxClass* entClass = entity->isA();
    if (entClass->isDerivedFrom(AcDbLine::desc()))
    {
        static bool s_lineFlag = true; // to mimic multiple lines, with different dynamic properties
        properties.append(AcOPMPropertyEntry(_T("Dynamic Properties Line"), _T("dynamic PIP Double"),
                                             AcOPMPROP_FirstUserProp + 150, opmTypeDouble));

        properties.append(AcOPMPropertyEntry(_T("Dynamic Properties Line"), _T("dynamic PIP String"),
                                             AcOPMPROP_FirstUserProp + 151, opmTypeString));

        if (s_lineFlag)
            properties.append(AcOPMPropertyEntry(_T("Dynamic Properties Line"), _T("dynamic PIP Integer"),
                                                 AcOPMPROP_FirstUserProp + 152, opmTypeInteger));
        s_lineFlag = !s_lineFlag;
        return true;
    }
    else
    if (entClass->isDerivedFrom(AcDbCircle::desc()))
    {
        static bool s_circleFlag = true; // to mimic multiple circles, with different dynamic properties
        properties.append(AcOPMPropertyEntry(_T("Dynamic Properties Circle"), _T("dynamic PIP Double"),
                                             AcOPMPROP_FirstUserProp + 160, opmTypeDouble));

        properties.append(AcOPMPropertyEntry(_T("Dynamic Properties Circle"), _T("dynamic PIP String"),
                                             AcOPMPROP_FirstUserProp + 161, opmTypeString));

        if (s_circleFlag)
            properties.append(AcOPMPropertyEntry(_T("Dynamic Properties Circle"), _T("dynamic PIP Integer"),
                                                 AcOPMPROP_FirstUserProp + 162, opmTypeInteger));
        s_circleFlag = !s_circleFlag;
        return true;
    }

    // other entity type
    properties.append(AcOPMPropertyEntry(_T("Dynamic Properties Entity"), _T("dynamic PIP Double"),
                                         AcOPMPROP_FirstUserProp + 170, opmTypeDouble));

    return true;
}

// fill the properties array for NoSelection mode
bool CMyOPMClientExtension::getPropertyMap(AcOPMPropertyArray& properties) const
{
    properties.append(AcOPMPropertyEntry(_T("App Settings"), _T("App Setting 1"),
                                         AcOPMPROP_FirstUserProp + 201, opmTypeString));

    properties.append(AcOPMPropertyEntry(_T("App Settings"), _T("App Setting 2"),
                                         AcOPMPROP_FirstUserProp + 202, opmTypeDistance));

    properties.append(AcOPMPropertyEntry(_T("Doc Settings"), _T("Doc Setting 1"),
                                         AcOPMPROP_FirstUserProp + 203, opmTypeCheckBox));

    // parentString + subString
    AcOPMPropertyEntry property1(_T("Doc Settings"), _T("Doc Setting 2"),
                                 AcOPMPROP_FirstUserProp + 204, opmTypeInteger);
    property1.m_childNames.append(_T("SubSetting A")); property1.m_childTypes.append(opmTypeString);
    property1.m_childNames.append(_T("SubSetting B")); property1.m_childTypes.append(opmTypeInteger);

    properties.append(property1);

    return true;
}

#if __BRXTARGET >= 16
bool CMyOPMClientExtension::getNativePropertiesToDisable(AcOPMNativePropertyArray& disableNativeProps) const
{
    disableNativeProps.append(acOpmId_Color);
    disableNativeProps.append(acOpmId_Layer);
    return true;
}
#endif // __BRXTARGET

bool CMyOPMClientExtension::getObjectName(const AcDbEntity* entity, AcString& name, const AcOpmSubEntityType subentType) const
{
    if ((entity != NULL) && (entity->isA() == CMyEntity::desc()))
    {
        //name = CMyEntity::desc()->name();
        name = s_guiEntityName;
        return true;
    }
    return false;
}

#if __BRXTARGET >= 20  // since V20.2
bool CMyOPMClientExtension::getObjectName(const AcDbEntity* entity, const AcDbFullSubentPath& subEntPath, AcString& name) const
{
    if ((entity != NULL) && (entity->isA() == CMyEntity::desc()))
    {
        //name = CMyEntity::desc()->name();
        name = s_guiEntityName;
        return true;
    }
    return false;
}
#endif // __BRXTARGET

bool CMyOPMClientExtension::getCategoryName(AcOPMCategoryId category, AcString& name) const
{
    return false;
}

bool CMyOPMClientExtension::getCategoryName(const AcString& category, AcString& name) const
{
    // PerInstance properties
    if (category == _T("PIP"))
    {
        name = _T("Per Instance Properties");
        return true;
    }

    // NoSelection properties
    if (category == _T("App Settings"))
    {
        name = _T("Application Settings");
        return true;
    }
    if (category == _T("Doc Settings"))
    {
        name = _T("Document Settings");
        return true;
    }

    return false;
}

bool CMyOPMClientExtension::getPropertyName(const AcDbEntity* entity,
                                            AcOPMPropertyId propertyId,
                                            const AcString& childName,
                                            AcString& name) const
{
    switch (propertyId)
    {
        case AcOPMPROP_FirstUserProp + 23 :
             {
                 if (childName.isEmpty())
                 {
                     name = _T("Property 23 Main String");
                     return true;
                 }
                 if (childName == _T("Child String A"))
                 {
                     name = _T("Child A");
                     return true;
                 }
                 if (childName == _T("Child String B"))
                 {
                     name = _T("Child B");
                     return true;
                 }
             }
             return false;
    }
    return false;
}

bool CMyOPMClientExtension::getPropertyDescription(const AcDbEntity* entity,
                                                   AcOPMPropertyId propertyId,
                                                   const AcString& childName,
                                                   AcString& description) const
{
    // normal entity properties + PerInstance properties
    switch (propertyId)
    {
        case AcOPMPROP_FirstUserProp :      // opmTypeBool
             description = _T("a boolean value");
             return true;
        case AcOPMPROP_FirstUserProp + 1 :  // opmTypeCheckBox
             description = _T("  use Details");
             return true;
        case AcOPMPROP_FirstUserProp + 2 :  // opmTypeInteger
             description = _T("an integer value");
             return true;
        case AcOPMPROP_FirstUserProp + 3 :  // opmTypeString + predefinedStrings
             description = _T("a dropdown list");
             return true;
        case AcOPMPROP_FirstUserProp + 4 :  // opmTypeAngle
             description = _T("an angle value");
             return true;
        case AcOPMPROP_FirstUserProp + 5 :  // opmTypeColor
             {
                 if (childName.isEmpty())
                 {
                     description = _T("a color value");
                     return true;
                 }
                 if (childName == _T("String")) // opmTypeString
                 {
                     description = _T("a string value");
                     return true;
                 }
                 if (childName == _T("Pnt 2d")) // opmTypePoint2d
                 {
                     description = _T("a Point2d value");
                     return true;
                 }
                 if (childName == _T("Pnt 3d")) // opmTypePoint3d
                 {
                     description = _T("a Point3d value");
                     return true;
                 }
                 if (childName == _T("Pnt 2d Ucs")) // opmTypePoint2dUcs
                 {
                     description = _T("a Point2d Ucs value");
                     return true;
                 }
                 if (childName == _T("Pnt 3d Ucs")) // opmTypePoint3dUcs
                 {
                     description = _T("a Point3d Ucs value");
                     return true;
                 }
                 if (childName == _T("Layer")) // opmTypeLayer
                 {
                     description = _T("a Layer value");
                     return true;
                 }
                 if (childName == _T("Block")) // opmTypeBlock
                 {
                     description = _T("a Block value");
                     return true;
                 }
                 if (childName == _T("Ucs")) // opmTypeUcs
                 {
                     description = _T("an Ucs value");
                     return true;
                 }
                 if (childName == _T("View")) // opmTypeView
                 {
                     description = _T("a View value");
                     return true;
                 }
                 if (childName == _T("Linetype")) // opmTypeLinetype
                 {
                     description = _T("a Linetype value");
                     return true;
                 }
                 if (childName == _T("Lineweight")) // opmTypeLineweight
                 {
                     description = _T("a Lineweight value");
                     return true;
                 }
                 if (childName == _T("ArrowHead")) // opmTypeArrowhead
                 {
                     description = _T("an ArrowHead value");
                     return true;
                 }
                 if (childName == _T("Folder")) // opmTypeFolder
                 {
                     description = _T("a Folder value");
                     return true;
                 }
                 if (childName == _T("File")) // opmTypeFile
                 {
                     description = _T("a File value");
                     return true;
                 }
                 return false;
             }

        case AcOPMPROP_FirstUserProp + 6 :  // opmTypeVector2d
             description = _T("a Vector2d value");
             return true;
        case AcOPMPROP_FirstUserProp + 7 :  // opmTypeVector3d
             description = _T("a Vector3d value");
             return true;
        case AcOPMPROP_FirstUserProp + 8 :  // opmTypeVector2dUcs
             description = _T("a Vector2d Ucs value");
             return true;
        case AcOPMPROP_FirstUserProp + 9 :  // opmTypeVector3dUcs
             description = _T("a Vector3d Ucs value");
             return true;
        case AcOPMPROP_FirstUserProp + 10 :  // opmTypeRange
             description = _T("a Range value");
             return true;
        case AcOPMPROP_FirstUserProp + 11 :  // opmTypeTextstyle
             description = _T("a Textstyle value");
             return true;
        case AcOPMPROP_FirstUserProp + 12 :  // opmTypeDimstyle
             description = _T("a Dimensionstyle value");
             return true;
        case AcOPMPROP_FirstUserProp + 13 :  // opmTypeTablestyle
             description = _T("a Tablestyle value");
             return true;
        case AcOPMPROP_FirstUserProp + 14 :  // opmTypeMlinestyle
             description = _T("a MLinestyle value");
             return true;
        case AcOPMPROP_FirstUserProp + 15 :  // opmTypeMleaderstyle
             description = _T("a MLeaderstyle value");
             return true;
        case AcOPMPROP_FirstUserProp + 16 :  // opmTypeMaterial
             description = _T("a Material value");
             return true;
        case AcOPMPROP_FirstUserProp + 17 :  // opmTypeLayout
             description = _T("a Layout value");
             return true;
        case AcOPMPROP_FirstUserProp + 18 :  // opmTypePlotStyleName
             description = _T("a Plotstyle value");
             return true;
        case AcOPMPROP_FirstUserProp + 19 :  // opmTypeGradientName
             description = _T("a Gradient value");
             return true;
        case AcOPMPROP_FirstUserProp + 20 :  // opmTypePatternType
        case AcOPMPROP_FirstUserProp + 21 :  // opmTypePatternName
             description = _T("a HatchPattern / HatchType nvalue");
             return true;
        case AcOPMPROP_FirstUserProp + 22 :  // opmTypeAnnotativeScale
             description = _T("an AnnotationScale value");
             return true;

        // parent + child strings
        case AcOPMPROP_FirstUserProp + 23 :  // opmTypeString
             {
                 if (childName.isEmpty())
                 {
                     description = _T("a Parent string value");
                     return true;
                 }
                 if (childName == _T("Child String A")) // opmTypeString
                 {
                     description = _T("a Child string value");
                     return true;
                 }
                 if (childName == _T("Child String B")) // opmTypeString
                 {
                     description = _T("a Child string value");
                     return true;
                 }
             }
             return false;

        case AcOPMPROP_FirstUserProp + 24 :  // eTypeCombo + predefinedStrings
             description = _T("a dropdown list with edit field");
             return true;
        case AcOPMPROP_FirstUserProp + 25 :  // eTypeString
             description = _T("simple string");
             return true;
        case AcOPMPROP_FirstUserProp + 26 :  // eTypeCombo
             description = _T("client callback");
             return true;
        case AcOPMPROP_FirstUserProp + 27 :  // eTypeEnum + predefinedStrings
             {
                 // test AcOPMUtilities::getActiveOPMPropertyEntry()
                 bool res = true;
                 description = _T("a dropdown list");
                 // V16 NEXT_BREAKING_CHANGE
                 //AcOPMPropertyEntry activeOPMEntry;
                 //res = acOPMExtensionManager()->getActiveOPMPropertyEntry(activeOPMEntry);
                 return res;
             }

        // Per-Instance properties
        case AcOPMPROP_FirstUserProp + 100 : // opmTypeString
             description = _T("a PerInstance string value");
             return true;
        case AcOPMPROP_FirstUserProp + 101 : // opmTypeDistance
             description = _T("a PerInstance distance (double) value");
             return true;
    }

    // NoSelection properties
    switch (propertyId)
    {
    case AcOPMPROP_FirstUserProp + 201 : // opmTypeString
         description = _T("a NoSelection string value");
         return true;
    case AcOPMPROP_FirstUserProp + 202 : // opmTypeDistance
         description = _T("a NoSelection distance value");
         return true;
    case AcOPMPROP_FirstUserProp + 203 : // opmTypeCheckBox
         description = _T("a NoSelection CheckBox value");
         return true;
    case AcOPMPROP_FirstUserProp + 204 : // opmTypeInteger
         if (childName.isEmpty())
         {
             description = _T("a NoSelection Parent integer value");
             return true;
         }
         if (childName == _T("SubSetting A")) // opmTypeString
         {
             description = _T("a NoSelection Child string value");
             return true;
         }
         if (childName == _T("SubSetting B")) // opmTypeInteger
         {
             description = _T("a NoSelection Child integer value");
             return true;
         }
         return false;
    }

    return false;
}

bool CMyOPMClientExtension::getPropertyEnabled(const AcDbEntity* entity,
                                               AcOPMPropertyId propertyId,
                                               const AcString& childName,
                                               bool& enabled, bool& hideDisabled) const
{
    // testing : for Per-Instance Properties, mimic different entities by the switch
    static bool switchPerEntity = false;

    if (propertyId == (AcOPMPROP_FirstUserProp + 101)) // "PIP Distance"
    {
        switchPerEntity = !switchPerEntity;
        enabled = switchPerEntity;
        hideDisabled = true;
        return true;
    }

    // for testing Enabled/HideDisabled - works
    switch (propertyId)
    {
        case AcOPMPROP_FirstUserProp + 6 : // opmTypeVector2d
             enabled = false;
             hideDisabled = false; //true;
             return true;
        case AcOPMPROP_FirstUserProp + 7 : // opmTypeVector3d
             enabled = false;
             hideDisabled = false;
             return true;
    }

    return false;
}

bool CMyOPMClientExtension::getPropertyReadOnly(const AcDbEntity* entity,
                                                AcOPMPropertyId propertyId,
                                                const AcString& childName,
                                                bool& readOnly) const
{
    if (propertyId == (AcOPMPROP_FirstUserProp + 8)) // opmTypeVector2dUcs
    {
        readOnly = true;
        return true;
    }

    // parent + child strings
    if (propertyId == (AcOPMPROP_FirstUserProp + 23)) // opmTypeString
    {
        if (childName.isEmpty())
            readOnly = true;
        else
            readOnly = false;
        return true;
    }

    if (propertyId == (AcOPMPROP_FirstUserProp + 203)) // opmTypeCheckBox
    {
        readOnly = true;
        return true;
    }

    return false;
}

bool CMyOPMClientExtension::getPredefinedStrings(const AcDbEntity* entity,
                                                 AcOPMPropertyId propertyId,
                                                 const AcString& childName,
                                                 AcStringArray& predefinedStrings) const
{
    static bool s_useShortList_27 = false;

    switch (propertyId)
    {
        case AcOPMPROP_FirstUserProp + 24 :  // eTypeCombo + predefinedStrings
             predefinedStrings = m_comboPredefined24;
             return true;

        case AcOPMPROP_FirstUserProp + 27 :  // eTypeEnum + predefinedStrings
             predefinedStrings = m_enumPredefined27;
             // to mimic different values per entity
             // predefinedStrings = s_useShortList_27 ? m_enumPredefined27     //   1,2,3
             //                                       : m_enumPredefined27_2;  // 0,1,2,3,4
             s_useShortList_27 = !s_useShortList_27;
             return true;

    }
    return false;
}

bool CMyOPMClientExtension::getPropertyValue(const AcDbEntity* entity, AcOPMPropertyId propertyId,
                                             const AcString& childName, AcOPMVariant& value) const
{
    static bool s_flagProp24 = true;  // to mimic different values for different entities
    static bool s_flagProp27 = true;  // to mimic different values for different entities

        // normal entity properties + PerInstance properties
    switch (propertyId)
    {
        case AcOPMPROP_FirstUserProp :      // opmTypeBool
             value = m_bool0;
             return true;
        case AcOPMPROP_FirstUserProp + 1 :  // opmTypeCheckBox
             value = m_checkBox1;
             return true;
        case AcOPMPROP_FirstUserProp + 2 :  // opmTypeInteger
             value = m_integer2;
             return true;
        case AcOPMPROP_FirstUserProp + 3 :  // opmTypeString + predefinedStrings
             value = m_comboStr3;
             return true;
        case AcOPMPROP_FirstUserProp + 4 :  // opmTypeAngle
             value = m_double4;
             return true;
        case AcOPMPROP_FirstUserProp + 5 :  // opmTypeColor
             {
                 if (childName.isEmpty())
                 {
                     value = m_color5;
                     return true;
                 }
                 if (childName == _T("String")) // opmTypeString
                 {
                     value = m_sub5idx0;
                     return true;
                 }
                 if (childName == _T("Pnt 2d")) // opmTypePoint2d
                 {
                     value = m_sub5idx1;
                     return true;
                 }
                 if (childName == _T("Pnt 3d")) // opmTypePoint3d
                 {
                     value = m_sub5idx2;
                     return true;
                 }
                 if (childName == _T("Pnt 2d Ucs")) // opmTypePoint2dUcs
                 {
                     value = m_sub5idx3;
                     return true;
                 }
                 if (childName == _T("Pnt 3d Ucs")) // opmTypePoint3dUcs
                 {
                     value = m_sub5idx4;
                     return true;
                 }
                 if (childName == _T("Layer")) // opmTypeLayer
                 {
                     value = m_sub5idx5;
                     return true;
                 }
                 if (childName == _T("Block")) // opmTypeBlock
                 {
                     value = m_sub5idx6;
                     return true;
                 }
                 if (childName == _T("Ucs")) // opmTypeUcs
                 {
                     value = m_sub5idx7;
                     return true;
                 }
                 if (childName == _T("View")) // opmTypeView
                 {
                     value = m_sub5idx8;
                     return true;
                 }
                 if (childName == _T("Linetype")) // opmTypeLinetype
                 {
                     value = m_sub5idx9;
                     return true;
                 }
                 if (childName == _T("Lineweight")) // opmTypeLineweight
                 {
                     value = m_sub5idx10;
                     return true;
                 }
                 if (childName == _T("ArrowHead")) // opmTypeArrowhead
                 {
                     value = m_sub5idx11;
                     return true;
                 }
                 if (childName == _T("Folder")) // opmTypeFolder
                 {
                     value = m_sub5idx12;
                     return true;
                 }
                 if (childName == _T("File")) // opmTypeFile
                 {
                     value = m_sub5idx13;
                     return true;
                 }
                 return false;
             }

        case AcOPMPROP_FirstUserProp + 6 :  // opmTypeVector2d
             value = m_vec2d;
             return true;
        case AcOPMPROP_FirstUserProp + 7 :  // opmTypeVector3d
             value = m_vec3d;
             return true;
        case AcOPMPROP_FirstUserProp + 8 :  // opmTypeVector2dUcs
             value = m_vec2dUcs;
             return true;
        case AcOPMPROP_FirstUserProp + 9 :  // opmTypeVector3dUcs
             value = m_vec3dUcs;
             return true;
        case AcOPMPROP_FirstUserProp + 10 :  // opmTypeRange
             {
                 // INT64 : first 16 bit (short)minValue, next 16 bit (short)minValue, next 16 bit (short)value
                 unsigned short minVal = (unsigned short)-10;
                 unsigned short maxVal = (unsigned short)30;
                 unsigned short curVal = (unsigned short)m_range;
                 INT64 minVal64 = minVal;
                 INT64 maxVal64 = (INT64)((UINT64)maxVal << 16);
                 INT64 curVal64 = (INT64)((UINT64)curVal << 32);
                 m_range = minVal64 | maxVal64 | curVal64;
                 value = m_range;
             }
             return true;
        case AcOPMPROP_FirstUserProp + 11 :  // opmTypeTextstyle
             value = m_textstyle;
             return true;
        case AcOPMPROP_FirstUserProp + 12 :  // opmTypeDimstyle
             value = m_dimstyle;
             return true;
        case AcOPMPROP_FirstUserProp + 13 :  // opmTypeTablestyle
             value = m_tablestyle;
             return true;
        case AcOPMPROP_FirstUserProp + 14 :  // opmTypeMlinestyle
             value = m_mlstyle;
             return true;
        case AcOPMPROP_FirstUserProp + 15 :  // opmTypeMleaderstyle
             value = m_mleaderstyle;
             return true;
        case AcOPMPROP_FirstUserProp + 16 :  // opmTypeMaterial
             value = m_material;
             return true;
        case AcOPMPROP_FirstUserProp + 17 :  // opmTypeLayout
             value = m_layout;
             return true;
        case AcOPMPROP_FirstUserProp + 18 :  // opmTypePlotStyleName
             value = m_plotstyle;
             return true;
        case AcOPMPROP_FirstUserProp + 19 :  // opmTypeGradientName
             value = m_gradient;
             return true;
        case AcOPMPROP_FirstUserProp + 20 :  // opmTypePatternType
        case AcOPMPROP_FirstUserProp + 21 :  // opmTypePatternName
             value = m_pattern;
             return true;
        case AcOPMPROP_FirstUserProp + 22 :  // opmTypeAnnotativeScale
             value = m_annoscale;
             return true;

        // parent + child strings
        case AcOPMPROP_FirstUserProp + 23 :  // opmTypeString
             {
                 if (childName.isEmpty())
                 {
                     m_parentStr23 = m_childStr23a;
                     m_parentStr23 += _T(" + ");
                     m_parentStr23 += m_childStr23b;
                     value = m_parentStr23;
                     return true;
                 }
                 if (childName == _T("Child String A")) // opmTypeString
                 {
                     value = m_childStr23a;
                     return true;
                 }
                 if (childName == _T("Child String B")) // opmTypeString
                 {
                     value = m_childStr23b;
                     return true;
                 }
             }
             return false;

        case AcOPMPROP_FirstUserProp + 24 :  // eTypeCombo + predefinedStrings
             value = m_comboStr24;
             // to mimic different values per entity
             // value = s_flagProp24 ? m_comboPredefined24[0] : m_comboPredefined24[1];
             s_flagProp24 = !s_flagProp24;
             return true;
        case AcOPMPROP_FirstUserProp + 25 :  // eTypeString
             value = m_string25;
             return true;
        case AcOPMPROP_FirstUserProp + 26 :  // eTypeCombo
             value = m_string26;
             return true;
        case AcOPMPROP_FirstUserProp + 27 :  // eTypeEnum + predefinedStrings
             value = m_enumStr27;
             // to mimic different values per entity
             // value = s_flagProp27 ? m_enumPredefined27[0] : m_enumPredefined27[1];
             s_flagProp27 = !s_flagProp27;
             return true;

        // Per-Instance properties
        case AcOPMPROP_FirstUserProp + 100 : // opmTypeString
             value = m_pipString;
             return true;
        case AcOPMPROP_FirstUserProp + 101 : // opmTypeDistance
             value = m_pipDouble;
             return true;

        // dynamic Per-Instance properties
        case AcOPMPROP_FirstUserProp + 150 : // eTypeDouble
             value = m_dynPipDouble1;
             return true;
        case AcOPMPROP_FirstUserProp + 151 : // eTypeString
             value = m_dynPipString1;
             return true;
        case AcOPMPROP_FirstUserProp + 152 : // eTypeInteger
             value = m_dynPipInteger1;
             return true;

        case AcOPMPROP_FirstUserProp + 160 : // eTypeDouble
             value = m_dynPipDouble2;
             return true;
        case AcOPMPROP_FirstUserProp + 161 : // eTypeString
             value = m_dynPipString2;
             return true;
        case AcOPMPROP_FirstUserProp + 162 : // eTypeInteger
             value = m_dynPipInteger2;
             return true;

        case AcOPMPROP_FirstUserProp + 170 : // eTypeDouble
             value = m_dynPipDouble3;
             return true;
    }

    // NoSelection properties
    static int s_counter = 0;  // for testring purpose
    switch (propertyId)
    {
    case AcOPMPROP_FirstUserProp + 201 : // opmTypeString
         value = m_appSettings1;
         {
             AcString tmp;
             tmp.format(_T("%ls : %d"), m_appSettings1.kwszPtr(), s_counter);
             value = tmp;
             ++s_counter;
         }
         return true;
    case AcOPMPROP_FirstUserProp + 202 : // opmTypeDouble
         value = m_appSettings2;
         return true;
    case AcOPMPROP_FirstUserProp + 203 : // opmTypeCheckBox
         value = m_docSettings1;
         return true;
    case AcOPMPROP_FirstUserProp + 204 : // opmTypeInteger
         if (childName.isEmpty())
         {
             value = m_docSettings2;
             return true;
         }
         if (childName == _T("SubSetting A")) // opmTypeString
         {
             value = m_docSettings2a;
             return true;
         }
         if (childName == _T("SubSetting B")) // opmTypeInteger
         {
             value = m_docSettings2b;
             return true;
         }
         return false;
    }

    return false;
}

#if __BRXTARGET >= 20  // since V20.2
bool CMyOPMClientExtension::getPropertyValue(const AcDbEntity* entity, const AcDbFullSubentPath& subEntPath,
                                             const AcOPMPropertyId propertyId, const AcString& childName,
                                             AcOPMVariant& value) const
{
    return false;
};
#endif // __BRXTARGET

bool CMyOPMClientExtension::setPropertyValue(AcDbEntity* entity,
                                             AcOPMPropertyId propertyId, 
                                             const AcString& childName,
                                             const AcOPMVariant& value)
{
    // normal entity properties + PerInstance properties
    switch (propertyId)
    {
        case AcOPMPROP_FirstUserProp :      // opmTypeBool
             return value.get(m_bool0);
        case AcOPMPROP_FirstUserProp + 1 :  // opmTypeCheckBox
             return value.get(m_checkBox1);
        case AcOPMPROP_FirstUserProp + 2 :  // opmTypeInteger
             return value.get(m_integer2);
        case AcOPMPROP_FirstUserProp + 3 :  // opmTypeString + predefinedStrings
             return value.get(m_comboStr3);
        case AcOPMPROP_FirstUserProp + 4 :  // opmTypeAngle
             return value.get(m_double4);
        case AcOPMPROP_FirstUserProp + 5 :  // opmTypeColor
             {
                 if (childName.isEmpty())
                 {
                     return value.get(m_color5);
                 }
                 if (childName == _T("String")) // opmTypeString
                 {
                     return value.get(m_sub5idx0);
                 }
                 if (childName == _T("Pnt 2d")) // opmTypePoint2d
                 {
                     return value.get(m_sub5idx1);
                 }
                 if (childName == _T("Pnt 3d")) // opmTypePoint3d
                 {
                     return value.get(m_sub5idx2);
                 }
                 if (childName == _T("Pnt 2d Ucs")) // opmTypePoint2dUcs
                 {
                     return value.get(m_sub5idx3);
                 }
                 if (childName == _T("Pnt 3d Ucs")) // opmTypePoint3dUcs
                 {
                     return value.get(m_sub5idx4);
                 }
                 if (childName == _T("Layer")) // opmTypeLayer
                 {
                     return value.get(m_sub5idx5);
                 }
                 if (childName == _T("Block")) // opmTypeBlock
                 {
                     return value.get(m_sub5idx6);
                 }
                 if (childName == _T("Ucs")) // opmTypeUcs
                 {
                     return value.get(m_sub5idx7);
                 }
                 if (childName == _T("View")) // opmTypeView
                 {
                     return value.get(m_sub5idx8);
                 }
                 if (childName == _T("Linetype")) // opmTypeLinetype
                 {
                     return value.get(m_sub5idx9);
                 }
                 if (childName == _T("Lineweight")) // opmTypeLineweight
                 {
                     return value.get(m_sub5idx10);
                 }
                 if (childName == _T("ArrowHead")) // opmTypeArrowhead
                 {
                     return value.get(m_sub5idx11);
                 }
                 if (childName == _T("Folder")) // opmTypeFolder
                 {
                     return value.get(m_sub5idx12);
                 }
                 if (childName == _T("File")) // opmTypeFile
                 {
                     return value.get(m_sub5idx13);
                 }
                 return false;
             }

        case AcOPMPROP_FirstUserProp + 6 :  // opmTypeVector2d
             return value.get(m_vec2d);
        case AcOPMPROP_FirstUserProp + 7 :  // opmTypeVector3d
             return value.get(m_vec3d);
        case AcOPMPROP_FirstUserProp + 8 :  // opmTypeVector2dUcs
             return value.get(m_vec2dUcs);
        case AcOPMPROP_FirstUserProp + 9 :  // opmTypeVector3dUcs
             return value.get(m_vec3dUcs);
        case AcOPMPROP_FirstUserProp + 10 :  // opmTypeRange
             return value.get(m_range);
        case AcOPMPROP_FirstUserProp + 11 :  // opmTypeTextstyle
             return value.get(m_textstyle);
        case AcOPMPROP_FirstUserProp + 12 :  // opmTypeDimstyle
             return value.get(m_dimstyle);
        case AcOPMPROP_FirstUserProp + 13 :  // opmTypeTablestyle
             return value.get(m_tablestyle);
        case AcOPMPROP_FirstUserProp + 14 :  // opmTypeMlinestyle
             return value.get(m_mlstyle);
        case AcOPMPROP_FirstUserProp + 15 :  // opmTypeMleaderstyle
             return value.get(m_mleaderstyle);
        case AcOPMPROP_FirstUserProp + 16 :  // opmTypeMaterial
             return value.get(m_material);
        case AcOPMPROP_FirstUserProp + 17 :  // opmTypeLayout
             return value.get(m_layout);
        case AcOPMPROP_FirstUserProp + 18 :  // opmTypePlotStyleName
             return value.get(m_plotstyle);
        case AcOPMPROP_FirstUserProp + 19 :  // opmTypeGradientName
             return value.get(m_gradient);
        case AcOPMPROP_FirstUserProp + 20 :  // opmTypePatternType
        case AcOPMPROP_FirstUserProp + 21 :  // opmTypePatternName
             return value.get(m_pattern);
        case AcOPMPROP_FirstUserProp + 22 :  // opmTypeAnnotativeScale
             return value.get(m_annoscale);

        // parent + child strings
        case AcOPMPROP_FirstUserProp + 23 :  // opmTypeString
             {
                 if (childName.isEmpty())
                 {
                     return value.get(m_parentStr23);
                 }
                 if (childName == _T("Child String A")) // opmTypeString
                 {
                     m_parentStr23  = m_childStr23a;
                     m_parentStr23 += _T(" + ");
                     m_parentStr23 += m_childStr23b;
                     return value.get(m_childStr23a);
                 }
                 if (childName == _T("Child String B")) // opmTypeString
                 {
                     m_parentStr23  = m_childStr23a;
                     m_parentStr23 += _T(" + ");
                     m_parentStr23 += m_childStr23b;
                     return value.get(m_childStr23b);
                 }
             }
             return false;

        case AcOPMPROP_FirstUserProp + 24 :  // eTypeCombo + predefinedStrings
             {
                 if (!value.get(m_comboStr24))
                     return false;
                 if (!m_comboPredefined24.contains(m_comboStr24))
                     m_comboPredefined24.append(m_comboStr24);
             }
             return true;
        case AcOPMPROP_FirstUserProp + 25 :  // eTypeString
             return value.get(m_string25);
        case AcOPMPROP_FirstUserProp + 26 :  // eTypeCallback
             return value.get(m_string26);
        case AcOPMPROP_FirstUserProp + 27 :  // eTypeEnum + predefinedStrings
             return value.get(m_enumStr27);

        // Per-Instance properties
        case AcOPMPROP_FirstUserProp + 100 : // opmTypeString
             return value.get(m_pipString);
        case AcOPMPROP_FirstUserProp + 101 : // opmTypeDistance
             return value.get(m_pipDouble);

        // dynamic Per-Instance properties
        case AcOPMPROP_FirstUserProp + 150 : // eTypeDouble
             return value.get(m_dynPipDouble1);
        case AcOPMPROP_FirstUserProp + 151 : // eTypeString
             return value.get(m_dynPipString1);
        case AcOPMPROP_FirstUserProp + 152 : // eTypeInteger
             return value.get(m_dynPipInteger1);

        case AcOPMPROP_FirstUserProp + 160 : // eTypeDouble
             return value.get(m_dynPipDouble2);
        case AcOPMPROP_FirstUserProp + 161 : // eTypeString
             return value.get(m_dynPipString2);
        case AcOPMPROP_FirstUserProp + 162 : // eTypeInteger
             return value.get(m_dynPipInteger2);

        case AcOPMPROP_FirstUserProp + 170 : // eTypeDouble
             return value.get(m_dynPipDouble3);

        // NoSelection properties
        case AcOPMPROP_FirstUserProp + 201 : // opmTypeString
             return value.get(m_appSettings1);
        case AcOPMPROP_FirstUserProp + 202 : // opmTypeDouble
             return value.get(m_appSettings2);
        case AcOPMPROP_FirstUserProp + 203 : // opmTypeCheckBox
             return value.get(m_docSettings1);
        case AcOPMPROP_FirstUserProp + 204 : // opmTypeInteger
             if (childName.isEmpty())
             {
                 return value.get(m_docSettings2);
             }
             if (childName == _T("SubSetting A")) // opmTypeString
             {
                 return value.get(m_docSettings2a);
             }
             if (childName == _T("SubSetting B")) // opmTypeInteger
             {
                 return value.get(m_docSettings2b);
             }
             return false;
    }

    return false;
}

#if __BRXTARGET >= 20  // since V20.2
bool CMyOPMClientExtension::setPropertyValue(AcDbEntity* entity, const AcDbFullSubentPath& subEntPath,
                                             const AcOPMPropertyId propertyId, const AcString& childName,
                                             const AcOPMVariant& value)
{
    return false;
};
#endif // __BRXTARGET

#if __BRXTARGET >= 22  // since V22
// this function is called to retrieve all possible entity names, specific for this AcOPMClientExtension;
bool CMyOPMClientExtension::allEntityNames(AcOPMEntityTypeNames& names) const
{
    names[s_guiEntityName] = s_guiEntityName;
    return true;
}
#endif // __BRXTARGET

// client Callback function
bool clientCallbackFunction(const AcDbObjectIdArray& pickSet,
                            AcOPMPropertyId propertyId, const AcString& propertyName,
                            const AcString& childName, AcOPMVariant& value)
{
    acedAlert(_T("*** client Callback reached"));

    TCHAR buffer[256];
    int	rt = acedGetString(1, _T("\n* Enter new string value : "), buffer);
    if (rt == RTNORM)
    {
        value = buffer;
    }
    return true;
}

#endif // BRX_APP
