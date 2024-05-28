// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbRasterImageDef.h"

/** _ */
class BRX_EXPORT AcDbRasterVariables: public AcDbObject
{
public:
    enum FrameSettings
    {
        kImageFrameInvalid = -1,
        kImageFrameOff,
        kImageFrameAbove,
        kImageFrameBelow,
        kImageFrameOnNoPlot
    };

    enum ImageQuality
    {
        kImageQualityInvalid = -1,
        kImageQualityDraft,
        kImageQualityHigh
    };

    ACRX_DECLARE_MEMBERS(AcDbRasterVariables);

    AcDbRasterVariables();
    virtual ~AcDbRasterVariables();

    virtual Acad::ErrorStatus dwgInFields(AcDbDwgFiler*);
    virtual Acad::ErrorStatus dwgOutFields(AcDbDwgFiler*) const;
    virtual Acad::ErrorStatus dxfInFields(AcDbDxfFiler*);
    virtual Acad::ErrorStatus dxfOutFields(AcDbDxfFiler*) const;
    virtual Acad::ErrorStatus setImageFrame(FrameSettings);
    virtual Acad::ErrorStatus setImageQuality(ImageQuality);
    virtual Acad::ErrorStatus setUserScale(AcDbRasterImageDef::Units);
    virtual AcDbRasterImageDef::Units userScale() const;
    virtual FrameSettings imageFrame() const;
    virtual ImageQuality imageQuality() const;

    static AcDbRasterVariables* create();
    static AcDbRasterVariables* openRasterVariables(AcDb::OpenMode,AcDbDatabase* = NULL);
    static ClassVersion classVersion();
};
