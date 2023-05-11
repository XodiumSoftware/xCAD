// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbEntity.h"

/** _ */
class BRX_EXPORT AcDbFcf: public AcDbEntity
{
public:
    enum whichLine
    {
        kAll = -1
    };

    ACDB_DECLARE_MEMBERS(AcDbFcf);

    AcDbFcf();
    AcDbFcf(const ACHAR*,const AcGePoint3d&,const AcGeVector3d&,const AcGeVector3d&);
    virtual ~AcDbFcf();

    virtual AcDbHardPointerId dimensionStyle() const;
    virtual AcGePoint3d location() const;
    virtual AcGeVector3d direction() const;
    virtual AcGeVector3d normal() const;
    virtual ACHAR* text(const int = kAll) const;
    virtual bool castShadows() const;
    virtual bool receiveShadows() const;
    virtual void getBoundingPline(AcGePoint3dArray&) const;
    virtual void getBoundingPoints(AcGePoint3dArray&) const;
    virtual void setCastShadows(bool);
    virtual void setDimensionStyle(AcDbHardPointerId);
    virtual void setDimVars();
    virtual void setLocation(const AcGePoint3d&);
    virtual void setOrientation(const AcGeVector3d&,const AcGeVector3d&);
    virtual void setReceiveShadows(bool);
    virtual void setText(const ACHAR*);

    Acad::ErrorStatus getDimstyleData(AcDbDimStyleTableRecord*&) const;
    Acad::ErrorStatus setDimclrd(AcCmColor&);
    Acad::ErrorStatus setDimclrt(AcCmColor&);
    Acad::ErrorStatus setDimgap(double);
    Acad::ErrorStatus setDimscale(double);
    Acad::ErrorStatus setDimstyleData(AcDbDimStyleTableRecord*);
    Acad::ErrorStatus setDimstyleData(AcDbObjectId);
    Acad::ErrorStatus setDimtxsty(AcDbObjectId);
    Acad::ErrorStatus setDimtxt(double);
    AcCmColor dimclrd() const;
    AcCmColor dimclrt() const;
    AcDbObjectId dimtxsty() const;
    double dimgap() const;
    double dimscale() const;
    double dimtxt() const;

protected:
    virtual Acad::ErrorStatus subGetGripPoints(AcGePoint3dArray&,AcDbIntArray&,AcDbIntArray&) const;
    virtual void subList() const;
    virtual Acad::ErrorStatus subMoveGripPointsAt(const AcDbIntArray&,const AcGeVector3d&);
};
