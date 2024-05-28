// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbCurve.h"

/** _ */
class BRX_EXPORT AcDb3dPolyline: public AcDbCurve
{
public:
    ACDB_DECLARE_MEMBERS(AcDb3dPolyline);

    AcDb3dPolyline();
    AcDb3dPolyline(AcDb::Poly3dType,AcGePoint3dArray&,Adesk::Boolean = Adesk::kFalse);
    ~AcDb3dPolyline();

    DBCURVE_METHODS

    Acad::ErrorStatus appendVertex(AcDb3dPolylineVertex*);
    Acad::ErrorStatus appendVertex(AcDbObjectId&,AcDb3dPolylineVertex*);
    Acad::ErrorStatus convertToPolyType(AcDb::Poly3dType);
    Acad::ErrorStatus insertVertexAt(AcDbObjectId&,const AcDbObjectId&,AcDb3dPolylineVertex*);
    Acad::ErrorStatus insertVertexAt(const AcDb3dPolylineVertex*,AcDb3dPolylineVertex*);
    Acad::ErrorStatus makeClosed();
    Acad::ErrorStatus makeOpen();
    Acad::ErrorStatus openSequenceEnd(AcDbSequenceEnd*&,AcDb::OpenMode);
    Acad::ErrorStatus openVertex(AcDb3dPolylineVertex*&,AcDbObjectId,AcDb::OpenMode,bool = false);
    Acad::ErrorStatus setPolyType(AcDb::Poly3dType);
    Acad::ErrorStatus splineFit();
    Acad::ErrorStatus splineFit(AcDb::Poly3dType,Adesk::Int16);
    Acad::ErrorStatus straighten();
    AcDb::Poly3dType polyType() const;
    AcDbObjectIterator* vertexIterator() const;
    Acad::ErrorStatus setClosed(Adesk::Boolean);
    Acad::ErrorStatus length(double &) const;

protected:
    virtual Adesk::Boolean subWorldDraw(AcGiWorldDraw*);
};
