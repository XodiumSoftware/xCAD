// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbBlockReference.h"
#include "Misc/AcValue.h"
#include "Misc/AcGridProperty.h"
#include "AcCell.h"

class AcDbTableTemplate;
class AcDbTableIterator;
class AcDbDataLink;
class AcDbLinkedTableData;


/** _ */
class BRX_EXPORT AcDbTable: public AcDbBlockReference
{
public:
    enum TableStyleOverrides
    {
        kTitleSuppressed = 1,
        kHeaderSuppressed,
        kFlowDirection,
        kHorzCellMargin,
        kVertCellMargin,
        kTitleRowColor,
        kHeaderRowColor,
        kDataRowColor,
        kTitleRowFillNone,
        kHeaderRowFillNone,
        kDataRowFillNone,
        kTitleRowFillColor,
        kHeaderRowFillColor,
        kDataRowFillColor,
        kTitleRowAlignment,
        kHeaderRowAlignment,
        kDataRowAlignment,
        kTitleRowTextStyle,
        kHeaderRowTextStyle,
        kDataRowTextStyle,
        kTitleRowTextHeight,
        kHeaderRowTextHeight,
        kDataRowTextHeight,
        kTitleHorzTopColor = 40,
        kTitleHorzInsideColor,
        kTitleHorzBottomColor,
        kTitleVertLeftColor,
        kTitleVertInsideColor,
        kTitleVertRightColor,
        kHeaderHorzTopColor,
        kHeaderHorzInsideColor,
        kHeaderHorzBottomColor,
        kHeaderVertLeftColor,
        kHeaderVertInsideColor,
        kHeaderVertRightColor,
        kDataHorzTopColor,
        kDataHorzInsideColor,
        kDataHorzBottomColor,
        kDataVertLeftColor,
        kDataVertInsideColor,
        kDataVertRightColor,
        kTitleHorzTopLineWeight = 70,
        kTitleHorzInsideLineWeight,
        kTitleHorzBottomLineWeight,
        kTitleVertLeftLineWeight,
        kTitleVertInsideLineWeight,
        kTitleVertRightLineWeight,
        kHeaderHorzTopLineWeight,
        kHeaderHorzInsideLineWeight,
        kHeaderHorzBottomLineWeight,
        kHeaderVertLeftLineWeight,
        kHeaderVertInsideLineWeight,
        kHeaderVertRightLineWeight,
        kDataHorzTopLineWeight,
        kDataHorzInsideLineWeight,
        kDataHorzBottomLineWeight,
        kDataVertLeftLineWeight,
        kDataVertInsideLineWeight,
        kDataVertRightLineWeight,
        kTitleHorzTopVisibility = 100,
        kTitleHorzInsideVisibility,
        kTitleHorzBottomVisibility,
        kTitleVertLeftVisibility,
        kTitleVertInsideVisibility,
        kTitleVertRightVisibility,
        kHeaderHorzTopVisibility,
        kHeaderHorzInsideVisibility,
        kHeaderHorzBottomVisibility,
        kHeaderVertLeftVisibility,
        kHeaderVertInsideVisibility,
        kHeaderVertRightVisibility,
        kDataHorzTopVisibility,
        kDataHorzInsideVisibility,
        kDataHorzBottomVisibility,
        kDataVertLeftVisibility,
        kDataVertInsideVisibility,
        kDataVertRightVisibility,
        kCellAlignment = 130,
        kCellBackgroundFillNone,
        kCellBackgroundColor,
        kCellContentColor,
        kCellTextStyle,
        kCellTextHeight,
        kCellTopGridColor,
        kCellRightGridColor,
        kCellBottomGridColor,
        kCellLeftGridColor,
        kCellTopGridLineWeight,
        kCellRightGridLineWeight,
        kCellBottomGridLineWeight,
        kCellLeftGridLineWeight,
        kCellTopVisibility,
        kCellRightVisibility,
        kCellBottomVisibility,
        kCellLeftVisibility,
        kCellDataType
    };

    ACDB_DECLARE_MEMBERS(AcDbTable);

    AcDbTable();
    AcDbTable(const AcDbLinkedTableData*, AcDb::TableCopyOption);
    virtual ~AcDbTable();

