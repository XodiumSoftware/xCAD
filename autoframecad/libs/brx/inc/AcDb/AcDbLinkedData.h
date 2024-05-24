// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDbObject.h"
#include "AcDb/AcDbGlobal.h"
#include "AcDbDataLink.h"

class BRX_IMPORTEXPORT AcDbLinkedData : public AcDbObject
{
public:
    ACDB_DECLARE_MEMBERS(AcDbLinkedData);

    AcDbLinkedData();
    virtual ~AcDbLinkedData();

    Acad::ErrorStatus dwgInFields(AcDbDwgFiler* pFiler) override;
    Acad::ErrorStatus dwgOutFields(AcDbDwgFiler* pFiler) const override;
    Acad::ErrorStatus dxfInFields(AcDbDxfFiler* pFiler) override;
    Acad::ErrorStatus dxfOutFields(AcDbDxfFiler* pFiler) const override;
   
    virtual Acad::ErrorStatus clear(void);
    virtual Acad::ErrorStatus setName(const ACHAR* pszName);
    virtual Acad::ErrorStatus setDescription(const ACHAR* pszDescription);

    virtual bool isEmpty() const;

    virtual const ACHAR* name() const;
    virtual const ACHAR* description() const;
};
