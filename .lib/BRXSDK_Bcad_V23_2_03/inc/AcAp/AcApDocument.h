// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcAp/AcApGlobal.h"
#include "AcRx/AcRxObject.h"
#include "Misc/AcLispAppInfo.h"
#include "AcDb/AcDbGlobal.h"

/** _ */
class BRX_IMPORTEXPORT AcApDocument: public AcRxObject
{
public:
    enum SaveFormat
    {
        kUnknown = -1,
        kR12_dxf = 1,
        kR13_dwg = 4,
        kR13_dxf = 5,
        kR14_dwg = 8,
        kR14_dxf = 9,
        k2000_dwg = 12,
        kR15_dwg = 12,
        k2000_dxf = 13,
        kR15_dxf = 13,
        k2000_Template = 14,
        kR15_Template = 14,
        k2000_Standard = 15,
        kR15_Standard = 15,
        k2000_xml = 16,
        kR15_xml = 16,
        k2004_dwg = 24,
        kR18_dwg = 24,
        k2004_dxf = 25,
        kR18_dxf = 25,
        k2004_Template = 26,
        kR18_Template = 26,
        k2004_Standard = 27,
        kR18_Standard = 27,
        k2007_dwg = 36,
        k2007_dxf = 37,
        k2007_Template = 38,
        k2007_Standard = 39,
        k2010_dwg = 48,
        k2010_dxf = 49,
        k2010_Template = 50,
        k2010_Standard = 51,
        k2013_dwg = 60,
        k2013_dxf = 61,
        k2013_Template = 62,
        k2013_Standard = 63,
        k2018_dwg = 64,
        k2018_dxf = 65,
        k2018_Template = 66,
        k2018_Standard = 67,

        kNative = k2018_dwg,
        kNative_Template = k2018_Template,
     };

    ACRX_DECLARE_MEMBERS(AcApDocument);

    virtual AcAp::DocLockMode lockMode(bool = false) const = 0;
    virtual AcAp::DocLockMode myLockMode() const = 0;
    virtual AcApStatusBar* drawingStatusBar() const = 0;
    virtual AcDbDatabase* database() const = 0;
    virtual AcEdInputPointManager* inputPointManager() = 0;
    virtual AcLispAppInfo* GetItemOfLispList(int) const = 0;
    virtual AcTransactionManager* transactionManager() const = 0;
    virtual bool isQuiescent() const = 0;
    virtual bool isReadOnly() const = 0;
    virtual CDocument* cDoc() const = 0;
    virtual const ACHAR* docTitle() const = 0;
    virtual const ACHAR* fileName() const = 0;
    virtual IDispatch* GetIDispatch(bool) = 0;
    virtual int GetCountOfLispList() const = 0;
    virtual SaveFormat formatForSave() const = 0;
    virtual void* contextPtr() const = 0;
    virtual bool isCommandInputInactive() const = 0;

    void setDocTitle(const ACHAR*);
    Acad::ErrorStatus popDbmod();
    void pushDbmod();
    bool isNamedDrawing() const;

    Acad::ErrorStatus downgradeDocOpen(bool);
    Acad::ErrorStatus upgradeDocOpen();

    static Acad::ErrorStatus getDwgVersionFromSaveFormat(SaveFormat, AcDb::AcDbDwgVersion&, AcDb::MaintenanceReleaseVersion&);

    // BRX_START
    bool saveAs(const ACHAR*, AcApDocument::SaveFormat = AcApDocument::kNative);
    // BRX_END
};
