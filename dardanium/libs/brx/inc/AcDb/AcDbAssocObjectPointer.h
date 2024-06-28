// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbAssocActionBody.h"
#include "AcDb/AcDbAssocDependencyBody.h"
#include "AcDb/AcDbObjectPointer.h"
#include "AcDbSmartObjectPointer.h"

template<class OBJ> class AcDbAssocObjectPointer
{
public:
    AcDbAssocObjectPointer(AcDbObjectId, AcDb::OpenMode, bool = false, bool = false);
    AcDbAssocObjectPointer( AcDbAssocAction*, AcDbObjectId, AcDb::OpenMode, bool = false, bool = false);
    AcDbAssocObjectPointer(const AcDbAssocActionBody*, AcDbObjectId, AcDb::OpenMode, bool = false, bool = false);
    AcDbAssocObjectPointer(const AcDbAssocDependency*, AcDbObjectId , AcDb::OpenMode, bool = false, bool = false);
    AcDbAssocObjectPointer(const AcDbAssocDependencyBody*, AcDbObjectId, AcDb::OpenMode, bool = false, bool = false);
    AcDbAssocObjectPointer(AcDbAssocAction*, OBJ*);
    AcDbAssocObjectPointer(const AcDbAssocActionBody*, OBJ* pObject);
    AcDbAssocObjectPointer(AcDbAssocObjectPointer&&);

    ~AcDbAssocObjectPointer();

    Acad::ErrorStatus openStatus() const;
    bool isSubstituteObject() const { return m_pCopyObj != NULL; }
    const OBJ* operator->() const { return m_pObj; }
    OBJ* operator->() { return m_pObj; }
    operator const OBJ* () const { return m_pObj; }
    operator OBJ* () { return m_pObj; }
    AcDbAssocObjectPointer& operator=(AcDbAssocObjectPointer&&);

private:
    AcDbAssocAction* const m_pAction;
    const AcDbAssocActionBody* const m_pActionBody;
    const AcDbAssocDependency* const m_pDependency;
    const AcDbAssocDependencyBody* const m_pDependencyBody;
    const AcDbObjectId m_pId;
    AcDbSmartObjectPointer<OBJ> m_pPtrObj;
    OBJ* m_pObj;
    AcDbObject* m_pCopyObj;
    Acad::ErrorStatus m_pErrorStatus;

    void setup(AcDbAssocAction*, AcDb::OpenMode, bool, bool);
    AcDbAssocObjectPointer();
    AcDbAssocObjectPointer(const AcDbAssocObjectPointer&);
    AcDbAssocObjectPointer& operator=(const AcDbAssocObjectPointer&);
};

inline AcDbAssocAction* acdbAssocGetCurrentlyEvaluatedActionPointer(AcDbObjectId objectId)
{
    AcDbAssocAction* pAction;
    Acad::ErrorStatus es = acdbOpenObject(pAction, objectId, AcDb::kForRead);
    if (pAction == NULL || es != Acad::eOk)
        return nullptr;
    return pAction;
}

template<class OBJ>
inline AcDbAssocObjectPointer<OBJ>::AcDbAssocObjectPointer(AcDbObjectId currentId, AcDb::OpenMode mode, bool isErased, bool isLocked)
  : m_pAction(acdbAssocGetCurrentlyEvaluatedActionPointer(currentId)),
    m_pActionBody(NULL),
    m_pDependency(NULL),
    m_pDependencyBody(NULL),
    m_pId(currentId),
    m_pObj(NULL),
    m_pCopyObj(NULL),
    m_pErrorStatus(Acad::eNullObjectId)
{
    setup(m_pAction, mode, isErased, isLocked);
}

template<class OBJ>
inline AcDbAssocObjectPointer<OBJ>::AcDbAssocObjectPointer(AcDbAssocAction* pAction, AcDbObjectId id, AcDb::OpenMode mode, bool isErased, bool isLocked)
  : m_pAction(pAction),
    m_pActionBody(NULL),
    m_pDependency(NULL),
    m_pDependencyBody(NULL),
    m_pId(id),
    m_pObj(NULL),
    m_pCopyObj(NULL),
    m_pErrorStatus(Acad::eNullObjectId)
{
    setup(pAction, mode, isErased, isLocked);
}

