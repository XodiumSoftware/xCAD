// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbGlobal.h"
#include "AcRx/AcRxObject.h"

/** _ */
class BRX_IMPORTEXPORT AcDbEntityHyperlinkPE: public AcRxObject
{
public:
    ACRX_DECLARE_MEMBERS(AcDbEntityHyperlinkPE);

    virtual Acad::ErrorStatus getHyperlinkCollection(AcDbObject*,AcDbHyperlinkCollection*&,bool = false,bool = true) = 0;
    virtual Acad::ErrorStatus getHyperlinkCollection(const AcDbObjectIdArray*&,AcDbHyperlinkCollection*&,bool = false,bool = true) = 0;
    virtual Acad::ErrorStatus getHyperlinkCount(AcDbObject*,UINT&,bool = true) = 0;
    virtual Acad::ErrorStatus getHyperlinkCount(const AcDbObjectIdArray*&,UINT&,bool = true) = 0;
    virtual Acad::ErrorStatus hasHyperlink(AcDbObject*,bool&,bool = true) = 0;
    virtual Acad::ErrorStatus hasHyperlink(const AcDbObjectIdArray*&,bool&,bool = true) = 0;
    virtual Acad::ErrorStatus setHyperlinkCollection(AcDbObject*,AcDbHyperlinkCollection*) = 0;
};
