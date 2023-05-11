#pragma once

#include "brx_importexport.h"
#include "BrxSpecific/BcImageSource.h"


// Helper classes followed by several simple BcImageSource implementations that can be used for
// common cases, and as examples for implementing more complex image sources.

class BRX_IMPORTEXPORT WinBitmapImageHelper
{
public:
    // Generate raw AcGiPixelBGRA32 data from a bitmap. If height or width are non-zero on input,
    // the generated data will be stretched to the specified size (possibly changing aspect ratio).
    // If both dimensions are set to zero on input, the original bitmap dimensions will be retained.
    // If one dimension is set to zero, the bitmap will be stretched, but its aspect ratio will be
    // retained. In all cases, the returned width and height values will be set to the actual size
    // of the returned image.
    static AcGiPixelBGRA32* CreatePixelData(const ACHAR* filePath, Adesk::UInt32& height, Adesk::UInt32& width);
    static AcGiPixelBGRA32* CreatePixelData(HBITMAP bmp, Adesk::UInt32& height, Adesk::UInt32& width);
    static AcGiPixelBGRA32* CreatePixelData(HICON icon, Adesk::UInt32& height, Adesk::UInt32& width);

    static void FreePixelData(AcGiPixelBGRA32*& pixelData);
};

// image file at original size
class BcImageFile : public BcLockedImage, protected WinBitmapImageHelper
{
    BcImageFile(const ACHAR* filePath) : m_filePath(filePath) {}
public:
    static BcImageFile* create(const ACHAR* filePath) { return new BcImageFile(filePath); }
    virtual AcGiPixelBGRA32* lock(Adesk::UInt32& width, Adesk::UInt32& height) override
    {
        if (!m_pixelData)
            m_pixelData = CreatePixelData(m_filePath, m_height, m_width);
        if (m_pixelData)
        {
            width = m_width;
            height = m_height;
        }
        return m_pixelData;
    }
    virtual void unlock() override
    {
        FreePixelData(m_pixelData);
        m_height = 0;
        m_width = 0;
        delete this;
    }
private:
    AcString m_filePath;
    AcGiPixelBGRA32* m_pixelData = nullptr;
    Adesk::UInt32 m_height = 0;
    Adesk::UInt32 m_width = 0;
};

// image file stretched to specified height
class BcSizedImageFile : public BcLockedImage, protected WinBitmapImageHelper
{
    BcSizedImageFile(const ACHAR* filePath, Adesk::UInt32 size) : m_filePath(filePath), m_size(size) {}
public:
    static BcSizedImageFile* create(const ACHAR* filePath, Adesk::UInt32 size) { return new BcSizedImageFile(filePath, size); }
    virtual AcGiPixelBGRA32* lock(Adesk::UInt32& width, Adesk::UInt32& height) override
    {
        if (!m_pixelData)
        {
            m_height = m_size;
            m_pixelData = CreatePixelData(m_filePath, m_height, m_width);
        }
        if (m_pixelData)
        {
            width = m_width;
            height = m_height;
        }
        return m_pixelData;
    }
    virtual void unlock() override
    {
        FreePixelData(m_pixelData);
        m_height = 0;
        m_width = 0;
        delete this;
    }
private:
    AcString m_filePath;
    Adesk::UInt32 m_size = 0;
    AcGiPixelBGRA32* m_pixelData = nullptr;
    Adesk::UInt32 m_height = 0;
    Adesk::UInt32 m_width = 0;
};

// HBITMAP image data at original size
class BcWinBitmap : public BcLockedImage, protected WinBitmapImageHelper
{
    BcWinBitmap(HBITMAP bmp) : m_bmp(bmp) {}
public:
    static BcWinBitmap* create(HBITMAP bmp) { return new BcWinBitmap(bmp); }
    virtual AcGiPixelBGRA32* lock(Adesk::UInt32& width, Adesk::UInt32& height) override
    {
        if (!m_pixelData)
            m_pixelData = CreatePixelData(m_bmp, m_height, m_width);
        if (m_pixelData)
        {
            width = m_width;
            height = m_height;
        }
        return m_pixelData;
    }
    virtual void unlock() override
    {
        FreePixelData(m_pixelData);
        m_height = 0;
        m_width = 0;
        delete this;
    }
private:
    HBITMAP m_bmp;
    AcGiPixelBGRA32* m_pixelData = nullptr;
    Adesk::UInt32 m_height = 0;
    Adesk::UInt32 m_width = 0;
};

