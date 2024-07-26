// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcBr/AcBrGlobal.h"
#include "AcBr/AcBrMassProps.h"

class AcDbFullSubentPath;
class AcGeBoundBlock3d;
class AcGeLinearEnt3d;
class AcGePoint3d;
class AcBrEntity;
struct AcBrMassProps;

class AcBrEntity: public AcRxObject
{
public:
    ACRX_DECLARE_MEMBERS(AcBrEntity);

protected:
    friend class BrxBrEntityImp;
    class BrxBrEntityImp* m_pBrxImp;

    AcBrEntity();
    AcBrEntity(const AcBrEntity&);
public:
    virtual ~AcBrEntity();

    AcBr::ErrorStatus get(AcDbFullSubentPath&) const;
    AcBr::ErrorStatus getBoundBlock(AcGeBoundBlock3d&) const;
    AcBr::ErrorStatus getBrep(AcBrBrep&) const;
    AcBr::ErrorStatus getLineContainment(const AcGeLinearEnt3d&,const Adesk::UInt32&,Adesk::UInt32&,AcBrHit*&) const;
    AcBr::ErrorStatus getMassProps(AcBrMassProps&,const double& = 0.0,const double& = 0.0,double& = defaultDoubleNull) const;
    AcBr::ErrorStatus getPerimeterLength(double&,const double& = 0.0,double& = defaultDoubleNull) const;
    AcBr::ErrorStatus getPointContainment(const AcGePoint3d&,AcGe::PointContainment&,AcBrEntity*&) const;
    AcBr::ErrorStatus getSubentPath(AcDbFullSubentPath&) const;
    AcBr::ErrorStatus getSurfaceArea(double&,const double& = 0.0,double& = defaultDoubleNull) const;
    AcBr::ErrorStatus getValidationLevel(AcBr::ValidationLevel&) const;
    AcBr::ErrorStatus getVolume(double&,const double& = 0.0,double& = defaultDoubleNull) const;
    AcBr::ErrorStatus set(const AcDbFullSubentPath&);
    AcBr::ErrorStatus setEntity(void*,AcDbFullSubentPath& = defaultNullFSP);
    AcBr::ErrorStatus setSubentPath(AcDbFullSubentPath&);
    AcBr::ErrorStatus setValidationLevel(const AcBr::ValidationLevel& = AcBr::kFullValidation);
    Adesk::Boolean brepChanged() const;
    Adesk::Boolean checkEntity() const;
    Adesk::Boolean isEqualTo(const AcRxObject*) const;
    Adesk::Boolean isNull() const;
    void* getEntity() const;

public:
    // for internal use only
    BrxBrEntityImp* getImpl() const { return m_pBrxImp; };

protected:
    AcBrEntity& operator=(const AcBrEntity&);
};
