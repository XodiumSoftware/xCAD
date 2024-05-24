// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcGe/AcGeEntity3d.h"

/** _ */
class BRX_IMPORTEXPORT AcGeBoundBlock3d: public AcGeEntity3d
{
public:
    AcGeBoundBlock3d();
    AcGeBoundBlock3d(const AcGeBoundBlock3d&);
    AcGeBoundBlock3d(const AcGePoint3d&,const AcGeVector3d&,const AcGeVector3d&,const AcGeVector3d&);

    AcGeBoundBlock3d& extend(const AcGePoint3d&);
    AcGeBoundBlock3d& set(const AcGePoint3d&,const AcGePoint3d&);
    AcGeBoundBlock3d& set(const AcGePoint3d&,const AcGeVector3d&,const AcGeVector3d&,const AcGeVector3d&);
    AcGeBoundBlock3d& setToBox(Adesk::Boolean);
    AcGeBoundBlock3d& swell(double);
    Adesk::Boolean contains(const AcGePoint3d&) const;
    Adesk::Boolean isBox() const;
    Adesk::Boolean isDisjoint(const AcGeBoundBlock3d&) const;
    void get(AcGePoint3d&,AcGeVector3d&,AcGeVector3d&,AcGeVector3d&) const;
    void getMinMaxPoints(AcGePoint3d&,AcGePoint3d&) const;

    AcGeBoundBlock3d& operator=(const AcGeBoundBlock3d&);
};