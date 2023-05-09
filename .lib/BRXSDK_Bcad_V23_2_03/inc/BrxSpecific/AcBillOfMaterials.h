// Declares the high-level Bill of materials API

// Property of Bricsys NV. All rights reserved.
// This file is part of the source code of Bricsys NV. The source code
// is subject to copyright, is a trade secret of Bricsys NV, and contains
// embodiments of inventions disclosed in patent applications and patents
// of Bricsys NV.

/////////////////////////////////////////////////////////////////////////

#pragma once

#ifndef _AcBillOfMaterials_h_Included
#define _AcBillOfMaterials_h_Included

#include "brx_importexport.h"
#include "Misc/MiscGlobal.h"
#include "AcDb/AcDbObjectId.h"

class BrxBomValueImp;
class BrxBomValue;

class BrxBomContentImp;
class BrxBomContent;

class BrxBillOfMaterialsImp;
class BrxBillOfMaterials;
typedef AcArray<BrxBillOfMaterials, AcArrayObjectCopyReallocator<BrxBillOfMaterials>> BrxBillOfMaterialsArray;


// Enum Definition

enum class BrxBomContentType
{
    kInternal = 0,  // to extract internal hierarchical structure of the corresponding BOM table
    kFormatted = 1, // to extract flat table with cell values formatted as in BOM Manager
};

enum class BrxBomTableType
{
    kTopLevel = 0,     // Computes leaves of assembly tree
    kBottomLevel = 1,  // Computes occurrences of direct children
    kHierarchical = 2, // Computes all levels with hierarchy
    kUnknown = 3,
};

class BRX_IMPORTEXPORT BrxBomValue
{
public:
    BrxBomValue();
    BrxBomValue(const BrxBomValue& other);
    virtual BrxBomValue& operator=(const BrxBomValue& other);
    virtual ~BrxBomValue();

    // verifies whether this BrxBomValue (or derived) instance is empty
    virtual bool isNull() const;

    // sets this BrxBomValue instance (or derived) to be empty
    virtual void setNull();

    // returns a value
    virtual AcValue value() const;

    // returns a file path of the image
    virtual AcString imagePath() const;

    // returns the current unit, the @value is calculated based on it
    virtual AcString unit() const;

    // units which can be applied to the BOM table cell
    virtual AcStringArray supportedUnits() const;

    // returns false if the unit is not supported
    virtual bool convertTo(AcString unit, AcValue& value) const;

    friend class BrxBomContent;

private:
    BrxBomValueImp* m_pBrxImp = nullptr;
};

class BRX_IMPORTEXPORT BrxBomContent
{
public:
    BrxBomContent();
    BrxBomContent(const BrxBomContent& other);
    virtual BrxBomContent& operator=(const BrxBomContent& other);
    virtual ~BrxBomContent();

    // verifies whether this BrxBomContent (or derived) instance is empty
    virtual bool isNull() const;

    // sets this BrxBomContent instance (or derived) to be empty
    virtual void setNull();

    // returns status of this content, if status is eHasErrors content cannot be used
    virtual Acad::ErrorStatus status() const;

    // returns the number of rows with data, excluding a footer row
    virtual unsigned nbDataRows() const;

    // returns the number of columns
    virtual unsigned nbCols() const;

    // returns if the table has a title row
    virtual bool hasTitle() const;

    // returns if the table has a header row
    virtual bool hasHeader() const;

    // returns if the table has a footer row
    virtual bool hasFooter() const;

    // returns the column title
    virtual AcString columnTitle(int index, bool localized = false) const;

    // returns if a cell contains a thumbnail image
    virtual bool hasImage(int row, int column) const;

    // returns the value of a cell
    virtual BrxBomValue cellValue(int row, int column) const;

    // returns paths to entities corresponding to that row
    virtual AcDbFullSubentPathArray rowEntities(int row) const;

    // returns the footer title
    virtual AcString footerTitle() const;

    // returns the value of the footer
    virtual BrxBomValue footerValue(int column) const;

    // returns the child content for that row, or default (empty content) if no such child content exists
    virtual BrxBomContent getRowChildContent(int row) const;

    friend class BrxBillOfMaterials;

private:
    BrxBomContentImp* m_pBrxImp = nullptr;
};

enum class BrxBomColumnType
{
    kUndefined = 0,
    kNumber,
    kName,
    kQuantity,
    kLevel,
    kThumbnails,
    kFormula,
    kTemplate,
    kParameters,
    kProperty
};

enum class BrxBomThumbnailView
{
    kFront = 0,
    kRear,
    kLeft,
    kRight,
    kTop,
    kBottom,
    kTopBackLeft,
    kTopBackRight,
    kTopFrontLeft,
    kTopFrontRight,
    kDownBackLeft,
    kDownBackRight,
    kDownFrontLeft,
    kDownFrontRight,
    kCustom
};

