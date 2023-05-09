// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbDynBlockReferenceProperty.h"


/** _ */
class AcDbDynBlockReference: public AcHeapOperators
{
public:
    AcDbDynBlockReference(AcDbObjectId);
    AcDbDynBlockReference(AcDbBlockReference*);
    virtual ~AcDbDynBlockReference();

    Acad::ErrorStatus convertToStaticBlock();
    Acad::ErrorStatus convertToStaticBlock(const AcString&);
    Acad::ErrorStatus resetBlock();
    AcDbObjectId anonymousBlockTableRecord() const;
    AcDbObjectId blockId() const;
    AcDbObjectId dynamicBlockTableRecord() const;
    bool isDynamicBlock() const;
    void getBlockProperties(AcDbDynBlockReferencePropertyArray&) const;

    static bool isDynamicBlock(AcDbObjectId);
private:
//BRX START
    class BrxDbDynBlockReferenceImp* m_pBrxImpl;
//BRX END
};
