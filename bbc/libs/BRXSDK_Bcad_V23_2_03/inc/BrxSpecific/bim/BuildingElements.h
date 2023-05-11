// Copyright (C) Menhirs NV. All rights reserved.

// BuildingElements.h
// BRX API for BricsCAD BIM functionality + interfaces

// BIM building elements, compositions and spatial locations

//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH

#pragma once
                 
#include <memory>  // std::shared_ptr
#include <vector>
#include <map>
#include <set>

#include "Misc/MiscGlobal.h"
#include "Misc/AcString.h"
#include "Misc/AcValue.h"
#include "Misc/AcArray.h"
#include "AcDb/AcDbObjectId.h"
#include "AcDb/AcDbDatabase.h"
#include "AcDb/AcDbFullSubentPath.h"
#include "AcGe/AcGeCurve3d.h"
#include "AcGe/AcGePoint3d.h"
#include "BrxSpecific/AcSharedPtr.h"
#include "BrxSpecific/bim/BimDefs.h"


class AcDb3dSolid;

// shared pointer holding an 'AcGeCurve3d*' instance, to allow automatic destruction
typedef AcSharedPtr<AcGeCurve3d>  AcGeCurve3dPtr;
typedef AcArray<AcGeCurve3dPtr, AcArrayObjectCopyReallocator<AcGeCurve3dPtr> >  AcGeCurve3dPtrArray;


/////////////////////////////////////////////////////////////////////////////
// BIM data objects
// class forwards
class BrxBimSpatialLocation;
class BrxBimStory;
class BrxBimBuilding;
class BrxBimRoom;
class BrxBimComposition;
class BrxBimPly;
class BrxBimMaterial;

namespace BimApi
{

///////////////////////////////////////////////////////////////////////////////

// BIM object types
enum BimObjectType
{
    eBimUnknownObject = 0,
    eBimSpatialLocation,
    eBimStory,
    eBimBuilding,
    eBimComposition,
    eBimRoomObject,
    eBimPly,
    eBimMaterial,
};

// BIM building element types
enum BimElementType : int
{
    eBimGenericBuildingElt         = 0,
    eBimSection                    = 1,
    eBimWall                       = 2,
    eBimWindow                     = 3,
    eBimDoor                       = 4,
    eBimColumn                     = 5,
    eBimSlab                       = 6,
    eBimBeam                       = 7,
    eBimRoom                       = 8,
    eBimCovering                   = 9,
    eBimCurtainWall                = 10,
    eBimFlowTerminal               = 11,
    eBimFurnishingElement          = 12,
    eBimMember                     = 13,
    eBimPile                       = 14,
    eBimRailing                    = 15,
    eBimRamp                       = 16,
    eBimRampFlight                 = 17,
    eBimRoof                       = 18,
    eBimSite                       = 19,
    eBimStair                      = 20,
    eBimStairFlight                = 21,
    eBimFooting                    = 22,
    //eBimSpaceHeater              = 23,
    //eBimLightingFixture          = 24,
    //eBimSanitaryTerminal         = 25,
    eBimXReference                 = 26,
    eBimDistributionControlElement = 27,
    eBimDistributionPort           = 28,
    eBimDistributionFlowElement    = 29,
    eBimDistributionChamberElement = 30,
    eBimEnergyConversionDevice     = 31,
    eBimFlowFitting                = 32,
    eBimFlowController             = 33,
    eBimFlowMovingDevice           = 34,
    eBimFlowSegment                = 35,
    eBimFlowStorageDevice          = 36,
    eBimFlowTreatmentDevice        = 37,
    eBimReinforcingBar             = 38,
    eBimReinforcingMesh            = 39,
    eBimTendon                     = 40,
    eBimTendonAnchor               = 41,
    eBimPlate                      = 42,
    eBimDiscreteAccessory          = 43,
    eBimFastener                   = 44,
    eBimMechanicalFastener         = 45,
    eBimSchedule                   = 46,
    eBimGridAxis                   = 47,
    eBimGrid                       = 48,
    eBimFlowConnectionPoint        = 49,
    eBimOpening                    = 50,
    eBimAnnotation                 = 51,
    // V21
    eBimSpatialElementType         = 52,
    eBimSpaceType                  = 53,
    eBimBuildingType               = 54,
    eBimStoryType                  = 55,
    eBimViewportType               = 56,
    //
    eBimProduct                    = 57, // V23
    eNoBuildingElement, // end of list
};

typedef AcArray< BimElementType,    AcArrayMemCopyReallocator<BimElementType> >       BimTypes;
typedef AcArray< BrxBimStory,       AcArrayObjectCopyReallocator<BrxBimStory> >       BimStories;
typedef AcArray< BrxBimBuilding,    AcArrayObjectCopyReallocator<BrxBimBuilding> >    BimBuildings;
typedef AcArray< BrxBimComposition, AcArrayObjectCopyReallocator<BrxBimComposition> > BimCompositions;
typedef AcArray< BrxBimMaterial,    AcArrayObjectCopyReallocator<BrxBimMaterial> >    BimMaterials;
typedef AcArray< BrxBimPly,         AcArrayObjectCopyReallocator<BrxBimPly> >         BimPlies;

}; // namespace BimApi


///////////////////////////////////////////////////////////////////////////////
// BrxBimPolicies, to define particular BRX BIM API behaviour
class BrxBimPolicies
{
public:
    enum EPolicyOptions
    {
        eNothing = 0,

        // option defines whether modified BIM objects are immediately saved to database resp library;
        // preset : as 'instant save' true
        eInstantSave,
    };

    // enable or disable the specified policy option
    static void setPolicy(EPolicyOptions option, bool enable);

    // returns the enabled/disabled status of the specified policy option
    static bool getPolicy(EPolicyOptions option);
};

///////////////////////////////////////////////////////////////////////////////
// BIM core classes to handle Buildings, Stories (both SpatialLocations), MaterialCompositions, Rooms

// base class for all BIM related classes
class BRX_IMPORTEXPORT BrxBimObject
{
    friend class BrxBimBase;
    friend class BrxBimSpatialLocation;
    friend class BrxBimStory;
    friend class BrxBimBuilding;
    friend class BrxBimComposition;
    friend class BrxBimRoom;
    friend class BrxBimMaterial;
    friend class BrxBimPly;
    friend class BrxBimSpace;

public:
    virtual ~BrxBimObject();

    // returns the type identification as enum and string
    virtual BimApi::BimObjectType typeDesc() const = 0;
    virtual const ACHAR* typeName() const = 0;

    virtual bool isNull() const = 0;
    virtual void setNull() = 0;

    virtual AcString name() const = 0;
    virtual AcString description() const = 0;

    virtual BimApi::ResultStatus setName(const ACHAR* szNewName) const = 0;
    virtual BimApi::ResultStatus setDescription(const ACHAR* szInfo) const = 0;

protected:
    BrxBimObject();
    BrxBimObject(const BrxBimObject& other);
    BrxBimObject& operator=(const BrxBimObject& other);

private:
    class BrxBimImplBase* m_pImpl = nullptr;  // internal use only !
};


///////////////////////////////////////////////////////////////////////////////
// BrxBimSpatialLocation : BIM spatial locations (buildings and stories)
//
// Class which holds a Building or Story object in the BIM Project Database, representing
// the spatial location of a BIM Building Element (an AcDbEntity classified as a certain BIM object).
//
// - all spatial locations are stored in the 'Project' database (embedded in the AcDbDatabase)
// - each AcDbDatabase has a default Project and default Site to which all Buildings are related
// - each Story is related to a Building
// - each BIM Building Element can have only one SpatialLocation (Building or Story) assigned (in case
//   the AcDbEntity is not yet BIM-classified, it is classified as GenericBuildingElt)
// - can be converted/casted to either a Building or a Story
//
// NOTE : string name are treated *CASE-SENSITIVE*; be careful with spelling (to be improved in the future)

class BRX_IMPORTEXPORT BrxBimSpatialLocation : public BrxBimObject
{
public:
    BrxBimSpatialLocation();
    virtual ~BrxBimSpatialLocation();

    BrxBimSpatialLocation(const BrxBimSpatialLocation& other);
    BrxBimSpatialLocation& operator=(const BrxBimSpatialLocation& other);

    // upcast ctor + assignment : useful to construct a base-class instance from BrxBimStory
    BrxBimSpatialLocation(const BrxBimStory& story);
    BrxBimSpatialLocation& operator=(const BrxBimStory& story);

    // upcast ctor + assignment : useful to construct a base-class instance from BrxBimBuilding
    BrxBimSpatialLocation(const BrxBimBuilding& building);
    BrxBimSpatialLocation& operator=(const BrxBimBuilding& building);

    virtual bool operator== (const BrxBimSpatialLocation& other) const;
    virtual bool operator!= (const BrxBimSpatialLocation& other) const;

    virtual bool operator== (const BrxBimStory& other) const;
    virtual bool operator!= (const BrxBimStory& other) const;

    virtual bool operator== (const BrxBimBuilding& other) const;
    virtual bool operator!= (const BrxBimBuilding& other) const;

    // returns the type identification as enum and string
    virtual BimApi::BimObjectType typeDesc() const { return BimApi::eBimSpatialLocation; };
    virtual const ACHAR* typeName() const { return _T("BimSpatialLocation"); };

    // returns true if this object does not hold a valid building or valid story (empty object)
    virtual bool isNull() const;
    // sets this object to be empty
    virtual void setNull();

    // returns the name of this SpatialLocation object, or an empty string
    virtual AcString name() const;
    virtual AcString longName() const;

    // sets the name of this SpatialLocation object, returns 'eOk' for success, or an error status
    // if assigning the new name fails or is not appropriate
    virtual BimApi::ResultStatus setName(const ACHAR* szNewName) const;
    virtual BimApi::ResultStatus setLongName(const ACHAR* szLongName) const;

    // returns the description of this SpatialLocation, or an empty string (if the object is empty)
    virtual AcString description() const;

    // sets the description of this SpatialLocation, returns 'eOK' succeeds, or an error status
    virtual BimApi::ResultStatus setDescription(const ACHAR* szInfo) const;

    // returns true if this SpatialLocation object is of *type* 'BrxBimStory', 'BrxBimBuilding', 'BrxBimSite' (can be empty !)
    virtual bool isStory()    const;
    virtual bool isBuilding() const;

    // returns true if this SpatialLocation object *contains* a non-empty object of type 'BrxBimStory' resp. 'BrxBimBuilding'
    virtual bool hasStory()    const;
    virtual bool hasBuilding() const;

    // returns all entities, from specified database, using this SpatialLocation object
    virtual BimApi::ResultStatus assignedObjects(AcDbObjectIdArray& ids, const AcDbDatabase* database) const;

    // assign this SpatialLocation object to specified entity
    // (an unclassified AcDbEntity is treated as a GenericBuildingElt, if the BIM status is queried)
    virtual BimApi::ResultStatus assignToEntity(const AcDbObjectId& id) const;

    //===== static utility functions =====

    // returns the BrxBimSpatialLocation pointer, if 'other' object is of type 'BrxBimSpatialLocation' or derived
    static BrxBimSpatialLocation* cast(const BrxBimObject* other);

