#pragma once
#include "AcDb/AcDbDatabase.h"

class AcDbAssocAction;
class AcDbAssocNetwork;

enum AcDbAssocStatus
{
    kIsUpToDateAssocStatus = 0,
    kChangedDirectlyAssocStatus = 1,
    kChangedTransitivelyAssocStatus = 2,
    kChangedNoDifferenceAssocStatus = 3, 
    kFailedToEvaluateAssocStatus = 4,
    kErasedAssocStatus = 5,
    kSuppressedAssocStatus = 6,
    kUnresolvedAssocStatus = 7,
};

inline int evaluationRequestSeverityLevel(AcDbAssocStatus);
inline int isEvaluationRequest(AcDbAssocStatus evalStatus);
inline bool isToBeSkipped(AcDbAssocStatus evalStatus);

enum AcDbAssocEvaluationMode
{
    kModifyObjectsAssocEvaluationMode = 0,
    kModifyActionAssocEvaluationMode = 1,
};

enum AcDbAssocDraggingState
{
    kNotDraggingAssocDraggingState = 0,
    kFirstSampleAssocDraggingState = 1,
    kIntermediateSampleAssocDraggingState = 2,
    kLastSampleAssocDraggingState = 3,
};

enum AcDbAssocTransformationType
{
    kNotSpecified = 0,
    kStretch = 1,
    kRotate = 2,
    kMove = 3,
};

class AcDbAssocEvaluationCallback
{
public:
    AcDbAssocEvaluationCallback() {}
    virtual ~AcDbAssocEvaluationCallback() noexcept = default;
    virtual AcDbAssocEvaluationMode evaluationMode() const { return kModifyObjectsAssocEvaluationMode; };
    virtual void beginActionEvaluation(AcDbAssocAction*) = 0;
    virtual void endActionEvaluation(AcDbAssocAction*) = 0;
    virtual void setActionEvaluationErrorStatus(AcDbAssocAction*, Acad::ErrorStatus, const AcDbObjectId & = AcDbObjectId::kNull, AcDbObject* = NULL, void* = NULL) = 0;
    virtual void beginActionEvaluationUsingObject(AcDbAssocAction*, const AcDbObjectId&, bool, bool, AcDbObject*&) = 0;
    virtual void endActionEvaluationUsingObject(AcDbAssocAction*, const AcDbObjectId&, AcDbObject*) = 0;
    virtual void allDependentActionsMarkedToEvaluate(AcDbAssocNetwork*) {};
    virtual AcDbAssocDraggingState draggingState() const { return kNotDraggingAssocDraggingState; };
    virtual bool cancelActionEvaluation() { return false; };
    virtual AcDbEvalContext* getAdditionalData() const { return NULL; };
    virtual AcDbAssocTransformationType getTransformationType() const { return kNotSpecified; };
};

inline bool isDraggingProvidingSubstituteObjects(const AcDbAssocEvaluationCallback*);
