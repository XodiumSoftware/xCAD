// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbUnderlayFile.h"

/** _ */
class __declspec(novtable) AcDbUnderlayHost
{
protected:
    virtual ~AcDbUnderlayHost() = 0;

public:
    virtual Acad::ErrorStatus getFile(const ACHAR*,const ACHAR*,AcDbUnderlayFile*&) const = 0;

    static void getAdjustedColor(AcGeVector3d&,const AcGeVector3d&,const AcGeVector3d&,const AcGeVector3d&,const AcDbUnderlayDrawContext&);
};
