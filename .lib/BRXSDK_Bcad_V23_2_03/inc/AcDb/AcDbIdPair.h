// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbObjectId.h"

/** _ */
class BRX_IMPORTEXPORT AcDbIdPair
{
private:
    AcDbObjectId m_keyId;
    AcDbObjectId m_valueId;
    bool m_isCloned;
    bool m_isOwnerXlated;
    bool m_isPrimary;

public:
    AcDbIdPair();
    AcDbIdPair(const AcDbIdPair&);
    AcDbIdPair(AcDbObjectId,AcDbObjectId,bool,bool = false,bool = true);

    AcDbObjectId key() const;
    AcDbObjectId value() const;
    bool isCloned() const;
    bool isOwnerXlated() const;
    bool isPrimary() const;
    void setIsCloned(bool);
    void setIsOwnerXlated(bool);
    void setIsPrimary(bool);
    void setKey(AcDbObjectId);
    void setValue(AcDbObjectId);
};

template<> struct T_AcArrayAllocatorSelector<AcDbIdPair, false> {
  typedef AcArrayMemCopyReallocator<AcDbIdPair> Allocator;
}; //AcDbIdPair can use fast MemCopyReallocator
