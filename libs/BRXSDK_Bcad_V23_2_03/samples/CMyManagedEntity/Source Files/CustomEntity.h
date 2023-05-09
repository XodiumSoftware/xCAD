// Copyright (C) Menhirs NV. All rights reserved.
//The entity represents a circle that is controlled by 3 points

#pragma once

#include "Stdafx.h"
#include "mgdinterop.h"

using namespace System;

#ifdef _BCAD

using namespace Teigha::Geometry;
using namespace Teigha::DatabaseServices;
using namespace Teigha::Runtime;

#else

using namespace Autodesk::AutoCAD::Runtime;
using namespace Autodesk::AutoCAD::Geometry;
using namespace Autodesk::AutoCAD::DatabaseServices;

#endif

class CMyEntity;
class CMyEntityDerived;

namespace CustomManagedEntity 
{

[Wrapper("CMyEntity")]
public ref class CMyManagedEntity : public Entity
{
public:
    CMyManagedEntity();

public protected:
    CMyManagedEntity(System::IntPtr unmanagedPointer, bool autoDelete);
    CMyEntity*  GetImpObj();

public:
    property Point3d Point1
    {
    void set(Point3d value);
    }

    property Point3d Point2
    {
    void set(Point3d value);
    }

    property Point3d Point3
    {
    void set(Point3d value);
    }
};

[Wrapper("CMyEntityDerived")]
public ref class CMyManagedEntityDerived : public CMyManagedEntity
{
public:
    CMyManagedEntityDerived();

public protected:
    CMyManagedEntityDerived(System::IntPtr unmanagedPointer, bool autoDelete);
    CMyEntityDerived*  GetImpObj();
};

}

class CMyEntity : public AcDbEntity
{
private:
    // stored in DWG
    AcGePoint3d m_point1;
    AcGePoint3d m_point2;
    AcGePoint3d m_point3;

public:
    ACRX_DECLARE_MEMBERS(CMyEntity);

public:
    CMyEntity();
    CMyEntity(const AcGePoint3d&,const AcGePoint3d&,const AcGePoint3d&);
    virtual ~CMyEntity() {};

    virtual Acad::ErrorStatus dwgOutFields(AcDbDwgFiler*) const;
    virtual Acad::ErrorStatus dwgInFields(AcDbDwgFiler*);
    virtual Acad::ErrorStatus dxfOutFields(AcDbDxfFiler*) const;
    virtual Acad::ErrorStatus dxfInFields(AcDbDxfFiler*);

    virtual Adesk::Boolean subWorldDraw(AcGiWorldDraw*);
    virtual Acad::ErrorStatus subGetGripPoints(AcGePoint3dArray&,AcDbIntArray&,AcDbIntArray&) const;
    virtual Acad::ErrorStatus subMoveGripPointsAt(const AcDbIntArray&,const AcGeVector3d&);
    virtual Acad::ErrorStatus subGetOsnapPoints(AcDb::OsnapMode,Adesk::GsMarker,const AcGePoint3d&,const AcGePoint3d&,const AcGeMatrix3d&,AcGePoint3dArray&,AcDbIntArray&) const;
    virtual Acad::ErrorStatus subTransformBy(const AcGeMatrix3d&);

    Acad::ErrorStatus set_Point1(AcGePoint3d pnt);
    Acad::ErrorStatus set_Point2(AcGePoint3d pnt);
    Acad::ErrorStatus set_Point3(AcGePoint3d pnt);
};

//////////////////////////////////////////////////////////////////////////
class CMyEntityDerived : public CMyEntity
{
public:
    ACRX_DECLARE_MEMBERS(CMyEntityDerived);

public:
    CMyEntityDerived();
    CMyEntityDerived(const AcGePoint3d&,const AcGePoint3d&,const AcGePoint3d&);
    virtual ~CMyEntityDerived() {};
};

ACDB_REGISTER_OBJECT_ENTRY_AUTO(CMyEntity)
ACDB_REGISTER_OBJECT_ENTRY_AUTO(CMyEntityDerived)
