// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbObject.h"

/** _ */
class BRX_EXPORT AcDbDictionary: public AcDbObject
{
public:
    ACDB_DECLARE_MEMBERS(AcDbDictionary);

    AcDbDictionary();
    virtual ~AcDbDictionary();

    virtual Acad::ErrorStatus decomposeForSave(AcDb::AcDbDwgVersion,AcDbObject*&,AcDbObjectId&,Adesk::Boolean&);
    virtual Acad::ErrorStatus dwgInFields(AcDbDwgFiler*);
    virtual Acad::ErrorStatus dwgOutFields(AcDbDwgFiler*) const;
    virtual Acad::ErrorStatus dxfInFields(AcDbDxfFiler*);
    virtual Acad::ErrorStatus dxfOutFields(AcDbDxfFiler*) const;
    virtual Acad::ErrorStatus subErase(Adesk::Boolean = Adesk::kTrue);
    virtual AcDb::DuplicateRecordCloning mergeStyle() const;
    virtual void erased(const AcDbObject*,Adesk::Boolean = Adesk::kTrue);
    virtual void goodbye(const AcDbObject*);
    virtual void setMergeStyle(AcDb::DuplicateRecordCloning);

    Acad::ErrorStatus getAt(const ACHAR*,AcDbObject*&,AcDb::OpenMode) const;
    Acad::ErrorStatus getAt(const ACHAR*,AcDbObjectId&) const;
    Acad::ErrorStatus nameAt(AcDbObjectId,ACHAR*&) const;
    Acad::ErrorStatus nameAt(AcDbObjectId,AcString&) const;
    Acad::ErrorStatus remove(AcDbObjectId);
    Acad::ErrorStatus remove(const ACHAR*);
    Acad::ErrorStatus remove(const ACHAR*,AcDbObjectId&);
    Acad::ErrorStatus setAt(const ACHAR*,AcDbObject*,AcDbObjectId&);
    AcDbDictionaryIterator* newIterator() const;
    Adesk::UInt32 numEntries() const;
    bool has(AcDbObjectId) const;
    bool has(const ACHAR*) const;
    bool isTreatElementsAsHard() const;
    bool setName(const ACHAR*,const ACHAR*);
    void setTreatElementsAsHard(bool);

protected:
    virtual Acad::ErrorStatus subGetClassID(CLSID*) const;
};
