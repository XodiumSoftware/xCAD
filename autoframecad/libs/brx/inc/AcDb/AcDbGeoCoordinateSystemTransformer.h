// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

class BrxDbGeoCoordinateSystemTransformerImp;


class BRX_IMPORTEXPORT AcDbGeoCoordinateSystemTransformer
{
public:
    AcDbGeoCoordinateSystemTransformer();
    virtual ~AcDbGeoCoordinateSystemTransformer();

    static Acad::ErrorStatus create(const AcString&, const AcString&,
        AcDbGeoCoordinateSystemTransformer*&);

    static Acad::ErrorStatus transformPoint(const AcString&, const AcString&,
        const AcGePoint3d&, AcGePoint3d&);
    static Acad::ErrorStatus transformPoints(const AcString&, const AcString&,
        const AcGePoint3dArray&, AcGePoint3dArray&);

    virtual Acad::ErrorStatus getSourceCoordinateSystemId(AcString&) const = 0;
    virtual Acad::ErrorStatus getTargetCoordinateSystemId(AcString&) const = 0;
    virtual Acad::ErrorStatus transformPoint(const AcGePoint3d&, AcGePoint3d&) const = 0;
    virtual Acad::ErrorStatus transformPoints(const AcGePoint3dArray&, AcGePoint3dArray&) const = 0;

private:
    friend BrxDbGeoCoordinateSystemTransformerImp;
    BrxDbGeoCoordinateSystemTransformerImp* m_pBrxImp;
};
