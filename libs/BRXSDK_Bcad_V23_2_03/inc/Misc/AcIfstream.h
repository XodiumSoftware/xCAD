// Copyright (C) Menhirs NV. All rights reserved.
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