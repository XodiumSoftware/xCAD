// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcPl/AcPlObject.h"

class AcPlPlotInfo;

#define DEFAULT_DIMENSIONAL_WEIGHT 50
#define DEFAULT_MEDIA_BOUNDS_WEIGHT 100
#define DEFAULT_MEDIA_GROUP_WEIGHT 50
#define DEFAULT_PRINTABLE_BOUNDS_WEIGHT 10
#define DEFAULT_SHEET_DIMENSIONAL_WEIGHT 10
#define DEFAULT_SHEET_MEDIA_GROUP_WEIGHT 10
#define DEFAULT_THRESHOLD 500

/** _ */
class AcPlPlotInfoValidator: public AcPlObject
{
public:
    enum eCustomSizeResult
    {
        ePossible = 0,
        eMustCreatePC3 = 1,
        eRotationRequired = 2,
        ePC3DirReadOnly = 4,
        ePMPDirReadOnly = 8,
        ePMPDirMissing = 16,
        eUnknownErrPMPDir = 32,
        ePC3FileReadOnly = 64,
        eSizeTooBig = 128,
        eException = 256,
        eUnknownErrPC3File = 512,
        eUnknownErrPMPFile = 1024,
        ePMPFileReadOnly = 2048,
        eWidthAndHeightMustBePositive = 4096,
        eDeviceLoadFailed = 8192
    };

    enum MatchingPolicy
    {
        kMatchDisabled = 1,
        kMatchEnabled,
        kMatchEnabledCustom,
        kMatchEnabledTmpCustom
    };

protected:
    MatchingPolicy m_matchingPolicy;
    unsigned int m_dimensionalWeight;
    unsigned int m_matchingThreshold;
    unsigned int m_mediaBoundsWeight;
    unsigned int m_mediaGroupWeight;
    unsigned int m_printableBoundsWeight;
    unsigned int m_sheetDimensionalWeight;
    unsigned int m_sheetMediaGroupWeight;

public:
    ACRX_DECLARE_MEMBERS(AcPlPlotInfoValidator);

    AcPlPlotInfoValidator();
    virtual ~AcPlPlotInfoValidator();

    virtual Acad::ErrorStatus validate(AcPlPlotInfo&);
    virtual unsigned long isCustomPossible(AcPlPlotInfo&) const;

    MatchingPolicy matchingPolicy() const;
    unsigned int dimensionalWeight() const;
    unsigned int mediaBoundsWeight() const;
    unsigned int mediaGroupWeight() const;
    unsigned int mediaMatchingThreshold() const;
    unsigned int printableBoundsWeight() const;
    unsigned int sheetDimensionalWeight() const;
    unsigned int sheetMediaGroupWeight() const;
    void setDimensionalWeight(unsigned int = DEFAULT_DIMENSIONAL_WEIGHT);
    void setMediaBoundsWeight(unsigned int = DEFAULT_MEDIA_BOUNDS_WEIGHT);
    void setMediaGroupWeight(unsigned int = DEFAULT_MEDIA_GROUP_WEIGHT);
    void setMediaMatchingPolicy(MatchingPolicy);
    void setMediaMatchingThreshold(unsigned int = DEFAULT_THRESHOLD);
    void setPrintableBoundsWeight(unsigned int = DEFAULT_PRINTABLE_BOUNDS_WEIGHT);
    void setSheetDimensionalWeight(unsigned int = DEFAULT_SHEET_DIMENSIONAL_WEIGHT);
    void setSheetMediaGroupWeight(unsigned int = DEFAULT_SHEET_MEDIA_GROUP_WEIGHT);
};
