// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "Misc/AcArray.h"
#include "AcCm/AcCmColor.h"
#include "AcCm/AcCmTransparency.h"
#include "AcDb/AcDbFullSubentPath.h"
#include "AcDb/AcDbObject.h"

/** _ */
class BRX_IMPORTEXPORT AcDbEntity: public AcDbObject
{
public:
    ACDB_DECLARE_MEMBERS(AcDbEntity);

protected:
    AcDbEntity();
public:
    virtual ~AcDbEntity();

    enum VisualStyleType
    {
      kFullVisualStyle = 0,
      kFaceVisualStyle = 1,
      kEdgeVisualStyle = 2,
    };

    virtual Acad::ErrorStatus addSubentPaths(const AcDbFullSubentPathArray&) final;
    virtual Acad::ErrorStatus applyPartialUndo(AcDbDwgFiler*,AcRxClass*);
    virtual Acad::ErrorStatus audit(AcDbAuditInfo*);
    virtual Acad::ErrorStatus deleteSubentPaths(const AcDbFullSubentPathArray&) final;
    virtual Acad::ErrorStatus dwgInFields(AcDbDwgFiler*);
    virtual Acad::ErrorStatus dwgOutFields(AcDbDwgFiler*) const;
    virtual Acad::ErrorStatus dxfInFields(AcDbDxfFiler*);
    virtual Acad::ErrorStatus dxfOutFields(AcDbDxfFiler*) const;
    virtual Acad::ErrorStatus explode(AcDbVoidPtrArray&) const final;
    virtual Acad::ErrorStatus getCompoundObjectTransform(AcGeMatrix3d&) const final;
    virtual Acad::ErrorStatus getGeomExtents(AcDbExtents&) const final;
    virtual Acad::ErrorStatus getGripEntityUCS(const void*,AcGeVector3d&,AcGePoint3d&,AcGeVector3d&) const final;
    virtual Acad::ErrorStatus getGripPoints(AcDbGripDataPtrArray&,const double,const int,const AcGeVector3d&,const int) const final;
    virtual Acad::ErrorStatus getGripPoints(AcGePoint3dArray&,AcDbIntArray&,AcDbIntArray&) const final;
    virtual Acad::ErrorStatus getGripPointsAtSubentPath(const AcDbFullSubentPath&,AcDbGripDataPtrArray&,const double,const int,const AcGeVector3d&,const int) const final;
    virtual Acad::ErrorStatus getGsMarkersAtSubentPath(const AcDbFullSubentPath&,AcArray<Adesk::GsMarker>&) const final;
    virtual Acad::ErrorStatus getMaterialMapper(AcGiMapper&) const;
    virtual Acad::ErrorStatus getOsnapPoints(AcDb::OsnapMode,Adesk::GsMarker,const AcGePoint3d&,const AcGePoint3d&,const AcGeMatrix3d&,AcGePoint3dArray&,AcDbIntArray&) const final;
    virtual Acad::ErrorStatus getOsnapPoints(AcDb::OsnapMode,Adesk::GsMarker,const AcGePoint3d&,const AcGePoint3d&,const AcGeMatrix3d&,AcGePoint3dArray&,AcDbIntArray&,const AcGeMatrix3d&) const final;
    virtual Acad::ErrorStatus getPlane(AcGePlane&,AcDb::Planarity&) const;
    virtual Acad::ErrorStatus getStretchPoints(AcGePoint3dArray&) const final;
    virtual Acad::ErrorStatus getSubentClassId(const AcDbFullSubentPath&,CLSID*) const final;
    virtual Acad::ErrorStatus getSubentPathGeomExtents(const AcDbFullSubentPath&,AcDbExtents&) const final;
    virtual Acad::ErrorStatus getSubentPathsAtGsMarker(AcDb::SubentType,Adesk::GsMarker,const AcGePoint3d&,const AcGeMatrix3d&,int&,AcDbFullSubentPath*&,int = 0,AcDbObjectId* = NULL) const final;
    virtual Acad::ErrorStatus getTransformedCopy(const AcGeMatrix3d&,AcDbEntity*&) const final;
    virtual Acad::ErrorStatus highlight(const AcDbFullSubentPath& = kNullSubent,const Adesk::Boolean = Adesk::kFalse) const final;
    virtual Acad::ErrorStatus intersectWith(const AcDbEntity*,AcDb::Intersect,AcGePoint3dArray&,Adesk::GsMarker = 0,Adesk::GsMarker = 0) const final;
    virtual Acad::ErrorStatus intersectWith(const AcDbEntity*,AcDb::Intersect,const AcGePlane&,AcGePoint3dArray&,Adesk::GsMarker = 0,Adesk::GsMarker = 0) const final;
    virtual Acad::ErrorStatus moveGripPointsAt(const AcDbIntArray&,const AcGeVector3d&) final;
    virtual Acad::ErrorStatus moveGripPointsAt(const AcDbVoidPtrArray&,const AcGeVector3d&,const int) final;
    virtual Acad::ErrorStatus moveGripPointsAtSubentPaths(const AcDbFullSubentPathArray&,const AcDbVoidPtrArray&,const AcGeVector3d&,const int) final;
    virtual Acad::ErrorStatus moveStretchPointsAt(const AcDbIntArray&,const AcGeVector3d&) final;
    virtual Acad::ErrorStatus setColor(const AcCmColor&,Adesk::Boolean = Adesk::kTrue);
    virtual Acad::ErrorStatus setColor(const AcCmColor&, bool, AcDbDatabase*);
    virtual Acad::ErrorStatus setColorIndex(Adesk::UInt16,Adesk::Boolean = Adesk::kTrue);
    virtual Acad::ErrorStatus setLayer(AcDbObjectId,Adesk::Boolean = Adesk::kTrue,bool = false);
    virtual Acad::ErrorStatus setLayer(const ACHAR*,Adesk::Boolean = Adesk::kTrue,bool = false);
    virtual Acad::ErrorStatus setLinetype(AcDbObjectId,Adesk::Boolean = Adesk::kTrue);
    virtual Acad::ErrorStatus setLinetype(const ACHAR*,Adesk::Boolean = Adesk::kTrue);
    virtual Acad::ErrorStatus setLinetypeScale(double,Adesk::Boolean = Adesk::kTrue);
    virtual Acad::ErrorStatus setLineWeight(AcDb::LineWeight,Adesk::Boolean = Adesk::kTrue);
    virtual Acad::ErrorStatus setMaterial(AcDbObjectId,Adesk::Boolean = Adesk::kTrue);
    virtual Acad::ErrorStatus setMaterial(const ACHAR*,Adesk::Boolean = Adesk::kTrue);
    virtual Acad::ErrorStatus setMaterialMapper(const AcGiMapper&,Adesk::Boolean = Adesk::kTrue);
    virtual Acad::ErrorStatus setPlotStyleName(AcDb::PlotStyleNameType,AcDbObjectId = AcDbObjectId::kNull,Adesk::Boolean = Adesk::kTrue);
    virtual Acad::ErrorStatus setPlotStyleName(const ACHAR*,Adesk::Boolean = Adesk::kTrue);
    virtual Acad::ErrorStatus setTransparency(const AcCmTransparency&,Adesk::Boolean = Adesk::kTrue);
    virtual Acad::ErrorStatus setVisibility(AcDb::Visibility,Adesk::Boolean = Adesk::kTrue) final;
    virtual Acad::ErrorStatus transformBy(const AcGeMatrix3d&) final;
    virtual Acad::ErrorStatus transformSubentPathsBy(const AcDbFullSubentPathArray&,const AcGeMatrix3d&) final;
    virtual Acad::ErrorStatus unhighlight(const AcDbFullSubentPath& = kNullSubent,const Adesk::Boolean = Adesk::kFalse) const final;
    virtual AcDb::CollisionType collisionType() const;
    virtual AcDbEntity* subentPtr(const AcDbFullSubentPath&) const final;
    virtual AcGiDrawable* drawable();
    virtual AcGsNode* gsNode() const;
    virtual Adesk::Boolean cloneMeForDragging() final;
    virtual Adesk::Boolean isPlanar() const;
    virtual bool castShadows() const;
    virtual bool hideMeForDragging() const final;
    virtual bool receiveShadows() const;
    virtual void dragStatus(const AcDb::DragStat);
    virtual void getEcs(AcGeMatrix3d&) const;
    virtual void gripStatus(const AcDb::GripStat) final;
    virtual void list() const final;
    virtual void saveAs(AcGiWorldDraw*,AcDb::SaveType);
    virtual void setCastShadows(bool);
    virtual void setGsNode(AcGsNode*);
    virtual void setReceiveShadows(bool);
    virtual void subentGripStatus(const AcDb::GripStat,const AcDbFullSubentPath&) final;
    virtual void subSetDatabaseDefaults(AcDbDatabase*);
    virtual Acad::ErrorStatus setVisualStyle(AcDbObjectId, VisualStyleType = kFullVisualStyle, Adesk::Boolean = true);
    virtual bool isContentSnappable() const final;
    virtual bool bounds(AcDbExtents&) const;

