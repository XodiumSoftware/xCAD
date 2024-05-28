// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcGe/AcGeGlobal.h"

/** _ */
class BRX_IMPORTEXPORT AcGeKnotVector
{
protected:
    AcGeDoubleArray m_values;
    double m_tol;

public:
    AcGeKnotVector(double = 1.e-9);
    AcGeKnotVector(int,int,double = 1.e-9);
    AcGeKnotVector(int,const double[],double = 1.e-9);
    AcGeKnotVector(int,const AcGeKnotVector&);
    AcGeKnotVector(const AcGeKnotVector&);
    AcGeKnotVector(const AcGeDoubleArray&,double = 1.e-9);
    ~AcGeKnotVector();

    AcGeKnotVector& append(AcGeKnotVector&,double = 0.0);
    AcGeKnotVector& insert(double);
    AcGeKnotVector& insertAt(int,double,int = 1);
    AcGeKnotVector& removeAt(int);
    AcGeKnotVector& removeSubVector(int,int);
    AcGeKnotVector& reverse();
    AcGeKnotVector& set(int,const double[],double = 1.e-9);
    AcGeKnotVector& setGrowLength(int);
    AcGeKnotVector& setLogicalLength(int);
    AcGeKnotVector& setPhysicalLength(int);
    AcGeKnotVector& setRange(double,double);
    AcGeKnotVector& setTolerance(double);
    Adesk::Boolean contains(double) const;
    Adesk::Boolean isEmpty() const;
    Adesk::Boolean isEqualTo(const AcGeKnotVector&) const;
    Adesk::Boolean isOn(double) const;
    const double* asArrayPtr() const;
    double endParam() const;
    double startParam() const;
    double tolerance() const;
    double* asArrayPtr();
    int append(double);
    int getInterval(int,double,AcGeInterval&) const;
    int growLength() const;
    int length() const;
    int logicalLength() const;
    int multiplicityAt(int) const;
    int numIntervals() const;
    int physicalLength() const;
    int split(double,AcGeKnotVector*,int,AcGeKnotVector*,int) const;
    void getDistinctKnots(AcGeDoubleArray&) const;

protected:
    Adesk::Boolean isValid(int) const;

public:
    AcGeKnotVector& operator=(const AcGeDoubleArray&);
    AcGeKnotVector& operator=(const AcGeKnotVector&);
    const double operator[](int) const;
    double& operator[](int);
};
