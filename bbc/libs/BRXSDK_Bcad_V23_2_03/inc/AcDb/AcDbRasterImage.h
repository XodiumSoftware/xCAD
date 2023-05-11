// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbImage.h"

/** _ */
class BRX_EXPORT AcDbRasterImage: public AcDbImage
{
public:
    enum ClipBoundaryType
    {
        kInvalid = 0,
        kRect,
        kPoly
    };

    enum ImageDisplayOpt
    {
        kShow = 1,
        kShowUnAligned = 2,
        kClip = 4,
        kTransparent = 8
    };

    ACRX_DECLARE_MEMBERS(AcDbRasterImage);

    AcDbRasterImage();
    virtual ~AcDbRasterImage();

    virtual Acad::ErrorStatus dwgInFields(AcDbDwgFiler*);
    virtual Acad::ErrorStatus dwgOutFields(AcDbDwgFiler*) const;
    virtual Acad::ErrorStatus dxfInFields(AcDbDxfFiler*);
    virtual Acad::ErrorStatus dxfOutFields(AcDbDxfFiler*) const;
    virtual Acad::ErrorStatus getPixelToModelTransform(AcGeMatrix3d&) const;
    virtual Acad::ErrorStatus getVertices(AcGePoint3dArray&) const;
    virtual Acad::ErrorStatus setBrightness(Adesk::Int8);
    virtual Acad::ErrorStatus setClipBoundary(ClipBoundaryType,const AcGePoint2dArray&);
    virtual Acad::ErrorStatus setClipBoundaryToWholeImage(AcGeVector2d& = const_cast<AcGeVector2d&>(AcGeVector2d::kIdentity));
    virtual Acad::ErrorStatus setContrast(Adesk::Int8);
    virtual Acad::ErrorStatus setFade(Adesk::Int8);
    virtual Acad::ErrorStatus setImageDefId(AcDbObjectId);
    virtual Acad::ErrorStatus subSwapIdWith(AcDbObjectId,Adesk::Boolean = Adesk::kFalse,Adesk::Boolean = Adesk::kFalse);
    virtual AcDbObjectId imageDefId() const;
    virtual AcDbObjectId reactorId() const;
    virtual AcGeVector2d imageSize(Adesk::Boolean = Adesk::kFalse) const;
    virtual AcGeVector2d scale() const;
    virtual AcGiSentScanLines* getScanLines(const AcGiRequestScanLines&) const;
    virtual Adesk::Boolean freeScanLines(AcGiSentScanLines*) const;
    virtual Adesk::Boolean isSetDisplayOpt(ImageDisplayOpt) const;
    virtual Adesk::Boolean setOrientation(const AcGePoint3d&,const AcGeVector3d&,const AcGeVector3d&);
    virtual Adesk::Int8 brightness() const;
    virtual Adesk::Int8 contrast() const;
    virtual Adesk::Int8 fade() const;
    virtual bool castShadows() const;
    virtual bool receiveShadows() const;
    virtual ClipBoundaryType clipBoundaryType() const;
    virtual const AcGePoint2dArray& clipBoundary() const;
    virtual void getOrientation(AcGePoint3d&,AcGeVector3d&,AcGeVector3d&) const;
    virtual Adesk::Boolean isClipInverted() const;
    virtual void saveAs(AcGiWorldDraw*,AcDb::SaveType);
    virtual void setCastShadows(bool);
    virtual void setDisplayOpt(ImageDisplayOpt,Adesk::Boolean);
    virtual void setReactorId(AcDbObjectId);
    virtual void setReceiveShadows(bool);
    virtual void setClipInverted(Adesk::Boolean);

    Adesk::Boolean isClipped() const;

    double      imageHeight() const;
    double      imageWidth() const;
    AcGePoint3d position() const;
    double      rotation() const;
    double      width() const;
    double      height() const;
    bool        isImageShown() const;
    bool        isShownClipped() const;
    bool        isImageTransparent() const;

    Acad::ErrorStatus setHeight(double);
    Acad::ErrorStatus setWidth(double);
    Acad::ErrorStatus setRotation(double);
    void setShowImage(bool);
    void setShowClipped(bool);
    void setImageTransparency(bool);

    static ClassVersion classVersion();

protected:
    virtual Acad::ErrorStatus subExplode(AcDbVoidPtrArray&) const;
    virtual Acad::ErrorStatus subGetGeomExtents(AcDbExtents&) const;
    virtual Acad::ErrorStatus subGetGripPoints(AcGePoint3dArray&,AcDbIntArray&,AcDbIntArray&) const;
    virtual Acad::ErrorStatus subGetGsMarkersAtSubentPath(const AcDbFullSubentPath&,AcArray<Adesk::GsMarker>&) const;
    virtual Acad::ErrorStatus subGetOsnapPoints(AcDb::OsnapMode,Adesk::GsMarker,const AcGePoint3d&,const AcGePoint3d&,const AcGeMatrix3d&,AcGePoint3dArray&,AcDbIntArray&) const;
    virtual Acad::ErrorStatus subGetStretchPoints(AcGePoint3dArray&) const;
    virtual Acad::ErrorStatus subGetSubentPathsAtGsMarker(AcDb::SubentType,Adesk::GsMarker,const AcGePoint3d&,const AcGeMatrix3d&,int&,AcDbFullSubentPath*&,int = 0,AcDbObjectId* = NULL) const;
    virtual Acad::ErrorStatus subGetTransformedCopy(const AcGeMatrix3d&,AcDbEntity*&) const;
    virtual Acad::ErrorStatus subIntersectWith(const AcDbEntity*,AcDb::Intersect,AcGePoint3dArray&,Adesk::GsMarker = 0,Adesk::GsMarker = 0) const;
    virtual Acad::ErrorStatus subIntersectWith(const AcDbEntity*,AcDb::Intersect,const AcGePlane&,AcGePoint3dArray&,Adesk::GsMarker = 0,Adesk::GsMarker = 0) const;
    virtual void subList() const;
    virtual Acad::ErrorStatus subMoveGripPointsAt(const AcDbIntArray&,const AcGeVector3d&);
    virtual Acad::ErrorStatus subMoveGripPointsAt(const AcDbVoidPtrArray&, const AcGeVector3d&, const int);
    virtual Acad::ErrorStatus subMoveStretchPointsAt(const AcDbIntArray&,const AcGeVector3d&);
    virtual AcDbEntity* subSubentPtr(const AcDbFullSubentPath&) const;
    virtual Acad::ErrorStatus subTransformBy(const AcGeMatrix3d&);
    virtual void subViewportDraw(AcGiViewportDraw*);
    virtual Adesk::Boolean subWorldDraw(AcGiWorldDraw*);
};

void modelToPixel(const AcGeMatrix3d&,const AcGePoint3d&,AcGePoint2d&);
void modelToPixel(const AcGeVector3d&,const AcGeMatrix3d&,const AcGePlane&,const AcGePoint3d&,AcGePoint2d&);
void pixelToModel(const AcGeMatrix3d&,const AcGePoint2d&,AcGePoint3d&);
