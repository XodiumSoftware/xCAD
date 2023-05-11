// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcAp/AcApGlobal.h"
#include "AcDb/AcDbGlobal.h"
#include "AcRx/AcRxObject.h"

class AcGePoint3d;
class AcEdInputPointFilterResultImp;

/** _ */
class BRX_IMPORTEXPORT AcEdInputPointFilterResult
{
public:
    ~AcEdInputPointFilterResult();

    const AcGePoint3d& newPoint() const;
    void setNewPoint(const AcGePoint3d&);

    bool displayOsnapGlyph() const;
    void setDisplayOsnapGlyph(bool);

    const ACHAR* newTooltipString() const;
    void setNewTooltipString(const ACHAR*);

    bool retry() const;
    void setRetry(bool);

private:
    AcEdInputPointFilterResult();
    AcEdInputPointFilterResult(const AcEdInputPointFilterResult&);
    AcEdInputPointFilterResult& operator=(const AcEdInputPointFilterResult&);

private:
    friend class AcEdInputPointFilterResultImp;
    AcEdInputPointFilterResult(AcEdInputPointFilterResultImp*);
    AcEdInputPointFilterResultImp* m_pBrxImp;
};
