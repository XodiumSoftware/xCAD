// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

// BRX API for BricsCAD Civil object functionality + interfaces

/** Civil Db Curve base class */
class BRX_EXPORT BrxCvDbCurve : public AcDbCurve
{
public:
    ACDB_DECLARE_MEMBERS(BrxCvDbCurve);

    // get/set the name of the BrxCvDbCurve derived entity
    const ACHAR* name() const;
    bool         setName(const ACHAR* szName);

    // get/set the description of the BrxCvDbCurve derived entity
    const ACHAR* description() const;
    bool         setDescription(const ACHAR* szDescription);
};
