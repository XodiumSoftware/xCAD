// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbFullSubentPath.h"

/** _ */
class BRX_IMPORTEXPORT AcEdUIContext: public AcRxObject
{
public:
    ACRX_DECLARE_MEMBERS(AcEdUIContext);

    virtual void onCommand(Adesk::UInt32) = 0;
    virtual void OnUpdateMenu();
    virtual void* getMenuContext(const AcRxClass*,const AcDbObjectIdArray&) = 0;
    virtual void* getMenuContext(const AcRxClass*,const AcDbObjectIdArray&,const AcArray< AcDbFullSubentPathArray,AcArrayObjectCopyReallocator<AcDbFullSubentPathArray> >&);
};