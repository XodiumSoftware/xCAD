// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcGi/AcGiGeometry.h"

class OwnerDraw;
class OwnerDraw3d;

/** _ */
class BRX_IMPORTEXPORT AcGiViewportGeometry: public AcGiGeometry
{
public:
    enum ImageSource
    {
        kFromDwg = 0,
        kFromOleObject,
        kFromRender
    };

    ACRX_DECLARE_MEMBERS(AcGiViewportGeometry);

    virtual Adesk::Boolean polygonDc(const Adesk::UInt32,const AcGePoint3d*) const = 0;
    virtual Adesk::Boolean polygonEye(const Adesk::UInt32,const AcGePoint3d*) const = 0;
    virtual Adesk::Boolean polylineDc(const Adesk::UInt32,const AcGePoint3d*) const = 0;
    virtual Adesk::Boolean polylineEye(const Adesk::UInt32,const AcGePoint3d*) const = 0;
    virtual Adesk::Boolean rasterImageDc(const AcGePoint3d&,const AcGeVector3d&,const AcGeVector3d&,const AcGeMatrix2d&,AcDbObjectId,AcGiImageOrg,Adesk::UInt32,Adesk::UInt32,Adesk::Int16,Adesk::Boolean,ImageSource,const AcGeVector3d&,const AcGiImageOrg,const AcGeMatrix2d&,const Adesk::UInt32,const Adesk::UInt32) const = 0;

    //V10
    virtual Adesk::Boolean ownerDraw3d(AcGePoint3d&,AcGePoint3d&,OwnerDraw3d*) const;
    virtual Adesk::Boolean ownerDrawDc(Adesk::Int32,Adesk::Int32,Adesk::Int32,Adesk::Int32,Adesk::Int32,const OwnerDraw*) const = 0;
};