    Acad::ErrorStatus boundingBoxIntersectWith(const AcDbEntity*,AcDb::Intersect,AcGePoint3dArray&,Adesk::GsMarker,Adesk::GsMarker) const;
    Acad::ErrorStatus boundingBoxIntersectWith(const AcDbEntity*,AcDb::Intersect,const AcGePlane&,AcGePoint3dArray&,Adesk::GsMarker,Adesk::GsMarker) const;
    Acad::ErrorStatus draw();
    Acad::ErrorStatus setPropertiesFrom(const AcDbEntity*,Adesk::Boolean = Adesk::kTrue);
    AcCmColor color() const;
    AcCmEntityColor entityColor() const;
    AcCmTransparency transparency() const;
    AcDb::LineWeight lineWeight() const;
    AcDb::PlotStyleNameType getPlotStyleNameId(AcDbObjectId&) const;
    AcDb::Visibility visibility() const;
    AcDbObjectId blockId() const;
    AcDbObjectId layerId() const;
    AcDbObjectId linetypeId() const;
    AcDbObjectId materialId() const;
    ACHAR* layer() const;
    ACHAR* linetype() const;
    ACHAR* material() const;
    ACHAR* plotStyleName() const;
    Adesk::UInt16 colorIndex() const;
    double linetypeScale() const;
    void recordGraphicsModified(Adesk::Boolean = Adesk::kTrue);
    void setDatabaseDefaults();
    void setDatabaseDefaults(AcDbDatabase*);
    AcDbObjectId visualStyleId(VisualStyleType = kFullVisualStyle) const;

protected:
    friend class AcGiDrawableOverrule;
    virtual Adesk::Boolean subWorldDraw(AcGiWorldDraw*);
    virtual Adesk::UInt32 subSetAttributes(AcGiDrawableTraits*);
    virtual void subViewportDraw(AcGiViewportDraw*);

