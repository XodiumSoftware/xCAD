// Copyright (C) Menhirs NV. All rights reserved.

// AcOpmExtensions.h
// AcOPMVariant AcOPMPropertyEntry AcOPMExtensionManager AcOPMClientExtension interfaces

//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH

#pragma once

#include "Misc/MiscGlobal.h"
#include "Misc/AcString.h"
#include "AcCm/AcCmColor.h"
#include "AcDb/AcDbObjectId.h"
#include "AcDb/AcDbFullSubentPath.h"
#include "AcGe/AcGePoint2d.h"
#include "AcGe/AcGePoint3d.h"
#include "AcGe/AcGeVector2d.h"
#include "AcGe/AcGeVector3d.h"

#include "BrxSpecific/AcOpmNativePropertyIds.h" // IDs of OPM property entries for native entities

#include <map>

#ifdef _WIN32
#include <limits.h>
#include <OleAuto.h>
#include <atlcomcli.h>
#endif

class AcRxClass;
class AcDbEntity;
class AcOPMClientExtension;


typedef int AcOPMCategoryId;
typedef int AcOPMPropertyId;

// predefined category IDs:
// negative values are 'built-in' categories, positive are extension-specific
const AcOPMCategoryId AcOPMCAT_Nil                    =   -1;
const AcOPMCategoryId AcOPMCAT_Misc                   =   -2;  //("Misc")
const AcOPMCategoryId AcOPMCAT_Font                   =   -3;
const AcOPMCategoryId AcOPMCAT_Position               =   -4;
const AcOPMCategoryId AcOPMCAT_Appearance             =   -5;
const AcOPMCategoryId AcOPMCAT_Behavior               =   -6;
const AcOPMCategoryId AcOPMCAT_Data                   =   -7;
const AcOPMCategoryId AcOPMCAT_List                   =   -8;
const AcOPMCategoryId AcOPMCAT_Text                   =   -9;  //("Text")
const AcOPMCategoryId AcOPMCAT_Scale                  =  -10;
const AcOPMCategoryId AcOPMCAT_DDE                    =  -11;
const AcOPMCategoryId AcOPMCAT_General                =  -12;  //("General")
const AcOPMCategoryId AcOPMCAT_Mass                   =  -13;  //("Mass")
const AcOPMCategoryId AcOPMCAT_Pattern                =  -14;  //("Pattern")
const AcOPMCategoryId AcOPMCAT_DataPoints             =  -15;  //("Data Points")
const AcOPMCategoryId AcOPMCAT_Mesh                   =  -16;  //("Mesh")
const AcOPMCategoryId AcOPMCAT_ImageAdjust            =  -17;  //("Image Adjust")
const AcOPMCategoryId AcOPMCAT_ControlPoints          =  -18;
const AcOPMCategoryId AcOPMCAT_PrimaryUnits           =  -19;  //("Primary units")
const AcOPMCategoryId AcOPMCAT_AltUnits               =  -20;  //("Alternate units")
const AcOPMCategoryId AcOPMCAT_Fit                    =  -21;  //("Fit ")
const AcOPMCategoryId AcOPMCAT_LinesArrows            =  -22;  //("Lines & Arrows")
const AcOPMCategoryId AcOPMCAT_Tolerances             =  -23;  //("Tolerances")
const AcOPMCategoryId AcOPMCAT_Table                  =  -24;  //("Table")
const AcOPMCategoryId AcOPMCAT_Geometry               =  -25;  //("Geometry")
const AcOPMCategoryId AcOPMCAT_Section                =  -26;  //("Section Object")
const AcOPMCategoryId AcOPMCAT_UnderlayAdjust         =  -27;  //("Underlay Adjust")
const AcOPMCategoryId AcOPMCAT_Solid_History          =  -28;
const AcOPMCategoryId AcOPMCAT_Fillet                 =  -29;
const AcOPMCategoryId AcOPMCAT_Chamfer                =  -30;
const AcOPMCategoryId AcOPMCAT_3DVisualization        =  -31;
const AcOPMCategoryId AcOPMCAT_Table_Breaks           =  -32;
const AcOPMCategoryId AcOPMCAT_SURFACE_ASSOCIATIVITY  =  -33;
const AcOPMCategoryId AcOPMCAT_SURFACE_TRIM           =  -34;
const AcOPMCategoryId AcOPMCAT_ViewDefinition         =  -35;
const AcOPMCategoryId AcOPMCAT_Annotation             =  -36;
const AcOPMCategoryId AcOPMCAT_ReferenceData          =  -37;
const AcOPMCategoryId AcOPMCAT_Representation         =  -38;
const AcOPMCategoryId AcOPMCAT_PointcloudAdjust       =  -39;
const AcOPMCategoryId AcOPMCAT_GeomapImageAdjust      =  -40;

const AcOPMCategoryId AcOPMCAT_Attributes             = -100;  //("Attributes")
const AcOPMCategoryId AcOPMCAT_Light                  = -101;  //("Light")
const AcOPMCategoryId AcOPMCAT_PhotometricProperties  = -102;  //("Photometric Properties")
const AcOPMCategoryId AcOPMCAT_Attenuation            = -103;  //("Attenuation")
const AcOPMCategoryId AcOPMCAT_RenderedShadowDetails  = -104;  //("Rendered Shadow Details")
const AcOPMCategoryId AcOPMCAT_WebOffsets             = -105;  //("Web Offsets")
const AcOPMCategoryId AcOPMCAT_PhotometricWeb         = -106;  //("Photometric Web")
const AcOPMCategoryId AcOPMCAT_Custom                 = -107;  //("Custom")
const AcOPMCategoryId AcOPMCAT_Constraint             = -108;  //("Constraint")
const AcOPMCategoryId AcOPMCAT_Camera                 = -109;  //("Camera")
const AcOPMCategoryId AcOPMCAT_Clipping               = -110;  //("Clipping") for Camera entity
const AcOPMCategoryId AcOPMCAT_Boundary               = -111;  //("Boundary")
const AcOPMCategoryId AcOPMCAT_Leaders                = -112;
const AcOPMCategoryId AcOPMCAT_Block                  = -113;
const AcOPMCategoryId AcOPMCAT_Quantity               = -114;

// OPM extensions use negative (built-in) or positive Category IDs, starting from AcOPMCAT_FirstUserCat
const AcOPMCategoryId AcOPMCAT_FirstUserCat   = 1;

// OPM extensions use positive Property IDs, starting from AcOPMPROP_FirstUserProp
const AcOPMPropertyId AcOPMPROP_FirstUserProp = 1;


