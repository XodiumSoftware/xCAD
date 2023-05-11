// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcRx/AcRxObject.h"

/** _ */
class BRX_IMPORTEXPORT AcRxCopyOnWriteObject : public AcRxObject
{
public:
    ACRX_DECLARE_MEMBERS(AcRxCopyOnWriteObject);

    AcRxCopyOnWriteObject(AcRxObject*);
    AcRxCopyOnWriteObject(const AcRxCopyOnWriteObject&);
    virtual ~AcRxCopyOnWriteObject();

    const AcRxCopyOnWriteObject& operator=(const AcRxCopyOnWriteObject&);

protected:
    AcRxObject* write();
    const AcRxObject* read() const;
    void unshare();

private:
    void* mpData;
};

// Helper macros used by derived classes

#define ACRX_DECLARE_MEMBERS_READWRITE_EXPIMP(CLASS, DATATYPE, EXPIMP) \
    ACRX_DECLARE_MEMBERS_EXPIMP(CLASS, EXPIMP); \
    DATATYPE* write() { return (DATATYPE*)AcRxCopyOnWriteObject::write(); } \
    const DATATYPE* read() const { return (const DATATYPE*)AcRxCopyOnWriteObject::read(); }

#define ACRX_DECLARE_MEMBERS_READWRITE(CLASS, DATATYPE) \
    ACRX_DECLARE_MEMBERS_READWRITE_EXPIMP(CLASS, DATATYPE, ACRX_EMPTY)
