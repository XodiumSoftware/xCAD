// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbHardOwnershipId.h"
#include "AcDb/AcDbHardPointerId.h"
#include "AcDb/AcDbR13ObjectId.h"
#include "AcDb/AcDbSoftOwnershipId.h"
#include "AcDb/AcDbSoftPointerId.h"
#include "AcDb/AcDbSubentId.h"
#include "Misc/AcHeapOperators.h"

#ifdef __cplusplus

/** _ */
class BRX_IMPORTEXPORT AcDbFullSubentPath : public AcHeapOperators
{
private:
    AcDbSubentId m_seId;
    AcDbObjectIdArray m_ids;

public:
    AcDbFullSubentPath();
    AcDbFullSubentPath(AcDb::SubentType,INT_PTR);
    AcDbFullSubentPath(AcDbObjectId,AcDb::SubentType,INT_PTR);
    AcDbFullSubentPath(AcDbObjectId,AcDbSubentId);
    AcDbFullSubentPath(AcDbObjectIdArray,AcDbSubentId);
    AcDbFullSubentPath(const AcDbFullSubentPath&);
    ~AcDbFullSubentPath();

    AcDbObjectIdArray& objectIds();
    AcDbSubentId& subentId();
    const AcDbObjectIdArray& objectIds() const;
    const AcDbSubentId subentId() const;
    void objectIds(AcDbObjectIdArray&) const;

    AcDbFullSubentPath& operator=(const AcDbFullSubentPath&);
    bool operator!=(const AcDbFullSubentPath&) const;
    bool operator==(const AcDbFullSubentPath&) const;
};

typedef AcArray< AcDbFullSubentPath, AcArrayObjectCopyReallocator<AcDbFullSubentPath> > AcDbFullSubentPathArray;
typedef AcArray< AcDbFullSubentPath* > AcDbFullSubentPathPtrArray;
typedef AcDbFullSubentPathArray AcSubentPathArray;

//BRX START
BRX_IMPORTEXPORT
//BRX END
extern const AcDbFullSubentPath kNullSubent;

#endif //__cplusplus
