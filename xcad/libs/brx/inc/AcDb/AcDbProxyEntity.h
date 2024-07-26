// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbEntity.h"

class AcDbProxyObject;

/** _ */
class __declspec(novtable) AcDbProxyEntity: public AcDbEntity
{
public:
    enum
    {
        kNoOperation = 0,
        kEraseAllowed = 1,
        kTransformAllowed = 2,
        kColorChangeAllowed = 4,
        kLayerChangeAllowed = 8,
        kLinetypeChangeAllowed = 16,
        kLinetypeScaleChangeAllowed = 32,
        kVisibilityChangeAllowed = 64,
        kCloningAllowed = 128,
        kLineWeightChangeAllowed = 256,
        kPlotStyleNameChangeAllowed = 512,
        kAllButCloningAllowed = 895,
        kDisableProxyWarning = 1024,
        kMaterialChangeAllowed = 2048,
        kAllAllowedBits = 3071
    };

    enum GraphicsMetafileType
    {
        kNoMetafile = 0,
        kBoundingBox,
        kFullGraphics
    };

    ACRX_DECLARE_MEMBERS(AcDbProxyEntity);

    virtual ~AcDbProxyEntity() {}

    virtual Acad::ErrorStatus getReferences(AcDbObjectIdArray&,AcDbIntArray&) const = 0;
    virtual const ACHAR* applicationDescription() const = 0;
    virtual const ACHAR* originalClassName() const = 0;
    virtual const ACHAR* originalDxfName() const = 0;
    virtual GraphicsMetafileType graphicsMetafileType() const = 0;
    virtual int proxyFlags() const = 0;

protected:
    virtual Acad::ErrorStatus subExplode(AcDbVoidPtrArray&) const;
    virtual Acad::ErrorStatus subGetGeomExtents(AcDbExtents&) const;
    virtual Acad::ErrorStatus subTransformBy(const AcGeMatrix3d&);
};

const int kAllEntityProxyFlags = 2175;

BRX_IMPORTEXPORT AcDbProxyEntity* acEntityToProxy(const AcDbEntity& pObj, AcDb::AcDbDwgVersion dwgVer, AcDb::MaintenanceReleaseVersion nMaintVer);
