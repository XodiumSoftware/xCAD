// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbObjectPointerBase.h"

/** _ */
template<class OBJ> class AcDbObjectPointer : public AcDbObjectPointerBase<OBJ>
{
public:
    AcDbObjectPointer();
    AcDbObjectPointer(AcDbObjectPointer&&);
    AcDbObjectPointer(AcDbObjectId, AcDb::OpenMode = AcDb::kForRead, bool = false);

    Acad::ErrorStatus open(AcDbObjectId, AcDb::OpenMode = AcDb::kForRead, bool = false);
    AcDbObjectPointer& operator=(AcDbObjectPointer&&);
};

template<class OBJ>
AcDbObjectPointer<OBJ>::AcDbObjectPointer() :
    AcDbObjectPointerBase<OBJ>()
{
}

template<class OBJ>
AcDbObjectPointer<OBJ>::AcDbObjectPointer(AcDbObjectPointer&& other) :
    AcDbObjectPointerBase<OBJ>(std::move(other))
{
}

template<class OBJ>
AcDbObjectPointer<OBJ>::AcDbObjectPointer(AcDbObjectId id, AcDb::OpenMode eOM, bool erased)
    : AcDbObjectPointerBase<OBJ>(id, eOM, erased)
{
}

template<class OBJ>
Acad::ErrorStatus AcDbObjectPointer<OBJ>::open(AcDbObjectId id, AcDb::OpenMode eOM, bool erased)
{
    return AcDbObjectPointerBase<OBJ>::open(id, eOM, erased);
}


template<class OBJ>
inline AcDbObjectPointer<OBJ>& AcDbObjectPointer<OBJ>::operator=(AcDbObjectPointer&& other)
{
    AcDbObjectPointerBase<OBJ>::operator=(std::move(other));
    return *this;
}


typedef AcDbObjectPointer<AcDbDictionary> AcDbDictionaryPointer;
typedef AcDbObjectPointer<AcDbEntity> AcDbEntityPointer;
