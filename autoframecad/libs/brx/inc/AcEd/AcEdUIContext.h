// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
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