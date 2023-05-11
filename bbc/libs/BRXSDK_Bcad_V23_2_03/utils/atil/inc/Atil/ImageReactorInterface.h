// Copyright (C) 2017-2018 Menhirs NV. All rights reserved.
#pragma once

#include "Exception.h"


namespace Atil
{;


class ATIL_IMPORTEXPORT ImageReactorInterface
{
public:
    virtual ~ImageReactorInterface() {}
    virtual void onModified(int row, int column) {}
};


}; //namespace Atil
