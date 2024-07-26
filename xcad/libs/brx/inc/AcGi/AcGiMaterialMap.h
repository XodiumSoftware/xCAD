// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcGi/AcGiGlobal.h"
#include "AcRx/AcRxObject.h"

/** _ */
class BRX_IMPORTEXPORT AcGiMaterialMap: public AcRxObject
{
public:
    enum Source
    {
        kScene = 0,
        kFile,
        kProcedural
    };

    ACRX_DECLARE_MEMBERS(AcGiMaterialMap);

    AcGiMaterialMap();
    AcGiMaterialMap(const AcGiMaterialMap&);
    virtual ~AcGiMaterialMap();

    virtual const AcGiMapper& mapper() const;
    virtual const AcGiMaterialTexture* texture() const;
    virtual const ACHAR* sourceFileName () const;
    virtual double blendFactor() const;
    virtual Source source() const;
    virtual void set(const AcGiMaterialMap&);
    virtual void setBlendFactor(double);
    virtual void setMapper(const AcGiMapper&);
    virtual void setSource(Source);
    virtual void setSourceFileName(const ACHAR*);
    virtual void setTexture(const AcGiMaterialTexture*);

    AcGiMaterialMap& operator=(const AcGiMaterialMap&);
    bool operator==(const AcGiMaterialMap&) const;

    static const AcGiMaterialMap kNull;
};
