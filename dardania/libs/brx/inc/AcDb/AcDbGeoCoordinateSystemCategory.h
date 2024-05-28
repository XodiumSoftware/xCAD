// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

class AcDbGeoCoordinateSystem;
class BrxDbGeoCoordinateSystemCategoryImp;


class BRX_IMPORTEXPORT AcDbGeoCoordinateSystemCategory
{
public:
    AcDbGeoCoordinateSystemCategory();
    virtual ~AcDbGeoCoordinateSystemCategory();

    static Acad::ErrorStatus createAll(AcArray<AcDbGeoCoordinateSystemCategory*>&);

    virtual Acad::ErrorStatus getCoordinateSystemAt(int, AcDbGeoCoordinateSystem*&) const = 0;
    virtual Acad::ErrorStatus getId(AcString&) const = 0;
    virtual Acad::ErrorStatus getNumOfCoordinateSystem(int&) const = 0;

private:
    friend BrxDbGeoCoordinateSystemCategoryImp;
    BrxDbGeoCoordinateSystemCategoryImp* m_pBrxImp;
};
