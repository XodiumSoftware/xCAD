// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbObjectId.h"

#ifdef __cplusplus

/** _ */
class BRX_IMPORTEXPORT AcDbHardOwnershipId: public AcDbObjectId
{
public:
    AcDbHardOwnershipId();
    AcDbHardOwnershipId(const AcDbObjectId&);
    AcDbHardOwnershipId(const AcDbStub*);

    AcDbHardOwnershipId& operator=(const AcDbHardOwnershipId&);
    AcDbHardOwnershipId& operator=(const AcDbObjectId&);
    AcDbHardOwnershipId& operator=(const AcDbStub*);
    bool operator!=(const AcDbObjectId&) const;
    bool operator!=(const AcDbStub*) const;
    bool operator==(const AcDbObjectId&) const;
    bool operator==(const AcDbStub*) const;
    operator AcDbStub*() const;
};

#endif //__cplusplus
