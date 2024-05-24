// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "Misc/MiscGlobal.h"

/** _ */
class AcFileDependencyInfo
{
public:
    bool mAffectsGraphics;
    bool mIsModified;
    const ACHAR* mpFeature;
    const ACHAR* mpFileName;
    const ACHAR* mpFingerprintGuid;
    const ACHAR* mpFoundPath;
    const ACHAR* mpFullFileName;
    const ACHAR* mpVersionGuid;
    Adesk::Int32 mFileSize;
    Adesk::Int32 mIndex;
    Adesk::Int32 mReferenceCount;
    Adesk::Int32 mTimeStamp;
};
