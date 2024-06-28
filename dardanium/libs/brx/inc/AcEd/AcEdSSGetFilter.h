// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcEd/AcEdInputContextReactor.h"
#include "AcEd/AcEdSelectionSetService.h"

typedef AcArray< AcDbIntArray, AcArrayObjectCopyReallocator<AcDbIntArray> > AcDbArrayIntArray;

/** _ */
class BRX_IMPORTEXPORT AcEdSSGetFilter: public AcEdInputContextReactor
{
public:
//BRX START
    AcEdSSGetFilter();
    virtual ~AcEdSSGetFilter();
//BRX_END
public:
    virtual void endEntsel(Acad::PromptStatus,const AcDbObjectId&,const AcGePoint3d&,AcEdSelectionSetService&) {}
    virtual void endSSGet(Acad::PromptStatus,int,AcEdSelectionSetService&,const AcDbObjectIdArray&) {}
    virtual void ssgetAddFailed(int,int,AcEdSelectionSetService&,const AcDbObjectIdArray&,resbuf*) {}
    virtual void ssgetAddFilter(int,AcEdSelectionSetService&,const AcDbObjectIdArray&,const AcDbObjectIdArray&) {}
    virtual void ssgetRemoveFailed(int,int,AcEdSelectionSetService&,const AcDbObjectIdArray&,resbuf*,AcDbIntArray&,AcDbArrayIntArray&) {}
    virtual void ssgetRemoveFilter(int,AcEdSelectionSetService&,const AcDbObjectIdArray&,const AcDbObjectIdArray&,AcDbIntArray&,AcDbArrayIntArray&) {}
};