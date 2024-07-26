// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

class BRX_IMPORTEXPORT PointCloudBinaryOperatorFilter : public IPointCloudFilter
{
public:
    virtual ~PointCloudBinaryOperatorFilter();
    int testCell(double, double, double, double, double, double) const  override = 0;
    bool testPoint(float, float, float) const override = 0;
    IPointCloudFilter* clone() const override = 0;
    void freeObject(void) override = 0;
    bool isInverted() const override;
    void setIsInverted(bool) override;

protected:
    PointCloudBinaryOperatorFilter(IPointCloudFilter*, IPointCloudFilter*);
    PointCloudBinaryOperatorFilter(const PointCloudBinaryOperatorFilter&);

protected:
    IPointCloudFilter* mpLeftFilter;
    IPointCloudFilter* mpRightFilter;

private:
    bool m_isInverted;

private:
    PointCloudBinaryOperatorFilter& operator = (const PointCloudBinaryOperatorFilter&);
};

class BRX_IMPORTEXPORT PointCloudIntersectionFilter : public PointCloudBinaryOperatorFilter
{
public:
    PointCloudIntersectionFilter(IPointCloudFilter*, IPointCloudFilter*);
    ~PointCloudIntersectionFilter();

    int testCell(double, double, double, double, double, double) const override;
    bool testPoint(float, float, float) const override;
    IPointCloudFilter* clone() const override;
    void freeObject(void) override;
};

class BRX_IMPORTEXPORT PointCloudUnionFilter : public PointCloudBinaryOperatorFilter
{
public:
    PointCloudUnionFilter(IPointCloudFilter*, IPointCloudFilter*);
    ~PointCloudUnionFilter();

    int testCell(double, double, double, double, double, double) const override;
    bool testPoint(float, float, float) const override;
    IPointCloudFilter* clone() const override;
    void freeObject(void) override;
};

class BRX_IMPORTEXPORT PointCloudXORFilter : public PointCloudBinaryOperatorFilter
{
public:
    PointCloudXORFilter(IPointCloudFilter*, IPointCloudFilter*);
    ~PointCloudXORFilter();

    int testCell(double, double, double, double, double, double) const override;
    bool testPoint(float, float, float) const override;
    IPointCloudFilter* clone() const override;
    void freeObject(void) override;
};