    // returns the SpatialLocation object assigned to the specified entity
    static BimApi::ResultStatus assignedSpatialLocation(BrxBimSpatialLocation& spatialLocation, const AcDbObjectId& id);

    // removes any assigned spatial location (Building, Story) from specified entity
    static BimApi::ResultStatus removeSpatialLocationFrom(const AcDbObjectId& id);
};


///////////////////////////////////////////////////////////////////////////////
// BrxBimStory : BIM Story object
//
// Class which holds a Story object in the BIM Project Database.
// - can be converted/casted to a BrxBimSpatialLocation
//
// NOTE : string name are treated *CASE-SENSITIVE*; be careful with spelling (to be improved in the future)

class BRX_IMPORTEXPORT BrxBimStory : public BrxBimSpatialLocation
{
public:
    BrxBimStory();
    virtual ~BrxBimStory();

    BrxBimStory(const BrxBimStory& other);
    BrxBimStory& operator=(const BrxBimStory& other);

    virtual bool operator== (const BrxBimStory& other) const;
    virtual bool operator!= (const BrxBimStory& other) const;

    virtual bool operator== (const BrxBimSpatialLocation& other) const;
    virtual bool operator!= (const BrxBimSpatialLocation& other) const;

    // returns the type identification as enum and string
    virtual BimApi::BimObjectType typeDesc() const { return BimApi::eBimStory; };
    virtual const ACHAR* typeName() const { return _T("BimStory"); };

    // creates a new Story object using given name, within specified building
    virtual BimApi::ResultStatus createStory(const ACHAR* szName, BrxBimBuilding& building);

    // delete this Story object
    virtual BimApi::ResultStatus deleteStory();

    // returns true if this object does not hold a valid Story object (empty object)
    virtual bool isNull() const;
    // sets this Story object to be empty
    virtual void setNull();

    // returns the name of this Story object, or an empty string in case of an error
    virtual AcString name() const;
    virtual AcString longName() const;

    // sets the name of this Story object, returns 'eOk' for success, or an error status
    // if assigning the new name fails or is not appropriate
    virtual BimApi::ResultStatus setName(const ACHAR* szNewName) const;
    virtual BimApi::ResultStatus setLongName(const ACHAR* szLongName) const;

    // returns the description of this Story, or an empty string (if the object is empty)
    virtual AcString description() const;

    // sets the description of this Story, returns 'eOK' succeeds, or an error status
    virtual BimApi::ResultStatus setDescription(const ACHAR* szInfo) const;

    // returns the elevation of this Story object
    virtual double elevation() const;

    // assigned the specified elevation to this Story object
    virtual BimApi::ResultStatus setElevation(double elevation) const;

    // returns the Building object this Story object belongs to (or empty Building object)
    virtual BimApi::ResultStatus getBuilding(BrxBimBuilding& building) const;

    // returns all entities, from specified database, using this Story object
    virtual BimApi::ResultStatus assignedObjects(AcDbObjectIdArray& ids, const AcDbDatabase* database) const;

    // assign this Story object to specified entity
    // (an unclassified AcDbEntity is treated as a GenericBuildingElt, if the BIM status is queried)
    virtual BimApi::ResultStatus assignToEntity(const AcDbObjectId& id) const;

    //===== static utility functions =====

    // returns the Story object pointer, if 'other' object is of type 'BrxBimStory' or derived from it
    static BrxBimStory* cast(const BrxBimObject* other);

    // creates a new Story with given name, for given Building, in specified database
    static BimApi::ResultStatus createStory(BrxBimStory& story, const AcDbDatabase* database, const ACHAR* buildingName, const ACHAR* storyName);

    // deletes the Story with given name, for given Building, in specified database
    static BimApi::ResultStatus deleteStory(const AcDbDatabase* database, const ACHAR* buildingName, const ACHAR* storyName);

    // returns the Story object, using the specified story name, from particular database
    static BimApi::ResultStatus getStory(BrxBimStory& story, const AcDbDatabase* database, const ACHAR* buildingName, const ACHAR* storyName);

    // returns the Story object assigned to specified entity
    static BimApi::ResultStatus assignedStory(BrxBimStory& story, const AcDbObjectId& id);

    // returns the array of all defined Story objects for the given database
    static BimApi::ResultStatus allStories(BimApi::BimStories& stories, const AcDbDatabase* database);
    static BimApi::ResultStatus allStories(AcStringArray& stories, const AcDbDatabase* database);
};


///////////////////////////////////////////////////////////////////////////////
// BrxBimBuilding : BIM Building object
//
// Class which holds a Building object in the BIM Project Database.
// - can be converted/casted to a BrxBimSpatialLocation
//
// NOTE : string name are treated *CASE-SENSITIVE*; be careful with spelling (to be improved in the future)

class BRX_IMPORTEXPORT BrxBimBuilding : public BrxBimSpatialLocation
{
public:
    BrxBimBuilding();
    virtual ~BrxBimBuilding();

    BrxBimBuilding(const BrxBimBuilding& other);
    BrxBimBuilding& operator=(const BrxBimBuilding& other);

    virtual bool operator== (const BrxBimBuilding& other) const;
    virtual bool operator!= (const BrxBimBuilding& other) const;

    virtual bool operator== (const BrxBimSpatialLocation& other) const;
    virtual bool operator!= (const BrxBimSpatialLocation& other) const;

    // returns the type identification as enum and string
    virtual BimApi::BimObjectType typeDesc() const { return BimApi::eBimBuilding; };
    virtual const ACHAR* typeName() const { return _T("BimBuilding"); };

    // creates a new Building object using given name, within specified database
    virtual BimApi::ResultStatus createBuilding(const ACHAR* szName, const AcDbDatabase* database);

    // delete this Building object from specified database
    virtual BimApi::ResultStatus deleteBuilding(const AcDbDatabase* database);

    // returns true if this object does not hold a valid Building object (empty object)
    virtual bool isNull() const;
    // sets this Building object to be empty
    virtual void setNull();

    // creates a new story with given name, inside this Building
    virtual BimApi::ResultStatus createStory(BrxBimStory& story, const ACHAR* storyName) const;

    // deletes the specified story from the Building object
    virtual BimApi::ResultStatus deleteStory(const ACHAR* storyName) const;
    virtual BimApi::ResultStatus deleteStory(BrxBimStory& story) const;

    // returns the name of this Building object, or an empty string in case of an error
    virtual AcString name() const;
    virtual AcString longName() const;

    // sets the name of this BrxBimBuilding object, returns 'eOk' for success, or an error status
    // if assigning the new name fails or is not appropriate
    virtual BimApi::ResultStatus setName(const ACHAR* szNewName) const;
    virtual BimApi::ResultStatus setLongName(const ACHAR* szLongName) const;

    // returns the description of this Building object, or an empty string (if the object is empty)
    virtual AcString description() const;

    // sets the description of this Building object, returns 'eOK' succeeds, or an error status
    virtual BimApi::ResultStatus setDescription(const ACHAR* szInfo) const;

    // returns the Building's story with specified name
    virtual BimApi::ResultStatus getStory(BrxBimStory& story, const ACHAR* storyName) const;

    // returns all Story objects defined for this Building
    virtual BimApi::ResultStatus allStories(BimApi::BimStories& stories) const;
    virtual BimApi::ResultStatus allStories(AcStringArray& stories) const;

    // returns all entities, from specified database, using this Building object
    virtual BimApi::ResultStatus assignedObjects(AcDbObjectIdArray& ids, const AcDbDatabase* database) const;

    // assign this Building object to specified entity
    // (an unclassified AcDbEntity is treated as a GenericBuildingElt, if the BIM status is queried)
    virtual BimApi::ResultStatus assignToEntity(const AcDbObjectId& id) const;

    //===== static utility functions =====

    // returns the Building object pointer, if 'other' object is of type 'BrxBimBuilding' or derived from it
    static BrxBimBuilding* cast(const BrxBimObject* other);

    // creates a new Building with given name, in specified database
    static BimApi::ResultStatus createBuilding(BrxBimBuilding& building, const AcDbDatabase* database, const ACHAR* name);

    // deletes the Building with given name in specified database
    static BimApi::ResultStatus deleteBuilding(const AcDbDatabase* database, const ACHAR* buildingName);

    // returns the Building object assigned to specified entity
    static BimApi::ResultStatus assignedBuilding(BrxBimBuilding& building, const AcDbObjectId& id);

    // returns the Building object, using the specified building name, from particular database
    static BimApi::ResultStatus getBuilding(BrxBimBuilding& building, const AcDbDatabase* database, const ACHAR* buildingName);

    // returns the array of all defined Building objects for the given database
    static BimApi::ResultStatus allBuildings(BimApi::BimBuildings& buildings, const AcDbDatabase* database);
    static BimApi::ResultStatus allBuildings(AcStringArray& buildings, const AcDbDatabase* database);

    // returns the array of all Stories objects for specified Building, for the given database;
    // if no Building is specified, then all Buildings of the database are returned
    static BimApi::ResultStatus allStories(BimApi::BimStories& stories, const AcDbDatabase* database, const ACHAR* building = nullptr);
    static BimApi::ResultStatus allStories(AcStringArray& stories, const AcDbDatabase* database, const ACHAR* building = nullptr);
};


///////////////////////////////////////////////////////////////////////////////
// BrxBimRoom : BIM room object
//
// Class which holds a BIM Room object in the BIM Library
// - all rooms have a database-resident (stored with dwg database) representation
//
// NOTE : string name are treated *CASE-SENSITIVE*; be careful with spelling (to be improved in the future)

// constant room representation names
static const AcString acRoomRepresentationNone(_T("None"));
static const AcString acRoomRepresentationHatch(_T("Hatch"));
static const AcString acRoomRepresentationSolid(_T("Solid"));
static const AcString acRoomRepresentationFootprint(_T("Footprint"));

class BRX_IMPORTEXPORT BrxBimRoom : public BrxBimObject
{
public:
    BrxBimRoom();
    BrxBimRoom(const AcDbObjectId& id);
    BrxBimRoom(const BrxBimRoom& other);
    virtual ~BrxBimRoom();

    virtual BrxBimRoom& operator=(const BrxBimRoom& other);

    virtual bool operator== (const BrxBimRoom& other) const;
    virtual bool operator!= (const BrxBimRoom& other) const;

    // returns the type identification string
    virtual BimApi::BimObjectType typeDesc() const { return BimApi::eBimRoomObject; };
    virtual const ACHAR* typeName() const { return _T("BimRoom"); };

    // verifies whether the specified object is a valid room (in logical context)
    virtual bool isRoomValid() const;

    // Creates this room as associative room. An associative room will have bounding elements
    // associated with the room. Bounding entities are searched around 'insidePoint' in
    // plane 'basePlane';
    // Requires AcDb3dSolid based entities, and the bounding entity / entities must be
    // classified as BimWalls before !
    // NOTE : creating & updating associative rooms only works with the current drawing !
    // NOTE : V21 change - created "room" is now a "space" object, no longer associative !
    //        'basePlane' is ignored in V21 and higher !
    virtual AcDbObjectId createAssociativeRoom(const AcGePoint3d& insidePoint, const AcGePlane& basePlane);

