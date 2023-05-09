// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbAuditInfo.h"
#include "AcDb/AcDbBoiler.h"
#include "AcDb/AcDbDwgFiler.h"
#include "AcDb/AcDbDxfFiler.h"
#include "AcGi/AcGiDrawable.h"
#include "Misc/AcHeapOperators.h"

class BrxDbObjectImp;

/** _ */
class BRX_IMPORTEXPORT AcDbObject: public AcGiDrawable, public AcHeapOperators
{
private:
    BrxDbObjectImp* m_pBrxImp;
public:
    // ----- diagnostic functions : BRX Object -----
    // 1=Read 2=Write 4=NotifyEnabled 8=Notifying 16=isCancelling 32=isUndoing 64=TransactionResident
    int getBrxOpenState() const;
    int getBrxOpenCount() const;
    int getCustomObjectState() const; // 1=isCustomObject 2=DifferentialUndoDisabled -1=Error
    // ----- diagnostic functions : ODA Object -----
    // 1=Read 2=Write 4=NotifyEnabled 8=Notifying 16=isCancelling 32=isUndoing 64=TransactionResident
    int getOdaOpenState() const;
    int getOdaOpenCount() const;

public:
    ACDB_DECLARE_MEMBERS(AcDbObject);

protected:
    AcDbObject();
public:
    virtual ~AcDbObject();

    virtual Acad::ErrorStatus applyPartialUndo(AcDbDwgFiler*,AcRxClass*);
    virtual Acad::ErrorStatus audit(AcDbAuditInfo*);
    virtual Acad::ErrorStatus copyFrom(const AcRxObject*);
    virtual Acad::ErrorStatus decomposeForSave(AcDb::AcDbDwgVersion,AcDbObject*&,AcDbObjectId&,Adesk::Boolean&);
    virtual Acad::ErrorStatus deepClone(AcDbObject*,AcDbObject*&,AcDbIdMapping&,Adesk::Boolean = Adesk::kTrue) const final;
    virtual Acad::ErrorStatus dwgInFields(AcDbDwgFiler*);
    virtual Acad::ErrorStatus dwgOutFields(AcDbDwgFiler*) const;
    virtual Acad::ErrorStatus dxfInFields(AcDbDxfFiler*);
    virtual Acad::ErrorStatus dxfOutFields(AcDbDxfFiler*) const;
    virtual Acad::ErrorStatus getClassID(CLSID*) const final;
    virtual Acad::ErrorStatus getObjectSaveVersion(const AcDbDwgFiler*,AcDb::AcDbDwgVersion&,AcDb::MaintenanceReleaseVersion&);
    virtual Acad::ErrorStatus getObjectSaveVersion(const AcDbDxfFiler*,AcDb::AcDbDwgVersion&,AcDb::MaintenanceReleaseVersion&);
    virtual Acad::ErrorStatus removeField(AcDbObjectId);
    virtual Acad::ErrorStatus removeField(const ACHAR*);
    virtual Acad::ErrorStatus removeField(const ACHAR*,AcDbObjectId&);
    virtual Acad::ErrorStatus removePersistentReactor(AcDbObjectId);
    virtual Acad::ErrorStatus setField(const ACHAR*,AcDbField*,AcDbObjectId&);
    virtual Acad::ErrorStatus setOwnerId(AcDbObjectId);
    virtual Acad::ErrorStatus setXData(const resbuf*);
    virtual Acad::ErrorStatus subHandOverTo(AcDbObject*);
    virtual Acad::ErrorStatus subSwapIdWith(AcDbObjectId,Adesk::Boolean = Adesk::kFalse,Adesk::Boolean = Adesk::kFalse);
    virtual Acad::ErrorStatus swapReferences(const AcDbIdMapping&);
    virtual Acad::ErrorStatus wblockClone(AcRxObject*,AcDbObject*&,AcDbIdMapping&,Adesk::Boolean = Adesk::kTrue) const final;
    virtual AcDb::DuplicateRecordCloning mergeStyle() const;
    virtual AcDbObjectId id() const;
    virtual AcGiDrawable* drawable();
    virtual AcGsNode* gsNode() const;
    virtual AcRxObject* clone() const;
    virtual Adesk::Boolean isPersistent() const;
    virtual resbuf* xData(const ACHAR* = NULL) const;
    virtual void addPersistentReactor(AcDbObjectId);
    virtual void cancelled(const AcDbObject*);
    virtual void copied(const AcDbObject*,const AcDbObject*);
    virtual void erased(const AcDbObject*,Adesk::Boolean = Adesk::kTrue);
    virtual void goodbye(const AcDbObject*);
    virtual void modified(const AcDbObject*);
    virtual void modifiedGraphics(const AcDbEntity*);
    virtual void modifiedXData(const AcDbObject*);
    virtual void modifyUndone(const AcDbObject*);
    virtual void objectClosed(const AcDbObjectId);
    virtual void openedForModify(const AcDbObject*);
    virtual void reappended(const AcDbObject*);
    virtual void recvPropagateModify(const AcDbObject*);
    virtual void setGsNode(AcGsNode*);
    virtual void subObjModified(const AcDbObject*,const AcDbObject*);
    virtual void unappended(const AcDbObject*);
    virtual void xmitPropagateModify() const;

