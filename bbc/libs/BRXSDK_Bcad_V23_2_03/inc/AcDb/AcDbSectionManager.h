// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbObject.h"

class AcDbSection;
class AcDbSectionManagerIterator;

/** _ */
class BRX_EXPORT AcDbSectionManager: public AcDbObject
{
public:
    ACDB_DECLARE_MEMBERS(AcDbSectionManager);

    AcDbSectionManager();
    ~AcDbSectionManager();

    virtual Acad::ErrorStatus dwgInFields(AcDbDwgFiler*);
    virtual Acad::ErrorStatus dwgOutFields(AcDbDwgFiler*) const;
    virtual Acad::ErrorStatus dxfInFields(AcDbDxfFiler*);
    virtual Acad::ErrorStatus dxfOutFields(AcDbDxfFiler*) const;

    Acad::ErrorStatus getLiveSection(AcDbObjectId&) const;
    Acad::ErrorStatus getLiveSection(AcDbSection*&,AcDb::OpenMode) const;
    Acad::ErrorStatus getSection(const ACHAR*,AcDbObjectId&) const;
    Acad::ErrorStatus getSection(const ACHAR*,AcDbSection*&,AcDb::OpenMode) const;
    Acad::ErrorStatus getUniqueSectionName(const ACHAR*,ACHAR*&) const;
    Acad::ErrorStatus newIterator(AcDbSectionManagerIterator*&) const;
    int numSections() const;
};
