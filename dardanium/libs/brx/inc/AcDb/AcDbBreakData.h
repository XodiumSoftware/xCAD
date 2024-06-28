// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbObject.h"

class AcDbBreakPointRef;

    /** _ */
class BRX_EXPORT AcDbBreakData : public AcDbObject
{
  public:
    ACDB_DECLARE_MEMBERS(AcDbBreakData);

    AcDbBreakData();
    ~AcDbBreakData();

    AcDbObjectId dimObjId() const;
    Acad::ErrorStatus setDimObjId(const AcDbObjectId&);
    Acad::ErrorStatus addBreakPointRef(AcDbBreakPointRef*);
    Acad::ErrorStatus getBreakPointRef(AcArray<AcDbBreakPointRef*>&) const;
    Acad::ErrorStatus getBreakPointRef(int, AcArray<AcDbBreakPointRef*>&) const;
    Acad::ErrorStatus postToDb(AcDbObjectId&);
    Acad::ErrorStatus eraseFromDb();
    Acad::ErrorStatus deleteAllBreakPointRefs();
    Acad::ErrorStatus removeAssociativity(bool);
    Acad::ErrorStatus dwgInFields(AcDbDwgFiler*) override;
    Acad::ErrorStatus dwgOutFields(AcDbDwgFiler*) const;
    Acad::ErrorStatus dxfInFields(AcDbDxfFiler*) override;
    Acad::ErrorStatus dxfOutFields(AcDbDxfFiler*) const;
};
