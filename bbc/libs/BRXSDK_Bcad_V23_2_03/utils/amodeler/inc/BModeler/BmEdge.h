// Copyright (C) 2006-2009 Menhirs NV. All rights reserved.
#pragma once

#include "BmEntity.h"

namespace AModeler
{

class ImplEdge;

class BM_IMPORTEXPORT Edge: public Entity
{
public:
    std::shared_ptr<ImplEdge> m_pBrxImp;

    union
    {
        Edge* eptr;
        Edge* nie;
        int n;
        int xmin;
        IntInterval3d* ibp;
    };

    Edge();
    Edge(Vertex*,Face*,Edge*,Edge*,Curve* = NULL);

    bool angleBetweenFacesIsConcave() const;
    bool angleBetweenFacesIsConvex() const;
    bool angleBetweenFacesIsStraight() const;
    bool canMergeWithPrevious(bool) const;
    bool hasPartner(Edge*) const;
    bool isApprox() const;
    bool isBridge() const;
    bool isEulerEdge() const;
    bool isManifold() const;
    bool isOnCircle() const;
    bool isOnFullCircle() const;
    Circle3d circle() const;
    Color color() const;
    Curve* curve() const;
    double angleBetweenEdges() const;
    double angleBetweenFaces() const;
    Edge* eulerEdge();
    Edge* getPartnerBridgeEdge() const;
    Edge* next() const;
    Edge* nextSkipBridge() const;
    Edge* partner() const;
    Edge* prev() const;
    Edge* prevSkipBridge() const;
    Face* face() const;
    Line3d line() const;
    Plane plane() const;
    Point3d point() const;
    Surface* surface() const;
    Vector3d normal() const;
    Vector3d unitVector() const;
    Vector3d vector() const;
    Vector3d vertexNormal() const;
    Vertex* vertex() const;
    void addAfter(Edge*);
    void addPartner(Edge*);
    void collapse();
    void getAllEdgesEndingInVertex(std::vector<Edge*>&);
    void getAllEdgesSharingSameFaces(bool,std::vector<Edge*>&);
    void getAllEdgesStartingFromVertex(std::vector<Edge*>&);
    void merge();
    void mergeLoopsAddBridgeEdge(Edge*);
    void mergeLoopsSharingEdge();
    void orderPartnerEdgesAroundEulerEdge();
    void print(FILE* = NULL) const;
    void remove();
    void removePartner();
    void restore(SaveRestoreCallback*);
    void save(SaveRestoreCallback*) const;
    void setApproxFlag(OnOff = kOn);
    void setBridgeFlag(OnOff = kOn);
    void setColor(Color,bool = false);
    void setCurve(Curve*,bool = false);
    void setFace(Face*);
    void setNext(Edge*);
    void setPartner(Edge*);
    void setPrev(Edge*);
    void setVertex(Vertex*);
    void split(Vertex*);
    // V12
    Flag flags() const;
};

}
