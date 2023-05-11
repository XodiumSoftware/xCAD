// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbObjectPointerBase.h"

/** _ */
template<class OBJ> class AcDbSymbolTableRecordPointer : public AcDbObjectPointerBase<OBJ>
{
public:
    AcDbSymbolTableRecordPointer();
    AcDbSymbolTableRecordPointer(AcDbObjectId, AcDb::OpenMode = AcDb::kForRead, bool = false);
    AcDbSymbolTableRecordPointer(const ACHAR*, AcDbDatabase*, AcDb::OpenMode = AcDb::kForRead, bool = false);
private:
    AcDbSymbolTableRecordPointer(AcDbSymbolTableRecordPointer&);

public:
    Acad::ErrorStatus open(AcDbObjectId, AcDb::OpenMode = AcDb::kForRead, bool = false);
    Acad::ErrorStatus open(const ACHAR*, AcDbDatabase*, AcDb::OpenMode = AcDb::kForRead, bool = false);

private:
    AcDbSymbolTableRecordPointer& operator=(AcDbSymbolTableRecordPointer&);
};

template<class OBJ>
AcDbSymbolTableRecordPointer<OBJ>::AcDbSymbolTableRecordPointer() :
    AcDbObjectPointerBase<OBJ>()
{
}

template<class OBJ>
AcDbSymbolTableRecordPointer<OBJ>::AcDbSymbolTableRecordPointer(AcDbObjectId id, AcDb::OpenMode eOM, bool erased)
    : AcDbObjectPointerBase<OBJ>(id, eOM, erased)
{
}

template<class OBJ>
AcDbSymbolTableRecordPointer<OBJ>::AcDbSymbolTableRecordPointer(const ACHAR* pStrName, AcDbDatabase* pDb, AcDb::OpenMode eOM, bool erased)
    : AcDbObjectPointerBase<OBJ>()
{
    if (!pStrName)
    {
        this->m_status = Acad::eInvalidInput;
        return;
    }

    AcDbSymbolTablePointer<typename OBJ::TableType> symbolTable(pDb, AcDb::kForRead);
    this->m_status = symbolTable.openStatus();
    if (Acad::eOk != this->m_status)
        return;

    this->m_status = symbolTable->getAt(pStrName, this->m_ptr, eOM, erased);
}

template<class OBJ>
Acad::ErrorStatus AcDbSymbolTableRecordPointer<OBJ>::open(AcDbObjectId id, AcDb::OpenMode eOM, bool erased)
{
    return AcDbObjectPointerBase<OBJ>::open(id, eOM, erased);
}

template<class OBJ>
Acad::ErrorStatus AcDbSymbolTableRecordPointer<OBJ>::open(const ACHAR* pStrName, AcDbDatabase* pDb, AcDb::OpenMode eOM, bool erased)
{
    if (!pStrName)
        return Acad::eInvalidInput;

    AcDbSymbolTablePointer<typename OBJ::TableType>  symbolTable(pDb, AcDb::kForRead);
    Acad::ErrorStatus status = symbolTable.openStatus();
    if (Acad::eOk != status)
        return status;

    if (this->m_ptr)
    {
        status = this->close();
        if (Acad::eOk != status)
            return status;
    }

    this->m_status = symbolTable->getAt(pStrName, this->m_ptr, eOM, erased);
    return this->m_status;
}

typedef AcDbSymbolTableRecordPointer<AcDbBlockTableRecord> AcDbBlockTableRecordPointer;
typedef AcDbSymbolTableRecordPointer<AcDbDimStyleTableRecord> AcDbDimStyleTableRecordPointer;
typedef AcDbSymbolTableRecordPointer<AcDbLayerTableRecord> AcDbLayerTableRecordPointer;
typedef AcDbSymbolTableRecordPointer<AcDbLinetypeTableRecord> AcDbLinetypeTableRecordPointer;
typedef AcDbSymbolTableRecordPointer<AcDbRegAppTableRecord> AcDbRegAppTableRecordPointer;
typedef AcDbSymbolTableRecordPointer<AcDbTextStyleTableRecord> AcDbTextStyleTableRecordPointer;
typedef AcDbSymbolTableRecordPointer<AcDbUCSTableRecord> AcDbUCSTableRecordPointer;
typedef AcDbSymbolTableRecordPointer<AcDbViewportTableRecord> AcDbViewportTableRecordPointer;
typedef AcDbSymbolTableRecordPointer<AcDbViewTableRecord> AcDbViewTableRecordPointer;