    // Creates this room as non-associative room. A non-associative room do not have bounding elements
    // associated with the room. Accepts object id of the entity (solid, region, or polyline)
    // to be used for room creation.
    // Requires ACIS based entities (AcDb3dSolid, AcDbRegion, or AcDbPolyline, and the bounding
    // entity / entities must be :
    // a) not classified as any BimElementType
    // b) or, must be classified as BimRoom
    // NOTE : creating & updating associative rooms only works with the current drawing !
    // NOTE : V21 change - created "room" is now the input 'entityId', if that can be classified as a "room"
    virtual AcDbObjectId createNonAssociativeRoom(const AcDbObjectId& entityId);

    // Updates the boundaries of this room.
    // NOTE           : creating & updating associative rooms only works with the current drawing !
    // IMPORTANT NOTE : for associative room updates, the display must be in updated state !
    // (as boundary detection uses the display system);
    // if 'updateAssociativeRoom()' fails, please use acedRedraw() or ads_regen() and repeat
    virtual BimApi::ResultStatus updateAssociativeRoom();

    // Verifies whether this room is associative (or not a valid room at all).
    virtual bool isAssociativeRoom() const;

    // Returns the boundary entities, for an associative room (and error status for non-room
    // and non-associative room).
    virtual BimApi::ResultStatus getBoundingElements(AcDbObjectIdArray& boundaryEnts) const;
    virtual BimApi::ResultStatus getOpenings(AcDbObjectIdArray& openingEnts);

    // returns the drawing entity which refers to the specified BrxBimRoom object
    // (only for non-associative rooms);
    // returns kNull for associative rooms
    virtual BimApi::ResultStatus getRoomEntity(AcDbObjectId& refId) const;

    // Retrieves the entity referred to by this room.
    virtual AcDbObjectId getId() const;

    // Assigns the specified entity for this room; returns an error status if 'id' is not a valid room
    virtual BimApi::ResultStatus setId(const AcDbObjectId& id);

    // Returns true if this object does not hold a valid room object (empty object)
    virtual bool isNull() const;
    // sets this room object to be empty
    virtual void setNull();

    // Returns the unique room identification (GUID string).
    virtual AcString roomIdent() const;

    // Returns the GUI name of this room object, or an empty string in case of an error
    // Note : the 'name/roomName' is a user-friendly GUI string, user can change the name by GUI operations !
    //        For unique room identification, use the 'roomIdent()' function.
    virtual AcString name() const;
    virtual AcString roomName() const;
    virtual AcString roomNumber() const;

    // sets the name of this room, returns 'true' for success, or 'false' if assigning
    // the new name fails or is not appropriate
    // Note : the 'name' is a user-friendly GUI string, user can change the name by GUI operations !
    //        For unique room identification, use the 'roomIdent()' function.
    virtual BimApi::ResultStatus setName(const ACHAR* szNewName) const;
    virtual BimApi::ResultStatus setRoomName(const ACHAR* szNewName) const;
    virtual BimApi::ResultStatus setRoomNumber(const ACHAR* szNewNumber) const;

    // returns the description of this room, or an empty string (if the object is empty)
    virtual AcString description() const;

    // sets the description of this room, returns 'eOK' succeeds, or an error status
    virtual BimApi::ResultStatus setDescription(const ACHAR* szInfo) const;

    // returns the area for this room
    virtual BimApi::ResultStatus roomArea(double& area) const;

    // returns and assigns the representation for this room
    // defaults are : acRoomRepresentationNone, acRoomRepresentationHatch, acRoomRepresentationSolid,
    // NOTE : V21 change - the "room representation" is now just a user attribute, no effects to visual display
    virtual BimApi::ResultStatus getRoomRepresentation(AcString& representation) const;
    virtual BimApi::ResultStatus setRoomRepresentation(const ACHAR* representation);

    // returns and assigns the department for this room
    // NOTE : V21 change - the "room department" is now just a user attribute
    virtual BimApi::ResultStatus getRoomDepartment(AcString& department) const;
    virtual BimApi::ResultStatus setRoomDepartment(const ACHAR* department);

    // Assign this room object to the specified story resp. building
    virtual BimApi::ResultStatus assignToStory(const BrxBimStory& story);
    virtual BimApi::ResultStatus assignToBuilding(const BrxBimBuilding& building);

    // Retrieves the Building resp. Story where this room object is assigned to
    virtual BimApi::ResultStatus getAssignedLocation(BrxBimSpatialLocation& location) const;
    virtual BimApi::ResultStatus getAssignedStory(BrxBimStory& story) const;
    virtual BimApi::ResultStatus getAssignedBuilding(BrxBimBuilding& building) const;

    // Remove this room object from any Building and Story where it is assigned to
    virtual BimApi::ResultStatus unassignLocation();

    //===== static utility functions =====

    // verifies whether the specified object is a valid room (in logical context)
    static bool isRoomValid(const AcDbObjectId& id);

    // Creates an associative room, having bounding elements associated with the room.
    // Bounding entities are searched around 'insidePoint' in plane 'basePlane';
    // Requires AcDb3dSolid based entities, and the bounding entity / entities must be
    // classified as BimWalls before !
    // NOTE : creating & updating associative rooms only works with the current drawing !
    static AcDbObjectId buildAssociativeRoom(const AcGePoint3d& insidePoint, const AcGePlane& basePlane);

    // Creates a non-associative room, which does not have bounding elements associated with the room.
    // Accepts object id of the entity (solid, region, or polyline) to be used for room creation.
    // Requires ACIS based entities (AcDb3dSolid, AcDbRegion, or AcDbPolyline, and the bounding
    // entity / entities must be :
    // a) not classified as any BimElementType
    // b) or, must be classified as BimRoom
    static AcDbObjectId buildNonAssociativeRoom(const AcDbObjectId& fromEntity);

    // Assign this room object to the specified story resp. building
    static BimApi::ResultStatus assignToStory(const AcDbObjectId& id, const BrxBimStory& story);
    static BimApi::ResultStatus assignToBuilding(const AcDbObjectId& id, const BrxBimBuilding& building);

    // Retrieves the Building resp. Story where the specified room object is assigned to
    static BimApi::ResultStatus getAssignedLocation(const AcDbObjectId& id, BrxBimSpatialLocation& location);
    static BimApi::ResultStatus getAssignedStory(const AcDbObjectId& id, BrxBimStory& story);
    static BimApi::ResultStatus getAssignedBuilding(const AcDbObjectId& id, BrxBimBuilding& building);

    // Remove the specified room object from any assigned Building or Story
    static BimApi::ResultStatus unassignLocation(const AcDbObjectId& id);

    // Returns all rooms for the specified Building resp. Story for the current drawing
    // (or for specified 'pDb' database)
    static BimApi::ResultStatus getAllRooms(AcDbObjectIdArray& rooms, const AcDbDatabase* pDb = nullptr);
    static BimApi::ResultStatus getAllRooms(AcDbObjectIdArray& rooms, const BrxBimStory&    story,    const AcDbDatabase* pDb = nullptr);
    static BimApi::ResultStatus getAllRooms(AcDbObjectIdArray& rooms, const BrxBimBuilding& building, const AcDbDatabase* pDb = nullptr);

    // Verifies the specified entity whether it is an associative room (or not a valid room at all).
    static bool isAssociativeRoom(const AcDbObjectId& id);

    // Updates the boundaries of the specified room.
    // NOTE           : creating & updating associative rooms only works with the current drawing !
    // IMPORTANT NOTE : for associative room updates, the display must be in updated state !
    // (as boundary detection uses the display system);
    // if 'updateAssociativeRoom()' fails, please use acedRedraw() or ads_regen() and repeat
    static BimApi::ResultStatus updateAssociativeRoom(const AcDbObjectId& id);

    // Returns the boundary entities, for an associative room (and error status for non-room
    // and non-associative room).
    static BimApi::ResultStatus getBoundingElements(const AcDbObjectId& id, AcDbObjectIdArray& boundaryEnts);

    // Returns the boundary entities, for an associative room (and error status for non-room
    // and non-associative room).
    static BimApi::ResultStatus getOpenings(const AcDbObjectId& id, AcDbObjectIdArray& openingEnts);

    // returns the drawing entity which refers to the specified BrxBimRoom object
    // (only for non-associative rooms);
    // returns kNull for associative rooms
    static BimApi::ResultStatus getRoomEntity(const BrxBimRoom& bimRoom, AcDbObjectId& refId);

    // returns the unique room identification (GUID string).
    static AcString roomIdent(const AcDbObjectId& id);

    // returns the GUI name of this room object, or an empty string in case of an error
    // Note : the 'name' is a user-friendly GUI string, user can change the name by GUI operations !
    //        For unique room identification, use the 'roomIdent()' function.
    static AcString roomName(const AcDbObjectId& id);

    // sets the name of this room, returns 'true' for success, or 'false' if assigning
    // the new name fails or is not appropriate
    // Note : the 'name' is a user-friendly GUI string, user can change the name by GUI operations !
    //        For unique room identification, use the 'roomIdent()' function.
    static BimApi::ResultStatus setRoomName(const AcDbObjectId& id, const ACHAR* szNewName);

    // returns the "room number" of this room object, or an empty string in case of an error
    // Note : for unique room identification, use the 'roomIdent()' function.
    static AcString roomNumber(const AcDbObjectId& id);

    // assigns a new "room number" to this room object;
    static BimApi::ResultStatus setRoomNumber(const AcDbObjectId& id, const ACHAR* szNewNumber);

    // gets the description of this room, returns an empty string in case of an error
    static AcString description(const AcDbObjectId& id);

    // gets and sets the description of this room, returns 'eOK' succeeds, or an error status
    static BimApi::ResultStatus setDescription(const AcDbObjectId& id, const ACHAR* szInfo);

    // returns the area for this room
    static BimApi::ResultStatus roomArea(const AcDbObjectId& id, double& area);

    // returns and assigns the representation for the specified room
    // defaults are : acRoomRepresentationNone, acRoomRepresentationHatch, acRoomRepresentationSolid
    // defaults are : acRoomRepresentationNone, acRoomRepresentationHatch, acRoomRepresentationSolid,
    // NOTE : V21 change - the "room representation" is now just a user attribute, no effects to visual display
    static BimApi::ResultStatus getRoomRepresentation(const AcDbObjectId& id, AcString& representation);
    static BimApi::ResultStatus setRoomRepresentation(const AcDbObjectId& id, const ACHAR* representation);

    // returns and assigns the department for the specified room
    // NOTE : V21 change - the "room department" is now just a user attribute
    static BimApi::ResultStatus getRoomDepartment(const AcDbObjectId& id, AcString& department);
    static BimApi::ResultStatus setRoomDepartment(const AcDbObjectId& id, const ACHAR* department);
};


///////////////////////////////////////////////////////////////////////////////
// BrxBimSpace : BIM space support
//
// Set of functions to handle BIM 'Space' objects in the BIM system.
//
// Starting with V21, 'BIM Spaces' will replace the former 'BIM Rooms' concept.
// (but BRX interface tries to keep the 'BIM Rooms' functionality alive as best as possible)
//
// A 'BIM Space' is an entity, representing a space item in the BIM logic.
//
// NOTE : string name are treated *CASE-SENSITIVE*; be careful with spelling (to be improved in the future)

