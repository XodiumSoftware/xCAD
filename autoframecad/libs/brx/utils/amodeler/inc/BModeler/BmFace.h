// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "BmEntity.h"
#include "BmInterval3d.h"
#include "BmPlane.h"

namespace AModeler
{

class ImplFace;

class BM_IMPORTEXPORT Face: public Entity
{
public:
    std::shared_ptr<ImplFace> m_pBrxImp;

    Face	*marker;
public:
    union
    {
        Edge* iel;
        Face* fptr;
        int n;
    };

    Face();
    Face(Body*);
    Face(const Face&);
    Face(Surface*,Body*);
    Face(Edge*,Surface*,Body*);
    Face(const Circle3d&,int,int,Body*);
    Face(Point3d[],int,int,bool,Body*,Edge** = NULL);
    Face(Vertex*[],Curve*[],Edge*[],int,int,bool,Body*,Edge** = NULL);
    Face(const Point3d[],PolygonVertexData*[],int,const Vector3d&,int,bool,Body*);
    ~Face();

    bool isPlanar(double = epsAbs()) const;
    bool isPointInside(const Point3d&) const;
    bool isSelfIntersecting() const;
    Color color() const;
    const Interval3d& interval() const;
    const IntInterval3d& projInterval() const;
    const Plane& plane() const;
    double area() const;
    Edge* edge(int) const;
    Edge* edgeLoop() const;
    Face* next() const;
    Face* prev() const;
    Face* split(Edge*,Edge*,Body*);
    int edgeCount() const;
    Surface* surface() const;
    void addEdge(Edge*,Edge* = NULL);
    void decomposeIntoContiguousFaces(Body*,std::vector<Face*>&);
    void deleteAllEdges();
    void deleteInterval() const;
    void deletePlane() const;
    void deleteProjInterval() const;
    void extractAllLoops(std::vector< std::vector<Edge*> >&) const;
    void insertHoles(const std::vector<Face*>&,Body*,std::vector<Face*>&);
    void lift(const Transf3d&,bool,Body*);
    void massProperties(const Body&,bool,bool,double&,double&,Point3d&) const;
    void modified();
    void negate();
    void paint(const Body&,Color,bool = false,bool = false);
    void print(FILE* = NULL) const;
    void removeEdge(Edge*);
    void restore(SaveRestoreCallback*,int);
    void save(SaveRestoreCallback*) const;
    void setAttrib(void*);
    void setColor(Color,bool = false,bool = false);
    void setEdgeLoop(Edge*);
    void setNext(Face*);
    void setPrev(Face*);
    void setProjInterval(const IntInterval3d&) const;
    void setSurface(Surface*);
    void triangulate(OutputTriangleCallback*,TriangulationType = kGenerateTriangles) const;
    void* attrib() const;
private:
    mutable Interval3d	interval_, proj_interval_;
};

}
