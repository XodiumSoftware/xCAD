// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "brx_platform_3264.h"
#include "AcDb/AcDbHandle.h"

#if defined(__GNUC__) && (__GNUC__ >= 8)
#  pragma GCC diagnostic push
#  pragma GCC diagnostic ignored "-Wclass-memaccess" // for AcArray [with T = AcDbObjectId; R = AcArrayMemCopyReallocator]
#endif
#include "Misc/AcArray.h"
#if defined(__GNUC__) && (__GNUC__ >= 8)
#  pragma GCC diagnostic pop
#endif

#ifdef __cplusplus

class AcDbDatabase;
class AcRxClass;

/** _ */
class BRX_IMPORTEXPORT AcDbObjectId
{
protected:
    AcDbStub* mId;

public:
    static const AcDbObjectId kNull;

    AcDbObjectId();
    AcDbObjectId(const AcDbStub*);

    AcDbDatabase* database() const;
    AcDbDatabase* originalDatabase() const;
    AcDbHandle handle() const;
    AcDbHandle nonForwardedHandle() const;
    AcDbObjectId& setFromOldId(LONG_PTR);
#ifdef __SYS_64_BIT__ // only on 64 bit systems
    AcDbObjectId& setFromOldId(ULONG_PTR);
#endif
    bool isEffectivelyErased() const;
    bool isErased() const;
    bool isNull() const;
    bool isValid() const;
    bool objectLeftOnDisk() const;
    LONG_PTR asOldId() const;
    void convertToRedirectedId();
    void setNull();
    bool isResident() const;
    AcRxClass* objectClass() const;

    AcDbObjectId& operator=(const AcDbObjectId&);
    AcDbObjectId& operator=(const AcDbStub*);
    bool operator!=(const AcDbObjectId&) const;
    bool operator!=(const AcDbStub*) const;
    bool operator<(const AcDbObjectId&) const;
    bool operator<(const AcDbStub*) const;
    bool operator<=(const AcDbObjectId&) const;
    bool operator<=(const AcDbStub*) const;
    bool operator==(const AcDbObjectId&) const;
    bool operator==(const AcDbStub*) const;
    bool operator>(const AcDbObjectId&) const;
    bool operator>(const AcDbStub*) const;
    bool operator>=(const AcDbObjectId&) const;
    bool operator>=(const AcDbStub*) const;
    operator AcDbStub*() const;
};

template<> struct T_AcArrayAllocatorSelector<AcDbObjectId, false> {
  typedef AcArrayMemCopyReallocator<AcDbObjectId> Allocator;
}; //AcDbObjectId can use fast MemCopyReallocator
typedef AcArray< AcDbObjectId, AcArrayMemCopyReallocator< AcDbObjectId > > AcDbObjectIdArray;

#endif //__cplusplus