enum class EBimSpaceRepresentation
{
    eSolid     = 0,
    eFootprint = 1,
};

class BRX_IMPORTEXPORT BrxBimSpace
{
public:
    // creates a 'BIM Space' object for the boundaries as found around the 'pickPt';
    // this function always & only works with the actual drawing
    static AcDbObjectId createSpace(const AcGePoint3d& pickPt);

    // queries the specified 'BIM Space' object for its validity + update status
    static bool  isSpaceValid(const AcDbObjectId& spaceId);
    static bool  isSpaceUpdated(const AcDbObjectId& spaceId);

    // returns the drawing entity which refers to the specified space object
    static BimApi::ResultStatus getSpaceEntity(AcDbObjectId& spaceId, const ACHAR* spaceName, const AcDbDatabase* pDb = nullptr);

    // updates the specified 'BIM Space' object
    static BimApi::ResultStatus updateSpace(const AcDbObjectId& spaceId);

    // retrieves the bounding elements of the 'BIM Space' object
    static BimApi::ResultStatus getBoundingElements(const AcDbObjectId& spaceId, AcDbObjectIdArray& boundaries);

    // get/set the number string of the 'BIM Space' object
    static BimApi::ResultStatus getSpaceNumber(const AcDbObjectId& spaceId, AcString& numberStr);
    static BimApi::ResultStatus setSpaceNumber(const AcDbObjectId& spaceId, const ACHAR* numberStr);

    // gets the area of the 'BIM Space' object
    static BimApi::ResultStatus getSpaceArea(const AcDbObjectId& spaceId, double& area);

    // get/set the representation of the 'BIM Space' object
    static BimApi::ResultStatus getSpaceRepresentation(const AcDbObjectId& spaceId, EBimSpaceRepresentation& representation);
    static BimApi::ResultStatus setSpaceRepresentation(const AcDbObjectId& spaceId, EBimSpaceRepresentation  representation);

    // get all 'BIM Space' objects for the specified spatial location
    static BimApi::ResultStatus getAllSpaces(AcDbObjectIdArray& allSpaces, const AcDbDatabase* pDb = nullptr);
    static BimApi::ResultStatus getAllSpaces(AcDbObjectIdArray& allSpaces, const BrxBimBuilding& building, const AcDbDatabase* pDb = nullptr);
    static BimApi::ResultStatus getAllSpaces(AcDbObjectIdArray& allSpaces, const BrxBimStory&    story,    const AcDbDatabase* pDb = nullptr);

    // assign the 'BIM Space' to the specified story resp. building
    static BimApi::ResultStatus assignToBuilding(const AcDbObjectId& spaceId, const BrxBimBuilding& building);
    static BimApi::ResultStatus assignToStory(const AcDbObjectId& spaceId,    const BrxBimStory& story);
};


///////////////////////////////////////////////////////////////////////////////
// BrxBimMaterial : BIM material object
//
// Class which handles a BIM Material.
//
// NOTE : string name are treated *CASE-SENSITIVE*; be careful with spelling (to be improved in the future)

enum EMaterialFunction
{
    eNone,
    eStructure,
    eSubstrate,
    eInsulation,
    eFinish1,
    eFinish2,
    eMembrane
};

class BRX_IMPORTEXPORT BrxBimMaterial : public BrxBimObject
{
    friend class BrxBimPly;
    struct BrxMaterialImpl;
    // ! underlying core data - for internal use only !
    std::shared_ptr<BrxMaterialImpl>  m_material = nullptr;

public:
    enum EHatchType
    {
        eHatchNone        = -1,
        eHatchUserDefined =  0,
        eHatchPredefined  =  1,
        eHatchCustom      =  2,
    };

    struct HatchPattern
    {
        HatchPattern() {};
        HatchPattern(double scaleOrSpacing, double angle = 0.0, bool cross = false)
            : m_scaleOrSpacing(scaleOrSpacing), m_angle(angle), m_cross(cross)
        {
        };
        HatchPattern(EHatchType type, const ACHAR* name, double scaleOrSpacing = 1.0, double angle = 0.0)
            : m_type(type), m_name(name), m_scaleOrSpacing(scaleOrSpacing), m_angle(angle)
        {
        };
    
        EHatchType  m_type = eHatchNone;
        AcString    m_name;
        double      m_scaleOrSpacing = 1.0, m_angle = 0.0;
        bool        m_cross = false;
    };

    BrxBimMaterial();
    BrxBimMaterial(const BrxBimMaterial& other);
    BrxBimMaterial(const ACHAR* szName);
    virtual ~BrxBimMaterial();

    virtual BrxBimMaterial& operator=(const BrxBimMaterial& other);

    // object comparison is done by tha 'name' only, as material names must be unique
    virtual bool operator==(const BrxBimMaterial& other);
    virtual bool operator!=(const BrxBimMaterial& other);

    // returns the BrxBimPly instance pointer, if 'other' object is of type 'BrxBimPly' or derived from it
    static BrxBimMaterial* cast(const BrxBimObject* other);

    virtual BimApi::BimObjectType typeDesc() const { return BimApi::eBimMaterial; };
    virtual const ACHAR* typeName() const { return _T("BimMaterial"); };

    virtual bool isNull() const;
    virtual void setNull();

    virtual AcString name() const;
    virtual AcString description() const;
    virtual AcString comments() const;
    virtual AcString appearance() const;
    virtual HatchPattern cutPattern() const;
    virtual HatchPattern surfacePattern() const;

    // if a BrxBimMaterial is modified, it needs to be explicitly reassigned to
    // the BrxBimPly object, to become effective !
    virtual BimApi::ResultStatus setName(const ACHAR* szNewName) const;
    virtual BimApi::ResultStatus setDescription(const ACHAR* szInfo) const;
    virtual BimApi::ResultStatus setComments(const ACHAR* szComment) const;
    virtual BimApi::ResultStatus setAppearance(const ACHAR* szAppearance) const;
    virtual BimApi::ResultStatus setCutPattern(const HatchPattern& pattern) const;
    virtual BimApi::ResultStatus setSurfacePattern(const HatchPattern& pattern) const;

    // deletes this material from its assigned library, 
    virtual BimApi::ResultStatus deleteMaterial();

    // saves this material to its assigned library
    virtual BimApi::ResultStatus saveMaterial();

    //===== static utility functions =====

    // verifies whether a material with specified name is available for the given database (in its primary or secondary library)
    static bool hasMaterial(const ACHAR* name, const AcDbDatabase* database, bool fromPrimaryLibrary = true);

    // returns the Material with the given name if it exists in the given database, or empty object otherwise;
    // if required, the Material is loaded from the secondary library into the primary library
    static BimApi::ResultStatus getMaterial(BrxBimMaterial& material, const AcDbDatabase* database, const ACHAR* name);

    // deletes the Material with specified name from the particular Library.
    static BimApi::ResultStatus deleteMaterial(const ACHAR* name, AcDbDatabase* pDb, bool fromPrimaryLibrary = true);

    // saves the Material to the specified library, of the specified database;
    // - the argument 'material' object remains unchanged, in case the material was not yet
    //   saved or was saved to the same library
    // - the argument 'material' object is set to a cloned material object, in case the composition
    //   was previously saved to another library;
    static BimApi::ResultStatus saveMaterial(BrxBimMaterial& material, const AcDbDatabase* database, bool toPrimaryLibrary = true);

    // returns all used Materials for the specified database (using the primary library, saved inside the database)
    static BimApi::ResultStatus allMaterials(BimApi::BimMaterials& materials, const AcDbDatabase* database);
    static BimApi::ResultStatus allMaterials(AcStringArray& materials, const AcDbDatabase* database);

    // returns all available Materials for the specified database (using the secondary library)
    static BimApi::ResultStatus availableMaterials(BimApi::BimMaterials& materials, const AcDbDatabase* database);
    static BimApi::ResultStatus availableMaterials(AcStringArray& materials, const AcDbDatabase* database);

    //===== Informational Assets =====

    // access to 'Informational Assets'
    class BRX_IMPORTEXPORT InformationalAssets
    {
        friend class BrxBimMaterial;
        struct BrxInformationAssetImpl;
        // ! underlying core data - for internal use only !
        std::shared_ptr<BrxInformationAssetImpl>  m_infoAssets = nullptr;

    private:
        InformationalAssets();
    public:
        InformationalAssets(const InformationalAssets& other);
        virtual ~InformationalAssets();
        virtual InformationalAssets& operator=(const InformationalAssets& other);

        virtual bool isNull() const;
        virtual void setNull();

        //---------- properties ------------

        virtual const ACHAR*         label() const;
        virtual BimApi::ResultStatus setLabel(const ACHAR* value);

        virtual const ACHAR*         manufacturer() const;
        virtual BimApi::ResultStatus setManufacturer(const ACHAR* value);

        virtual const ACHAR*         mark() const;
        virtual BimApi::ResultStatus setMark(const ACHAR* value);

        virtual const ACHAR*         model() const;
        virtual BimApi::ResultStatus setModel(const ACHAR* value);

        virtual const ACHAR*         classification() const;
        virtual BimApi::ResultStatus setClassification(const ACHAR* value);

        virtual const ACHAR*         cost() const;
        virtual BimApi::ResultStatus setCost(const ACHAR* value);

        virtual const ACHAR*         keynote() const;
        virtual BimApi::ResultStatus setKeynote(const ACHAR* value);

        virtual const ACHAR*         url() const;
        virtual BimApi::ResultStatus setUrl(const ACHAR* value);

        virtual const ACHAR*         uniqueCode() const;
        virtual BimApi::ResultStatus setUniqueCode(const ACHAR* value);
    };

    // the InformationalAssets allow direct access + modifications to underlying data
    virtual InformationalAssets  getInformationAssets(bool createIfMissing = true);
    virtual BimApi::ResultStatus setInformationAssets(const InformationalAssets& assets);

    //===== Physical Assets =====

    // access to 'Physical Assets'
    class BRX_IMPORTEXPORT PhysicalAssets
    {
        friend class BrxBimMaterial;
        struct BrxPhysicalAssetImpl;
        // ! underlying core data - for internal use only !
        std::shared_ptr<BrxPhysicalAssetImpl>  m_physicalAssets = nullptr;

    private:
        PhysicalAssets();
    public:
        PhysicalAssets(const PhysicalAssets& other);
        virtual ~PhysicalAssets();
        virtual PhysicalAssets& operator=(const PhysicalAssets& other);

        virtual bool isNull() const;
        virtual void setNull();

        //---------- properties ------------
        // the values in PhysicalAssets are always in a fixed unit (no matter the library unit):
        // Density: kg/(m * m * m)
        // SpecificHeat: J/(kg * K)
        // ThermalConductivity: W/(m * K)

        virtual bool                 hasDensity() const;
        virtual double               density() const;
        virtual BimApi::ResultStatus setDensity(double value);
        virtual BimApi::ResultStatus clearDensity();

        virtual bool                 hasSpecificHeat() const;
        virtual double               specificHeat() const;
        virtual BimApi::ResultStatus setSpecificHeat(double value);
        virtual BimApi::ResultStatus clearSpecificHeat();

