// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbBlockTable.h"
#include "AcDb/AcDbDatabase.h"
#include "AcDb/AcDbDimStyleTable.h"
#include "AcDb/AcDbLayerTable.h"
#include "AcDb/AcDbLinetypeTable.h"
#include "AcDb/AcDbRegAppTable.h"
#include "AcDb/AcDbTextStyleTable.h"
#include "AcDb/AcDbTextStyleTableRecord.h"
#include "AcDb/AcDbUCSTable.h"
#include "AcDb/AcDbViewportTable.h"
#include "AcDb/AcDbViewTable.h"

/** _ */
namespace AcDbSymbolUtilities
{

enum CompatibilityMode
{
    kPreExtendedNames = 0,
    kExtendedNames
};

enum NameCaseMode
{
    kForceToUpper = 0,
    kPreserveCase
};

enum NewNameMode
{
    kAsExistingName = 0,
    kAsNewName
};

enum VerticalBarMode
{
    kNoVerticalBar = 0,
    kAllowVerticalBar
};

Acad::ErrorStatus getBlockId(AcDbObjectId&,const ACHAR*,AcDbDatabase*);
Acad::ErrorStatus getDimStyleId(AcDbObjectId&,const ACHAR*,AcDbDatabase*);
Acad::ErrorStatus getLayerId(AcDbObjectId&,const ACHAR*,AcDbDatabase*);
Acad::ErrorStatus getLinetypeId(AcDbObjectId&,const ACHAR*,AcDbDatabase*);
Acad::ErrorStatus getRegAppId(AcDbObjectId&,const ACHAR*,AcDbDatabase*);
Acad::ErrorStatus getSymbolName(ACHAR*&,AcDbObjectId);
Acad::ErrorStatus getTextStyleId(AcDbObjectId&,const ACHAR*,AcDbDatabase*);
Acad::ErrorStatus getUCSId(AcDbObjectId&,const ACHAR*,AcDbDatabase*);
Acad::ErrorStatus getViewId(AcDbObjectId&,const ACHAR*,AcDbDatabase*);
bool hasBlock(AcDbObjectId,AcDbDatabase*);
bool hasBlock(const ACHAR*,AcDbDatabase*);
bool hasDimStyle(AcDbObjectId,AcDbDatabase*);
bool hasDimStyle(const ACHAR*,AcDbDatabase*);
bool hasLayer(AcDbObjectId,AcDbDatabase*);
bool hasLayer(const ACHAR*,AcDbDatabase*);
bool hasLinetype(AcDbObjectId,AcDbDatabase*);
bool hasLinetype(const ACHAR*,AcDbDatabase*);
bool hasRegApp(AcDbObjectId,AcDbDatabase*);
bool hasRegApp(const ACHAR*,AcDbDatabase*);
bool hasTextStyle(AcDbObjectId,AcDbDatabase*);
bool hasTextStyle(const ACHAR*,AcDbDatabase*);
bool hasUCS(AcDbObjectId,AcDbDatabase*);
bool hasUCS(const ACHAR*,AcDbDatabase*);
bool hasView(AcDbObjectId,AcDbDatabase*);
bool hasView(const ACHAR*,AcDbDatabase*);
bool hasViewport(AcDbObjectId,AcDbDatabase*);
bool hasViewport(const ACHAR*,AcDbDatabase*);

}; // namespace AcDbSymbolUtilities
