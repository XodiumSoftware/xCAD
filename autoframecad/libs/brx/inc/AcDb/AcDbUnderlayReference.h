// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbEntity.h"

class AcUnderlayLayer;

/** _ */
class BRX_IMPORTEXPORT AcDbUnderlayReference: public AcDbEntity
{
public:
    ACDB_DECLARE_MEMBERS(AcDbUnderlayReference);

    virtual ~AcDbUnderlayReference() = 0;

    virtual bool isFramePlottable() const;
    virtual bool isFrameVisible() const;

    Acad::ErrorStatus setClipBoundary(const AcGePoint2dArray&);
    Acad::ErrorStatus setClipInverted(bool);
    Acad::ErrorStatus setContrast(Adesk::UInt8);
    Acad::ErrorStatus setDefinitionId(AcDbObjectId);
    Acad::ErrorStatus setFade(Adesk::UInt8);
    Acad::ErrorStatus setHeight(double);
    Acad::ErrorStatus setIsAdjustedForBackground(bool);
    Acad::ErrorStatus setIsClipped(bool);
    Acad::ErrorStatus setIsMonochrome(bool);
    Acad::ErrorStatus setIsOn(bool);
    Acad::ErrorStatus setNormal(const AcGeVector3d&);
    Acad::ErrorStatus setPosition(const AcGePoint3d&);
    Acad::ErrorStatus setRotation(double);
    Acad::ErrorStatus setScaleFactors(const AcGeScale3d&);
    Acad::ErrorStatus setTransform(const AcGeMatrix3d&);
    Acad::ErrorStatus setUnderlayLayer(int, const AcUnderlayLayer&);
    Acad::ErrorStatus setWidth(double);
    Acad::ErrorStatus generateClipBoundaryFromPline(AcDbObjectId);
    Acad::ErrorStatus getUnderlayLayer(int, AcUnderlayLayer&) const;
    Acad::ErrorStatus height(double&) const;
    Acad::ErrorStatus width(double&) const;

    AcDbObjectId definitionId() const;
    AcGeMatrix3d transform() const;
    AcGePoint3d position() const;
    AcGeScale3d scaleFactors() const;
    AcGeVector3d normal() const;
    Adesk::UInt8 contrast() const;
    Adesk::UInt8 fade() const;
    Adesk::UInt32 underlayLayerCount() const;

    bool isAdjustedForBackground() const;
    bool isClipInverted() const;
    bool isClipped() const;
    bool isMonochrome() const;
    bool isOn() const;

    const AcGePoint2dArray& clipBoundary() const;
    double rotation() const;

    static Adesk::UInt8 contrastDefault();
    static Adesk::UInt8 contrastLowerLimit();
    static Adesk::UInt8 contrastUpperLimit();
    static Adesk::UInt8 fadeDefault();
    static Adesk::UInt8 fadeLowerLimit();
    static Adesk::UInt8 fadeUpperLimit();

protected:
    virtual bool subIsContentSnappable() const;
};
