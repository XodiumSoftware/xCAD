// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbSymbolTableRecord.h"

/** _ */
class BRX_EXPORT AcDbLinetypeTableRecord: public AcDbSymbolTableRecord
{
public:
    typedef AcDbLinetypeTable TableType;

    ACDB_DECLARE_MEMBERS(AcDbLinetypeTableRecord);

    AcDbLinetypeTableRecord();
    virtual ~AcDbLinetypeTableRecord();

    AcDbObjectId shapeStyleAt(int) const;
    AcGeVector2d shapeOffsetAt(int) const;
    AcGiDrawable* drawable();
    AcGsNode* gsNode() const;
    Acad::ErrorStatus asciiDescription(ACHAR*&) const;
    Acad::ErrorStatus asciiDescription(const ACHAR*&) const;
    Acad::ErrorStatus comments(ACHAR*&) const;
    Acad::ErrorStatus comments(const ACHAR*&) const;
    Acad::ErrorStatus setAsciiDescription(const ACHAR*);
    Acad::ErrorStatus setComments(const ACHAR*);
    Acad::ErrorStatus setDashLengthAt(int, double);
    Acad::ErrorStatus setNumDashes(int);
    Acad::ErrorStatus setPatternLength(double);
    Acad::ErrorStatus setShapeIsUcsOrientedAt(int, bool);
    Acad::ErrorStatus setShapeIsUprightAt(int, bool);
    Acad::ErrorStatus setShapeNumberAt(int, int);
    Acad::ErrorStatus setShapeOffsetAt(int, const AcGeVector2d&);
    Acad::ErrorStatus setShapeRotationAt(int, double);
    Acad::ErrorStatus setShapeScaleAt(int, double);
    Acad::ErrorStatus setShapeStyleAt(int, AcDbObjectId);
    Acad::ErrorStatus setTextAt(int, const ACHAR*);
    Acad::ErrorStatus textAt(int, ACHAR*&) const;
    Acad::ErrorStatus textAt(int, const ACHAR*&) const;
    bool isScaledToFit() const;
    bool shapeIsUcsOrientedAt(int) const;
    bool shapeIsUprightAt(int) const;
    double dashLengthAt(int) const;
    double patternLength() const;
    double shapeRotationAt(int) const;
    double shapeScaleAt(int) const;
    int numDashes() const;
    int shapeNumberAt(int) const;
    void setGsNode(AcGsNode*);
    void setIsScaledToFit(bool);

protected:
    virtual Adesk::Boolean subWorldDraw(AcGiWorldDraw*);
    virtual Adesk::UInt32 subSetAttributes(AcGiDrawableTraits*);
    virtual void subViewportDraw(AcGiViewportDraw*);
};
