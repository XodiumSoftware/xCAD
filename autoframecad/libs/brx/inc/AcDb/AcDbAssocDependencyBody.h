// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDbObject.h"
#include "AcDbAssocDependency.h"

class BRX_EXPORT AcDbAssocDependencyBody : public AcDbObject
{
public:
    ACRX_DECLARE_MEMBERS(AcDbAssocDependencyBody);
    AcDbAssocDependencyBody();
    ~AcDbAssocDependencyBody() noexcept = default;

    AcDbAssocStatus status() const;
    AcDbAssocEvaluationCallback* currentEvaluationCallback() const;

    AcDbObjectId parentDependency() const { return ownerId(); }
    AcDbObjectId owningAction() const;
    AcDbObjectId dependentOnObject() const;

    bool isAttachedToObject() const { return !dependentOnObject().isNull(); }
    bool isActionEvaluationInProgress() const;

    Acad::ErrorStatus setStatus(AcDbAssocStatus setStatus, bool = true);

    virtual void evaluateOverride() = 0;
    virtual Acad::ErrorStatus updateDependentOnObjectOverride() { return Acad::eNotImplementedYet; }
    virtual Acad::ErrorStatus hasCachedValueOverride(bool&) const { return Acad::eNotImplementedYet; }
    virtual Acad::ErrorStatus isRelevantChangeOverride(bool&) const { return Acad::eNotImplementedYet; }
    virtual Acad::ErrorStatus isDependentOnTheSameThingAsOverride(const AcDbAssocDependency*, bool&) const { return Acad::eNotImplementedYet; }
    virtual Acad::ErrorStatus isEqualToOverride(const AcDbAssocDependency*, bool&) const { return Acad::eNotImplementedYet; }
    virtual void erasedOverride(const AcDbObject*, Adesk::Boolean) {}
    virtual void modifiedOverride(const AcDbObject*) {}
    virtual void clonedOverride(const AcDbObject*, const AcDbObject*) {}
    virtual void auditAssociativeDataOverride(AcDbAssocStatus&) {};
};
