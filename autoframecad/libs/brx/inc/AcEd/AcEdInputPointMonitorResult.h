// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
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
