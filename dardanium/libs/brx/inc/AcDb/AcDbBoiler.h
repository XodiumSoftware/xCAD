// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcRx/AcRxBoiler.h"

#define ACDB_DECLARE_MEMBERS(T_CLASS) \
private: \
    friend class BrxFriend; \
public: \
    ACRX_DECLARE_MEMBERS(T_CLASS)

#define MAKE_ACDBOPENOBJECT_FUNCTION(T_CLASS)
