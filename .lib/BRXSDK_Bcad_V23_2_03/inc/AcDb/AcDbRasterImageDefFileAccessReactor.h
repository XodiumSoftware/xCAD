// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbObjectReactor.h"
#include "AcDb/AcDbRasterImageDef.h"

/** _ */
class AcDbRasterImageDefFileAccessReactor: public AcDbObjectReactor
{
public:
    ACRX_DECLARE_MEMBERS(AcDbRasterImageDefFileAccessReactor);

    virtual ~AcDbRasterImageDefFileAccessReactor();

    virtual Adesk::Boolean onOpen(const AcDbRasterImageDef*,const ACHAR*,const ACHAR*,Adesk::Boolean&,ACHAR*&) = 0;
    virtual Adesk::Boolean onPathChange(const AcDbRasterImageDef*,const ACHAR*,const ACHAR*,Adesk::Boolean&,ACHAR*&) = 0;
    virtual void onAttach(const AcDbRasterImageDef*,const ACHAR*) = 0;
    virtual void onClose(const AcDbRasterImageDef*,const ACHAR*) = 0;
    virtual void onDetach(const AcDbRasterImageDef*,const ACHAR*) = 0;
    virtual void onDialog(AcDbRasterImageDef*,const ACHAR*,const ACHAR*) = 0;
};
