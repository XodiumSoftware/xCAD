// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "Misc/MiscGlobal.h"
#include <fstream>

/** _ */
class BRX_IMPORTEXPORT AcOfstream: public std::wofstream
{
public:
    class AcOfstream();
    class AcOfstream(const ACHAR*);

    void open(const ACHAR*);
    void open(const ACHAR*,ios_base::openmode);
};