        virtual bool                 hasThermalConductivity() const;
        virtual double               thermalConductivity() const;
        virtual BimApi::ResultStatus setThermalConductivity(double value);
        virtual BimApi::ResultStatus clearThermalConductivity();
    };

    // the PhysicalAssets allow direct access + modifications to underlying data
    virtual PhysicalAssets       getPhysicalAssets(bool createIfMissing = true);
    virtual BimApi::ResultStatus setPhysicalAssets(const PhysicalAssets& assets);

    //===== BIM Assets =====

    // access to 'BIM Assets'
    class BRX_IMPORTEXPORT BimAssets
    {
        friend class BrxBimMaterial;
        struct BrxBimAssetImpl;
        // ! underlying core data - for internal use only !
        std::shared_ptr<BrxBimAssetImpl>  m_bimAssets = nullptr;

    private:
        BimAssets();
    public:
        BimAssets(const BimAssets& other);
        virtual ~BimAssets();
        virtual BimAssets& operator=(const BimAssets& other);

        virtual bool isNull() const;
        virtual void setNull();

        //---------- properties ------------

        virtual const ACHAR*         layer() const;
        virtual BimApi::ResultStatus setLayer(const ACHAR* value);

        virtual bool                 unionSection() const;
        virtual BimApi::ResultStatus setUnionSection(bool value);

        virtual EMaterialFunction    defaultFunction() const;
        virtual BimApi::ResultStatus setDefaultFunction(EMaterialFunction value);

        virtual bool                 hasVariableThickness() const;
        virtual BimApi::ResultStatus setHasVariableThickness(bool value);

        using ThicknessList = std::set<double>;
        virtual ThicknessList        thicknessValues() const;
        virtual BimApi::ResultStatus setThicknessValues(const ThicknessList& values);
    };

    // the BimAssets allow direct access + modifications to underlying data
    virtual BimAssets            getBimAssets(bool createIfMissing = true);
    virtual BimApi::ResultStatus setBimAssets(const BimAssets& assets);
};


///////////////////////////////////////////////////////////////////////////////
// BrxBimPly : BIM Ply object
//
// Class which handles a BIM Material Ply.
//
// NOTE : string name are treated *CASE-SENSITIVE*; be careful with spelling (to be improved in the future)

class BRX_IMPORTEXPORT BrxBimPly : public BrxBimObject
{
public:
    BrxBimPly();
    BrxBimPly(const BrxBimPly& other);
    BrxBimPly(const BrxBimMaterial& material, EMaterialFunction function = eNone, double thickness = 1.0);
    virtual ~BrxBimPly();

    virtual BrxBimPly& operator=(const BrxBimPly& other);

    // returns the BrxBimPly instance pointer, if 'other' object is of type 'BrxBimPly' or derived from it
    static BrxBimPly* cast(const BrxBimObject* other);

    virtual BimApi::BimObjectType typeDesc() const { return BimApi::eBimPly; };
    virtual const ACHAR* typeName() const { return _T("BimPly"); };

    virtual bool isNull() const;
    virtual void setNull();

    // name + description are not available with a Ply
    virtual AcString          name() const { return _T(""); };
    virtual AcString          description() const { return _T(""); };
    virtual double            thickness() const;
    virtual EMaterialFunction function() const;
    virtual BrxBimMaterial    material() const;

    // name + description are not available with a Ply
    virtual BimApi::ResultStatus setName(const ACHAR* szNewName) const { return BimApi::eNotImplemented; };
    virtual BimApi::ResultStatus setDescription(const ACHAR* szInfo) const { return BimApi::eNotImplemented; };
    virtual BimApi::ResultStatus setThickness(double value);
    virtual BimApi::ResultStatus setFunction(EMaterialFunction function);
    virtual BimApi::ResultStatus setMaterial(const BrxBimMaterial& material);
};


///////////////////////////////////////////////////////////////////////////////
// BrxBimComposition : BIM composition object
//
// Class which holds a (material) Composition in the BIM Library
// - all compositions are stored in the associated BIM Library (embedded in the AcDbDatabase)
// - a Composition consists of plies of Materials
// - each BIM building element can have only one Composition assigned (in case
//   the AcDbEntity is not yet BIM-classified, it is treated as of type 'GenericBuildingElt')
//
// NOTE : string name are treated *CASE-SENSITIVE*; be careful with spelling (to be improved in the future)

class BRX_IMPORTEXPORT BrxBimComposition : public BrxBimObject
{
public:
    enum ECompositionType
    {
        eCompositionNone  = 0x00,
        eCompositionWall  = 0x01,
        eCompositionRoof  = 0x02,
        eCompositionSlab  = 0x04,
        eCompositionOther = 0x80
    };

    BrxBimComposition();
    BrxBimComposition(const ACHAR* name);
    BrxBimComposition(const BrxBimComposition& other);
    virtual ~BrxBimComposition();

    virtual BrxBimComposition& operator=(const BrxBimComposition& other);

    virtual bool operator== (const BrxBimComposition& other) const;
    virtual bool operator!= (const BrxBimComposition& other) const;

    // returns the type identification string
    virtual BimApi::BimObjectType typeDesc() const { return BimApi::eBimComposition; };
    virtual const ACHAR* typeName() const { return _T("BimComposition"); };

    // returns true if this object does not hold a valid Composition object (empty object)
    virtual bool isNull() const;
    // sets this building object to be empty
    virtual void setNull();

    // returns the name of this Composition object, or an empty string in case of an error
    virtual AcString name() const;
    // sets the name of this Composition, returns 'true' for success, or 'false' if assigning
    // the new name fails or is not appropriate
    virtual BimApi::ResultStatus setName(const ACHAR* szNewName) const;

    // returns the description of this Composition, or an empty string (if the object is empty)
    virtual AcString description() const;

    // sets the description of this Composition, returns 'eOK' succeeds, or an error status
    virtual BimApi::ResultStatus setDescription(const ACHAR* szInfo) const;

    // returns the comment string of this Composition, or an empty string (if the object is empty)
    virtual AcString comments() const;
    // sets the comment string for this Composition, returns 'eOK' succeeds, or an error status
    virtual BimApi::ResultStatus setComments(const ACHAR* szComment) const;

    // returns the composition type of this BrxBimComposition object
    virtual ECompositionType type() const;
    // sets the composition type for this BrxBimComposition object
    virtual BimApi::ResultStatus setType(ECompositionType type);

    // returns the layer (as name) used by this BrxBimComposition object;
    // the layer name must not necessarily exist yet in drawing database, will be created on-demand
    virtual const AcString layer() const;
    // sets the layer (as name) used by this BrxBimComposition object;
    // the layer name must not necessarily exist yet in drawing database, will be created on-demand
    virtual BimApi::ResultStatus setLayer(const ACHAR* szLayer);

    // returns all entities, from specified database, using this Composition object
    virtual BimApi::ResultStatus assignedObjects(AcDbObjectIdArray& ids, const AcDbDatabase* database) const;

    // assign this Composition object to specified entity
    // assigning a Composition to an unclassified object will have this object classified as eBimGenericBuildingElt;
    // (an unclassified AcDbEntity is treated as a GenericBuildingElt, if the BIM status is queried)
    // if 'varPlyThickness' is specified as >= 0.0, the variable ply in this Composition (if any) is set to that value
    virtual BimApi::ResultStatus assignToEntity(const AcDbObjectId& id, double varPlyThickness = -1.0) const;

    // deletes this Composition from the associated Library, if it is associated with a library.
    virtual BimApi::ResultStatus deleteComposition();

    // saves the Composition to its library, if any is associated;
    virtual BimApi::ResultStatus saveComposition();

    //---------- Composition Structure : access to Plies (BrxBimPly) -----------

    // returns the number of Plies used by this Composition object
    virtual size_t numberOfPlies() const;

    // returns a copy of the Ply object at the specified index;
    // if index is beyond the number of Plies, then an empty BrxBimPly object is returned
    virtual BrxBimPly getPlyAt(size_t index) const;

    // assigns the given Ply object to this Composition object, at the specified index;
    // this effectively updates the Composition/Plies structure;
    // if the index is beyond the Plies range, a new Ply is appended to the Composition;
    // otherwise the existing Ply (at the index) is replaced by the new Ply object
    virtual BimApi::ResultStatus setPlyAt(size_t index, const BrxBimPly& ply);

    // returns the index of that Ply, which uses a variable width;
    // -1 is returned if no Ply uses a variable width
    virtual int variablePlyIndex() const;

    // returns the thickness used by the "variable Ply", or -1.0 if no Ply is set as "variable Ply"
    virtual double variablePlyThickness() const;

    // defines the Ply, which uses a variable width;
    // input a value < 0 to "clear" the variable Ply index (meaning, no Ply uses a variable width)
    // -1 is returned if no Ply uses a variable thickness
    virtual BimApi::ResultStatus setVariablePlyIndex(int index);

    //===== static utility functions =====

    // returns the BrxBimComposition instance pointer, if 'other' object is of type 'BrxBimComposition' or derived from it
    static BrxBimComposition* cast(const BrxBimObject* other);

    // returns the thickness of the variable ply in the composition assigned to this entity;
    // returns 0.0 if there is no variable ply.
    static double variablePlyThickness(const AcDbObjectId& id);

    // verifies whether a composition with specified name is available for the given database (in its primary or secondary library)
    static bool hasComposition(const ACHAR* name, const AcDbDatabase* database, bool fromPrimaryLibrary = true);

    // deletes the Composition with specified name from the particular Library.
    static BimApi::ResultStatus deleteComposition(AcDbDatabase* pDb, const ACHAR* szName, bool fromPrimaryLibrary = true);

    // deletes the specified Material from specified database
    static BimApi::ResultStatus deleteMaterial(const AcDbDatabase* database, const ACHAR* name);

    // removes an assigned Composition from the entity
    static BimApi::ResultStatus removeCompositionFrom(const AcDbObjectId& id);

    // returns the assigned Composition if there is one, or empty object otherwise;
    // optionally also returns the 'variable Ply thickness', if a Ply with variable thickness is contained
    // in the Composition
    static BimApi::ResultStatus assignedComposition(BrxBimComposition& composition, const AcDbObjectId& id, double* varPlyThickness = nullptr);
    static BimApi::ResultStatus assignedComposition(AcString& name, const AcDbObjectId& id, double* varPlyThickness = nullptr);

    // returns all used Compositions for the specified database (using the primary library, saved inside the database)
    static BimApi::ResultStatus allCompositions(BimApi::BimCompositions& compositions, const AcDbDatabase* database);
    static BimApi::ResultStatus allCompositions(AcStringArray& compositions, const AcDbDatabase* database);

    // returns all available Compositions for the specified database (using the secondary library)
    static BimApi::ResultStatus availableCompositions(BimApi::BimCompositions& compositions, const AcDbDatabase* database);
    static BimApi::ResultStatus availableCompositions(AcStringArray& compositions, const AcDbDatabase* database);

    // returns the Composition with the given name if it exists in the given database, or empty object otherwise;
    // if required, the Composition is loaded from the secondary library into the primary library
    static BimApi::ResultStatus getComposition(BrxBimComposition& composition, const AcDbDatabase* database, const ACHAR* name);

