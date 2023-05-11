// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbEvalExpr.h"
#include "Misc/AcString.h"

/** _ */
class AcDbEvalConnectable: public AcDbEvalExpr
{
public:
    ACRX_DECLARE_MEMBERS(AcDbEvalConnectable);

protected:
    AcDbEvalConnectable();
public:
    virtual ~AcDbEvalConnectable();

    virtual Acad::ErrorStatus connectTo(const AcString&,const AcDbEvalNodeId,const AcString&);
    virtual Acad::ErrorStatus disconnectFrom(const AcString&,const AcDbEvalNodeId,const AcString&);
    virtual Acad::ErrorStatus getConnectedNames(const AcString&,const AcDbEvalNodeId,AcStringArray&) const;
    virtual Acad::ErrorStatus getConnectedObjects(const AcString&,AcDbEvalNodeIdArray&) const;
    virtual Acad::ErrorStatus getConnectionNames(AcStringArray&) const;
    virtual Acad::ErrorStatus getConnectionType(const AcString&,AcDb::DwgDataType&) const;
    virtual Acad::ErrorStatus getConnectionValue(const AcString&,AcDbEvalVariant&) const;
    virtual Acad::ErrorStatus setConnectionValue(const AcString&,const AcDbEvalVariant&);
    virtual bool connectionAllowed(const AcString&,const AcDbEvalNodeId,const AcString&) const;
    virtual bool hasConnectionNamed(const AcString&) const;
};