    virtual Acad::ErrorStatus audit(AcDbAuditInfo*);
    virtual Acad::ErrorStatus deleteCellContent(int,int);
    virtual Acad::ErrorStatus deleteColumns(int,int = 1);
    virtual Acad::ErrorStatus deleteRows(int,int = 1);
    virtual Acad::ErrorStatus dwgInFields(AcDbDwgFiler*);
    virtual Acad::ErrorStatus dwgOutFields(AcDbDwgFiler*) const;
    virtual Acad::ErrorStatus dxfInFields(AcDbDxfFiler*);
    virtual Acad::ErrorStatus dxfOutFields(AcDbDxfFiler*) const;
    virtual Acad::ErrorStatus generateLayout();
    virtual Acad::ErrorStatus getBlockAttributeValue(int,int,const AcDbObjectId&,ACHAR*&) const;
    virtual Acad::ErrorStatus getCellExtents(int,int,bool,AcGePoint3dArray&) const;
    virtual Acad::ErrorStatus getSubSelection(int&,int&,int&,int&) const;
    virtual Acad::ErrorStatus insertColumns(int,double,int = 1);
    virtual Acad::ErrorStatus insertRows(int,double,int = 1);
    virtual Acad::ErrorStatus mergeCells(int,int,int,int);
    virtual Acad::ErrorStatus recomputeTableBlock(bool = true);
    virtual Acad::ErrorStatus select(const AcGePoint3d&,const AcGeVector3d&,const AcGeVector3d&,double,double,bool,bool,int&,int&,AcDbFullSubentPathArray* = NULL) const;
    virtual Acad::ErrorStatus selectSubRegion(const AcGePoint3d&,const AcGePoint3d&,const AcGeVector3d&,const AcGeVector3d&,double,double,AcDb::SelectType,bool,bool,int&,int&,int&,int&,AcDbFullSubentPathArray* = NULL) const;
    virtual Acad::ErrorStatus setAlignment(AcDb::CellAlignment,int = AcDb::kAllRows);
    virtual Acad::ErrorStatus setAlignment(int,int,AcDb::CellAlignment);
    virtual Acad::ErrorStatus setAutoScale(int,int,bool);
    virtual Acad::ErrorStatus setBackgroundColor(const AcCmColor&,int = AcDb::kAllRows);
    virtual Acad::ErrorStatus setBackgroundColor(int,int,const AcCmColor&);
    virtual Acad::ErrorStatus setBackgroundColorNone(bool,int = AcDb::kAllRows);
    virtual Acad::ErrorStatus setBackgroundColorNone(int,int,bool);
    virtual Acad::ErrorStatus setBlockAttributeValue(int,int,const AcDbObjectId&,const ACHAR*);
    virtual Acad::ErrorStatus setBlockRotation(int,int,double);
    virtual Acad::ErrorStatus setBlockScale(int,int,double);
    virtual Acad::ErrorStatus setBlockTableRecordId(int,int,const AcDbObjectId&,bool = false);
    virtual Acad::ErrorStatus setCellType(int,int,AcDb::CellType);
    virtual Acad::ErrorStatus setColumnWidth(double);
    virtual Acad::ErrorStatus setColumnWidth(int,double);
    virtual Acad::ErrorStatus setContentColor(const AcCmColor&,int = AcDb::kAllRows);
    virtual Acad::ErrorStatus setContentColor(int,int,const AcCmColor&);
    virtual Acad::ErrorStatus setDirection(const AcGeVector3d&);
    virtual Acad::ErrorStatus setFieldId(int,int,const AcDbObjectId&);
    virtual Acad::ErrorStatus setFlowDirection(AcDb::FlowDirection);
    virtual Acad::ErrorStatus setGridColor(const AcCmColor&,int,int);
    virtual Acad::ErrorStatus setGridColor(int,int,short,const AcCmColor&);
    virtual Acad::ErrorStatus setGridLineWeight(AcDb::LineWeight,int,int);
    virtual Acad::ErrorStatus setGridLineWeight(int,int,short,AcDb::LineWeight);
    virtual Acad::ErrorStatus setGridVisibility(AcDb::Visibility,int,int);
    virtual Acad::ErrorStatus setGridVisibility(int,int,short,AcDb::Visibility);
    virtual Acad::ErrorStatus setHeight(double);
    virtual Acad::ErrorStatus setHorzCellMargin(double);
    virtual Acad::ErrorStatus setNormal(const AcGeVector3d&);
    virtual Acad::ErrorStatus setNumColumns(int);
    virtual Acad::ErrorStatus setNumRows(int);
    virtual Acad::ErrorStatus setPosition(const AcGePoint3d&);
    virtual Acad::ErrorStatus setRowHeight(double);
    virtual Acad::ErrorStatus setRowHeight(int,double);
    virtual Acad::ErrorStatus setSubSelection(int,int,int,int);
    virtual Acad::ErrorStatus setTableStyle(const AcDbObjectId&);
    virtual Acad::ErrorStatus setTextHeight(double,int = AcDb::kAllRows);
    virtual Acad::ErrorStatus setTextHeight(int,int,double);
    virtual Acad::ErrorStatus setTextRotation(int,int,AcDb::RotationAngle);
    virtual Acad::ErrorStatus setTextString(int,int,const ACHAR*);
    virtual Acad::ErrorStatus setTextStyle(const AcDbObjectId&,int = AcDb::kAllRows);
    virtual Acad::ErrorStatus setTextStyle(int,int,const AcDbObjectId&);
    virtual Acad::ErrorStatus setVertCellMargin(double);
    virtual Acad::ErrorStatus setWidth(double);
    virtual Acad::ErrorStatus subClose();
    virtual Acad::ErrorStatus suppressHeaderRow(bool);
    virtual Acad::ErrorStatus suppressTitleRow(bool);
    virtual Acad::ErrorStatus unmergeCells(int,int,int,int);
    virtual AcCmColor backgroundColor(AcDb::RowType = AcDb::kDataRow) const;
    virtual AcCmColor backgroundColor(int,int) const;
    virtual AcCmColor contentColor(AcDb::RowType = AcDb::kDataRow) const;
    virtual AcCmColor contentColor(int,int) const;
    virtual AcCmColor gridColor(AcDb::GridLineType,AcDb::RowType = AcDb::kDataRow) const;
    virtual AcCmColor gridColor(int,int,AcDb::CellEdgeMask) const;
    virtual AcDb::CellAlignment alignment(AcDb::RowType = AcDb::kDataRow) const;
    virtual AcDb::CellAlignment alignment(int,int) const;
    virtual AcDb::CellType cellType(int,int) const;
    virtual AcDb::FlowDirection flowDirection() const;
    virtual AcDb::LineWeight gridLineWeight(AcDb::GridLineType,AcDb::RowType = AcDb::kDataRow) const;
    virtual AcDb::LineWeight gridLineWeight(int,int,AcDb::CellEdgeMask) const;
    virtual AcDb::RotationAngle textRotation(int,int) const;
    virtual AcDb::RowType rowType(int) const;
    virtual AcDb::Visibility gridVisibility(AcDb::GridLineType,AcDb::RowType = AcDb::kDataRow) const;
    virtual AcDb::Visibility gridVisibility(int,int,AcDb::CellEdgeMask) const;
    virtual AcDbObjectId blockTableRecordId(int,int) const;
    virtual AcDbObjectId fieldId(int,int) const;
    virtual AcDbObjectId tableStyle() const;
    virtual AcDbObjectId textStyle(AcDb::RowType = AcDb::kDataRow) const;
    virtual AcDbObjectId textStyle(int,int) const;
    virtual AcGePoint3d attachmentPoint(int,int) const;
    virtual AcGeVector3d direction() const;
    virtual ACHAR* textString(int,int) const;
    virtual Adesk::UInt32 numColumns() const;
    virtual Adesk::UInt32 numRows() const;
    virtual bool castShadows() const;
    virtual bool cellStyleOverrides(int,int,AcDbIntArray&) const;
    virtual bool hasSubSelection() const;
    virtual bool hitTest(const AcGePoint3d&,const AcGeVector3d&,double,double,int&,int&);
    virtual bool isAutoScale(int,int) const;
    virtual bool isBackgroundColorNone(AcDb::RowType = AcDb::kDataRow) const;
    virtual bool isBackgroundColorNone(int,int) const;
    virtual bool isHeaderSuppressed() const;
    virtual bool isMergedCell(int,int,int* = NULL,int* = NULL,int* = NULL,int* = NULL) const;
    virtual bool isTitleSuppressed() const;
    virtual bool receiveShadows() const;
    virtual bool reselectSubRegion(AcDbFullSubentPathArray&) const;
    virtual bool tableStyleOverrides(AcDbIntArray&) const;
    virtual const ACHAR* textStringConst(int,int) const;
    virtual double blockRotation(int,int) const;
    virtual double blockScale(int,int) const;
    virtual double columnWidth(int) const;
    virtual double height() const;
    virtual double horzCellMargin() const;
    virtual double minimumColumnWidth(int) const;
    virtual double minimumRowHeight(int) const;
    virtual double minimumTableHeight() const;
    virtual double minimumTableWidth() const;
    virtual double rowHeight(int) const;
    virtual double textHeight(AcDb::RowType = AcDb::kDataRow) const;
    virtual double textHeight(int,int) const;
    virtual double vertCellMargin() const;
    virtual double width() const;
    virtual void clearSubSelection();
    virtual void clearTableStyleOverrides(int = 0);
    virtual void erased(const AcDbObject*,Adesk::Boolean);
    virtual void objectClosed(const AcDbObjectId);
    virtual void setCastShadows(bool);
    virtual void setReceiveShadows(bool);

