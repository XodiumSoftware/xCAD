// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcGe/AcGeGlobal.h"
#include "AcGi/AcGiParameter.h"

class AcGiMapperImp;

/** _ */
class BRX_IMPORTEXPORT AcGiMapper: public AcGiParameter
{
public:
    enum AutoTransform
    {
        kInheritAutoTransform = 0,
        kNone = 1,
        kObject = 2,
        kModel = 4
    };

    enum Projection
    {
        kInheritProjection = 0,
        kPlanar,
        kBox,
        kCylinder,
        kSphere
    };

    enum Tiling
    {
        kInheritTiling = 0,
        kTile,
        kCrop,
        kClamp
    };

public:
    ACRX_DECLARE_MEMBERS_READWRITE(AcGiMapper, AcGiMapperImp);

    AcGiMapper();
    AcGiMapper(const AcGiMapper&);
    virtual ~AcGiMapper();

    virtual AutoTransform autoTransform() const;
    virtual const AcGeMatrix3d& transform() const;
    virtual Projection projection() const;
    virtual Tiling uTiling() const;
    virtual Tiling vTiling() const;
    virtual void set(const AcGiMapper&);
    virtual void setAutoTransform(AutoTransform);
    virtual void setProjection(Projection);
    virtual void setUTiling(Tiling);
    virtual void setVTiling(Tiling);
    virtual void setTransform(const AcGeMatrix3d&);

    AcGiMapper& operator=(const AcGiMapper&);
    bool operator!=(const AcGiMapper&) const;
    bool operator==(const AcGiMapper&) const;

    Tiling tiling() const; //deprecated
    void setTiling(Tiling); //deprecated

    static const AcGiMapper kIdentity;
};
