// Copyright (C) Menhirs NV. All rights reserved.
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