    Acad::ErrorStatus setValue(int,int,const AcValue&);
    bool isRegenerateTableSuppressed() const;
    void clearCellOverrides(int,int);
    void suppressRegenerateTable(bool);

    //V10
    virtual Acad::ErrorStatus getCellExtents(int,int,double&,double&,bool) const;
    virtual Acad::ErrorStatus getDataType(AcValue::DataType&,AcValue::UnitType&,AcDb::RowType) const;
    virtual Acad::ErrorStatus select_next_cell(int,int&,int&,AcDbFullSubentPathArray* = NULL,bool = true) const;
    virtual Acad::ErrorStatus setDataType(AcValue::DataType,AcValue::UnitType);
    virtual Acad::ErrorStatus setDataType(AcValue::DataType,AcValue::UnitType,int);
    virtual Acad::ErrorStatus setFieldId(int,int,const AcDbObjectId&,AcDb::CellOption);
    virtual Acad::ErrorStatus setFormat(const ACHAR*);
    virtual Acad::ErrorStatus setFormat(const ACHAR*,int);
    virtual Acad::ErrorStatus textString(int,int,AcValue::FormatOption,AcString&) const;
    virtual const ACHAR* format(AcDb::RowType);
    virtual void setRegen();
    virtual void suppressInvisibleGrid(bool);

