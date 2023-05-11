// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcRx/AcRxBoiler.h"

#define ACDB_DECLARE_MEMBERS(T_CLASS) \
private: \
    friend class BrxFriend; \
public: \
    ACRX_DECLARE_MEMBERS(T_CLASS)

#define MAKE_ACDBOPENOBJECT_FUNCTION(T_CLASS)