// this class provides information about BOM column: internal identifier, localized and global (non-localized) name and
// category
class BRX_IMPORTEXPORT BrxBomColumn
{
    friend BrxBillOfMaterials;

public:
    BrxBomColumn();
    BrxBomColumn(const BrxBomColumn&);
    BrxBomColumn& operator=(const BrxBomColumn&);
    ~BrxBomColumn();

    // verifies whether this BrxBomColumn (or derived) instance is empty
    bool isNull() const;

    // returns internal identifier
    AcString id() const;

    // returns column name (localized name if @localized is true, global otherwise)
    AcString name(bool localized = false) const;

    // returns category name (localized name if @localized is true, global otherwise)
    AcString category(bool localized = false) const;

    // returns type of this column
    BrxBomColumnType type() const;

private:
    class BrxBomColumnImp;
    BrxBomColumnImp* m_pBrxImp;
};

using BrxBomColumns = AcArray<BrxBomColumn, AcArrayObjectCopyReallocator<BrxBomColumn>>;

// Bill of Materials

class BRX_IMPORTEXPORT BrxBillOfMaterials
{
public:
    BrxBillOfMaterials();
    BrxBillOfMaterials(const BrxBillOfMaterials& other);
    virtual BrxBillOfMaterials& operator=(const BrxBillOfMaterials& other);
    virtual ~BrxBillOfMaterials();

    // verifies whether this BrxBillOfMaterials (or derived) instance is empty
    virtual bool isNull() const;

    // sets this BrxBillOfMaterials instance (or derived) to be empty
    virtual void setNull();

    // returns the UID (identificator) of the table
    virtual AcString uid() const;

    // returns the title of the BrxBillOfMaterials object
    virtual AcString title() const;

    // returns type of the table
    virtual BrxBomTableType type() const;

    // returns Bill of materials table template (configuration)
    virtual AcString configuration() const;

    // removes the table and all associated tables
    virtual Acad::ErrorStatus erase();

    // sets new title for the table
    virtual Acad::ErrorStatus setTitle(const ACHAR* title);

    // changes the configuration of the table
    virtual Acad::ErrorStatus setConfiguration(const ACHAR* newConfig);

    // returns the list of associated tables
    virtual AcDbObjectIdArray associatedTables() const;

    // constructs the BOM content object
    virtual Acad::ErrorStatus getContent(BrxBomContent& bomData, BrxBomContentType contentType, const ACHAR* targetPathForThumbnails = nullptr) const;

    // exports table's content to csv or xlsx file
    virtual Acad::ErrorStatus exportContent(const ACHAR* path, const ACHAR delimiter = ';');

    // links and updates given table
    virtual Acad::ErrorStatus linkWithTable(const AcDbObjectId& tableId);

    // unlinks given associated table - this table will remain in the document but will no longer be updated
    virtual Acad::ErrorStatus unlinkTable(const AcDbObjectId& tableId);

    // removes given associated table from the document
    virtual Acad::ErrorStatus removeTable(const AcDbObjectId& tableId);

    // Applies collected changes
    virtual Acad::ErrorStatus save();

    // Saves and updates all associated tables
    virtual Acad::ErrorStatus updateAll();

    // retrieves list of all the available BOM columns related to the existing properties (including columns they have
    // already been added)
    virtual BrxBomColumns availableColumns() const;

    // retrieves list of all the columns added to BOM
    virtual BrxBomColumns addedColumns() const;

    // adds a new column to BOM. It is assumed that the passed argument is one of the available columns
    virtual Acad::ErrorStatus addColumn(const BrxBomColumn& column);

    // removes a column from BOM
    virtual Acad::ErrorStatus removeColumn(const BrxBomColumn& column);

    // adds a new formula column to BOM
    virtual Acad::ErrorStatus addFormulaColumn(const ACHAR* columnName, const ACHAR* expression);

    // adds a new template column to BOM
    virtual Acad::ErrorStatus addTemplateColumn(const ACHAR* columnName, const ACHAR* expression);

    // adds a new thumbnails column to BOM
    virtual Acad::ErrorStatus addThumbnailsColumn(const ACHAR* columnName,
                                                  BrxBomThumbnailView viewType,
                                                  int width,
                                                  int height,
                                                  const ACHAR* visualStyle = ACRX_T(""),
                                                  int rgbColor = -1,
                                                  double blockScale = 1.0);

    // returns a Bill of materials table by its id
    static BrxBillOfMaterials getBillOfMaterials(AcDbDatabase* pDb, const ACHAR* uid);

    // returns all Bill of materials tables in the document
    static BrxBillOfMaterialsArray getBillsOfMaterials(AcDbDatabase* pDb);

    // creates Bill of materials table with given configuration, if configuration is empty, the default template is used
    static BrxBillOfMaterials createBomTable(AcDbDatabase* pDb, const ACHAR* title = nullptr, const ACHAR* configuration = nullptr);

private:
    BrxBillOfMaterialsImp* m_pBrxImp = nullptr;
};

#endif // _AcBillOfMaterials_h_Included
