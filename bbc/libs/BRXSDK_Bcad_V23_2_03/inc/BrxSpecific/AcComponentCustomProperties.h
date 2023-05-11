// BRX API for component custom properties structure

// Property of Bricsys NV. All rights reserved.
// This file is part of the source code of Bricsys NV. The source code
// is subject to copyright, is a trade secret of Bricsys NV, and contains
// embodiments of inventions disclosed in patent applications and patents
// of Bricsys NV.

/////////////////////////////////////////////////////////////////////////

#pragma once

#ifndef _AcComponentCustomProperties_h_Included
#define _AcComponentCustomProperties_h_Included

#include "brx_importexport.h"
#include "Misc/MiscGlobal.h"
#include "Misc/AcValue.h"
#include "AcDb/AcDbObjectId.h"
#include "AcSharedPtr.h"

class BrxMechanicalPropertySet;
using BrxMechanicalPropertySets =
    AcArray<BrxMechanicalPropertySet, AcArrayObjectCopyReallocator<BrxMechanicalPropertySet>>;

class BrxMechanicalPropertyDefinition;
using BrxMechanicalPropertyDefinitions =
    AcArray<BrxMechanicalPropertyDefinition, AcArrayObjectCopyReallocator<BrxMechanicalPropertyDefinition>>;

// these enum flags are used to get type of the custom properties value
enum BRX_IMPORTEXPORT BrxMechanicalPropertyType
{
    eUndefined = 0,
    eInteger,
    eReal,
    eBoolean,
    eString
};

// represents a custom component properties category (property set), a category consists of custom properties
class BRX_IMPORTEXPORT BrxMechanicalPropertySet
{
public:
    BrxMechanicalPropertySet();
    BrxMechanicalPropertySet(const BrxMechanicalPropertySet& other);
    BrxMechanicalPropertySet& operator=(const BrxMechanicalPropertySet& other);
    ~BrxMechanicalPropertySet();

    // checks if this property set (category) is empty
    bool isNull() const;

    // returns the category name
    AcString categoryName() const;

    // returns true if the property is not available for all the instances in the document, but it can be assigned for
    // the particular instance or instances
    bool isPerInstance() const;

    // returns the category label
    AcString categoryLabel() const;

    // returns the list of all the properties stored in this property set
    BrxMechanicalPropertyDefinitions getAllCustomProperties() const;

    // returns the existing custom property by its name
    BrxMechanicalPropertyDefinition getPropertyByName(const ACHAR* propertyName) const;

    // creates a new custom property and adds it to this property set
    BrxMechanicalPropertyDefinition
    addProperty(const ACHAR* propertyName, BrxMechanicalPropertyType type, const ACHAR* label = ACRX_T(""));

    // retrieves all the existing categories for the given database
    static BrxMechanicalPropertySets getAllCategories(AcDbDatabase* pDb);

    // finds the property set by its name in the given database
    static BrxMechanicalPropertySet getCategoryByName(AcDbDatabase* pDb, const ACHAR* categoryName);

    // creates a new category (property set) with the given parameters
    static BrxMechanicalPropertySet createCategory(AcDbDatabase* pDb,
                                                   const ACHAR* categoryName,
                                                   bool isPerInstance = false,
                                                   const ACHAR* label = ACRX_T(""));

private:
    class BrxMechanicalPropertySetImp;
    std::unique_ptr<BrxMechanicalPropertySetImp> m_pBrxImp;
};


// represents property enumeration, it contains a value and its description
struct BRX_IMPORTEXPORT BrxMechanicalPropertyEnum
{
    AcValue value;       // value as string
    AcString description; // description of the value
};
using BrxMechanicalPropertyEnums = AcArray<BrxMechanicalPropertyEnum>;


// describes the particular custom property
class BRX_IMPORTEXPORT BrxMechanicalPropertyDefinition
{
friend BrxMechanicalPropertySet;

public:
    BrxMechanicalPropertyDefinition();
    BrxMechanicalPropertyDefinition(const BrxMechanicalPropertyDefinition& other);
    BrxMechanicalPropertyDefinition& operator=(const BrxMechanicalPropertyDefinition& other);
    ~BrxMechanicalPropertyDefinition();

    // checks if this property is empty
    bool isNull() const;

    // returns true if the corresponding custom property is stored in database
    bool doesExist() const;

    // returns unique custom property name, this name can be used as identifier inside the particular database
    AcString name() const;

    // returns label name of the corresponding custom property
    AcString label() const;

    // returns type of this property, the following types are supported: Integer, Real, String and Boolean
    BrxMechanicalPropertyType type() const;

    // returns all the enumeration values set for this property (enumerations are not supported for the Boolean type)
    BrxMechanicalPropertyEnums enumValues() const;

    // sets a label for this custom property
    Acad::ErrorStatus setLabel(const ACHAR* newLabel);

    // sets a type for this custom property
    Acad::ErrorStatus setType(BrxMechanicalPropertyType newTypeName);

    // sets the new enumeration values for this custom property
    Acad::ErrorStatus setEnumValues(const BrxMechanicalPropertyEnums& aNewEnumValues);

  private:
    class BrxMechanicalPropertyDefinitionImp;
    std::unique_ptr<BrxMechanicalPropertyDefinitionImp> m_pBrxImp;
};

#endif // _AcComponentCustomProperties_h_Included
