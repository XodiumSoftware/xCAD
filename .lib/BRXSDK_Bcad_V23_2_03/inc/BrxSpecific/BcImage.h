#pragma once

#include "brx_importexport.h"

// Utility classes for encapsulating AcGiImageBGRA32 image data and protecting access so that it
// can be safely and efficiently passed (or returned) by value.

class AcGiPixelBGRA32;
class BcLockedImage;

class BcImageData : protected AcGiImageBGRA32
{
    BcLockedImage* m_pDataLock;
public:
    BcImageData(BcImageData&& rhs);
    BcImageData(BcLockedImage* pDataLock);
    virtual ~BcImageData();
    BcImageData& operator ==(BcImageData&& rhs);
    AcGiPixelBGRA32* image() const { return AcGiImageBGRA32::image(); }
    Adesk::UInt32 width() const { return AcGiImageBGRA32::width(); }
    Adesk::UInt32 height() const { return AcGiImageBGRA32::height(); }
};

class BcLockedImage
{
public:
    virtual ~BcLockedImage() {}
    virtual AcGiPixelBGRA32* lock(Adesk::UInt32& width, Adesk::UInt32& height) = 0; //gain access to the raw pixels
    virtual void unlock() = 0; //image pixel data will be no longer safely accessible after this call
};

inline BcImageData::BcImageData(BcImageData&& rhs) : m_pDataLock(rhs.m_pDataLock)
{
    rhs.m_pDataLock = nullptr;
    setImage(rhs.width(), rhs.height(), rhs.image());
    rhs.setImage(0, 0, nullptr);
}

inline BcImageData::BcImageData(BcLockedImage* pDataLock) : m_pDataLock(pDataLock)
{
    if (m_pDataLock)
    {
        Adesk::UInt32 width = 0;
        Adesk::UInt32 height = 0;
        AcGiPixelBGRA32* data = m_pDataLock->lock(width, height);
        setImage(width, height, data);
    }
}

inline BcImageData::~BcImageData()
{
    if (m_pDataLock)
        m_pDataLock->unlock();
}

inline BcImageData& BcImageData::operator ==(BcImageData&& rhs)
{
    m_pDataLock = rhs.m_pDataLock;
    rhs.m_pDataLock = nullptr;
    setImage(rhs.width(), rhs.height(), rhs.image());
    rhs.setImage(0, 0, nullptr);
    return *this;
}
