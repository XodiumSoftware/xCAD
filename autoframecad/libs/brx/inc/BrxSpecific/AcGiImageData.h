// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcGi/AcGiImage.h"
#include "AcGi/AcGiPixel.h"
#include <memory>
#include <vector>


// BRX only
// This is a reference counted container implementation for image data. The container is designed
// to be efficiently copied for use in passing images as value arguments or function return values.

class AcGiImageBGRA32Data : public AcGiImageBGRA32
{
public:
    typedef std::shared_ptr< std::vector<AcGiPixelBGRA32> > AcGiImageBGRA32PixelsPtr;
    inline AcGiImageBGRA32Data(Adesk::UInt32 width, Adesk::UInt32 height, AcGiImageBGRA32PixelsPtr pixels)
        : m_pixelBuffer(pixels)
    {
        m_imageData.setImage(width, height, (width * height) > 0 ? &*pixels->begin() : nullptr);
    }
private:
    AcGiImageBGRA32PixelsPtr m_pixelBuffer;
    AcGiImageBGRA32 m_imageData;
};

typedef std::shared_ptr<AcGiImageBGRA32Data> AcGiImageBGRA32DataPtr;
