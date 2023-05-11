#pragma once
#include "AcDbObject.h"
#include "AcDbAssocAction.h"

class BRX_EXPORT AcDbAssocActionBody : public AcDbObject
{
public:
    ACRX_DECLARE_MEMBERS(AcDbAssocActionBody);

    AcDbAssocActionBody();
    ~AcDbAssocActionBody() noexcept = default;

    AcDbAssocStatus status() const;
    AcDbAssocEvaluationCallback* currentEvaluationCallback() const;
    AcValue::UnitType valueParamUnitType(const AcString&) const;

    AcDbObjectId parentAction() const { return ownerId(); }
    AcDbObjectId owningNetwork() const;
    AcDbObjectId paramAtName(const AcString&, int = 0) const;
    AcDbObjectId paramAtIndex(int) const;
    static AcDbObjectId parentAction(const AcDbObjectId&);

    const AcDbObjectIdArray& ownedParams() const;
    const AcDbObjectIdArray& paramsAtName(const AcString&) const;

    bool isActionEvaluationInProgress() const;
    bool hasAnyErasedOrBrokenDependencies() const;

    Acad::ErrorStatus setStatus(AcDbAssocStatus, bool = true, bool = false) const;
    Acad::ErrorStatus getDependencies(bool, bool, AcDbObjectIdArray&) const;
    Acad::ErrorStatus addDependency(const AcDbObjectId&, bool = true) const;
    Acad::ErrorStatus addDependency(AcRxClass*, AcRxClass*, bool, bool, int, AcDbObjectId&) const;
    Acad::ErrorStatus removeDependency(const AcDbObjectId&, bool) const;
    Acad::ErrorStatus removeAllDependencies(bool) const;
    Acad::ErrorStatus evaluateDependencies() const;
    Acad::ErrorStatus addParam(const AcDbObjectId&, int&) const;
    Acad::ErrorStatus addParam(const AcString&, AcRxClass*, AcDbObjectId&, int&) const;
    Acad::ErrorStatus removeParam(const AcDbObjectId&, bool) const;
    Acad::ErrorStatus removeAllParams(bool) const;
    Acad::ErrorStatus getValueParamArray(const AcString&, AcArray<AcDbEvalVariant>&, AcArray<AcString>&, AcArray<AcString>&) const;
    Acad::ErrorStatus getValueParam(const AcString&, AcDbEvalVariant&, AcString&, AcString&, int = 0) const;
    Acad::ErrorStatus setValueParamArray(const AcString&, const AcArray<AcDbEvalVariant>&, const AcArray<AcString>&, const AcArray<AcString>&, AcArray<AcString>&, bool) const;
    Acad::ErrorStatus setValueParam(const AcString&, const AcDbEvalVariant&, const AcString&, const AcString&, AcString&, bool, int = 0) const;
    Acad::ErrorStatus setValueParamUnitType(const AcString&, AcValue::UnitType) const;
    Acad::ErrorStatus removeValueParam(const AcString&) const;
    Acad::ErrorStatus valueParamInputVariables(const AcString&, AcDbObjectIdArray&) const;
    Acad::ErrorStatus setValueParamControlledObjectDep(const AcString&, const AcDbObjectId&) const;
    Acad::ErrorStatus updateValueParamControlledObject(const AcString&) const;
    Acad::ErrorStatus updateValueParamFromControlledObject(const AcString&) const;
    Acad::ErrorStatus updateAllObjectsControlledByValueParams() const;
    Acad::ErrorStatus transformAllConstantGeometryParams(const AcGeMatrix3d&) const;
    Acad::ErrorStatus scaleAllDistanceValueParams(double) const;
    static Acad::ErrorStatus createActionAndActionBodyAndPostToDatabase(AcRxClass*, const AcDbObjectId&, AcDbObjectId&, AcDbObjectId&);
    static Acad::ErrorStatus getActionBodiesOnObject(const AcDbObject*, bool, bool, AcDbObjectId*, AcDbObjectIdArray*, AcDbObjectIdArray* = NULL);
    
