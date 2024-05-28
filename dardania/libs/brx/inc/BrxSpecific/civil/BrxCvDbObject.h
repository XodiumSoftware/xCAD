// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

// BRX API for BricsCAD Civil object functionality + interfaces

/** Common base class for civil entity classes */
class BRX_EXPORT BrxCvDbObject : public AcDbObject
{
public:
    ACDB_DECLARE_MEMBERS(BrxCvDbObject);

    // get/set the name of the civil object
    const ACHAR* name() const;
    bool         setName(const ACHAR* szName);

    // get/set the description of the civil object
    const ACHAR* description() const;
    bool         setDescription(const ACHAR* szDescription);
};
