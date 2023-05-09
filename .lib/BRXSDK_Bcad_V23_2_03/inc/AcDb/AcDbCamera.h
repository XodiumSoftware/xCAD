// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbEntity.h"

/** _ */
class BRX_EXPORT AcDbCamera: public AcDbEntity
{
public:
    ACDB_DECLARE_MEMBERS(AcDbCamera);

    AcDbCamera ();
    virtual ~AcDbCamera();

    virtual Acad::ErrorStatus dwgInFields(AcDbDwgFiler*);
    virtual Acad::ErrorStatus dwgOutFields(AcDbDwgFiler*) const;
    virtual Acad::ErrorStatus dxfInFields(AcDbDxfFiler*);
    virtual Acad::ErrorStatus dxfOutFields(AcDbDxfFiler*) const;
    virtual Acad::ErrorStatus subClose();
    virtual Acad::ErrorStatus subErase(Adesk::Boolean);
    virtual Acad::ErrorStatus subOpen(AcDb::OpenMode);

    Acad::ErrorStatus setView(const AcDbObjectId);
    AcDbObjectId view() const;

protected:
    virtual Acad::ErrorStatus subDeepClone(AcDbObject*,AcDbObject*&,AcDbIdMapping&,Adesk::Boolean = Adesk::kTrue) const;
    virtual Acad::ErrorStatus subGetGripPoints(AcDbGripDataPtrArray&,const double,const int,const AcGeVector3d&,const int) const;
    virtual Acad::ErrorStatus subGetStretchPoints(AcGePoint3dArray&) const;
    virtual Acad::ErrorStatus subHighlight(const AcDbFullSubentPath& = kNullSubent,const Adesk::Boolean = Adesk::kFalse) const;
    virtual Acad::ErrorStatus subMoveGripPointsAt(const AcDbVoidPtrArray&,const AcGeVector3d&,const int);
    virtual Acad::ErrorStatus subMoveStretchPointsAt(const AcDbIntArray&,const AcGeVector3d&);
    virtual Acad::ErrorStatus subTransformBy(const AcGeMatrix3d&);
    virtual Acad::ErrorStatus subUnhighlight(const AcDbFullSubentPath& = kNullSubent,const Adesk::Boolean = Adesk::kFalse) const;
    virtual Acad::ErrorStatus subWblockClone(AcRxObject*,AcDbObject*&,AcDbIdMapping&,Adesk::Boolean = Adesk::kTrue) const;
    virtual Adesk::Boolean subWorldDraw(AcGiWorldDraw*);
    virtual Adesk::UInt32 subSetAttributes(AcGiDrawableTraits*);
    virtual void subList() const;
    virtual void subViewportDraw(AcGiViewportDraw*);
};
