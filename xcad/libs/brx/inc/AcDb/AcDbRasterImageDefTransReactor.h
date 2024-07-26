// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbObjectReactor.h"
#include "AcDb/AcDbRasterImageDefReactor.h"

/** _ */
class AcDbRasterImageDefTransReactor: public AcDbObjectReactor
{
public:
    ACRX_DECLARE_MEMBERS(AcDbRasterImageDefTransReactor);

    virtual ~AcDbRasterImageDefTransReactor();

    virtual Adesk::Boolean onDeleteImage(const AcDbRasterImageDef*,Atil::Image*,AcDbRasterImageDefReactor::DeleteImageEvent,Adesk::Boolean) = 0;
};
