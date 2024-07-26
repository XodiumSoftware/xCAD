// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "Atil/Defs.h"


namespace Atil
{;

class Vector2d;
class Point2d;


class ATIL_IMPORTEXPORT Matrix2d
{
public:
    static Matrix2d translation(const Vector2d& v);
    static Matrix2d rotation(double angle, const Point2d& center);
    static Matrix2d scaling(double scaleAll, const Point2d& center);
    static Matrix2d mirroring(const Point2d& pnt);
    static Matrix2d alignCoordSys(const Point2d& pfo, const Vector2d& vf1, const Vector2d& vf2, const Point2d& pto, const Vector2d& vt1, const Vector2d& vt2);

public:
    Matrix2d();
    Matrix2d(const Matrix2d& rh);
    Matrix2d& setToIdentity();
    Matrix2d operator*(const Matrix2d& mx) const;
    Matrix2d& operator*=(const Matrix2d& mx);
    Matrix2d& preMultBy(const Matrix2d& lh);
    Matrix2d& postMultBy(const Matrix2d& rh);
    Matrix2d& setToProduct(const Matrix2d& mx1, const Matrix2d& mx2);
    Matrix2d& invert();
    Matrix2d inverse() const;
    bool isSingular() const;
    Matrix2d& transposeIt();
    Matrix2d transpose() const;
    bool operator== (const Matrix2d& mx) const;
    bool operator!= (const Matrix2d& mx) const;
    bool isEqualTo (const Matrix2d& mx) const;
    double scale(void);
    double det() const;
    Matrix2d& setTranslation(const Vector2d& v);
    Vector2d translation() const;
    bool isConformal (double& sc, double& ang, bool& mir, Vector2d& vref) const;
    Matrix2d& setCoordSystem(const Point2d& po, const Vector2d& v1, const Vector2d& v2);
    void getCoordSystem(Point2d& po, Vector2d& v1, Vector2d& v2) const;
    Matrix2d& setToTranslation(const Vector2d& v);
    Matrix2d& setToRotation(double ang, const Point2d& c);
    Matrix2d& setToScaling(double sc, const Point2d& c);
    Matrix2d& setToScaling(double sx, double sy, const Point2d& c);
    Matrix2d& setToMirroring(const Point2d& p);
    Matrix2d& setToAlignCoordSys(const Point2d&  pfo, const Vector2d& vf1, const Vector2d& vf2, const Point2d& pt0, const Vector2d& vt1, const Vector2d& vt2);
    double operator()(unsigned int r, unsigned int c) const { return entry[r][c]; }
    double& operator()(unsigned int r, unsigned int c) { return entry[r][c]; }

public:
    static const Matrix2d kIdentity;
    double entry[3][3];
};


} //namespace Atil
