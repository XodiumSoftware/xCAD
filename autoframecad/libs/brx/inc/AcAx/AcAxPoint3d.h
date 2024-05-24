// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcGe/AcGePoint3d.h"

#ifdef _WIN32
#pragma warning(disable:4290)
#endif

/** _ */
class BRX_IMPORTEXPORT AcAxPoint3d: public AcGePoint3d
{
public:
    AcAxPoint3d();
    AcAxPoint3d(const AcGePoint3d&);
    AcAxPoint3d(const AcGeVector3d&);
    AcAxPoint3d(const SAFEARRAY*) noexcept(false);
    AcAxPoint3d(const VARIANT&) noexcept(false);
    AcAxPoint3d(const VARIANT*) noexcept(false);
    AcAxPoint3d(double,double,double);

    SAFEARRAY* asSafeArrayPtr() const noexcept(false);
    VARIANT& setVariant(VARIANT&) const noexcept(false);
    VARIANT* asVariantPtr() const noexcept(false);
    VARIANT* setVariant(VARIANT*) const noexcept(false);

    AcAxPoint3d& operator=(const AcGePoint3d&);
    AcAxPoint3d& operator=(const AcGeVector3d&);
    AcAxPoint3d& operator=(const SAFEARRAY*) noexcept(false);
    AcAxPoint3d& operator=(const VARIANT&) noexcept(false);
    AcAxPoint3d& operator=(const VARIANT*) noexcept(false);
};