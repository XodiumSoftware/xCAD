// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbGlobal.h"
#include "AcRx/AcRxClass.h"
#include "Misc/AcArray.h"
#include "Misc/AcHeapOperators.h"

#ifdef __cplusplus

/** _ */
class BRX_IMPORTEXPORT AcDbSubentId : public AcHeapOperators
{
private:
    AcDb::SubentType m_type;
    AcRxClass* m_pClass;
    INT_PTR m_index;

public:
    AcDbSubentId();
    AcDbSubentId(AcDb::SubentType,INT_PTR);
    AcDbSubentId(AcRxClass*,INT_PTR);

    AcDb::SubentType type() const;
    AcRxClass* typeClass() const;
    INT_PTR index() const;
    void setIndex(INT_PTR);
    void setType(AcDb::SubentType);
    void setTypeClass(AcRxClass*);

    bool operator!=(const AcDbSubentId&) const;
    bool operator==(const AcDbSubentId&) const;
};

//BRX START
BRX_IMPORTEXPORT
//BRX END
extern const AcDbSubentId kNullSubentId;
const INT_PTR kNullSubentIndex = 0;

template<> struct T_AcArrayAllocatorSelector<AcDbSubentId, false> {
  typedef AcArrayMemCopyReallocator<AcDbSubentId> Allocator;
}; //AcDbSubentId can use fast MemCopyReallocator
typedef AcArray< AcDbSubentId, AcArrayMemCopyReallocator< AcDbSubentId > > AcDbSubentIdArray;
typedef AcArray< AcDbSubentId* > AcDbSubentIdPtrArray;

#endif //__cplusplus
