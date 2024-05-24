// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcCm/AcCmGlobal.h"
#include "AcDb/AcDbGlobal.h"
#include "AcGe/AcGeGlobal.h"
#include "AcGi/AcGiGlobal.h"
#include "AcGi/AcGiParameter.h"

class AcGiFaceDataImp;

/** _ */
class BRX_IMPORTEXPORT AcGiFaceData: public AcGiParameter
{
public:
    ACRX_DECLARE_MEMBERS_READWRITE(AcGiFaceData, AcGiFaceDataImp);

    AcGiFaceData();
    ~AcGiFaceData();

    virtual AcCmEntityColor* trueColors() const;
    virtual AcDbObjectId* layerIds() const;
    virtual AcDbObjectId* materials() const;
    virtual AcGeVector3d* normals() const;
    virtual AcGiMapper* mappers() const;
    virtual Adesk::LongPtr* selectionMarkers() const;
    virtual Adesk::UInt8* visibility() const;
    virtual short* colors() const;
    virtual void setColors(const short*);
    virtual void setLayers(const AcDbObjectId*);
    virtual void setMappers(const AcGiMapper*);
    virtual void setMaterials(const AcDbObjectId*);
    virtual void setNormals(const AcGeVector3d*);
    virtual void setSelectionMarkers(const Adesk::LongPtr*);
    virtual void setTrueColors(const AcCmEntityColor*);
    virtual void setVisibility(const Adesk::UInt8*);

    virtual AcCmTransparency* transparency() const;
    virtual void setTransparency(const AcCmTransparency*);
};
