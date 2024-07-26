// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcGe/AcGePoint2d.h"
#include "AcPl/AcPlObject.h"

/** _ */
class AcPlPlotConfig: public AcPlObject
{
public:

    enum PlotToFileCapability
    {
        kNoPlotToFile = 0,
        kPlotToFileAllowed,
        kMustPlotToFile
    };

    ACRX_DECLARE_MEMBERS(AcPlPlotConfig);

private:
//BRX START
    friend class AcPlPlotConfigImp;
//BRX END
    AcPlPlotConfig();
public:
    virtual ~AcPlPlotConfig();

    virtual Acad::ErrorStatus copyFrom(const AcRxObject*);
    virtual Acad::ErrorStatus getDefaultFileExtension(const ACHAR*&) const;
    virtual Acad::ErrorStatus setPlotToFile(bool);
    virtual bool isPlotToFile() const;
    virtual bool saveToPC3(const ACHAR*);
    virtual const ACHAR* deviceName() const;
    virtual const ACHAR* fullPath() const;
    virtual PlotToFileCapability plotToFileCapability() const;
    virtual unsigned int maxDeviceDPI() const;
    virtual unsigned long deviceType() const;
    virtual void getCanonicalMediaNameList(AcArray<ACHAR*>&) const;
    virtual void getDescriptionFields(ACHAR*&,ACHAR*&,ACHAR*&,ACHAR*&,ACHAR*&,ACHAR*&) const;
    virtual void getLocalMediaName(const ACHAR*,ACHAR*&) const;
    virtual void getMediaBounds(const ACHAR*,AcGePoint2d&,AcGeBoundBlock2d&) const;
    virtual void refreshMediaNameList();
};
