// Copyright (C) 2006-2009 Menhirs NV. All rights reserved.
#pragma once

#include "BmGlobal.h"

namespace AModeler
{

class ImplMorphingMap;

class BM_IMPORTEXPORT MorphingMap
{
private:
    std::shared_ptr<ImplMorphingMap> m_pBrxImp;

public:
    enum
    {
        kCrossEdgeIsApprox = 1,
        kBaseEdgeIsApprox
    };

    static const MorphingMap kNull;

    MorphingMap();
    MorphingMap(const MorphingMap&);
    ~MorphingMap();

    bool isIdentity() const;
    bool isNull() const;
    int length() const;
    void add(int,int,int = 0);
    void addAt(int,int,int,int = 0);
    void createFromTwoPointLoops(const std::vector<Point2d>&,const std::vector<Point2d>&);
    void del(int);
    void get(int,int&,int&,int&) const;
    void init();
    void normalize(int,int);
    void print() const;
    void remapIndices(const std::vector<int>&,const std::vector<int>&);
    void setToExplicitIdentityMap(int);

    MorphingMap& operator=(const MorphingMap&);
};

}
