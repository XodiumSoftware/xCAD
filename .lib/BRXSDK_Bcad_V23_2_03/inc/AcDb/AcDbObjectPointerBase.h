// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbGlobal.h"

/** _ */
template<class OBJ> class AcDbObjectPointerBase
{
protected:
    OBJ* m_ptr;
    Acad::ErrorStatus m_status;

public:
    AcDbObjectPointerBase(); 
    AcDbObjectPointerBase(AcDbObjectPointerBase&&);
protected:
    AcDbObjectPointerBase(AcDbObjectId, AcDb::OpenMode = AcDb::kForRead, bool = false);
private:
    AcDbObjectPointerBase(AcDbObjectPointerBase&);
public:
    virtual ~AcDbObjectPointerBase();

private:
    Acad::ErrorStatus deleteOrClosePtr();
public:
    Acad::ErrorStatus acquire(OBJ*&);
    Acad::ErrorStatus close();
    Acad::ErrorStatus create();
    Acad::ErrorStatus open(AcDbObjectId, AcDb::OpenMode = AcDb::kForRead, bool = false);
    Acad::ErrorStatus openStatus() const;
    Acad::ErrorStatus release(OBJ*&);
    const OBJ* object() const;
private:
    AcDbObjectPointerBase& operator=(AcDbObjectPointerBase&);
public:
    OBJ* object();
    const OBJ* operator->() const;
    OBJ* operator->();
    operator const OBJ*() const;
    operator OBJ*();
    AcDbObjectPointerBase& operator=(AcDbObjectPointerBase&&);
};

template<class OBJ>
AcDbObjectPointerBase<OBJ>::AcDbObjectPointerBase()
{
    m_ptr = NULL;
    m_status = Acad::eNullObjectPointer;
}

template<class OBJ>
AcDbObjectPointerBase<OBJ>::AcDbObjectPointerBase(AcDbObjectId id, AcDb::OpenMode eOM, bool erased)
{
    m_ptr = NULL;
    m_status = acdbOpenObject(m_ptr, id, eOM, erased);
}

template<class OBJ>
AcDbObjectPointerBase<OBJ>::~AcDbObjectPointerBase()
{
    deleteOrClosePtr();
}

template<class OBJ>
Acad::ErrorStatus AcDbObjectPointerBase<OBJ>::deleteOrClosePtr()
{
    if (!m_ptr)
    {
        m_status = Acad::eNullObjectPointer;
        return Acad::eOk;
    }

    if (m_ptr->objectId().isNull())
    {
        delete m_ptr;
        m_ptr = NULL;
        m_status = Acad::eNullObjectPointer;
        return Acad::eOk;
    }

    Acad::ErrorStatus status = m_ptr->close();
    m_ptr = NULL;
    m_status = Acad::eNullObjectPointer;
    return status;
}

template<class OBJ>
Acad::ErrorStatus AcDbObjectPointerBase<OBJ>::acquire(OBJ*& pObj)
{
    if (!pObj)
        return Acad::eNullObjectPointer;

    Acad::ErrorStatus status = deleteOrClosePtr();
    if (Acad::eOk != status)
        return status;

    m_ptr = pObj;
    pObj = NULL;

    m_status = Acad::eOk;
    return m_status;
}

template<class OBJ>
Acad::ErrorStatus AcDbObjectPointerBase<OBJ>::close()
{
    if (!m_ptr)
        return Acad::eNullObjectPointer;

    return deleteOrClosePtr();
}

template<class OBJ>
Acad::ErrorStatus AcDbObjectPointerBase<OBJ>::create()
{
    Acad::ErrorStatus status = deleteOrClosePtr();
    if (Acad::eOk != status)
        return status;

    m_ptr = new OBJ;
    if (!m_ptr)
        return Acad::eNullObjectPointer;

    m_status = Acad::eOk;
    return m_status;
}

template<class OBJ>
Acad::ErrorStatus AcDbObjectPointerBase<OBJ>::open(AcDbObjectId id, AcDb::OpenMode eOM, bool erased)
{
    Acad::ErrorStatus status = deleteOrClosePtr();
    if (Acad::eOk != status)
        return status;

    m_status = acdbOpenObject(m_ptr, id, eOM, erased);
    return m_status;
}

template<class OBJ>
Acad::ErrorStatus AcDbObjectPointerBase<OBJ>::openStatus() const
{
    return m_status;
}

template<class OBJ>
Acad::ErrorStatus AcDbObjectPointerBase<OBJ>::release(OBJ*& pObj)
{
    if (!m_ptr)
        return Acad::eNullObjectPointer;

    pObj = m_ptr;
    m_ptr = NULL;
    m_status = Acad::eNullObjectPointer;

    return Acad::eOk;
}

template<class OBJ>
const OBJ* AcDbObjectPointerBase<OBJ>::object() const
{
    return m_ptr;
}

template<class OBJ>
OBJ* AcDbObjectPointerBase<OBJ>::object()
{
    return m_ptr;
}

template<class OBJ>
const OBJ* AcDbObjectPointerBase<OBJ>::operator->() const
{
    return object();
}

template<class OBJ>
OBJ* AcDbObjectPointerBase<OBJ>::operator->()
{
    return object();
}

template<class OBJ>
AcDbObjectPointerBase<OBJ>::operator const OBJ*() const
{
    return object();
}

template<class OBJ>
AcDbObjectPointerBase<OBJ>::operator OBJ*()
{
    return object();
}

template<class OBJ>
inline AcDbObjectPointerBase<OBJ>::AcDbObjectPointerBase(AcDbObjectPointerBase&& other) 
    : m_ptr(NULL), m_status(Acad::eNullObjectPointer)
{
    *this = other;
}

template<class OBJ>
inline AcDbObjectPointerBase<OBJ>& AcDbObjectPointerBase<OBJ>::operator=(AcDbObjectPointerBase&& other)
{
    if (*this != other)
    {
        m_ptr = std::move(other.m_ptr);
        m_status = std::move(other.m_status);

        other.m_ptr = NULL;
        other.m_status = Acad::eNullObjectPointer;
    }
    return *this;
}
