// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbGlobal.h"

/** _ */
class BRX_IMPORTEXPORT AcDbLoftOptions
{
//BRX START
private:
    friend class BrxDbLoftOptionsImp;
    class BrxDbLoftOptionsImp* m_pBrxImp;
//BRX END

public:
    enum NormalOption
    {
        kNoNormal = 0,
        kFirstNormal,
        kLastNormal,
        kEndsNormal,
        kAllNormal,
        kUseDraftAngles
    };

    AcDbLoftOptions();
    AcDbLoftOptions(const AcDbLoftOptions&);
    ~AcDbLoftOptions();

    Acad::ErrorStatus checkCrossSectionCurves(AcArray<AcDbEntity*>&,bool&,bool&,bool&,bool = false);
    Acad::ErrorStatus checkGuideCurves(AcArray<AcDbEntity*>&,bool = false);
    Acad::ErrorStatus checkLoftCurves(AcArray<AcDbEntity*>&,AcArray<AcDbEntity*>&,AcDbEntity*,bool&,bool&,bool&,bool = false);
    Acad::ErrorStatus checkOptions(bool = false);
    Acad::ErrorStatus checkPathCurve(AcDbEntity*,bool = false);
    Acad::ErrorStatus setOptionsFromSysvars();
    Acad::ErrorStatus setSysvarsFromOptions();
    bool alignDirection() const;
    bool arcLengthParam() const;
    bool closed() const;
    bool noTwist() const;
    bool ruled() const;
    bool simplify() const;
    bool virtualGuide() const;
    double draftEnd() const;
    double draftEndMag() const;
    double draftStart() const;
    double draftStartMag() const;
    bool periodic() const;
    NormalOption normal() const;
    void setAlignDirection(bool);
    void setArcLengthParam(bool);
    void setClosed(bool);
    void setDraftEnd(double);
    void setDraftEndMag(double);
    void setDraftStart(double);
    void setDraftStartMag(double);
    void setNormal(NormalOption);
    void setNoTwist(bool);
    void setRuled(bool);
    void setSimplify(bool);
    void setVirtualGuide(bool);
    void setPeriodic(bool);

    AcDbLoftOptions& operator=(const AcDbLoftOptions&);
};
