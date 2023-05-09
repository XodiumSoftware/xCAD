// Copyright (C) Menhirs NV. All rights reserved.
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
