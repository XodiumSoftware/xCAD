// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcGe/AcGeGlobal.h"

//BRX START
class OdGeInterval;
//BRX END

/** _ */
class BRX_IMPORTEXPORT AcGeInterval
{
private:
    //BRX START
    OdGeInterval* m_pBrxImp;
    //BRX END

public:
    AcGeInterval(double = 1.e-12);
    AcGeInterval(double,double,double = 1.e-12);
    AcGeInterval(Adesk::Boolean,double,double = 1.e-12);
    AcGeInterval(const AcGeInterval&);
    ~AcGeInterval();

    AcGeInterval& set();
    AcGeInterval& set(Adesk::Boolean,double);
    AcGeInterval& set(double,double);
    AcGeInterval& setLower(double);
    AcGeInterval& setTolerance(double);
    AcGeInterval& setUpper(double);
    Adesk::Boolean contains(const AcGeInterval&) const;
    Adesk::Boolean contains(double) const;
    Adesk::Boolean intersectWith(const AcGeInterval&,AcGeInterval&) const;
    Adesk::Boolean isBounded() const;
    Adesk::Boolean isBoundedAbove() const;
    Adesk::Boolean isBoundedBelow() const;
    Adesk::Boolean isContinuousAtUpper(const AcGeInterval&) const;
    Adesk::Boolean isDisjoint(const AcGeInterval&) const;
    Adesk::Boolean isEqualAtLower(const AcGeInterval&) const;
    Adesk::Boolean isEqualAtLower(double) const;
    Adesk::Boolean isEqualAtUpper(const AcGeInterval&) const;
    Adesk::Boolean isEqualAtUpper(double) const;
    Adesk::Boolean isOverlapAtUpper(const AcGeInterval&,AcGeInterval&) const;
    Adesk::Boolean isPeriodicallyOn(double,double&);
    Adesk::Boolean isSingleton() const;
    Adesk::Boolean isUnBounded() const;
    double element() const;
    double length() const;
    double lowerBound() const;
    double tolerance() const;
    double upperBound() const;
    int subtract(const AcGeInterval&,AcGeInterval&,AcGeInterval&) const;
    void getBounds(double&,double&) const;
    void getMerge(const AcGeInterval&,AcGeInterval&) const;

    AcGeInterval& operator=(const AcGeInterval&);
    Adesk::Boolean operator!=(const AcGeInterval&) const;
    Adesk::Boolean operator<(const AcGeInterval&) const;
    Adesk::Boolean operator<(double) const;
    Adesk::Boolean operator<=(const AcGeInterval&) const;
    Adesk::Boolean operator<=(double) const;
    Adesk::Boolean operator==(const AcGeInterval&) const;
    Adesk::Boolean operator>(const AcGeInterval&) const;
    Adesk::Boolean operator>(double) const;
    Adesk::Boolean operator>=(const AcGeInterval&) const;
    Adesk::Boolean operator>=(double) const;

    friend Adesk::Boolean operator<(double,const AcGeInterval&);
    friend Adesk::Boolean operator<=(double,const AcGeInterval&);
    friend Adesk::Boolean operator>(double,const AcGeInterval&);
    friend Adesk::Boolean operator>=(double,const AcGeInterval&);
};
