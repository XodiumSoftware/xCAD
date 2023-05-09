// Copyright (C) 2006-2009 Menhirs NV. All rights reserved.
#pragma once

#include "BmGlobal.h"

namespace AModeler
{

class ImplEntity;

class BM_IMPORTEXPORT Entity
{
private:
    std::shared_ptr<ImplEntity> m_pBrxImp;

public:
    Entity();
    virtual ~Entity();

    bool isFlagOff(Flag) const;
    bool isFlagOn(Flag) const;
    Flag flags() const;
    void flipFlag(Flag);
    void setFlagOff(Flag);
    void setFlagOn(Flag);
    void setFlags(Flag);
};

}
