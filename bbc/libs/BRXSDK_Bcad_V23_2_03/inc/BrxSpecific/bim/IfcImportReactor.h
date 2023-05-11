// Copyright (C) Menhirs NV. All rights reserved.

// IfcImportReactor.h
// BRX API for BricsCAD BIM functionality + interfaces

// IFC Import reactor (customising the IFC import)

//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH

#pragma once

#include "Misc/MiscGlobal.h"
#include "AcGe/AcGePoint3d.h"
#include "AcGe/AcGeMatrix3d.h"
#include "AcDb/AcDbDatabase.h"
#include "AcDb/AcDbEntity.h"

#include "BrxSpecific/bim/BimDefs.h"
#include "BrxSpecific/bim/BuildingElements.h"

#ifndef BRX_API  // only include for client builds
  #include "BrxSpecific/bim/IfcDefs.h"
#else
  #include "Ice/API/IfcApi.h"
#endif

class BrxIfcTranslatorOptions;

namespace BimApi
{

enum EIfcImportModelOrigin
{
    eIfcGlobalOrigin    = 0,  // BricsCAD WCS matches IFC Global Coordinate system
    eIfcSiteLocation    = 1,  // BricsCAD WCS matches IFC Site Location 
    eIfcProjectLocation = 2,  // BricsCAD WCS matches IFC Project Location 
};

// extra options to fine-tune IFC import; can be derived from in BRX applications
class BRX_IMPORTEXPORT BrxIfcImportOptions
{
    class BrxIfcImportOptionsImpl* m_pImpl = nullptr;

public:    
    BrxIfcImportOptions();
    virtual ~BrxIfcImportOptions();

    // for internal purpose
    BrxIfcImportOptionsImpl* getImpl() const { return m_pImpl; };

    // defines whether BIM definitions are imported or not
    virtual bool importBimData() const;
    virtual void setImportBimData(bool bOn);

    // defines whether IFC "Space" definitions are imported or not
    virtual bool importIfcSpace() const;
    virtual void setImportIfcSpace(bool bOn);

    // defines whether IFC Parametric Component definitions are imported or not
    virtual bool importParametricComponents() const;
    virtual void setImportParametricComponents(bool bOn);

    // defines whether Project Structures are imported as XRefs or directly into target database
    virtual bool importIfcProjectStructureAsXrefs() const;
    virtual void setImportIfcProjectStructureAsXrefs(bool bOn);

    // defines whether BRep objects are imported as meshes or 3dSolids
    virtual bool importBrepGeometryAsMeshes() const;
    virtual void setImportBrepGeometryAsMeshes(bool bOn);

    // defines whether IFC model is located at original base point or not (see EIfcImportModelOrigin)
    virtual EIfcImportModelOrigin importModelOrigin() const;
    virtual void setImportModelOrigin(EIfcImportModelOrigin mode);
};

// imports the the specified database as IFC file;
// using 'pOptions = nullptr' means : default behaviour
BRX_IMPORTEXPORT BimApi::ResultStatus importIfcFile(AcDbDatabase* pDb, const ACHAR* szFilename, const BrxIfcImportOptions* pOptions = nullptr);

} // namespace


// BIM IFC Import reactor : allows client applications to participate in IFC import process

class BRX_IMPORTEXPORT BimIfcImportInfo
{
public:
    BimIfcImportInfo();
    BimIfcImportInfo(BrxIfcTranslatorOptions* opts, Ice::IfcApi::Header* header);
    ~BimIfcImportInfo() {};

    AcString fileName() const;
    AcString timeStamp() const;
    AcString author() const;
    AcString organization() const;
    AcString preprocessorVersion() const;
    AcString originatingSystem() const;
    AcString authorization() const;

    bool importBimData() const;
    bool importIfcSpace() const;
    bool importParametricComponents() const;
    bool importIfcProjectStructureAsXrefs() const;
    bool importBrepGeometryAsMeshes() const;

private:
    class Impl;
    Impl* m_pImpl = nullptr;
};

class BRX_IMPORTEXPORT BimIfcImportReactorInstance
{
public:
    BimIfcImportReactorInstance() {};
    virtual ~BimIfcImportReactorInstance() {};

public:
    // Context is the model specific object. Contains utility functions.
    class BRX_IMPORTEXPORT Context
    {
    public:
        // Utility functions
        // gives free and full access to the IfcModel in memory; return value
        // is *ONLY* guaranteed to be valid during execution of the reactor events !
        // ! NOTE ! this function can only be called during a reactor callback !
        Ice::IfcApi::Model* ifcModel();

        // returns the actual database used for the IFC Export
        // ! NOTE ! this function can only be called during a reactor callback !
        AcDbDatabase* database();

        // returns an AcDbEntity* which was created from Ice::IfcApi::Entity;
        // Layer and color (if defined) are assigned to result entity
        AcDbEntity* createDefaultRepresentation(const Ice::IfcApi::Entity& entity,
            bool isParent, const Ice::IfcApi::Entity& parent);

        // returns an AcDbEntity* which was created from IfcRepresentationItem;
        // Layer and color (if defined) are assigned to result entity
        AcDbEntity* createRepresentationFromItem(const Ice::IfcApi::Entity& entity);

        // converts an Ice::IfcApi::Entity representing an IfcCartesianPoint to AcGePoint3d
        AcGePoint3d createPoint(const Ice::IfcApi::Entity& point);

