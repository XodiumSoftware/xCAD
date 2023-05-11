// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbSymbolTable.h"

/** _ */
class BRX_EXPORT AcDbLayerTable: public AcDbSymbolTable
{
public:
    typedef AcDbLayerTableRecord RecordType;

    ACDB_DECLARE_MEMBERS(AcDbLayerTable);

    AcDbLayerTable();
    virtual ~AcDbLayerTable();

    Acad::ErrorStatus add(AcDbLayerTableRecord*);
    Acad::ErrorStatus add(AcDbObjectId&,AcDbLayerTableRecord*);
    Acad::ErrorStatus getAt(const ACHAR*,AcDbLayerTableRecord*&,AcDb::OpenMode,bool = false) const;
    Acad::ErrorStatus getAt(const ACHAR*,AcDbObjectId&,bool = false) const;
    Acad::ErrorStatus newIterator(AcDbLayerTableIterator*&,bool = true,bool = true) const;
    bool has(AcDbObjectId) const;
    bool has(const ACHAR*) const;
    void generateUsageData();

    bool hasUnreconciledLayers() const;
    Acad::ErrorStatus getUnreconciledLayers(AcDbObjectIdArray&) const;
};
