// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "Misc/AcArray.h"
#include "AcDb/AcDbSurface.h"

class AcGeKnotVector;
class AcGeNurbSurface;

/** _ */
class BRX_EXPORT AcDbNurbSurface : public AcDbSurface
{
public:
    ACDB_DECLARE_MEMBERS(AcDbNurbSurface);

    AcDbNurbSurface();
    AcDbNurbSurface(int, int, bool, int, int,
                    const AcGePoint3dArray&, const AcGeDoubleArray&,
                    const AcGeKnotVector&,   const AcGeKnotVector&);

    virtual ~AcDbNurbSurface();

    Acad::ErrorStatus getNormal(double, double, AcGeVector3d&) const;
    Acad::ErrorStatus getWeight(int, int, double&) const;

    Acad::ErrorStatus get(int&, int&, bool&, int&, int&, AcGePoint3dArray&, AcGeDoubleArray&, AcGeKnotVector&, AcGeKnotVector&) const;
    Acad::ErrorStatus getControlPointAt(int, int, AcGePoint3d&) const;    
    Acad::ErrorStatus getControlPoints(int&, int&, AcGePoint3dArray&) const;    

    Acad::ErrorStatus getNumberOfControlPointsInU(int&) const;
    Acad::ErrorStatus getDegreeInU(int&) const;
    Acad::ErrorStatus getPeriodInU(double&) const;
    Acad::ErrorStatus getNumberOfSpansInU(int&) const;
    Acad::ErrorStatus getIsolineAtU(double, AcArray<AcDbCurve*>&) const;
    Acad::ErrorStatus getNumberOfKnotsInU(int&) const;
    Acad::ErrorStatus getUKnots(AcGeKnotVector&) const;
    Acad::ErrorStatus isClosedInU(bool&) const;
    Acad::ErrorStatus isPeriodicInU(bool&) const;
    Acad::ErrorStatus isClosedInV(bool&) const;
    Acad::ErrorStatus isPeriodicInV(bool&) const;

    Acad::ErrorStatus getNumberOfControlPointsInV(int&) const;
    Acad::ErrorStatus getDegreeInV(int&) const;
    Acad::ErrorStatus getPeriodInV(double&) const;
    Acad::ErrorStatus getNumberOfSpansInV(int&) const;
    Acad::ErrorStatus getIsolineAtV(double, AcArray<AcDbCurve*>&) const;
    Acad::ErrorStatus getNumberOfKnotsInV(int&) const;
    Acad::ErrorStatus getVKnots(AcGeKnotVector&) const;

    Acad::ErrorStatus getParameterOfPoint(const AcGePoint3d&, double&, double&) const;

    Acad::ErrorStatus isPointOnSurface(const AcGePoint3d&, bool&) const;
    Acad::ErrorStatus isPlanar(bool&, AcGePoint3d&, AcGeVector3d&) const;
    Acad::ErrorStatus isRational(bool&) const;    

    Acad::ErrorStatus setWeight(int, int, double);

    Acad::ErrorStatus set(int, int, bool, int, int, const AcGePoint3dArray&, const AcGeDoubleArray&, const AcGeKnotVector&, const AcGeKnotVector&);    
    Acad::ErrorStatus setControlPointAt(int, int, const AcGePoint3d&);    
    Acad::ErrorStatus setControlPoints(int, int, const AcGePoint3dArray&);    

    Acad::ErrorStatus evaluate(double, double, AcGePoint3d&) const;
    Acad::ErrorStatus evaluate(double, double, AcGePoint3d&, AcGeVector3d&, AcGeVector3d&) const;
    Acad::ErrorStatus evaluate(double, double, AcGePoint3d&, AcGeVector3d&, AcGeVector3d&, AcGeVector3d&, AcGeVector3d&, AcGeVector3d&) const;
    Acad::ErrorStatus evaluate(double, double, int, AcGePoint3d&, AcGeVector3dArray&) const;

    Acad::ErrorStatus InsertKnotAtU(double);
    Acad::ErrorStatus InsertControlPointsAtU(double u, const AcGePoint3dArray&, const AcGeDoubleArray&);
    Acad::ErrorStatus RemoveControlPointsAtU(int);

    Acad::ErrorStatus InsertKnotAtV(double);
    Acad::ErrorStatus RemoveControlPointsAtV(int);
    Acad::ErrorStatus InsertControlPointsAtV(double v, const AcGePoint3dArray&, const AcGeDoubleArray&);

    Acad::ErrorStatus modifyPositionAndTangent(double, double, const AcGePoint3d&, const AcGeVector3d* = NULL, const AcGeVector3d* = NULL);
    Acad::ErrorStatus rebuild(int, int, int, int, bool = false);

    void dragStatus (const AcDb::DragStat);

protected:
    virtual Acad::ErrorStatus subGetClassID(CLSID*) const;
};
