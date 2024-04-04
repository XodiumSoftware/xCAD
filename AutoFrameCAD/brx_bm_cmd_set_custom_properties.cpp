// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////

// Implementation of BMSETCUSTOMPROPERTIES

#include "StdAfx.h"
#include "utils.h"
#include "afxdlgs.h"

namespace BrxMechComponentsSample
{

    Acad::ErrorStatus addCustomPropertyToComponent(const AcDbObjectId &componentId,
                                                   const ACHAR *categoryName,
                                                   const ACHAR *propertyName,
                                                   const AcValue value)
    {
        auto component = BrxComponentDefinition::getComponentDefinition(componentId);
        if (component.isNull())
            return Acad::eNullObjectPointer;

        // Below we are trying to set @value for the custom property by its name and
        // category. Using of the eCreateForAllIfNotExist means that if there is no
        // property with @propertyName in the @categoryName category it will be
        // created for all the component instances.
        // If you need to create a new property only for the particular component
        // instance, use @eCreateForThisInstanceIfNotExist.
        return component.setCustomPropertyValue(categoryName, propertyName, value,
                                                BrxComponentDefinition::ECustomPropertyParameters::eCreateForAllIfNotExist);
    }

    bool addCustomProperties(const AcDbObjectIdArray &aComponentIds,
                             const ACHAR *categoryName,
                             const AcStringArray &aCustomPropertyNames,
                             const AcStringArray &aPropValues)
    {
        // It is assumed that order of values from @aPropValues corresponds to order
        // of properties in @aCustomPropertyNames.
        if (aCustomPropertyNames.length() != aPropValues.length())
        {
            acutPrintf(ACRX_T("\nError! Number of properties differs from number of property values.\n"));
            return false;
        }

        bool result = true;

        // Adds the new custom properties with names from CSV file
        // (@aCustomPropertyNames) for all the components.
        for (int propertyIdx = 0; propertyIdx < aCustomPropertyNames.length(); ++propertyIdx)
        {
            for (const auto &componentId : aComponentIds)
            {
                AcValue value{};
                value.set(aPropValues[propertyIdx]);
                const AcString customPropName{aCustomPropertyNames[propertyIdx]};
                Acad::ErrorStatus es = addCustomPropertyToComponent(
                    componentId, categoryName, customPropName, value);
                if (es != Acad::eOk)
                {
                    acutPrintf(
                        ACRX_T(
                            "\nThe %s custom property wasn't set for component.\n"),
                        customPropName.constPtr(), (int)__LINE__);
                    result = false;
                }
            }
        }

        return result;
    }

    /**
     * Retrieves custom properties from the passed parsed CSV data, creates them
     * (if there are no such properties before) and sets values to these properties
     * for the corresponding components.
     * NOTE: It is assumed that these custom properties are in the same category
     * (property set), the new ones will be added to this category. If there is no
     * such category, the new one will be added.
     */
    bool setCustomProperties(AcDbDatabase *pDb,
                             const ParsedPropertiesData &data,
                             const ACHAR *propertyCategory)
    {
        const ACHAR *keyProperty = data.keyPropertyName();
        const AcStringArray aKeyPropValues = data.keyPropertyValues();
        const AcStringArray aCustomPropertyNames = data.customPropertyNames();
        const AcDbObjectIdArray aAllComponentIds = getAllComponentsFromDatabase(pDb);

        ComponentsFilter filter{keyProperty, aAllComponentIds};
        bool result = true;
        for (int propValueIdx = 0; propValueIdx < aKeyPropValues.length(); ++propValueIdx)
        {
            AcDbObjectIdArray aComponentIds;
            filter.retrieveComponentsByProperty(aKeyPropValues[propValueIdx], aComponentIds);
            result &= addCustomProperties(
                aComponentIds, propertyCategory, aCustomPropertyNames,
                data.customPropertyValues(propValueIdx + 1));
        }

        return result;
    }

    /**
     * Creates a new BOM table in BOM Manager and set its uid which can be used to
     * extract the BOM table again.
     */
    bool createBOM(AcDbDatabase *pDb, const ACHAR *bomTableName, AcString &uid)
    {
        BrxBillOfMaterials bom = BrxBillOfMaterials::createBomTable(pDb, bomTableName);
        if (bom.isNull())
            return false;

        uid = bom.uid();
        return true;
    }

    /**
     * Adds columns by custom properties which were extracted from CSV file.
     */
    bool addColumnsToBOM(AcDbDatabase *pDb, const AcString &uid,
                         const ACHAR *keyPropName,
                         const AcStringArray &aCustomPropNames)
    {
        BrxBillOfMaterials bom = BrxBillOfMaterials::getBillOfMaterials(pDb, uid);
        if (bom.isNull())
            return false;

        displayBomContent(bom);

        const auto aAvailableColumns = bom.availableColumns();
        printColumnsNames(aAvailableColumns);

        auto addColumnToBOM = [&bom, &aAvailableColumns](const ACHAR *propName)
        {
            for (const auto &column : aAvailableColumns)
            {
                if (column.name().compare(AcString(propName)) == 0)
                {
                    acutPrintf(ACRX_T("%s\n"), column.name().kACharPtr());
                    bom.addColumn(column);
                    return true;
                }
            }

            return false;
        };

        AcStringArray aExistingColumnsNames = extractColumnNames(bom.addedColumns());

        // A new bom table is generated by default template, so it can already contain key property
        if (!aExistingColumnsNames.contains(keyPropName))
        {
            if (!addColumnToBOM(keyPropName))
            {
                acutPrintf(ACRX_T("The key property %s has not been added. %d\n"),
                           keyPropName, (int)__LINE__);
                return false;
            }
        }

        // Adds columns by all the custom properties names
        for (const auto &propName : aCustomPropNames)
        {
            AcString fullName{propName};
            fullName.append(_ACRX_T("~User")); // Custom property columns names have additional suffix with namespace
            if (!addColumnToBOM(fullName))
            {
                acutPrintf(ACRX_T("The custom property %s has not been added. %d\n"),
                           propName.constPtr(), (int)__LINE__);
                return false;
            }
        }

        bom.save(); // saves collected changes, update isn't required here because there are no associated tables yet

        acutPrintf(ACRX_T("----Added columns: \n"));
        printColumnsNames(bom.addedColumns());
        displayBomContent(bom);
        return true;
    }

