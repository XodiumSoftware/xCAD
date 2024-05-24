// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcGs/AcGsDCPoint.h"

/** _ */
class BRX_IMPORTEXPORT AcGsDCRect
{
public:
    enum NullFlag
    {
        Null = 0
    };

    AcGsDCPoint m_min;
    AcGsDCPoint m_max;

    AcGsDCRect();
    AcGsDCRect(const AcGsDCPoint&,const AcGsDCPoint&);
    AcGsDCRect(long,long,long,long);
    AcGsDCRect(NullFlag);

    bool is_null() const;
    bool within(const AcGsDCRect&) const;
    void set_null();

    AcGsDCRect& operator=(const AcGsDCRect&);
    bool operator!=(const AcGsDCRect&) const;
    bool operator==(const AcGsDCRect&) const;
    void operator&=(const AcGsDCRect&);
    void operator|=(const AcGsDCRect&);
};