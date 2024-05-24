// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbObjectPointerBase.h"

/** _ */
template<class OBJ> class AcDbSymbolTablePointer: public AcDbObjectPointerBase<OBJ>
{
public:
    AcDbSymbolTablePointer();
    AcDbSymbolTablePointer(AcDbDatabase*,AcDb::OpenMode = AcDb::kForRead);
    AcDbSymbolTablePointer(AcDbObjectId,AcDb::OpenMode = AcDb::kForRead);
private:
    AcDbSymbolTablePointer(AcDbSymbolTablePointer&);

public:
    Acad::ErrorStatus open(AcDbDatabase*,AcDb::OpenMode = AcDb::kForRead);
    Acad::ErrorStatus open(AcDbObjectId,AcDb::OpenMode = AcDb::kForRead);

private:
    AcDbSymbolTablePointer& operator=(AcDbSymbolTablePointer&);
};

template<class OBJ>
AcDbSymbolTablePointer<OBJ>::AcDbSymbolTablePointer() :
AcDbObjectPointerBase<OBJ>()
{
}

template<class OBJ>
AcDbSymbolTablePointer<OBJ>::AcDbSymbolTablePointer(AcDbDatabase* pDb,AcDb::OpenMode eOM) :
AcDbObjectPointerBase<OBJ>()
{
    if (!pDb)
    {
        AcDbSymbolTablePointer::m_status = Acad::eNullObjectPointer;
        return;
    }

    AcDbSymbolTablePointer::m_status = pDb->getSymbolTable(AcDbSymbolTablePointer::m_ptr,eOM);
}

template<class OBJ>
AcDbSymbolTablePointer<OBJ>::AcDbSymbolTablePointer(AcDbObjectId id,AcDb::OpenMode eOM) :
AcDbObjectPointerBase<OBJ>(id,eOM,false)
{
}

template<class OBJ>
Acad::ErrorStatus AcDbSymbolTablePointer<OBJ>::open(AcDbDatabase* pDb,AcDb::OpenMode eOM)
{
    if (!pDb)
        return Acad::eInvalidInput;

    if (AcDbSymbolTablePointer::m_ptr)
    {
        Acad::ErrorStatus status = AcDbSymbolTablePointer::close();
        if (Acad::eOk != status)
            return status;
    }

    AcDbSymbolTablePointer::m_status = pDb->getSymbolTable(AcDbSymbolTablePointer::m_ptr,eOM);
    return AcDbSymbolTablePointer::m_status;
}

template<class OBJ>
Acad::ErrorStatus AcDbSymbolTablePointer<OBJ>::open(AcDbObjectId id,AcDb::OpenMode eOM)
{
    return AcDbObjectPointerBase<OBJ>::open(id,eOM,false);
}

typedef AcDbSymbolTablePointer<AcDbBlockTable> AcDbBlockTablePointer;
typedef AcDbSymbolTablePointer<AcDbDimStyleTable> AcDbDimStyleTablePointer;
typedef AcDbSymbolTablePointer<AcDbLayerTable> AcDbLayerTablePointer;
typedef AcDbSymbolTablePointer<AcDbLinetypeTable> AcDbLinetypeTablePointer;
typedef AcDbSymbolTablePointer<AcDbRegAppTable> AcDbRegAppTablePointer;
typedef AcDbSymbolTablePointer<AcDbTextStyleTable> AcDbTextStyleTablePointer;
typedef AcDbSymbolTablePointer<AcDbUCSTable> AcDbUCSTablePointer;
typedef AcDbSymbolTablePointer<AcDbViewportTable> AcDbViewportTablePointer;
typedef AcDbSymbolTablePointer<AcDbViewTable> AcDbViewTablePointer;
