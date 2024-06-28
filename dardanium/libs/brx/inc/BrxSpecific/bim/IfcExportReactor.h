// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

// BRX API for BricsCAD BIM functionality + interfaces
// IFC Export reactor (customising the IFC export)

#include "Misc/MiscGlobal.h"
#include "Misc/AcString.h"
#include "AcGe/AcGePoint2d.h"
#include "AcGe/AcGePoint3d.h"
#include "AcGe/AcGeVector2d.h"
#include "AcGe/AcGeVector3d.h"
#include "AcGe/AcGeMatrix2d.h"
#include "AcGe/AcGeMatrix3d.h"
#include "AcDb/AcDbObjectId.h"
#include "AcDb/AcDbDatabase.h"
#include "AcDb/AcDbEntity.h"
#include "AcDb/AcDb3dSolid.h"

#include "BrxSpecific/bim/BimDefs.h"

#ifndef BRX_API  // only include for client builds
  #include "BrxSpecific/bim/IfcDefs.h"
#else
  #include "Ice/API/IfcApi.h"
#endif


namespace BimApi
{

// structure to collect all main project/header data of an IFC file
struct BimIfcProjectData
{
    struct Project     { AcString name;
                         AcString description;
                         AcString phase;
                         double northAngle; } project;

    struct Author      { AcString givenName;
                         AcString familyName;
                         AcString organization; } author;

    struct Application { AcString fullName;
                         AcString identifier;
                         AcString version;
                         AcString developer;    } application;

    struct Site        { AcString name;
                         AcString description;
                         double latitude = 0.0;   // interval ( -90, +90)
                         double longitude = 0.0;  // interval (-180,+180)
                         double elevation = 0.0;
                         AcString landTitleNumber;
                         AcString internalLocation;
                         AcString postalBox;
                         AcString town;
                         AcString region;
                         AcString postalCode;
                         AcString country;
                         AcString adressLines;
                         double buildableArea = 0.0;
                         double totalArea = 0.0;
                         double buildingHeightLimit = 0.0; } site;
};

// extra options to fine-tune IFC export; can be derived from in BRX applications
class BRX_IMPORTEXPORT BrxIfcExportOptions
{
    class BrxIfcExportOptionsImpl* m_pImpl = nullptr;

public:
    enum EModelViewDefType
    {
        eNotSet = 0,
        eReference = 1,
        eDesignTransfer = 2,
    };

public:    
    BrxIfcExportOptions();
    BrxIfcExportOptions(const BrxIfcExportOptions& other);
    virtual ~BrxIfcExportOptions();

    virtual BrxIfcExportOptions& operator=(const BrxIfcExportOptions& other);

    virtual bool exportBaseQuantities() const;
    virtual void setExportBaseQuantities(bool bOn);

    virtual bool exportElementsOnFrozenAndHiddenLayer() const;
    virtual void setExportElementsOnFrozenAndHiddenLayer(bool bOn);

    virtual bool explodeExternalReferences() const;
    virtual void setExplodeExternalReferences(bool bOn);

    virtual bool exportMultiPlyElementsAsAggregated() const;
    virtual void setExportMultiPlyElementsAsAggregated(bool bOn);

    virtual AcDbObjectIdArray objectsToExport() const;
    // Specify objects to be exported. Objects must belong to model space block.
    virtual void setObjectsToExport(const AcDbObjectIdArray& arObjectsForExport);

    virtual AcDbFullSubentPathArray nestedObjectsToExport() const;
    // Specify nested objects to be exported.
    virtual void setNestedObjectsToExport(const AcDbFullSubentPathArray& arObjectsForExport);

    Ice::EIfcSchemaId ifcVersion() const;
    void setIfcVersion(Ice::EIfcSchemaId eSchemaId);

