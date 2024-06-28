// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
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
