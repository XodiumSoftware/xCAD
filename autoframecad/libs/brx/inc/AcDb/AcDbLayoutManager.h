// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbLayout.h"
#include "AcDb/AcDbLayoutManagerReactor.h"

/** _ */
class BRX_IMPORTEXPORT AcDbLayoutManager: public AcRxObject
{
public:
    virtual Acad::ErrorStatus cloneLayout(AcDbLayout*, const ACHAR*, int = 0, const AcDbDatabase* = NULL) = 0;
    virtual Acad::ErrorStatus copyLayout(const ACHAR*, const ACHAR*, const AcDbDatabase* = NULL) = 0;
    virtual Acad::ErrorStatus createLayout(const ACHAR*, AcDbObjectId&, AcDbObjectId&,AcDbDatabase* = NULL) = 0;
    virtual Acad::ErrorStatus deleteLayout(const ACHAR*, const AcDbDatabase* = NULL) = 0;
    virtual Acad::ErrorStatus renameLayout(const ACHAR*, const ACHAR*, const AcDbDatabase* = NULL) = 0;
    virtual Acad::ErrorStatus setCurrentLayout(const ACHAR*, const AcDbDatabase* = NULL) = 0;
    virtual Acad::ErrorStatus setCurrentLayoutId(AcDbObjectId) = 0;
    virtual AcDbObjectId getActiveLayoutBTRId(const AcDbDatabase* = NULL) = 0;
    virtual AcDbObjectId getNonRectVPIdFromClipId(AcDbObjectId) = 0;
    virtual bool isVpnumClipped(int, const AcDbDatabase* = NULL) = 0;
    virtual const ACHAR* findActiveLayout(bool, const AcDbDatabase* = NULL) = 0; //deprecated
    virtual int countLayouts(AcDbDatabase* = NULL) = 0;
    virtual void addReactor(AcDbLayoutManagerReactor*) = 0;
    virtual void removeReactor(AcDbLayoutManagerReactor*) = 0;

    Acad::ErrorStatus getLayoutNamed (const ACHAR* name, AcDbLayout*& pLayout, AcDb::OpenMode mode = AcDb::kForRead, const AcDbDatabase* pDb = NULL);
    bool              layoutExists   (const ACHAR* name, const AcDbDatabase* pDb = NULL);

    // since V21
    virtual Acad::ErrorStatus getActiveLayoutName(AcString&, bool allowModel, const AcDbDatabase* = NULL) = 0;

    // since V22
    virtual AcDbObjectId findLayoutNamed(const ACHAR*, const AcDbDatabase* = NULL) = 0;
};
