// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbOleFrame.h"
#include "Misc/CRectangle3d.h"

/** _ */
class BRX_EXPORT AcDbOle2Frame: public AcDbOleFrame
{
public:
    ACDB_DECLARE_MEMBERS(AcDbOle2Frame);

    AcDbOle2Frame();
    virtual ~AcDbOle2Frame();

    virtual Acad::ErrorStatus dwgInFields(AcDbDwgFiler*);
    virtual Acad::ErrorStatus dwgOutFields(AcDbDwgFiler*) const;
    virtual Acad::ErrorStatus dxfInFields(AcDbDxfFiler*);
    virtual Acad::ErrorStatus dxfOutFields(AcDbDxfFiler*) const;
    virtual Acad::ErrorStatus setTransparency(const AcCmTransparency&, Adesk::Boolean = Adesk::kTrue);
    virtual Adesk::Boolean getLinkName(ACHAR*, int) const;
    virtual Adesk::Boolean getLinkPath(ACHAR*, int) const;
    virtual Adesk::UInt8 outputQuality() const;
    virtual bool castShadows() const;
    virtual bool receiveShadows() const;
    virtual int getType() const;
    virtual void getLocation(AcGePoint3d&) const;
    virtual void getUserType(ACHAR*, int) const;
    virtual void position(CRectangle3d&) const;
    virtual void position(RECT&) const;
    virtual void saveAs(AcGiWorldDraw*,AcDb::SaveType);
    virtual void setCastShadows(bool);
    virtual void setOleObject(const void*);
    virtual void setOutputQuality(Adesk::UInt8);
    virtual void setPosition(const CRectangle3d&);
    virtual void setPosition(const RECT&);
    virtual void setReceiveShadows(bool);
    virtual void* getOleObject() const;

    Acad::ErrorStatus setLockAspect(const Adesk::Boolean);
    Acad::ErrorStatus setRotation(const double);
    Acad::ErrorStatus setScaleHeight(const double);
    Acad::ErrorStatus setScaleWidth(const double);
    Acad::ErrorStatus setWcsHeight(const double);
    Acad::ErrorStatus setWcsWidth(const double);
    AcCmTransparency transparency() const;
    AcDb::Visibility visibility() const;
    Adesk::Boolean autoOutputQuality() const;
    Adesk::Boolean lockAspect() const;
    double rotation() const;
    double scaleHeight() const;
    double scaleWidth() const;
    double wcsHeight() const;
    double wcsWidth() const;
    void setAutoOutputQuality(Adesk::UInt8);
    void setLocation(const AcGePoint3d&);

    Acad::ErrorStatus getUserType(AcString&) const;
    Acad::ErrorStatus getLinkName(AcString&) const;
    Acad::ErrorStatus getLinkPath(AcString&) const;

protected:
    virtual Acad::ErrorStatus subExplode(AcDbVoidPtrArray&) const;
    virtual Acad::ErrorStatus subGetGeomExtents(AcDbExtents&) const;
    virtual Acad::ErrorStatus subGetGripPoints(AcGePoint3dArray&,AcDbIntArray&,AcDbIntArray&) const;
    virtual Acad::ErrorStatus subGetGsMarkersAtSubentPath(const AcDbFullSubentPath&,AcArray<Adesk::GsMarker>&) const;
    virtual Acad::ErrorStatus subGetOsnapPoints(AcDb::OsnapMode,Adesk::GsMarker,const AcGePoint3d&,const AcGePoint3d&,const AcGeMatrix3d&,AcGePoint3dArray&,AcDbIntArray&) const;
    virtual Acad::ErrorStatus subGetStretchPoints(AcGePoint3dArray&) const;
    virtual Acad::ErrorStatus subGetSubentPathsAtGsMarker(AcDb::SubentType,Adesk::GsMarker,const AcGePoint3d&,const AcGeMatrix3d&,int&,AcDbFullSubentPath*&,int = 0,AcDbObjectId* = NULL) const;
    virtual Acad::ErrorStatus subGetTransformedCopy(const AcGeMatrix3d&,AcDbEntity*&) const;
    virtual Acad::ErrorStatus subIntersectWith(const AcDbEntity*,AcDb::Intersect,AcGePoint3dArray&,Adesk::GsMarker = 0,Adesk::GsMarker = 0) const;
    virtual Acad::ErrorStatus subIntersectWith(const AcDbEntity*,AcDb::Intersect,const AcGePlane&,AcGePoint3dArray&,Adesk::GsMarker = 0,Adesk::GsMarker = 0) const;
    virtual void subList() const;
    virtual Acad::ErrorStatus subMoveGripPointsAt(const AcDbIntArray&,const AcGeVector3d&);
    virtual Acad::ErrorStatus subMoveStretchPointsAt(const AcDbIntArray&,const AcGeVector3d&);
    virtual Acad::ErrorStatus subSetVisibility(AcDb::Visibility,Adesk::Boolean = Adesk::kTrue);
    virtual Acad::ErrorStatus subTransformBy(const AcGeMatrix3d&);
    virtual AcDbEntity* subSubentPtr(const AcDbFullSubentPath&) const;
    virtual void subViewportDraw(AcGiViewportDraw*);
    virtual Adesk::Boolean subWorldDraw(AcGiWorldDraw*);
};
