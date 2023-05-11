// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbObject.h"

/** _ */
class BRX_IMPORTEXPORT AcDbProxyObject: public AcDbObject
{
public:
    enum
    {
        kNoOperation = 0,
        kMergeIgnore = 0,
        kEraseAllowed = 1,
        kAllButCloningAllowed = 1,
        kCloningAllowed = 128,
        kAllAllowedBits = 129,
        kMergeReplace = 256,
        kMergeMangleName = 512,
        kDisableProxyWarning = 1024
    };

    ACRX_DECLARE_MEMBERS(AcDbProxyObject);

    virtual ~AcDbProxyObject() {}

    virtual Acad::ErrorStatus getReferences(AcDbObjectIdArray&,AcDbIntArray&) const = 0;
    virtual AcDb::DuplicateRecordCloning mergeStyle() const = 0;
    virtual const ACHAR* applicationDescription() const = 0;
    virtual const ACHAR* originalClassName() const = 0;
    virtual const ACHAR* originalDxfName() const = 0;
    virtual int proxyFlags() const = 0;
};

BRX_IMPORTEXPORT AcDbProxyObject* acObjectToProxy(const AcDbObject& pObj, AcDb::AcDbDwgVersion dwgVer, AcDb::MaintenanceReleaseVersion nMaintVer);