    // Creates a table on the model space
    bool createTable(AcDbDatabase *pDb, AcDbObjectId &tableId)
    {
        AcDbTable *pTable = new AcDbTable();
        pTable->setPosition(AcGePoint3d{0.0, 0.0, 0.0});
        auto styleId = pDb->tablestyle();
        auto es = pTable->setTableStyle(styleId);
        if (es != Acad::eOk)
            return false;

        es = addToDatabase(pDb, pTable, tableId, true); // add to model space
        pTable->close();
        if (tableId.isNull())
        {
            acutPrintf(ACRX_T("The table has not been added. %d\n"), (int)__LINE__);
            return false;
        }

        return true;
    }

    /**
     * Creates a table associated with the created BOM table (with @uid) and update
     * it with the current BOM content.
     */
    bool createAssociatedBOMTable(AcDbDatabase *pDb, const AcString &uid)
    {
        BrxBillOfMaterials bom = BrxBillOfMaterials::getBillOfMaterials(pDb, uid);
        if (bom.isNull())
            return false;

        AcDbObjectId tableId;
        if (!createTable(pDb, tableId))
            return false;

        bom.linkWithTable(tableId); // links the created table with the BOM table, fills the table by BOM content
        bom.save();                 // saves collected changes
        bom.updateAll();            // updates added associated table

        displayBomContent(bom);

        return true;
    }

    /**
     * Runs MFC file dialog to select CSV file and returns its name.
     */
    AcString getCSVFileName()
    {
        const TCHAR szFilter[] = _T("CSV Files (*.csv)|*.csv|");
        CFileDialog dlg(TRUE, _T("csv"), NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, szFilter);
        if (dlg.DoModal() == IDOK)
            return AcString{dlg.GetPathName()};

        return ACRX_T("");
    }

    /**
     * Returns the name of the category which custom properties will be set in this app.
     */
    AcString getCategoryName()
    {
        AcString categoryName;
        int rt = ads_getstring(1, ACRX_T("Input a category name for custom properties:"), categoryName);
        return categoryName;
    }

    const wchar_t s_delimiter{';'}; // hard-coded delimiter for CSV file

    /**
     * Implementation of the new command BMSETCUSTOMPROPERTIES which allows to
     * select a CSV file with information about custom properties and their values,
     * sets the values for the custom properties for the components with the
     * corresponding key values. If there are no properties with some names, they
     * will be created in the given category (property set). It is assumed that data
     * should be filled the following way:
     * <key property name>   ; <name of 1st custom property> ; name of 2d custom property; ...\n
     * <key property value1> ; <value11>                     ; <value12>                 ; ...\n
     * <key property value2> ; <value21>                     ; <value22>                 ; ...\n
     * ...
     * So this data means that for the component which has the <key property name>
     * property with <key property value1> the <value11> value will be set for the
     * <name of 1st custom property> custom property will.
     */
    void cmdBmSetCustomProperties()
    {
        // Checking the license. A mechanical license is required to use the BRX Components API.
        if (!isLicenseAvailable(BricsCAD::eMechanical))
        {
            acutPrintf(
                ACRX_T("\nError! Mechanical component is not available!\nPlease "
                       "verify your BricsCAD License and 'RunAsLevel' setting. %d\n"),
                (int)__LINE__);
            return;
        }

        // Obtaining the database of the current opened document.
        AcDbDatabase *pDb = acdbHostApplicationServices()->workingDatabase();
        if (!pDb)
        {
            acutPrintf(ACRX_T("\nError! No current database was found. %d\n"), (int)__LINE__);
            return;
        }

        // Selecting CSV file with custom properties and their values for components.
        AcString acFileName = getCSVFileName();

        // Parsing custom properties, their values from the selected CSV file.
        AcStringMatrix aaParsedStrings{};
        readCSVFile(aaParsedStrings, acFileName, s_delimiter);
        ParsedPropertiesData parsedData{aaParsedStrings};
        const AcString keyPropertyName = parsedData.keyPropertyName();

        // Obtaining the category.
        AcString categoryName = getCategoryName();

        // Setting custom properties values according to the parsed data.
        setCustomProperties(pDb, parsedData, categoryName);
        auto aPropNames = parsedData.customPropertyNames();

        // Creating a new BOM table by the default template.
        AcString newBomId; // BOM table identifier
        if (!createBOM(pDb, _T("BOM with new custom properties"), newBomId))
        {
            acutPrintf(ACRX_T("\nError! BOM table wasn't created. %d\n"), (int)__LINE__);
            return;
        }

        // Adding custom properties columns to the created BOM table.
        if (!addColumnsToBOM(pDb, newBomId, keyPropertyName, aPropNames))
        {
            acutPrintf(ACRX_T("\nError! There are problems with adding custom "
                              "properties columns. %d\n"),
                       (int)__LINE__);
            return;
        }

        // Creating a new table that will be linked to the created BOM table on the
        // model layout.
        if (!createAssociatedBOMTable(pDb, newBomId))
        {
            acutPrintf(ACRX_T("\nError! An associated table wasn't created. %d\n"), (int)__LINE__);
            return;
        }
    }

}
