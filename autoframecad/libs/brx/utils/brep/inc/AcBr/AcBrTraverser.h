// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcBr/AcBrGlobal.h"

class AcRxObject;

class AcBrTraverser: public AcRxObject
{
public:
    ACRX_DECLARE_MEMBERS(AcBrTraverser);

protected:
    friend class BrxAcBrTraverserImp;
    class BrxAcBrTraverserImp* m_pBrxImp;

    AcBrTraverser();
    AcBrTraverser(const AcBrTraverser&);
public:
    virtual ~AcBrTraverser();
    
    AcBr::ErrorStatus getValidationLevel(AcBr::ValidationLevel&) const;
    AcBr::ErrorStatus next();
    AcBr::ErrorStatus restart();
    AcBr::ErrorStatus setValidationLevel(const AcBr::ValidationLevel& = AcBr::kFullValidation);
    Adesk::Boolean brepChanged() const;
    Adesk::Boolean done() const;
    Adesk::Boolean isEqualTo(const AcRxObject*) const;
    Adesk::Boolean isNull() const;

public:
    // for internal use only
    BrxAcBrTraverserImp* getImpl() const { return m_pBrxImp; };

protected:
    AcBrTraverser& operator=(const AcBrTraverser&);
};
