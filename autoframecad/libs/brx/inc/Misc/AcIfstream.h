// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "Misc/MiscGlobal.h"
#include <fstream>

/** _ */
class BRX_IMPORTEXPORT AcIfstream: public std::wifstream
{
public:
    class AcIfstream();
    class AcIfstream(const ACHAR*);

    void open(const ACHAR*);
    void open(const ACHAR*,ios_base::openmode);
};