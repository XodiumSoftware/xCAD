// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

// BRX API for BricsCAD Civil object functionality + interfaces

/** Common base class for civil sub-object classes */
class BRX_EXPORT BrxCvDbSubObject : public AcRxObject
{
public:
    ACRX_DECLARE_MEMBERS(BrxCvDbSubObject);

    // get/set the name of the BrxCvDbSubObject derived entity
    const ACHAR* name() const;
    bool         setName(const ACHAR* szName);

    // get/set the description of the BrxCvDbSubObject derived entity
    const ACHAR* description() const;
    bool         setDescription(const ACHAR* szDescription);
};
