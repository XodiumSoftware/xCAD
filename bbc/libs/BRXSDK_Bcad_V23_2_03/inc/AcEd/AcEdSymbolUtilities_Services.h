// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "Misc/MiscGlobal.h"

/** _ */
namespace AcEdSymbolUtilities
{

/** _ */
class Services
{
public:
    virtual Acad::PromptStatus getCompatibleSymbolString(ACHAR*&,const ACHAR*,AcDbDatabase*) const = 0;
    virtual Acad::PromptStatus getSymbolString(ACHAR*&,const ACHAR*,bool,bool) const = 0;
};

const Services* servicesPtr();

}

namespace AcEdSymUtil = AcEdSymbolUtilities;
typedef AcEdSymbolUtilities::Services AcEdSymUtilServices;

const AcEdSymUtilServices* acedSymUtil();
