// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcCm/AcCmColor.h"
#include "AcDb/AcDbObject.h"
#include "Misc/AcValue.h"
#include "Misc/AcGridProperty.h"

class AcDbTableTemplate;

/** _ */
class BRX_EXPORT AcDbTableStyle: public AcDbObject
{
public:
    ACDB_DECLARE_MEMBERS(AcDbTableStyle);

    AcDbTableStyle();
    virtual ~AcDbTableStyle();

    virtual Acad::ErrorStatus audit(AcDbAuditInfo*);
    virtual Acad::ErrorStatus dwgInFields(AcDbDwgFiler*);
    virtual Acad::ErrorStatus dwgOutFields(AcDbDwgFiler*) const;
    virtual Acad::ErrorStatus dxfInFields(AcDbDxfFiler*);
    virtual Acad::ErrorStatus dxfOutFields(AcDbDxfFiler*) const;
    virtual Acad::ErrorStatus getName(ACHAR*&) const;
    virtual Acad::ErrorStatus postTableStyleToDb(AcDbDatabase*,const ACHAR*,AcDbObjectId&);
    virtual Acad::ErrorStatus setAlignment(AcDb::CellAlignment,int = AcDb::kAllRows);
    virtual Acad::ErrorStatus setBackgroundColor(const AcCmColor&,int = AcDb::kAllRows);
    virtual Acad::ErrorStatus setBackgroundColorNone(bool,int = AcDb::kAllRows);
    virtual Acad::ErrorStatus setBitFlags(Adesk::UInt32);
    virtual Acad::ErrorStatus setColor(const AcCmColor&,int = AcDb::kAllRows);
    virtual Acad::ErrorStatus setDescription(const ACHAR*);
    virtual Acad::ErrorStatus setFlowDirection(AcDb::FlowDirection);
    virtual Acad::ErrorStatus setGridColor(const AcCmColor,int = AcDb::kAllGridLines,int = AcDb::kAllRows);
    virtual Acad::ErrorStatus setGridLineWeight(AcDb::LineWeight,int = AcDb::kAllGridLines,int = AcDb::kAllRows);
    virtual Acad::ErrorStatus setGridVisibility(AcDb::Visibility,int = AcDb::kAllGridLines,int = AcDb::kAllRows);
    virtual Acad::ErrorStatus setHorzCellMargin(double);
    virtual Acad::ErrorStatus setName(const ACHAR*);
    virtual Acad::ErrorStatus setTextHeight(double,int = AcDb::kAllRows);
    virtual Acad::ErrorStatus setTextStyle(const AcDbObjectId,int = AcDb::kAllRows);
    virtual Acad::ErrorStatus setVertCellMargin(double);
    virtual Acad::ErrorStatus suppressHeaderRow(bool);
    virtual Acad::ErrorStatus suppressTitleRow(bool);
    virtual AcCmColor backgroundColor(AcDb::RowType = AcDb::kDataRow) const;
    virtual AcCmColor color(AcDb::RowType = AcDb::kDataRow) const;
    virtual AcCmColor gridColor(AcDb::GridLineType,AcDb::RowType = AcDb::kDataRow) const;
    virtual AcDb::CellAlignment alignment(AcDb::RowType = AcDb::kDataRow) const;
    virtual AcDb::FlowDirection flowDirection() const;
    virtual AcDb::LineWeight gridLineWeight(AcDb::GridLineType,AcDb::RowType = AcDb::kDataRow) const;
    virtual AcDb::Visibility gridVisibility(AcDb::GridLineType,AcDb::RowType = AcDb::kDataRow) const;
    virtual AcDbObjectId textStyle(AcDb::RowType = AcDb::kDataRow) const;
    virtual Adesk::UInt32 bitFlags() const;
    virtual bool isBackgroundColorNone(AcDb::RowType = AcDb::kDataRow) const;
    virtual bool isHeaderSuppressed() const;
    virtual bool isTitleSuppressed() const;
    virtual const ACHAR* description() const;
    virtual double horzCellMargin() const;
    virtual double textHeight(AcDb::RowType = AcDb::kDataRow) const;
    virtual double vertCellMargin() const;

    //V10
    virtual Acad::ErrorStatus getDataType(AcValue::DataType&,AcValue::UnitType&) const;
    virtual Acad::ErrorStatus getDataType(AcValue::DataType&,AcValue::UnitType&,AcDb::RowType) const;
    virtual Acad::ErrorStatus setDataType(AcValue::DataType,AcValue::UnitType);
    virtual Acad::ErrorStatus setDataType(AcValue::DataType,AcValue::UnitType,int);
    virtual Acad::ErrorStatus setFormat(const ACHAR*);
    virtual Acad::ErrorStatus setFormat(const ACHAR*,int);
    virtual const ACHAR* format() const;
    virtual const ACHAR* format(AcDb::RowType) const;

