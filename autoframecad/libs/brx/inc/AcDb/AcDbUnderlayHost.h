// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
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
