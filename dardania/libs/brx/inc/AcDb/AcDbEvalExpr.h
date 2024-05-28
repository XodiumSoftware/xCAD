// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbEvalIdMap.h"
#include "AcDb/AcDbEvalVariant.h"
#include "AcDb/AcDbObject.h"

/** _ */
class AcDbEvalExpr: public AcDbObject
{
protected:
    AcDbEvalVariant m_lastValue;

public:
    ACDB_DECLARE_MEMBERS(AcDbEvalExpr);

    AcDbEvalExpr();
    virtual ~AcDbEvalExpr();

    virtual Acad::ErrorStatus evaluate(const AcDbEvalContext*);
    virtual Acad::ErrorStatus postInDatabase(AcDbObjectId&,AcDbDatabase*);
    virtual bool equals(const AcDbEvalExpr*) const;
    virtual bool isActivatable();
    virtual void activated(AcDbEvalNodeIdArray&);
    virtual void addedToGraph(AcDbEvalGraph*);
    virtual void adjacentEdgeAdded(const AcDbEvalNodeId&,const AcDbEvalNodeId&,bool);
    virtual void adjacentEdgeRemoved(const AcDbEvalNodeId&);
    virtual void adjacentNodeRemoved(const AcDbEvalNodeId&);
    virtual void copiedIntoGraph(AcDbEvalGraph*);
    virtual void graphEvalAbort(bool);
    virtual void graphEvalEnd(bool);
    virtual void graphEvalStart(bool);
    virtual void movedFromGraph(AcDbEvalGraph*);
    virtual void movedIntoGraph(AcDbEvalGraph*);
    virtual void remappedNodeIds(AcDbEvalIdMap&);
    virtual void removedFromGraph(AcDbEvalGraph*);

    Acad::ErrorStatus getGraph(AcDbEvalGraph**,AcDb::OpenMode) const;
    AcDbEvalNodeId nodeId() const;
    AcDbEvalVariant value() const;
};
