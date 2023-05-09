// Copyright (C) 2010-2011 Menhirs NV. All rights reserved.
#pragma once

#include "AcRibbonBase.h"
#include "AcRibbonItem.h"

class AcRibbonItemImp;

class BRX_EXPORT AcRibbonSeparator : public AcRibbonItem
{
    friend class AcRibbonInternal;

public:
    AcRibbonSeparator();
    virtual ~AcRibbonSeparator();

    void setSeparatorStyle(AcRibbonUtils::RibbonSeparatorStyle style);
    AcRibbonUtils::RibbonSeparatorStyle separatorStyle() const;

private:
    AcRibbonSeparator(AcRibbonItemImp*);
};