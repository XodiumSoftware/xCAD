// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

// This is an example how to use the C++ OPM Extension API,
// a BricsCAD specific PropertiesPanel interface

#ifdef BRX_APP  // not available with ARX

#include "BrxSpecific/AcOpmExtensions.h"

class CMyOPMClientExtension : public AcOPMClientExtension
{
public:
    CMyOPMClientExtension();
    ~CMyOPMClientExtension();

public:

#if __BRXTARGET >= 17
    virtual bool getApplicationName(AcString& name) const;

    virtual void beginPropertiesUpdate(const AcDbObjectIdArray& selectionSet) const;
    virtual void endPropertiesUpdate() const;
#endif // __BRXTARGET

    // properties for "target entity type"
    virtual bool getPropertyMap(const AcRxClass* entityClass, AcOPMPropertyArray& properties) const;

    // dynamic PerInstance properties
    virtual bool supportsDynamicProperties() const;
    virtual bool getDynamicPropertyMap(const AcDbEntity* entity, AcOPMPropertyArray& properties) const;

    // properties for "NO SELECTION" mode
    virtual bool getPropertyMap(AcOPMPropertyArray& properties) const;

#if __BRXTARGET >= 16
    // to declare 'native' properties to be disabled (for entity types handled by this extension)
    bool getNativePropertiesToDisable(AcOPMNativePropertyArray& disableNativeProps) const;
#endif // __BRXTARGET

    virtual bool getObjectName(const AcDbEntity* entity, AcString& name, const AcOpmSubEntityType subentType = opmNullSubentType) const;

#if __BRXTARGET >= 20  // since V20.2
    virtual bool getObjectName(const AcDbEntity* entity, const AcDbFullSubentPath& subEntPath, AcString& name) const;
#endif // __BRXTARGET

    virtual bool getCategoryName(const AcString& category, AcString& name) const;
    virtual bool getCategoryName(AcOPMCategoryId category, AcString& name) const;

    virtual bool getPropertyName(const AcDbEntity* entity, AcOPMPropertyId propertyId,
                                 const AcString& childName, AcString& name) const;

    virtual bool getPropertyDescription(const AcDbEntity* entity, AcOPMPropertyId propertyId,
                                        const AcString& childName, AcString& description) const;

    virtual bool getPropertyEnabled(const AcDbEntity* entity, AcOPMPropertyId propertyId,
                                    const AcString& childName, bool& enabled, bool& hideDisabled) const;

    virtual bool getPropertyReadOnly(const AcDbEntity* entity, AcOPMPropertyId propertyId,
                                     const AcString& childName, bool& readOnly) const;

    virtual bool getPredefinedStrings(const AcDbEntity* entity, AcOPMPropertyId propertyId,
                                      const AcString& childName, AcStringArray& predefinedStrings) const;

    virtual bool getPropertyValue(const AcDbEntity* entity, AcOPMPropertyId propertyId,
                                  const AcString& childName, AcOPMVariant& value) const;

#if __BRXTARGET >= 20  // since V20.2
    virtual bool getPropertyValue(const AcDbEntity* entity, const AcDbFullSubentPath& subEntPath,
                                  const AcOPMPropertyId propertyId, const AcString& childName,
                                  AcOPMVariant& value) const;
#endif // __BRXTARGET

    virtual bool setPropertyValue(AcDbEntity* entity, AcOPMPropertyId propertyId,
                                  const AcString& childName, const AcOPMVariant& value);
#if __BRXTARGET >= 20  // since V20.2
    virtual bool setPropertyValue(AcDbEntity* entity, const AcDbFullSubentPath& subEntPath,
                                  const AcOPMPropertyId propertyId, const AcString& childName,
                                  const AcOPMVariant& value);
#endif // __BRXTARGET

#if __BRXTARGET >= 22  // since V22
    // this function is called to retrieve all possible entity names, specific for this AcOPMClientExtension;
    // return 'false' to indicate that the names mapping is not provided;
    virtual bool allEntityNames(AcOPMEntityTypeNames& names) const;
#endif // __BRXTARGET


private:
    // test data
    bool           m_bool0;        //_T("Test Property Bool"), AcOPMPROP_FirstUserProp, opmTypeBool);
    bool           m_checkBox1;    //_T("Property 1 CheckBox"), AcOPMPROP_FirstUserProp + 1, opmTypeCheckBox);

