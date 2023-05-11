// Copyright (C) 2010-2011 Menhirs NV. All rights reserved.
#pragma once

#include "AcRibbonBase.h"
#include "AcRibbonItem.h"


class AcRibbonItemImp;

class BRX_EXPORT AcRibbonTextBox : public AcRibbonItem
{
    friend class AcRibbonInternal;

public:
    AcRibbonTextBox();
    virtual ~AcRibbonTextBox();

    void setShowText(bool);
    bool showText() const;

    void setTextValue(const ACHAR* acText);
    void textValue(AcString& acText) const;

    void setShowImage(bool);
    bool showImage() const;

private:
    AcRibbonTextBox(AcRibbonItemImp*);
};