    EModelViewDefType mvdType() const;
    void setMvdType(EModelViewDefType eType);
};

// exports the modelspace of the specified drawing as IFC file;
// 'pOptions = nullptr' means : default behaviour
BRX_IMPORTEXPORT BimApi::ResultStatus exportIfcFile(const AcApDocument* pDoc, const ACHAR* szFilename, const BrxIfcExportOptions* pOptions = nullptr);

} // namespace


// BIM IFC Export reactor : allows client applications to participate in IFC export process
// BimIfcExportReactorInstance is the "core reactor", which will handle the export reactor events;
// can be specific for IFC2x3 resp. IFC4, if needed (then referring to include files from
// "BrxSpecific/bim/ifc/IFC2X3" resp. "BrxSpecific/bim/ifc/IFC4", if low-level Ice/Ifc access
// is required), but can also be a unified instance serving IFC2x3 IFC4 and IFC4x1 standards;

class BRX_IMPORTEXPORT BimIfcExportReactorInstance
{
public:
    BimIfcExportReactorInstance() {};
    virtual ~BimIfcExportReactorInstance() {};
    /////////////////////
    // Utility functions

    // gives free and full access to the IfcModel constructed in memory; return value
    // is *ONLY* guaranteed to be valid during execution of the reactor events !
    // warning : changing the pointer structure might lead to inconsistent IFC files;
    // changing labels or numbers within an IfcEntity can be considered safe

    class Context
    {
    public:
        Ice::IfcApi::Model* ifcModel();

        // returns the actual database used for the IFC Export
        // ! NOTE ! this function can only be called during a reactor callback !
        AcDbDatabase* database();

        // returns the existing IfcProduct (if any) for specified entity, or sub-entity
        // ! NOTE ! this function can only be called during a reactor callback !
        Ice::IfcApi::Entity getProduct(const AcDbObjectId& id);
        Ice::IfcApi::Entity getProduct(const AcDbFullSubentPath& idSubent);

        /////////////////////
        // Utility setter methods: the following methods fully set the relevant data in
        // the IfcModel for the given object

        // sets all data on the IfcRoot level for any object derived from IfcRoot;
        // the parameters should observe the following:
        // 
        // - no name/description is set in case empty strings are provided (default)
        // - guid should be either a GUID in enclosed hexadecimal notation,
        //   e.g. "{3F2504E0-4F89-41D3-9A0C-0305E82C3301}" or an empty string (default),
        //   in which case a new random GUID is created
        // - pHist should either point to an already created IfcOwnerHistory in the IfcModel
        //   or be nullptr (default) in which case the history of the IfcProject is used
        // ! NOTE ! this function can only be called during a reactor callback !
        bool setIfcRootData(Ice::IfcApi::Entity& ifcObject,
            const ACHAR* name = nullptr,  // default: no name set
            const ACHAR* description = nullptr,  // default: no description set
            const ACHAR* guid = nullptr,  // default: a new random guid
            Ice::IfcApi::Entity* pHist = nullptr); // default: history of the IfcProject

        // creates and sets all location dependent data for an IfcElement
        // (IfcObjectPlacement, IfcRelContainedInSpatialStructure) while creating the
        // necessary IfcSpatialStructureElements (and the corresponding IfcRelAggregates)
        // 
        // - clients have to choose whether they want to set the location relative to
        //   WCS or to a BricsCAD BIM building/story; the specified relativeCoordSys
        //   is always relative to this choice
        // 
        // - when using BricsCAD BIM building/stories, clients can either specify the
        //   AcDbEntity (with the location attached; if none, location is set relative
        //   to WCS) or the name of the BricsCAD BIM building/story ('false' is returned
        //   in case of a non-existing building/story name)
        //
        // ! NOTE ! these functions can only be called during a reactor callback !

        bool setLocationRelToWCS(Ice::IfcApi::Entity& ifcProduct, const AcGeMatrix3d* relativeCoordSys = nullptr);

        bool setLocationRelToAssignedSpatialLocation(Ice::IfcApi::Entity& ifcElement,
            const AcDbEntity* correspondingEntity,
            const AcGeMatrix3d* relativeCoordSys = nullptr);

