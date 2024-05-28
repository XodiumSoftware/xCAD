// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#pragma pack(push, 8)

#include "AcRx/AcRxBoiler.h"

#ifdef __cplusplus

class BrxRxObjectImp;

/** _ */
class BRX_IMPORTEXPORT AcRxObject
{
protected:
    AcRxObject();
public:
    virtual ~AcRxObject();

    virtual Acad::ErrorStatus copyFrom(const AcRxObject*);
    virtual AcRx::Ordering comparedTo(const AcRxObject*) const;
    virtual AcRxClass* isA() const;
    virtual AcRxObject* clone() const;
    virtual Adesk::Boolean isEqualTo(const AcRxObject*) const;

    AcRxObject* queryX(const AcRxClass*) const;
    AcRxObject* x(const AcRxClass*) const;
    bool isKindOf(const AcRxClass*) const;

    static AcRxClass* desc();
    static AcRxObject* cast(const AcRxObject*);

private:
    friend BrxRxObjectImp;
    BrxRxObjectImp* m_pImp = NULL;
public:
    static OdRxObjectPtr createOdObjectImp(const ACHAR*);
};

#define ACRX_PE_PTR(RxObject,ProtExtClass) ProtExtClass::cast(RxObject->queryX(ProtExtClass::desc()))
#define ACRX_X_CALL(RxObject,ProtExtClass) ProtExtClass::cast(RxObject->x(ProtExtClass::desc()))

#endif //__cplusplus

#pragma pack(pop)