    // assigns the Composition with specified name to the entity
    // assigning a Composition to an unclassified object will have this object classified as eBimGenericBuildingElt;
    // (an unclassified AcDbEntity is treated as a GenericBuildingElt, if the BIM status is queried)
    // if 'varPlyThickness' is specified as >= 0.0, the variable ply in this Composition (if any) is set to that value
    static BimApi::ResultStatus assignToEntity(const ACHAR* name, const AcDbObjectId& id, double varPlyThickness = -1.0);

    // adds/updates Materials and/or Compositions to the embedded Library from specified XML file;
    // - a sample of an xml file can be found at "<BRX-SDK>/BrxSpecific/bim/Bim-Materials-Compositions-Sample.xml"
    // - Materials and Compositions are required to have unique names (! CASE-SENSITIVE !)
    // - if 'updateExistingObjects' is true, existing library items with the same name will be updated
    //   with the new information; otherwise, only objects that don't exist in the library will be added
    static BimApi::ResultStatus addMaterialsAndCompositionsFromXML(const ACHAR* xmlFileName,
                                                                   const AcDbDatabase* database,
                                                                   bool updateExistingObjects = true);

    // saves the Composition to the specified library, of the specified database;
    // - the argument 'composition' object remains unchanged, in case the composition was not yet
    //   saved or was saved to the same library
    // - the argument 'composition' object is set to a cloned composition object, in case the composition
    //   was previously saved to another library;
    static BimApi::ResultStatus saveComposition(BrxBimComposition& composition, const AcDbDatabase* database, bool toPrimaryLibrary = true);
};


///////////////////////////////////////////////////////////////////////////////
// BrxBimProfile : provides access to profile geometry and definition for linear AcDb3dSolid,
// classified as BIM BuildingElement objects
//  
// - currently supported linear BuildingElement types : columns, beams and member
//
// 
// client code can derive an own, extended utility class from this
//

class BrxBimDialogs;

class BRX_IMPORTEXPORT BrxBimProfile
{
    friend class BrxBimDialogs;

    struct BrxProfileImpl;
    // ! underlying core data - for internal use only !
    std::shared_ptr<BrxProfileImpl>  m_profile = nullptr;

public:
    enum class EConnectorType
    {
        eStructural,
        eFlow,
        eNone
    };
    
    enum class EProfileType
    {
        eProfileGeneric,
        eProfileStructuralConcrete,
        eProfileStructuralSteel,
        eProfileHVAC,
        eProfilePiping,
        eProfileElectrical
    };

    // initialises this 'BrxBimProfile' for the AcDb3dSolid specified by 'id';
    // if the entity is not an AcDb3dSolid, or not a suitable ("linear") AcDb3dSolid,
    // a call to 'isValid()' returns 'false' (and any other function also returns an error)
    BrxBimProfile();
    BrxBimProfile(const AcDbObjectId& id);
    virtual ~BrxBimProfile();

    BrxBimProfile(const BrxBimProfile& other);
    virtual BrxBimProfile& operator=(const BrxBimProfile& other);

    // allows to switch this BrxBimProfile object to use a different entity
    virtual bool setFromId(const AcDbObjectId& id);

    // returns 'true' if the associated entity is of 'linear' AcDb3dSolid type
    virtual bool isValid() const;

    virtual AcString getName() const;
    virtual AcString getShape() const;
    virtual AcString getStandard() const;
    virtual AcString getDescription() const;

    // returns the 'Profile' geometry;
    // the profile geometry is an array of loops (arrays of AcGe curves) where the first loop is
    // the outer loop of the profile, and following loops are the inner loops (if present)
    virtual BimApi::ResultStatus getProfileCurves(AcArray<AcGeCurve3dPtrArray>& profileLoops, 
                                                  const AcDbDatabase* db = nullptr) const;

    // applies resp. removes this profile to the specified entity, optionally using rotated profile;
    // (rotation is in radians)
    virtual BimApi::ResultStatus applyProfileTo(const AcDbObjectId& id, double rotationAngle = 0.0, bool keepClippings = true);

    // saves this profile to the library of the given database;
    // updates this profile object to the stored profile object, depending on whether it was ever
    // saved before to the same library;
    virtual BimApi::ResultStatus saveProfile(const AcDbDatabase* db = nullptr);

    //===== static utility functions =====
    static bool isValid(const BrxBimProfile& profile);

    static AcString getName(const BrxBimProfile& profile);
    static AcString getShape(const BrxBimProfile& profile);
    static AcString getStandard(const BrxBimProfile& profile);
    static AcString getDescription(const BrxBimProfile& profile);
    static BimApi::ResultStatus getProfileCurves(const BrxBimProfile& profile, 
                                                 AcArray<AcGeCurve3dPtrArray>& profileLoops, 
                                                 const AcDbDatabase* db = nullptr);

    // returns available library standards, from specified database, or all available standards from library, if database is NULL
    static BimApi::ResultStatus getAllProfileStandards(AcStringArray& standards, const AcDbDatabase* db);

    // returns available profile names and profile types, from specified database, or all available from library if database is NULL;
    typedef std::map<EProfileType, AcStringArray>  ProfileTypeMap;
    static BimApi::ResultStatus getAllProfileNames(ProfileTypeMap& typedNamesMap, const ACHAR* szStandard, const AcDbDatabase* db);

    // returns available sizes, for specified profile (by standard, name, and type), from specified database, or from library if database is NULL;
    static BimApi::ResultStatus getAllProfileSizes(AcStringArray& sizeNames,
                                                   const ACHAR* szStandard, const ACHAR* szName, EProfileType type,
                                                   const AcDbDatabase* db);

    static std::vector<BrxBimProfile> getAllProfiles(const AcDbDatabase* db);
    static std::vector<BrxBimProfile> getAllLibraryProfiles(const AcDbDatabase* db);
    static BrxBimProfile getAssignedProfile(const AcDbObjectId& id);

    static AcDbObjectIdArray getAllAssignedObjects(const BrxBimProfile& profile, const AcDbDatabase* db = nullptr);

    // applies resp. removes the specified profile to/from the specified entity, optionally using rotated profile;
    // (rotation is in radians)
    static BimApi::ResultStatus applyProfileTo(const BrxBimProfile& profile, const AcDbObjectId& id,
                                               const double rotationAngle = 0.0, const bool keepClippings = true);
    static BimApi::ResultStatus removeProfileFrom(const AcDbObjectId& id);

    // applies the specified Profile to a set of points
    // points : ordered array of points;
    //          any two adjacent points are the start and end of line to which profile will be applied
    // profile : the profile to be applied
    // pDb : if specified, the generated profile elements (and connectors) will be added to that database
    // connectorType : type of connector that will be used
    // rotationAngle : rotation angle of profile in its plane (radians);
    //                 Profile plane is plane that has its normal codirectional to the line to which this profile is applied,
    //                 x-axis and y-axis will be calculated using transformation that transform z-axis of WCS to normal
    // useAligment : controls the alignment of created solids one by one

    static AcArray<AcDb3dSolid*> applyProfile(const AcGePoint3dArray& points,
                                              const BrxBimProfile& profile,
                                              AcDbDatabase* pDb = nullptr,
                                              const EConnectorType connectorType = EConnectorType::eFlow,
                                              const double rotationAngle = 0.0,
                                              const bool useAlignment = true);

    // returns the Profile with the given standard, name, type and shape/size if it exists in the Library of specified database, or an empty object otherwise
    static BrxBimProfile getProfile(const ACHAR* standardName, const ACHAR* profileName, const ACHAR* shapeName, EProfileType profileType, const AcDbDatabase* db = nullptr);

    // saves the specified profile to the library of given database;
    // updates this profile object to the stored profile object, depending on whether it was ever
    // saved before to the same library;
    static BimApi::ResultStatus saveProfile(BrxBimProfile& profile, const AcDbDatabase* db = nullptr);

    // adds/updates one or more Profile definition(s) to the embedded Library from specified XML file;
    // - samples of Profile xml files can be found at "<BRX-SDK>/BrxSpecific/bim/sample_profiles.xml"
    // and "<BRX-SDK>/BrxSpecific/bim/sample_profiles.norm.xml";
    // template can be found at "<BRX-SDK>/BrxSpecific/bim/bsyslib_profiles.xsd"
    // - all names used by Profile definition are required to be unique (! CASE-SENSITIVE !)
    // - if 'updateExistingObjects' is true, existing library items with the same name will be updated
    //   with the new information; otherwise, only objects that don't exist in the library will be added
    static BimApi::ResultStatus addProfileFromXML(const ACHAR* xmlFileName, const AcDbDatabase* database,
                                                  bool updateExistingObjects = true);
};


///////////////////////////////////////////////////////////////////////////////
// BrxBimLinearGeometry : geometry access for linear BIM BuildingElement objects
//  
// - currently supported linear BuildingElement types : columns and beams
//
// - for each linear BuildingElement, a geometrical representation (including
//   axis, profile and marking of the clipping faces) can be retrieved
//
// - each linear BuildingElement can have a 'Profile' assigned 
// - all 'Profiles' are stored in the associated Library, which is embedded in the AcDbDatabase
//
// Provides access to the geometrical representation of a linear BuildingElement if the
// given AcDbObjectId refers to a linear BuildingElement with AcDb3dSolid geometry.
//    
// guaranteed conditions :
// - the 'Profile' is a closed + planar AcGeCurve3d
// - the 'Extrusion Path' is of type AcGe::kLineSeg3d
// - the 'Extrusion Path' has a start point and end point
// - the geometric center of the 'Profile' is on the 'Extrusion Path'
// - the 'Extrusion Path' is perpendicular to Profile's plane
//
// NOTE: the 'Axis' is the representation of the axis in BricsCAD and is not necessarily
//       coincident or even parallel with 'Extrusion Path'
// 
// client code can derive an own, extended utility class from this
//

namespace bim_api
{
    // ! underlying core data - for internal use only !
    struct LinearBuildingElementGeometry;
};

class BRX_IMPORTEXPORT BrxBimLinearGeometry
{
public:
    // initialises this 'BrxBimLinearGeometry' for the AcDb3dSolid specified by 'id';
    // if the entity is not an AcDb3dSolid, or not a suitable ("linear") AcDb3dSolid,
    // a call to 'isValid()' returns 'false' (and any other function also returns an error)
    BrxBimLinearGeometry();
    BrxBimLinearGeometry(const AcDbObjectId& id);
    virtual ~BrxBimLinearGeometry();

    BrxBimLinearGeometry(const BrxBimLinearGeometry& other);
    virtual BrxBimLinearGeometry& operator=(const BrxBimLinearGeometry& other);

    // allows to switch this BrxBimLinearGeometry object to use a different entity
    virtual bool setId(const AcDbObjectId& id);

    // allows to retrieve the associated AcDbObjectId
    virtual const AcDbObjectId& getId() const { return m_id; };

    // returns 'true' if the associated entity is of 'linear' AcDb3dSolid type
    virtual bool isValid() const;

