// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcRx/AcRxObject.h"
#include "AcDb/AcDbGlobal.h"
#include "Misc/AcArray.h"
#include "AcDb/AcDbSubentId.h"
#include "AcDb/AcDbAssocPersSubentId.h"

class AcRxClass;
class AcDbDatabase;
class AcDbEntity;
class AcDbDwgFiler;
class AcDbAuditInfo;
class AcDbDxfFiler;
class AcGeMatrix3d;
class AcGePoint3d;
class AcGeEntity3d;
class AcGeCurve3d;
class AcGeSurface;
class AcDbGeometryProjector;
class AcDbCompoundObjectId;


enum RigidSetType
{
    kNotRigidSet         = 0,
    kScalableRigidSet    = 1,
    kNonScalableRigidSet = 2,
};


/** _ */
class BRX_EXPORT AcDbAssocPersSubentIdPE: public AcRxObject
{
public:
    ACRX_DECLARE_MEMBERS(AcDbAssocPersSubentIdPE);

    AcDbAssocPersSubentIdPE();
    virtual ~AcDbAssocPersSubentIdPE();

    virtual Acad::ErrorStatus getTransientSubentIds(const AcDbEntity*, AcDbDatabase*, const AcDbAssocPersSubentId*, AcDbSubentIdArray&) const;
    virtual Acad::ErrorStatus getAllSubentities(const AcDbEntity*, AcDb::SubentType, AcDbSubentIdArray&);
    virtual Acad::ErrorStatus getAllSubentities(const AcDbEntity*, const AcRxClass*, AcDbSubentIdArray&);

    virtual Acad::ErrorStatus getVertexSubentityGeometry(const AcDbEntity*, const AcDbSubentId&, AcGePoint3d&);
    virtual Acad::ErrorStatus getEdgeVertexSubentities(const AcDbEntity*, const AcDbSubentId&, AcDbSubentId&, AcDbSubentId&, AcDbSubentIdArray&);

    virtual Acad::ErrorStatus getSplineEdgeVertexSubentities(const AcDbEntity*, const AcDbSubentId&, AcDbSubentId&, AcDbSubentId&, AcDbSubentIdArray&, AcDbSubentIdArray&);
    virtual Acad::ErrorStatus getEdgeSubentityGeometry(const AcDbEntity*, const AcDbSubentId&, AcGeCurve3d*&);
    virtual Acad::ErrorStatus getFaceSubentityGeometry(const AcDbEntity*, const AcDbSubentId&, AcGeSurface*&);

    virtual Acad::ErrorStatus getSubentityGeometry(const AcDbEntity*, const AcDbSubentId&, AcGeEntity3d*&);
    virtual Acad::ErrorStatus getSubentGeometryXform(const AcDbEntity*, const AcDbObjectIdArray&, AcGeMatrix3d&) const;

    virtual Acad::ErrorStatus getFaceSilhouetteGeometry(AcDbEntity*, AcRxObject*, const AcDbSubentId&, const AcGeMatrix3d*, AcDbGeometryProjector*, AcArray<int>&, AcArray<AcGeCurve3d*>&);
    virtual Acad::ErrorStatus getTransientFaceSilhouetteIds(AcDbEntity*, AcDbDatabase*, AcRxObject*, const AcDbSubentId&, const AcGeMatrix3d*, AcDbGeometryProjector*, const AcDbAssocPersSubentId*, AcArray<int>&);
    virtual Acad::ErrorStatus getRigidSetTransform(const AcDbEntity*, AcGeMatrix3d&);

    virtual Acad::ErrorStatus setSubentityGeometry(AcDbEntity*, const AcDbSubentId&, const AcGeEntity3d*);
    virtual Acad::ErrorStatus setVertexSubentityGeometry(AcDbEntity*, const AcDbSubentId&, const AcGePoint3d&);
    virtual Acad::ErrorStatus setEdgeSubentityGeometry(AcDbEntity*, const AcDbSubentId&, const AcGeCurve3d*);
    virtual Acad::ErrorStatus setFaceSubentityGeometry(AcDbEntity*, const AcDbSubentId&, const AcGeSurface*);
    virtual Acad::ErrorStatus setRigidSetTransform(AcDbEntity*, const AcGeMatrix3d&);

    virtual Acad::ErrorStatus mirrorPersSubent(const AcDbEntity*, AcDbDatabase*, AcDbAssocPersSubentId*);
    virtual Acad::ErrorStatus transferPersSubentToAnotherEntity(AcDbEntity*, AcDbDatabase*, AcDbEntity*, AcDbDatabase*, const AcDbAssocPersSubentId*);
    virtual Acad::ErrorStatus makePersSubentPurgeable(AcDbEntity*, AcDbDatabase*, const AcDbAssocPersSubentId*, bool);

    virtual int getRigidSetState(const AcDbEntity*);

    virtual AcDbAssocPersSubentId* createNewPersSubent(AcDbEntity*, AcDbDatabase*, const AcDbCompoundObjectId&, const AcDbSubentId&);
    virtual AcDbAssocPersSubentId* createNewPersFaceSilhouetteId(AcDbEntity*, AcDbDatabase*, AcRxObject*, const AcDbCompoundObjectId&, const AcDbSubentId&, const AcGeMatrix3d*, AcDbGeometryProjector*, int);

    virtual Acad::ErrorStatus releasePersSubent(AcDbEntity*, AcDbDatabase*, const AcDbAssocPersSubentId*);
};