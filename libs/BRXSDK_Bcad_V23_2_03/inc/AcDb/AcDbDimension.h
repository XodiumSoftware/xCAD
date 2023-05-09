// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbMText.h"

/** _ */
class BRX_IMPORTEXPORT AcDbDimension: public AcDbEntity
{
public:
    ACDB_DECLARE_MEMBERS(AcDbDimension);
protected:
    AcDbDimension();
public:
    ~AcDbDimension();

    #include "AcDb/AcDbDimensioningVariables.h"
    virtual Acad::ErrorStatus getPlane(AcGePlane&,AcDb::Planarity&) const;
    virtual Adesk::Boolean isPlanar() const;
    virtual bool castShadows() const;
    virtual bool receiveShadows() const;
    virtual void erased(AcDbObject*,Adesk::Boolean);
    virtual void objectClosed(const AcDbObjectId);
    virtual void setCastShadows(bool);
    virtual void setReceiveShadows(bool);

    Acad::ErrorStatus fieldFromMText(AcDbMText*);
    Acad::ErrorStatus fieldToMText(AcDbMText*);
    Acad::ErrorStatus formatMeasurement(ACHAR*,const size_t,double,ACHAR*);
    Acad::ErrorStatus generateLayout();
    Acad::ErrorStatus getDimstyleData(AcDbDimStyleTableRecord*&) const;
    Acad::ErrorStatus measurement(double&);
    Acad::ErrorStatus recomputeDimBlock(bool = true);
    Acad::ErrorStatus removeTextField();
    Acad::ErrorStatus setArrowFirstIsFlipped(bool);
    Acad::ErrorStatus setArrowSecondIsFlipped(bool);
    Acad::ErrorStatus setDimBlockId(const AcDbObjectId&);
    Acad::ErrorStatus setDimBlockPosition(const AcGePoint3d&);
    Acad::ErrorStatus setDimensionStyle(AcDbObjectId);
    Acad::ErrorStatus setDimensionText(const ACHAR*);
    Acad::ErrorStatus setDimExt1Linetype(const AcDbObjectId);
    Acad::ErrorStatus setDimExt2Linetype(const AcDbObjectId);
    Acad::ErrorStatus setDimfit(int);
    Acad::ErrorStatus setDimLineLinetype(const AcDbObjectId);
    Acad::ErrorStatus setDimstyleData(AcDbDimStyleTableRecord*);
    Acad::ErrorStatus setDimstyleData(AcDbObjectId);
    Acad::ErrorStatus setDimunit(int);
    Acad::ErrorStatus setDynamicDimension(bool);
    Acad::ErrorStatus setElevation(double);
    Acad::ErrorStatus setHorizontalRotation(double);
    Acad::ErrorStatus setNormal(const AcGeVector3d&);
    Acad::ErrorStatus setTextAttachment(AcDbMText::AttachmentPoint);
    Acad::ErrorStatus setTextLineSpacingFactor(double);
    Acad::ErrorStatus setTextLineSpacingStyle(AcDb::LineSpacingStyle);
    Acad::ErrorStatus setTextPosition(const AcGePoint3d&);
    Acad::ErrorStatus setTextRotation(double);
    Acad::ErrorStatus useDefaultTextPosition();
    Acad::ErrorStatus useSetTextPosition();

    bool suppressLeadingZeros() const;
    bool suppressTrailingZeros() const;
    bool suppressAngularLeadingZeros() const;
    bool suppressAngularTrailingZeros() const;
    bool altSuppressLeadingZeros() const;
    bool altSuppressTrailingZeros() const;
    bool toleranceSuppressLeadingZeros() const;
    bool toleranceSuppressTrailingZeros() const;
    bool altToleranceSuppressLeadingZeros() const;
    bool altToleranceSuppressTrailingZeros() const;

    Acad::ErrorStatus setSuppressLeadingZeros(bool);
    Acad::ErrorStatus setSuppressTrailingZeros(bool);
    Acad::ErrorStatus setSuppressAngularLeadingZeros(bool);
    Acad::ErrorStatus setSuppressAngularTrailingZeros(bool);
    Acad::ErrorStatus setAltSuppressLeadingZeros(bool);
    Acad::ErrorStatus setAltSuppressTrailingZeros(bool);
    Acad::ErrorStatus setToleranceSuppressLeadingZeros(bool);
    Acad::ErrorStatus setToleranceSuppressTrailingZeros(bool);
    Acad::ErrorStatus setAltToleranceSuppressLeadingZeros(bool);
    Acad::ErrorStatus setAltToleranceSuppressTrailingZeros(bool);

    AcDb::LineSpacingStyle textLineSpacingStyle() const;
    AcDbMText::AttachmentPoint textAttachment() const;
    AcDbObjectId dimBlockId() const;
    AcDbObjectId dimensionStyle() const;
    AcDbObjectId dimExt1Linetype() const;
    AcDbObjectId dimExt2Linetype() const;
    AcDbObjectId dimLineLinetype() const;
    AcGePoint3d dimBlockPosition() const;
    AcGePoint3d textPosition() const;
    AcGeVector3d normal() const;
    ACHAR* dimensionText() const;
    Adesk::Boolean isUsingDefaultTextPosition() const;
    bool getArrowFirstIsFlipped() const;
    bool getArrowSecondIsFlipped() const;
    bool isDynamicDimension() const;
    double elevation() const;
    double horizontalRotation() const;
    double textLineSpacingFactor() const;
    double textRotation() const;
    int dimfit() const;
    int dimunit() const;
    AcGeMatrix3d blockTransform() const;

protected:
    virtual Acad::ErrorStatus subGetOsnapPoints(AcDb::OsnapMode,Adesk::GsMarker,const AcGePoint3d&,const AcGePoint3d&,const AcGeMatrix3d&,AcGePoint3dArray&,AcDbIntArray&) const;
};