    int paramCount() const;
    void ownedValueParamNames(AcArray<AcString>&) const;

    //Virtual methods
    virtual void evaluateOverride() = 0;
    virtual Acad::ErrorStatus getDependenciesOverride(bool, bool, AcDbObjectIdArray&) const { return Acad::eNotImplementedYet; }
    virtual Acad::ErrorStatus getDependentObjectsOverride(bool, bool, AcDbObjectIdArray&) const { return Acad::eNotImplementedYet; }
    virtual Acad::ErrorStatus removeAllDependenciesOverride(bool) { return Acad::eNotImplementedYet; }
    virtual Acad::ErrorStatus isOwnedDependencyOverride(const AcDbAssocDependency*, bool&) const { return Acad::eNotImplementedYet; }
    virtual Acad::ErrorStatus isExternalDependencyOverride(const AcDbAssocDependency*, bool&) const { return Acad::eNotImplementedYet; }
    virtual Acad::ErrorStatus hasDependencyCachedValueOverride(const AcDbAssocDependency*, bool&) const { return Acad::eNotImplementedYet; }
    virtual Acad::ErrorStatus isRelevantDependencyChangeOverride(const AcDbAssocDependency*, bool&) const { return Acad::eNotImplementedYet; }
    virtual Acad::ErrorStatus areDependenciesOnTheSameThingOverride(const AcDbAssocDependency*, const AcDbAssocDependency*, bool&) const { return Acad::eNotImplementedYet; }
    virtual Acad::ErrorStatus areDependenciesEqualOverride(const AcDbAssocDependency*, const AcDbAssocDependency*, bool&) const { return Acad::eNotImplementedYet; }
    virtual Acad::ErrorStatus evaluateDependencyOverride(AcDbAssocDependency*) { return Acad::eNotImplementedYet; }
    virtual Acad::ErrorStatus dependentObjectClonedOverride(const AcDbAssocDependency*, const AcDbObject*, const AcDbObject*) { return Acad::eNotImplementedYet; }
    virtual Acad::ErrorStatus addMoreObjectsToDeepCloneOverride(AcDbIdMapping&, AcDbObjectIdArray&) const { return Acad::eNotImplementedYet; }
    virtual Acad::ErrorStatus postProcessAfterDeepCloneOverride(AcDbIdMapping&) { return Acad::eNotImplementedYet; }
    virtual Acad::ErrorStatus postProcessAfterDeepCloneCancelOverride(AcDbIdMapping&) { return Acad::eNotImplementedYet; }
    virtual Acad::ErrorStatus ownedDependencyStatusChangedOverride(AcDbAssocDependency*, AcDbAssocStatus) { return Acad::eNotImplementedYet; }
    virtual Acad::ErrorStatus isEqualToOverride(const AcDbAssocAction*, bool&) const { return Acad::eNotImplementedYet; }
    virtual Acad::ErrorStatus evaluationPriorityOverride(AcDbAssocEvaluationPriority&) const { return Acad::eNotImplementedYet; }
    virtual Acad::ErrorStatus getDependentActionsToEvaluateOverride(AcDbActionsToEvaluateCallback*) const { return Acad::eNotImplementedYet; }
    virtual Acad::ErrorStatus transformActionByOverride(const AcGeMatrix3d&) { return Acad::eNotImplementedYet; }
    virtual Acad::ErrorStatus dragStatusOverride(const AcDb::DragStat) { return Acad::eNotImplementedYet; }
    virtual Acad::ErrorStatus removeActionsControllingObjectOverride(AcDbObject*) { return Acad::eNotImplementedYet; }

    virtual void auditAssociativeDataOverride(AcDbAssocStatus&);
    virtual Acad::ErrorStatus notificationOverride(class AcDbAssocNotificationData*);
    virtual Acad::ErrorStatus collectPersSubentNamingDataOverride(AcDbPersStepIdArray&, AcDbPersSubentIdArray&) const;
    virtual Acad::ErrorStatus clonePersSubentNamingDataOverride(class AcDbAssocPersSubentManagerCloner*);
};
