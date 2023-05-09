// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcAp/AcApDocManager.h"
#include "AcAp/AcApDocManagerReactor.h"

#if defined(_DEBUG) && !defined(BRX_BCAD_DEBUG)
#undef _DEBUG
#include <map>
#define _DEBUG
#else
#include <map>
#endif

/** _ */
template<class VALUE> class AcApDataManager: public AcApDocManagerReactor
{
private:
    std::map<AcApDocument*,VALUE> m_map;

public:
    AcApDataManager();
    ~AcApDataManager();

    virtual void documentToBeDestroyed(AcApDocument*);

    VALUE& docData();
    VALUE& docData(AcApDocument*);
};

template<class VALUE>
AcApDataManager<VALUE>::AcApDataManager()
{
    AcApDocManager* pDocMan = acDocManagerPtr();
    if (!pDocMan)
        return;
    pDocMan->addReactor(this);
}

template<class VALUE>
AcApDataManager<VALUE>::~AcApDataManager()
{
    AcApDocManager* pDocMan = acDocManagerPtr();
    if (!pDocMan)
        return;
    pDocMan->removeReactor(this);
}

template<class VALUE>
void AcApDataManager<VALUE>::documentToBeDestroyed(AcApDocument* pDoc)
{
    m_map.erase(pDoc);
}

template<class VALUE>
VALUE& AcApDataManager<VALUE>::docData()
{
    AcApDocManager* pDocMan = acDocManagerPtr();
    return docData(pDocMan->curDocument());
}

template<class VALUE>
VALUE& AcApDataManager<VALUE>::docData(AcApDocument* pDoc)
{
    return m_map[pDoc];
}