    Acad::ErrorStatus getDataType(int,int,AcValue::DataType&,AcValue::UnitType&) const;
    Acad::ErrorStatus resetValue(int,int);
    Acad::ErrorStatus setDataType(int,int,AcValue::DataType,AcValue::UnitType);
    Acad::ErrorStatus setFormat(int,int,const ACHAR*);
    Acad::ErrorStatus setValue(int,int,LPCTSTR,AcValue::ParseOption);
    AcValue value(int,int) const;
    const ACHAR* format(int,int) const;

    //V12
    Acad::ErrorStatus setSize(int,int);
    Acad::ErrorStatus setCellStyle(int,int,const ACHAR*);
    const ACHAR* cellStyle(int,int) const;

    // V14.2
    int getCustomData(int, int) const;
    Acad::ErrorStatus getCustomData(int, int, const ACHAR*, AcValue*) const;
    Acad::ErrorStatus setCustomData(int, int, int);
    Acad::ErrorStatus setCustomData(int, int, const ACHAR*, const AcValue*);

    virtual Acad::ErrorStatus copyFrom(const AcRxObject*); // temporary

    Acad::ErrorStatus setTextString(int, int, int, const ACHAR*);
    Acad::ErrorStatus setGridLineWeight(int, int, AcDb::GridLineType, AcDb::LineWeight);
    AcDb::LineWeight gridLineWeight(int, int, AcDb::GridLineType);

    AcDb::Visibility gridVisibility(int, int, AcDb::GridLineType) const;
    Acad::ErrorStatus setGridVisibility(int,int, AcDb::GridLineType, AcDb::Visibility);

    AcCmColor contentColor(int, int, int) const;
    Acad::ErrorStatus setContentColor(int, int, int, const AcCmColor&);

    Acad::ErrorStatus getDataType(int, int, int, AcValue::DataType&, AcValue::UnitType&) const;
    Acad::ErrorStatus setDataType(int, int, int, AcValue::DataType,  AcValue::UnitType);

    AcDbObjectId textStyle(int, int, int) const;
    Acad::ErrorStatus setTextStyle(int, int, int, const AcDbObjectId&);

    double textHeight(int, int, int) const;
    Acad::ErrorStatus setTextHeight(int, int, int, double);

    AcCmColor gridColor(int, int, AcDb::GridLineType) const;
    Acad::ErrorStatus setGridColor(int, int, AcDb::GridLineType, const AcCmColor&);

    AcGePoint3d attachmentPoint(int, int, int) const;

    AcValue value(int, int, int) const;
    AcValue value(int, int, int, AcValue::FormatOption) const;

