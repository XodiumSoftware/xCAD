// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcRx/AcRxObject.h"
#include "AcRx/AcRxDictionaryIterator.h"

/** _ */
class BRX_IMPORTEXPORT AcRxDictionary: public AcRxObject
{
public:
    ACRX_DECLARE_MEMBERS(AcRxDictionary);

    virtual AcRxDictionaryIterator* newIterator(AcRx::DictIterType = AcRx::kDictSorted) = 0;
    virtual AcRxObject* at(Adesk::UInt32) const = 0;
    virtual AcRxObject* at(const ACHAR*) const = 0;
    virtual AcRxObject* atPut(Adesk::UInt32,AcRxObject*) = 0;
    virtual AcRxObject* atPut(const ACHAR*,AcRxObject*,Adesk::UInt32&) = 0;
    virtual AcRxObject* remove(Adesk::UInt32) = 0;
    virtual AcRxObject* remove(const ACHAR*) = 0;
    virtual Adesk::Boolean atKeyAndIdPut(const ACHAR*,Adesk::UInt32,AcRxObject*) = 0;
    virtual Adesk::Boolean deletesObjects() const = 0;
    virtual Adesk::Boolean has(Adesk::UInt32) const = 0;
    virtual Adesk::Boolean has(const ACHAR*) const = 0;
    virtual Adesk::Boolean isCaseSensitive() const = 0;
    virtual Adesk::Boolean isSorted() const = 0;
    virtual Adesk::Boolean resetKey(Adesk::UInt32,const ACHAR*) = 0;
    virtual Adesk::Boolean resetKey(const ACHAR*,const ACHAR*) = 0;
    virtual Adesk::UInt32 idAt(const ACHAR*) const = 0;
    virtual Adesk::UInt32 numEntries() const = 0;
    virtual const ACHAR* keyAt(Adesk::UInt32) const = 0;

    AcRxObject* atPut(const ACHAR*,AcRxObject*);
};

extern "C" AcRxDictionary* acrxSysRegistry();

#define acrxClassDictionary AcRxDictionary::cast(acrxSysRegistry()->at(ACRX_CLASS_DICTIONARY))
#define acrxServiceDictionary AcRxDictionary::cast(acrxSysRegistry()->at(ACRX_SERVICE_DICTIONARY))
