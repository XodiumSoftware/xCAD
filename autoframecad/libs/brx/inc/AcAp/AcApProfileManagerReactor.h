// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "Misc/MiscGlobal.h"

class AcApProfileManagerReactorImp;

/** _ */
class AcApProfileManagerReactor
{
public:
    AcApProfileManagerReactor();
    virtual ~AcApProfileManagerReactor();

    virtual void currentProfileChanged(const ACHAR*) {}
    virtual void currentProfileReset(const ACHAR*) {}
    virtual void currentProfileSaved(const ACHAR*) {}
    virtual void currentProfileWillBeReset(const ACHAR*) {}
    virtual void currentProfileWillBeSaved(const ACHAR*) {}
    virtual void currentProfileWillChange(const ACHAR*) {}
    virtual void profileReset(const ACHAR*) {}
    virtual void profileSaved(const ACHAR*) {}
    virtual void profileWillBeSaved(const ACHAR*) {}
    virtual void profileWillReset(const ACHAR*) {}

//BRX START
private:
    friend AcApProfileManagerReactorImp;
    AcApProfileManagerReactorImp* m_pBrxImp;
//BRX END
};
