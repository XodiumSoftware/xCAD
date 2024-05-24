// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbAuditInfo.h"
#include "AcDb/AcDbDwgFiler.h"
#include "AcDb/AcDbDxfFiler.h"
#include "AcRx/AcRxClass.h"

/** _ */
class AcDbXObject: public AcRxObject
{
protected:
    AcDbXObject();

public:
    ACRX_DECLARE_MEMBERS(AcDbXObject);

    virtual Acad::ErrorStatus audit(AcDbAuditInfo*);
    virtual Acad::ErrorStatus dwgInFields(AcDbDwgFiler*);
    virtual Acad::ErrorStatus dwgOutFields(AcDbDwgFiler*) const;
    virtual Acad::ErrorStatus dxfInFields(AcDbDxfFiler*);
    virtual Acad::ErrorStatus dxfOutFields(AcDbDxfFiler*) const;

    Acad::ErrorStatus dwgIn(AcDbDwgFiler*);
    Acad::ErrorStatus dwgOut(AcDbDwgFiler*) const;
    Acad::ErrorStatus dxfIn(AcDbDxfFiler*);
    Acad::ErrorStatus dxfOut(AcDbDxfFiler*) const;
};
