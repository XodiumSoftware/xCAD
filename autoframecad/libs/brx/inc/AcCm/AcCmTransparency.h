// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "Misc/MiscGlobal.h"

/** _ */
class BRX_IMPORTEXPORT AcCmTransparency
{
public:
    enum
    {
        kTransparencySolid = -16777214,
        kTransparencyByLayer = 0,
        kTransparencyByBlock,
        kTransparencyClear
    };

    enum transparencyMethod
    {
        kByLayer = 0,
        kByBlock,
        kByAlpha,
        kErrorValue
    };

private:
    union TransparencyUnion
    {
        Adesk::UInt32 allData;
        struct
        {
            Adesk::UInt8 alpha;
            Adesk::UInt8 empty1;
            Adesk::UInt8 empty2;
            Adesk::UInt8 method;
        };
    };

    TransparencyUnion m_data;

public:
    AcCmTransparency();
    AcCmTransparency(Adesk::UInt8);
    AcCmTransparency(double);
    AcCmTransparency(const AcCmTransparency&);
    ~AcCmTransparency();

    Adesk::UInt32 serializeOut() const;
    Adesk::UInt8 alpha() const;
    double alphaPercent() const;
    bool isByAlpha() const;
    bool isByBlock() const;
    bool isByLayer() const;
    bool isClear() const;
    bool isSolid() const;
    void serializeIn(Adesk::UInt32);
    void setAlpha(Adesk::UInt8);
    void setAlphaPercent(double);
    void setMethod(transparencyMethod);

    AcCmTransparency& operator=(const AcCmTransparency&);
    bool operator!=(const AcCmTransparency&) const;
    bool operator==(const AcCmTransparency&) const;
};