// data types for client properties
enum AcOpmDataType
{
    opmTypeNone            =  0,
    opmTypeInteger         =  1,  // INT64 (always 64 bit)
    opmTypeBool            =  2,  // bool
    opmTypeCheckBox        =  3,  // bool
    opmTypeDouble          =  4,  // double
    opmTypeAngle           =  5,  // double
    opmTypeDistance        =  6,  // double
    opmTypeArea            =  7,  // double
    opmTypeFactor          =  8,  // double
    opmTypeString          =  9,  // AcString/const wchar_t*
    opmTypeColor           = 10,  // AcCmColor
    opmTypeLineweight      = 11,  // Integer
    opmTypePoint2d         = 12,  // AcGePoint3d  (always World)
    opmTypePoint3d         = 13,  // AcGePoint3d  (always World)
    opmTypeVector2d        = 14,  // AcGeVector3d (always World)
    opmTypeVector3d        = 15,  // AcGeVector3d (always World)
    opmTypePoint2dUcs      = 16,  // AcGePoint3d  (will be transformed WCS->UCS)
    opmTypePoint3dUcs      = 17,  // AcGePoint3d  (will be transformed WCS->UCS)
    opmTypeVector2dUcs     = 18,  // AcGeVector3d (will be transformed WCS->UCS)
    opmTypeVector3dUcs     = 19,  // AcGeVector3d (will be transformed WCS->UCS)
    opmTypeRange           = 20,  // INT64 : first 16 bits - (short)minValue, next 16 bits - (short)maxValue, next 16 bits - (short)value
    opmTypeGradientName    = 21,  // AcString/const wchar_t*
    opmTypePatternType     = 22,  // AcString/const wchar_t* (prefixed by "U|" for userdefined, "P|" for predefined, "C|" for custon pattern type)
    opmTypePatternName     = 23,  // AcString/const wchar_t* (prefixed by "U|" for userdefined, "P|" for predefined, "C|" for custon pattern type)
    opmTypeAnnotativeScale = 24,  // AcString/const wchar_t*
    opmTypeVolume          = 25,  // double
    opmTypeExpression      = 26,  // AcString + AcString
    opmTypeQuantity        = 27,  // double + AcString
    opmTypeMass            = 28,  // double + AcString

    // referenced objects
    opmTypeObjectHandle    = 30,  // AcDbObjectId
    opmTypeLayer           = 31,  // AcString/const wchar_t*/AcDbObjectId
    opmTypeLinetype        = 32,  // AcString/const wchar_t*/AcDbObjectId
    opmTypeBlock           = 34,  // AcString/const wchar_t*/AcDbObjectId
    opmTypeView            = 35,  // AcString/const wchar_t*/AcDbObjectId
    opmTypeUcs             = 36,  // AcString/const wchar_t*/AcDbObjectId
    opmTypeTextstyle       = 37,  // AcString/const wchar_t*/AcDbObjectId
    opmTypeDimstyle        = 38,  // AcString/const wchar_t*/AcDbObjectId
    opmTypeTablestyle      = 39,  // AcString/const wchar_t*/AcDbObjectId
    opmTypeMlinestyle      = 40,  // AcString/const wchar_t*/AcDbObjectId
    opmTypeMleaderstyle    = 41,  // AcString/const wchar_t*/AcDbObjectId
    opmTypeMaterial        = 42,  // AcString/const wchar_t*/AcDbObjectId
    opmTypeLayout          = 43,  // AcString/const wchar_t*/AcDbObjectId
    opmTypePlotStyleName   = 44,  // AcString/const wchar_t*/AcDbObjectId
    opmTypeArrowhead       = 45,  // AcString/const wchar_t*/AcDbObjectId
    // misc
    opmTypeFile            = 50,  // AcString/const wchar_t*
    opmTypeFolder          = 51,  // AcString/const wchar_t*
    opmTypeCallback        = 52,  // AcString/const wchar_t*
    // array
    opmTypeEnum            = 60,  // OdString + INT64 (index to PredefinedStrings)
    opmTypeCombo           = 61,  // OdString + INT64 (index to PredefinedStrings)

    // extra to be combined with the above enum values
    opmFlagReloadPanelOnModify = 0x1000, // forces PropertiesPanel to reload all properties after 'this' property was edited
    opmFlagNoUserEdit          = 0x2000, // sets (only) the edit field of opmTypeCallback to read-only
    opmFlagGlobalRange         = 0x4000, // the range is a single global range index used for all entities (i.e. not per instance)
                                         // getPropertyValue() always returns (short)initialValue instead of the current (short)value
    //
    opmDataTypeMask        = 0x0FFF,
};

// error codes
enum AcOpmResult
{
    opmNoError = 0,
    opmEmptyProperties,
    opmNullPointer,
    opmCategoryNotSpecified,
    opmEmptyPropertyName,
    opmWrongObjectClass,
    opmDuplicatePropertyName,
    opmDuplicatePropertyId,
    opmDuplicateObjectClass,
    opmDuplicateRegistration,
    opmPropertyIdNotFound,
    opmPropertyIdOutOfRange,
    opmBuiltInCategoryNotFound,
    opmBuiltInCategoryNotAllowed,
    opmMismatchingArrays,
    opmUnknownError,
};

// since V17
enum AcOpmSubEntityType
{
    opmNullSubentType   = 0x00,
    opmFaceSubentType   = 0x01,
    opmEdgeSubentType   = 0x02,
    opmVertexSubentType = 0x04,
    opmClassSubentType  = 0x08,
};
// end V17

// a property editor callback function; will be used by the PropertiesPanel for properties
// with 'opmTypeCallback' type
class AcOPMVariant;
typedef bool (*AcOPMPropertyDialogProc)(const AcDbObjectIdArray& pickSet,
                                        AcOPMPropertyId propertyId, const AcString& propertyName,
                                        const AcString& childName, AcOPMVariant& value);


// the data item class
class AcOPMVariant
{
public:
    typedef enum
    {
        kVoid = 0,
        kBool,
        kInteger,
        kDouble,
        kString,
        kObjectId,
        kColor,
        kPoint,
        kVector,
        kCallback,
    } varType;

    AcOPMVariant() : m_type(kVoid) {};
    virtual ~AcOPMVariant() {};

    AcOPMVariant(const AcOPMVariant& other)
    {
        *this = other;
    };

    AcOPMVariant& operator= (const AcOPMVariant& other)
    {
        this->m_type = other.m_type;
        this->m_bool = other.m_bool;
        this->m_integer = other.m_integer;
        this->m_double = other.m_double;
        this->m_string = other.m_string;
        this->m_id = other.m_id;
        this->m_color = other.m_color;
        this->m_point = other.m_point;
        this->m_vector = other.m_vector;
        return *this;
    };

    const AcOPMVariant* operator->() const { return this; };
    AcOPMVariant*       operator->()       { return this; };
    operator AcOPMVariant*() { return this; };

    AcOPMVariant(const bool val)          { m_bool = val; m_type = kBool; };
    AcOPMVariant(const int val)           { m_integer = (INT64)val; m_type = kInteger; };
    AcOPMVariant(const unsigned int val)  { m_integer = (INT64)val; m_type = kInteger; };
    AcOPMVariant(const INT64 val)         { m_integer = val; m_type = kInteger; };
    AcOPMVariant(const UINT64 val)        { m_integer = (INT64)val; m_type = kInteger; };
    AcOPMVariant(const double val)        { m_double = val; m_type = kDouble; };
    AcOPMVariant(const char* val)         { m_string = val; m_type = kString; };
    AcOPMVariant(const wchar_t* val)      { m_string = val; m_type = kString; };
    AcOPMVariant(const AcString& val)     { m_string = val; m_type = kString; };
    AcOPMVariant(const AcDbObjectId& val) { m_id = val; m_type = kObjectId; };
    AcOPMVariant(const AcCmColor& val)    { m_color = val; m_type = kColor; };
    AcOPMVariant(const AcGePoint2d& val)  { m_point.x = val.x; m_point.y = val.y; m_point.z = 0; m_type = kPoint; };
    AcOPMVariant(const AcGePoint3d& val)  { m_point = val; m_type = kPoint; };
    AcOPMVariant(const AcGeVector2d& val) { m_vector.x = val.x; m_vector.y = val.y; m_vector.z = 0; m_type = kVector; };
    AcOPMVariant(const AcGeVector3d& val) { m_vector = val; m_type = kVector; };
    AcOPMVariant(const AcOPMPropertyDialogProc* val) { m_integer = (INT64)val; m_type = kCallback; };

