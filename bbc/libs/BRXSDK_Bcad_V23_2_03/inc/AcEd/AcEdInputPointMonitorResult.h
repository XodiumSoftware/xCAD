// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcAp/AcApGlobal.h"
#include "AcDb/AcDbGlobal.h"
#include "AcRx/AcRxObject.h"

class AcEdInputPointMonitorResultImp;

/** _ */
class BRX_IMPORTEXPORT AcEdInputPointMonitorResult
{
public:
    ~AcEdInputPointMonitorResult();

    const ACHAR* additionalTooltipString() const;
    void setAdditionalTooltipString(const ACHAR*);

    bool appendToTooltipStr() const;

private:
    AcEdInputPointMonitorResult();
    AcEdInputPointMonitorResult(const AcEdInputPointMonitorResult&);
    AcEdInputPointMonitorResult& operator=(const AcEdInputPointMonitorResult&);

private:
    friend class AcEdInputPointMonitorResultImp;
    AcEdInputPointMonitorResult(AcEdInputPointMonitorResultImp*);
    AcEdInputPointMonitorResultImp* m_pBrxImp;
};
