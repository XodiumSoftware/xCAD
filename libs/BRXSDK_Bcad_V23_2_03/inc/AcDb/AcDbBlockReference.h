// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbEntity.h"
#include "AcGe/AcGeMatrix3d.h"

/** _ */
class BRX_EXPORT AcDbBlockReference: public AcDbEntity
{
public:
    ACDB_DECLARE_MEMBERS(AcDbBlockReference);

    AcDbBlockReference();
    AcDbBlockReference(const AcGePoint3d&,AcDbObjectId);
    ~AcDbBlockReference();

    virtual Acad::ErrorStatus explodeToOwnerSpace() const;
    virtual Acad::ErrorStatus getPlane(AcGePlane&,AcDb::Planarity&) const;
    virtual Acad::ErrorStatus setBlockTableRecord(AcDbObjectId);
    virtual Acad::ErrorStatus setBlockTransform(const AcGeMatrix3d&);
    virtual Acad::ErrorStatus setNormal(const AcGeVector3d&);
    virtual Acad::ErrorStatus setPosition(const AcGePoint3d&);
    virtual Acad::ErrorStatus setRotation(double);
    virtual Acad::ErrorStatus setScaleFactors(const AcGeScale3d&);
    virtual Adesk::Boolean isPlanar() const;
    virtual Adesk::Boolean treatAsAcDbBlockRefForExplode() const;
    virtual AcGePoint3d position() const;

    Acad::ErrorStatus appendAttribute(AcDbAttribute*);
    Acad::ErrorStatus appendAttribute(AcDbObjectId&,AcDbAttribute*);
    Acad::ErrorStatus geomExtentsBestFit(AcDbExtents&,const AcGeMatrix3d& = AcGeMatrix3d::kIdentity) const;
    Acad::ErrorStatus openAttribute(AcDbAttribute*&,AcDbObjectId,AcDb::OpenMode,bool = false);
    Acad::ErrorStatus openSequenceEnd(AcDbSequenceEnd*&,AcDb::OpenMode);
    AcDbObjectId blockTableRecord() const;
    AcDbObjectIterator* attributeIterator() const;

    AcGeMatrix3d blockTransform() const;
    AcGeScale3d scaleFactors() const;
    AcGeVector3d normal() const;
    double rotation() const;

    AcGeMatrix3d nonAnnotationBlockTransform() const;
    AcGeScale3d  nonAnnotationScaleFactors() const;

protected:
    virtual Acad::ErrorStatus subGetClassID(CLSID*) const;
    virtual Acad::ErrorStatus subGetGsMarkersAtSubentPath(const AcDbFullSubentPath&,AcArray<Adesk::GsMarker>&) const;
    virtual Acad::ErrorStatus subGetSubentPathsAtGsMarker(AcDb::SubentType,Adesk::GsMarker,const AcGePoint3d&,const AcGeMatrix3d&,int&,AcDbFullSubentPath*&,int = 0,AcDbObjectId* = NULL) const;
    virtual Acad::ErrorStatus subGetTransformedCopy(const AcGeMatrix3d&, AcDbEntity*&) const;
    virtual Acad::ErrorStatus subHighlight(const AcDbFullSubentPath& = kNullSubent,const Adesk::Boolean = Adesk::kFalse) const;
    virtual Acad::ErrorStatus subUnhighlight(const AcDbFullSubentPath& = kNullSubent,const Adesk::Boolean = Adesk::kFalse) const;
    virtual AcDbEntity* subSubentPtr(const AcDbFullSubentPath&) const;
    virtual Adesk::Boolean subWorldDraw(AcGiWorldDraw*);
    virtual void subGripStatus(const AcDb::GripStat);
};
