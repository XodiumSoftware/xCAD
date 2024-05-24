// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcRx/AcRxObject.h"

//BRX START
class OdGiLightAttenuation;
//BRX END

/** _ */
class BRX_IMPORTEXPORT AcGiLightAttenuation: public AcRxObject
{
private:
    //BRX START
    OdGiLightAttenuation* m_pBrxImp;
    //BRX END
public:
    enum AttenuationType
    {
        kNone = 0,
        kInverseLinear,
        kInverseSquare
    };

    ACRX_DECLARE_MEMBERS(AcGiLightAttenuation);

    AcGiLightAttenuation();
    virtual ~AcGiLightAttenuation();

    virtual AttenuationType attenuationType() const;
    virtual bool useLimits() const;
    virtual double endLimit() const;
    virtual double startLimit() const;
    virtual void setAttenuationType(AttenuationType);
    virtual void setLimits(double,double);
    virtual void setUseLimits(bool);

    bool operator==(const AcGiLightAttenuation&) const;
};