    int            m_integer2;     //property3.m_propertyId   = AcOPMPROP_FirstUserProp + 2 opmTypeInteger;
    AcString       m_comboStr3;    //(_T("Test Category"), _T("Property 3 Enum/Combo"), AcOPMPROP_FirstUserProp + 3, opmTypeString, false, predefinedStrings));
    double         m_double4;      //(_T("Extra Category"), _T("Property 4 Double"), AcOPMPROP_FirstUserProp + 4, opmTypeDouble));

    AcCmColor      m_color5;       //(_T("Extra Category"), _T("Property 5 Color + SubProps"), AcOPMPROP_FirstUserProp + 5, opmTypeColor);
    AcString       m_sub5idx0;     //    _T("String"));     property5.m_childTypes.push_back(opmTypeString);
    AcGePoint2d    m_sub5idx1;     //    _T("Pnt 2d"));     property5.m_childTypes.push_back(opmTypePoint2d);
    AcGePoint3d    m_sub5idx2;     //    _T("Pnt 3d"));     property5.m_childTypes.push_back(opmTypePoint3d);
    AcGePoint2d    m_sub5idx3;     //    _T("Pnt 2d Ucs")); property5.m_childTypes.push_back(opmTypePoint2dUcs);
    AcGePoint3d    m_sub5idx4;     //    _T("Pnt 3d Ucs")); property5.m_childTypes.push_back(opmTypePoint3dUcs);
    AcString       m_sub5idx5;     //    _T("Layer"));      property5.m_childTypes.push_back(opmTypeLayer);
    AcString       m_sub5idx6;     //    _T("Block"));      property5.m_childTypes.push_back(opmTypeBlock);
    AcString       m_sub5idx7;     //    _T("Ucs"));        property5.m_childTypes.push_back(opmTypeUcs);
    AcString       m_sub5idx8;     //    _T("View"));       property5.m_childTypes.push_back(opmTypeView);
    AcString       m_sub5idx9;     //    _T("Linetype"));   property5.m_childTypes.push_back(opmTypeLinetype);
    int            m_sub5idx10;    //    _T("Lineweight")); property5.m_childTypes.push_back(opmTypeLineweight);
    AcString       m_sub5idx11;    //    _T("ArrowHead"));  property5.m_childTypes.push_back(opmTypeArrowhead);
    AcString       m_sub5idx12;    //    _T("Folder"));     property5.m_childTypes.push_back(opmTypeFolder);
    AcString       m_sub5idx13;    //    _T("File"));       property5.m_childTypes.push_back(opmTypeFile);

    AcGeVector2d   m_vec2d;        //_T("More Properties ..."), _T("Property 6 Vec 2d"), AcOPMPROP_FirstUserProp + 6, opmTypeVector2d));
    AcGeVector3d   m_vec3d;        //_T("More Properties ..."), _T("Property 7 Vec 3d"), AcOPMPROP_FirstUserProp + 7, opmTypeVector3d));
    AcGeVector2d   m_vec2dUcs;     //_T("More Properties ..."), _T("Property 8 Vec 2d Ucs"), AcOPMPROP_FirstUserProp + 8, opmTypeVector2dUcs));
    AcGeVector3d   m_vec3dUcs;     //_T("More Properties ..."), _T("Property 9 Vec 3d Ucs"), AcOPMPROP_FirstUserProp + 9, opmTypeVector3dUcs));
    mutable INT64  m_range;        //_T("More Properties ..."), _T("Property 10 Range"), AcOPMPROP_FirstUserProp + 10, opmTypeRange));
    AcString       m_textstyle;    //_T("More Properties ..."), _T("Property 11 TextStyle"), AcOPMPROP_FirstUserProp + 11, opmTypeTextstyle));
    AcString       m_dimstyle;     //_T("More Properties ..."), _T("Property 12 DimStyle"), AcOPMPROP_FirstUserProp + 12, opmTypeDimstyle));
    AcString       m_tablestyle;   //_T("More Properties ..."), _T("Property 13 Tablestyle"), AcOPMPROP_FirstUserProp + 13, opmTypeTablestyle));
    AcString       m_mlstyle;      //_T("More Properties ..."), _T("Property 14 Mlinestyle"), AcOPMPROP_FirstUserProp + 14, opmTypeMlinestyle));
    AcString       m_mleaderstyle; //_T("More Properties ..."), _T("Property 15 Mleaderstyle"), AcOPMPROP_FirstUserProp + 15, opmTypeMleaderstyle));
    AcString       m_material;     //_T("More Properties ..."), _T("Property 16 Material"), AcOPMPROP_FirstUserProp + 16, opmTypeMaterial));
    AcString       m_layout;       //_T("More Properties ..."), _T("Property 17 Layout"), AcOPMPROP_FirstUserProp + 17, opmTypeLayout));
    AcString       m_plotstyle;    //_T("More Properties ..."), _T("Property 18 PlotStyleName"), AcOPMPROP_FirstUserProp + 18, opmTypePlotStyleName));
    AcString       m_gradient;     //_T("More Properties ..."), _T("Property 19 GradientName"), AcOPMPROP_FirstUserProp + 19, opmTypeGradientName));
    AcString       m_pattern;      //_T("More Properties ..."), _T("Property 20 PatternType"), AcOPMPROP_FirstUserProp + 20, opmTypePatternType));
                                   //_T("More Properties ..."), _T("Property 21 PatternName"), AcOPMPROP_FirstUserProp + 21, opmTypePatternName));
    AcString       m_annoscale;    //_T("More Properties ..."), _T("Property 22 AnnotativeScale"), AcOPMPROP_FirstUserProp + 22, opmTypeAnnotativeScale));

