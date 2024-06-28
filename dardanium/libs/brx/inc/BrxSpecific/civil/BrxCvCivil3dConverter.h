// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

// BRX API for BricsCAD Civil3d Import functionality + interfaces

#include <memory>
#include <vector>
#include <utility>

#include "Misc/AcArray.h"
#include "AcDb/AcDbObjectId.h"

//---------- AutoCAD Civil3D entity conversion -------------

// Civil3d entity info class
// provides basic informations about the Civil3d entity

class BrxCvCivil3dEntityInfoImpl;
class BrxCvCivil3dEntityInfo;

class BrxCvCivil3dConverterImpl;
class BrxCvCivil3dConverter;

typedef std::vector<BrxCvCivil3dEntityInfo>  BrxCvCivil3dEntityInfos;
typedef std::vector<std::pair<BrxCvCivil3dEntityInfo, AcDbObjectId> > BrxCvCivil3dEntityInfoMap;

class BRX_EXPORT BrxCvCivil3dEntityInfo
{
    friend BrxCvCivil3dEntityInfoImpl;
    friend BrxCvCivil3dConverter;

    std::shared_ptr<BrxCvCivil3dEntityInfoImpl> m_pInfoImpl = nullptr;

public:
    enum Civil3dEntityType  // Civil3d entity type
    {
        eNoEntity    = -1,
        eAlignment   =  0,
        eProfile     =  1,
        eTinSurface  =  2,
        eProfileView =  3,
    };
    enum Civil3dAlignmentType  // applies to 'eAlignment' entity type
    {
        eNotAlignment  = -1, 
        eCenterline    =  0, 
        eOffset        =  1,
        eCurbReturn    =  2,
        eRail          =  3,
        eMiscellaneous =  4,
    };
    enum Civil3dProfileType  // applies to 'eProfile' entity type
    {
        eNotProfile     = -1, 
        eLayout         =  0,
        eStaticSurface  =  1,
        eDynamicSurface =  2,
        eQuick          =  3,
    };

    BrxCvCivil3dEntityInfo();
    virtual ~BrxCvCivil3dEntityInfo();

    // verify validity
    bool isNull() const;

    // returns the name and description of the AEC Civil3d entity
    AcString name() const;
    AcString description() const;

    // returns the type of the AEC Civil3d entity
    Civil3dEntityType type() const;

    // returns the AcDbObjectId of the AEC Civil3d entity
    AcDbObjectId objectId() const;

    // applicable for 'eAlignment' entity type, returns 'eNotAlignment' otherwise
    Civil3dAlignmentType alignmentType() const;

    // applicable for 'eProfile' entity type, returns 'eNotProfile' resp. empty BrxCvCivil3dEntityInfo otherwise
    Civil3dProfileType  profileType() const;
    BrxCvCivil3dEntityInfo baseAlignment() const;
    BrxCvCivil3dEntityInfo baseSurface() const;

    // applicable for 'eProfileView' entity type, returns an empty vector otherwise
    BrxCvCivil3dEntityInfos profiles() const;
};

// Civil3d converter class

// suggested workflow :
//
// 1. instantiate the converter
//
// 2. query the list of existing AEC Civil3d entities by 'getCivilEntities()'
//
// 3. (optionally) if desired, create a new BrxCvCivil3dEntityInfos list, and filter only intended
//    AEC Civil3d entity types, for later conversion;
//    or, skip step 3. and use the full entity list for conversion
//
// 4. call 'convert()' to create BricsCAD Civil TinSurface family (and related) entities
//
// 5. (optionally) 'attachedLabels()' and 'unattachedLabels()' allow to retrieve additional object relations
//
// 6. finally call 'getInsertedEntities()' to get all entities inserted into *target* database

class BRX_EXPORT BrxCvCivil3dConverter
{
    BrxCvCivil3dConverterImpl* m_pImpl = nullptr;

public:
    enum Civil3dLabels  // bit-flags, can be combined
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
    BrxCvCivil3dConverter(const AcDbDatabase* sourceDb = NULL, AcDbDatabase* targetDb = NULL, Civil3dLabels doLabels = eDefaultLabels);
    virtual ~BrxCvCivil3dConverter();

    // returns whether the converter initialisation was valid
    bool isValid() const;

    // get Civil3d entities from source database (can be the "current" database)
    BrxCvCivil3dEntityInfos getCivilEntities() const;

    // convert entities from Civil3d -> BRX entities;
    // converted entities are not yet added to current database ModelSpace (see 'insertNativeEntities()' below);
    BrxCvCivil3dEntityInfoMap convert(const BrxCvCivil3dEntityInfos& entitiesToConvert);

    // extracted labels IDs - connected to specific alignment/surface object;
    // valid only after calling 'convert()'
    AcDbObjectIdArray attachedLabels(const BrxCvCivil3dEntityInfo& civilEntity) const;

    // extracted label ids - not attached to any supported entity;
    // valid only after calling 'convert()'
    AcDbObjectIdArray unattachedLabels() const;

    // returns all entities added to the specified target database;
    // valid only after 'convert()' function was run;
    AcDbObjectIdArray getInsertedEntities() const;
};
