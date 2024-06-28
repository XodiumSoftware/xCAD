// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbGlobal.h"
#include "AcGe/AcGeGlobal.h"

/** _ */
class BRX_IMPORTEXPORT AcDbRevolveOptions
{
//BRX START
private:
    friend class BrxDbRevolveOptionsImp;
    class BrxDbRevolveOptionsImp* m_pBrxImp;
//BRX END
public:
    AcDbRevolveOptions();
    AcDbRevolveOptions(const AcDbRevolveOptions&);
    ~AcDbRevolveOptions();

    Acad::ErrorStatus checkRevolveCurve(AcDbEntity*,const AcGePoint3d&,const AcGeVector3d&,bool&,bool&,bool&,bool = false);
    bool closeToAxis() const;
    double draftAngle() const;
    double twistAngle() const;
    void setCloseToAxis(bool);
    void setDraftAngle(double);
    void setTwistAngle(double);

    AcDbRevolveOptions& operator=(const AcDbRevolveOptions&);
};