    // parent + child strings
    mutable AcString m_parentStr23;//_T("More Properties ..."), _T("Property 23 Parent + Child Strings"), AcOPMPROP_FirstUserProp + 23, opmTypeString);
    AcString       m_childStr23a;  //_T("Child String A")
    AcString       m_childStr23b;  //_T("Child String B")

    AcString       m_comboStr24;   //_T("More Properties ..."), _T("Property 24 Enum"), AcOPMPROP_FirstUserProp + 24, eTypeString);
    AcStringArray  m_comboPredefined24;

    AcString       m_string25;     //_T("More Properties ..."), _T("Property 25 String"), AcOPMPROP_FirstUserProp + 25, eTypeString);

    // Callback property
    AcString       m_string26;     //_T("More Properties ..."), _T("Property 26 Callback"), AcOPMPROP_FirstUserProp + 26, eTypeCallback);

    // enum combo
    AcString       m_enumStr27;    //_T("More Properties ..."), _T("Property 25 String"), AcOPMPROP_FirstUserProp + 27, eTypeString);
    AcStringArray  m_enumPredefined27;
    AcStringArray  m_enumPredefined27_2;

    // Per-Instance properties
    AcString       m_pipString;    //_T("PIP"), _T("PIP String"), AcOPMPROP_FirstUserProp + 100, opmTypeString, true));
    double         m_pipDouble;    //_T("PIP"), _T("PIP Double"), AcOPMPROP_FirstUserProp + 101, opmTypeDouble, true));

    // dynamic Per-Instance properties
    AcString       m_dynPipString1;
    double         m_dynPipDouble1;
    int            m_dynPipInteger1;

    AcString       m_dynPipString2;
    double         m_dynPipDouble2;
    int            m_dynPipInteger2;

    AcString       m_dynPipString3;
    double         m_dynPipDouble3;
    int            m_dynPipInteger3;

    // NoSelection properties
    AcString       m_appSettings1;  //_T("App Settings"), _T("App Setting 1"), AcOPMPROP_FirstUserProp + 201, opmTypeString));
    double         m_appSettings2;  //_T("App Settings"), _T("App Setting 2"), AcOPMPROP_FirstUserProp + 202, opmTypeDouble));
    bool           m_docSettings1;  //_T("Doc Settings"), _T("Doc Setting 1"), AcOPMPROP_FirstUserProp + 203, opmTypeCheckBox));
    int            m_docSettings2;  //_T("Doc Settings"), _T("Doc Setting 2"), AcOPMPROP_FirstUserProp + 204, opmTypeInteger);
    AcString       m_docSettings2a; //_T("SubSetting A")); property1.m_childTypes.push_back(opmTypeString);
    int            m_docSettings2b; //_T("SubSetting B")); property1.m_childTypes.push_back(opmTypeInteger);

};

class CMyOPMClientExtension2 : public AcOPMClientExtension
{
public:
    CMyOPMClientExtension2();
    ~CMyOPMClientExtension2();

public:

#if __BRXTARGET >= 17
    virtual bool getApplicationName(AcString& name) const;

    virtual void beginPropertiesUpdate(const AcDbObjectIdArray& selectionSet) const;
    virtual void endPropertiesUpdate() const;
#endif // __BRXTARGET

    // properties for "target entity type" ("main" entity)
    virtual bool getPropertyMap(const AcRxClass* entityClass,
                                AcOPMPropertyArray& properties) const;

    // supports dynamic properties for "target entity type" ?
    virtual bool supportsDynamicProperties() const;