    // returns the 'Axis' curve of the 'linear' AcDb3dSolid
    virtual BimApi::ResultStatus getAxis(AcGeCurve3dPtr& axis) const;

    // returns the 'Extrusion Path' curve of the 'linear' AcDb3dSolid
    virtual BimApi::ResultStatus getExtrusionPath(AcGeCurve3dPtr& path) const;

    // returns the 'Profile' geometry of the 'linear' AcDb3dSolid;
    // the profile geometry is an array of loops (arrays of AcGe curves) where the first loop is
    // the outer loop of the profile, and following loops the inner loops (if present)
    virtual BimApi::ResultStatus getProfile(AcArray<AcGeCurve3dPtrArray>& profile) const;

    // returns the BrxBimProfile assigned to a linear AcDb3dSolid, if any (otherwise empty, not valid profile)
    virtual BimApi::ResultStatus getAssignedProfile(BrxBimProfile& profile) const;

    // returns the 'Side Faces' of the 'linear' AcDb3dSolid
    virtual BimApi::ResultStatus getSideFaces(AcDbFullSubentPathArray& sideFaces) const;

    // returns the 'Clipping Faces' of the 'linear' AcDb3dSolid
    virtual BimApi::ResultStatus getClippingFaces(AcDbFullSubentPathArray& clippingFaces) const;

    //returns the 'Axis' Start Point of the 'linear' AcDb3dSolid
    virtual BimApi::ResultStatus getStartPoint(AcGePoint3d& startPoint) const;
    
    //returns the 'Axis' End Point of the 'linear' AcDb3dSolid
    virtual BimApi::ResultStatus getEndPoint(AcGePoint3d& endPoint) const;

private:
    AcDbObjectId  m_id;
    std::shared_ptr<bim_api::LinearBuildingElementGeometry>  m_geometry = nullptr;
};


///////////////////////////////////////////////////////////////////////////////
// BimClassification : classification of AcDbEntity as BIM building elements (utility class)
//
// client code can derive an own, extended utility class from this
//
// NOTE : string name are treated *CASE-SENSITIVE*; be careful with spelling (to be improved in the future)

// 'BIM' properties are now (>= V18) classified into categories; V17 implicitly used 'Bricsys + IFC2x3';
// V18 and higher are backward-compatible, default category is 'kStandard' (= 'Bricsys + IFC2x3')
enum EBimCategory : int
{
    kStandard      = 0,  // Bricsys + IFC2x3
    kBricsys       = 1,  // Bricsys
    kIFC2x3        = 2,  // IFC2x3
    kIFCCustom     = 3,  // IFCCustom
    kUser          = 4,  // User
    kQuantity      = 5,  // Bricsys Quantity
    kClassfication = 6,  // ClassificationSystem
    kIFC4          = 7,  // IFC4
    kIFCQuantity   = 8,  // IFC Quantity
};


namespace BimApi
{
// BIM properties can also be accessed via the "Category Name" instead of "Category Enum";
// this approach is more flexible for future extensions
static const ACHAR* bimCategoryStandard        = NULL;
static const ACHAR* bimCategoryBricsys         = _T("Bricsys");
static const ACHAR* bimCategoryBricsysQuantity = _T("BricsysQuantity");
static const ACHAR* bimCategoryIFC2x3          = _T("IFC2x3");
static const ACHAR* bimCategoryIFC4            = _T("IFC4");
static const ACHAR* bimCategoryCustom          = _T("Custom");
static const ACHAR* bimCategoryUser            = _T("User");
static const ACHAR* bimCategoryClassification  = _T("Classification System");
static const ACHAR* bimCategoryIfcQuantity     = _T("Quantity");
}; // namespace BimApi

typedef  std::map<AcString, AcString>  BimPropertiesMap;

class BRX_IMPORTEXPORT BimClassification
{
public:
    BimClassification() {};
    virtual ~BimClassification() {};

public:
    //----- entity related functions -----

    // get/set the name, description, guid of a BIM building element (a BIM classified entity)
    // NOTE : setting the name/description of an unclassified entity will have this entity
    //        to be classified as an 'eBimGenericBuildingElt'

    static const ACHAR* getName(const AcDbObjectId& id);
    static BimApi::ResultStatus setName(const AcDbObjectId& id, const ACHAR* szName);

    static const ACHAR* getDescription(const AcDbObjectId& id);
    static BimApi::ResultStatus setDescription(const AcDbObjectId& id, const ACHAR* szDescription);

    static const ACHAR* getGUID(const AcDbObjectId& id);

    // classify + unclassify an entity
    static BimApi::ResultStatus classifyAs(const AcDbObjectId& id, const BimApi::BimElementType objectType);
    static BimApi::ResultStatus classifyAs(const AcDbObjectId& id, const AcString& typeName, bool localName = false);
    static BimApi::ResultStatus unClassify(const AcDbObjectId& id);

    // query entity's classification status
    static bool isClassifiedAs(const AcDbObjectId& id, const BimApi::BimElementType objectType);
    static bool isClassifiedAs(const AcDbObjectId& id, const AcString& typeName, bool localName = false);
    static bool isClassifiedAsAnyBuildingElement(const AcDbObjectId& id);
    static bool isUnclassified(const AcDbObjectId& id);

    // query entity's object classification
    static BimApi::ResultStatus getClassification(BimApi::BimElementType& objectType, const AcDbObjectId& id);
    static BimApi::ResultStatus getClassification(AcString& typeName, const AcDbObjectId& id, bool localName = false);
    
    // query entity's BIM object properties
    static BimApi::ResultStatus getProperties(AcStringArray& propertyNames, const AcDbObjectId& id);
    static BimApi::ResultStatus getProperties(BimPropertiesMap& properties, const AcDbObjectId& id);

    static bool hasProperty(const AcDbObjectId& id, const ACHAR* szPropertyName, const EBimCategory category = kStandard);
    static bool hasProperty(const AcDbObjectId& id, const ACHAR* szPropertyName, const ACHAR* category);

    static bool deleteProperty(const AcDbObjectId& id, const ACHAR* szPropertyName, const EBimCategory category = kStandard);
    static bool deleteProperty(const AcDbObjectId& id, const ACHAR* szPropertyName, const ACHAR* category);

    static BimApi::ResultStatus getProperty(AcValue& propertyValue, const AcDbObjectId& id, const ACHAR* szPropertyName, const EBimCategory category = kStandard);
    static BimApi::ResultStatus getProperty(AcValue& propertyValue, const AcDbObjectId& id, const ACHAR* szPropertyName, const ACHAR* category);

    static BimApi::ResultStatus setProperty(const AcDbObjectId& id, const ACHAR* szPropertyName, const AcValue& propertyValue, const EBimCategory category = kStandard);
    static BimApi::ResultStatus setProperty(const AcDbObjectId& id, const ACHAR* szPropertyName, const AcValue& propertyValue, const ACHAR* category);

    //===== static utility functions =====

    // retrieve all entities in given database, having any or specific classification, or having no classification
    static BimApi::ResultStatus getAllClassified(AcDbObjectIdArray& ids, const AcDbDatabase* database);
    static BimApi::ResultStatus getAllClassifiedAs(AcDbObjectIdArray& ids, const BimApi::BimElementType objectType, const AcDbDatabase* database);
    static BimApi::ResultStatus getAllClassifiedAs(AcDbObjectIdArray& ids, const AcString& typeName, const AcDbDatabase* database, bool localName = false);
    static BimApi::ResultStatus getAllUnclassified(AcDbObjectIdArray& ids, const AcDbDatabase* database);

    // retrieve all used classifications for the given database
    static BimApi::ResultStatus getAllUsedClassifications(BimApi::BimTypes& usedTypes, const AcDbDatabase* database);
    static BimApi::ResultStatus getAllUsedClassifications(AcStringArray& typeNames, const AcDbDatabase* database, bool localNames = false);

    // retrieve all possible BIM type names
    static BimApi::ResultStatus getBimTypeNames(AcStringArray& typeNames, bool localNames = false);

private:
    BimClassification(const BimClassification&);
    BimClassification& operator=(const BimClassification&);
};


//----------------- BIM NameSpaces Functions -------------------

class BRX_IMPORTEXPORT BimNameSpaces
{
public:
    BimNameSpaces() {};
    virtual ~BimNameSpaces() {};

public:
    // returns the list of available BIM NameSpaces (as mapping <name,label>)), for specified database;
    // if no database is specified, the current drawing database is used;
    static BimApi::ResultStatus listNameSpaces(BimPropertiesMap& nameSpaces, AcDbDatabase* pDb = nullptr);

    // verifies whether the given NameSpace name (or label) is available in specified database, case-insensitive;
    // if no database is specified, the current drawing database is used;
    static BimApi::ResultStatus hasNameSpace(const ACHAR* szNameOrLabel, AcDbDatabase* pDb = nullptr);

    // verifies whether the given NameSpace name (or label) is visible specified database, case-insensitive;
    // if no database is specified, the current drawing database is used;
    static BimApi::ResultStatus getIsNameSpaceVisible(bool& visible, const ACHAR* szNameOrLabel,
                                                      AcDbDatabase* pDb = nullptr);

    // defines whether the given NameSpace name (or label) is visible specified database, case-insensitive;
    // if no database is specified, the current drawing database is used;
    static BimApi::ResultStatus setIsNameSpaceVisible(bool visible, const ACHAR* szNameOrLabel,
                                                      AcDbDatabase* pDb = nullptr);

    // creates a new NameSpace with given name and label, is visible or invisible, for the specified database;
    // if no label is specified, the PropertySpace name is used as label;
    // if no database is specified, the current drawing database is used;
    static BimApi::ResultStatus createNameSpace(const ACHAR* szName, const ACHAR* szLabel = nullptr,
                                                bool visible = true, AcDbDatabase* pDb = nullptr);

    // deletes the NameSpace given by name (or label) in specified database, case-insensitive;
    // if no database is specified, the current drawing database is used;
    // NOTE : all PropertySets contained in the NameSpace are also removed
    static BimApi::ResultStatus deleteNameSpace(const ACHAR* szNameOrLabel, AcDbDatabase* pDb = nullptr);

    //======== since V23.2

    // returns the 'Label' of the specified NameSpace;
    // if no database is specified, the current drawing database is used;
    static BimApi::ResultStatus getNameSpaceLabel(AcString& label, const ACHAR* szName, AcDbDatabase* pDb = nullptr);

    // assigns the 'Label' for the specified NameSpace;
    // if no database is specified, the current drawing database is used;
    static BimApi::ResultStatus setNameSpaceLabel(const ACHAR* szName, const ACHAR* szLabel, AcDbDatabase* pDb = nullptr);
};

//----------------- BIM PropertySets Functions -----------------

struct BimPropertyInfo
{
    AcString  m_name;
    AcString  m_desc;
    AcString  m_type;
};
typedef  std::vector<BimPropertyInfo>  BimPropertiesList;

class BRX_IMPORTEXPORT BimPropertySets
{
public:
    BimPropertySets() {};
    virtual ~BimPropertySets() {};

public:
    //------------- PropertySet related Functions ----------------

