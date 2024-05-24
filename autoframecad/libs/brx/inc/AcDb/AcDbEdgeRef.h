// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "Misc/MiscGlobal.h"
#include "AcDb/AcDbSubentId.h"
#include "AcDb/AcDbCompoundObjectId.h"
#include "AcDb/AcDbFullSubentPath.h"
#include "AcDb/AcDbSubentRef.h"

class AcRxObject;
class AcDbEntity;

class AcGeCurve3d;

/** _ */
class BRX_IMPORTEXPORT AcDbEdgeRef : public AcDbSubentRef
{
public:
    ACRX_DECLARE_MEMBERS(AcDbEdgeRef);

    AcDbEdgeRef();
    AcDbEdgeRef(const AcDbEdgeRef&);

    virtual ~AcDbEdgeRef();

    explicit AcDbEdgeRef(const AcDbCompoundObjectId&, 
                         const AcDbSubentId& = kNullSubentId, 
                         const AcDbSubentId& = kNullSubentId, 
                         const AcGeCurve3d* = NULL);

    explicit AcDbEdgeRef(const AcGeCurve3d*);
    explicit AcDbEdgeRef(const AcDbEntity*);  
    explicit AcDbEdgeRef(const AcDbFullSubentPath&);  

    AcDbEdgeRef& operator=(const AcDbEdgeRef&);

    virtual bool isEmpty() const;
    virtual bool isValid() const;
    virtual void reset();

    virtual Acad::ErrorStatus copyFrom(const AcRxObject*);

    AcDbSubentId faceSubentId() const;
    void setFaceSubentity(const AcDbSubentId&);

    const AcGeCurve3d* curve() const;
    virtual AcDbEntity* createEntity() const;

    virtual Acad::ErrorStatus evaluateCurve(AcGeCurve3d*&) const;
    virtual Acad::ErrorStatus evaluateAndCacheGeometry(); 

private:
    void setCurve(const AcGeCurve3d*);
};
