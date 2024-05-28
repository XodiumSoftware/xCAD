// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
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
