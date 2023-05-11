// Copyright (C) 2017-2018 Menhirs NV. All rights reserved.
#pragma once

#include "Atil/Defs.h"


namespace Atil
{;


class RowProviderInterface;


class ATIL_IMPORTEXPORT ColorModelInterface
{
public:
    virtual ~ColorModelInterface() {}

    virtual bool canConvertFrom(const ColorModelInterface* cm) const = 0;
    virtual bool canConvertTo(const ColorModelInterface* cm) const = 0;
    virtual RowProviderInterface* getModelConversionFrom(const ColorModelInterface* cm, RowProviderInterface* rp) const = 0;
    virtual RowProviderInterface* getModelConversionTo(const ColorModelInterface* cm, RowProviderInterface* rp) const = 0;
};


} //namespace Atil
