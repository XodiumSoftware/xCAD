// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcCm/AcCmColor.h"
#include "AcDb/AcDbObject.h"

/** _ */
class BRX_EXPORT AcDbGroup: public AcDbObject
{
public:
    ACDB_DECLARE_MEMBERS(AcDbGroup);

    AcDbGroup();
    AcDbGroup(const ACHAR*,bool = true);
    virtual ~AcDbGroup();

    virtual Acad::ErrorStatus applyPartialUndo(AcDbDwgFiler*,AcRxClass*);
    virtual Acad::ErrorStatus dwgInFields(AcDbDwgFiler*);
    virtual Acad::ErrorStatus dwgOutFields(AcDbDwgFiler*) const;
    virtual Acad::ErrorStatus dxfInFields(AcDbDxfFiler*);
    virtual Acad::ErrorStatus dxfOutFields(AcDbDxfFiler*) const;
    virtual Acad::ErrorStatus subClose();
    virtual Acad::ErrorStatus subErase(Adesk::Boolean = Adesk::kTrue);
    virtual void erased(const AcDbObject*, Adesk::Boolean);
    virtual void goodbye(const AcDbObject*);

    Acad::ErrorStatus append(AcDbObjectId);
    Acad::ErrorStatus append(AcDbObjectIdArray);
    Acad::ErrorStatus clear();
    Acad::ErrorStatus getIndex(AcDbObjectId,Adesk::UInt32&) const;
    Acad::ErrorStatus getName(ACHAR*&) const;
    Acad::ErrorStatus insertAt(Adesk::UInt32,AcDbObjectId);
    Acad::ErrorStatus insertAt(Adesk::UInt32,AcDbObjectIdArray);
    Acad::ErrorStatus prepend(AcDbObjectId);
    Acad::ErrorStatus prepend(AcDbObjectIdArray);
    Acad::ErrorStatus remove(AcDbObjectId);
    Acad::ErrorStatus remove(AcDbObjectIdArray);
    Acad::ErrorStatus removeAt(Adesk::UInt32);
    Acad::ErrorStatus removeAt(Adesk::UInt32,AcDbObjectIdArray);
    Acad::ErrorStatus replace(AcDbObjectId,AcDbObjectId);
    Acad::ErrorStatus reverse();
    Acad::ErrorStatus setAnonymous();
    Acad::ErrorStatus setColor(const AcCmColor&);
    Acad::ErrorStatus setColorIndex(Adesk::UInt16);
    Acad::ErrorStatus setDescription(const ACHAR*);
    Acad::ErrorStatus setHighlight(bool);
    Acad::ErrorStatus setLayer(AcDbObjectId);
    Acad::ErrorStatus setLayer(const ACHAR*);
    Acad::ErrorStatus setLinetype(AcDbObjectId);
    Acad::ErrorStatus setLinetype(const ACHAR*);
    Acad::ErrorStatus setLinetypeScale(double);
    Acad::ErrorStatus setMaterial(AcDbObjectId);
    Acad::ErrorStatus setMaterial(const ACHAR*);
    Acad::ErrorStatus setName(const ACHAR*);
    Acad::ErrorStatus setSelectable(bool);
    Acad::ErrorStatus setVisibility(AcDb::Visibility);
    Acad::ErrorStatus transfer(Adesk::UInt32,Adesk::UInt32,Adesk::UInt32);
    AcDbGroupIterator* newIterator();
    Adesk::UInt32 allEntityIds(AcDbObjectIdArray&) const;
    Adesk::UInt32 numEntities() const;
    bool has(const AcDbEntity*) const;
    bool isAnonymous() const;
    bool isNotAccessible() const;
    bool isSelectable() const;
    const ACHAR* description() const;
    const ACHAR* name() const;
};
