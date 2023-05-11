// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcCm/AcCmGlobal.h"
#include "AcDb/AcDbGlobal.h"
#include "AcGi/AcGiParameter.h"

class AcGiEdgeDataImp;

/** _ */
class BRX_IMPORTEXPORT AcGiEdgeData: public AcGiParameter
{
public:
    ACRX_DECLARE_MEMBERS_READWRITE(AcGiEdgeData, AcGiEdgeDataImp);

    AcGiEdgeData();
    ~AcGiEdgeData();

    virtual AcCmEntityColor* trueColors() const;
    virtual AcDbObjectId* layerIds() const;
    virtual AcDbObjectId* linetypeIds() const;
    virtual Adesk::LongPtr* selectionMarkers() const;
    virtual Adesk::UInt8* visibility() const;
    virtual short* colors() const;
    virtual void setColors(const short*);
    virtual void setLayers(const AcDbObjectId*);
    virtual void setLineTypes(const AcDbObjectId*);
    virtual void setSelectionMarkers(const Adesk::LongPtr*);
    virtual void setTrueColors(const AcCmEntityColor*);
    virtual void setVisibility(const Adesk::UInt8*);
};
