// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
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
