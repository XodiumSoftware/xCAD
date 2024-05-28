// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "brx_importexport.h"
#include "BrxSpecific/BcImage.h"


// This abstract interface must be implemented by custom image sources. The interface will be
// called by the control when it needs an icon.
//
// Note: see BcImageSourceMFC.h for implementation examples.

class BcImageSource
{
public:
    virtual ~BcImageSource() {}
    enum Theme { eDark = 0, eLight = 1 };
    virtual BcImageData getIcon(int preferredSize, Theme theme) = 0;
};

typedef AcSharedPtr<BcImageSource> BcImageSourcePtr;
