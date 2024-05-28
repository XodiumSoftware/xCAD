// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
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
