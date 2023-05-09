// Copyright (C) Menhirs NV. All rights reserved.
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
