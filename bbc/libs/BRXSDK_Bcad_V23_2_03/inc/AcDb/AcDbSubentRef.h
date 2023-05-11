// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "Misc/MiscGlobal.h"
#include "AcDb/AcDbSubentId.h"
#include "AcDb/AcDbFullSubentPath.h"
#include "AcDb/AcDbCompoundObjectId.h"
#include "AcDb/AcDbGeomRef.h"

class AcRxObject;
class BrxDbSubentRefImp;

/** _ */
class AcDbSubentRef : public AcDbGeomRef
{
public:
    ACRX_DECLARE_MEMBERS(AcDbSubentRef);

    AcDbSubentRef();
    virtual ~AcDbSubentRef();

    explicit AcDbSubentRef(const AcDbCompoundObjectId&,
                           const AcDbSubentId& = kNullSubentId); 

    AcDbSubentRef& operator=(const AcDbSubentRef&);

    virtual bool isEmpty() const;
    virtual bool isValid() const;
    virtual void reset();

    virtual AcDbSubentId subentId() const;
    virtual const AcDbCompoundObjectId& entity() const;

    virtual Acad::ErrorStatus copyFrom(const AcRxObject*);

    virtual Acad::ErrorStatus evaluateAndCacheGeometry();
    virtual AcDbEntity* createEntity() const;

protected:
    void setFromSubentPath(const AcDbFullSubentPath&);
    void setSubent(const AcDbSubentId&);
    void setEntity(const AcDbCompoundObjectId&);

private:
    BrxDbSubentRefImp* m_pBrxImp;
};