    friend class AcDbVisibilityOverrule;
    virtual AcDb::Visibility subVisibility() const;
    virtual Acad::ErrorStatus subSetVisibility(AcDb::Visibility, Adesk::Boolean = true);

    friend class AcDbTransformOverrule;
    virtual Acad::ErrorStatus subTransformBy(const AcGeMatrix3d&);
    virtual Acad::ErrorStatus subGetTransformedCopy(const AcGeMatrix3d&, AcDbEntity*&) const;
    virtual Acad::ErrorStatus subExplode(AcDbVoidPtrArray&) const;
    virtual Adesk::Boolean subCloneMeForDragging();
    virtual bool subHideMeForDragging() const;

    friend class AcDbPropertiesOverrule;
    virtual void subList() const;

    friend class AcDbGeometryOverrule;
    virtual Acad::ErrorStatus subIntersectWith(const AcDbEntity*, AcDb::Intersect, AcGePoint3dArray&,
        Adesk::GsMarker = 0, Adesk::GsMarker = 0) const;
    virtual Acad::ErrorStatus subIntersectWith(const AcDbEntity*, AcDb::Intersect, const AcGePlane&,
        AcGePoint3dArray&, Adesk::GsMarker = 0, Adesk::GsMarker = 0) const;
    virtual Acad::ErrorStatus subGetGeomExtents(AcDbExtents&) const;
    virtual Acad::ErrorStatus subGetGripEntityUCS(const void*, AcGeVector3d&, AcGePoint3d&,
        AcGeVector3d&) const;

