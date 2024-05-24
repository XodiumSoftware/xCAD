// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcPl/AcPlGlobal.h"
#include "AcPl/AcPlObject.h"

/** _ */
class AcPlPlotConfigInfo: public AcPlObject
{
public:
    ACRX_DECLARE_MEMBERS(AcPlPlotConfigInfo);

    AcPlPlotConfigInfo();
    AcPlPlotConfigInfo(const AcPlPlotConfigInfo&);
    AcPlPlotConfigInfo(const ACHAR*,const ACHAR*,DeviceType);
    virtual ~AcPlPlotConfigInfo();

    Acad::ErrorStatus copyFrom(const AcRxObject*);
    const ACHAR* deviceName() const;
    const ACHAR* fullPath() const;
    DeviceType deviceType() const;
    void setDeviceName(const ACHAR*);
    void setDeviceType(DeviceType);
    void setFullPath(const ACHAR*);

    const AcPlPlotConfigInfo& operator=(const AcPlPlotConfigInfo&);
};
