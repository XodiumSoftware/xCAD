// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "BrxSpecific/civil/BrxCvDbObject.h"

class BRX_EXPORT BrxCvDbObjectManager : public BrxCvDbObject
{
public:
    ACDB_DECLARE_MEMBERS(BrxCvDbObjectManager);
    virtual ~BrxCvDbObjectManager();

    // returns the number of objects stored by this manager;
    Adesk::UInt32 elementCount();
    // returns an array of all stored IDs;
    AcDbObjectIdArray ids();
    // returns an array of all stored names;
    AcStringArray names();
    // returns the stored objectId at given the index;
    AcDbObjectId idAt(const Adesk::UInt32 index);
    // returns the stored objectId with given name;
    AcDbObjectId idAt(const AcString& szName);
    // returns the stored object's name at the given index;
    const ACHAR* nameAt(const Adesk::UInt32 index);

    // returns if this manager contains an object with given ID;
    bool has(const AcDbObjectId& id);
    // returns if this manager contains an object with given name;
    bool has(const ACHAR* szName);

    // removes an object with the given ID from this manager, returns true on success;
    bool remove(const AcDbObjectId& id);
    // removes an object with given name from this manager, returns true on success;
    bool remove(const ACHAR* szName);
};
