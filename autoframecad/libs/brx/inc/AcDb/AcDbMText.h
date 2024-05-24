// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbEntity.h"
#include "AcDb/AcDbMTextFragment.h"

/** _ */
class BRX_EXPORT AcDbMText: public AcDbEntity
{
public:
    enum AttachmentPoint
    {
        kTopLeft = 1,
        kTopCenter,
        kTopRight,
        kMiddleLeft,
        kMiddleCenter,
        kMiddleRight,
        kBottomLeft,
        kBottomCenter,
        kBottomRight,
        kBaseLeft,
        kBaseCenter,
        kBaseRight,
        kBaseAlign,
        kBottomAlign,
        kMiddleAlign,
        kTopAlign,
        kBaseFit,
        kBottomFit,
        kMiddleFit,
        kTopFit,
        kBaseMid,
        kBottomMid,
        kMiddleMid,
        kTopMid
    };

    enum FlowDirection
    {
        kLtoR = 1,
        kRtoL,
        kTtoB,
        kBtoT,
        kByStyle
    };

    enum ColumnType
    {
        kNoColumns      = 0,
        kStaticColumns  = 1,
        kDynamicColumns = 2,
    };

    ACDB_DECLARE_MEMBERS(AcDbMText);

    AcDbMText();
    ~AcDbMText();

    Acad::ErrorStatus convertFieldToText();
    Acad::ErrorStatus getBackgroundFillColor(AcCmColor&) const;
    Acad::ErrorStatus getBackgroundScaleFactor(double&) const;
    Acad::ErrorStatus getBackgroundTransparency(AcCmTransparency&) const;
    Acad::ErrorStatus removeField(AcDbObjectId);
    Acad::ErrorStatus removeField(const ACHAR*);
    Acad::ErrorStatus removeField(const ACHAR*,AcDbObjectId&);
    Acad::ErrorStatus setAttachment(AttachmentPoint);
    Acad::ErrorStatus setAttachmentMovingLocation(AttachmentPoint);
    Acad::ErrorStatus setBackgroundFill(bool);
    Acad::ErrorStatus setBackgroundFillColor(const AcCmColor&);
    Acad::ErrorStatus setBackgroundScaleFactor(const double);
    Acad::ErrorStatus setBackgroundTransparency(const AcCmTransparency&);
    Acad::ErrorStatus setDirection(const AcGeVector3d&);
    Acad::ErrorStatus setField(const ACHAR*,AcDbField*,AcDbObjectId&);
    Acad::ErrorStatus setFlowDirection(FlowDirection);
    Acad::ErrorStatus setHeight(double);
    Acad::ErrorStatus setLineSpacingFactor(double);
    Acad::ErrorStatus setLineSpacingStyle(AcDb::LineSpacingStyle);
    Acad::ErrorStatus setLocation(const AcGePoint3d&);
    Acad::ErrorStatus setNormal(const AcGeVector3d&);
    Acad::ErrorStatus setRotation(double);
    Acad::ErrorStatus setTextHeight(double);
    Acad::ErrorStatus setTextStyle(AcDbObjectId);
    Acad::ErrorStatus setUseBackgroundColor(bool);
    Acad::ErrorStatus setWidth(double);
    Acad::ErrorStatus setShowBorders(bool);
    AcDb::LineSpacingStyle lineSpacingStyle() const;
    AcDbObjectId textStyle() const;
    AcGePoint3d location() const;
    AcGeVector3d direction() const;
    AcGeVector3d normal() const;
    Acad::ErrorStatus contents(AcString&) const;
    ACHAR* contents() const; //deprecated
    Acad::ErrorStatus contentsRTF(AcString& sContentsRTF) const;
    ACHAR* contentsRTF() const; //deprecated
    Acad::ErrorStatus text(AcString&) const;
    ACHAR* text() const; //deprecated
    AttachmentPoint attachment() const;
    bool backgroundFillOn() const;
    bool useBackgroundColorOn() const;
    double actualHeight(AcGiWorldDraw* = NULL) const;
    double actualWidth() const;
    double ascent() const;
    double descent() const;
    double height() const;
    double lineSpacingFactor() const;
    double rotation() const;
    double textHeight() const;
    double width() const;
    FlowDirection flowDirection() const;
    int correctSpelling();
    int setContents(const ACHAR*);
    int setContentsRTF(const ACHAR*);
    void explodeFragments(AcDbMTextEnum,void*,AcGiWorldDraw* = NULL) const;
    void getBoundingPoints(AcGePoint3dArray&) const;
    void getEcs(AcGeMatrix3d&) const;
    bool showBorders() const;

    Acad::ErrorStatus getColumnType(ColumnType&) const;
    Acad::ErrorStatus getColumnAutoHeight(bool&) const;
    Acad::ErrorStatus getColumnCount(int&) const;
    Acad::ErrorStatus getColumnWidth(double&) const;
    Acad::ErrorStatus getColumnGutterWidth(double&) const;
    Acad::ErrorStatus getColumnFlowReversed(bool&) const;
    Acad::ErrorStatus getColumnHeight(int, double&) const;

    Acad::ErrorStatus setColumnType(ColumnType);
    Acad::ErrorStatus setColumnAutoHeight(bool);
    Acad::ErrorStatus setColumnCount(int);
    Acad::ErrorStatus setColumnWidth(double);
    Acad::ErrorStatus setColumnGutterWidth(double);
    Acad::ErrorStatus setColumnFlowReversed(bool);
    Acad::ErrorStatus setColumnHeight(int, double);

    Acad::ErrorStatus setDynamicColumns(double, double, bool);
    Acad::ErrorStatus setStaticColumns(double, double, int);

    static const ACHAR* const alignChange();
    static const ACHAR* const blockBegin();
    static const ACHAR* const blockEnd();
    static const ACHAR* const colorChange();
    static const ACHAR* const fontChange();
    static const ACHAR* const heightChange();
    static const ACHAR* const lineBreak();
    static const ACHAR* const nonBreakSpace();
    static const ACHAR* const obliqueChange();
    static const ACHAR* const overlineOff();
    static const ACHAR* const overlineOn();
    static const ACHAR* const paragraphBreak();
    static const ACHAR* const stackStart();
    static const ACHAR* const trackChange();
    static const ACHAR* const underlineOff();
    static const ACHAR* const underlineOn();
    static const ACHAR* const widthChange();

protected:
    virtual Acad::ErrorStatus subGetTransformedCopy(const AcGeMatrix3d&, AcDbEntity*&) const;
};
