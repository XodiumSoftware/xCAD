// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcRibbonBase.h"

class AcRibbonPanelSourceImp;
class AcRibbonItem;

typedef AcArray <AcRibbonItem*> AcItemCollection;

class BRX_EXPORT AcRibbonPanelSource : public AcRibbonBase
{
    friend class AcRibbonInternal;

public:
    AcRibbonPanelSource();
    virtual ~AcRibbonPanelSource();

    void setTitle(const ACHAR* acTitle);
    void title(AcString& acTitle) const; //deprecated
    AcString title() const;

    void setName(const ACHAR* acName);
    void name(AcString& acName) const; //deprecated
    AcString name() const;

    void setId(const ACHAR* acId);
    void id(AcString& acId) const; //deprecated
    AcString id() const;

    AcRibbonUtils::AcResult addItem(AcRibbonItem*);
    AcRibbonUtils::AcResult removeItem(AcRibbonItem*);

    AcRibbonUtils::AcResult items(AcItemCollection&);

    AcRibbonItem* findItem(const ACHAR* id, bool searchSubItems);

private:
    AcRibbonPanelSource(AcRibbonPanelSourceImp*);

private:
    AcRibbonPanelSourceImp* m_pBrxImp;
};