        // returns the local coordinate system of the product, in relation to the WCS of the database
        AcGeMatrix3d getLocalPlacement(const Ice::IfcApi::Entity& localPlacementId);

        // return an array of AcDbEntity, representing an IFC "Swept Area" object
        AcDbEntityPtrArray createSweptArea(const Ice::IfcApi::Entity& sweptArea);

        /* TODO : requires BrxBimSpatialLocation to be extended for "Site" spatial location
        // returns the spatial location (either a Building, Story, or Site) constructed from
        // IfcSpatialStructureElement. If IfcSpatialStructureElement is not IfcSite, IfcBuilding,
        // or IfcBuildingStorey, an empty pointer is returned.
        bool getSpatialStructure(BrxBimSpatialLocation& bimSpatialLocation, const Ice::IfcApi::Entity& spatialStructureId);
        */

        // Initialize AcDbEntity with imported entity obtained from ifcEntity,
        // if native import was used. Returns true if successful, false otherwise.
        bool getEntity(AcDbEntity*& pEntity, const Ice::IfcApi::Entity& ifcEntity);

        // Initialize AcDbObjectId with imported entity id obtained from ifcEntity,
        // if native import was used. Returns true if successful, false otherwise.
        // Should be called only inside 'beforeCompletion()' function, as the DB entity is NDBR before
        bool getEntity(AcDbObjectId& objId, const Ice::IfcApi::Entity& ifcEntity);

        // Unit Conversion factors from measuring system defined in IfcGeometricRepresentationContext
        // to current drawing
        double angleConversionFactor();
        double areaConversionFactor();
        double lengthConversionFactor();
        double volumeConversionFactor();

        // returns the IfcGeometricRepresentationContext.Precision, if defined; 1e-8 otherwise
        double precision();

        class Impl;                               // internal use only !
        Context(Impl* pImpl) : m_pImpl(pImpl) {}; // internal use only !
    private: 
        Impl* m_pImpl = nullptr;                  // internal use only !
    };

    //////////////////////////////////////////////////////////////////////////////////////
    // reactor events/callbacks, allow client application to intercept + adjust IFC import
    //////////////////////////////////////////////////////////////////////////////////////

    // called at the beginning of IFC import process; intended to allow synchronisation and
    // housekeeping for applications
    virtual void onStart(BimIfcImportReactorInstance::Context& context, const Ice::IfcApi::Entity& project, const BimIfcImportInfo& info) {};

    // called when the specified IFC entity is about to be processed;
    // 'isParent' indicates whether 'entity' is a parent or child object
    // 'parentEntity' specifies the associated parent object, if applicable
    // return 'true' if the IFC entity is handled by application code;
    // return 'false' if not handled, and IFC core shall continue processing this IFC object
    virtual bool onIfcProduct(BimIfcImportReactorInstance::Context& context, const Ice::IfcApi::Entity& entity, bool isParent, const Ice::IfcApi::Entity& parentEntity) { return false; };

    // called at the end of IFC import processing; intended to allow synchronisation and
    // housekeeping for applications;
    // 'success' indicates whether import finally succeeded
    virtual void beforeCompletion(BimIfcImportReactorInstance::Context& context, bool success) {};

    // returns whether IFC class is currently fully supported in BricsCAD IFC import
    static bool isFullySupported(const Ice::IfcApi::EntityDesc& desc, Ice::EIfcSchemaId schema);

    // this function called after importing of entity is finished. Just created entityes passed as argument.
    virtual void onIfcProductImported(const Ice::IfcApi::Entity& sourceEntity, bool isParent, const Ice::IfcApi::Entity& sourceParentEntity, AcDbEntityPtrArray& createdAcEntites, const AcGeMatrix3d* constructedAcEntityTransformation) {};

};

class BRX_IMPORTEXPORT BimIfcImportReactor
{
public:
    BimIfcImportReactor();
    virtual ~BimIfcImportReactor();

    // attaches / removes this IFC Import Reactor to / from BIM host system
    bool attachReactor();
    bool detachReactor();

    // depending on the IFC version, this reactor object is asked for a version-specific event handler;
    // if no low-level Ice:: namespace functions are needed, the event handler could be the same;
    // this reactor remains the owner of the returned 'BimIfcImportReactorInstance' instance, it is not
    // automatically deleted by BRX or BIM/IFC core !
    // BRX client applications can determine the IFC version based on these callback functions
    virtual BimIfcImportReactorInstance* getIfcReactorInstance(Ice::EIfcSchemaId schema) = 0;

    // clients should pick a unique GUID and hard-code it in their application.
    // BricsCAD will internally use this GUID to identify the reactor & application
    // across sessions, releases and different third party applications
    // notation : enclosed hexadecimal (e.g. "{3F2504E0-4F89-41D3-9A0C-0305E82C3301}")
    virtual const ACHAR* GUID() const = 0;

    // the display name will be used in the user interface for users to identify/enable/
    // disable/prioritize your application
    virtual const ACHAR* displayName() const = 0;

private:
    class Impl;
    Impl* m_pImpl = nullptr;  // internal use only !

    BimIfcImportReactor(const BimIfcImportReactor& other) = delete;
    BimIfcImportReactor& operator=(const BimIfcImportReactor& other) = delete;
};
