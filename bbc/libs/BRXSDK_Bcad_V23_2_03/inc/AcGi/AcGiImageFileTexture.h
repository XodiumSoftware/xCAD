// Copyright (C) Menhirs NV. All rights reserved.
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