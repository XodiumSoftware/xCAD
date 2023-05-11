// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbObjectId.h"
#include "MFC/CAcUi/CAcUiGlobal.h"

/** _ */
class BRX_IMPORTEXPORT CAcUiLTypeRecord: public CObject
{
public:
    AcDbObjectId objectId();
    BOOL isDependent();
    CString & ltypeName();
    void setIsDependent(BOOL);
    void setLTypeName(CString);
    void setObjectId(AcDbObjectId);

private:
    AcDbObjectId  m_objectId;
    BOOL          m_isDependent;
    CString       m_ltypeName;    
};