    Acad::ErrorStatus setValue(int, int, int, const AcValue&);
    Acad::ErrorStatus setValue(int, int, int, const AcValue&, AcValue::ParseOption);
    Acad::ErrorStatus setValue(int, int, int, LPCTSTR, AcValue::ParseOption);

    AcString textString(int, int, int) const;
    Acad::ErrorStatus textString(int, int, int, AcValue::FormatOption, AcString&) const;

    AcDbObjectId fieldId(int, int, int) const;
    Acad::ErrorStatus setFieldId(int, int, int, const AcDbObjectId&, AcDb::CellOption);

    AcDbObjectId blockTableRecordId(int, int, int) const;
    Acad::ErrorStatus setBlockTableRecordId(int, int, int, const AcDbObjectId&, bool);

    Acad::ErrorStatus getBlockAttributeValue(int, int, int, const AcDbObjectId&, ACHAR*&) const;
    Acad::ErrorStatus setBlockAttributeValue(int, int, int, const AcDbObjectId&, const ACHAR*);

    bool hitTest(const AcGePoint3d&, const AcGeVector3d&, double, double, int&, int&, int&, AcDb::TableHitItem&);
    AcCellRange getSubSelection() const;
    Acad::ErrorStatus setSubSelection(const AcCellRange&);

    bool canDelete(int, int, bool) const;
    bool canInsert(int, bool) const;    
    bool isEmpty(int, int) const;
    bool isFormatEditable(int, int) const;
    bool isContentEditable(int, int) const;    

    AcDb::CellState cellState(int, int) const;
    Acad::ErrorStatus setCellState(int, int, AcDb::CellState);

    Acad::ErrorStatus insertRowsAndInherit(int, int, int);
    Acad::ErrorStatus insertColumnsAndInherit(int, int, int);

    AcCellRange getMergeRange(int, int) const;
    AcDbTableIterator* getIterator() const;
    AcDbTableIterator* getIterator(const AcCellRange*, AcDb::TableIteratorOption) const;

    AcDb::CellContentType contentType(int, int) const;
    AcDb::CellContentType contentType(int, int, int) const;

    int numContents(int, int) const;
    int createContent(int, int, int);
    Acad::ErrorStatus moveContent(int, int, int, int);

    Acad::ErrorStatus deleteContent(int, int);
    Acad::ErrorStatus deleteContent(int, int, int);
    Acad::ErrorStatus deleteContent(const AcCellRange&);

    AcString dataFormat(int, int) const;
    AcString dataFormat(int, int, int) const;
    Acad::ErrorStatus setDataFormat(int, int, const ACHAR*);
    Acad::ErrorStatus setDataFormat(int, int, int nContent, const ACHAR*);

    bool hasFormula(int, int, int) const;
    Acad::ErrorStatus setFormula(int, int, int, const ACHAR*);
    AcString getFormula(int, int, int) const;

    double margin(int, int, AcDb::CellMargin) const;
    Acad::ErrorStatus setMargin(int, int, AcDb::CellMargin, double);

    double rotation() const;
    double rotation(int, int, int) const;
    Acad::ErrorStatus setRotation(double);
    Acad::ErrorStatus setRotation(int, int, int, double);

    bool isAutoScale(int, int, int) const;
    Acad::ErrorStatus setAutoScale(int, int, int, bool);

    double scale(int, int, int) const;
    Acad::ErrorStatus setScale(int, int, int, double);

    AcDb::CellContentLayout contentLayout(int, int) const;
    Acad::ErrorStatus setContentLayout(int, int, AcDb::CellContentLayout);

    bool isMergeAllEnabled(int, int) const;
    Acad::ErrorStatus enableMergeAll(int, int, bool);

    AcDb::CellProperty getOverride(int, int, int) const;
    AcDb::GridProperty getOverride(int, int, AcDb::GridLineType) const;
    Acad::ErrorStatus setOverride(int, int, int, AcDb::CellProperty);
    Acad::ErrorStatus setOverride(int, int, AcDb::GridLineType, AcDb::GridProperty);
    Acad::ErrorStatus removeAllOverrides(int, int);

    AcDb::GridLineStyle gridLineStyle(int, int, AcDb::GridLineType) const;
    Acad::ErrorStatus setGridLineStyle(int, int, AcDb::GridLineType, AcDb::GridLineStyle);

    AcDbObjectId gridLinetype(int, int, AcDb::GridLineType) const;
    Acad::ErrorStatus setGridLinetype(int, int, AcDb::GridLineType, const AcDbObjectId&);

