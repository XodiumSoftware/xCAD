// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "MFC/CAdUi/CAdUiVolumeDescriptor.h"

/** _ */
class CAdUiVFATVolumeDescriptor: public CAdUiVolumeDescriptor
{
public:
    BOOL ValidateFilename(const CString*,const BOOL = FALSE) const;
    BOOL ValidateSegment(const CString*,const BOOL = FALSE) const;
    CAdUiVFATVolumeDescriptor(const CString&);
    ~CAdUiVFATVolumeDescriptor() {}
};