    AcOPMVariant& set(const bool val)          { m_bool = val; m_type = kBool; return *this; };
    AcOPMVariant& set(const int val)           { m_integer = (INT64)val; m_type = kInteger; return *this; };
    AcOPMVariant& set(const unsigned int val)  { m_integer = (INT64)val; m_type = kInteger; return *this; };
    AcOPMVariant& set(const INT64 val)         { m_integer = val; m_type = kInteger; return *this; };
    AcOPMVariant& set(const UINT64 val)        { m_integer = (INT64)val; m_type = kInteger; return *this; };
    AcOPMVariant& set(const double val)        { m_double = val; m_type = kDouble; return *this; };
    AcOPMVariant& set(const char* val)         { m_string = val; m_type = kString; return *this; };
    AcOPMVariant& set(const wchar_t* val)      { m_string = val; m_type = kString; return *this; };
    AcOPMVariant& set(const AcString& val)     { m_string = val; m_type = kString; return *this; };
    AcOPMVariant& set(const AcDbObjectId& val) { m_id = val; m_type = kObjectId; return *this; };
    AcOPMVariant& set(const AcCmColor& val)    { m_color = val; m_type = kColor; return *this; };
    AcOPMVariant& set(const AcGePoint2d& val)  { m_point.x = val.x; m_point.y = val.y; m_point.z = 0; m_type = kPoint; return *this; };
    AcOPMVariant& set(const AcGePoint3d& val)  { m_point = val; m_type = kPoint; return *this; };
    AcOPMVariant& set(const AcGeVector2d& val) { m_vector.x = val.x; m_vector.y = val.y; m_vector.z = 0; m_type = kVector; return *this; };
    AcOPMVariant& set(const AcGeVector3d& val) { m_vector = val; m_type = kVector; return *this; };    
    AcOPMVariant& set(const AcOPMPropertyDialogProc* val) { m_integer = (INT64)val; m_type = kCallback; return *this; };

    bool get(bool& val)           const { if (m_type != kBool)     return false; val = m_bool; return true; };
    bool get(int& val)            const { if (m_type != kInteger)  return false; val = (int)m_integer; return true; };
    bool get(unsigned int& val)   const { if (m_type != kInteger)  return false; val = (unsigned int)m_integer; return true; };
    bool get(INT64& val)          const { if (m_type != kInteger)  return false; val = m_integer; return true; };
    bool get(UINT64& val)         const { if (m_type != kInteger)  return false; val = (UINT64)m_integer; return true; };
    bool get(double& val)         const { if (m_type != kDouble)   return false; val = m_double; return true; };
    bool get(const wchar_t*& val) const { if (m_type != kString)   return false; val = (const wchar_t*)m_string; return true; };
    bool get(AcString& val)       const { if (m_type != kString)   return false; val = m_string; return true; };
    bool get(AcDbObjectId& val)   const { if (m_type != kObjectId) return false; val = m_id; return true; };
    bool get(AcCmColor& val)      const { if (m_type != kColor)    return false; val = m_color; return true; };
    bool get(AcGePoint2d& val)    const { if (m_type != kPoint)    return false; val.x = m_point.x;  val.y = m_point.y; return true; };
    bool get(AcGePoint3d& val)    const { if (m_type != kPoint)    return false; val = m_point; return true; };
    bool get(AcGeVector2d& val)   const { if (m_type != kVector)   return false; val.x = m_vector.x; val.y = m_vector.y; return true; };
    bool get(AcGeVector3d& val)   const { if (m_type != kVector)   return false; val = m_vector; return true; };
    bool get(AcOPMPropertyDialogProc*& val) const{ if (m_type != kCallback) return false; val = (AcOPMPropertyDialogProc*)m_integer; return true; };

    AcOPMVariant& operator=(const bool val)          { m_bool = val; m_type = kBool; return *this; };
    AcOPMVariant& operator=(const int val)           { m_integer = (INT64)val; m_type = kInteger; return *this; };
    AcOPMVariant& operator=(const unsigned int val)  { m_integer = (INT64)val; m_type = kInteger; return *this; };
    AcOPMVariant& operator=(const INT64 val)         { m_integer = val; m_type = kInteger; return *this; };
    AcOPMVariant& operator=(const UINT64 val)        { m_integer = (INT64)val; m_type = kInteger; return *this; };
    AcOPMVariant& operator=(const double val)        { m_double = val; m_type = kDouble; return *this; };
    AcOPMVariant& operator=(const char* val)         { m_string = val; m_type = kString; return *this; };
    AcOPMVariant& operator=(const wchar_t* val)      { m_string = val; m_type = kString; return *this; };
    AcOPMVariant& operator=(const AcString& val)     { m_string = val; m_type = kString; return *this; };
    AcOPMVariant& operator=(const AcDbObjectId& val) { m_id = val; m_type = kObjectId; return *this; };
    AcOPMVariant& operator=(const AcCmColor& val)    { m_color = val; m_type = kColor; return *this; };
    AcOPMVariant& operator=(const AcGePoint2d& val)  { m_point.x = val.x; m_point.y = val.y; m_point.z = 0; m_type = kPoint; return *this; };
    AcOPMVariant& operator=(const AcGePoint3d& val)  { m_point = val; m_type = kPoint; return *this; };
    AcOPMVariant& operator=(const AcGeVector2d& val) { m_vector.x = val.x; m_vector.y = val.y; m_vector.z = 0; m_type = kVector; return *this; };
    AcOPMVariant& operator=(const AcGeVector3d& val) { m_vector = val; m_type = kVector; return *this; };    
    AcOPMVariant& operator=(const AcOPMPropertyDialogProc* val) { m_integer = (INT64)val; m_type = kCallback; return *this; };

    bool operator== (const AcOPMVariant& other) const
    {
        if (m_type != other.m_type) return false;
        switch (m_type)
        {
        case kBool :     return (m_bool == other.m_bool);
        case kInteger :
        case kCallback : return (m_integer == other.m_integer);
        case kDouble :   return (m_double == other.m_double);
        case kString :   return (m_string == other.m_string);
        case kObjectId : return (m_id == other.m_id);
        case kColor :    return (m_color == other.m_color);
        case kPoint :    return (m_point == other.m_point);
        case kVector :   return (m_vector == other.m_vector);
        case kVoid :     return false;
        }
        return false;
    };
    bool operator!= (const AcOPMVariant& other) const { return !(*this == other); };
    
    varType type() const { return m_type; };
    void    setType(varType type) { m_type = type; };

