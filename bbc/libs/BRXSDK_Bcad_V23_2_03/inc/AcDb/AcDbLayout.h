// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbPlotSettings.h"
#include "AcDb/AcDbExtents.h"
#include "AcDb/AcDbExtents2d.h"

/** _ */
class BRX_EXPORT AcDbLayout: public AcDbPlotSettings
{
public:
    ACDB_DECLARE_MEMBERS(AcDbLayout);

    AcDbLayout();
    virtual ~AcDbLayout();

    virtual Acad::ErrorStatus addToLayoutDict(AcDbDatabase*,AcDbObjectId);
    virtual Acad::ErrorStatus setBlockTableRecordId(AcDbObjectId);
    virtual Acad::ErrorStatus setLayoutName(const ACHAR*);
    virtual void setTabOrder(int);
    virtual void setTabSelected(Adesk::Boolean);

    Acad::ErrorStatus getLayoutName(ACHAR*&) const;
    Acad::ErrorStatus getLayoutName(const ACHAR*&) const;
    Acad::ErrorStatus getThumbnail(BITMAPINFO*&) const;
    Acad::ErrorStatus setThumbnail(const BITMAPINFO*);
    AcDbObjectId getBlockTableRecordId() const;
    AcDbObjectIdArray getViewportArray() const;
    bool getTabSelected() const;
    int getTabOrder() const;

    Acad::ErrorStatus initialize(AcDbObjectId* = NULL);

    bool annoAllVisible() const;
    Acad::ErrorStatus setAnnoAllVisible(bool);

    void getLimits(AcDbExtents2d&) const;
    void getLimits(AcGePoint2d&, AcGePoint2d&) const;

    void getExtents(AcDbExtents& extent) const;
    void getExtents(AcGePoint3d&, AcGePoint3d&) const;
};
