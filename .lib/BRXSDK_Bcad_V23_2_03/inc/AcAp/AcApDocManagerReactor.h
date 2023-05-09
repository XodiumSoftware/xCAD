// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcAp/AcApDocument.h"

/** _ */
class BRX_IMPORTEXPORT AcApDocManagerReactor: public AcRxObject
{
public:
    ACRX_DECLARE_MEMBERS(AcApDocManagerReactor);

protected:
    AcApDocManagerReactor();

public:
    virtual void documentActivated(AcApDocument*);
    virtual void documentActivationModified(bool);
    virtual void documentBecameCurrent(AcApDocument*);
    virtual void documentCreateCanceled(AcApDocument*);
    virtual void documentCreated(AcApDocument*);
    virtual void documentCreateStarted(AcApDocument*);
    virtual void documentDestroyed(const ACHAR*);
    virtual void documentLockModeChanged(AcApDocument*,AcAp::DocLockMode,AcAp::DocLockMode,AcAp::DocLockMode,const ACHAR*);
    virtual void documentLockModeChangeVetoed(AcApDocument*,const ACHAR*);
    virtual void documentLockModeWillChange(AcApDocument*,AcAp::DocLockMode,AcAp::DocLockMode,AcAp::DocLockMode,const ACHAR*);
    virtual void documentToBeActivated(AcApDocument*);
    virtual void documentToBeDeactivated(AcApDocument*);
    virtual void documentToBeDestroyed(AcApDocument*);

protected:
    Acad::ErrorStatus veto();
};