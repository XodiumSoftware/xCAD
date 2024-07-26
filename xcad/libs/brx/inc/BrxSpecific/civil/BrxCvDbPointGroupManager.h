// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "BrxSpecific/civil/BrxCvDbObjectManager.h"

/** Class to handle Civil Point Groups */
class BRX_EXPORT BrxCvDbPointGroupManager : public BrxCvDbObjectManager
{
public:
    ACDB_DECLARE_MEMBERS(BrxCvDbPointGroupManager);
    virtual ~BrxCvDbPointGroupManager();

    // the "PointGroup ID" is a database-resident BRX Civil object, derived from BrxCvDbPointGroup;
    // acdbOpenObject() can be used, result should be cast to BrxCvDbPointGroup;
    // If there is at least one BrxCvDbPoint in the database, there also exists a named point group "_All points",
    // that is not editable and always contains every point in the drawing. Checking if a point with some 'number'
    // exists can be done by querying the "_All points" group.

    // returns the point group manager for this database
    static Acad::ErrorStatus getManager(AcDbObjectId& idManager, AcDbDatabase* db,
                                        bool createIfNotExists = true);
    // returns the point group manager for this database, opened for read or write
    // it is the users responsibility to close this object
    static Acad::ErrorStatus openManager(BrxCvDbPointGroupManager*& pManager, AcDbDatabase* db,
                                         AcDb::OpenMode openMode = AcDb::kForRead,
                                         bool createIfNotExists = true);

    // create a new BrxCvDbPointGroup and returns its objectId, database-specific;
    AcDbObjectId createPointGroup(const ACHAR* szName);

    // returns all the array of all point group object IDs that contain the BrxCvDbPoint with this number, database-specific;
    AcDbObjectIdArray groupsWithPoint(Adesk::UInt32 number) const;
    // reapplies the point group filters to all the points in the given database
    Adesk::UInt32 updatePointGroups();

    // Returns the next point number that will be used when appending the point to MS, if current point's number is 0 or duplicated.
    Adesk::UInt32 nextPointNumber() const;
    // Sets what point number will be used when a newly appended point's number is 0 or duplicated
    bool setNextPointNumber(Adesk::UInt32 number);
};
