// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "Misc/MiscGlobal.h"
#include "AcDb/AcDbSubentId.h"
#include "AcDb/AcDbCompoundObjectId.h"

class AcRxObject;
class BODY;

/** _ */
class AcDbFaceRef : public AcDbSubentRef
{
public:
    ACRX_DECLARE_MEMBERS(AcDbFaceRef);

    AcDbFaceRef();
    AcDbFaceRef(const AcDbFaceRef&);
    virtual ~AcDbFaceRef();

    explicit AcDbFaceRef(const AcDbCompoundObjectId&,
                         const AcDbSubentId& = kNullSubentId,
                         class BODY* = NULL); 

    AcDbFaceRef& operator=(const AcDbFaceRef&);

    virtual bool isEmpty() const;
    virtual bool isValid() const;
    virtual void reset();

    virtual Acad::ErrorStatus copyFrom(const AcRxObject*);

    virtual AcDbEntity* createEntity() const;

    virtual Acad::ErrorStatus evaluateAndCacheGeometry();

    BODY* asmBody() const;

private:
    void* m_pImpl;
};
