// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbGlobal.h"
#include "AcGe/AcGeGlobal.h"

/** _ */
class BRX_IMPORTEXPORT AcDbSweepOptions
{
//BRX START
private:
    friend class BrxDbSweepOptionsImp;
    class BrxDbSweepOptionsImp* m_pBrxImp;
//BRX END
public:
    enum AlignOption
    {
        kNoAlignment = 0,
        kAlignSweepEntityToPath,
        kTranslateSweepEntityToPath,
        kTranslatePathToSweepEntity
    };

    enum MiterOption
    {
        kDefaultMiter = 0,
        kOldMiter,
        kNewMiter,
        kCrimpMiter,
        kBendMiter
    };

    AcDbSweepOptions();
    AcDbSweepOptions(const AcDbSweepOptions&);
    ~AcDbSweepOptions();

    Acad::ErrorStatus checkPathCurve(AcDbEntity*,bool = false);
    Acad::ErrorStatus checkSweepCurve(AcDbEntity*,AcDb::Planarity&,AcGePoint3d&,AcGeVector3d&,bool&,double&,bool = false);
    Acad::ErrorStatus setPathEntityTransform(AcDbEntity*,bool = false);
    Acad::ErrorStatus setSweepEntityTransform(AcArray<AcDbEntity*>&,bool = false);
    AcGePoint3d basePoint() const;
    AcGeVector3d twistRefVec() const;
    AlignOption align() const;
    bool alignStart() const;
    bool bank() const;
    bool checkIntersections() const;
    bool getPathEntityTransform(AcGeMatrix3d&);
    bool getSweepEntityTransform(AcGeMatrix3d&);
    double alignAngle() const;
    double draftAngle() const;
    double endDraftDist() const;
    double scaleFactor() const;
    double startDraftDist() const;
    double twistAngle() const;
    MiterOption miterOption() const;
    void setAlign(AlignOption);
    void setAlignAngle(double);
    void setAlignStart(bool);
    void setBank(bool);
    void setBasePoint(AcGePoint3d&);
    void setCheckIntersections(bool);
    void setDraftAngle(double);
    void setEndDraftDist(double);
    void setMiterOption(MiterOption);
    void setPathEntityTransform(AcGeMatrix3d&);
    void setScaleFactor(double);
    void setStartDraftDist(double);
    void setSweepEntityTransform(AcGeMatrix3d&);
    void setTwistAngle(double);
    void setTwistRefVec(const AcGeVector3d&);

    AcDbSweepOptions& operator=(const AcDbSweepOptions&);
};
