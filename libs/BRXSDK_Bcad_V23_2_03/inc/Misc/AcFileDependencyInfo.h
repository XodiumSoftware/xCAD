// Copyright (C) Menhirs NV. All rights reserved.
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
