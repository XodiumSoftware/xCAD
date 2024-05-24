// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcGi/AcGiImageTexture.h"

/** _ */
class AcGiImageFileTexture: public AcGiImageTexture
{
public:
    ACRX_DECLARE_MEMBERS(AcGiImageFileTexture);

    AcGiImageFileTexture();
    AcGiImageFileTexture(const AcGiImageFileTexture&);
    virtual ~AcGiImageFileTexture();

    virtual Acad::ErrorStatus copyFrom(const AcRxObject*);
    virtual bool operator==(const AcGiMaterialTexture&) const;
    virtual const ACHAR* sourceFileName() const;
    virtual void setSourceFileName(const ACHAR*);

    AcGiImageFileTexture& operator=(const AcGiImageFileTexture&);
};