    Acad::ErrorStatus cancel();
    Acad::ErrorStatus close();
    Acad::ErrorStatus closeAndPage(Adesk::Boolean = Adesk::kTrue);
    Acad::ErrorStatus createExtensionDictionary();
    Acad::ErrorStatus downgradeOpen();
    Acad::ErrorStatus downgradeToNotify(Adesk::Boolean);
    Acad::ErrorStatus dwgIn(AcDbDwgFiler*);
    Acad::ErrorStatus dwgOut(AcDbDwgFiler*) const;
    Acad::ErrorStatus dxfIn(AcDbDxfFiler*);
    Acad::ErrorStatus dxfOut(AcDbDxfFiler*,Adesk::Boolean,Adesk::uchar*) const;
    Acad::ErrorStatus erase(Adesk::Boolean = Adesk::kTrue);
    Acad::ErrorStatus getBinaryData(const ACHAR*,Adesk::Int32&,char*&) const;
    Acad::ErrorStatus getField(const ACHAR*,AcDbField*&,AcDb::OpenMode) const;
    Acad::ErrorStatus getField(const ACHAR*,AcDbObjectId&) const;
    Acad::ErrorStatus getFieldDictionary(AcDbDictionary*&,AcDb::OpenMode) const;
    Acad::ErrorStatus getObjectBirthVersion(AcDb::AcDbDwgVersion&,AcDb::MaintenanceReleaseVersion&);
    Acad::ErrorStatus handOverTo(AcDbObject*,Adesk::Boolean = Adesk::kTrue,Adesk::Boolean = Adesk::kTrue);
    Acad::ErrorStatus releaseExtensionDictionary();
    Acad::ErrorStatus setBinaryData(const ACHAR*,Adesk::Int32,const char*);
    Acad::ErrorStatus swapIdWith(AcDbObjectId,Adesk::Boolean = Adesk::kFalse,Adesk::Boolean = Adesk::kFalse);
    Acad::ErrorStatus upgradeFromNotify(Adesk::Boolean&);
    Acad::ErrorStatus upgradeOpen();
    Acad::ErrorStatus xDataTransformBy(const AcGeMatrix3d&);
    AcDbDatabase* database() const;
    AcDbDwgFiler* undoFiler();
    AcDbObjectId extensionDictionary() const;
    AcDbObjectId getFieldDictionary() const;
    AcDbObjectId objectId() const;
    AcDbObjectId ownerId() const;
    AcDbVoidPtrArray* reactors();
    Adesk::Boolean isAcDbObjectIdsInFlux() const;
    Adesk::Boolean isAProxy() const;
    Adesk::Boolean isCancelling() const;
    Adesk::Boolean isErased() const;
    Adesk::Boolean isEraseStatusToggled() const;
    Adesk::Boolean isModified() const;
    Adesk::Boolean isModifiedGraphics() const;
    Adesk::Boolean isModifiedXData() const;
    Adesk::Boolean isNewObject() const;
    Adesk::Boolean isNotifyEnabled() const;
    Adesk::Boolean isNotifying() const;
    Adesk::Boolean isReadEnabled() const;
    Adesk::Boolean isReallyClosing() const;
    Adesk::Boolean isTransactionResident() const;
    Adesk::Boolean isUndoing() const;
    Adesk::Boolean isWriteEnabled() const;
    bool hasFields() const;
    bool hasPersistentReactor(AcDbObjectId) const;
    bool hasSaveVersionOverride();
    const AcDbVoidPtrArray* reactors() const;
    void addReactor(AcDbObjectReactor*) const;
    void assertNotifyEnabled() const;
    void assertReadEnabled() const;
    void assertWriteEnabled(Adesk::Boolean = Adesk::kTrue,Adesk::Boolean = Adesk::kTrue);
    void disableUndoRecording(Adesk::Boolean);
    bool isUndoRecordingDisabled() const;
    void getAcDbHandle(AcDbHandle&) const;
    void removeReactor(AcDbObjectReactor*) const;
    void setAcDbObjectIdsInFlux();
    void setHasSaveVersionOverride(bool);

    //V13
public:
    virtual Acad::ErrorStatus composeForLoad(AcDb::OdaSaveType, AcDb::AcDbDwgVersion);

protected:
    //AcGiDrawableOverrule
    virtual Adesk::UInt32 subViewportDrawLogicalFlags(AcGiViewportDraw*);
    virtual Adesk::Boolean subWorldDraw(AcGiWorldDraw*);
    virtual Adesk::UInt32 subSetAttributes(AcGiDrawableTraits*);
    virtual void subViewportDraw(AcGiViewportDraw*);

    friend class AcDbPropertiesOverrule;
    virtual Acad::ErrorStatus subGetClassID(CLSID*) const;

    friend class AcDbObjectOverrule;
    public:
    virtual Acad::ErrorStatus subOpen(AcDb::OpenMode);
    virtual Acad::ErrorStatus subCancel();
    virtual Acad::ErrorStatus subClose();
    virtual Acad::ErrorStatus subErase(Adesk::Boolean);
    protected:
    virtual Acad::ErrorStatus subDeepClone(AcDbObject*, AcDbObject*&, AcDbIdMapping&, Adesk::Boolean = true) const;
    virtual Acad::ErrorStatus subWblockClone(AcRxObject*, AcDbObject*&, AcDbIdMapping&, Adesk::Boolean = true) const;
};
