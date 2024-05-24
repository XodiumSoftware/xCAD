// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbLinkedTableData.h"
#include "Misc/AcGridProperty.h"

class BRX_IMPORTEXPORT AcDbFormattedTableData : public AcDbLinkedTableData
{
public:
    ACDB_DECLARE_MEMBERS(AcDbFormattedTableData);

    AcDbFormattedTableData();
    ~AcDbFormattedTableData();

    virtual AcDb::CellAlignment alignment(int, int) const;
    virtual AcCmColor backgroundColor(int, int) const;

    virtual AcCmColor contentColor(int, int) const;
    virtual AcCmColor contentColor(int, int, int) const;

    virtual AcDb::CellContentLayout contentLayout(int, int);
    virtual Acad::ErrorStatus enableMergeAll(int, int, bool);
    virtual AcDb::FlowDirection flowDirection() const;
    virtual Acad::ErrorStatus getGridProperty(int, int, AcDb::GridLineType, AcGridProperty&) const;
    virtual AcCellRange getMergeRange(int, int) const;

    virtual AcDb::GridProperty getOverride(int, int, AcDb::GridLineType) const;
    virtual AcDb::CellProperty getOverride(int, int, int) const;

    virtual AcCmColor gridColor(int, int, AcDb::GridLineType) const;
    virtual double gridDoubleLineSpacing(int, int, AcDb::GridLineType) const;
    virtual AcDb::GridLineStyle gridLineStyle(int, int, AcDb::GridLineType) const;
    virtual AcDbObjectId gridLinetype(int, int, AcDb::GridLineType) const;
    virtual AcDb::LineWeight gridLineWeight(int, int, AcDb::GridLineType) const;
    virtual AcDb::Visibility gridVisibility(int, int, AcDb::GridLineType) const;
    
    virtual int insertColumnAndInherit(int, int, int);
    virtual int insertRowAndInherit(int, int, int);

    virtual bool isAutoScale(int, int) const;
    virtual bool isAutoScale(int, int, int) const;

    virtual bool isFormatEditable(int, int) const;
    virtual bool isMergeAllEnabled(int, int) const;
    virtual bool isMerged(int, int) const;
    virtual double margin(int, int, AcDb::CellMargin) const;
    virtual Acad::ErrorStatus merge(const AcCellRange&);
    virtual Acad::ErrorStatus removeAllOverrides(int, int);

    virtual double rotation(int, int) const;
    virtual double rotation(int, int, int) const;

    virtual double scale(int, int) const;
    virtual double scale(int, int, int) const;

    virtual Acad::ErrorStatus setAlignment(int, int, AcDb::CellAlignment);

    virtual Acad::ErrorStatus setAutoScale(int, int, bool);
    virtual Acad::ErrorStatus setAutoScale(int, int, int, bool);

    virtual Acad::ErrorStatus setBackgroundColor(int, int, const AcCmColor&);
    
    virtual Acad::ErrorStatus setContentColor(int, int, const AcCmColor&);
    virtual Acad::ErrorStatus setContentColor(int, int, int, const AcCmColor&);

    virtual Acad::ErrorStatus setContentLayout(int, int, AcDb::CellContentLayout);

    virtual Acad::ErrorStatus setFieldId(int, int, const AcDbObjectId&, AcDb::CellOption);
    virtual Acad::ErrorStatus setFieldId(int, int, int, const AcDbObjectId&, AcDb::CellOption);

    virtual Acad::ErrorStatus setFlowDirection(AcDb::FlowDirection);
    virtual Acad::ErrorStatus setGridColor(int, int, AcDb::GridLineType, const AcCmColor&);
    virtual Acad::ErrorStatus setGridDoubleLineSpacing(int, int, AcDb::GridLineType, double);
    virtual Acad::ErrorStatus setGridLineStyle(int, int, AcDb::GridLineType, AcDb::GridLineStyle);
    virtual Acad::ErrorStatus setGridLinetype(int, int, AcDb::GridLineType, const AcDbObjectId&);
    virtual Acad::ErrorStatus setGridLineWeight(int, int, AcDb::GridLineType, AcDb::LineWeight);

    virtual Acad::ErrorStatus setGridProperty(const AcCellRange&, AcDb::GridLineType, const AcGridProperty&);
    virtual Acad::ErrorStatus setGridProperty(int, int, AcDb::GridLineType, const AcGridProperty&);

    virtual Acad::ErrorStatus setGridVisibility(int, int, AcDb::GridLineType, AcDb::Visibility);
    virtual Acad::ErrorStatus setMargin(int, int, AcDb::CellMargin, double);

    virtual Acad::ErrorStatus setOverride(int, int, AcDb::GridLineType, AcDb::GridProperty);
    virtual Acad::ErrorStatus setOverride(int, int, int, AcDb::CellProperty);

    virtual Acad::ErrorStatus setRotation(int, int, double);
    virtual Acad::ErrorStatus setRotation(int, int, int, double);

    virtual Acad::ErrorStatus setScale(int, int, double);
    virtual Acad::ErrorStatus setScale(int, int, int, double);

    virtual Acad::ErrorStatus setTextHeight(int, int, double);
    virtual Acad::ErrorStatus setTextHeight(int, int, int, double);

    virtual Acad::ErrorStatus setTextStyle(int, int, const AcDbObjectId&);
    virtual Acad::ErrorStatus setTextStyle(int, int, int, const AcDbObjectId&);

    virtual double textHeight(int, int) const;
    virtual double textHeight(int, int, int) const;

    virtual AcDbObjectId textStyle(int, int) const;
    virtual AcDbObjectId textStyle(int, int, int) const;

    virtual Acad::ErrorStatus unmerge(const AcCellRange&);
};