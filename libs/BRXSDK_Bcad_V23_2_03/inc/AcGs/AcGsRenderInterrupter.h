// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcGs/AcGsModel.h"

class AcGsView;

/** _ */
class BRX_IMPORTEXPORT AcGsRenderInterrupter
{
public:
    virtual bool interrupt(AcGsView*, AcGsModel::RenderType) = 0;
};