    double gridDoubleLineSpacing(int, int, AcDb::GridLineType) const;
    Acad::ErrorStatus setGridDoubleLineSpacing(int, int, AcDb::GridLineType, double);

    Acad::ErrorStatus getGridProperty(int, int, AcDb::GridLineType, AcGridProperty&) const;
    Acad::ErrorStatus setGridProperty(int, int, AcDb::GridLineType, const AcGridProperty&);
    Acad::ErrorStatus setGridProperty(const AcCellRange&, AcDb::GridLineType, const AcGridProperty&);

    bool isLinked(int, int) const;
    int getDataLink(const AcCellRange*, AcDbObjectIdArray&) const;
    AcDbObjectId getDataLink(int, int) const;
    Acad::ErrorStatus getDataLink(int, int, AcDbDataLink*&, AcDb::OpenMode) const;
    AcCellRange getDataLinkRange(int, int) const;

    Acad::ErrorStatus setDataLink(const AcCellRange&, const AcDbObjectId&, bool);
    Acad::ErrorStatus setDataLink(int, int, const AcDbObjectId&, bool);
    Acad::ErrorStatus removeDataLink();
    Acad::ErrorStatus removeDataLink(int, int);    
    Acad::ErrorStatus updateDataLink(int, int, AcDb::UpdateDirection, AcDb::UpdateOption);
    Acad::ErrorStatus updateDataLink(AcDb::UpdateDirection, AcDb::UpdateOption);

    AcCellRange cellRange() const;
    Acad::ErrorStatus fill(const AcCellRange&, const AcCellRange&, AcDb::TableFillOption);

    Acad::ErrorStatus copyFrom(const AcDbLinkedTableData*, AcDb::TableCopyOption);
    Acad::ErrorStatus copyFrom(const AcDbLinkedTableData*, AcDb::TableCopyOption, const AcCellRange&, const AcCellRange&, AcCellRange*);
    Acad::ErrorStatus copyFrom(const AcDbTable*, AcDb::TableCopyOption, const AcCellRange&, const AcCellRange&, AcCellRange*);

    Acad::ErrorStatus enableBreak(bool);
    bool isBreakEnabled() const;
    double breakSpacing() const;
    Acad::ErrorStatus setBreakSpacing(double);
    double breakHeight(int) const;
    Acad::ErrorStatus setBreakHeight(int, double);
    AcGeVector3d breakOffset(int) const;
    Acad::ErrorStatus setBreakOffset(int, const AcGeVector3d&);
    AcDb::TableBreakFlowDirection breakFlowDirection() const;
    Acad::ErrorStatus setBreakFlowDirection(AcDb::TableBreakFlowDirection);
    AcDb::TableBreakOption breakOption() const;
    Acad::ErrorStatus setBreakOption(AcDb::TableBreakOption);

    AcString getToolTip(int, int) const;
    Acad::ErrorStatus setToolTip(int, int, const ACHAR*);

    const ACHAR* getColumnName(int) const;
    Acad::ErrorStatus setColumnName(int, const ACHAR*);

    Acad::ErrorStatus createTemplate(AcDbTableTemplate*&, AcDb::TableCopyOption);
    Acad::ErrorStatus getIndicatorSize(double&, double&) const;

protected:
    virtual Acad::ErrorStatus subExplode(AcDbVoidPtrArray&) const;
    virtual Acad::ErrorStatus subGetGeomExtents(AcDbExtents&) const;
    virtual Acad::ErrorStatus subGetGripPoints(AcGePoint3dArray&,AcDbIntArray&,AcDbIntArray&) const;
    virtual Acad::ErrorStatus subGetOsnapPoints(AcDb::OsnapMode,Adesk::GsMarker,const AcGePoint3d&,const AcGePoint3d&,const AcGeMatrix3d&,AcGePoint3dArray&,AcDbIntArray&) const;
    virtual Acad::ErrorStatus subGetStretchPoints(AcGePoint3dArray&) const;
    virtual Acad::ErrorStatus subGetTransformedCopy(const AcGeMatrix3d&,AcDbEntity*&) const;
    virtual void subList() const;
    virtual Acad::ErrorStatus subMoveGripPointsAt(const AcDbIntArray&,const AcGeVector3d&);
    virtual Acad::ErrorStatus subMoveStretchPointsAt(const AcDbIntArray&,const AcGeVector3d&);
    virtual Acad::ErrorStatus subTransformBy(const AcGeMatrix3d&);
    virtual Adesk::Boolean subWorldDraw(AcGiWorldDraw*);
};
