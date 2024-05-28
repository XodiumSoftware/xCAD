// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbEntity.h"

/** _ */
class BRX_EXPORT AcDbText: public AcDbEntity
{
public:
    ACDB_DECLARE_MEMBERS(AcDbText);

    AcDbText();
    AcDbText(const AcGePoint3d&,const ACHAR*,AcDbObjectId = AcDbObjectId::kNull,double = 0.0,double = 0.0);
    ~AcDbText();

    virtual Acad::ErrorStatus adjustAlignment(const AcDbDatabase* = NULL);
    virtual Acad::ErrorStatus getPlane(AcGePlane&,AcDb::Planarity&) const;
    virtual Adesk::Boolean isPlanar() const;
    virtual bool castShadows() const;
    virtual bool receiveShadows() const;

    Acad::ErrorStatus convertFieldToText();
    Acad::ErrorStatus mirrorInX(Adesk::Boolean);
    Acad::ErrorStatus mirrorInY(Adesk::Boolean);
    Acad::ErrorStatus removeField(AcDbObjectId);
    Acad::ErrorStatus removeField(const ACHAR*);
    Acad::ErrorStatus removeField(const ACHAR*,AcDbObjectId&);
    Acad::ErrorStatus setAlignmentPoint(const AcGePoint3d&);
    Acad::ErrorStatus setField(const ACHAR*,AcDbField*,AcDbObjectId&);
    Acad::ErrorStatus setHeight(double);
    Acad::ErrorStatus setHorizontalMode(AcDb::TextHorzMode);
    Acad::ErrorStatus setNormal(const AcGeVector3d&);
    Acad::ErrorStatus setOblique(double);
    Acad::ErrorStatus setPosition(const AcGePoint3d&);
    Acad::ErrorStatus setRotation(double);
    Acad::ErrorStatus setTextString(const ACHAR*);
    Acad::ErrorStatus setTextStyle(AcDbObjectId);
    Acad::ErrorStatus setThickness(double);
    Acad::ErrorStatus setVerticalMode(AcDb::TextVertMode);
    Acad::ErrorStatus setWidthFactor(double);
    AcDb::TextHorzMode horizontalMode() const;
    AcDb::TextVertMode verticalMode() const;
    AcDbObjectId textStyle() const;
    AcGePoint3d alignmentPoint() const;
    AcGePoint3d position() const;
    AcGeVector3d normal() const;
    ACHAR* textString() const;
    Adesk::Boolean isDefaultAlignment() const;
    Adesk::Boolean isMirroredInX() const;
    Adesk::Boolean isMirroredInY() const;
    const ACHAR* textStringConst() const;
    double height() const;
    double oblique() const;
    double rotation() const;
    double thickness() const;
    double widthFactor() const;
    int correctSpelling();

    enum AcTextAlignment
    {
        kTextAlignmentLeft = 0,
        kTextAlignmentCenter = 1,
        kTextAlignmentRight = 2,
        kTextAlignmentAligned = 3,
        kTextAlignmentMiddle = 4,
        kTextAlignmentFit = 5,
        kTextAlignmentTopLeft = 6,
        kTextAlignmentTopCenter = 7,
        kTextAlignmentTopRight = 8,
        kTextAlignmentMiddleLeft = 9,
        kTextAlignmentMiddleCenter = 10,
        kTextAlignmentMiddleRight = 11,
        kTextAlignmentBottomLeft = 12,
        kTextAlignmentBottomCenter = 13,
        kTextAlignmentBottomRight = 14
    };
    AcTextAlignment justification() const;
    Acad::ErrorStatus setJustification(AcTextAlignment);
    void getBoundingPoints(AcGePoint3dArray&) const;

protected:
    virtual Adesk::UInt32 subSetAttributes(AcGiDrawableTraits*);
};
