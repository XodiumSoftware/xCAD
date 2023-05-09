// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

/** _ */
struct BRX_IMPORTEXPORT AcGiLineAttrUtils
{
    static AcDb::LineWeight acgiIndexToLineWeight(char);
    static char acgiLineWeightToIndex(AcDb::LineWeight);
};
