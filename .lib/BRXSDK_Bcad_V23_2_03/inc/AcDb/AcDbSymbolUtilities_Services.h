// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "Misc/MiscGlobal.h"

/** _ */
namespace AcDbSymbolUtilities
{

/** _ */
class Services
{
public:
    virtual Acad::ErrorStatus getBlockNameFromInsertPathName(ACHAR*&,const ACHAR*) const = 0;
    virtual Acad::ErrorStatus getInsertPathNameFromBlockName(ACHAR*&,const ACHAR*) const = 0;
    virtual Acad::ErrorStatus getPathNameFromSymbolName(ACHAR*&,const ACHAR*,const ACHAR*) const = 0;
    virtual Acad::ErrorStatus getSymbolNameFromPathName(ACHAR*&,const ACHAR*,const ACHAR*) const = 0;
    virtual Acad::ErrorStatus makeDependentName(ACHAR*&,const ACHAR*,const ACHAR*) const = 0;
    virtual Acad::ErrorStatus preValidateSymbolName(ACHAR*&,bool) const = 0;
    virtual Acad::ErrorStatus repairPreExtendedSymbolName(ACHAR*&,const ACHAR*,bool) const = 0;
    virtual Acad::ErrorStatus repairSymbolName(ACHAR*&,const ACHAR*,bool) const = 0;
    virtual Acad::ErrorStatus validateCompatibleSymbolName(const ACHAR*,bool,bool,bool) const = 0;
    virtual Acad::ErrorStatus validatePreExtendedSymbolName(const ACHAR*,bool) const = 0;
    virtual Acad::ErrorStatus validateSymbolName(const ACHAR*,bool) const = 0;
    virtual AcDbObjectId blockModelSpaceId(AcDbDatabase*) const = 0;
    virtual AcDbObjectId blockPaperSpaceId(AcDbDatabase*) const = 0;
    virtual AcDbObjectId layerDefpointsId(AcDbDatabase*) const = 0;
    virtual AcDbObjectId layerZeroId(AcDbDatabase*) const = 0;
    virtual AcDbObjectId linetypeByBlockId(AcDbDatabase*) const = 0;
    virtual AcDbObjectId linetypeByLayerId(AcDbDatabase*) const = 0;
    virtual AcDbObjectId linetypeContinuousId(AcDbDatabase*) const = 0;
    virtual AcDbObjectId regAppAcadId(AcDbDatabase*) const = 0;
    virtual AcDbObjectId textStyleStandardId(AcDbDatabase*) const = 0;
    virtual bool compatibilityMode(AcDbDatabase*) const = 0;
    virtual bool getMaxSymbolNameLength(size_t&,size_t&,bool,bool) const = 0;
    virtual bool hasVerticalBar(const ACHAR*) const = 0;
    virtual bool isBlockLayoutName(const ACHAR*) const = 0;
    virtual bool isBlockModelSpaceName(const ACHAR*) const = 0;
    virtual bool isBlockPaperSpaceName(const ACHAR*) const = 0;
    virtual bool isLayerDefpointsName(const ACHAR*) const = 0;
    virtual bool isLayerZeroName(const ACHAR*) const = 0;
    virtual bool isLinetypeByBlockName(const ACHAR*) const = 0;
    virtual bool isLinetypeByLayerName(const ACHAR*) const = 0;
    virtual bool isLinetypeContinuousName(const ACHAR*) const = 0;
    virtual bool isRegAppAcadName(const ACHAR*) const = 0;
    virtual bool isTextStyleStandardName(const ACHAR*) const = 0;
    virtual bool isViewportActiveName(const ACHAR*) const = 0;
    virtual bool splitDependentName(size_t&,const ACHAR*&,const ACHAR*) const = 0;
    virtual const ACHAR* blockModelSpaceName() const = 0;
    virtual const ACHAR* blockPaperSpaceName() const = 0;
    virtual const ACHAR* layerDefpointsName() const = 0;
    virtual const ACHAR* layerZeroName() const = 0;
    virtual const ACHAR* linetypeByBlockName() const = 0;
    virtual const ACHAR* linetypeByLayerName() const = 0;
    virtual const ACHAR* linetypeContinuousName() const = 0;
    virtual const ACHAR* regAppAcadName() const = 0;
    virtual const ACHAR* textStyleStandardName() const = 0;
    virtual const ACHAR* viewportActiveName() const = 0;
    virtual int compareSymbolName(const ACHAR*,const ACHAR*) const = 0;
};

const Services* servicesPtr();

}

namespace AcDbSymUtil = AcDbSymbolUtilities;
typedef AcDbSymbolUtilities::Services AcDbSymUtilServices;

const AcDbSymUtilServices* acdbSymUtil();
