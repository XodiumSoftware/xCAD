// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbObjectId.h"

#ifdef __cplusplus

/** _ */
class BRX_IMPORTEXPORT AcDbSoftOwnershipId: public AcDbObjectId
{
public:
    AcDbSoftOwnershipId();
    AcDbSoftOwnershipId(const AcDbObjectId&);
    AcDbSoftOwnershipId(const AcDbStub*);

    AcDbSoftOwnershipId& operator=(const AcDbObjectId&);
    AcDbSoftOwnershipId& operator=(const AcDbSoftOwnershipId&);
    AcDbSoftOwnershipId& operator=(const AcDbStub*);
    bool operator!=(const AcDbObjectId&) const;
    bool operator!=(const AcDbStub*) const;
    bool operator==(const AcDbObjectId&) const;
    bool operator==(const AcDbStub*) const;
    operator AcDbStub*() const;
};

#endif //__cplusplus
