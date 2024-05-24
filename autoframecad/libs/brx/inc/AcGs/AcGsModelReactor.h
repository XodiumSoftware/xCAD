// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcGs/AcGsView.h"

class BRX_IMPORTEXPORT AcGsModelReactor
{
  public:
    AcGsModelReactor() {}
    virtual ~AcGsModelReactor() {}

  public:
    virtual bool onAdded(AcGsModel*, AcGiDrawable*, AcGiDrawable*) { return false; };
    virtual bool onAdded(AcGsModel*, AcGiDrawable*, Adesk::IntDbId) { return false; };
    virtual bool onModified(AcGsModel*, AcGiDrawable*, AcGiDrawable*) { return false; };
    virtual bool onModified(AcGsModel*, AcGiDrawable*, Adesk::IntDbId) { return false; };
    virtual bool onErased(AcGsModel*, AcGiDrawable*, AcGiDrawable*) { return false; };
    virtual bool onErased(AcGsModel*, AcGiDrawable*, Adesk::IntDbId) { return false; };
    virtual bool onSceneGraphRootAdded(AcGsModel*, AcGiDrawable*) { return false; };
    virtual bool onSceneGraphRootErased(AcGsModel*, AcGiDrawable*) { return false; };
};