    // dynamic properties for "target entity type" ("main" entity)
    virtual bool getDynamicPropertyMap(const AcDbEntity* entity,
                                       AcOPMPropertyArray& properties) const;

#if __BRXTARGET >= 17
    // properties for "target entity type" ("subentity" entity)
    virtual bool getPropertyMap(const AcRxClass* entityClass,
                                const AcOpmSubEntityType subentType,
                                AcOPMPropertyArray& properties) const;

    // dynamic properties for "target entity type" ("subentity" entity)
    virtual bool getDynamicPropertyMap(const AcDbEntity* entity,
                                       const AcOpmSubEntityType subentType,
                                       const AcDbFullSubentPathArray& fspArray,
                                       AcOPMPropertyArray& properties) const;
#endif // __BRXTARGET

    // properties for "NO SELECTION" mode

    // not necessary
    //virtual bool getPropertyMap(AcOPMPropertyArray& properties) const;

    // not necessary
    //virtual bool getNativePropertiesToDisable(AcOPMNativePropertyArray& disableNativeProps) const;

    // not necessary
    //virtual bool getObjectName(const AcDbEntity* entity, AcString& name) const;

    // not necessary
    //virtual bool getCategoryName(const AcString& category, AcString& name) const;
    // not necessary
    //virtual bool getCategoryName(AcOPMCategoryId category, AcString& name) const;

    // not necessary
    //virtual bool getPropertyName(const AcDbEntity* entity, AcOPMPropertyId propertyId,
    //                             const AcString& childName, AcString& name) const;

    // not necessary
    //virtual bool getPropertyDescription(const AcDbEntity* entity, AcOPMPropertyId propertyId,
    //                                    const AcString& childName, AcString& description) const;

    // not necessary
    //virtual bool getPropertyEnabled(const AcDbEntity* entity, AcOPMPropertyId propertyId,
    //                                const AcString& childName, bool& enabled, bool& hideDisabled) const;

    // not necessary
    //virtual bool getPropertyReadOnly(const AcDbEntity* entity, AcOPMPropertyId propertyId,
    //                                 const AcString& childName, bool& readOnly) const;

    // not necessary
    //virtual bool getPredefinedStrings(const AcDbEntity* entity, AcOPMPropertyId propertyId,
    //                                  const AcString& childName, AcStringArray& predefinedStrings) const;

    // get property value for "target entity type" ("main" entity)
    virtual bool getPropertyValue(const AcDbEntity* entity,
                                  AcOPMPropertyId propertyId,
                                  const AcString& childName,
                                  AcOPMVariant& value) const;

    // set property value for "target entity type" ("main" entity)
    virtual bool setPropertyValue(AcDbEntity* entity,
                                  AcOPMPropertyId propertyId,
                                  const AcString& childName,
                                  const AcOPMVariant& value);

#if __BRXTARGET >= 17
    // get property value for "target entity type" ("subentity" entity)
    virtual bool getPropertyValue(const AcDbEntity* entity,
                                  const AcOpmSubEntityType subentType,
                                  const AcDbFullSubentPathArray& fspArray,
                                  const AcOPMPropertyId propertyId,
                                  const AcString& childName,
                                  AcOPMVariant& value) const;

    // set property value for "target entity type" ("subentity" entity)
    virtual bool setPropertyValue(AcDbEntity* entity,
                                  const AcOpmSubEntityType subentType,
                                  const AcDbFullSubentPathArray& fspArray,
                                  const AcOPMPropertyId propertyId,
                                  const AcString& childName,
                                  const AcOPMVariant& value);
#endif // __BRXTARGET

#if __BRXTARGET >= 22  // since V22
    // this function is called to retrieve all possible entity names, specific for this AcOPMClientExtension;
    // return 'false' to indicate that the names mapping is not provided;
    virtual bool allEntityNames(AcOPMEntityTypeNames& names) const;
#endif // __BRXTARGET

private:
    // test data
    AcString       m_mainStr;
    AcString       m_mainDynStr;
    AcString       m_mainPipStr;

    int            m_intSubentVertex;
    int            m_intSubentEdge;
    int            m_intSubentFace;

    double         m_dblDynSubentVertex;
    double         m_dblDynSubentEdge;
    double         m_dblDynSubentFace;

    double         m_dblPipSubentVertex;
    double         m_dblPipSubentEdge;
    double         m_dblPipSubentFace;
};

#endif // BRX_APP

bool registerMyOPMExtension();    // dummy implemented for ARX build
bool unregisterMyOPMExtension();  // dummy implemented for ARX build
