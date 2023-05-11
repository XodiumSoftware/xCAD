// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

class AcGePoint2d;

/** _ */
class BRX_IMPORTEXPORT AcDbMPolygonCrossing
{
public:
    AcDbMPolygonCrossing();
    ~AcDbMPolygonCrossing();

    AcGePoint2d getCrossingPoint() const;
    int getEdgeIndex() const;
    int getLoopIndex() const;
    void setCrossingPoint(const AcGePoint2d&);
    void setEdgeIndex(int);
    void setLoopIndex(int);
};