    bool initialised() const { return (m_type > kVoid); };
    void reset() { setType(kVoid); };

#ifdef _WIN32 // only for Windows platform
    // Converting COM variant to/from the BRX OpmVariant.
    // This allows to use one common variant type in client code related to COM and C++ OPM APIs.
    Acad::ErrorStatus setToCOM(VARIANT* pVarData) const
    {
        if (pVarData == NULL) return Acad::eInvalidInput;

        if (!initialised())
        {
            ::VariantInit(pVarData);
        }
        if (m_type == kBool)
        {
            *pVarData = CComVariant(m_bool);
        }
        else
        if (m_type == kInteger)
        {
            if ((m_integer >= INT_MIN) && (m_integer <= INT_MAX))
                *pVarData = CComVariant((int)m_integer);      // as 32-bit integer (VT_I4)
            else
                *pVarData = CComVariant((INT64)m_integer); // as 64-bit integer (VT_I8)
        }
        else
        if(m_type == kDouble)
        {
            *pVarData = CComVariant(m_double);
        }
        else
        if (m_type == kString)
        {
            *pVarData = CComVariant(m_string.constPtr());
        }
        else
        {
            return Acad::eInvalidInput;
        }
        return Acad::eOk;
    };
    Acad::ErrorStatus getFromCOM(const VARIANT* pVarData)
    {
        if (pVarData == NULL) return Acad::eInvalidInput;

        if ((pVarData->vt == VT_ERROR) || (pVarData->vt == VT_EMPTY))
        {
            reset();
        }
        else
        if (pVarData->vt == VT_BOOL)
        {
            set((V_BOOL(pVarData) == 1) ? true : false);
        }
        else
        if ((pVarData->vt == VT_I1)  || (pVarData->vt == VT_I2)  || (pVarData->vt == VT_I4)  ||
            (pVarData->vt == VT_UI1) || (pVarData->vt == VT_UI2) || (pVarData->vt == VT_UI4) ||
            (pVarData->vt == VT_INT) || (pVarData->vt == VT_UINT))
        {
            set((int)(V_INT(pVarData)));
        }
        else
        if ((pVarData->vt == VT_I8)  || (pVarData->vt == VT_UI8))
        {
            set((INT64)(V_I8(pVarData)));
        }
        else
        if (pVarData->vt == VT_R4)
        {
            set(V_R4(pVarData));
        }
        else
        if (pVarData->vt == VT_R8)
        {
            set(V_R8(pVarData));
        }
        else
        if (pVarData->vt == VT_BSTR)
        {
            set(V_BSTR(pVarData));
        }
        else
        {
            return Acad::eInvalidInput;
        }
        return Acad::eOk;
    };
#endif // _WIN32

public:
    varType       m_type;
    bool          m_bool;
    INT64         m_integer;
    double        m_double;
    AcString      m_string;
    AcDbObjectId  m_id;
    AcCmColor     m_color;
    AcGePoint3d   m_point;
    AcGeVector3d  m_vector;
};

// basic OPM property entry
class AcOPMPropertyEntry
{
public:
    AcOPMPropertyEntry()
        : m_categoryId(AcOPMCAT_Nil),
          m_propertyId(AcOPMCAT_FirstUserCat),
          m_propertyType(opmTypeNone),
          m_editable(true),
          m_isPerInstance(false),
          m_callbackFunc(NULL)
    {
    };

    AcOPMPropertyEntry(AcOPMCategoryId catId,      // only valid for built-in categories
                       const AcString& propName,
                       AcOPMPropertyId propId,
                       AcOpmDataType propType,
                       bool isPerInstance = false)
        : m_categoryId(catId),
          m_propertyName(propName),
          m_propertyId(propId),
          m_propertyType(propType),
          m_editable(true),
          m_isPerInstance(isPerInstance),
          m_callbackFunc(NULL)
    {
    };

    AcOPMPropertyEntry(const AcString& catName,  // category ID will be automatically assigned
                       const AcString& propName,
                       AcOPMPropertyId propId,
                       AcOpmDataType propType,
                       bool isPerInstance = false)
        : m_categoryName(catName),
          m_categoryId(AcOPMCAT_Nil),
          m_propertyName(propName),
          m_propertyId(propId),
          m_propertyType(propType),
          m_editable(true),
          m_isPerInstance(isPerInstance),
          m_callbackFunc(NULL)
    {
    };

    AcOPMPropertyEntry(AcOPMCategoryId catId,
                       const AcString& propName,
                       AcOPMPropertyId propId,
                       AcOpmDataType propType,
                       bool isPerInstance,
                       const AcStringArray& predefinedStrings)
        : m_categoryId(catId),
          m_propertyName(propName),
          m_propertyId(propId),
          m_propertyType(propType),
          m_editable(true),
          m_isPerInstance(isPerInstance),
          m_predefinedStrings(predefinedStrings),
          m_callbackFunc(NULL)
    {
    };

    AcOPMPropertyEntry(const AcString& catName,  // category ID will be automatically assigned
                       const AcString& propName,
                       AcOPMPropertyId propId,
                       AcOpmDataType propType,
                       bool isPerInstance,
                       const AcStringArray& predefinedStrings)
        : m_categoryName(catName),
          m_categoryId(AcOPMCAT_Nil),
          m_propertyName(propName),
          m_propertyId(propId),
          m_propertyType(propType),
          m_editable(true),
          m_isPerInstance(isPerInstance),
          m_predefinedStrings(predefinedStrings),
          m_callbackFunc(NULL)
    {
    };

    AcOPMPropertyEntry(const AcOPMPropertyEntry& other)
    {
        *this = other;
    };

    AcOPMPropertyEntry& operator= (const AcOPMPropertyEntry& other)
    {
        m_categoryName  = other.m_categoryName;
        m_categoryId    = other.m_categoryId;
        m_propertyName  = other.m_propertyName;
        m_propertyId    = other.m_propertyId;
        m_propertyType  = other.m_propertyType;
        m_predefinedStrings = other.m_predefinedStrings;
        m_editable      = other.m_editable;
        m_isPerInstance = other.m_isPerInstance;
        m_callbackFunc  = other.m_callbackFunc;
        m_childNames    = other.m_childNames;
        m_childTypes    = other.m_childTypes;
        m_pClientData   = other.m_pClientData;

        return *this;
    };

// since V17
    void  setClientData(void* clientData) { m_pClientData = clientData; };
    void* getClientData() const { return m_pClientData; };
// end V17

    virtual ~AcOPMPropertyEntry() {};

public:
    AcString           m_categoryName;      // used as 'Label' for category (ignored for built-in categories)
    AcOPMCategoryId    m_categoryId;        // predefined or client category ID
    AcString           m_propertyName;      // property label
    AcOPMPropertyId    m_propertyId;        // property ID unique within application (built-in properties are ignored)
    AcOpmDataType      m_propertyType;      // data type for property
    AcStringArray      m_predefinedStrings; // array of predefined value strings
    bool               m_editable;          // false for a read-only property
    bool               m_isPerInstance;     // false for a normal property, true for a Per-Instance property
    AcOPMPropertyDialogProc m_callbackFunc; // property editor (as callback), if non-NULL
    // optional child items (allows expanding the main property)
    AcStringArray      m_childNames;        // array of property labels for child items
    AcArray<AcOpmDataType> m_childTypes;    // array of data types for child items
// since V17
    void*              m_pClientData;       // client data (cookie/cargo), not used by C++ OPM API or PropertiesPanel
// end V17
};

