// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbGlobal.h"
#include "AcGe/AcGeGlobal.h"
#include "AcRx/AcRxObject.h"

/** _ */
class BRX_IMPORTEXPORT AcRxEventReactor: public AcRxObject
{
public:
    ACRX_DECLARE_MEMBERS(AcRxEventReactor);

    virtual void abortAttach(AcDbDatabase*);
    virtual void abortDeepClone(AcDbIdMapping&);
    virtual void abortDxfIn(AcDbDatabase*);
    virtual void abortDxfOut(AcDbDatabase*);
    virtual void abortInsert(AcDbDatabase*);
    virtual void abortRestore(AcDbDatabase*);
    virtual void abortSave(AcDbDatabase*);
    virtual void abortWblock(AcDbDatabase*);
    virtual void beginAttach(AcDbDatabase*,const ACHAR*,AcDbDatabase*);
    virtual void beginDeepClone(AcDbDatabase*,AcDbIdMapping&);
    virtual void beginDeepCloneXlation(AcDbIdMapping&,Acad::ErrorStatus*);
    virtual void beginDxfIn(AcDbDatabase*);
    virtual void beginDxfOut(AcDbDatabase*);
    virtual void beginInsert(AcDbDatabase*,const AcGeMatrix3d&,AcDbDatabase*);
    virtual void beginInsert(AcDbDatabase*,const ACHAR*,AcDbDatabase*);
    virtual void beginRestore(AcDbDatabase*,const ACHAR*,AcDbDatabase*);
    virtual void beginSave(AcDbDatabase*,const ACHAR*);
    virtual void beginWblock(AcDbDatabase*,AcDbDatabase*);
    virtual void beginWblock(AcDbDatabase*,AcDbDatabase*,AcDbObjectId);
    virtual void beginWblock(AcDbDatabase*,AcDbDatabase*,const AcGePoint3d*&);
    virtual void beginWblockObjects(AcDbDatabase*,AcDbIdMapping&);
    virtual void comandeered(AcDbDatabase*,AcDbObjectId,AcDbDatabase*);
    virtual void databaseConstructed(AcDbDatabase*);
    virtual void databaseToBeDestroyed(AcDbDatabase*);
    virtual void dwgFileOpened(AcDbDatabase*,ACHAR*); //deprecated
    virtual void dwgFileOpened(AcDbDatabase*,const ACHAR*);
    virtual void dxfInComplete(AcDbDatabase*);
    virtual void dxfOutComplete(AcDbDatabase*);
    virtual void endAttach(AcDbDatabase*);
    virtual void endDeepClone(AcDbIdMapping&);
    virtual void endInsert(AcDbDatabase*);
    virtual void endRestore(AcDbDatabase*);
    virtual void endWblock(AcDbDatabase*);
    virtual void initialDwgFileOpenComplete(AcDbDatabase*);
    virtual void otherAttach(AcDbDatabase*,AcDbDatabase*);
    virtual void otherInsert(AcDbDatabase*,AcDbIdMapping&,AcDbDatabase*);
    virtual void otherWblock(AcDbDatabase*,AcDbIdMapping&,AcDbDatabase*);
    virtual void partialOpenNotice(AcDbDatabase*);
    virtual void preXrefLockFile(AcDbDatabase*,AcDbObjectId);
    virtual void redirected(AcDbObjectId,AcDbObjectId);
    virtual void saveComplete(AcDbDatabase*,const ACHAR*);
    virtual void wblockNotice(AcDbDatabase*);

    virtual void xrefSubCommandAborted(AcDbDatabase*,AcXrefSubCommand,const AcDbObjectIdArray&,const ACHAR* const*,const ACHAR* const*);
    virtual void xrefSubCommandStart(AcDbDatabase*,AcXrefSubCommand,const AcDbObjectIdArray&,const ACHAR* const*,const ACHAR* const*,bool&);
    virtual void xrefSubCommandEnd(AcDbDatabase*,AcXrefSubCommand, const AcDbObjectIdArray&,const ACHAR* const*, const ACHAR* const*);

    virtual void xrefSubcommandBindItem   (AcDbDatabase*,int,AcDbObjectId);
    virtual void xrefSubcommandAttachItem (AcDbDatabase*,int,const ACHAR*);
    virtual void xrefSubcommandOverlayItem(AcDbDatabase*,int,const ACHAR*);
    virtual void xrefSubcommandDetachItem (AcDbDatabase*,int,AcDbObjectId);
    virtual void xrefSubcommandPathItem   (int,AcDbObjectId,const ACHAR*);
    virtual void xrefSubcommandReloadItem (AcDbDatabase*,int,AcDbObjectId);
    virtual void xrefSubcommandUnloadItem (AcDbDatabase*,int,AcDbObjectId);
};
