// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

class AcGePoint3d;

/** _ */
class BRX_IMPORTEXPORT AcGs2DViewLimitManager
{
public:
    virtual ~AcGs2DViewLimitManager() {}

    virtual bool testView(const AcGePoint3d&,double) = 0;
};
