// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "BrxSpecific/civil/BrxCvDbObjectManager.h"

/** Class to manage Civil File Formats */
class BRX_EXPORT BrxCvDbFileFormatManager : public BrxCvDbObjectManager
{
public:
    ACDB_DECLARE_MEMBERS(BrxCvDbFileFormatManager);
    virtual ~BrxCvDbFileFormatManager();

    // the "Format ID" is a database-resident BRX Civil object, derived from BrxCvDbObject;
    // acdbOpenObject() can be used, result should be cast to BrxCvDbObject;

        // returns the file format manager for this database
    static Acad::ErrorStatus getManager(AcDbObjectId& idManager, AcDbDatabase* db,
                                        bool createIfNotExists = true);
    // returns the file format manager for this database, opened for read or write
    // it is the users responsibility to close this object
    static Acad::ErrorStatus openManager(BrxCvDbFileFormatManager*& pManager, AcDbDatabase* db,
                                         AcDb::OpenMode openMode = AcDb::kForRead,
                                         bool createIfNotExists = true);

    // returns the array of suitable Civil File format IDs, database-specific;
    AcDbObjectIdArray applicableFileFormats(const ACHAR* fileName);

    // returns the array of all available Civil File format IDs, database-specific;
    AcDbObjectIdArray allFileFormats();
};
