// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbObject.h"
#include <ctime>

class AcValue;

/** _ */
class BRX_EXPORT AcDbDataLink : public AcDbObject
{
public:
    ACDB_DECLARE_MEMBERS(AcDbDataLink);

    AcDbDataLink();
    virtual ~AcDbDataLink();

    virtual Acad::ErrorStatus dwgInFields(AcDbDwgFiler*) override;
    virtual Acad::ErrorStatus dwgOutFields(AcDbDwgFiler*) const override;
    virtual Acad::ErrorStatus dxfInFields(AcDbDxfFiler*) override;
    virtual Acad::ErrorStatus dxfOutFields(AcDbDxfFiler*) const override;

    const ACHAR* connectionString(void) const;
    const ACHAR* dataAdapterId(void) const;
    const ACHAR* description(void) const;
    Acad::ErrorStatus getCustomData(const ACHAR*, AcValue*) const;
    Acad::ErrorStatus getSourceFiles(AcDb::DataLinkGetSourceContext, AcStringArray&) const;
    int getTargets(AcDbObjectIdArray&) const;
    AcString getToolTip(void) const;
    Acad::ErrorStatus getUpdateStatus(AcDb::UpdateDirection*, std::tm*, AcString*) const;
    bool isValid(void) const;
    AcString name(void) const;
    AcDb::DataLinkOption option(void) const;
    Acad::ErrorStatus repathSourceFiles(const wchar_t*, AcDb::PathOption);
    Acad::ErrorStatus setConnectionString(const ACHAR*);
    Acad::ErrorStatus setCustomData(const ACHAR*, const AcValue*);
    Acad::ErrorStatus setDataAdapterId(const ACHAR*);
    Acad::ErrorStatus setDescription(const ACHAR*);
    Acad::ErrorStatus setName(const ACHAR*);
    Acad::ErrorStatus setOption(AcDb::DataLinkOption);
    Acad::ErrorStatus setToolTip(const ACHAR*);
    Acad::ErrorStatus setUpdateOption(int);
    Acad::ErrorStatus setUpdateStatus(const ACHAR*);
    Acad::ErrorStatus update(AcDb::UpdateDirection, AcDb::UpdateOption);
    int updateOption(void) const;
};

typedef AcArray<AcDbDataLink*> AcDbDataLinkArray;
