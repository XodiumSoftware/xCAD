// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbAbstractViewTableRecord.h"

class AcDbAnnotationScale;

/** _ */
class BRX_EXPORT AcDbViewTableRecord: public AcDbAbstractViewTableRecord
{
public:
    typedef AcDbViewTable TableType;

    ACDB_DECLARE_MEMBERS(AcDbViewTableRecord);

    AcDbViewTableRecord();
    virtual ~AcDbViewTableRecord();

    AcDbAnnotationScale* annotationScale() const;
    Acad::ErrorStatus disassociateUcsFromView();
    Acad::ErrorStatus getCategoryName(ACHAR*&) const;
    Acad::ErrorStatus getLayerState(ACHAR*&) const;
    Acad::ErrorStatus getLayout(AcDbObjectId&) const;
    Acad::ErrorStatus getThumbnail(BITMAPINFO*&) const;

    Acad::ErrorStatus setAnnotationScale(const AcDbAnnotationScale*);
    Acad::ErrorStatus setCamera(AcDbObjectId);
    Acad::ErrorStatus setCategoryName(const ACHAR*);
    Acad::ErrorStatus setIsCameraPlottable(bool);
    Acad::ErrorStatus setLayerState(const ACHAR*);
    Acad::ErrorStatus setLayout(AcDbObjectId);
    Acad::ErrorStatus setLiveSection(const AcDbObjectId&);
    Acad::ErrorStatus setParametersFromViewport(AcDbObjectId);
    Acad::ErrorStatus setThumbnail(const BITMAPINFO*);
    Acad::ErrorStatus setViewAssociatedToViewport(bool);
    AcDbObjectId camera() const;
    AcDbObjectId liveSection() const;
    bool isCameraPlottable() const;
    bool isPaperspaceView() const;
    bool isUcsAssociatedToView() const;
    bool isViewAssociatedToViewport() const;
    void setIsPaperspaceView(bool);
};
