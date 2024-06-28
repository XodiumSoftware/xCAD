// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDbObject.h"
#include "AcDbAssocGlobal.h"
#include "AcValue.h"
#include "AcDbEvalVariant.h"

class BRX_IMPORTEXPORT AcDbAssocAction : public AcDbObject
{
public:
    ACRX_DECLARE_MEMBERS(AcDbAssocAction)
    AcDbAssocAction();
    ~AcDbAssocAction() noexcept = default;

    AcDbAssocStatus status() const;
    AcDbAssocEvaluationCallback* currentEvaluationCallback() const;
    AcDbAssocEvaluationPriority evaluationPriority() const;
    AcValue::UnitType valueParamUnitType(const AcString&) const;

    AcDbObjectId actionBody() const;
    AcDbObjectId owningNetwork() const;
    AcDbObjectId objectThatOwnsNetworkInstance() const;
    AcDbObjectId paramAtName(const AcString&, int = 0) const;
    AcDbObjectId paramAtIndex(int) const;

    static AcDbObjectId actionBody(const AcDbObjectId&);

    const AcDbObjectIdArray& ownedParams() const;
    const AcDbObjectIdArray& paramsAtName(const AcString&) const;

    bool isActionBodyAProxy() const;
    bool isOwnedDependency(const AcDbAssocDependency*) const;
    bool isExternalDependency(const AcDbAssocDependency*) const;
    bool isRelevantDependencyChange(const AcDbAssocDependency*) const;
    bool hasDependencyCachedValue(const AcDbAssocDependency*) const;
    bool areDependenciesOnTheSameThing(const AcDbAssocDependency*, const AcDbAssocDependency*) const;
    bool areDependenciesEqual(const AcDbAssocDependency*, const AcDbAssocDependency*) const;
    bool isActionEvaluationInProgress() const;
    bool isEqualTo(const AcDbAssocAction*) const;

    static bool doesObjectHaveActiveActions(const AcDbObject*);

    Acad::ErrorStatus setActionBody(const AcDbObjectId&);
    Acad::ErrorStatus setStatus(AcDbAssocStatus, bool = true, bool = false);
    Acad::ErrorStatus setOwningNetwork(const AcDbObjectId&, bool);
    Acad::ErrorStatus getDependencies(bool, bool, AcDbObjectIdArray&) const;
    Acad::ErrorStatus addDependency(const AcDbObjectId&, bool = true);
    Acad::ErrorStatus addDependency(AcRxClass*, AcRxClass*, bool, bool, int, AcDbObjectId&);
    Acad::ErrorStatus removeDependency(const AcDbObjectId&, bool);
    Acad::ErrorStatus removeAllDependencies(bool);
    Acad::ErrorStatus getDependentObjects(bool, bool, AcDbObjectIdArray&) const;
    Acad::ErrorStatus notification(AcDbAssocNotificationData*);

    Acad::ErrorStatus addMoreObjectsToDeepClone(AcDbIdMapping&, AcDbObjectIdArray&) const;
    Acad::ErrorStatus postProcessAfterDeepClone(AcDbIdMapping&);
    Acad::ErrorStatus postProcessAfterDeepCloneCancel(AcDbIdMapping&);
    Acad::ErrorStatus evaluateDependencies();
    Acad::ErrorStatus removeAllParams(bool);
    Acad::ErrorStatus addParam(const AcDbObjectId&, int&);
    Acad::ErrorStatus addParam(const AcString&, AcRxClass*, AcDbObjectId&, int&);
    Acad::ErrorStatus removeParam(const AcDbObjectId&, bool);
    Acad::ErrorStatus getValueParamArray(const AcString&, AcArray<AcDbEvalVariant>&, AcArray<AcString>&, AcArray<AcString>&) const; //TODO
    Acad::ErrorStatus getValueParam(const AcString&, AcDbEvalVariant&, AcString&, AcString&, int = 0) const;
    Acad::ErrorStatus setValueParamArray(const AcString&, const AcArray<AcDbEvalVariant>&, const AcArray<AcString>&, const AcArray<AcString>&, AcArray<AcString>&, bool); //TODO
    Acad::ErrorStatus setValueParam(const AcString&, const AcDbEvalVariant&, const AcString&, const AcString&, AcString&, bool, int = 0);
    Acad::ErrorStatus setValueParamUnitType(const AcString&, AcValue::UnitType);
    Acad::ErrorStatus removeValueParam(const AcString&);
    Acad::ErrorStatus valueParamInputVariables(const AcString&, AcDbObjectIdArray&) const;
    Acad::ErrorStatus setValueParamControlledObjectDep(const AcString&, const AcDbObjectId&);
    Acad::ErrorStatus updateValueParamControlledObject(const AcString&) const;
    Acad::ErrorStatus updateValueParamFromControlledObject(const AcString&);
    Acad::ErrorStatus updateAllObjectsControlledByValueParams() const;
    Acad::ErrorStatus transformAllConstantGeometryParams(const AcGeMatrix3d&);
    Acad::ErrorStatus scaleAllDistanceValueParams(double);
    Acad::ErrorStatus ownedDependencyStatusChanged(AcDbAssocDependency*, AcDbAssocStatus);
    Acad::ErrorStatus transformActionBy(const AcGeMatrix3d&);
    static Acad::ErrorStatus getActionsDependentOnObject(const AcDbObject*, bool, bool, AcDbObjectIdArray&);
    static Acad::ErrorStatus removeActionsControllingObject(const AcDbObjectId&, int = 0, const AcDbObjectId & = AcDbObjectId::kNull);
    static Acad::ErrorStatus markDependentActionsToEvaluate(const AcDbObjectId&);
    
    void dependentObjectCloned(const AcDbAssocDependency*, const AcDbObject*, const AcDbObject*);
    void evaluateDependency(AcDbAssocDependency*);
    void getDependentActionsToEvaluate(AcDbActionsToEvaluateCallback*) const;
    void evaluate(AcDbAssocEvaluationCallback*);
    void dragStatus(const AcDb::DragStat);
    void ownedValueParamNames(AcArray<AcString>&) const;
};
