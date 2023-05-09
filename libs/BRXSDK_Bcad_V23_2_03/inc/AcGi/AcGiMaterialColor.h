// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcCm/AcCmGlobal.h"
#include "AcRx/AcRxObject.h"

/** _ */
class BRX_IMPORTEXPORT AcGiMaterialColor: public AcRxObject
{
public:
    enum Method
    {
        kInherit = 0,
        kOverride
    };

    ACRX_DECLARE_MEMBERS(AcGiMaterialColor);

    AcGiMaterialColor();
    AcGiMaterialColor(const AcGiMaterialColor&);
    virtual ~AcGiMaterialColor();

    virtual const AcCmEntityColor& color() const;
    virtual double factor() const;
    virtual Method method() const;
    virtual void set(const AcGiMaterialColor&);
    virtual void setColor(const AcCmEntityColor&);
    virtual void setFactor(double);
    virtual void setMethod(Method);

    AcGiMaterialColor& operator=(const AcGiMaterialColor&);
    bool operator==(const AcGiMaterialColor&) const;

    static const AcGiMaterialColor kNull;
};
