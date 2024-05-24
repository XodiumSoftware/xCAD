// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "OPMStructs.h"

// In ax_bricscaddb.h CALPOLESTR is used in class members of IOPMPropertyExpander
// Client code will use OPMOLESTR
// Both are same structure definition content, nevertheless another type for the
// compiler
// Classes derived from IOPMPropertyExpander would not compile
// Include COMWrapperBegin.h before including ax_bricscaddb.h and afterwards include
// COMWrapperEnd.h, to undefine CALPOLESTR and CADWORD
#define CALPOLESTR OPMLPOLESTR
#define CADWORD OPMDWORD