template<class OBJ>
inline AcDbAssocObjectPointer<OBJ>::AcDbAssocObjectPointer(const AcDbAssocActionBody* pActionBody, AcDbObjectId id, AcDb::OpenMode mode, bool isErased, bool isLocked)
  : m_pAction(NULL),
    m_pActionBody(pActionBody),
    m_pDependency(NULL),
    m_pDependencyBody(NULL),
    m_pId(id),
    m_pObj(NULL),
    m_pCopyObj(NULL),
    m_pErrorStatus(Acad::eNullObjectId)
{
    if (!pActionBody || !m_pActionBody)
        return;
    AcDbObjectId idAssocAction = m_pActionBody->parentAction();
    AcDbObjectPointer<AcDbAssocAction> pAction(idAssocAction, AcDb::kForRead, true);
    if (pAction == NULL)
        return;
    setup(pAction, mode, isErased, isLocked);
}

template<class OBJ>
inline AcDbAssocObjectPointer<OBJ>::AcDbAssocObjectPointer(const AcDbAssocDependency* pDependency, AcDbObjectId id, AcDb::OpenMode mode, bool isErased, bool isLocked)
  : m_pAction(NULL),
    m_pActionBody(NULL),
    m_pDependency(pDependency),
    m_pDependencyBody(NULL),
    m_pId(id),
    m_pObj(NULL),
    m_pCopyObj(NULL),
    m_pErrorStatus(Acad::eNullObjectId)
{
    if (!m_pDependency)
        return;
    AcDbObjectId idAssocAction = m_pDependency->owningAction();
    AcDbObjectPointer<AcDbAssocAction> pAction(idAssocAction, AcDb::kForRead, true);
    if (!pAction)
        return;
    setup(pAction, mode, isErased, isLocked);
}

template<class OBJ>
inline AcDbAssocObjectPointer<OBJ>::AcDbAssocObjectPointer(const AcDbAssocDependencyBody* pDependencyBody, AcDbObjectId id, AcDb::OpenMode mode, bool isErased, bool isLocked)
  : m_pAction(NULL),
    m_pActionBody(NULL),
    m_pDependency(NULL),
    m_pDependencyBody(pDependencyBody),
    m_pId(id),
    m_pObj(NULL),
    m_pCopyObj(NULL),
    m_pErrorStatus(Acad::eNullObjectId)
{
    if (!m_pDependencyBody)
        return;
    AcDbObjectId idDependency = m_pDependencyBody->parentDependency();
    AcDbObjectPointer<AcDbAssocDependency> pDependency(idDependency, AcDb::kForRead, true);
    if (!pDependency)
        return;
    AcDbObjectId idAssocAction = pDependency->owningAction();
    AcDbObjectPointer<AcDbAssocAction> pAction(idAssocAction, AcDb::kForRead, true);
    if (!pAction)
        return;
    setup(pAction, mode, isErased, isLocked);
}

template<class OBJ>
inline AcDbAssocObjectPointer<OBJ>::AcDbAssocObjectPointer(AcDbAssocAction* pAction, OBJ* pObj)
  : m_pAction(pAction),
    m_pActionBody(NULL),
    m_pDependency(NULL),
    m_pDependencyBody(NULL),
    m_pId(AcDbObjectId::kNull),
    m_pObj(pObj),
    m_pCopyObj(pObj),
    m_pErrorStatus(pObj != NULL ? Acad::eOk : Acad::eNullObjectId)
{
    if (!pAction)
        return;
    AcDbAssocEvaluationCallback* pEvalCallback = pAction->currentEvaluationCallback();
    if (!pEvalCallback)
        return;
    AcDbObject* pObjInput = pObj;
    pEvalCallback->beginActionEvaluationUsingObject(pAction, AcDbObjectId::kNull, true, true, pObjInput);
}

template<class OBJ>
inline AcDbAssocObjectPointer<OBJ>::AcDbAssocObjectPointer(const AcDbAssocActionBody* pActionBody, OBJ* pObj)
  : m_pAction(NULL),
    m_pActionBody(pActionBody),
    m_pDependency(NULL),
    m_pDependencyBody(NULL),
    m_pId(AcDbObjectId::kNull),
    m_pObj(pObj),
    m_pCopyObj(pObj),
    m_pErrorStatus(pObj != NULL ? Acad::eOk : Acad::eNullObjectId)
{
    if (!m_pActionBody)
        return;
    AcDbObjectId idAssocAction = m_pActionBody->parentAction();
    AcDbObjectPointer<AcDbAssocAction> pAction(idAssocAction, AcDb::kForRead, true);
    if (!pAction)
        return;
    AcDbAssocEvaluationCallback* const pEvalCallback = pAction->currentEvaluationCallback();
    if (!pEvalCallback)
        return;
    AcDbObject* pObjInput = pObj;
    pEvalCallback->beginActionEvaluationUsingObject(pAction, AcDbObjectId::kNull, true, true, pObjInput);
}

