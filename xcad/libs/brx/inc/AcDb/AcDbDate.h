// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbGlobal.h"

/** _ */
class BRX_IMPORTEXPORT AcDbDate
{
private:
    friend class BrxDbDateImp;
    class BrxDbDateImp* m_pBrxImp;

public:
    enum InitialValue
    {
        kInitZero = 1,
        kInitLocalTime,
        kInitUniversalTime
    };

    AcDbDate();
    AcDbDate(InitialValue);
    AcDbDate(const AcDbDate&);
    virtual ~AcDbDate();

    Acad::ErrorStatus dwgIn(AcDbDwgFiler*);
    Acad::ErrorStatus dwgOut(AcDbDwgFiler*) const;
    const AcDbDate& add(const AcDbDate&);
    const AcDbDate& subtract(const AcDbDate&);
    double julianFraction() const;
    long julianDay() const;
    long msecsPastMidnight() const;
    short day() const;
    short hour() const;
    short millisecond() const;
    short minute() const;
    short month() const;
    short second() const;
    short year() const;
    void getDate(short&,short&,short&) const;
    void getLocalTime();
    void getTime(short&,short&,short&,short&) const;
    void getTime(SYSTEMTIME&) const;
    void getUniversalTime();
    void localToUniversal();
    void setDate(short,short,short);
    void setDay(short);
    void setHour(short);
    void setJulianDate(long,long);
    void setJulianDay(long);
    void setJulianFraction(double);
    void setMillisecond(short);
    void setMinute(short);
    void setMonth(short);
    void setMsecsPastMidnight(long);
    void setSecond(short);
    void setTime(const SYSTEMTIME&);
    void setTime(short,short,short,short);
    void setToZero();
    void setYear(short);
    void universalToLocal();

    bool operator<(const AcDbDate&) const;
    bool operator<=(const AcDbDate&) const;
    bool operator==(const AcDbDate&) const;
    bool operator>(const AcDbDate&) const;
    bool operator>=(const AcDbDate&) const;
    const AcDbDate operator+(const AcDbDate&) const;
    const AcDbDate operator-(const AcDbDate&) const;
    const AcDbDate& operator+=(const AcDbDate&);
    const AcDbDate& operator-=(const AcDbDate&);
    const AcDbDate& operator=(const AcDbDate&);
};
