// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcRx/AcRxObject.h"

/** _ */
class BRX_IMPORTEXPORT AcGiDisplayStyle: public AcRxObject
{
public:
    enum DisplaySettings
    {
        kNone = 0,
        kBackgrounds = 1,
        kLighting = 2,
        kMaterials = 4,
        kTextures = 8
    };
    enum ShadowType
    {
        kShadowsNone = 0,
        kShadowsGroundPlane,
        kShadowsFull,
        kShadowsFullAndGround
    };

    ACRX_DECLARE_MEMBERS(AcGiDisplayStyle);

    AcGiDisplayStyle();
    AcGiDisplayStyle(const AcGiDisplayStyle&);
    virtual ~AcGiDisplayStyle();

    virtual AcGiDisplayStyle& operator=(const AcGiDisplayStyle&);
    virtual ShadowType shadowType() const;
    virtual bool isDisplaySettingsFlagSet(DisplaySettings) const;
    virtual bool operator==(const AcGiDisplayStyle&) const;
    virtual double brightness() const;
    virtual unsigned long displaySettings() const;
    virtual void set(const AcGiDisplayStyle&);
    virtual void setBrightness(double);
    virtual void setDisplaySettings(unsigned long);
    virtual void setDisplaySettingsFlag(DisplaySettings,bool);
    virtual void setShadowType(ShadowType);
};
