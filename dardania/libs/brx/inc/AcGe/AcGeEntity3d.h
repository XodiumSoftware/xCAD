// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcGe/AcGeEntity2d.h"
#include "AcGe/AcGePoint3d.h"

/** _ */
class BRX_IMPORTEXPORT AcGeEntity3d
{
protected:
    friend class BrxGeEntity3dImp;

    BrxGeEntity3dImp* m_pBrxImp;

    AcGeEntity3d();
    AcGeEntity3d(const AcGeEntity3d&);
public:
    //BRX START
    virtual
    //BRX END
        ~AcGeEntity3d();

    AcGe::EntityId type() const;
    AcGeEntity3d& mirror(const AcGePlane&);
    AcGeEntity3d& rotateBy(double,const AcGeVector3d&,const AcGePoint3d& = AcGePoint3d::kOrigin);
    AcGeEntity3d& scaleBy(double,const AcGePoint3d& = AcGePoint3d::kOrigin);
    AcGeEntity3d& transformBy(const AcGeMatrix3d&);
    AcGeEntity3d& translateBy(const AcGeVector3d&);
    AcGeEntity3d* copy() const;
    Adesk::Boolean isEqualTo(const AcGeEntity3d&,const AcGeTol& = AcGeContext::gTol) const;
    Adesk::Boolean isKindOf(AcGe::EntityId) const;
    Adesk::Boolean isOn(const AcGePoint3d&,const AcGeTol& = AcGeContext::gTol) const;

    AcGeEntity3d& operator=(const AcGeEntity3d&);
    Adesk::Boolean operator!=(const AcGeEntity3d&) const;
    Adesk::Boolean operator==(const AcGeEntity3d&) const;
};
