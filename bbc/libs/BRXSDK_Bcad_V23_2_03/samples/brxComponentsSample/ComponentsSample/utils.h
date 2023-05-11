// Utility functions

// Property of Bricsys NV. All rights reserved.
// This file is part of the source code of Bricsys NV. The source code
// is subject to copyright, is a trade secret of Bricsys NV, and contains
// embodiments of inventions disclosed in patent applications and patents
// of Bricsys NV.

/////////////////////////////////////////////////////////////////////////

#pragma once

#include "stdafx.h"

namespace BrxMechComponentsSample {

/**
 * Adds entity to model space of target database and returns its id
 * @param pDb
 *   Database to add to
 * @param pEntity
 *   Entity to add
 * @param objId
 *   Result id if succeeded
 * @param addToModelSpace
 *   Defines to which space table to be added
 * @return
 *   Acad::eOk if succeeded
 */
Acad::ErrorStatus addToDatabase(AcDbDatabase *pDb, AcDbEntity *pEntity,
                                AcDbObjectId &objId,
                                bool addToModelSpace = true);

/**
 * For given database extracts id of its model space
 * @param pDb
 *   pointer to database
 * @param blockId
 *   reference where id of given database model space will be put
 * @return
 *   Acad::eOk if succeeded
 */
Acad::ErrorStatus getModelSpaceId(AcDbDatabase* pDb, AcDbObjectId& blockId);

/**
 * Filters for components by the key property.
 */
class ComponentsFilter
{
public:
    using KeyPropertyFilter = std::function<AcString(const AcDbObjectId& objId)>;

    enum class EComponentProperty
    {
        eComponentName,
        eComponentDescription,
        eComponentFile,
        eInstanceName,
        ePartStandard,
        ePartType,
        ePartCategory,
        ePartDescription,
        ePhysicalMaterial,
        eIsStandard,
        eBOMStatus,
        eNone
    };

public:
    ComponentsFilter(const ACHAR* keyProperty, const AcDbObjectIdArray& aAllComponentIds);

    // Filter components which has @keyPropValue for the key property.
    Acad::ErrorStatus retrieveComponentsByProperty(const ACHAR* keyPropValue,
                                                   AcDbObjectIdArray& aResultComponentIds) const;

    // Returns hard-coded names of components properties
    static AcStringArray componentPropertyNames();

    // Returns index of component property from the list from @componentPropertyNames()
    static EComponentProperty getComponentIndex(const AcString& keyProperty);

    // Provides filter-function (which calls the corresponding property getter) for
    // the particular component properties by their names.
    static KeyPropertyFilter getKeyPropertyFilter(const AcString& keyProperty);

private:
    KeyPropertyFilter m_filterFunction = nullptr;
    AcDbObjectIdArray m_aAllComponentIds;
};

/**
 * Special class to parse custom properties data from raw CSV cells data
 */
using AcStringMatrix = AcArray<AcStringArray>;
class ParsedPropertiesData
{
public:
    ParsedPropertiesData(const AcStringMatrix& data);

    AcString keyPropertyName() const;
    AcStringArray keyPropertyValues() const;
    AcStringArray customPropertyNames() const;
    AcStringArray customPropertyValues(int rowIdx) const;

private:
    AcStringArray retrieveStringRow(int rowIdx) const;

private:
    AcArray<AcStringArray> m_aaParsedStrings;
};

/**
 * Parses cells data from the string of the CSV line
 * @param[out] aParsedStrings
 *   output strings array which contains sequential cells values from the processed CSV line
 * @param lineStr
 *   input string which provides the content of the particular CSV line
 * @param delimiter
 *   a delimiter symbol in the processed CSV file
 * @return
 *   Acad::eOk if succeeded
 */
Acad::ErrorStatus parseCSVLine(AcStringArray& aParsedStrings, const AcString& lineStr, wchar_t delimiter);

/**
 * Extracts all the cells data from the particular CSV file.
 *@param[out] aaParsedStrings
 *   output strings matrix which contains sequential cells values from the of the processed CSV line
 * @param acFileName
 *   the name of the processed CSV line
 * @param delimiter
 *   a delimiter symbol in the processed CSV file
 * @return
 *   Acad::eOk if succeeded
 */
Acad::ErrorStatus readCSVFile(AcStringMatrix& aaParsedStrings, const AcString& acFileName, wchar_t delimiter);

/**
 * Returns all the components instances ids
 */
AcDbObjectIdArray getAllComponentsFromDatabase(AcDbDatabase* pDb);

/**
 * Utility function which prints the current BOM content to the command line.
 * @param bom
 *   bom table for which BOM content should be printed
 * @return
 *   true if successful
 */
bool displayBomContent(const BrxBillOfMaterials& bom);

// Extracts names of BOM columns
AcStringArray extractColumnNames(const BrxBomColumns& aColumns);

// Prints names of the passed BOM columns
void printColumnsNames(const BrxBomColumns& aColumns);

} // namespace BrxMechComponentsSample
