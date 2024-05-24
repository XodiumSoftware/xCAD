// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbObject.h"

/** _ */
class BRX_EXPORT AcDbSortentsTable: public AcDbObject
{
public:
    ACRX_DECLARE_MEMBERS(AcDbSortentsTable);

    AcDbSortentsTable();
    virtual ~AcDbSortentsTable();

    virtual Acad::ErrorStatus applyPartialUndo(AcDbDwgFiler*,AcRxClass*);
    virtual Acad::ErrorStatus audit(AcDbAuditInfo*);
    virtual Acad::ErrorStatus dwgInFields(AcDbDwgFiler*);
    virtual Acad::ErrorStatus dwgOutFields(AcDbDwgFiler*) const;
    virtual Acad::ErrorStatus dxfInFields(AcDbDxfFiler*);
    virtual Acad::ErrorStatus dxfOutFields(AcDbDxfFiler*) const;

    Acad::ErrorStatus firstEntityIsDrawnBeforeSecond(AcDbObjectId,AcDbObjectId,bool&) const;
    Acad::ErrorStatus getFullDrawOrder(AcDbObjectIdArray&,Adesk::UInt8 = 0) const;
    Acad::ErrorStatus getRelativeDrawOrder(AcDbObjectIdArray&,Adesk::UInt8 = 0) const;
    Acad::ErrorStatus moveAbove(const AcDbObjectIdArray&,AcDbObjectId);
    Acad::ErrorStatus moveBelow(const AcDbObjectIdArray&,AcDbObjectId);
    Acad::ErrorStatus moveToBottom(const AcDbObjectIdArray&);
    Acad::ErrorStatus moveToTop(const AcDbObjectIdArray&);
    Acad::ErrorStatus remove(AcDbObjectId);
    Acad::ErrorStatus setBlockId(AcDbObjectId);
    Acad::ErrorStatus setRelativeDrawOrder(const AcDbObjectIdArray&);
    Acad::ErrorStatus swapOrder(AcDbObjectId,AcDbObjectId);
    AcDbObjectId blockId() const;
    Adesk::Boolean sortAs(AcDbObjectId,AcDbHandle&) const;
    void getSortHandle(AcDbObjectId,AcDbHandle&) const;
};