template<class OBJ>
inline void AcDbAssocObjectPointer<OBJ>::setup(AcDbAssocAction* pAction, AcDb::OpenMode mode, bool isErased, bool isLocked)
{
    if (m_pId.isNull())
        return;
    m_pObj = NULL;
    m_pCopyObj = NULL;
    m_pErrorStatus = Acad::eNullObjectId;

    if(pAction)
    {
        AcDbAssocEvaluationCallback* const pEvalCallback = pAction->currentEvaluationCallback();
        if(pEvalCallback)
        {
            pEvalCallback->beginActionEvaluationUsingObject(pAction, m_pId, true, mode == AcDb::kForWrite, m_pCopyObj);
            if (!m_pCopyObj)
            {
                m_pObj = OBJ::cast(m_pCopyObj);
                m_pErrorStatus = m_pObj != NULL ? Acad::eOk : Acad::eNotThatKindOfClass;
            }
        }
    }
    if (!m_pCopyObj)
    {
        if (m_pPtrObj.open(m_pId, mode, isErased, isLocked) == Acad::eOk)
            m_pObj = m_pPtrObj;
    }
}

template<class OBJ>
inline AcDbAssocObjectPointer<OBJ>::~AcDbAssocObjectPointer()
{
    if (m_pId.isNull() && !m_pCopyObj)
        return;

    if (m_pAction)
    {
        AcDbAssocEvaluationCallback* const pEvalCallback = m_pAction->currentEvaluationCallback();
        if (pEvalCallback)
            pEvalCallback->endActionEvaluationUsingObject(m_pAction, m_pId, m_pObj);
    }
    else
    {
        AcDbObjectPointer<AcDbAssocAction> pAction;
        if (m_pActionBody)
            pAction.open(m_pActionBody->parentAction(), AcDb::kForRead, true);
        else if (m_pDependency)
            pAction.open(m_pDependency->owningAction(), AcDb::kForRead, true);
        else if (m_pDependencyBody)
        {
            AcDbObjectPointer<AcDbAssocDependency> pDependency(m_pDependencyBody->parentDependency(), AcDb::kForRead, true);
            if (pDependency.openStatus() == Acad::eOk)
                pAction.open(pDependency->owningAction(), AcDb::kForRead, true);
        }
        if (pAction.openStatus() != Acad::eOk)
            return;
        AcDbAssocEvaluationCallback* const pEvalCallback = pAction->currentEvaluationCallback();
        if (pEvalCallback)
                pEvalCallback->endActionEvaluationUsingObject(pAction, m_pId, m_pObj);
    }
}

template<class OBJ>
inline Acad::ErrorStatus AcDbAssocObjectPointer<OBJ>::openStatus() const
{
    if (!m_pCopyObj)
        return m_pPtrObj.openStatus();
    return m_pErrorStatus;
}

template<class OBJ>
inline AcDbAssocObjectPointer<OBJ>::AcDbAssocObjectPointer(AcDbAssocObjectPointer&& other)
    : m_pAction(NULL),
    m_pActionBody(NULL),
    m_pDependency(NULL),
    m_pDependencyBody(NULL),
    m_pId(AcDbObjectId::kNull),
    m_pObj(NULL),
    m_pCopyObj(NULL),
    m_pErrorStatus(Acad::eNullObjectPointer)
{
    *this = other;
}

template<class OBJ>
inline AcDbAssocObjectPointer<OBJ>& AcDbAssocObjectPointer<OBJ>::operator=(AcDbAssocObjectPointer&& other)
{
    if (*this != other)
    {
        m_pAction = std::move(other.m_pAction);
        m_pActionBody = std::move(other.m_pActionBody);
        m_pDependency = std::move(other.m_pDependency);
        m_pDependencyBody = std::move(other.m_pDependencyBody);
        m_pId = std::move(other.m_pId);
        m_pObj = std::move(other.m_pObj);
        m_pCopyObj = std::move(other.m_pCopyObj);
        m_pErrorStatus = std::move(other.m_pErrorStatus);

        other.m_pAction = NULL;
        other.m_pActionBody = NULL;
        other.m_pDependency = NULL;
        other.m_pDependencyBody = NULL;
        other.m_pId = AcDbObjectId::kNull;
        other.m_pObj = NULL;
        other.m_pCopyObj = NULL;
        other.m_pErrorStatus = Acad::eNullObjectPointer;  
    }
    return *this;
}
