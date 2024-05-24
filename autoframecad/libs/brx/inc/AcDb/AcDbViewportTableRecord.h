// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbAbstractViewTableRecord.h"

/** _ */
class BRX_EXPORT AcDbViewportTableRecord: public AcDbAbstractViewTableRecord
{
public:
    typedef AcDbViewportTable TableType;

    ACDB_DECLARE_MEMBERS(AcDbViewportTableRecord);

    AcDbViewportTableRecord();
    virtual ~AcDbViewportTableRecord();

    AcGePoint2d gridIncrements() const;
    AcGePoint2d lowerLeftCorner() const;
    AcGePoint2d snapBase() const;
    AcGePoint2d snapIncrements() const;
    AcGePoint2d upperRightCorner() const;
    AcGiDrawable* drawable();
    AcGsView* gsView() const;
    Adesk::Int16 gridMajor() const;
    Adesk::Int16 number() const;
    Adesk::Int16 snapPair() const;
    Adesk::UInt16 circleSides() const;
    bool fastZoomsEnabled() const;
    bool gridEnabled() const;
    bool iconAtOrigin() const;
    bool iconEnabled() const;
    bool isGridAdaptive() const;
    bool isGridBoundToLimits() const;
    bool isGridFollow() const;
    bool isGridSubdivisionRestricted() const;
    bool isUcsSavedWithViewport() const;
    bool isometricSnapEnabled() const;
    bool snapEnabled() const;
    bool ucsFollowMode() const;
    double snapAngle() const;
    Acad::ErrorStatus getCategoryName(ACHAR*&) const;
    void setCircleSides(Adesk::UInt16);
    void setFastZoomsEnabled(bool);
    void setGridAdaptive(bool);
    void setGridBoundToLimits(bool);
    void setGridEnabled(bool);
    void setGridFollow(bool);
    void setGridIncrements(const AcGePoint2d&);
    void setGridMajor(Adesk::Int16);
    void setGridSubdivisionRestricted(bool);
    void setGsView(AcGsView*);
    void setIconAtOrigin(bool);
    void setIconEnabled(bool);
    void setIsometricSnapEnabled(bool);
    void setLowerLeftCorner(const AcGePoint2d&);
    void setSnapAngle(double);
    void setSnapBase(const AcGePoint2d&);
    void setSnapEnabled(bool);
    void setSnapIncrements(const AcGePoint2d&);
    void setSnapPair(Adesk::Int16);
    void setUcsFollowMode(bool);
    void setUcsPerViewport(bool);
    void setUpperRightCorner(const AcGePoint2d&);
    Acad::ErrorStatus setCategoryName(const ACHAR*);

protected:
    virtual Adesk::UInt32 subSetAttributes(AcGiDrawableTraits*);
    virtual Adesk::Boolean subWorldDraw(AcGiWorldDraw*);
};