        bool setLocationRelToBuilding(Ice::IfcApi::Entity& ifcElement, const ACHAR* buildingName,
            const AcGeMatrix3d* relativeCoordSys = nullptr);

        bool setLocationRelToStory(Ice::IfcApi::Entity& ifcElement, const ACHAR* buildingName,
            const ACHAR* storyName, const AcGeMatrix3d* relativeCoordSys = nullptr);

        // creates and sets a complete product representation for the given IfcProduct
        // 
        // - if the client wants their IfcProduct to have an ObjectPlacement, this
        //   should be set first; otherwise geometry coordinates are relative to WCS
        // - assumes entity to be representable as extruded area solid (prisms and cylinders),
        //   clipped extruded area solid (polyhedral solids) or BREP (any solid or surface);
        //   returns 'false' otherwise
        // - for extruded area solids: in case of multiple representations, the representation
        //   with the extrusion direction making the smallest angle with the input vector will be used
        // - for clipped extruded area solids: the extrusion direction will always be
        //   equal to the input vector;
        // 
        // ! NOTE ! these functions can only be called during a reactor callback !

        bool setRepresentationAsExtrudedAreaSolid(Ice::IfcApi::Entity& ifcProduct,
            const AcDb3dSolid* correspondingSolid,
            const AcGeVector3d& preferredSweepingDirection = AcGeVector3d::kZAxis);

        bool setRepresentationAsClippedExtrudedAreaSolid(Ice::IfcApi::Entity& ifcProduct,
            const AcDb3dSolid* correspondingSolid,
            const AcGeVector3d& extrusionDirection = AcGeVector3d::kZAxis);

        bool setRepresentationAsBrep(Ice::IfcApi::Entity& ifcProduct, const AcDbEntity* correspondingEntity);

        // creates and sets the associated material for the IfcObject from a BricsCAD BIM Composition
        //
        // - when using BricsCAD BIM compositions, clients can specify the corresponding
        //   entity (with the composition attached); if no material is associated or the
        //   name of the BricsCAD BIM composition does not exist, 'false' is returned;
        //   the thickness of the variable layer (if there is one) needs to be specified
        // 
        // ! NOTE ! these functions can only be called during a reactor callback !

        bool setMaterialToAssignedComposition(Ice::IfcApi::Entity& ifcObject, const AcDbEntity* correspondingEntity,
            double thicknessVariableLayer = 0.0);

        bool setMaterialToComposition(Ice::IfcApi::Entity& ifcObject, const ACHAR* compositionName,
            double thicknessVariableLayer = 0.0);

        /////////////////////
        // Utility getter methods: the following methods
        // - provide caching for common data types (e.g. multi-referenced points only appear once in IFC file)
        // - create all the necessary IfcObjects in the IfcModel in memory (both the requested class
        //   and any IfcObject it depends on)
        // - return a pointer to the created instance in the IfcModel (or nullptr in case of an error)

        // creates an IfcAxis2Placement object and all objects that are referred to.
        // - where possible, earlier created objects in the IfcModel are used
        // - the CoordSystem needs to be a orthogonal right-handed coordinate system
        // - in the 2d-case, the origin needs to be in the xy-plane and
        //   the Coordsystem.zDir needs to be equal to OdGeVector3d::kZAxis
        // - returns a pointer to the (possibly previously) created Axis2Placement object
        //   in case of success, nullptr otherwise
        //
        // ! NOTE ! these functions can only be called during a reactor callback !

        Ice::IfcApi::Entity getAxis2Placement2D(const AcGeMatrix2d& coordSystem) const;
        Ice::IfcApi::Entity getAxis2Placement3D(const AcGeMatrix3d& coordSystem) const;

        // creates the point/direction in case it doesn't exist yet in the IfcModel;
        // returns a pointer to the (possibly earlier created) point/vector
        //
        // ! NOTE ! these functions can only be called during a reactor callback !

