// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcGe/AcGeMatrix3d.h"

#ifdef _WIN32
#pragma warning(disable:4290)
#endif

/** _ */
class BRX_IMPORTEXPORT AcAxMatrix3d: public AcGeMatrix3d
{
public:
    AcAxMatrix3d();
    AcAxMatrix3d(const SAFEARRAY*) noexcept(false);
    AcAxMatrix3d(const VARIANT&) noexcept(false);
    AcAxMatrix3d(const VARIANT*) noexcept(false);

    AcAxMatrix3d& operator=(const SAFEARRAY*) noexcept(false);
    AcAxMatrix3d& operator=(const VARIANT&) noexcept(false);
    AcAxMatrix3d& operator=(const VARIANT*) noexcept(false);
};