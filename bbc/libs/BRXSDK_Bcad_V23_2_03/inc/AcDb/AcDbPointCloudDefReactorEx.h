// Copyright (C) Menhirs NV. All rights reserved.
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