        Ice::IfcApi::Entity  getCartesianPoint2D(const AcGePoint2d& pt) const;
        Ice::IfcApi::Entity  getCartesianPoint3D(const AcGePoint3d& pt) const;
        Ice::IfcApi::Entity  getDirection2D(const AcGeVector2d& vec) const;
        Ice::IfcApi::Entity  getDirection3D(const AcGeVector3d& vec) const;

        class Impl;                      // internal use only !
        Context(Impl* p) : m_pImpl(p) {} // internal use only !
    private:
        Impl* m_pImpl;                   // internal use only !
    };
    //////////////////////////////////////////////////////////////////////////////////////
    // reactor events/callbacks, allow client application to intercept + adjust IFC export
    //////////////////////////////////////////////////////////////////////////////////////

    // this function is called at the beginning of the export and can be used to set
    // the general project data to be included in the IFC file
    virtual void adjustProjectData(Context& context, BimApi::BimIfcProjectData& projectData) {};

    // this function is called once after the base IfcModel is set up in memory,
    // but before a full iteration over the entities in model space is initiated;
    // client applications can (re-)initialise their own data management here
    virtual void onBeginIfcModelSetup(Context& context) {};

    // this function is called on each entity in model space during IFC model setup
    // -> if the reactor returns a pointer to a valid product in the IfcModel, the
    //    default BricsCAD BIM export of this entity is skipped
    // -> if a nullptr is returned, the entity is exported by default BricsCAD BIM export
    virtual Ice::IfcApi::Entity onEntity(Context& context, AcDbEntity* pEntity) { return Ice::IfcApi::Entity::s_null; };

    // this function is called once after the full IfcModel is constructed in memory;
    // at this time, the IfcModel is fully initialised, but not yet filed to disk file;
    // therefore, client applications can provide some final adjustments to the IfcModel;
    // additionally, client applications can reset their own data management here
    virtual void onEndIfcModelSetup(Context& context) {};

    // this function is called on each entity in model space after BricsCAD exported this entity.
    //void onEntityConstructed(Ice::IfcApi::Entity& contructedEntity, AcDbEntity* pSourceBCEntity);
    virtual void onEntityConstructed(Ice::IfcApi::Entity& contructedEntity, AcDbEntity* pSourceBCEntity) {};
};

class BRX_IMPORTEXPORT BimIfcExportReactor
{
public:
    BimIfcExportReactor();
    virtual ~BimIfcExportReactor();

    // attaches / removes this IFC Export Reactor to / from BIM host system
    bool attachReactor();
    bool detachReactor();

    // depending on the IFC version, this reactor object is asked for a version-specific event handler;
    // if no low-level Ice:: namespace functions are needed, the event handler could be the same;
    // this reactor remains the owner of the returned 'BimIfcExportReactorInstance' instance, it is not
    // automatically deleted by BRX or BIM/IFC core !
    // BRX client applications can determine the IFC version based on these callback functions
    virtual BimIfcExportReactorInstance* getIfcReactorInstance(Ice::EIfcSchemaId schema) = 0;

    // clients should pick a unique GUID and hard-code it in their application.
    // BricsCAD will internally use this GUID to identify the reactor & application
    // across sessions, releases and different third party applications
    // notation : enclosed hexadecimal (e.g. "{3F2504E0-4F89-41D3-9A0C-0305E82C3301}")
    virtual const ACHAR* GUID() const = 0;

    // the display name will be used in the user interface for users to identify/enable/
    // disable/prioritize your application
    virtual const ACHAR* displayName() const = 0;

private:
    class Impl;               // internal use only !
    Impl* m_pImpl = nullptr;

    BimIfcExportReactor(const BimIfcExportReactor& other) = delete;
    BimIfcExportReactor& operator=(const BimIfcExportReactor& other) = delete;
};
