// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbObjectId.h"
#include "AcRx/AcRxEventReactor.h"

/** _ */
class BRX_IMPORTEXPORT AcEditorReactor: public AcRxEventReactor
{
public:
    ACRX_DECLARE_MEMBERS(AcEditorReactor);

    AcEditorReactor();

    virtual Acad::ErrorStatus xrefSubCommandStart(AcXrefSubCommand,const AcDbObjectIdArray&,const ACHAR* const*,const ACHAR* const*);
    virtual void abortAttach(AcDbDatabase*);
    virtual void abortDeepClone(AcDbIdMapping&);
    virtual void abortDxfIn(AcDbDatabase*);
    virtual void abortDxfOut(AcDbDatabase*);
    virtual void abortInsert(AcDbDatabase*);
    virtual void abortRestore(AcDbDatabase*);
    virtual void abortSave(AcDbDatabase*);
    virtual void abortWblock(AcDbDatabase*);
    virtual void beginAttach(AcDbDatabase*,const ACHAR*,AcDbDatabase*);
    virtual void beginClose(AcDbDatabase*);     //deprecated
    virtual void beginDeepClone(AcDbDatabase*,AcDbIdMapping&);
    virtual void beginDeepCloneXlation(AcDbIdMapping&,Acad::ErrorStatus*);
    virtual void beginDoubleClick(const AcGePoint3d&);
    virtual void beginDwgOpen(const ACHAR*);
    virtual void beginDxfIn(AcDbDatabase*);
    virtual void beginDxfOut(AcDbDatabase*);
    virtual void beginInsert(AcDbDatabase*,const AcGeMatrix3d&,AcDbDatabase*);
    virtual void beginInsert(AcDbDatabase*,const ACHAR*,AcDbDatabase*);
    virtual void beginQuit();
    virtual void beginRestore(AcDbDatabase*,const ACHAR*,AcDbDatabase*);
    virtual void beginRightClick(const AcGePoint3d&);
    virtual void beginSave(AcDbDatabase*,const ACHAR*);
    virtual void beginWblock(AcDbDatabase*,AcDbDatabase*);
    virtual void beginWblock(AcDbDatabase*,AcDbDatabase*,AcDbObjectId);
    virtual void beginWblock(AcDbDatabase*,AcDbDatabase*,const AcGePoint3d*&);
    virtual void beginWblockObjects(AcDbDatabase*,AcDbIdMapping&);
    virtual void cmdIUnkModified(const ACHAR*);
    virtual void comandeered(AcDbDatabase*,AcDbObjectId,AcDbDatabase*);
    virtual void commandCancelled(const ACHAR*);
    virtual void commandEnded(const ACHAR*);
    virtual void commandFailed(const ACHAR*);
    virtual void commandWillStart(const ACHAR*);
    virtual void databaseConstructed(AcDbDatabase*);
    virtual void databaseToBeDestroyed(AcDbDatabase*);
    virtual void docFrameMovedOrResized(Adesk::LongPtr,bool);
    virtual void dwgFileOpened(AcDbDatabase*,ACHAR*); //deprecated
    virtual void dwgFileOpened(AcDbDatabase*,const ACHAR*);
    virtual void dxfInComplete(AcDbDatabase*);
    virtual void dxfOutComplete(AcDbDatabase*);
    virtual void endAttach(AcDbDatabase*);
    virtual void endDeepClone(AcDbIdMapping&);
    virtual void endDwgOpen(const ACHAR*,AcDbDatabase*);
    virtual void endInsert(AcDbDatabase*);
    virtual void endRestore(AcDbDatabase*);
    virtual void endWblock(AcDbDatabase*);
    virtual void initialDwgFileOpenComplete(AcDbDatabase*);
    virtual void layoutSwitched(const ACHAR*);
    virtual void lispCancelled();
    virtual void lispEnded();
    virtual void lispWillStart(const ACHAR*);
    virtual void mainFrameMovedOrResized(Adesk::LongPtr,bool);
    virtual void modelessOperationEnded(const ACHAR*);
    virtual void modelessOperationWillStart(const ACHAR*);
    virtual void objectsLazyLoaded(const AcDbObjectIdArray&);
    virtual void otherAttach(AcDbDatabase*,AcDbDatabase*);
    virtual void otherInsert(AcDbDatabase*,AcDbIdMapping&,AcDbDatabase*);
    virtual void otherWblock(AcDbDatabase*,AcDbIdMapping&,AcDbDatabase*);
    virtual void partialOpenNotice(AcDbDatabase*);
    virtual void pickfirstModified();
    virtual void preXrefLockFile(AcDbObjectId);
    virtual void quitAborted();
    virtual void quitWillStart();
    virtual void redirected(AcDbObjectId,AcDbObjectId);
    virtual void saveComplete(AcDbDatabase*,const ACHAR*);
    virtual void sysVarChanged(const ACHAR*,Adesk::Boolean);
    virtual void sysVarWillChange(const ACHAR*);
    virtual void toolbarBitmapSizeChanged(Adesk::Boolean);
    virtual void toolbarBitmapSizeWillChange(Adesk::Boolean);
    virtual void undoSubcommandAuto(int,Adesk::Boolean);
    virtual void undoSubcommandBack(int);
    virtual void undoSubcommandBegin(int);
    virtual void undoSubcommandControl(int,int);
    virtual void undoSubcommandEnd(int);
    virtual void undoSubcommandMark(int);
    virtual void undoSubcommandNumber(int,int);
    virtual void unknownCommand(const ACHAR*,AcDbVoidPtrArray*);
    virtual void viewChanged();
    virtual void wblockNotice(AcDbDatabase*);
    virtual void xrefSubcommandAttachItem(AcDbDatabase*,int,const ACHAR*);
    virtual void xrefSubcommandBindItem(AcDbDatabase*,int,AcDbObjectId);
    virtual void xrefSubcommandDetachItem(AcDbDatabase*,int,AcDbObjectId);
    virtual void xrefSubcommandOverlayItem(AcDbDatabase*,int,const ACHAR*);
    virtual void xrefSubcommandPathItem(int,AcDbObjectId,const ACHAR*);
    virtual void xrefSubcommandReloadItem(AcDbDatabase*,int,AcDbObjectId);
    virtual void xrefSubcommandUnloadItem(AcDbDatabase*,int,AcDbObjectId);

    // moved from AcEditorReactor2 to AcEditorReactor
    virtual void beginDocClose(AcDbDatabase*);
    virtual void docCloseAborted(AcDbDatabase*);
    virtual void docCloseWillStart(AcDbDatabase*);
    virtual void dwgViewResized(Adesk::LongPtr);
    virtual void layoutToBeSwitched(const ACHAR*, const ACHAR*);

protected:
    Acad::ErrorStatus veto();
};
