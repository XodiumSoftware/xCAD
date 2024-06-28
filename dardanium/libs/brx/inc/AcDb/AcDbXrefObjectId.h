// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbObjectId.h"

/** _ */
class BRX_IMPORTEXPORT AcDbXrefObjectId
{
private:
    AcDbHandle m_xrefHandle;
    AcDbObjectId m_localObjectId;

public:
    AcDbXrefObjectId();
    AcDbXrefObjectId(const AcDbXrefObjectId&);

    Acad::ErrorStatus getLocalId(AcDbObjectId&) const;
    Acad::ErrorStatus getXrefId(AcDbObjectId&,AcDbHandle&) const;
    Acad::ErrorStatus resolveObjectId(AcDbObjectId&) const;
    Acad::ErrorStatus serializeFromResbuf(const resbuf*,resbuf*&);
    Acad::ErrorStatus serializeToResbuf(resbuf*&,resbuf*&) const;
    Acad::ErrorStatus setLocalId(AcDbObjectId);
    Acad::ErrorStatus setNull();
    Acad::ErrorStatus setXrefId(AcDbObjectId,const AcDbHandle&);
    bool isNull() const;
    bool isValid() const;
    bool isXref() const;

    AcDbXrefObjectId& operator=(const AcDbXrefObjectId&);
    bool operator!=(const AcDbXrefObjectId&) const;
    bool operator==(const AcDbXrefObjectId&) const;
};
