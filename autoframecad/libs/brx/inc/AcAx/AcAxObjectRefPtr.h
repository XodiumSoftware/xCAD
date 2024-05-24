// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcAx/AcAxObjectRef.h"
#include "AcDb/AcDbObjectPointer.h"

/** _ */
template<class OBJ> class AcAxObjectRefPtr: public AcDbObjectPointer<OBJ>
{
private:
    AcAxObjectRef* const m_pObjRef;

public:
    AcAxObjectRefPtr();
    AcAxObjectRefPtr(AcAxObjectRef* const,AcDb::OpenMode,bool = false);
private:
    AcAxObjectRefPtr(AcAxObjectRefPtr&);
public:
    ~AcAxObjectRefPtr();

private:
    AcAxObjectRefPtr& operator=(AcAxObjectRefPtr&);
};

template<class OBJ>
AcAxObjectRefPtr<OBJ>::AcAxObjectRefPtr()
:AcDbObjectPointer<OBJ>()
,m_pObjRef(NULL)
{
}

template<class OBJ>
AcAxObjectRefPtr<OBJ>::AcAxObjectRefPtr(AcAxObjectRef* const pObjRef,AcDb::OpenMode eOM,bool erased)
:m_pObjRef(pObjRef)
{
    if (!m_pObjRef)
    {
        this->m_status = Acad::eNullObjectPointer;
        return;
    }

    AcDbObjectId id = m_pObjRef->objectId();

    if (id.isNull())
    {
        AcDbObject* pNakedObj = NULL;
        m_pObjRef->release(id,pNakedObj);

        OBJ* pOBJ = OBJ::cast(pNakedObj);
        if (!pOBJ)
        {
            m_pObjRef->acquire(pNakedObj);
            this->m_ptr = NULL;
            this->m_status = Acad::eNotThatKindOfClass;
            return;
        }

        this->acquire(pOBJ);
        return;
    }

    this->m_status = acdbOpenObject(this->m_ptr,id,eOM,erased);
}

template<class OBJ>
AcAxObjectRefPtr<OBJ>::~AcAxObjectRefPtr()
{
    if (!this->m_ptr)
        return;

    AcDbObjectId id = this->m_ptr->objectId();
    if (!id.isNull())
        return;

    OBJ* pOBJ = NULL;
    this->release(pOBJ);
    m_pObjRef->acquire(reinterpret_cast<AcDbObject*&>(pOBJ));
}

typedef AcAxObjectRefPtr<AcDbObject> AcDbObjectRefPtr;
typedef AcAxObjectRefPtr<AcDbEntity> AcDbEntityRefPtr;
