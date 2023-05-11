// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

class IPointCloudFilter;
class AcPointCloudViewFrustum;

class BRX_IMPORTEXPORT AcViewFrustum
{
public:
    AcViewFrustum();
    ~AcViewFrustum();

    void setNearUpperRight(double, double, double);
    void setNearUpperLeft(double, double, double);
    void setNearLowerLeft(double, double, double);
    void setNearLowerRight(double, double, double);

    void setFarUpperRight(double, double, double);
    void setFarUpperLeft(double, double, double);
    void setFarLowerLeft(double, double, double);
    void setFarLowerRight(double, double, double);

    void nearUpperRight(double&, double&, double&) const;
    void nearUpperLeft(double&, double&, double&) const;
    void nearLowerLeft(double&, double&, double&) const;
    void nearLowerRight(double&, double&, double&) const;

    void farUpperRight(double&, double&, double&) const;
    void farUpperLeft(double&, double&, double&) const;
    void farLowerLeft(double&, double&, double&) const;
    void farLowerRight(double&, double&, double&) const;

    void setNearClip(bool);
    bool nearClip() const;

    void setFarClip(bool);
    bool farClip() const;

    AcPointCloudViewFrustum* asPointCloudFrustum() const;

private:
    void* m_pImp;
};

class BRX_IMPORTEXPORT AcPcPointFloat
{
public:
    float m_x;
    float m_y;
    float m_z;
    DWORD m_argb;
};

class BRX_IMPORTEXPORT AcPcPointDouble
{
public:
    double m_x;
    double m_y;
    double m_z;
    DWORD m_argb;
};

class BRX_IMPORTEXPORT AcPcPointAttributes
{
public:
    float m_intensity;
    float m_nx;
    float m_ny;
    float m_nz;
    BYTE m_classification;
};

class BRX_IMPORTEXPORT IAcPcDataBuffer
{
public:
    virtual ~IAcPcDataBuffer() {}

    virtual bool nativeDbl() = 0;
    virtual bool resize(DWORD size) = 0;
    virtual bool shrink(DWORD size) = 0;
    virtual DWORD size() const = 0;

    virtual AcPcPointFloat* floatPoints() = 0;
    virtual AcPcPointDouble* doublePoints() = 0;

    virtual AcPcPointAttributes* pointAttributes() = 0;

    virtual bool floatPoint(DWORD ptIx, AcPcPointFloat& pt) const = 0;
    virtual bool doublePoint(DWORD ptIx, AcPcPointDouble& pt) const = 0;

    virtual bool setDoublePoint(DWORD ptIx, AcPcPointDouble& pt) = 0;

    virtual bool offset(double&, double&, double&) const = 0;
    virtual bool entityTransform(AcGeMatrix3d& matrix) const = 0;

    virtual void copyFrom(IAcPcDataBuffer const& from) = 0;
};

class BRX_IMPORTEXPORT IAcPcPointFilter
{
public:
    virtual void doFilter(const IAcPcDataBuffer& inBuffer, IAcPcDataBuffer& outBuffer) = 0;
};

class BRX_IMPORTEXPORT IAcPcPointProcessor
{
public:
    virtual bool cancel() = 0;
    virtual void abort() = 0;
    virtual void finished() = 0;
    virtual bool processPoints() = 0;
    virtual IAcPcPointFilter* filter() = 0;
    IAcPcDataBuffer* buffer();
    void setBuffer(IAcPcDataBuffer* buffer);

private:
    IAcPcDataBuffer* m_pBuffer;
};

BRX_IMPORTEXPORT Acad::ErrorStatus acdbCreatePointCloudEntity(AcDbEntity*&, const AcString&, const AcString&,
    AcGePoint3d&, double = 1.0, double = 0.0);

BRX_IMPORTEXPORT Acad::ErrorStatus acdbAttachPointCloudExEntity(AcDbObjectId&, const AcString&, AcGePoint3d&,
    double = 1.0, double = 0.0, AcDbDatabase* = NULL);

BRX_IMPORTEXPORT Acad::ErrorStatus acdbAttachPointCloudEntity( AcDbObjectId&, const AcString&, const AcString&,
    AcGePoint3d&, double = 1.0, double = 0.0, AcDbDatabase* = NULL);

BRX_IMPORTEXPORT Acad::ErrorStatus acdbModifyPointCloudDataView(AcDbEntity*, IAcPcPointFilter*);

BRX_IMPORTEXPORT Acad::ErrorStatus acdbResetPointCloudDataView(AcDbEntity*);

BRX_IMPORTEXPORT Acad::ErrorStatus acdbProcessPointCloudData(AcDbEntity*, const AcDbExtents&, int, IAcPcPointProcessor*);

BRX_IMPORTEXPORT Acad::ErrorStatus acdbProcessPointCloudData(AcDbEntity*, const AcViewFrustum&, int, IAcPcPointProcessor*);

BRX_IMPORTEXPORT Acad::ErrorStatus acdbSetPointCloudFilter(AcDbEntity*, IPointCloudFilter*);
