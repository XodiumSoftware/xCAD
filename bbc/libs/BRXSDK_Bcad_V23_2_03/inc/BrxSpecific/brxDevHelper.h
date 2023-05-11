// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "Misc/AcArray.h"

class AcRxObject;
namespace Atil { class Image; }

namespace BRX
{
int getOpenObjects(AcArray<AcDbObject*>&);
int getAllObjects(AcArray<AcRxObject*>&);
int getNumOdRefsAdded(AcRxObject&);
int copyToClipboard(bool bCopyBase);
Acad::ErrorStatus writeImageToFile(const Atil::Image& image, const AcString& filename, const AcGeVector2d& resolutionMMPerPixel = AcGeVector2d());
};