    friend class AcDbSubentityOverrule;
    virtual Acad::ErrorStatus subGetCompoundObjectTransform(AcGeMatrix3d&) const;
    virtual Acad::ErrorStatus subGetSubentClassId(const AcDbFullSubentPath&, CLSID*) const;
    virtual Acad::ErrorStatus subAddSubentPaths(const AcDbFullSubentPathArray&);
    virtual Acad::ErrorStatus subDeleteSubentPaths(const AcDbFullSubentPathArray&);
    virtual Acad::ErrorStatus subTransformSubentPathsBy(const AcDbFullSubentPathArray&, const AcGeMatrix3d&);
    virtual Acad::ErrorStatus subGetGripPointsAtSubentPath(const AcDbFullSubentPath&, AcDbGripDataPtrArray&,
        const double, const int, const AcGeVector3d&, const int) const;
    virtual Acad::ErrorStatus subMoveGripPointsAtSubentPaths(const AcDbFullSubentPathArray&, const AcDbVoidPtrArray&,
        const AcGeVector3d&, const int);
    virtual Acad::ErrorStatus subGetSubentPathGeomExtents(const AcDbFullSubentPath&, AcDbExtents&) const;
    virtual Acad::ErrorStatus subGetSubentPathsAtGsMarker(AcDb::SubentType, Adesk::GsMarker, const AcGePoint3d&,
        const AcGeMatrix3d&, int&, AcDbFullSubentPath*&, int = 0, AcDbObjectId* = nullptr) const;
    virtual Acad::ErrorStatus subGetGsMarkersAtSubentPath(const AcDbFullSubentPath&, AcArray<Adesk::GsMarker>&) const;
    virtual AcDbEntity* subSubentPtr(const AcDbFullSubentPath&) const;
    virtual void subSubentGripStatus(const AcDb::GripStat, const AcDbFullSubentPath&);

    friend class AcDbOsnapOverrule;
    virtual Acad::ErrorStatus subGetOsnapPoints(AcDb::OsnapMode, Adesk::GsMarker, const AcGePoint3d&,
        const AcGePoint3d&, const AcGeMatrix3d&, AcGePoint3dArray&, AcDbIntArray&) const;
    virtual Acad::ErrorStatus subGetOsnapPoints(AcDb::OsnapMode, Adesk::GsMarker, const AcGePoint3d&,
        const AcGePoint3d&, const AcGeMatrix3d&, AcGePoint3dArray&, AcDbIntArray&, const AcGeMatrix3d&) const;
    virtual bool subIsContentSnappable() const;

    friend class AcDbGripOverrule;
    virtual void subGripStatus(const AcDb::GripStat);
    virtual Acad::ErrorStatus subGetGripPoints(AcGePoint3dArray&, AcDbIntArray&, AcDbIntArray&) const;
    virtual Acad::ErrorStatus subGetGripPoints(AcDbGripDataPtrArray&, const double, const int,
        const AcGeVector3d&, const int) const;
    virtual Acad::ErrorStatus subMoveGripPointsAt(const AcDbIntArray&, const AcGeVector3d&);
    virtual Acad::ErrorStatus subMoveGripPointsAt(const AcDbVoidPtrArray&, const AcGeVector3d&, const int);
    virtual Acad::ErrorStatus subGetStretchPoints(AcGePoint3dArray&) const;
    virtual Acad::ErrorStatus subMoveStretchPointsAt(const AcDbIntArray&, const AcGeVector3d&);

    friend class AcDbHighlightOverrule;
    virtual Acad::ErrorStatus subHighlight(const AcDbFullSubentPath& = kNullSubent, const Adesk::Boolean = false) const;
    virtual Acad::ErrorStatus subUnhighlight(const AcDbFullSubentPath& = kNullSubent, const Adesk::Boolean = false) const;
};

// BRX specific
typedef AcArray< AcDbEntity*, AcArrayMemCopyReallocator<AcDbEntity*> >  AcDbEntityPtrArray;