typedef AcArray<AcOpmNativePropertyId> AcOPMNativePropertyArray;
typedef AcArray<AcOPMPropertyEntry, AcArrayObjectCopyReallocator<AcOPMPropertyEntry> > AcOPMPropertyArray;


class BRX_IMPORTEXPORT AcOPMExtensionManager
{
public:
    virtual ~AcOPMExtensionManager() {};

    // registers a client extension for specified entity class (optionally for derived
    // entity classes);
    // a single client extension can be registered for multiple entity classes;
    // 'subEntityTypes' is a combination of requested AcOpmSubEntityType subentity types,
    // specifies which subEntity types are additionally supported (optional)
    virtual AcOpmResult registerEntityExtension (AcOPMClientExtension* clientExtension,
                                                 const AcRxClass* entityClass,
                                                 bool supportsDerivedClasses = false,
// since V17
                                                 int subEntityTypes = opmNullSubentType
// end V17
                                                ) = 0;

    // unregisters a client extension for specified entity class;
    // client extension remains registered for any other entity class, it was registered
    virtual bool  unregisterEntityExtension (AcOPMClientExtension* clientExtension,
                                             const AcRxClass* entityClass
                                            ) = 0;

    // registers a client extension for the "NoSelection" mode of PropertiesPanel;
    virtual AcOpmResult registerGeneralExtension (AcOPMClientExtension* clientExtension) = 0;

    // unregisters a client extension for the "NoSelection" mode of PropertiesPanel;
    virtual bool  unregisterGeneralExtension (AcOPMClientExtension* clientExtension) = 0;

    // removes a client extension from AcOPMExtensionManager;
    // the client extension is automatically unregistered for (any) entity class it was
    // registered for, and also unregisters for the "NoSelection" mode of PropertiesPanel;
    virtual bool  removeExtension (AcOPMClientExtension* clientExtension) = 0;

    // call this function to update the properties in "NoSelection" PropertiesPanel page;
    // AcOPMExtensionManager then queries those AcOPMClientExtension having "NoSelection"
    // properties by getPropertyName(), getPropertyDescription(), getPropertyEnabled(),
    // getPropertyReadOnly(), getPredefinedStrings(), getPropertyValue()
    virtual void updateNoSelectionProperties () = 0;

    // provides the active AcOPMPropertyEntry during AcOPMClientExtension callbacks
    // (outside of callback time this returns 'false' always);
    // available during these callbacks : getPropertyName(), getPropertyDescription(),
    // getPropertyEnabled(), getPropertyReadOnly(), getPredefinedStrings(),
    // getPropertyValue(), setPropertyValue();
    // client code must provide an AcOPMPropertyEntry instance
    virtual bool  getActiveOPMPropertyEntry (AcOPMPropertyEntry& activeOPMEntry) = 0;

    // provides the "m_pClientData" (cookie/cargo) for the active AcOPMPropertyEntry during
    // AcOPMClientExtension callbacks (outside of callback time this returns NULL always);
    // same logic as for above "getActiveOPMPropertyEntry()", but more lightweight
    virtual void* getActiveOPMPropertyClientData () const = 0;

// since V21
    // allows a client extension to influence the expanded/collapsed status of a category;
    // this function can be called during 'beginPropertiesUpdate' and 'endPropertiesUpdate()',
    // otherwise the call / is ignored;
    // if 'categoryName' is not an entry in the PropertiesGrid, or not a category, the call is ignored;
    virtual void expandCategory (const AcString& categoryName, bool expand = true) = 0;

    // declares the category 'categoryName' as "delayLoad" category :
    // this will set the category a) as initially collapsed, and b) when expanded, a messagebox will
    // be shown whether to expand or stay collapsed - this feature is useful for categories, where
    // collecting all data is costly and might take some significant time;
    // this function can be called during 'beginPropertiesUpdate' and 'endPropertiesUpdate()',
    // otherwise the call / is ignored;
    // if 'categoryName' is not an entry in the PropertiesGrid, or not a category, the call is ignored;
    virtual void delayLoadCategory (const AcString& categoryName, bool expand = true) = 0;

    // allows to register a specific 'entityClass', to hide or unhide the "undo per entity" PropertiesPanel entry
    // for selected entities of that class;
    // if 'isBaseClass' is 'true', entity classes derived from 'pClass' are included;
    // returns success or error
    virtual bool disableOpmUndoHistoryForClass(const AcRxClass* entityClass, bool isBaseClass = false) = 0;
    virtual bool enableOpmUndoHistoryForClass(const AcRxClass* entityClass) = 0;
// end V21
};

AcOPMExtensionManager* acOPMExtensionManager();

// some wrappers for commonly used functions
#define acRegisterEntityExtension         acOPMExtensionManager()->registerEntityExtension
#define acUnregisterEntityExtension       acOPMExtensionManager()->unregisterEntityExtension

#define acRegisterGeneralExtension        acOPMExtensionManager()->registerGeneralExtension
#define acUnregisterGeneralExtension      acOPMExtensionManager()->unregisterGeneralExtension

#define acRemoveOPMExtension              acOPMExtensionManager()->removeExtension
#define acOPMupdateNoSelectionProperties  acOPMExtensionManager()->updateNoSelectionProperties


typedef std::map<AcString, AcString> AcOPMEntityTypeNames; // <globalName, localName>

class AcOPMClientExtension
{
public:
    AcOPMClientExtension() {};
    virtual ~AcOPMClientExtension()
    {
        if (acOPMExtensionManager() != NULL)
            acOPMExtensionManager()->removeExtension(this);
    };

    // ========== Properties Registration Functions ==========

    // this function is called by AcOPMExtensionManager during registerOPMExtension() to
    // fill the properties array with AcOPMPropertyEntry entries, which define the additional
    // properties to be shown, when an entity of registered target entity class (or optionally
    // derived class) is selected;
    // as a single AcOPMClientExtension instance can be registered for multiple entity
    // classes, this callback provides the entityClass for which to fill-in the properties;
    // this function is also called, when 'int subEntityTypes != opmNullSubentType' is used
    // with acRegisterEntityExtension() :
    // this allows to define additional properties for the "main" entity, and additional
    // properties for main entity's subentities, independently
    virtual bool getPropertyMap(const AcRxClass* entityClass,
                                AcOPMPropertyArray& properties) const
    {
        return false;
    };

// since V17
    // this function is called by AcOPMExtensionManager during registerOPMExtension() to
    // fill the properties array with AcOPMPropertyEntry entries, which define the additional
    // *subentity* properties to be shown, when a subentity of registered AcOpmSubEntityType
    // for registered target entity class (or optionally derived class) is selected;
    // this function is only called, when 'int subEntityTypes' is *not* opmNullSubentType;
    // called once for each registered AcOpmSubEntityType, as specified by 'int subEntityTypes';
    // this allows to register properties for the "main" entity (say AcDb3dSolid), and extra
    // properties for each subentity type (say edge + face of the AcDb3dSolid);
    // Note : even when 'getPropertyMap()' call for the "main" entity returns 'false', this
    //        function is still called, to allow only subentity properties, but no extra
    //        properties for the main entity 
    virtual bool getPropertyMap(const AcRxClass* entityClass,
                                const AcOpmSubEntityType subentType,
                                AcOPMPropertyArray& properties) const
    {
        return false;
    };

