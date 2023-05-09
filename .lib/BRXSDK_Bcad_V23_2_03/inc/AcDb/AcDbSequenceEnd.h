// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbEntity.h"

/** _ */
class BRX_EXPORT AcDbSequenceEnd: public AcDbEntity
{
public:
    ACDB_DECLARE_MEMBERS(AcDbSequenceEnd);

    AcDbSequenceEnd();
    ~AcDbSequenceEnd();

    virtual bool castShadows() const;
    virtual bool receiveShadows() const;
    virtual void setCastShadows(bool);
    virtual void setReceiveShadows(bool);

protected:
    virtual Adesk::Boolean subWorldDraw(AcGiWorldDraw*);
    virtual Acad::ErrorStatus subTransformBy(const AcGeMatrix3d&);
};
