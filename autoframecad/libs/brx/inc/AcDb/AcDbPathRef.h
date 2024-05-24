// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "Misc/MiscGlobal.h"
#include "Misc/AcArray.h"
#include "AcDb/AcDbFullSubentPath.h"
#include "AcDb/AcDbEdgeRef.h"

class AcDbEntity;
class AcGeCurve3d;

/** _ */
class AcDbPathRef : public AcDbGeomRef
{
public:
    ACRX_DECLARE_MEMBERS(AcDbPathRef);

    AcDbPathRef();
    AcDbPathRef(const AcDbPathRef&);
    virtual ~AcDbPathRef();

    explicit AcDbPathRef(const AcArray<AcDbEdgeRef>&);

    AcDbPathRef(const AcDbFullSubentPathArray& edgeSubentPathArr,
                const AcDbFullSubentPathArray& faceSubentPathArr);

    virtual Acad::ErrorStatus copyFrom(const AcRxObject*);

    virtual bool isEmpty() const;
    virtual bool isValid() const;    
    virtual void reset();

    virtual AcDbEntity* createEntity() const;
    virtual Acad::ErrorStatus evaluateAndCacheGeometry();

    bool isEqualTo(const AcGeCurve3d*);
    bool isReferencePath();

    void setEdgeRefs(const AcArray<AcDbEdgeRef>&);
    const AcArray<AcDbEdgeRef>& edgeRefs() const;

    Acad::ErrorStatus getEntityArray(AcArray<AcDbEntity*>&entities, bool) const;

private:
    void* m_pImpl;
};
