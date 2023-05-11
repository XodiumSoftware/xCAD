// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

class AcPointCloudExtractedCylinderImp;

class BRX_IMPORTEXPORT AcPointCloudExtractedCylinder
{
public:
    AcPointCloudExtractedCylinder();
    AcPointCloudExtractedCylinder(double, double, AcGeVector3d = AcGeVector3d::kZAxis, AcGePoint3d = AcGePoint3d::kOrigin);
    virtual ~AcPointCloudExtractedCylinder();

    AcPointCloudExtractedCylinder(const AcPointCloudExtractedCylinder&);
    bool operator == (const AcPointCloudExtractedCylinder&) const;
    bool operator != (const AcPointCloudExtractedCylinder&) const;
    AcPointCloudExtractedCylinder& operator = (const AcPointCloudExtractedCylinder&);

    const static AcPointCloudExtractedCylinder kInvalid;

public:
    bool isValid() const;
    void clear();
    AcGeVector3d getAxis() const;
    void setAxis(AcGeVector3d);
    AcGePoint3d getOrigin() const;
    void setOrigin(AcGePoint3d);
    double getHeight() const;
    void setHeight(double);
    double getRadius() const;
    void setRadius(double);

private:
    AcPointCloudExtractedCylinderImp* m_pImp;
};
