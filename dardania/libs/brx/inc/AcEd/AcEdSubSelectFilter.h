// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbEntity.h"

/** _ */
class BRX_IMPORTEXPORT AcEdSubSelectFilter
{
public:
    enum SubSelectStatus
    {
        kSubSelectionNone = 0,
        kSubSelectionAugment,
        kSubSelectionExclusive,
        kSubSelectAll
    };

    virtual Acad::ErrorStatus subSelectClassList(AcArray<AcRxClass*>&);
    virtual bool cancelAllSubSelect();
    virtual bool cancelSubSelect(AcDbEntity*);
    virtual bool isSubSelected(AcDbEntity*) const;
    virtual bool onKey(unsigned long,unsigned int,unsigned int,unsigned int);
    virtual bool reSubSelectEntity(AcDbEntity*,AcDbFullSubentPathArray&);
    virtual bool selectEntity(const AcGePoint3d&,const AcGeVector3d&,const AcGeVector3d&,double,double,long,const AcGiViewport*,AcDbEntity*) const;
    virtual SubSelectStatus subSelectEntity(const AcGePoint3d&,const AcGePoint3d&,const AcGeVector3d&,const AcGeVector3d&,double,double,AcDb::SelectType,bool,bool,bool,const AcGiViewport*,AcDbEntity*,AcDbFullSubentPathArray&);
    virtual SubSelectStatus subSelectEntity(const resbuf*,bool,bool,bool,const AcGiViewport*,AcDbEntity*,AcDbFullSubentPathArray&);
};