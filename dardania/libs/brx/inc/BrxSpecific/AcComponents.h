// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

// declares the high-level 3D Components API

#ifndef _AcComponents_h_Included
#define _AcComponents_h_Included

#include "brx_importexport.h"
#include "Misc/MiscGlobal.h"
#include "Misc/AcValue.h"
#include "AcDb/AcDbObjectId.h"

class BrxComponentDefinitionImp;
class BrxComponentInstanceImp;
class BrxIUpdateMechStructureScopeImp;

Acad::ErrorStatus acdbInitComponentsClasses(); //deprecated
Acad::ErrorStatus acdbUninitComponentsClasses(); //deprecated


// Enum Definition

enum class EBrxComponentType  // component type, combined bit flag
{
    eNone                     = 0x00,
    eAssembly                 = 0x01,
    ePart                     = 0x02,
    eIsStandard               = 0x04,
    eMechanicalBlockOrEntity  = 0x08
};

enum class EBrxFileStatus
{
    eNotExternal  = 0,
    eResolved     = 1,
    eFileNotFound = 2,
    eUnresolved   = 3,
};

enum EBrxStatusBOM
{
    eRegular     = 0, // default behavior
    eTransparent = 1, // should be not included in BOM but its subcomponents can be included if necessary
    eTerminal    = 2, // should be treated as a leaf component
    eExcluded    = 3, // should be completely excluded from BOM with all subcomponents
};

// Mechanical structure Update Scope

// The purpose of this class is to provide updating mechanical structure of the
// model. Update of mechanical structure is required after component definition
// modifications. For example, component instances names are changed after
// setting the name of the corresponding component definition. Also assigning
// names is necessary in case of mechanical blocks creation. Instead of direct
// usage of this class it is better to use macros defined below :
// BRX_MECH_MODIFICATION_START and BRX_MECH_MODIFICATION_END
//
// Here is a small example analogous to creating a component definition (blockId
// is object of OdDbObject id, it is id of block or solid to retrieve definition
// from):
//   BRX_MECH_MODIFICATION_START(blockId.database());
//     auto componentDef = BrxComponentDefinition::getComponentDefinition(blockId, OdDb::kForRead, true);
//   BRX_MECH_MODIFICATION_END;
//
// NOTE: If you want to work with both features and components, just use
// BRX_FEATURE_MODIFICATION_START/BRX_FEATURE_MODIFICATION_END (or
// BRX_FEATURE_RECONSTRUCTION_START/BRX_FEATURE_RECONSTRUCTION_END).

class BRX_IMPORTEXPORT BrxIUpdateMechStructureScope
{
public:
    BrxIUpdateMechStructureScope(AcDbDatabase* pDb);
    BrxIUpdateMechStructureScope(const BrxIUpdateMechStructureScope& other);
    BrxIUpdateMechStructureScope& operator= (const BrxIUpdateMechStructureScope& other);
    virtual ~BrxIUpdateMechStructureScope();

private:
    BrxIUpdateMechStructureScopeImp* m_pScope;
};