    // this notification is sent when the OPM update starts (after selection);
    // for the "NoSelection" mode, the 'selectionSet' is empty;
    // this allows client extensions to inspeact the entire selection, which is
    // about to be processed (i.e. to inspect inter-object relations)
    virtual void beginPropertiesUpdate(const AcDbObjectIdArray& selectionSet) const
    {
    };

    // this notification is sent when the OPM update is finished
    virtual void endPropertiesUpdate() const
    {
    };
// end V17

    // this function is called by AcOPMExtensionManager during entity selection for this
    // AcOPMClientExtension, registed by AcOPMClientExtension::acRegisterEntityExtension(),
    // once for each selection cycle;
    // if supportsDynamicProperties() returns 'true', the client extension is asked for
    // each entity in current selection to provide the dynamic properties (see below)
    virtual bool supportsDynamicProperties() const
    {
        return false;
    };

    // this function is called by AcOPMExtensionManager during entity selection for this
    // AcOPMClientExtension, registed by AcOPMClientExtension::acRegisterEntityExtension()
    // for all entities in actual selection;
    // NOTE : if 'supportsDynamicProperties()' returns 'false', this 'getDynamicPropertyMap()'
    //        function will not be called
    // this allows to dynamically add properties, depending on the particular entity type/id;
    // fill the properties array with AcOPMPropertyEntry entries, which define the "dynamic"
    // properties, additionally to "static properties";
    // default implementation returns 'false' to indicate no dynamic properties
    virtual bool getDynamicPropertyMap(const AcDbEntity* entity,
                                       AcOPMPropertyArray& properties) const
    {
        return false;
    };

// since V17
    // this function is called by AcOPMExtensionManager during entity selection for this
    // AcOPMClientExtension, registed by AcOPMClientExtension::acRegisterEntityExtension()
    // for all subentities in actual selection;
    // NOTE : if 'supportsDynamicProperties()' returns 'false', this 'getDynamicPropertyMap()'
    //        function will not be called
    // this allows to dynamically add subentity properties for particular subentity type(s),
    // as specified by 'int subEntityTypes' in acRegisterEntityExtension();
    // NOTE : even if the call to 'getDynamicPropertyMap()' for a "main" entity returns 'false',
    //        this function is still called to provide properties for the subentity selected;
    // fill the properties array with AcOPMPropertyEntry entries, which define the "dynamic
    // subentity properties", additionally to "static subentity properties";
    // 'fspArray' specifies the currently selected subentities (for given "main" entity),
    // so client extension is free to define a single property (one for all), or one property
    // for each selected subentity, of given type 'subentType' ('fspArray' *only* contains
    // subentity pathes of that type);
    // default implementation returns 'false' to indicate no dynamic subentity properties
    virtual bool getDynamicPropertyMap(const AcDbEntity* entity,
                                       const AcOpmSubEntityType subentType,
                                       const AcDbFullSubentPathArray& fspArray,
                                       AcOPMPropertyArray& properties) const
    {
        return false;
    };
// end V17

    // this function is called by AcOPMExtensionManager during registerOPMExtension() to
    // fill the properties array with AcOPMPropertyEntry entries, which define the additional
    // properties to be shown when NO ENTITY SELECTION is active;
    // a single AcOPMClientExtension instance can be registered for one or more entity
    // classes, but can also serve for the "NO SLEECTION" mode;
    // this override is called during registration with
    // "AcOpmResult registerOPMExtension(const AcOPMClientExtension* clientExtension)"
    virtual bool getPropertyMap(AcOPMPropertyArray& properties) const
    {
        return false;
    };

    // this function is called by AcOPMExtensionManager during registerOPMExtension() to
    // allow the client extension to disable specific native properties (set as read-only);
    // useful, if the client extension adds extra properties to edit entity properties,
    // which are also present as 'native property' in OPM for that entity - as result,
    // user can edit that property by 2 OPM entries : the 'native' property, and the one
    // added by client extension;
    // client extension can add particular 'native property' IDs (see AcOpmNativePropertyIds.h)
    // to 'disableNativeProps' array to signal which native properties shall be disabled by
    // AcOPMExtensionManager, when related entities are selected by user;
    // disabling native properties will only be done, if client extension registers itself
    // for the selected entity type(s)
    virtual bool getNativePropertiesToDisable(AcOPMNativePropertyArray& disableNativeProps) const
    {
        return false;
    };

// since V17
    // this function is called to retrieve an "Application Name" for this client extension;
    // this name is used to distinguish between client extensions, resolve property IDs,
    // (potentially) display additional information and so on
    virtual bool getApplicationName(AcString& name) const
    {
        return false;
    };
// end V17

    // ========== Properties Handling Functions ==========

    // called to fill-in the 'ObjectName' to be used in Types combobox;
    // only called for custom entities -or- when option 'eSupportsPerInstanceProperties' is set;
    // return 'false' to indicate that the property is not served by this AcOPMClientExtension
    virtual bool getObjectName(const AcDbEntity* entity, AcString& name, const AcOpmSubEntityType subentType = opmNullSubentType) const
    {
        return false;
    };

    // called to fill-in the 'Category Name' to be used as 'Label' for the category;
    // return 'false' to use the category name as provided during property registration;
    // NOTE : depending on how the category was specified (by ID or name), the appropriate
    //        version of 'getCategoryName()' is called; best to overload both versions
    virtual bool getCategoryName(const AcString& category, AcString& categoryName) const
    {
        return false;
    };
    virtual bool getCategoryName(AcOPMCategoryId category, AcString& categoryName) const
    {
        return false;
    }

    // called to fill-in the 'Property Name' to be used as 'Label' for the property;
    // return 'false' to use the property name as provided during property registration;
    // NOTE : for "NoSelection" properties, the 'entity' argument is provided as NULL !!
    virtual bool getPropertyName(const AcDbEntity* entity,
                                 AcOPMPropertyId propertyId,
                                 const AcString& childName,
                                 AcString& name) const
    {
        return false;
    };

    // called to fill-in the 'Property Description' to be used as information for the property;
    // return 'false' to indicate that the property is not served by this AcOPMClientExtension;
    // NOTE : for "NoSelection" properties, the 'entity' argument is provided as NULL !!
    virtual bool getPropertyDescription(const AcDbEntity* entity,
                                        AcOPMPropertyId propertyId,
                                        const AcString& childName,
                                        AcString& description) const
    {
        return false;
    };

    // returns whether the specified property shall participate in 'PropertyPreview';
    // actually only called for combobox-based properties;
    // default is 'true' as for any built-in combobox-based property;
    // client extension can dynamically enable or disable 'PropertyPreview' depending on
    // the amount and type of selected entities (see 'beginPropertiesUpdate(...)' callback);
    // this function is called once for each AcOPMPropertyId, per selection cycle
    virtual bool allowPropertyPreview(AcOPMPropertyId propertyId) const
    {
        return true;
    };

    //===== Determine the "Enabled" and "HideDisabled" status =====

