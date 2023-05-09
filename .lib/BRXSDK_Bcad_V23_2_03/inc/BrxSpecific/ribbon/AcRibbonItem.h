// Copyright (C) 2010-2011 Menhirs NV. All rights reserved.
#pragma once

#include "AcRibbonBase.h"
#include "AcGi/AcGiImage.h"
#include "BrxSpecific/AcSharedPtr.h"

class AcRibbonItemImp;
class AcGiPixelBGRA32;
class AcRibbonImageSource;

//forward declaration
typedef AcSharedPtr<AcRibbonImageSource> AcRibbonImageSourcePtr;

class BRX_EXPORT AcRibbonItem : public AcRibbonBase
{
    friend class AcRibbonInternal;

public:
    // Utility classes for safely returning custom icon image data by value
    class ImageDataLock
    {
    public:
        virtual ~ImageDataLock() {}
        virtual AcGiPixelBGRA32* lock(Adesk::UInt32& width, Adesk::UInt32& height) = 0;
        virtual void unlock() = 0; //image pixel data will be no longer safely accessible after this call
    };
    class LockedImageData : protected AcGiImageBGRA32
    {
        ImageDataLock* m_pDataLock;
    public:
        LockedImageData(LockedImageData&& rhs) : m_pDataLock(rhs.m_pDataLock)
        {
            rhs.m_pDataLock = nullptr;
            setImage(rhs.width(), rhs.height(), rhs.image());
            rhs.setImage(0, 0, nullptr);
        }
        LockedImageData(ImageDataLock* pDataLock) : m_pDataLock(pDataLock)
        {
            if (m_pDataLock)
            {
                Adesk::UInt32 width = 0;
                Adesk::UInt32 height = 0;
                AcGiPixelBGRA32* data = m_pDataLock->lock(width, height);
                setImage(width, height, data);
            }
        }
        virtual ~LockedImageData() { if (m_pDataLock) m_pDataLock->unlock(); }
        LockedImageData& operator ==(LockedImageData&& rhs)
        {
            m_pDataLock = rhs.m_pDataLock;
            rhs.m_pDataLock = nullptr;
            setImage(rhs.width(), rhs.height(), rhs.image());
            rhs.setImage(0, 0, nullptr);
            return *this;
        }
        AcGiPixelBGRA32* image() const { return AcGiImageBGRA32::image(); }
        Adesk::UInt32 width() const { return AcGiImageBGRA32::width(); }
        Adesk::UInt32 height() const { return AcGiImageBGRA32::height(); }
    };

public:
    AcRibbonItem();
    virtual ~AcRibbonItem();

    AcRibbonUtils::RibbonToolType toolType() const;

    void setButtonStyle(AcRibbonUtils::RibbonButtonStyle);
    AcRibbonUtils::RibbonButtonStyle buttonStyle() const;

    void setText(const ACHAR* acText);
    void text(AcString& acText) const;

    void setId(const ACHAR* id);
    void id(AcString& acName) const;

    void setImagePath(const ACHAR* acImgPath);
    void imagePath(AcString& acImgPath) const;

    void setImageSource(AcRibbonImageSourcePtr acImgSource);
    AcRibbonImageSourcePtr imageSource() const;

    void setToolTip(const ACHAR* acToolTip);
    void toolTip(AcString& acToolTip) const;

    void setWidth(double width);
    double width() const;

    bool isEnabled() const;
    bool enable(bool isEnabled);

    bool isVisible() const;
    bool setVisible(bool isVisible);

    void setName(const ACHAR* acName);
    void name(AcString& acName) const;

protected:
    AcRibbonItem(AcRibbonItemImp*);

protected:
    AcRibbonItemImp* m_pBrxImp;
};


// Abstract interface that must be implemented by custom image sources. This interface will
// be called by the ribbon when it needs an icon for the ribbon item.
class AcRibbonImageSource
{
public:
    virtual ~AcRibbonImageSource() {}
    enum Theme { eDark = 0, eLight = 1 };
    virtual AcRibbonItem::LockedImageData getIcon(bool large, int preferredSize, Theme theme) = 0;
};
