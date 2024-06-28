// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbDatabase.h"
#include "AcDb/AcDbDictionary.h"

/** _ */
namespace AcDbDictUtil
{
Acad::ErrorStatus dictionaryGetAt(AcDbObjectId&,const ACHAR*,AcDbObjectId);
Acad::ErrorStatus dictionaryNameAt(ACHAR*&,AcDbObjectId);
Acad::ErrorStatus dictionaryNameAt(ACHAR*&,AcDbObjectId,AcDbObjectId);
Acad::ErrorStatus getColorId(AcDbObjectId&,const ACHAR*,AcDbDatabase*);
Acad::ErrorStatus getColorName(ACHAR*&,AcDbObjectId);
Acad::ErrorStatus getGroupId(AcDbObjectId&,const ACHAR*,AcDbDatabase*);
Acad::ErrorStatus getGroupName(ACHAR*&,AcDbObjectId);
Acad::ErrorStatus getLayoutId(AcDbObjectId&,const ACHAR*,AcDbDatabase*);
Acad::ErrorStatus getLayoutName(ACHAR*&,AcDbObjectId);
Acad::ErrorStatus getMaterialId(AcDbObjectId&,const ACHAR*,AcDbDatabase*);
Acad::ErrorStatus getMaterialName(ACHAR*&,AcDbObjectId);
Acad::ErrorStatus getMLStyleId(AcDbObjectId&,const ACHAR*,AcDbDatabase*);
Acad::ErrorStatus getMLStyleName(ACHAR*&,AcDbObjectId);
Acad::ErrorStatus getPlotSettingsId(AcDbObjectId&,const ACHAR*,AcDbDatabase*);
Acad::ErrorStatus getPlotSettingsName(ACHAR*&,AcDbObjectId);
Acad::ErrorStatus getPlotStyleNameId(AcDbObjectId&,const ACHAR*,AcDbDatabase*);
Acad::ErrorStatus getPlotStyleNameName(ACHAR*&,AcDbObjectId);
Acad::ErrorStatus getTableStyleId(AcDbObjectId&,const ACHAR*,AcDbDatabase*);
Acad::ErrorStatus getTableStyleName(ACHAR*&,AcDbObjectId);
Acad::ErrorStatus getVisualStyleId(AcDbObjectId&,const ACHAR*,AcDbDatabase*);
Acad::ErrorStatus getVisualStyleName(ACHAR*&,AcDbObjectId);
bool hasColor(const ACHAR*,AcDbDatabase*);
bool hasGroup(const ACHAR*,AcDbDatabase*);
bool hasLayout(const ACHAR*,AcDbDatabase*);
bool hasMaterial(const ACHAR*,AcDbDatabase*);
bool hasMLStyle(const ACHAR*,AcDbDatabase*);
bool hasPlotSettings(const ACHAR*,AcDbDatabase*);
bool hasPlotStyleName(const ACHAR*,AcDbDatabase*);
bool hasTableStyle(const ACHAR*,AcDbDatabase*);
bool hasVisualStyle(const ACHAR*,AcDbDatabase*);
}; // namespace AcDbDictUtil
