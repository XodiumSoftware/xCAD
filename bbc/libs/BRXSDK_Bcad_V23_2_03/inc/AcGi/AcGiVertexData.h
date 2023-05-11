// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcCm/AcCmGlobal.h"
#include "AcGe/AcGeGlobal.h"
#include "AcGi/AcGiGlobal.h"
#include "AcGi/AcGiParameter.h"

class AcGiVertexDataImp;

/** _ */
class BRX_IMPORTEXPORT AcGiVertexData: public AcGiParameter
{
public:
    enum MapChannel
    {
        kAllChannels = 0
    };

public:
    ACRX_DECLARE_MEMBERS_READWRITE(AcGiVertexData, AcGiVertexDataImp);

    AcGiVertexData();
    ~AcGiVertexData();

    virtual AcCmEntityColor* trueColors() const;
    virtual AcGeVector3d* normals() const;
    virtual AcGiOrientationType orientationFlag() const;
    virtual AcGePoint3d* mappingCoords(MapChannel) const;
    virtual void setNormals(const AcGeVector3d*);
    virtual void setOrientationFlag(const AcGiOrientationType);
    virtual void setTrueColors(const AcCmEntityColor*);
    virtual void setMappingCoords(MapChannel, const AcGePoint3d*);
};
