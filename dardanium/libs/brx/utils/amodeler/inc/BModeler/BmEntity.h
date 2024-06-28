// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
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
