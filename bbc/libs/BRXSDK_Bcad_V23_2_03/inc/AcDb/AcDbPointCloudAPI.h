// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

/** _ */
class IAcDbPointCloudDataBuffer
{
public:
    enum DataType
    {
        kIntensity = 1,
        kClassification = 2,
        kColor = 4,
        kNormal = 8
    };
    typedef Adesk::UInt8 RGBA[4];

public:
    virtual ~IAcDbPointCloudDataBuffer() {};
    virtual Adesk::UInt64 numPoints() const = 0;
    virtual const AcGePoint3d* points() const = 0;
    virtual const AcGeVector3d* normals() const = 0;
    virtual const RGBA* colors() const = 0;
    virtual const Adesk::UInt8* intensity()  const = 0;
    virtual const Adesk::UInt8* classifications() const = 0;
    virtual const AcGeMatrix3d& transform() const = 0;
    virtual void freeObject() = 0;
    virtual void* getBuffer() const = 0;
};

class IAcDbPointCloudSpatialFilter
{
public:
    enum FilterResult
    {
        FILTER_INSIDE = 0,
        FILTER_OUTSIDE,
        FILTER_INTERSECTS
    };

public:
    virtual ~IAcDbPointCloudSpatialFilter() {};
    virtual FilterResult testCell(const AcGePoint3d&, const AcGePoint3d&) const = 0;
    virtual FilterResult testPoint(const AcGePoint3d&) const = 0;
    virtual IAcDbPointCloudSpatialFilter* transformFilter(const AcGeMatrix3d&) const = 0;
    virtual IAcDbPointCloudSpatialFilter* clone() const = 0;
    virtual void freeObject() = 0;
};

class IAcDbPointCloudAttributeFilter
{
public:
    virtual ~IAcDbPointCloudAttributeFilter() {};
    virtual bool testPoint(const Adesk::UInt8 rgba[4], Adesk::UInt8, const float[3], Adesk::UInt8) const = 0;
    virtual IAcDbPointCloudAttributeFilter* clone() const = 0;
    virtual IAcDbPointCloudAttributeFilter* transformFilter(const AcGeMatrix3d&) const = 0;
    virtual void freeObject() = 0;
};

class IAcDbPointCloudPointProcessor
{
public:
    enum ProcessSate
    {
        Abort = 0,
        Continue
    };
    virtual ~IAcDbPointCloudPointProcessor() {};
    virtual ProcessSate process(const IAcDbPointCloudDataBuffer*) = 0;
};
