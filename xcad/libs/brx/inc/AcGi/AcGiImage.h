// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

class AcGiPixelBGRA32;

/** _ */
class AcGiImageBGRA32
{
public:
    AcGiImageBGRA32() : m_width(0) , m_height(0) , m_data(NULL) {}
    AcGiImageBGRA32(Adesk::UInt32 width, Adesk::UInt32 height, AcGiPixelBGRA32* data) : m_width(width), m_height(height), m_data(data) {}

    Adesk::UInt32 height() const { return m_height; }
    Adesk::UInt32 width() const { return m_width; }
    AcGiPixelBGRA32* image() const { return m_data; }
    void setImage(Adesk::UInt32 width, Adesk::UInt32 height, AcGiPixelBGRA32* data) { m_width = width, m_height = height, m_data = data; }

private:
    AcGiPixelBGRA32* m_data;
    Adesk::UInt32 m_width;
    Adesk::UInt32 m_height;
};
