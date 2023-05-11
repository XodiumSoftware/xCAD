// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcRx/AcRxObject.h"

/** _ */
class BRX_IMPORTEXPORT AcDbLayoutManagerReactor: public AcRxObject
{
public:
    ACRX_DECLARE_MEMBERS(AcDbLayoutManagerReactor);

    virtual void abortLayoutCopied(const ACHAR*,const AcDbObjectId&);
    virtual void abortLayoutRemoved(const ACHAR*,const AcDbObjectId&);
    virtual void abortLayoutRename(const ACHAR*,const ACHAR*,const AcDbObjectId&);
    virtual void layoutCopied(const ACHAR*,const AcDbObjectId&,const ACHAR*,const AcDbObjectId&);
    virtual void layoutCreated(const ACHAR*,const AcDbObjectId&);
    virtual void layoutRemoved(const ACHAR*,const AcDbObjectId&);
    virtual void layoutRenamed(const ACHAR*,const ACHAR*,const AcDbObjectId&);
    virtual void layoutsReordered();
    virtual void layoutSwitched(const ACHAR*,const AcDbObjectId&);
    virtual void layoutToBeCopied(const ACHAR*,const AcDbObjectId&);
    virtual void layoutToBeRemoved(const ACHAR*,const AcDbObjectId&);
    virtual void layoutToBeRenamed(const ACHAR*,const ACHAR*,const AcDbObjectId&);
    virtual void plotStyleTableChanged(const ACHAR*,const AcDbObjectId&);
};
