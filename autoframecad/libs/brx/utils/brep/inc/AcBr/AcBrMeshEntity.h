// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcBr/AcBrGlobal.h"

class AcBrEntity;
class AcRxObject;

class AcBrMeshEntity: public AcRxObject
{
public:
    ACRX_DECLARE_MEMBERS(AcBrMeshEntity);

protected:
    friend class BrxBrMeshEntityImp;
    class BrxBrMeshEntityImp* m_pBrxImp;

    AcBrMeshEntity();
    AcBrMeshEntity(const AcBrMeshEntity&);
public:
    virtual ~AcBrMeshEntity();

    AcBr::ErrorStatus getEntityAssociated(AcBrEntity*&) const;
    AcBr::ErrorStatus getValidationLevel(AcBr::ValidationLevel&) const;
    AcBr::ErrorStatus setValidationLevel(const AcBr::ValidationLevel& = AcBr::kFullValidation);
    Adesk::Boolean brepChanged() const;
    Adesk::Boolean isEqualTo(const AcRxObject*) const;
    Adesk::Boolean isNull() const;

protected:
    AcBrMeshEntity& operator=(const AcBrMeshEntity&);
};
