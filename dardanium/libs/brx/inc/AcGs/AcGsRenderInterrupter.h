// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcGs/AcGsModel.h"

class AcGsView;

/** _ */
class BRX_IMPORTEXPORT AcGsRenderInterrupter
{
public:
    virtual bool interrupt(AcGsView*, AcGsModel::RenderType) = 0;
};
