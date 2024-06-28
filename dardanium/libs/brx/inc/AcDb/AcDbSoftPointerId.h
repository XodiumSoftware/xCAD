// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbObjectId.h"

#ifdef __cplusplus

/** _ */
class BRX_IMPORTEXPORT AcDbSoftPointerId: public AcDbObjectId
{
public:
    AcDbSoftPointerId();
    AcDbSoftPointerId(const AcDbObjectId&);
    AcDbSoftPointerId(const AcDbStub*);

    AcDbSoftPointerId& operator=(const AcDbObjectId&);
    AcDbSoftPointerId& operator=(const AcDbSoftPointerId&);
    AcDbSoftPointerId& operator=(const AcDbStub*);
    bool operator!=(const AcDbObjectId&) const;
    bool operator!=(const AcDbStub*) const;
    bool operator==(const AcDbObjectId&) const;
    bool operator==(const AcDbStub*) const;
    operator AcDbStub*() const;
};

#endif //__cplusplus
