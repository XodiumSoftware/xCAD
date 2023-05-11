// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbRasterImage.h"

/** _ */
class BRX_EXPORT AcDbWipeout: public AcDbRasterImage
{
public:
    ACRX_DECLARE_MEMBERS(AcDbWipeout);

    AcDbWipeout();

    static Acad::ErrorStatus createImageDefinition();
    static Acad::ErrorStatus fitPointsToImage(AcGePoint2dArray&, AcGePoint2d&, double&, Adesk::Boolean = Adesk::kFalse);

    AcGiSentScanLines* getScanLines(const AcGiRequestScanLines&) const;
    Adesk::Boolean isClipped() const;
    Adesk::Boolean frame() const;
    Acad::ErrorStatus append(AcDbObjectId&);

    virtual AcRxObject* clone() const;
    virtual AcGeVector2d imageSize(Adesk::Boolean = Adesk::kFalse) const;

    virtual Adesk::Boolean isSetDisplayOpt(ImageDisplayOpt) const;
    virtual Adesk::Int8 brightness() const;
    virtual Adesk::Int8 contrast() const;
    virtual Adesk::Int8 fade() const;

    virtual void setDisplayOpt(ImageDisplayOpt, Adesk::Boolean);
    virtual Acad::ErrorStatus setBrightness(Adesk::Int8);
    virtual Acad::ErrorStatus setContrast(Adesk::Int8);
    virtual Acad::ErrorStatus setFade(Adesk::Int8);
    virtual AcGeVector2d scale() const;

protected:
    virtual void subList() const;
    virtual Acad::ErrorStatus subMoveGripPointsAt(const AcDbVoidPtrArray&, const AcGeVector3d&, const int);
    virtual Acad::ErrorStatus subMoveGripPointsAt(const AcDbIntArray&, const AcGeVector3d&);
    virtual Acad::ErrorStatus subTransformBy(const AcGeMatrix3d&);
    virtual Acad::ErrorStatus subGetTransformedCopy(const AcGeMatrix3d&, AcDbEntity*&) const;
    virtual void subViewportDraw(AcGiViewportDraw*);
    virtual Adesk::Boolean subWorldDraw(AcGiWorldDraw*);

public:
    static long mImageData;
};
