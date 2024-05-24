// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
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
