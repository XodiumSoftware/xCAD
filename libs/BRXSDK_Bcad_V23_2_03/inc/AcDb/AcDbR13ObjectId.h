// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbObjectId.h"

#ifdef __cplusplus

/** _ */
class BRX_IMPORTEXPORT AcDbR13ObjectId: public AcDbObjectId
{
public:
    bool operator!=(const AcDbR13ObjectId&) const;
    bool operator!=(const AcDbStub*) const;
    bool operator<(const AcDbR13ObjectId&) const;
    bool operator<(const AcDbStub*) const;
    bool operator<=(const AcDbR13ObjectId&) const;
    bool operator<=(const AcDbStub*) const;
    bool operator==(const AcDbR13ObjectId&) const;
    bool operator==(const AcDbStub*) const;
    bool operator>(const AcDbR13ObjectId&) const;
    bool operator>(const AcDbStub*) const;
    bool operator>=(const AcDbR13ObjectId&) const;
    bool operator>=(const AcDbStub*) const;
};

#endif //__cplusplus
