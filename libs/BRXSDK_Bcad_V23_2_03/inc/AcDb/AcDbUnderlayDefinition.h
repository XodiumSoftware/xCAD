// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbObject.h"

class AcDbUnderlayItem;

/** _ */
class BRX_IMPORTEXPORT AcDbUnderlayDefinition: public AcDbObject
{
public:
    ACDB_DECLARE_MEMBERS(AcDbUnderlayDefinition);

    AcDbUnderlayDefinition();
    virtual ~AcDbUnderlayDefinition() = 0;

    Acad::ErrorStatus getActiveFileName(AcString&) const;
    Acad::ErrorStatus getActiveFileName(const ACHAR*&) const;
    Acad::ErrorStatus load(const ACHAR*);
    Acad::ErrorStatus setItemName(const ACHAR*);
    Acad::ErrorStatus setSourceFileName(const ACHAR*);
    Acad::ErrorStatus setUnderlayItem(const ACHAR*,const ACHAR*,AcDbUnderlayItem*);
    bool isLoaded() const;
    const AcDbUnderlayItem* getUnderlayItem() const;
    const ACHAR* getItemName() const;
    const ACHAR* getSourceFileName() const;
    void unload();

    static AcString dictionaryKey(const AcRxClass*);
};
