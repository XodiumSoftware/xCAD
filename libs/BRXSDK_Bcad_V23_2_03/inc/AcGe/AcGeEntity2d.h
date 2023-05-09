// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcGe/AcGePoint2d.h"

/** _ */
class BRX_IMPORTEXPORT AcGeEntity2d
{
protected:
    friend class AcGeEntity3d;
    friend class BrxGeEntity3dImp;

    class BrxGeEntity3dImp* m_pBrxImp;

    AcGeEntity2d();
    AcGeEntity2d(const AcGeEntity2d&);
public:
    //BRX START
    virtual
    //BRX END
        ~AcGeEntity2d();

    AcGe::EntityId type() const;
    AcGeEntity2d& mirror(const AcGeLine2d&);
    AcGeEntity2d& rotateBy(double,const AcGePoint2d& = AcGePoint2d::kOrigin);
    AcGeEntity2d& scaleBy(double,const AcGePoint2d& = AcGePoint2d::kOrigin);
    AcGeEntity2d& transformBy(const AcGeMatrix2d&);
    AcGeEntity2d& translateBy(const AcGeVector2d&);
    AcGeEntity2d* copy() const;
    Adesk::Boolean isEqualTo(const AcGeEntity2d&,const AcGeTol& = AcGeContext::gTol) const;
    Adesk::Boolean isKindOf(AcGe::EntityId) const;
    Adesk::Boolean isOn(const AcGePoint2d&,const AcGeTol& = AcGeContext::gTol) const;

    AcGeEntity2d& operator=(const AcGeEntity2d&);
    Adesk::Boolean operator!=(const AcGeEntity2d&) const;
    Adesk::Boolean operator==(const AcGeEntity2d&) const;
};
