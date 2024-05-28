// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

// utilities related to DST and XML file handling + conversions

#include "Misc/MiscGlobal.h"

namespace BRX
{

BRX_IMPORTEXPORT Acad::ErrorStatus convertDst2Xml(const ACHAR* dstFile, const ACHAR* xmlFile);
BRX_IMPORTEXPORT Acad::ErrorStatus convertXml2Dst(const ACHAR* xmlFile, const ACHAR* dstFile);

};
