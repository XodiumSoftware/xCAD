#pragma once
#include "AcDbObject.h"
#include "AcDbAssocGlobal.h"
#include "AcString.h"

class BRX_EXPORT AcDbAssocManager : public AcDbObject
{
public:
    ACRX_DECLARE_MEMBERS(AcDbAssocManager)
    AcDbAssocManager();

    static bool evaluateTopLevelNetwork(AcDbDatabase*, AcDbAssocEvaluationCallback* = NULL, int = 0);
    static AcDbAssocEvaluationCallback* globalEvaluationMultiCallback();
    static Acad::ErrorStatus addGlobalEvaluationCallback(AcDbAssocEvaluationCallback*, int);
    static Acad::ErrorStatus removeGlobalEvaluationCallback(AcDbAssocEvaluationCallback*);
    static void getGlobalEvaluationCallbacks(AcArray<AcDbAssocEvaluationCallback*>&, AcArray<int>& orders);
    static bool isActionEvaluationInProgress(const AcDbDatabase*);
    static Acad::ErrorStatus requestToEvaluate(const AcDbObjectId&, AcDbAssocStatus = AcDbAssocStatus::kChangedDirectlyAssocStatus, bool = true);
    static AcDbAssocEvaluationCallback* getCurrentEvaluationCallback(const AcDbDatabase*);
    static bool hasAssocNetwork(const AcDbDatabase*);
    static AcDbObjectId currentlyEvaluatedAction(const AcDbDatabase*);
    static Acad::ErrorStatus auditAssociativeData(AcDbDatabase*, bool);
    static Acad::ErrorStatus markSyncUpWithXrefsNeeded(AcDbDatabase*);
    static Acad::ErrorStatus syncUpWithXrefs(AcDbDatabase*);
    static Acad::ErrorStatus initialize();
    static void uninitialize();
    static void enableProgressMeter(bool enableIt, const AcString& progressLabel = AcString());
};

class AcDbAssocNetworkEvaluationDisabler
{
public:
    explicit AcDbAssocNetworkEvaluationDisabler(AcDbDatabase*, bool = true);
    ~AcDbAssocNetworkEvaluationDisabler();
    static bool isDisabled(const AcDbDatabase*);

private:
    AcDbDatabase* m_pDb;
    bool m_isDisable;
};
