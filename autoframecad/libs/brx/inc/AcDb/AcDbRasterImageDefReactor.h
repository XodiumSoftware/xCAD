// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbRasterImageDef.h"

/** _ */
class BRX_EXPORT AcDbRasterImageDefReactor: public AcDbObject
{
public:
    enum DeleteImageEvent
    {
        kUnload = 1,
        kErase
    };

    ACRX_DECLARE_MEMBERS(AcDbRasterImageDefReactor);

    AcDbRasterImageDefReactor();
    virtual ~AcDbRasterImageDefReactor();

    virtual Acad::ErrorStatus dwgInFields(AcDbDwgFiler*);
    virtual Acad::ErrorStatus dwgOutFields(AcDbDwgFiler*) const;
    virtual Acad::ErrorStatus dxfInFields(AcDbDxfFiler*);
    virtual Acad::ErrorStatus dxfOutFields(AcDbDxfFiler*) const;
    virtual Adesk::Boolean onDeleteImage(const AcDbRasterImageDef*,Atil::Image*,DeleteImageEvent,Adesk::Boolean);
    virtual void erased(const AcDbObject*, Adesk::Boolean);
    virtual void modified(const AcDbObject*);

    static ClassVersion classVersion();
    static void setEnable(Adesk::Boolean);
};
