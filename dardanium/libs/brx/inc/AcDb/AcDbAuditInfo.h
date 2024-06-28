// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbGlobal.h"
#include "AcRx/AcRxGlobal.h"

/** _ */
class BRX_IMPORTEXPORT AcDbAuditInfo
{
private:
    //BRX START
    //V10
    friend class BrxDbAuditInfoImp;
    class BrxDbAuditInfoImp* m_pBrxImp;
    //BRX END

public:
    enum AuditPass
    {
        PASS1 = 1,
        PASS2
    };

    AcDbAuditInfo();
    ~AcDbAuditInfo();

    Acad::ErrorStatus fetchObject(AcDbObjectId,AcDbObjectId&,AcRxClass*,bool = false,bool = true,bool = false);
    Acad::ErrorStatus registerObject(AcDbHandle,bool,AcRxClass*);
    Acad::ErrorStatus updateObject(AcDbHandle,bool,bool,bool,bool,bool,bool,bool,AcRxClass*,AcRxClass*,AcDbObjectId);
    AuditPass auditPass() const;
    bool fixErrors() const;
    int numEntities();
    int numErrors() const;
    int numFixes() const;
    void errorsFixed(int);
    void errorsFound(int);
    void incNumEntities();
    void printError(const AcDbObject*,const ACHAR*,const ACHAR*,const ACHAR*);
    void printError(const ACHAR*,const ACHAR*,const ACHAR*,const ACHAR*);
    void printNumEntities(const ACHAR*);
    void requestRegen();
    void resetNumEntities();
};
