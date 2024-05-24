// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
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
