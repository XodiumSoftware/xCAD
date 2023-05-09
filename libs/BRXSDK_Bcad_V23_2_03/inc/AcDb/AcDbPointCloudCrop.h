// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

class AcDbPointCloudDxfHandler;
class AcDbPointCloudCropStateManagerImp;
class AcDbPointCloudCropImp;

class BRX_IMPORTEXPORT AcDbPointCloudCrop
{
public:
    enum CropType
    {
        kInvalid = 0,
        kRectangular,
        kPolygonal,
        kCircular
    };

public:
    AcDbPointCloudCrop();
    AcDbPointCloudCrop(const AcDbPointCloudCrop&);
    virtual ~AcDbPointCloudCrop();
    bool operator == (const AcDbPointCloudCrop&) const;
    bool operator != (const AcDbPointCloudCrop&) const;
    AcDbPointCloudCrop& operator=(const AcDbPointCloudCrop&);

public:
    void clear();
    bool isValid() const;
    CropType type() const;
    void setCropType(CropType);
    bool isInside() const;
    void setInside(bool);
    bool isInverted() const;
    void setInvert(bool);
    bool getCropPlane(AcGePlane& plane);
    void setCropPlane(const AcGePlane&);
    int length() const;
    void set(const AcGePoint3dArray&);
    const AcGePoint3dArray& get();
    void setDxfHandler(AcDbPointCloudDxfHandler*);

private:
    AcDbPointCloudCropImp* m_pImp;
    friend AcDbPointCloudCropStateManagerImp;
    AcDbPointCloudCrop(AcDbPointCloudCropImp* imp);
};