    // called to fill-in the 'Property Enabled' status for the property;
    // fill-in the 'enabled' hint, to enable or disable the property;
    // fill-in the 'hideDisabled' hint, to show or hide a disabled property;
    // return 'false' to indicate that the property is not served by this AcOPMClientExtension;
    // NOTE : for "NoSelection" properties, the 'entity' argument is provided as NULL !!
    virtual bool getPropertyEnabled(const AcDbEntity* entity,
                                    AcOPMPropertyId propertyId,
                                    const AcString& childName,
                                    bool& enabled,
                                    bool& hideDisabled) const
    {
        return false;
    };

// since V21
    // called to fill-in the 'Property Enabled' status for the property;
    // called for selected sub-entity, if client extension has registered the property for any
    // of the subentity types;
    // 'subentType' specifies the actual subentity type (same as in 'fspId');
    // only called, if the 'subentType' was also registered with registerEntityExtension();
    // return 'false' to indicate that the property is not served by this AcOPMClientExtension;
    // NOTE : if multiple same-typed sub-entities, of same "main" entity, are selected, the
    //        'fspArray' argument will only contain those sub-entities of type 'subentType'
    virtual bool getPropertyEnabled(const AcDbEntity* entity,
                                    const AcOpmSubEntityType subentType,
                                    const AcDbFullSubentPathArray& fspArray,
                                    const AcOPMPropertyId propertyId,
                                    const AcString& childName,
                                    bool& enabled,
                                    bool& hideDisabled) const
    {
        return false;
    };

    // called to fill-in the 'Property Enabled' status for the property;
    // this function is always called, if any subentity is selected, and subentity support is
    // specified with the registration
    // NOTE : if multiple sub-entities of same "main" entity are selected, this callback
    //        is called multiple times, once per selected sub-entity;
    // NOTE : - if the client-side handler call returns 'false' for any of these (multiple) calls,
    //          then the entire 'getPropertyEnabled()' cycle is treated as 'false/failed', and
    //          the above 'getPropertyReadOnly()' function is finally called
    //        - if all client-side handler calls return 'true', with different 'hideDisabled' results,
    //          then the above function is finally called to get a 'final' decision
    // NOTE : this function has priority, called before the above 'getPropertyEnabled()' function
    virtual bool getPropertyEnabled(const AcDbEntity* entity,
                                    const AcDbFullSubentPath& subEntPath,
                                    const AcOPMPropertyId propertyId,
                                    const AcString& childName,
                                    bool& enabled,
                                    bool& hideDisabled) const
    {
        return false;
    };
// end V21

    //===== Determine the "ReadOnly" status =====

    // called to fill-in the 'Property ReadOnly' status for the property;
    // return 'false' to indicate that the property is not served by this AcOPMClientExtension;
    // NOTE : for "NoSelection" properties, the 'entity' argument is provided as NULL !!
    virtual bool getPropertyReadOnly(const AcDbEntity* entity,
                                     AcOPMPropertyId propertyId,
                                     const AcString& childName,
                                     bool& readOnly) const
    {
        return false;
    };

// since V21
    // called to fill-in the 'Property ReadOnly' status for the property;
    // called for selected sub-entity, if client extension has registered the property for any
    // of the subentity types;
    // 'subentType' specifies the actual subentity type (same as in 'fspId');
    // only called, if the 'subentType' was also registered with registerEntityExtension();
    // return 'false' to indicate that the property is not served by this AcOPMClientExtension;
    // NOTE : if multiple same-typed sub-entities, of same "main" entity, are selected, the
    //        'fspArray' argument will only contain those sub-entities of type 'subentType'
    virtual bool getPropertyReadOnly(const AcDbEntity* entity,
                                     const AcOpmSubEntityType subentType,
                                     const AcDbFullSubentPathArray& fspArray,
                                     const AcOPMPropertyId propertyId,
                                     const AcString& childName,
                                     bool& readOnly) const
    {
        return false;
    };

    // called to fill-in the 'Property ReadOnly' status for the property;
    // this function is always called, if any subentity is selected, and subentity support is
    // specified with the registration
    // NOTE : if multiple sub-entities of same "main" entity are selected, this callback
    //        is called multiple times, once per selected sub-entity;
    // NOTE : - if the client-side handler call returns 'false' for any of these (multiple) calls,
    //          then the entire 'getPropertyReadOnly()' cycle is treated as 'false/failed', and
    //          the above 'getPropertyReadOnly()' function is finally called
    //        - if all client-side handler calls return 'true', with different 'readOnly' results,
    //          then the above function is finally called to get a 'final' decision
    // NOTE : this function has priority, called before the above 'getPropertyReadOnly()' function
    virtual bool getPropertyReadOnly(const AcDbEntity* entity,
                                     const AcDbFullSubentPath& subEntPath,
                                     const AcOPMPropertyId propertyId,
                                     const AcString& childName,
                                     bool& readOnly) const
    {
        return false;
    };
// end V21

    //===== Determine the "Predefined Strings" for enum properties =====

    // called to fill-in the 'PredefinedStrings' list for the property;
    // this dynamically allows to replace the strings from 'AcOPMPropertyEntry::m_predefinedStrings',
    // which are used as default, if 'false' is returned;
    // especially intended for "PerInstanceProperties" but also to support easier localisation
    // return 'false' to indicate that the property is not served by this AcOPMClientExtension;
    // NOTE : for "NoSelection" properties, the 'entity' argument is provided as NULL !!
    virtual bool getPredefinedStrings(const AcDbEntity* entity,
                                      AcOPMPropertyId propertyId,
                                      const AcString& childName,
                                      AcStringArray& predefinedStrings) const
    {
        return false;
    };

// since V21
    // called to fill-in the 'PredefinedStrings' list for the property;
    // called for selected sub-entity, if client extension has registered the property for any
    // of the subentity types;
    // 'subentType' specifies the actual subentity type (same as in 'fspId');
    // only called, if the 'subentType' was also registered with registerEntityExtension();
    // return 'false' to indicate that the property is not served by this AcOPMClientExtension;
    // NOTE : if multiple same-typed sub-entities, of same "main" entity, are selected, the
    //        'fspArray' argument will only contain those sub-entities of type 'subentType'
    virtual bool getPredefinedStrings(const AcDbEntity* entity,
                                      const AcOpmSubEntityType subentType,
                                      const AcDbFullSubentPathArray& fspArray,
                                      const AcOPMPropertyId propertyId,
                                      const AcString& childName,
                                      AcStringArray& predefinedStrings) const
    {
        return false;
    };

    // called to fill-in the 'PredefinedStrings' list for the property;
    // this function is always called, if any subentity is selected, and subentity support is
    // specified with the registration
    // NOTE : if multiple sub-entities of same "main" entity are selected, this callback
    //        is called multiple times, once per selected sub-entity;
    // NOTE : - if the client-side handler call returns 'false' for any of these (multiple) calls,
    //          then the entire 'getPredefinedStrings()' cycle is treated as 'false/failed', and
    //          the above 'getPredefinedStrings()' function is finally called
    //        - if all client-side handler calls return 'true', with different 'predefinedStrings' results,
    //          then the collection of all these strings is used (multiple strings filtered for single appearance)
    // NOTE : this function has priority, called before the above 'getPredefinedStrings()' function
    virtual bool getPredefinedStrings(const AcDbEntity* entity,
                                      const AcDbFullSubentPath& subEntPath,
                                      const AcOPMPropertyId propertyId,
                                      const AcString& childName,
                                      AcStringArray& predefinedStrings) const
    {
        return false;
    };
// end V21

