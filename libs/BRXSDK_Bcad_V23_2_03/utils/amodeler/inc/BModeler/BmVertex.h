// Copyright (C) 2006-2009 Menhirs NV. All rights reserved.
#pragma once

#include "BmEntity.h"
#include "BmIntPoint3d.h"

namespace AModeler
{

class ImplVertex;

class BM_IMPORTEXPORT Vertex: public Entity
{
//private:
public:
    std::shared_ptr<ImplVertex> m_pBrxImp;

public:
    Vertex	*marker;

    IntPoint3d ip;
    union
    {
        Edge* eptr;
        Vertex* vptr1;
    };
    union
    {
        int n;
        Vertex* vptr;
    };

    Vertex();
    Vertex(const Point3d&,Body*);
    ~Vertex();

    const Point3d& point() const;
    Vertex* next() const;
    VertexSurfaceData* vertexSurfaceData(const Edge*);
    VertexSurfaceData* vertexSurfaceDataList() const;
    void deleteVertexSurfaceData();
    void modified();
    void print(FILE* = NULL) const;
    void restore(SaveRestoreCallback*,int);
    void save(SaveRestoreCallback*) const;
    void setNext(Vertex*);
    void setPoint(const Point3d&);
    void setVertexSurfaceDataList(VertexSurfaceData*);
    void transform(const Transf3d&);
};

}
