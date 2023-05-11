// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbObjectId.h"

#ifdef __cplusplus

/** _ */
class BRX_IMPORTEXPORT AcDbHardPointerId: public AcDbObjectId
{
public:
    AcDbHardPointerId();
    AcDbHardPointerId(const AcDbObjectId&);
    AcDbHardPointerId(const AcDbStub*);

    AcDbHardPointerId& operator=(const AcDbHardPointerId&);
    AcDbHardPointerId& operator=(const AcDbObjectId&);
    AcDbHardPointerId& operator=(const AcDbStub*);
    bool operator!=(const AcDbObjectId&) const;
    bool operator!=(const AcDbStub*) const;
    bool operator==(const AcDbObjectId&) const;
    bool operator==(const AcDbStub*) const;
    operator AcDbStub*() const;
};

#endif //__cplusplus
