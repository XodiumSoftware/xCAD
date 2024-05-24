// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "Misc/MiscGlobal.h"
#include "Misc/AcArray.h"
#include "AcDb/AcDbObjectId.h"
#include "AcGe/AcGeMatrix3d.h"

class AcDbDatabase;
class AcDbIdMapping;
class AcDbDwgFiler;
class AcDbDxfFiler;


/** _ */
class BRX_IMPORTEXPORT AcDbCompoundObjectId : public AcRxObject
{
public:
    enum Status 
    {
        kValid = 0,
        kWasLoadedNowUnloaded,
        kCouldNotResolveNonTerminal,
        kCouldNotResolveTerminal,
        kCouldNotResolveTooEarly,
        kIncompatibleIdType = 1000,
    };

public:
    ACRX_DECLARE_MEMBERS(AcDbCompoundObjectId);

    AcDbCompoundObjectId();
    virtual ~AcDbCompoundObjectId();

    AcDbCompoundObjectId(const AcDbCompoundObjectId&);
    AcDbCompoundObjectId(const AcDbObjectId&, AcDbDatabase* = NULL);
    AcDbCompoundObjectId(const AcDbObjectId&, const AcDbObjectIdArray&, AcDbDatabase* = NULL);

    AcDbCompoundObjectId& operator=(const AcDbObjectId&);
    AcDbCompoundObjectId& operator=(const AcDbCompoundObjectId&);

    bool operator!=(const AcDbCompoundObjectId&) const;
    bool operator==(const AcDbCompoundObjectId&) const;

    AcDbObjectId topId() const; 
    AcDbObjectId leafId() const;

    Acad::ErrorStatus getPath(AcDbObjectIdArray&) const;
    Acad::ErrorStatus getFullPath(AcDbObjectIdArray&) const;
    Acad::ErrorStatus setFullPath(const AcDbObjectIdArray&, AcDbDatabase* = NULL);
    void setEmpty();

    Status status() const;
    bool remap(const AcDbIdMapping&);  

    Acad::ErrorStatus set(const AcDbObjectId&, AcDbDatabase* = NULL);
    Acad::ErrorStatus set(const AcDbObjectId&, const AcDbObjectIdArray&, AcDbDatabase* = NULL);
    Acad::ErrorStatus set(const AcDbCompoundObjectId&, AcDbDatabase* = NULL);

    bool isEmpty() const;
    bool isSimpleObjectId() const;
    bool isExternal() const;
    bool isValid(int = 1) const;

    Acad::ErrorStatus getTransform(AcGeMatrix3d&) const;

    Acad::ErrorStatus dwgInFields(AcDbDwgFiler*, int);
    Acad::ErrorStatus dwgOutFields(AcDbDwgFiler*, AcDbDatabase*) const;    

    Acad::ErrorStatus dxfInFields(AcDbDxfFiler*, AcDbDatabase*, int);
    Acad::ErrorStatus dxfOutFields(AcDbDxfFiler*, AcDbDatabase*) const;    

    static const AcDbCompoundObjectId& nullId();
};
