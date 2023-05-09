// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbEvalIdMap.h"
#include "AcDb/AcDbObject.h"

/** _ */
class AcDbEvalGraph: public AcDbObject
{
public:
    enum NodeId
    {
        kNullNodeId = 0
    };

    ACDB_DECLARE_MEMBERS(AcDbEvalGraph);

    AcDbEvalGraph();
    virtual ~AcDbEvalGraph();

    virtual Acad::ErrorStatus activate(const AcDbEvalNodeIdArray&) const;
    virtual Acad::ErrorStatus activate(const AcDbEvalNodeIdArray&,AcDbEvalNodeIdArray*) const;
    virtual Acad::ErrorStatus activate(const AcDbEvalNodeIdArray&,AcDbEvalNodeIdArray*,AcDbEvalNodeIdArray*) const;
    virtual Acad::ErrorStatus addEdge(const AcDbEvalNodeId&,const AcDbEvalNodeId&);
    virtual Acad::ErrorStatus addEdge(const AcDbEvalNodeId&,const AcDbEvalNodeId&,bool);
    virtual Acad::ErrorStatus addGraph(AcDbEvalGraph*,AcDbEvalIdMap*&);
    virtual Acad::ErrorStatus addNode(AcDbEvalExpr*,AcDbEvalNodeId&);
    virtual Acad::ErrorStatus evaluate() const;
    virtual Acad::ErrorStatus evaluate(const AcDbEvalContext*) const;
    virtual Acad::ErrorStatus evaluate(const AcDbEvalContext*,const AcDbEvalNodeIdArray*) const;
    virtual Acad::ErrorStatus getAllNodes(AcDbEvalNodeIdArray&) const;
    virtual Acad::ErrorStatus getEdgeInfo(const AcDbEvalNodeId&,const AcDbEvalNodeId&,AcDbEvalEdgeInfo&) const;
    virtual Acad::ErrorStatus getIncomingEdges(const AcDbEvalNodeId&,AcDbEvalEdgeInfoArray&) const;
    virtual Acad::ErrorStatus getIsActive(const AcDbEvalNodeId&,bool&) const;
    virtual Acad::ErrorStatus getNode(const AcDbEvalNodeId&,AcDb::OpenMode,AcDbObject**) const;
    virtual Acad::ErrorStatus getOutgoingEdges(const AcDbEvalNodeId&,AcDbEvalEdgeInfoArray&) const;
    virtual Acad::ErrorStatus postInDatabase(AcDbObjectId&,AcDbDatabase*);
    virtual Acad::ErrorStatus removeEdge(const AcDbEvalNodeId&,const AcDbEvalNodeId&);
    virtual Acad::ErrorStatus removeNode(AcDbEvalExpr*);
    virtual Acad::ErrorStatus removeNode(const AcDbEvalNodeId&);
    virtual bool equals(const AcDbEvalGraph*) const;
    virtual bool isSubgraphOf(const AcDbEvalGraph*) const;

    static Acad::ErrorStatus createGraph(AcDbDatabase*,const ACHAR*);
    static Acad::ErrorStatus createGraph(AcDbObject*,const ACHAR*);
    static Acad::ErrorStatus getGraph(AcDbDatabase*,const ACHAR*,AcDbEvalGraph**,const AcDb::OpenMode);
    static Acad::ErrorStatus getGraph(const AcDbObject*,const ACHAR*,AcDbEvalGraph**,const AcDb::OpenMode);
    static Acad::ErrorStatus removeGraph(AcDbDatabase*,const ACHAR*);
    static Acad::ErrorStatus removeGraph(AcDbObject*,const ACHAR*);
    static Acad::ErrorStatus replaceGraph(AcDbObject*,const ACHAR*,AcDbObjectId);
    static bool hasGraph(AcDbDatabase*,const ACHAR*);
    static bool hasGraph(const AcDbObject*,const ACHAR*);
};
