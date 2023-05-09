// Copyright (C) 2010-2011 Menhirs NV. All rights reserved.
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
    void title(AcString& acTitle) const;

    void setName(const ACHAR* acName);
    void name(AcString& acName) const;

    void setId(const ACHAR* acId);
    void id(AcString& acId) const;

    AcRibbonUtils::AcResult addItem(AcRibbonItem*);
    AcRibbonUtils::AcResult removeItem(AcRibbonItem*);

    AcRibbonUtils::AcResult items(AcItemCollection&);

    AcRibbonItem* findItem(const ACHAR* id, bool searchSubItems);

private:
    AcRibbonPanelSource(AcRibbonPanelSourceImp*);

private:
    AcRibbonPanelSourceImp* m_pBrxImp;
};