    //V12
    Acad::ErrorStatus createCellStyle(const ACHAR*);

    //V16
    AcDb::CellAlignment alignment(const ACHAR*) const;
    AcCmColor backgroundColor(const ACHAR*) const;
    int cellClass(const ACHAR*) const;
    AcCmColor color(const ACHAR*) const;
    Acad::ErrorStatus copyCellStyle(const ACHAR*, const ACHAR*);
    Acad::ErrorStatus copyCellStyle(const AcDbTableStyle*, const ACHAR*, const ACHAR*);
    const ACHAR* createCellStyle(void);
    Acad::ErrorStatus createCellStyle(const ACHAR*, const ACHAR*);
    Acad::ErrorStatus deleteCellStyle(const ACHAR*);
    Acad::ErrorStatus enableMergeAll(bool, const ACHAR*);
    const ACHAR* format(const ACHAR*) const;
    int getCellStyles(AcStringArray&) const;
    Acad::ErrorStatus getDataType(AcValue::DataType&, AcValue::UnitType&, const ACHAR*) const;
    Acad::ErrorStatus getGridProperty(AcGridProperty&, AcDb::GridLineType, const ACHAR*) const;
    AcDbObjectId getTemplate(void) const;
    Acad::ErrorStatus getTemplate(AcDbTableTemplate*&, AcDb::OpenMode);
    Acad::ErrorStatus getUniqueCellStyleName(const ACHAR*, AcString&) const;
    AcCmColor gridColor(AcDb::GridLineType, const ACHAR*) const;
    double gridDoubleLineSpacing(AcDb::GridLineType, const ACHAR*) const;
    AcDb::GridLineStyle gridLineStyle(AcDb::GridLineType, const ACHAR*) const;
    AcDbObjectId gridLinetype(AcDb::GridLineType, const ACHAR*) const;
    AcDb::LineWeight gridLineWeight(AcDb::GridLineType, const ACHAR*) const;
    AcDb::Visibility gridVisibility(AcDb::GridLineType, const ACHAR*) const;
    bool isCellStyleInUse(const ACHAR*) const;
    bool isMergeAllEnabled(const ACHAR*) const;
    bool isRenamable() const;
    double margin(AcDb::CellMargin, const ACHAR*) const;
    int numCellStyles(void) const;
    AcDbObjectId removeTemplate(void);
    Acad::ErrorStatus renameCellStyle(const ACHAR*, const ACHAR*);
    double rotation(const ACHAR*) const;
    Acad::ErrorStatus setAlignment(AcDb::CellAlignment, const ACHAR*);
    Acad::ErrorStatus setBackgroundColor(const AcCmColor&, const ACHAR*);
    Acad::ErrorStatus setCellClass(int, const ACHAR*);
    Acad::ErrorStatus setColor(const AcCmColor&, const ACHAR*);
    Acad::ErrorStatus setDataType(AcValue::DataType, AcValue::UnitType, const ACHAR*);
    Acad::ErrorStatus setFormat(const ACHAR*,  const ACHAR*);
    Acad::ErrorStatus setGridColor(const AcCmColor, AcDb::GridLineType, const ACHAR*);
    Acad::ErrorStatus setGridDoubleLineSpacing(double, AcDb::GridLineType, const ACHAR*);
    Acad::ErrorStatus setGridLineStyle(AcDb::GridLineStyle, AcDb::GridLineType, const ACHAR*);
    Acad::ErrorStatus setGridLinetype(const AcDbObjectId&, AcDb::GridLineType, const ACHAR*);
    Acad::ErrorStatus setGridLineWeight(AcDb::LineWeight, AcDb::GridLineType, const ACHAR*);
    Acad::ErrorStatus setGridProperty(const AcGridProperty&, AcDb::GridLineType, const ACHAR*);
    Acad::ErrorStatus setGridVisibility(AcDb::Visibility, AcDb::GridLineType, const ACHAR*);
    Acad::ErrorStatus setMargin(AcDb::CellMargin, double, const ACHAR*);
    Acad::ErrorStatus setRotation(double, const ACHAR*);
    Acad::ErrorStatus setTemplate(const AcDbObjectId&, AcDb::MergeCellStyleOption);
    Acad::ErrorStatus setTemplate(AcDbTableTemplate*, AcDb::MergeCellStyleOption, AcDbObjectId&);
    Acad::ErrorStatus setTextHeight(double, const ACHAR*);
    Acad::ErrorStatus setTextStyle(const AcDbObjectId&, const ACHAR*);
    double textHeight(const ACHAR*) const;
    AcDbObjectId textStyle(const ACHAR*) const;
};
