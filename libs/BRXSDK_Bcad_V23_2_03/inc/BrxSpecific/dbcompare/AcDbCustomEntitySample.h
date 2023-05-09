#pragma once


class AcDbCustomEntitySample : public AcDbEntity
{
public:
    ACRX_DECLARE_MEMBERS(AcDbCustomEntitySample);

protected:
    static Adesk::UInt32 kCurrentVersionNumber;

public:
    AcDbCustomEntitySample();
    virtual ~AcDbCustomEntitySample() {}

    virtual Acad::ErrorStatus dwgOutFields(AcDbDwgFiler*) const;
    virtual Acad::ErrorStatus dwgInFields(AcDbDwgFiler*);

    virtual Acad::ErrorStatus subTransformBy(const AcGeMatrix3d&);
    virtual Adesk::Boolean subWorldDraw(AcGiWorldDraw*);

public:
    void setCenter(const AcGePoint3d&);
    AcGePoint3d getCenter() const;

    void setRadiusParent(const double&);
    double getRadiusParent() const;

private:
    AcGePoint3d m_center;
    double m_radiusParent;
};

ACDB_REGISTER_OBJECT_ENTRY_AUTO(AcDbCustomEntitySample)
