// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

class AcGePoint3d;

/** _ */
class BRX_IMPORTEXPORT AcGs2DViewLimitManager
{
public:
    virtual ~AcGs2DViewLimitManager() {}

    virtual bool testView(const AcGePoint3d&,double) = 0;
};
