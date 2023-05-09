// Utility functions

// Property of Bricsys NV. All rights reserved.
// This file is part of the source code of Bricsys NV. The source code
// is subject to copyright, is a trade secret of Bricsys NV, and contains
// embodiments of inventions disclosed in patent applications and patents
// of Bricsys NV.

/////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "utils.h"
#include "Misc/AcCStdioFile.h"

namespace BrxMechComponentsSample {

Acad::ErrorStatus getModelSpaceId(AcDbDatabase* pDb, AcDbObjectId& blockId)
{
    AcDbObjectPointer<AcDbBlockTable> pBT(pDb->blockTableId(), AcDb::kForRead);
    if (!pBT)
        return Acad::eInvalidInput;

    return pBT->getAt(ACDB_MODEL_SPACE, blockId);
}

Acad::ErrorStatus addToDatabase(AcDbDatabase* pDb, AcDbEntity* pEnt,
                                AcDbObjectId& objId, bool addToModelSpace)
{
    Acad::ErrorStatus es = Acad::ErrorStatus::eOk;
    if (pEnt == nullptr)
        return Acad::eInvalidInput;

    AcDbObjectId blockId;
    AcDbObjectPointer<AcDbBlockTable> pBT(pDb->blockTableId(), AcDb::kForRead);
    if (!pBT)
        return Acad::eInvalidInput;

    es = pBT->getAt(addToModelSpace ? ACDB_MODEL_SPACE : ACDB_PAPER_SPACE, blockId);

    if (Acad::ErrorStatus::eOk != es)
        return Acad::eInvalidInput;

    AcDbBlockTableRecord* pMS = nullptr;;
    if (acdbOpenObject(pMS, blockId, AcDb::kForWrite) != Acad::eOk)
        return Acad::eInvalidInput;

    es = pMS->appendAcDbEntity(objId, pEnt);
    if (es != Acad::eOk)
    {
        acutPrintf(_T("*Error* Object not added to the database.\n"));
        pMS->close();
        return es;
    }

    pMS->close();

    return es;
}

AcStringArray ComponentsFilter::componentPropertyNames()
{
    static AcStringArray aComponentPropNames;
    if (aComponentPropNames.isEmpty())
    {
        aComponentPropNames.append(_ACRX_T("Component name"));
        aComponentPropNames.append(_ACRX_T("Component description"));
        aComponentPropNames.append(_ACRX_T("Component file"));
        aComponentPropNames.append(_ACRX_T("Instance name"));
        aComponentPropNames.append(_ACRX_T("Part standard"));
        aComponentPropNames.append(_ACRX_T("Part type"));
        aComponentPropNames.append(_ACRX_T("Part category"));
        aComponentPropNames.append(_ACRX_T("Part description"));
        aComponentPropNames.append(_ACRX_T("Physical material"));
        aComponentPropNames.append(_ACRX_T("Is standard"));
        aComponentPropNames.append(_ACRX_T("BOM status"));
    }

    return aComponentPropNames;
}

ComponentsFilter::EComponentProperty
ComponentsFilter::getComponentIndex(const AcString& keyProperty)
{
    const auto& componentPropNames = componentPropertyNames();
    auto propIdx = componentPropNames.find(keyProperty);
    if (propIdx >= 0 && propIdx < componentPropNames.length())
        return static_cast<EComponentProperty>(propIdx);
    return EComponentProperty::eNone;
}

ComponentsFilter::KeyPropertyFilter
ComponentsFilter::getKeyPropertyFilter(const AcString& keyProperty)
{
    EComponentProperty prop = getComponentIndex(keyProperty);
    KeyPropertyFilter filterFunction = nullptr;
    switch (prop)
    {
        case EComponentProperty::eComponentName:
        {
            filterFunction = [](const AcDbObjectId& objId) {
                auto component = BrxComponentDefinition::getComponentDefinition(objId);
                return component.isNull() ? _ACRX_T("") : component.name();
            };
            break;
        }
        case EComponentProperty::eComponentDescription:
        {
            filterFunction = [](const AcDbObjectId& objId) {
                auto component = BrxComponentDefinition::getComponentDefinition(objId);
                return component.isNull() ? _ACRX_T("") : component.description();
            };
            break;
        }
        case EComponentProperty::eComponentFile:
        {
            filterFunction = [](const AcDbObjectId& objId) {
                auto component = BrxComponentDefinition::getComponentDefinition(objId);
                return component.isNull() ? _ACRX_T("") : component.getFilePath();
            };
            break;
        }
        case EComponentProperty::eInstanceName:
        {
            filterFunction = [](const AcDbObjectId& objId) {
                auto instance = BrxComponentInstance::getComponentInstance(objId);
                return instance.isNull() ? _ACRX_T("") : instance.name();
            };
            break;
        }
        case EComponentProperty::ePartStandard:
        {
            filterFunction = [](const AcDbObjectId& objId) {
                auto component = BrxComponentDefinition::getComponentDefinition(objId);
                return component.isNull() ? _ACRX_T("") : component.standard();
            };
            break;
        }
        case EComponentProperty::ePartType:
        {
            filterFunction = [](const AcDbObjectId& objId) {
                auto component = BrxComponentDefinition::getComponentDefinition(objId);
                return component.isNull() ? _ACRX_T("") : component.standardPartType();
            };
            break;
        }
        case EComponentProperty::ePartCategory:
        {
            filterFunction = [](const AcDbObjectId& objId) {
                auto component = BrxComponentDefinition::getComponentDefinition(objId);
                return component.isNull() ? _ACRX_T("") : component.standardPartCategory();
            };
            break;
        }
        case EComponentProperty::ePartDescription:
        {
            filterFunction = [](const AcDbObjectId& objId) {
                auto component = BrxComponentDefinition::getComponentDefinition(objId);
                return component.isNull() ? _ACRX_T("") : component.standardPartDescription();
            };
            break;
        }
        case EComponentProperty::ePhysicalMaterial:
        {
            filterFunction = [](const AcDbObjectId& objId) {
                auto component = BrxComponentDefinition::getComponentDefinition(objId);
                return component.isNull() ? _ACRX_T("") : component.physicalMaterial();
            };
            break;
        }
        case EComponentProperty::eIsStandard:
        {
            filterFunction = [](const AcDbObjectId& objId) {
                auto component = BrxComponentDefinition::getComponentDefinition(objId);
                return !component.isNull() && component.isStandard() ? _ACRX_T("Yes") : _ACRX_T("No");
            };
            break;
        }
        case EComponentProperty::eBOMStatus:
        {
            filterFunction = [](const AcDbObjectId& objId) {
                auto component = BrxComponentDefinition::getComponentDefinition(objId);
                if (component.isNull())
                    return _ACRX_T("");

                switch (component.bomStatus())
                {
                    case EBrxStatusBOM::eRegular: return _ACRX_T("Regular");
                    case EBrxStatusBOM::eTransparent: return _ACRX_T("Transparent");
                    case EBrxStatusBOM::eTerminal: return _ACRX_T("Terminal");
                    case EBrxStatusBOM::eExcluded: return _ACRX_T("Excluded");
                    default:
                        return _ACRX_T("");
                };
            };
            break;
        }
        case EComponentProperty::eNone:
        default:
        {
            acutPrintf(ACRX_T("\nError! The %s key property was not found. %d\n"),
                       keyProperty.constPtr(), (int)__LINE__);
        }
    };

    return filterFunction;
}

ComponentsFilter::ComponentsFilter(const ACHAR* keyProperty, const AcDbObjectIdArray& aAllComponentIds)
    : m_aAllComponentIds(aAllComponentIds)
{
    // Creates a function to get value of the key property (with the @keyProperty name) for any component 
    m_filterFunction = getKeyPropertyFilter(keyProperty);
}

// Filter components which has @keyPropValue for the key property.
Acad::ErrorStatus ComponentsFilter::retrieveComponentsByProperty(
    const ACHAR* keyPropValue, AcDbObjectIdArray& aResultComponentIds) const
{
    for (const auto& componentId : m_aAllComponentIds)
    {
        if (m_filterFunction && m_filterFunction(componentId) == keyPropValue)
            aResultComponentIds.append(componentId);
    }

    return eOk;
}

ParsedPropertiesData::ParsedPropertiesData(const AcStringMatrix &data)
    : m_aaParsedStrings(data) {}

AcString ParsedPropertiesData::keyPropertyName() const
{
    return !m_aaParsedStrings.isEmpty() && !m_aaParsedStrings[0].isEmpty()
               ? m_aaParsedStrings[0][0]
               : _ACRX_T("");
}

AcStringArray ParsedPropertiesData::keyPropertyValues() const
{
    AcStringArray aResultStrings;
    for (int rowIdx = 1; rowIdx < m_aaParsedStrings.length(); ++rowIdx)
    {
        if (m_aaParsedStrings[rowIdx].isEmpty())
            continue;

        aResultStrings.append(m_aaParsedStrings[rowIdx][0]);
    }

    return aResultStrings;
}

AcStringArray ParsedPropertiesData::customPropertyNames() const
{
    return retrieveStringRow(0);
}

AcStringArray ParsedPropertiesData::customPropertyValues(int rowIdx) const
{
    return retrieveStringRow(rowIdx);
}

AcStringArray ParsedPropertiesData::retrieveStringRow(int rowIdx) const
{
    if (rowIdx >= m_aaParsedStrings.length() || m_aaParsedStrings[rowIdx].length() < 2)
        return {};

    AcStringArray aResultStrings;
    for (int column = 1; column < m_aaParsedStrings[rowIdx].length(); ++column)
    {
        aResultStrings.append(m_aaParsedStrings[rowIdx][column]);
    }

    return aResultStrings;
}

Acad::ErrorStatus parseCSVLine(AcStringArray& aParsedStrings, const AcString& lineStr, wchar_t delimiter)
{
    AcString field;
    bool quoteOn = false;
    const int inputLength = lineStr.length();
    for (int idx = 0; idx < inputLength; ++idx)
    {
        const wchar_t chr = lineStr.getAt(idx);
        if (chr == '\n')
            break;

        if (quoteOn)
        {
            if (chr == '\"')
            {
                if ((idx + 1 < inputLength) && lineStr.getAt(idx + 1) == delimiter)
                    quoteOn = false;
            }
            else
                field += chr;
        }
        else
        {
            if (chr == delimiter)
            {
                aParsedStrings.append(field);
                field = _ACRX_T("");
            }
            else if (chr == '\"')
            {
                if (field.isEmpty())
                    quoteOn = true;
                else
                    return Acad::eUnsupportedFileFormat;
            }
            else
                field += chr;
        }
    }

    if (!field.isEmpty())
        aParsedStrings.append(field);

    return Acad::eOk;
}

Acad::ErrorStatus readCSVFile(AcStringMatrix& aaParsedStrings, const AcString& acFileName, wchar_t delimiter)
{
    AcCStdioFile acFile(acFileName, CFile::modeRead);
    CString strBuffer;
    strBuffer.Empty();
    int rowIndex = 0;
    Acad::ErrorStatus es = Acad::eOk;
    while (acFile.ReadString(strBuffer))
    {
        AcString inputStr{ strBuffer };
        if (!inputStr.isEmpty())
        {
            aaParsedStrings.append(AcStringArray{});
            es = parseCSVLine(aaParsedStrings[rowIndex++], inputStr, delimiter);
            if (es != Acad::eOk)
                return es;
            strBuffer.Empty();
        }
    }

    return Acad::eOk;
}

AcDbObjectIdArray findAllComponentInstances(const AcDbObjectId& blockId)
{
    auto pComponent = BrxComponentDefinition::getComponentDefinition(blockId);
    if (pComponent.isNull())
        return Acad::eNullPtr;

    const auto aChildInstances = pComponent.instanceEntityIds();
    AcDbObjectIdArray aResult{ 0 };
    aResult.append(blockId);
    for (const auto& childInstId : aChildInstances)
    {
        if (!childInstId.isNull())
        {
            auto aChildResult = findAllComponentInstances(childInstId);
            aResult.append(aChildResult);
        }
    }

    return aResult;
}

AcDbObjectIdArray getAllComponentsFromDatabase(AcDbDatabase* pDb)
{
    AcDbObjectId msId;
    auto res = getModelSpaceId(pDb, msId);
    if (res != Acad::eOk)
        return res;

    return findAllComponentInstances(msId);
}

bool displayBomContent(const BrxBillOfMaterials& bom)
{
    acutPrintf(ACRX_T("----BOM content: \n"));
    BrxBomContent content;
    auto res = bom.getContent(content, BrxBomContentType::kFormatted);
    if (res)
    {
        acutPrintf(ACRX_T("* There are problems with content.\n"));
        return false;
    }

    const int nbCols = content.nbCols();
    const int nbRows = content.nbDataRows();
    for (int rowIdx = 0; rowIdx < nbRows; ++rowIdx)
    {
        for (int colIdx = 0; colIdx < nbCols; ++colIdx)
        {
            const BrxBomValue bomValue = content.cellValue(rowIdx, colIdx);
            const AcValue value = bomValue.value();
            const ACHAR* valAsStr = nullptr;
            if (value.get(valAsStr) && valAsStr)
                acutPrintf(valAsStr);
            else
                acutPrintf(ACRX_T(""));

            acutPrintf(ACRX_T("; "));
        }

        acutPrintf(ACRX_T("\n"));
    }

    return true;
}

AcStringArray extractColumnNames(const BrxBomColumns& aColumns)
{
    AcStringArray aColumnsNames;
    for (const auto& column : aColumns)
    {
        aColumnsNames.append(column.name());
    }

    return aColumnsNames;
}

void printColumnsNames(const BrxBomColumns& aColumns)
{
    AcStringArray aColumnsNames = extractColumnNames(aColumns);
    acutPrintf(ACRX_T("----Available columns: \n"));
    for (const auto& name : aColumnsNames)
    {
        acutPrintf(ACRX_T("%s\n"), name.kACharPtr());
    }
}

} // namespace BrxMechComponentsSample
