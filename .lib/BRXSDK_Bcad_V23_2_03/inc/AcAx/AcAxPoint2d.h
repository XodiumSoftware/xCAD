// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcGe/AcGePoint2d.h"

#ifdef _WIN32
#pragma warning(disable:4290)
#endif

/** _ */
class BRX_IMPORTEXPORT AcAxPoint2d: public AcGePoint2d
{
public:
    AcAxPoint2d();
    AcAxPoint2d(const AcGePoint2d&);
    AcAxPoint2d(const AcGeVector2d&);
    AcAxPoint2d(const SAFEARRAY*) noexcept(false);
    AcAxPoint2d(const VARIANT&) noexcept(false);
    AcAxPoint2d(const VARIANT*) noexcept(false);
    AcAxPoint2d(double,double);

    SAFEARRAY* asSafeArrayPtr() const noexcept(false);
    VARIANT& setVariant(VARIANT&) const noexcept(false);
    VARIANT* asVariantPtr() const noexcept(false);
    VARIANT* setVariant(VARIANT*) const noexcept(false);

    AcAxPoint2d& operator=(const AcGePoint2d&);
    AcAxPoint2d& operator=(const AcGeVector2d&);
    AcAxPoint2d& operator=(const SAFEARRAY*) noexcept(false);
    AcAxPoint2d& operator=(const VARIANT&) noexcept(false);
    AcAxPoint2d& operator=(const VARIANT*) noexcept(false);
};