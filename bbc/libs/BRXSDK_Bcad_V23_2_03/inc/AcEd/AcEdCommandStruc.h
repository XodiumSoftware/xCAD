// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcEd/AcEdGlobal.h"

/** _ */
struct AcEdCommandStruc
{
    AcEdCommand* cmd;
    AcRxFunctionPtr fcnAddr;
    HINSTANCE hResHandle;
    long flags;
    void* app;
};
