// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "Misc/MiscGlobal.h"

/** _ */
struct AcGiSentScanLines
{
    enum IsmRequestStatus
    {
        eOk = 0,
        eInvalidInput,
        eInvalidColorDepth,
        eInvalidPixelRequest,
        eInvalidDeliveryMethod,
        eNoValidCompressors,
        eInsufficientMemory
    };

    Adesk::Int16 mHasFailed;
    Adesk::Int16 mIsCancelled;
    Adesk::Int8* mpPixelBuffer;
    Adesk::UInt32 mBytes;
    Adesk::UInt32 mRowBytes;
    IsmRequestStatus mRequestStatus;
    void* mpImageId;
};
