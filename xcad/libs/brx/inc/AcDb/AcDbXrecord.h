// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbObject.h"

/** _ */
class BRX_EXPORT AcDbXrecord: public AcDbObject
{
public:
    ACDB_DECLARE_MEMBERS(AcDbXrecord);

    AcDbXrecord();
    virtual ~AcDbXrecord();

    virtual Acad::ErrorStatus dwgInFields(AcDbDwgFiler*);
    virtual Acad::ErrorStatus dwgOutFields(AcDbDwgFiler*) const;
    virtual Acad::ErrorStatus dxfInFields(AcDbDxfFiler*);
    virtual Acad::ErrorStatus dxfOutFields(AcDbDxfFiler*) const;
    virtual Acad::ErrorStatus subClose();
    virtual AcDb::DuplicateRecordCloning mergeStyle() const;
    virtual void setMergeStyle(AcDb::DuplicateRecordCloning);

    Acad::ErrorStatus rbChain(resbuf**,AcDbDatabase* = NULL) const;
    Acad::ErrorStatus setFromRbChain(const resbuf&,AcDbDatabase* = NULL);
    bool isXlateReferences() const;
    void setXlateReferences(bool);
};
