// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "Misc/AcArray.h"

typedef struct AcCell
{
  int mnRow;
  int mnColumn;

} AcCell;

typedef struct AcCellRange
{
  int mnTopRow;
  int mnLeftColumn;
  int mnBottomRow;
  int mnRightColumn;
  bool operator==(const AcCellRange&) const;
} AcCellRange;

typedef AcArray<AcCell> AcCellArray;
typedef AcArray<AcCellRange> AcCellRangeArray;
