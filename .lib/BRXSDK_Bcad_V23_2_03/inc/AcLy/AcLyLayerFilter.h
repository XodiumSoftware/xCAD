// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbLayerTableRecord.h"
#include "AcLy/AcLyBoolExpr.h"

/** _ */
class AcLyLayerFilter: public AcRxObject, public AcHeapOperators
{
public:
    enum DialogResult
    {
        kOk = 0,
        kCancel,
        kUseDefault
    };

    ACRX_DECLARE_MEMBERS(AcLyLayerFilter);

    AcLyLayerFilter();
    virtual ~AcLyLayerFilter();

    virtual Acad::ErrorStatus addNested(AcLyLayerFilter*);
    virtual Acad::ErrorStatus generateNested();
    virtual Acad::ErrorStatus getImages(HIMAGELIST&,Adesk::UInt32&,Adesk::UInt32&) const;
    virtual Acad::ErrorStatus readFrom(AcDbDxfFiler*);
    virtual Acad::ErrorStatus removeNested(AcLyLayerFilter*);
    virtual Acad::ErrorStatus setFilterExpression(const ACHAR*);
    virtual Acad::ErrorStatus setName(const ACHAR*);
    virtual Acad::ErrorStatus writeTo(AcDbDxfFiler*) const;
    virtual AcLyLayerFilter* parent() const;
    virtual bool allowDelete() const;
    virtual bool allowNested() const;
    virtual bool allowRename() const;
    virtual bool compareTo(const AcLyLayerFilter*) const;
    virtual bool dynamicallyGenerated() const;
    virtual bool filter(AcDbLayerTableRecord*) const;
    virtual bool isIdFilter() const;
    virtual bool isProxy() const;
    virtual const AcArray<AcLyLayerFilter*>& getNestedFilters() const;
    virtual const ACHAR* filterExpression() const;
    virtual const ACHAR* name() const;
    virtual const AcLyBoolExpr* filterExpressionTree() const;
    virtual DialogResult showEditor();
};