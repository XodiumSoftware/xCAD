// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbGlobal.h"

class BrxUnderlayLayerImp;

class BRX_IMPORTEXPORT AcUnderlayLayer
{
public:
    AcUnderlayLayer();
    AcUnderlayLayer(AcUnderlayLayer const&);
    ~AcUnderlayLayer();

    friend bool operator == (AcUnderlayLayer const&, AcUnderlayLayer const&);
    AcUnderlayLayer const& operator= (AcUnderlayLayer const&);

    typedef enum
    {
        kOff = 0,
        kOn = 1
    } State;

    Acad::ErrorStatus setName(const AcString&);
    Acad::ErrorStatus setState(State);

    AcString name() const;
    State state() const;

private:
    BrxUnderlayLayerImp* m_pImpl;
};