    // called to fill-in the 'Property Value' for the property;
    // the AcOPMVariant data type is already preset to the proper type (based on AcOPMPropertyArray
    // definition provided at registration time), to allow cross-checking;
    // 'childName' specifies the sub-item's (child) name, it is the name from property registration,
    // not the (optionally) 'translated' name; it is empty for the 'parent' or any non-child items
    // return 'false' to indicate that the property is not served by this AcOPMClientExtension;
    // NOTE : for "NoSelection" properties, the 'entity' argument is provided as NULL !!
    virtual bool getPropertyValue(const AcDbEntity* entity,
                                  AcOPMPropertyId propertyId,
                                  const AcString& childName,
                                  AcOPMVariant& value) const
    {
        return false;
    };

// since V17
    // as above : called to fill-in the 'Property Value' on client side;
    // called for selected subentity, if client extension has registered the property for any
    // of the subentity types;
    // 'subentType' specifies the actual subentity type (same as in 'fspId');
    // only called, if the 'subentType' was also registered with acRegisterEntityExtension();
    // NOTE : if multiple same-typed subentities, of same "main" entity, are selected, the
    //        'fspArray' argument will only contain those subentities of type 'subentType'
    virtual bool getPropertyValue(const AcDbEntity* entity,
                                  const AcOpmSubEntityType subentType,
                                  const AcDbFullSubentPathArray& fspArray,
                                  const AcOPMPropertyId propertyId,
                                  const AcString& childName,
                                  AcOPMVariant& value) const
    {
        return false;
    };
// end V17

// since V21
    // as above : called to fill-in the 'Property Value' on client side;
    // this function is always called, if any subentity is selected, and subentity support is
    // specified with the registration
    // NOTE : if multiple sub-entities of same "main" entity are selected, this callback
    //        is called multiple times, once per selected sub-entity;
    // NOTE : - if the client-side handler call returns 'false' for any of these (multiple) calls,
    //          then the entire 'getPropertyValue()' is treated as 'false/failed', and the above
    //          'getPropertyValue()' function is called
    //        - if all client-side handler calls return 'true', with different 'value' results,
    //          then the value of the property is treated as "*Varies*"
    // NOTE : this function has priority, called before the above 'getPropertyValue()' function
    virtual bool getPropertyValue(const AcDbEntity* entity,
                                  const AcDbFullSubentPath& subEntPath,
                                  const AcOPMPropertyId propertyId,
                                  const AcString& childName,
                                  AcOPMVariant& value) const
    {
        return false;
    };

    // allows a client extension to specify a custom parent for the specified 'propertyId' property;
    // this function is called after the 'getPropertyValue()' call using the same 'propertyId';
    // return 'false' to have the related PropertiesPanel item ordered in normal sequence;
    // return 'true' if a valid parent property is applied by 'AcOPMPropertyId& parentId'
    // NOTE : if returning a custom parent ID, then 2 conditions apply :
    //        a) it must be an AcOPMPropertyId which was already queried/processed before (to be parent)
    //        b) it must be a valid AcOPMPropertyId of this client extension
    virtual bool getPropertyParent(const AcOPMPropertyId propertyId, AcOPMPropertyId& parentId) const
    {
        return false;
    };
// end V21

    // called to save the 'Property Value' on client side;
    // the AcOPMVariant data type is already preset to the proper type (based on AcOPMPropertyArray
    // definition provided at registration time), to allow cross-checking;
    // 'childName' specifies the sub-item's (child) name, it is the name from property registration,
    // not the (optionally) 'translated' name; it is empty for the 'parent' or any non-child items
    // return 'false' to indicate that the value could not be stored properly;
    // NOTE : for "NoSelection" properties, the 'entity' argument is provided as NULL !!
    //        otherwise, in "selected entity" mode, the 'entity' is already opened in 'kForWrite' mode
    virtual bool setPropertyValue(AcDbEntity* entity,
                                  AcOPMPropertyId propertyId,
                                  const AcString& childName,
                                  const AcOPMVariant& value)
    {
        return false;
    };

// since V17
    // as above : called to save the 'Property Value' on client side;
    // called for selected subentity, if client extension has registered the property for any
    // of the subentity types (or combinations);
    // 'subentType' specifies the actual subentity type (same as in 'fspArray' entries);
    // only called, if the 'subentType' was also registered with acRegisterEntityExtension();
    // if multiple subentities of a "main" entity are selected (i.e. multiple edges or faces),
    // this function is called once for each selected subentity;
    // NOTE : if multiple same-typed subentities, of same "main" entity, are selected, the
    //        'fspArray' argument will only contain those subentities of type 'subentType'
    virtual bool setPropertyValue(AcDbEntity* entity,
                                  const AcOpmSubEntityType subentType,
                                  const AcDbFullSubentPathArray& fspArray,
                                  const AcOPMPropertyId propertyId,
                                  const AcString& childName,
                                  const AcOPMVariant& value)
    {
        return false;
    };
// end V17

// since V21
    // as above : called to apply the 'Property Value' on client side;
    // called for selected subentity, if client extension has registered the property for any
    // of the subentity types (or combinations);
    // NOTE : if multiple sub-entities of same "main" entity are selected, this callback
    //        is called multiple times, once per selected sub-entity;
    // NOTE : - if the client-side handler returns 'true' for any of these (multiple) calls, then
    //          the entire 'getPropertyValue()' is treated as 'true/successful', and the above
    //          'getPropertyValue()' functions are not called;
    //        - but if all client-side handler calls return 'false', then the entire 'getPropertyValue()'
    //          is treated as 'false/failed', and the above mentioned function is called
    // NOTE : this function has priority, called before the above 'setPropertyValue()' function
    virtual bool setPropertyValue(AcDbEntity* entity,
                                  const AcDbFullSubentPath& subEntPath,
                                  const AcOPMPropertyId propertyId,
                                  const AcString& childName,
                                  const AcOPMVariant& value)
    {
        return false;
    };

    // called to fill-in the 'ObjectName' to be used in Types combobox, if one or more sub-entities are selected;
    // only called for custom entities -or- when option 'eSupportsPerInstanceProperties' is set;
    // only called, if one or more sub-entities are selected, for the given "main" entity;
    // this callback is called multiple times, per each selected sub-entity then;
    // NOTE : this function has priority, called before the above function;
    // return 'false' to indicate that ths function is not served by this AcOPMClientExtension;
    // in such case, the above 'getObjectName()' is called afterwards
    virtual bool getObjectName(const AcDbEntity* entity, const AcDbFullSubentPath& subEntPath, AcString& name) const
    {
        return false;
    };
// end V21

// since V22
    // this function is called to retrieve all possible entity names, specific for this AcOPMClientExtension;
    // return 'false' to indicate that the names mapping is not provided;
    virtual bool allEntityNames(AcOPMEntityTypeNames& names) const
    {
        return false;
    };
// end V22
};