// HBITMAP image data stretched to specified height
class BcSizedWinBitmap : public BcLockedImage, protected WinBitmapImageHelper
{
    BcSizedWinBitmap(HBITMAP bmp, Adesk::UInt32 size) : m_bmp(bmp), m_size(size) {}
public:
    static BcSizedWinBitmap* create(HBITMAP bmp, Adesk::UInt32 size) { return new BcSizedWinBitmap(bmp, size); }
    virtual AcGiPixelBGRA32* lock(Adesk::UInt32& width, Adesk::UInt32& height) override
    {
        if (!m_pixelData)
        {
            m_height = m_size;
            m_pixelData = CreatePixelData(m_bmp, m_height, m_width);
        }
        if (m_pixelData)
        {
            width = m_width;
            height = m_height;
        }
        return m_pixelData;
    }
    virtual void unlock() override
    {
        FreePixelData(m_pixelData);
        delete this;
    }
private:
    HBITMAP m_bmp;
    Adesk::UInt32 m_size = 0;
    AcGiPixelBGRA32* m_pixelData = nullptr;
    Adesk::UInt32 m_height = 0;
    Adesk::UInt32 m_width = 0;
};

// HICON image data stretched to specified height
class BcSizedWinIcon : public BcLockedImage, protected WinBitmapImageHelper
{
    BcSizedWinIcon(HICON icon, Adesk::UInt32 size) : m_icon(icon), m_size(size) {}
public:
    static BcSizedWinIcon* create(HICON icon, Adesk::UInt32 size) { return new BcSizedWinIcon(icon, size); }
    virtual AcGiPixelBGRA32* lock(Adesk::UInt32& width, Adesk::UInt32& height) override
    {
        if (!m_pixelData)
        {
            m_height = m_size;
            m_pixelData = CreatePixelData(m_icon, m_height, m_width);
        }
        if (m_pixelData)
        {
            width = m_width;
            height = m_height;
        }
        return m_pixelData;
    }
    virtual void unlock() override
    {
        FreePixelData(m_pixelData);
        delete this;
    }
private:
    HICON m_icon;
    Adesk::UInt32 m_size = 0;
    AcGiPixelBGRA32* m_pixelData = nullptr;
    Adesk::UInt32 m_height = 0;
    Adesk::UInt32 m_width = 0;
};


//
// Image Sources
//

class BcImageFileSource : public BcImageSource
{
public:
    BcImageFileSource(const ACHAR* filePath) : m_filePath(filePath) {}
    virtual BcImageData getIcon(int /*preferredSize*/, Theme /*theme*/) override
    {
        return BcImageData(BcImageFile::create(m_filePath));
    }
private:
    AcString m_filePath;
};

class BcSizedImageFileSource : public BcImageSource
{
public:
    BcSizedImageFileSource(const ACHAR* filePath) : m_filePath(filePath) {}
    virtual BcImageData getIcon(int preferredSize, Theme /*theme*/) override
    {
        return BcImageData(BcSizedImageFile::create(m_filePath, preferredSize));
    }
private:
    AcString m_filePath;
};

class BcWinBitmapSource : public BcImageSource
{
public:
    BcWinBitmapSource(HBITMAP bmp) : m_bmp(bmp) {}
    virtual BcImageData getIcon(int /*preferredSize*/, Theme /*theme*/) override
    {
        return BcImageData(BcWinBitmap::create(m_bmp));
    }
private:
    HBITMAP m_bmp;
};

class BcSizedWinBitmapSource : public BcImageSource
{
public:
    BcSizedWinBitmapSource(HBITMAP bmp) : m_bmp(bmp) {}
    virtual BcImageData getIcon(int preferredSize, Theme /*theme*/) override
    {
        return BcImageData(BcSizedWinBitmap::create(m_bmp, preferredSize));
    }
private:
    HBITMAP m_bmp;
};

class BcSizedWinIconSource : public BcImageSource
{
public:
    BcSizedWinIconSource(HICON icon) : m_icon(icon) {}
    virtual BcImageData getIcon(int preferredSize, Theme /*theme*/) override
    {
        return BcImageData(BcSizedWinIcon::create(m_icon, preferredSize));
    }
private:
    HICON m_icon;
};

// themed icon provided at requested size
class BcThemedWinIcon : public BcImageSource
{
public:
    BcThemedWinIcon(HICON iconDark, HICON iconLight) : m_iconDark(iconDark), m_iconLight(iconLight) {}
    virtual BcImageData getIcon(int preferredSize, Theme theme) override
    {
        HICON themedIcon = (theme == BcImageSource::eDark) ? m_iconDark : m_iconLight;
        return BcImageData(BcSizedWinIcon::create(themedIcon, preferredSize));
    }
private:
    HICON m_iconDark;
    HICON m_iconLight;
};
