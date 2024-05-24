// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcRx/AcRxObject.h"

//BRX START
class OdGiShadowParameters;
//BRX END

/** _ */
class BRX_IMPORTEXPORT AcGiShadowParameters: public AcRxObject
{
private:
    //BRX START
    OdGiShadowParameters* m_pBrxImp;
    //BRX END
public:
    enum ShadowType
    {
        kShadowsRayTraced = 0,
        kShadowMaps
    };

    ACRX_DECLARE_MEMBERS(AcGiShadowParameters);

    AcGiShadowParameters();
    virtual ~AcGiShadowParameters();

    virtual Adesk::UInt16 shadowMapSize() const;
    virtual Adesk::UInt8 shadowMapSoftness() const;
    virtual bool setShadowMapSize(Adesk::UInt16);
    virtual bool setShadowMapSoftness(Adesk::UInt8);
    virtual bool shadowsOn() const;
    virtual ShadowType shadowType() const;
    virtual void setShadowsOn(bool);
    virtual void setShadowType(ShadowType);

    bool operator==(const AcGiShadowParameters&) const;
};