// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#ifdef __cplusplus

#include "AcGe/AcGeTol.h"

class AcGeVector3d;

/** _ */
struct AcGeContext
{
    /* BRX START */
    BRX_IMPORTEXPORT
    /* BRX END */
    static AcGeTol gTol;

    static void (*gErrorFunc)();
    static void (*gFreeMem)(void*);
    static void (*gOrthoVector)(const AcGeVector3d&,AcGeVector3d&);
    static void* (*gAllocMem)(size_t);
};

#endif // __cplusplus
