// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbObjectPointerBase.h"

/** _ */
template<class OBJ> class AcDbObjectPointer : public AcDbObjectPointerBase<OBJ>
{
public:
    AcDbObjectPointer();
    AcDbObjectPointer(AcDbObjectId, AcDb::OpenMode = AcDb::kForRead, bool = false);
private:
    AcDbObjectPointer(AcDbObjectPointer&);

public:
    Acad::ErrorStatus open(AcDbObjectId, AcDb::OpenMode = AcDb::kForRead, bool = false);

private:
    AcDbObjectPointer& operator=(AcDbObjectPointer&);
};

template<class OBJ>
AcDbObjectPointer<OBJ>::AcDbObjectPointer() :
    AcDbObjectPointerBase<OBJ>()
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

typedef AcDbObjectPointer<AcDbDictionary> AcDbDictionaryPointer;
typedef AcDbObjectPointer<AcDbEntity> AcDbEntityPointer;