#define BRX_MECH_MODIFICATION_START(DATABASE)                                  \
  {                                                                            \
    BrxIUpdateMechStructureScope brxUpdateMechStructureScope(DATABASE);

#define BRX_MECH_MODIFICATION_END }

// Class which stores the base information about property
struct BRX_IMPORTEXPORT BrxMechanicalPropertyInfo
{
    AcString m_categoryName;  // category name displayed in Mechanical browser (can be label if it exists)
    AcString m_propertyName;  // property name displayed in Mechanical browser (can be label if it exists)
    AcValue  m_value;         // property value
    AcString m_valueAsString; // string representation of the value
};

BRX_IMPORTEXPORT bool operator==(const BrxMechanicalPropertyInfo&, const BrxMechanicalPropertyInfo&);
using BrxMechanicalPropertyInfoArray = AcArray<BrxMechanicalPropertyInfo>;

// Component Definition

class BRX_IMPORTEXPORT BrxComponentDefinition
{
public:
    BrxComponentDefinition();
    BrxComponentDefinition(const BrxComponentDefinition& other);
    BrxComponentDefinition& operator=(const BrxComponentDefinition& other);
    virtual ~BrxComponentDefinition();

    // verifies whether this BrxComponentDefinition (or derived) instance is empty
    bool isNull() const;

    // sets this BrxComponentDefinition instance (or derived) to be empty
    void setNull();

    // returns the types of this component, combined EBrxComponentType bit flags
    Adesk::UInt32 componentType() const;

    // returns the BlockDefinition or 3dSolid objectId to which this component is attached to
    AcDbObjectId objectId() const;

    // returns the BlockDefinition objectId to which this component is attached to
    // deprecated, use objectId()
    AcDbObjectId blockId() const;

    // returns the array of entities, which are instances of this component;
    // returns a non-empty array only if the component type is 'Assembly'.
    AcDbObjectIdArray instanceEntityIds() const;

    // returns the array of block references, which are instances of this component;
    // returns a non-empty array only if the component type is 'Assembly'.
    // deprecated, use instanceEntityIds()
    AcDbObjectIdArray instanceBlockRefIds() const; 

    // returns the name of this component
    const ACHAR* name() const;

    // returns the description of this component
    const ACHAR* description() const;

    // returns whether this component definition is the root object
    bool isRoot() const;

    // returns whether this component definition is associated with an external file,
    // or whether it is a local component based on its BlockDefinition
    bool isExternal() const;

    // returns whether this component is standard
    bool isStandard() const;

    // returns standard part type of the component, relevant only for standard part
    AcString standardPartType(bool useLocalizedVersion = false);

    // returns name of the standard of the component, relevant only for standard part
    AcString standard(bool useLocalizedVersion = false);

    // returns standard part category of the component, relevant only for standard part
    AcString standardPartCategory(bool useLocalizedVersion = false);

    // returns standard part description of the component, relevant only for standard part
    AcString standardPartDescription(bool useLocalizedVersion = false);

    // verifies whether this component is up to date, when it refers to an external dwg file
    bool isUpToDate() const;

    // a component is called original if it defines the default geometry for the corresponding part or assembly;
    // for parametric components, it means that the component corresponds to the default values of its parameters;
    // components without parameters are always original.
    // 
    // returns whether this component is original or derived from the original one.
    bool isOriginal() const;

    // returns the objectId of the BlockDefinition this component is derived from;
    // returns kNull id if this component is the original BlockDefinition
    AcDbObjectId originalBlockId() const;

    // returns the actual status for an external component
    EBrxFileStatus fileStatus() const;

    // returns the path to file with definition of this external component, where it is defined as a root component
    const ACHAR* getFilePath() const;

    // returns the BOM status for this component
    EBrxStatusBOM bomStatus() const;

    // returns true if this component is sectionable
    // it is used in section views generation. Most instances are sectionable, while standard parts usually are not sectionable
    bool isSectionable() const;

    // returns true if the component represents array
    bool isArray() const;

    // returns true if the component represents array source (array item definition block)
    bool isArraySource() const;

    // returns the name of the material of this component
    // the name will be empty if the component doesn't have a material, the actual material should be extracted from the parent
    AcString physicalMaterial() const;

    // finds a value of the existing custom property with @categoryName and @propertyName,
    // if the property exists the value stored for this component will be returned
    bool getCustomPropertyValue(const ACHAR* categoryName, const ACHAR* propertyName, AcValue& value) const;

    // retrieves a list of names of all the categories (property sets) applicable to this component, i.e. all the
    // categories assigned to the component and all not per instance categories
    bool getAllApplicableCategories(AcStringArray& aCategoryNames) const;

    // retrieves values, names and categories of all the properties for the given component
    bool getAllCustomPropertiesValues(BrxMechanicalPropertyInfoArray& aMechPropertyInfos) const;

    // sets the name of the represented component, may affect other instances of the same component
    Acad::ErrorStatus setName(const ACHAR* componentName);

    // sets the description of the represented component, may affect other instances of the same component
    Acad::ErrorStatus setDescription(const ACHAR* description);

    // sets type of the represented component to standard or not, may affect other instances of the same component
    Acad::ErrorStatus setAsStandard(bool isStandard = true);

    // sets the BOM status of the represented component, may affect other instances of the same component
    Acad::ErrorStatus setStatusBOM(EBrxStatusBOM status);

    // sets the sectionability of the represented component, may affect other instances of the same component
    Acad::ErrorStatus setSectionability(bool isSectionable = true);

    // Sets the physical material of the represented component
    // If the createIfNotExist flag is true the material with the given name will be created in case there was no such a
    // material in the database before
    Acad::ErrorStatus setPhysicalMaterial(const ACHAR* materialName, bool createIfNotExist = false);

    // these enum flags are used to define behavior of custom property creation if the property doesn't exist.
    enum class ECustomPropertyParameters
    {
        eDoNotCreate = 0,                 // The property will not be created
        eCreateForThisInstanceIfNotExist, // The custom property will be created just for this component
        eCreateForAllIfNotExist // The custom property will be created for all the components in the mech structure
    };

    // sets a value for the existing custom property with @categoryName and @propertyName
    Acad::ErrorStatus setCustomPropertyValue(const ACHAR* categoryName,
                           const ACHAR* propertyName,
                           const AcValue& value,
                           ECustomPropertyParameters params = ECustomPropertyParameters::eDoNotCreate);

    // assigns the passed per-instance category (property set) for this component (i.e., makes this property set)
    Acad::ErrorStatus assignPropertySet(const ACHAR* categoryName);

    // completely removes the mechanical structure for the specified BlockDefinition (BlockTableRecord) or 3dSolid
    // NOTE: This component, all the components and inserts inside it will be invalid after the operation.
    // (Re-called getComponentDefinition method returns null component for the component itself and all the methods
    // will display the error dialog; behaviour of methods called by subcomponents objects will be undefined).
    bool unmech();

    // retrieves the Component Definition for the specified BlockDefinition (BlockTableRecord) or 3dSolid;
    // if 'createIfNotExists' argument is 'true', a Component Definition is created, if it does not exist yet
    // NOTE: in case of creating a new component the special update scope (BRX_MECH_MODIFICATION_START/
    // BRX_MECH_MODIFICATION_END) is required for correct assigning components names
    // @see BRX_MECH_MODIFICATION_START, BRX_MECH_MODIFICATION_END
    static BrxComponentDefinition getComponentDefinition(const AcDbObjectId& objectId, bool createIfNotExists = false);

private:
    BrxComponentDefinitionImp* m_pBrxImp;
};

// Component Instance

class BRX_IMPORTEXPORT BrxComponentInstance
{
public:
    BrxComponentInstance();
    BrxComponentInstance(const BrxComponentInstance& other);
    BrxComponentInstance& operator=(const BrxComponentInstance& other);
    virtual ~BrxComponentInstance();

    // verifies whether this BrxComponentInstance (or derived) instance is empty
    bool isNull() const;

    // sets this BrxComponentInstance instance (or derived) to be empty
    void setNull();

    // returns the BlockId or SolidId which this BrxComponentInstance is attached to
    AcDbObjectId instanceDefinitionId() const;

    // returns the BlockId which this BrxComponentInstance is attached to
    // deprecated, use instanceDefinitionId()
    AcDbObjectId instanceBlockId() const;

    // returns the objectId of the BlockReference or 3dSolid described by this BrxComponentInstance object
    AcDbObjectId entityId() const;

    // returns the objectId of the BlockReference described by this BrxComponentInstance object
    // deprecated, use entityId()
    AcDbObjectId blockReferenceId() const;

    // returns the name of the BrxComponentInstance object
    const ACHAR* name() const;

    // returns whether the BlockReference associated with this BrxComponentInstance is visible or not
    bool isVisible() const;

    // returns if this instance is frozen or shouldn't be visible as an instance
    bool isFrozen() const;

    // returns whether some of component properties (set for component definition) have been overridden for this instance
    bool hasOverriddenProperties() const;

    // retrieves a list of names of all the categories (property sets) applicable to this instance, i.e. all the
    // categories assigned to the instance and all not per instance categories
    bool getAllApplicableCategories(AcStringArray& aCategoryNames) const;

    // sets the name of this BrxComponentInstance
    Acad::ErrorStatus setName(const ACHAR* componentName);

    //assigns the passed per-instance category (property set) for this instance (i.e., makes this property set)
    Acad::ErrorStatus assignPropertySet(const ACHAR* categoryName);

    // retrieves the BrxComponentInstance for the specified BlockReference or 3dSolid
    static BrxComponentInstance getComponentInstance(const AcDbObjectId& entityId);

private:
    BrxComponentInstanceImp* m_pBrxImp;
};

#endif // _AcComponents_h_Included
