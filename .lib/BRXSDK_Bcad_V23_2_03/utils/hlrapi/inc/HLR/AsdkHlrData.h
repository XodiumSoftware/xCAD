// Copyright (C) 2006-2009 Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbSubentId.h"
#include "HlrGlobal.h"

class HLR_IMPORTEXPORT AsdkHlrData
{
public:
    // declares the visibility state for result entities
    enum Visibility
    {
        kVisible = 0,       // curve is visible
        kHidden,            // curve is hidden by other geometry
        kOccluded,          // curve is hidden by another curve
        kInternallyHidden,  // curve is hidden by by the source entity itself
        kUndefined          // undefined visibility
    };

protected:
    AcDbEntity* m_pEntity;         // source entity for the entity
    AcDbEntity* m_pResultEntity;   // a resulting HLR entity
    AcDbObjectIdArray m_objectIds; // chain of source entities for this result entity
    AcDbSubentId m_subentId;       // subentity ID for this result entity
    Visibility m_hlrVisibility;    // the primary visibility for result entity with 'kInternallyHidden' visibility
    Visibility m_visibility;       // visibility status of result entity

public:
    AsdkHlrData();
    AsdkHlrData(AcDbEntity* pSource, AcDbEntity* pResult);
    virtual ~AsdkHlrData();

    // returns the source entity for the result entity
    AcDbEntity* getEntity();

    // returns the result entity (typically a curve, could also be a point)
    AcDbEntity* getResultEntity();

    // returns the chain of source entities (when nested)
    AcDbObjectIdArray& getObjectIds();

    // returns the subentity type (if appropriate)
    AcDbSubentId getSubentId();

    // returns the visibility status for the entity (see above)
    Visibility getHlrVisibility();
    Visibility getVisibility();

    // for internal use; typically not to be used by application
    void setEntity(AcDbEntity*);
    void setHlrVisibility(Visibility);
    inline void setObjectIds(const AcDbObjectIdArray& ids) { m_objectIds = ids; }
    void setResultEntity(AcDbEntity*);
    inline void setSubentId(const AcDbSubentId& subentId) { m_subentId = subentId; }
    void setVisibility(Visibility);
};
