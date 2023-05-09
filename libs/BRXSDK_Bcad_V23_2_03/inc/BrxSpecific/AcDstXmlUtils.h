// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

// utilities related to DST and XML file handling + conversions

#include "Misc/MiscGlobal.h"

namespace BRX
{

BRX_IMPORTEXPORT Acad::ErrorStatus convertDst2Xml(const ACHAR* dstFile, const ACHAR* xmlFile);
BRX_IMPORTEXPORT Acad::ErrorStatus convertXml2Dst(const ACHAR* xmlFile, const ACHAR* dstFile);

};
