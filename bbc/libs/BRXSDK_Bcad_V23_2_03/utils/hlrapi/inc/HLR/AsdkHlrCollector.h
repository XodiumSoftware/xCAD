// Copyright (C) 2006-2009 Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbObjectId.h"
#include "HlrGlobal.h"
#include "AsdkHlrData.h"

class HLR_IMPORTEXPORT AsdkHlrCollector
{
public:
    AcArray<AsdkHlrData*> mOutputData;  // the result data collection
protected:
    AcArray<AcDbEntity*> mEntities; // collects the non-database-resident source entities
    AcDbObjectIdArray mEntityIds;   // collects the database-resident source entities
    bool mbDeleteInDestructor;      // defines whether the NDBR entities in 'mEntities' are
                                    // also deleted by clear() resp. DTor
public:
    AsdkHlrCollector();             // initialises 'mbDeleteInDestructor' as 'false'
    AsdkHlrCollector(AsdkHlrCollector&);
    AsdkHlrCollector(AcDbObjectIdArray&);
    AsdkHlrCollector(AcArray<AcDbEntity*>&,bool = false);

    virtual ~AsdkHlrCollector();

protected:
    friend class AsdkHlrEngine;
    virtual int initialize(AcArray<AcDbEntity*>&);
    virtual void close(AcArray<AcDbEntity*>&);

public:
    // returns a reference to the array of non-database-resident entities
    // (entities should be open in kForRead state)
    AcArray<AcDbEntity*>& getInputEntities();

    // returns a reference to the array of database-resident entities
    AcDbObjectIdArray& getInputEntityIds();

    // returns the 'mbDeleteInDestructor'
    bool getDeleteState();

    // add entities to collector
    void addEntities(AcArray<AcDbEntity*>&);
    void addEntities(AcDbObjectIdArray&);
    void addEntity(AcDbEntity*);
    void addEntity(AcDbObjectId);

    // clears the output result data, clears both entity arrays
    void clear();

    // remove entities from collector
    void removeEntities(AcArray<AcDbEntity*>&);
    void removeEntities(AcDbObjectIdArray&);
    void removeEntity(AcDbEntity*);
    void removeEntity(AcDbObjectId);

    // Note : if 'mbDeleteInDestructor' is set as 'true', the DTor will delete all objects
    //        in 'mOutputData' *AND* 'mEntities' !
    //        same applies to the 'clear()' function !
    void setDeleteState(bool);
};
