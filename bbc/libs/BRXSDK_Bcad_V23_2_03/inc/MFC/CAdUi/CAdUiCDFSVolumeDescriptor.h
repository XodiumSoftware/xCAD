// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "MFC/CAdUi/CAdUiVolumeDescriptor.h"

/** _ */
class CAdUiCDFSVolumeDescriptor: public CAdUiVolumeDescriptor
{
public:
    BOOL ValidateFilename(const CString*,const BOOL = FALSE) const;
    BOOL ValidateSegment(const CString*,const BOOL = FALSE) const;
    CAdUiCDFSVolumeDescriptor(const CString&);
    ~CAdUiCDFSVolumeDescriptor() {}
};
