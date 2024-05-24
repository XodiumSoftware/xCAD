// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
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
    void textValue(AcString& acText) const; //deprecated
    AcString textValue() const;

    void setShowImage(bool);
    bool showImage() const;

private:
    AcRibbonTextBox(AcRibbonItemImp*);
};

