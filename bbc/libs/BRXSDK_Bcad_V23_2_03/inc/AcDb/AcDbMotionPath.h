// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbObject.h"

/** _ */
class BRX_EXPORT AcDbMotionPath: public AcDbObject
{
public:
    ACRX_DECLARE_MEMBERS(AcDbMotionPath);

    AcDbMotionPath();
    virtual ~AcDbMotionPath();

    virtual Acad::ErrorStatus dwgInFields(AcDbDwgFiler*);
    virtual Acad::ErrorStatus dwgOutFields(AcDbDwgFiler*) const;
    virtual Acad::ErrorStatus dxfInFields(AcDbDxfFiler*);
    virtual Acad::ErrorStatus dxfOutFields(AcDbDxfFiler*) const;

    Acad::ErrorStatus setCameraPath(const AcDbObjectId&);
    Acad::ErrorStatus setCornerDecel(bool);
    Acad::ErrorStatus setFrameRate(Adesk::UInt16);
    Acad::ErrorStatus setFrames(Adesk::UInt16);
    Acad::ErrorStatus setTargetPath(const AcDbObjectId&);
    Acad::ErrorStatus setViewTableRecordId(const AcDbObjectId&);
    AcDbObjectId cameraPath() const;
    AcDbObjectId targetPath() const;
    AcDbObjectId viewTableRecordId() const;
    Adesk::UInt32 frameRate() const;
    Adesk::UInt32 frames() const;
    bool cornerDecel() const;

protected:
    virtual Adesk::UInt32 subSetAttributes(AcGiDrawableTraits*);
};
