// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcRx/AcRxObject.h"

/** _ */
class BRX_IMPORTEXPORT AcDbDatabaseSummaryInfo: public AcRxObject
{
public:
    ACRX_DECLARE_MEMBERS(AcDbDatabaseSummaryInfo);

protected:
    AcDbDatabaseSummaryInfo();
public:
    virtual ~AcDbDatabaseSummaryInfo() {}

    virtual Acad::ErrorStatus addCustomSummaryInfo(const ACHAR*,const ACHAR*) = 0;
    virtual Acad::ErrorStatus deleteCustomSummaryInfo(const ACHAR*) = 0;
    virtual Acad::ErrorStatus deleteCustomSummaryInfo(const int) = 0;
    virtual Acad::ErrorStatus getAuthor(ACHAR*&) const = 0;
    virtual Acad::ErrorStatus getComments(ACHAR*&) const = 0;
    virtual Acad::ErrorStatus getCustomSummaryInfo(const ACHAR*,ACHAR*&) const = 0;
    virtual Acad::ErrorStatus getCustomSummaryInfo(const int,ACHAR*&,ACHAR*&) const = 0;
    virtual Acad::ErrorStatus getHyperlinkBase(ACHAR*&) const = 0;
    virtual Acad::ErrorStatus getKeywords(ACHAR*&) const = 0;
    virtual Acad::ErrorStatus getLastSavedBy(ACHAR*&) const = 0;
    virtual Acad::ErrorStatus getRevisionNumber(ACHAR*&) const = 0;
    virtual Acad::ErrorStatus getSubject(ACHAR*&) const = 0;
    virtual Acad::ErrorStatus getTitle(ACHAR*&) const = 0;
    virtual Acad::ErrorStatus setAuthor(const ACHAR*) = 0;
    virtual Acad::ErrorStatus setComments(const ACHAR*) = 0;
    virtual Acad::ErrorStatus setCustomSummaryInfo(const ACHAR*,const ACHAR*) = 0;
    virtual Acad::ErrorStatus setCustomSummaryInfo(const int,const ACHAR*,const ACHAR*) = 0;
    virtual Acad::ErrorStatus setHyperlinkBase(const ACHAR*) = 0;
    virtual Acad::ErrorStatus setKeywords(const ACHAR*) = 0;
    virtual Acad::ErrorStatus setLastSavedBy(const ACHAR*) = 0;
    virtual Acad::ErrorStatus setRevisionNumber(const ACHAR*) = 0;
    virtual Acad::ErrorStatus setSubject(const ACHAR*) = 0;
    virtual Acad::ErrorStatus setTitle(const ACHAR*) = 0;
    virtual AcDbDatabase* database() const = 0;
    virtual int numCustomInfo() const = 0;
    virtual void setDatabase(AcDbDatabase*) = 0;
};
