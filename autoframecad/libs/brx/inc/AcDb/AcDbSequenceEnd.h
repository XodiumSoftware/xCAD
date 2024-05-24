// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
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
