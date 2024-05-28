// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbTableContent.h"

class BRX_IMPORTEXPORT AcDbTableTemplate : public AcDbTableContent
{
public:
    ACDB_DECLARE_MEMBERS(AcDbTableTemplate);

    AcDbTableTemplate();
    AcDbTableTemplate(const AcDbTable*, AcDb::TableCopyOption);
    ~AcDbTableTemplate();

    virtual Acad::ErrorStatus capture(const AcDbTable*, AcDb::TableCopyOption);
    virtual Acad::ErrorStatus createTable(AcDbTable*&, AcDb::TableCopyOption);
};
