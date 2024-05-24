// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDbObject.h"
#include "AcDbAssocGlobal.h"
#include "AcDbCompoundObjectId.h"

class BRX_EXPORT AcDbAssocDependency : public AcDbObject
{
public:
    ACRX_DECLARE_MEMBERS(AcDbAssocDependency)
    AcDbAssocDependency();
    ~AcDbAssocDependency() noexcept = default;

    int order() const;

    AcDbAssocStatus status() const;
    AcDbAssocEvaluationCallback* currentEvaluationCallback() const;

    AcDbObjectId dependencyBody() const;
    AcDbObjectId owningAction() const { return ownerId(); }
    AcDbObjectId dependentOnObject() const;
    AcDbObjectId prevDependencyOnObject() const;
    AcDbObjectId nextDependencyOnObject() const;

    bool isReadDependency() const;
    bool isWriteDependency() const;
    bool isObjectStateDependent() const;
    bool isDependentOnCompoundObject() const;
    bool isAttachedToObject() const { return !dependentOnObject().isNull(); }
    bool isDelegatingToOwningAction() const;
    bool hasCachedValue() const;
    bool isRelevantChange() const;
    bool isDependentOnTheSameThingAs(const AcDbAssocDependency*) const;
    bool isDependentOnObjectReadOnly() const;
    bool isEqualTo(const AcDbAssocDependency*) const;
    bool isActionEvaluationInProgress() const;

    Acad::ErrorStatus setDependencyBody(const AcDbObjectId&);
    Acad::ErrorStatus setStatus(AcDbAssocStatus, bool = true);
    Acad::ErrorStatus setOwningAction(const AcDbObjectId&);
    Acad::ErrorStatus getDependentOnCompoundObject(AcDbCompoundObjectId&) const;
    Acad::ErrorStatus attachToObject(const AcDbCompoundObjectId&);
    Acad::ErrorStatus transferToObject(const AcDbCompoundObjectId&);
    Acad::ErrorStatus dependentOnObjectStatus() const;
    Acad::ErrorStatus detachFromObject();
    Acad::ErrorStatus updateDependentOnObject();
    Acad::ErrorStatus notification(AcDbAssocNotificationData*);

    static Acad::ErrorStatus getFirstDependencyOnObject(const AcDbObject*, AcDbObjectId&);
    static Acad::ErrorStatus getDependenciesOnObject(const AcDbObject*, bool, bool, AcDbObjectIdArray&);
    static Acad::ErrorStatus notifyDependenciesOnObject(const AcDbObject*, AcDbAssocStatus);   

    void setIsReadDependency(bool);
    void setIsWriteDependency(bool);
    void setIsObjectStateDependent(bool);
    void setOrder(int);
    void setIsDelegatingToOwningAction(bool);
    void setDependentOnObject(const AcDbCompoundObjectId&);
    void evaluate();

    void erased(const AcDbObject*, Adesk::Boolean = true) override;
    void modified(const AcDbObject*) override;
    void copied(const AcDbObject*, const AcDbObject*) override;
};

class AcDbAssocDependencyNotificationDisabler
{
public:
    explicit AcDbAssocDependencyNotificationDisabler(bool = true);
    ~AcDbAssocDependencyNotificationDisabler();
    static bool isDisabled();
};
