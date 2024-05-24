// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "Misc/MiscGlobal.h"
#include "AcDb/AcDbGlobal.h"

class AcDbDatabase;


class BRX_EXPORT AcDbWipeoutVariables: public AcDbObject
{
public:

    enum FrameSettings : Adesk::Int16  // bit flags
    {
        kNothing     = 0x00,  // no frame at all
        kShowAndPlot = 0x01,  // display + plot
        kPlotOnly    = 0x02,  // only plot, no show
        kShowOnly    = 0x04,  // only show, no plot
    };

    ACRX_DECLARE_MEMBERS(AcDbWipeoutVariables);

    static AcDbWipeoutVariables* openWipeoutVariables(AcDb::OpenMode, AcDbDatabase*);

    static FrameSettings convertFrameSysvarToSetting(Adesk::Int16);
    static Adesk::Int16  convertFrameSettingToSysvar(FrameSettings);

    FrameSettings drawFrame() const;
    bool          setDrawFrame(FrameSettings);
};
