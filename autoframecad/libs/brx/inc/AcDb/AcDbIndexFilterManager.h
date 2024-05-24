// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbIndex.h"

/** _ */
namespace AcDbIndexFilterManager
{
    Acad::ErrorStatus addFilter(AcDbBlockReference*,AcDbFilter*);
    Acad::ErrorStatus addIndex(AcDbBlockTableRecord*,AcDbIndex*);
    Acad::ErrorStatus getFilter(const AcDbBlockReference*,const AcRxClass*,AcDb::OpenMode,AcDbFilter*&);
    Acad::ErrorStatus getFilter(const AcDbBlockReference*,int,AcDb::OpenMode,AcDbFilter*&);
    Acad::ErrorStatus getIndex(const AcDbBlockTableRecord*,const AcRxClass*,AcDb::OpenMode,AcDbIndex*&);
    Acad::ErrorStatus getIndex(const AcDbBlockTableRecord*,int,AcDb::OpenMode,AcDbIndex*&);
    Acad::ErrorStatus removeFilter(AcDbBlockReference*,const AcRxClass*);
    Acad::ErrorStatus removeIndex (AcDbBlockTableRecord*,const AcRxClass*);
    Acad::ErrorStatus updateIndexes(AcDbDatabase*);
    int numFilters(const AcDbBlockReference*);
    int numIndexes(const AcDbBlockTableRecord*);
};