    // returns the list of available BIM PropertySets (as mapping <name,label>)) in given NameSpace,
    // for specified database;
    // if no nameSpace is specified, the "User" namespace is used (nameSpace is case-insensitive);
    // if no database is specified, the current drawing database is used;
    static BimApi::ResultStatus listPropertySets(BimPropertiesMap& propertySets, const ACHAR* szNameSpace = nullptr,
                                                 AcDbDatabase* pDb = nullptr);

    // verifies whether the given PropertySet name (or label) is available in given NameSpace,
    // for specified database;
    // PropertySet name is case-insensitive;
    // if no nameSpace is specified, the "User" namespace is used (nameSpace is case-insensitive);
    // if no database is specified, the current drawing database is used;
    static BimApi::ResultStatus hasPropertySet(const ACHAR* szNameOrLabel, const ACHAR* szNameSpace = nullptr,
                                               AcDbDatabase* pDb = nullptr);

    // returns the parameters of the given PropertySet name (or label), of given NameSpace,
    // for specified database;
    // PropertySet name is case-insensitive;
    // if no nameSpace is specified, the "User" namespace is used (nameSpace is case-insensitive)
    // if no database is specified, the current drawing database is used;
    static BimApi::ResultStatus getPropertySetParams(bool& visible, bool& perInstance,
                                                     const ACHAR* szNameOrLabel, const ACHAR* szNameSpace = nullptr,
                                                     AcDbDatabase* pDb = nullptr);

    // defines the parameters of the given PropertySet name (or label), of given NameSpace,
    // for specified database;
    // PropertySet name is case-insensitive;
    // if no nameSpace is specified, the "User" namespace is used (nameSpace is case-insensitive);
    // if no database is specified, the current drawing database is used;
    static BimApi::ResultStatus setPropertySetParams(bool visible, bool perInstance,
                                                     const ACHAR* szNameOrLabel, const ACHAR* szNameSpace = nullptr,
                                                     AcDbDatabase* pDb = nullptr);

    // creates a new PropertySet with given name and (optional) label, for the given NameSpace,
    // for specified database;
    // if label is not specified, the PropertySet name is used as label;
    // if no nameSpace is specified, the "User" namespace is used (nameSpace is case-insensitive);
    // if no database is specified, the current drawing database is used;
    static BimApi::ResultStatus createPropertySet(const ACHAR* szName, const ACHAR* szLabel = nullptr,
                                                  const ACHAR* szNameSpace = nullptr,
                                                  bool visible = true, bool perInstance = true,
                                                  AcDbDatabase* pDb = nullptr);

    // deletes the PropertySet given by name (or label) in specified database, case-insensitive;
    // if no nameSpace is specified, the "User" namespace is used (nameSpace is case-insensitive);
    // if no database is specified, the current drawing database is used;
    // NOTE : all Properties contained in the PropertySet are also removed
    static BimApi::ResultStatus deletePropertySet(const ACHAR* szNameOrLabel, const ACHAR* szNameSpace = nullptr,
                                                  AcDbDatabase* pDb = nullptr);

    //------------- PropertySet Properties related Functions ----------------

    // returns the list of available Properties (as std::vector<BimPropertyInfo>) for the given PropertiesSet,
    // for specified database;
    // if no database is specified, the current drawing database is used;
    static BimApi::ResultStatus listPsetProperties(BimPropertiesList& properties, const ACHAR* szPropertySetName,
                                                   AcDbDatabase* pDb = nullptr);

    // verifies whether the classified BIM entity has a given Property (by Name or Label) in specified PropertySet;
    // PropertySet name is case-insensitive;
    // Property name is case-insensitive;
    // NOTE : all available BIM NameSpaces are automatically searched for the specified PropertySet
    static BimApi::ResultStatus hasPSetProperty(const AcDbObjectId& id, const ACHAR* szPropertySetName,
                                                const ACHAR* szPropertyName);

    // returns the value assigned to given Property (by Name or Label) in specified PropertySet, for the
    // classified BIM entity;
    // PropertySet name is case-insensitive;
    // Property name is case-insensitive;
    // NOTE : all available BIM NameSpaces are automatically searched for the specified PropertySet
    static BimApi::ResultStatus getPSetProperty(const AcDbObjectId& id,
                                                const ACHAR* szPropertySetName, const ACHAR* szPropertyName,
                                                AcValue& value);

    // assigns the value to the given Property (by Name or Label) in specified PropertySet, for the
    // classified BIM entity;
    // if 'autoCreateProperty' is 'true', a missing Property is automatically created (as 'visible')
    // PropertySet name is case-insensitive;
    // Property name is case-insensitive;
    // NOTE : all available BIM NameSpaces are automatically searched for the specified PropertySet
    static BimApi::ResultStatus setPSetProperty(const AcDbObjectId& id,
                                                const ACHAR* szPropertySetName, const ACHAR* szPropertyName,
                                                const AcValue& value, bool autoCreateProperty = false);

    // removes the given Property (by Name or Label) in specified PropertySet (by Name or Label),
    // from the classified BIM entity;
    // PropertySet name is case-insensitive;
    // Property name is case-insensitive;
    // NOTE : all available BIM NameSpaces are automatically searched for the specified PropertySet
    static BimApi::ResultStatus deletePSetProperty(const AcDbObjectId& id,
                                                   const ACHAR* szPropertySetName, const ACHAR* szPropertyName);

    // removes the given Property (by Name or Label) from specified PropertySet (by Name or Label)
    // from specified database; if no database is specified, the current drawing database is used;
    // PropertySet name is case-insensitive;
    // Property name is case-insensitive;
    // NOTE : all available BIM NameSpaces are automatically searched for the specified PropertySet
    static BimApi::ResultStatus deletePSetProperty(const ACHAR* szPropertySetName, const ACHAR* szPropertyName,
                                                   AcDbDatabase* pDb = nullptr);

    //======== since V23.2

    //------------- PropertySet related Functions ----------------

    // returns the 'Label' for the specified PropertySet;
    // if no database is specified, the current drawing database is used;
    static BimApi::ResultStatus getPSetLabel(AcString& label, const ACHAR* szPropertySetName, AcDbDatabase* pDb = nullptr);

    // assigns the 'Label' for the specified PropertySet;
    // if no database is specified, the current drawing database is used;
    static BimApi::ResultStatus setPSetLabel(const ACHAR* szPropertySetName, const ACHAR* szPropertySetLabel, AcDbDatabase* pDb = nullptr);

    //------------- PropertySet Properties related Functions ----------------

    // create a new Property inside the specified PropertySet, with all appropriate parameters;
    // if no database is specified, the current drawing database is used;
    static BimApi::ResultStatus createPSetProperty(const ACHAR* szPropertySetName,
                                                   const ACHAR* szPropertyName, const ACHAR* szPropertyLabel = nullptr,
                                                   const ACHAR* szPropertyDesc = nullptr, bool visible = true,
                                                   AcDbDatabase* pDb = nullptr);

    // verifies whether the specified Property exists inside the specified PropertySet;
    // if no database is specified, the current drawing database is used;
    static BimApi::ResultStatus hasPSetProperty(const ACHAR* szPropertySetName, const ACHAR* szPropertyName, AcDbDatabase* pDb = nullptr);

    // retrieves all defining parameters for the specified Property inside the specified PropertySet;
    // if no database is specified, the current drawing database is used;
    static BimApi::ResultStatus getPSetPropertyParameters(const ACHAR* szPropertySetName, const ACHAR* szPropertyName,
                                                          AcString& label, AcString& description, bool& visible,
                                                          AcDbDatabase* pDb = nullptr);

    // assigns all defining parameters for the specified Property inside the specified PropertySet;
    // if no database is specified, the current drawing database is used;
    static BimApi::ResultStatus setPSetPropertyParameters(const ACHAR* szPropertySetName, const ACHAR* szPropertyName,
                                                          const ACHAR* szlabel, const ACHAR* szDescription, bool visible,
                                                          AcDbDatabase* pDb = nullptr);

    //-------- support for 'BIM Object Types' associated with a PropertySet

    // returns a map of 'global' BIM Type names and their associated 'localised' names
    typedef std::map<AcString, AcString>  BimTypeNames;
    static BimApi::ResultStatus listAllBimTypes(BimTypeNames& bimTypes);

    // returns the array of 'global' BIM Type names used by the specified PropertySet (by Name or Label)
    static BimApi::ResultStatus listBimTypes(AcStringArray& bimTypes, const ACHAR* szPropertySetName);

    // returns whether the specified PropertySet uses the 'bimType' BIM Type (as global name)
    static BimApi::ResultStatus hasBimType(const ACHAR* szPropertySetName, const ACHAR* szBimType);

    // adds the specified 'bimType' BIM Type (as global name) to the specified PropertySet uses 
    static BimApi::ResultStatus addBimType(const ACHAR* szPropertySetName, const ACHAR* szBimType);

    // removes the specified 'bimType' BIM Type (as global name) from the specified PropertySet
    static BimApi::ResultStatus delBimType(const ACHAR* szPropertySetName, const ACHAR* szBimType);
};


///////////////////////////////////////////////////////////////////////////////
// BrxBimDialogs : provides access to several BIM related dialogs
//
// client code can derive an own, extended utility class from this

class BRX_IMPORTEXPORT BrxBimDialogs
{
public:
    BrxBimDialogs() {};
    virtual ~BrxBimDialogs() {};

public:
    // shows the Composition dialog; 'id' can be kNull - if a valid entity, only compositions suitable
    // for that entitiy are shown; returns 'true' for OK, and 'false' if user cancelled the dialog
    static bool showCompositionsDialog(AcString& compositionName, const AcDbObjectId& id = AcDbObjectId::kNull);

    // shows the BIM Project dialog
    enum EProjectTab { eRecentTab = -1, eTabProject = 0, eTabLibrary = 1, eTabFilter  = 2, };
    static bool showProjectDialog(const AcDbDatabase* pDb, BrxBimDialogs::EProjectTab eTab = BrxBimDialogs::eTabProject);

    // shows the BIM 'Buildings & Stories' dialog
    static bool showBuildingsManagerDialog(const AcDbDatabase* pDb);

    // shows the BIM 'Materials' dialog
    static bool showMaterialsDialog(const AcDbDatabase* pDb);

    // shows the 'BIM Profiles' dialog;
    // if optional entity is provided by 'id' argument, that entity will get the selected profile assigned;
    // returns the boolean result status (true/false) and selected profile, if successful
    static bool showProfilesDialog(BrxBimProfile& profile, const AcDbObjectId& id = AcDbObjectId::kNull);
};


///////////////////////////////////////////////////////////////////////////////
// general utility functions

namespace BimApi
{
struct BimLibraryInfo
{
    enum ELibraryUnit
    {
        eUnitInch = 0,
        eUnitMillimeter,
    };

    AcString path;
    bool isPrimary  = true;
    bool isReadOnly = false;
    bool isNew      = false;
    AcString guid;
    ELibraryUnit unit = ELibraryUnit::eUnitMillimeter;
    AcString locale;
    AcString region;
};

BRX_IMPORTEXPORT BimApi::ResultStatus getLibraryInfo(BimApi::BimLibraryInfo& libInfo,
                                                     const AcDbDatabase* database,
                                                     bool forPrimaryLibrary);


}; // namespace BimApi
