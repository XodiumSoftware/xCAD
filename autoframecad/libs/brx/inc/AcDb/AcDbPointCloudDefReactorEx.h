// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

class PointCloudDefReactorExImp;

class BRX_IMPORTEXPORT AcDbPointCloudDefReactorEx : public AcDbObject
{
public:
    static int classVersion();
    static void setEnable(Adesk::Boolean);
    static Adesk::Boolean isEnabled();

    ACRX_DECLARE_MEMBERS(AcDbPointCloudDefReactorEx);

    AcDbPointCloudDefReactorEx();
    ~AcDbPointCloudDefReactorEx();

    //Acad::ErrorStatus dwgInFields(AcDbDwgFiler*) override;
    //Acad::ErrorStatus dwgOutFields(AcDbDwgFiler*) const override;
    //Acad::ErrorStatus dxfInFields(AcDbDxfFiler*) override;
    //Acad::ErrorStatus dxfOutFields(AcDbDxfFiler*) const override;
    //void erased(const AcDbObject*, Adesk::Boolean = true) override;
    //void modified(const AcDbObject*) override;

private:
    PointCloudDefReactorExImp* m_pImp;
};
