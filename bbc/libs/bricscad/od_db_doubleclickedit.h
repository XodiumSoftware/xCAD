// od_db_doubleclickedit.h : OdDbDoubleClickEdit class definition

// Copyright © Menhirs NV. All rights reserved.

//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH

#pragma once

#include "od_api_exports.h"

class ODAPI OdDbDoubleClickEdit: public OdRxObject
{
public:
    ODRX_DECLARE_MEMBERS(OdDbDoubleClickEdit);

    virtual void finishEdit() = 0;
    virtual void startEdit(OdDbEntity*,OdGePoint3d) = 0;
};
