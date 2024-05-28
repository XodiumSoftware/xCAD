// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbSymbolTableRecord.h"

/** _ */
class BRX_EXPORT AcDbBlockTableRecord: public AcDbSymbolTableRecord
{
public:
    typedef AcDbBlockTable TableType;
    typedef AcArray<Adesk::UInt8> PreviewIcon;

    enum BlockScaling
    {
        kAny = 0,
        kUniform
    };

    ACDB_DECLARE_MEMBERS(AcDbBlockTableRecord);

    AcDbBlockTableRecord();
    virtual ~AcDbBlockTableRecord();

    virtual Acad::ErrorStatus assumeOwnershipOf(AcDbObjectIdArray);
    virtual Acad::ErrorStatus decomposeForSave(AcDb::AcDbDwgVersion,AcDbObject*&,AcDbObjectId&,Adesk::Boolean&);
    virtual Acad::ErrorStatus dwgOutFields(AcDbDwgFiler*) const;
    virtual Acad::ErrorStatus dxfOutFields(AcDbDxfFiler*) const;

    Acad::ErrorStatus appendAcDbEntity(AcDbEntity*);
    Acad::ErrorStatus appendAcDbEntity(AcDbObjectId&,AcDbEntity*);
    Acad::ErrorStatus comments(ACHAR*&) const;
    Acad::ErrorStatus comments(const ACHAR*&) const;
    Acad::ErrorStatus getBlockReferenceIds(AcDbObjectIdArray&,bool = true,bool = false) const;
    Acad::ErrorStatus getErasedBlockReferenceIds(AcDbObjectIdArray&);
    Acad::ErrorStatus getPreviewIcon(PreviewIcon&) const;
    Acad::ErrorStatus getSortentsTable(AcDbSortentsTable*&,AcDb::OpenMode,bool = false);
    Acad::ErrorStatus newBlockReferenceIdIterator(AcDbBlockReferenceIdIterator*&) const;
    Acad::ErrorStatus newIterator(AcDbBlockTableRecordIterator*&,bool = true,bool = true) const;
    Acad::ErrorStatus openBlockBegin(AcDbBlockBegin*&,AcDb::OpenMode);
    Acad::ErrorStatus openBlockEnd(AcDbBlockEnd*&,AcDb::OpenMode);
    Acad::ErrorStatus pathName(ACHAR*&) const;
    Acad::ErrorStatus pathName(const ACHAR*&) const;
    Acad::ErrorStatus setBlockInsertUnits(AcDb::UnitsValue);
    Acad::ErrorStatus setBlockScaling(BlockScaling);
    Acad::ErrorStatus setComments(const ACHAR*);
    Acad::ErrorStatus setExplodable(bool);
    Acad::ErrorStatus setIsUnloaded(bool);
    Acad::ErrorStatus setLayoutId(AcDbObjectId);
    Acad::ErrorStatus setOrigin(const AcGePoint3d&);
    Acad::ErrorStatus setPathName(const ACHAR*);
    Acad::ErrorStatus setPreviewIcon(const PreviewIcon&);
    AcDb::UnitsValue blockInsertUnits() const;
    AcDb::XrefStatus xrefStatus() const;
    AcDbDatabase* xrefDatabase(bool = false) const;
    AcDbObjectId getLayoutId() const;
    AcGePoint3d origin() const;
    AcGiDrawable* drawable();
    BlockScaling blockScaling() const;
    bool explodable() const;
    bool hasAttributeDefinitions() const;
    bool hasPreviewIcon() const;
    bool isAnonymous() const;
    bool isFromExternalReference() const;
    bool isFromOverlayReference() const;
    bool isLayout() const;
    bool isUnloaded() const;
    Acad::ErrorStatus addAnnoScalestoBlkRefs(const bool = false);
    Acad::ErrorStatus postProcessAnnotativeBTR(int&, const bool = false, const bool = true);

protected:
    virtual Acad::ErrorStatus subGetClassID(CLSID*) const;
    virtual Adesk::Boolean subWorldDraw(AcGiWorldDraw*);
    virtual Adesk::UInt32 subSetAttributes(AcGiDrawableTraits*);
    virtual void subViewportDraw(AcGiViewportDraw*);
};
