// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbObjectReactor.h"

/** _ */
class BRX_IMPORTEXPORT AcDbEntityReactor: public AcDbObjectReactor
{
public:
    ACRX_DECLARE_MEMBERS(AcDbEntityReactor);

protected:
    AcDbEntityReactor();

public:
    virtual void dragCloneToBeDeleted(const AcDbEntity*,const AcDbEntity*);
    virtual void modifiedGraphics(const AcDbEntity*);
};
