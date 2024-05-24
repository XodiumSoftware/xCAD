// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#ifdef _WIN32

#ifndef AC_DO_NO_IMPORT
#import "msxml6.dll" named_guids rename_namespace("MSXML") rename("offset", "MSXMLoffset")
#else
#include "msxml6.tlh"
#endif

__declspec(selectany) extern const GUID CLSID_DOMDocumentAcad = MSXML::CLSID_DOMDocument60;

#endif // _WIN32
