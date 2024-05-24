// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbUnderlayItem.h"

/** _ */
class __declspec(novtable) AcDbUnderlayFile
{
public:
    virtual ~AcDbUnderlayFile() = 0;

    virtual Acad::ErrorStatus getItem(const ACHAR*,AcDbUnderlayItem*&) const = 0;
    virtual Acad::ErrorStatus getItem(int,AcDbUnderlayItem*&) const = 0;
    virtual int getItemCount() const = 0;
};
