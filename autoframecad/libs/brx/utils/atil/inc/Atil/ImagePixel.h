// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "Atil/Defs.h"
#include "Atil/DataModelAttributes.h"


namespace Atil
{;


struct ATIL_IMPORTEXPORT ImagePixel
{
    union
    {
        Data8 data1;
        Data8 data8;
        Data16 data16;
        Data32 data32;
        Data64 data64;
        Data128 data128;
        Data8 bitonal;
        Data8 gray;
        Data8 index;
        Data32 rgba;
        float gray32f;
    } value;
    DataModelAttributes::PixelType type;

    ImagePixel(DataModelAttributes::PixelType type = DataModelAttributes::kData1);

    bool operator==(const ImagePixel& rh) const;
    bool operator!=(const ImagePixel& rh) const;

    const ImagePixel& setToZero();
};


} //namespace Atil
