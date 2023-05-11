//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Copyright (C) Menhirs NV. All rights reserved.
//
// AcCivil3dConverter.h
// BRX API for BricsCAD Civil3d Import functionality + interfaces
//
//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH

#pragma once

#include <memory>
#include <vector>
#include <utility>

#include "Misc/AcArray.h"
#include "AcDb/AcDbObjectId.h"


//---------- AutoCAD Civil3D entity conversion -------------

// Civil3d entity info class
// provides basic informations about the Civil3d entity

class BrxCivil3dEntityInfoImpl;
class BrxCivil3dEntityInfo;

class BrxCivil3dConverterImpl;
class BrxCivil3dConverter;

typedef std::vector<BrxCivil3dEntityInfo>  BrxCivil3dEntityInfos;
typedef std::vector<std::pair<BrxCivil3dEntityInfo, AcDbObjectId> > BrxCivil3dEntityInfoMap;

class BRX_EXPORT BrxCivil3dEntityInfo
{
    friend BrxCivil3dEntityInfoImpl;
    friend BrxCivil3dConverter;

    std::shared_ptr<BrxCivil3dEntityInfoImpl> m_pInfoImpl = nullptr;

public:
    enum ECivil3dEntityType  // Civil3d entity type
    {
        eNoEntity    = -1,
        eAlignment   =  0,
        eProfile     =  1,
        eTinSurface  =  2,
        eProfileView =  3,
    };
    enum ECivil3dAlignmentType  // applies to 'eAlignment' entity type
    {
        eNotAlignment  = -1, 
        eCenterline    =  0, 
        eOffset        =  1,
        eCurbReturn    =  2,
        eRail          =  3,
        eMiscellaneous =  4,
    };
    enum ECivil3dProfileType  // applies to 'eProfile' entity type
    {
        eNotProfile     = -1, 
        eLayout         =  0,
        eStaticSurface  =  1,
        eDynamicSurface =  2,
        eQuick          =  3,
    };

    BrxCivil3dEntityInfo();
    virtual ~BrxCivil3dEntityInfo();

    // verify validity
    bool isNull() const;

    // returns the name and description of the AEC Civil3d entity
    AcString name() const;
    AcString description() const;

    // returns the type of the AEC Civil3d entity
    ECivil3dEntityType type() const;

    // returns the AcDbObjectId of the AEC Civil3d entity
    AcDbObjectId objectId() const;

    // applicable for 'eAlignment' entity type, returns 'eNotAlignment' otherwise
    ECivil3dAlignmentType alignmentType() const;

    // applicable for 'eProfile' entity type, returns 'eNotProfile' resp. empty BrxCivil3dEntityInfo otherwise
    ECivil3dProfileType  profileType() const;
    BrxCivil3dEntityInfo baseAlignment() const;
    BrxCivil3dEntityInfo baseSurface() const;

    // applicable for 'eProfileView' entity type, returns an empty vector otherwise
    BrxCivil3dEntityInfos profiles() const;
};

// Civil3d converter class

// suggested workflow :
//
// 1. instantiate the converter
//
// 2. query the list of existing AEC Civil3d entities by 'getCivilEntities()'
//
// 3. (optionally) if desired, create a new BrxCivil3dEntityInfos list, and filter only intended
//    AEC Civil3d entity types, for later conversion;
//    or, skip step 3. and use the full entity list for conversion
//
// 4. call 'convert()' to create BricsCAD Civil TinSurface family (and related) entities
//
// 5. (optionally) 'attachedLabels()' and 'unattachedLabels()' allow to retrieve additional object relations
//
// 6. finally call 'getInsertedEntities()' to get all entities inserted into *target* database

class BRX_EXPORT BrxCivil3dConverter
{
    BrxCivil3dConverterImpl* m_pImpl = nullptr;

public:
    enum ECivil3dLabels  // bit-flags, can be combined
    {
        eNoLabels         = 0x00,
        eSurfaceLabels    = 0x01,
        eAlignmentsLabels = 0x02,
        eUnattachedLabels = 0x04,
        //
        eDefaultLabels    = 0x06, // eAlignmentsLabels|eUnattachedLabels
        eAllLabels        = 0xff,
    };

    // instantiates the Civil3d converter, specifying the source and target database;
    // both databases can be the same, can also be the "current database";
    // for a NULL database, the "current database" is used
    BrxCivil3dConverter(const AcDbDatabase* sourceDb = NULL, AcDbDatabase* targetDb = NULL, ECivil3dLabels doLabels = eDefaultLabels);
    virtual ~BrxCivil3dConverter();

    // returns whether the converter initialisation was valid
    bool isValid() const;

    // get Civil3d entities from source database (can be the "current" database)
    BrxCivil3dEntityInfos getCivilEntities() const;

    // convert entities from Civil3d -> BRX entities;
    // converted entities are not yet added to current database ModelSpace (see 'insertNativeEntities()' below);
    BrxCivil3dEntityInfoMap convert(const BrxCivil3dEntityInfos& entitiesToConvert);

    // extracted labels IDs - connected to specific alignment/surface object;
    // valid only after calling 'convert()'
    AcDbObjectIdArray attachedLabels(const BrxCivil3dEntityInfo& civilEntity) const;

    // extracted label ids - not attached to any supported entity;
    // valid only after calling 'convert()'
    AcDbObjectIdArray unattachedLabels() const;

    // returns all entities added to the specified target database;
    // valid only after 'convert()' function was run;
    AcDbObjectIdArray getInsertedEntities() const;
};
