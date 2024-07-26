// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDbObject.h"
#include "AcDb/AcDbGlobal.h"
#include "AcDb/AcDbLinkedData.h"
#include "AcDb/AcDbTableIterator.h"

class BRX_IMPORTEXPORT AcDbLinkedTableData : public AcDbLinkedData
{
public:
    ACDB_DECLARE_MEMBERS(AcDbLinkedTableData);

    AcDbLinkedTableData();
    ~AcDbLinkedTableData();

    Acad::ErrorStatus dwgInFields(AcDbDwgFiler*) override;
    Acad::ErrorStatus dwgOutFields(AcDbDwgFiler*) const override;
    Acad::ErrorStatus dxfInFields(AcDbDxfFiler*) override;
    Acad::ErrorStatus dxfOutFields(AcDbDxfFiler*) const override;

    Acad::ErrorStatus clear() override;
    AcDbTableIterator* getIterator() const;
    AcDbTableIterator* getIterator(const AcCellRange*, AcDb::TableIteratorOption) const;

    virtual Acad::ErrorStatus copyFrom(const AcDbLinkedTableData*, AcDb::TableCopyOption, const AcCellRange&, const AcCellRange&, AcCellRange*);
    virtual Acad::ErrorStatus copyFrom(const AcDbLinkedTableData*, AcDb::TableCopyOption);
    virtual Acad::ErrorStatus setSize(int, int);
    virtual Acad::ErrorStatus setColumnName(int, const ACHAR*);
    virtual Acad::ErrorStatus deleteColumn(int, int);
    virtual Acad::ErrorStatus deleteRow(int, int);
    virtual Acad::ErrorStatus setCellState(int, int, AcDb::CellState);
    virtual Acad::ErrorStatus setToolTip(int, int, const ACHAR*);
    virtual Acad::ErrorStatus setCustomData(int, int, int);
    virtual Acad::ErrorStatus getCustomData(int, int, const ACHAR*, AcValue*) const;
    virtual Acad::ErrorStatus setCustomData(int, int, const ACHAR*, const AcValue*);
    virtual Acad::ErrorStatus removeDataLink(int, int);
    virtual Acad::ErrorStatus removeDataLink();
    virtual Acad::ErrorStatus updateDataLink(int, int, AcDb::UpdateDirection, AcDb::UpdateOption);
    virtual Acad::ErrorStatus updateDataLink(AcDb::UpdateDirection, AcDb::UpdateOption);
    virtual Acad::ErrorStatus setDataLink(int, int, const AcDbObjectId&, bool);
    virtual Acad::ErrorStatus setDataLink(const AcCellRange&, const AcDbObjectId&, bool);
    virtual Acad::ErrorStatus moveContent(int, int, int, int);
    virtual Acad::ErrorStatus deleteContent(int, int, int);
    virtual Acad::ErrorStatus deleteContent(int, int);
    virtual Acad::ErrorStatus deleteContent(const AcCellRange&);
    virtual Acad::ErrorStatus getDataType(int, int, AcValue::DataType&, AcValue::UnitType&) const;
    virtual Acad::ErrorStatus getDataType(int, int, int, AcValue::DataType&, AcValue::UnitType&) const;
    virtual Acad::ErrorStatus setDataType(int, int, AcValue::DataType, AcValue::UnitType);
    virtual Acad::ErrorStatus setDataType(int, int, int, AcValue::DataType, AcValue::UnitType);
    virtual Acad::ErrorStatus setDataFormat(int, int, const ACHAR*);
    virtual Acad::ErrorStatus setDataFormat(int, int, int, const ACHAR*);
    virtual Acad::ErrorStatus getValue(int, int, AcValue&) const;
    virtual Acad::ErrorStatus getValue(int, int, int, AcValue::FormatOption, AcValue&) const;
    virtual Acad::ErrorStatus setValue(int, int, const AcValue&);
    virtual Acad::ErrorStatus setValue(int, int, int, const AcValue&);
    virtual Acad::ErrorStatus setValue(int, int, int, const AcValue&, AcValue::ParseOption);
    virtual Acad::ErrorStatus getDataLink(int, int, AcDbDataLink*&, AcDb::OpenMode) const;
    virtual Acad::ErrorStatus setText(int, int, const ACHAR*);
    virtual Acad::ErrorStatus setText(int, int, int, const ACHAR*);
    virtual Acad::ErrorStatus setFormula(int, int, int, const ACHAR*);
    virtual Acad::ErrorStatus setFieldId(int, int, const AcDbObjectId&);
    virtual Acad::ErrorStatus setFieldId(int, int, int, const AcDbObjectId&);
    virtual Acad::ErrorStatus getField(int, int, int, AcDbField*&, AcDb::OpenMode) const;
    virtual Acad::ErrorStatus setBlockTableRecordId(int, int, const AcDbObjectId&);
    virtual Acad::ErrorStatus setBlockTableRecordId(int, int, int, const AcDbObjectId&);
    virtual Acad::ErrorStatus setBlockAttributeValue(int, int, const AcDbObjectId&, const ACHAR*);
    virtual Acad::ErrorStatus setBlockAttributeValue(int, int, int, const AcDbObjectId&, const ACHAR*);
    virtual Acad::ErrorStatus evaluateFormula();

    virtual int numColumns() const;
    virtual int appendColumn(int);
    virtual int insertColumn(int, int);
    virtual int numRows(void) const;
    virtual int appendRow(int);
    virtual int insertRow(int, int);
    virtual int getCustomData(int, int) const;
    virtual int getDataLink(const AcCellRange*, AcDbObjectIdArray&) const;
    virtual int numContents(int, int) const;
    virtual int createContent(int, int, int);

    virtual bool canInsert(int, bool) const;
    virtual bool canDelete(int, int, bool) const;
    virtual bool isContentEditable(int, int) const;
    virtual bool isLinked(int, int) const;
    virtual bool hasFormula(int, int, int) const;

    virtual AcString getToolTip(int, int) const;
    virtual AcString dataFormat(int, int) const;
    virtual AcString dataFormat(int, int, int) const;
    virtual AcString getText(int, int) const;
    virtual AcString getText(int, int, int) const;
    virtual AcString getText(int, int, int, AcValue::FormatOption) const;
    virtual AcString getFormula(int, int, int) const;
    virtual AcString getBlockAttributeValue(int, int, const AcDbObjectId&) const;
    virtual AcString getBlockAttributeValue(int, int, int, const AcDbObjectId&) const;
    
    virtual const ACHAR* getColumnName(int) const;
    
    virtual AcDbObjectId getDataLink(int, int) const;
    virtual AcDbObjectId getFieldId(int, int) const;
    virtual AcDbObjectId getFieldId(int, int, int) const;
    virtual AcDbObjectId getBlockTableRecordId(int, int) const;
    virtual AcDbObjectId getBlockTableRecordId(int, int, int) const;

    virtual AcDb::CellState cellState(int, int) const;

    virtual AcCellRange getDataLinkRange(int, int) const;

    virtual AcDb::CellContentType contentType(int, int) const;
    virtual AcDb::CellContentType contentType(int, int, int) const;
};
