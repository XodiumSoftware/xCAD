// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "../resource.h"

class CMyDialogBar: public CDialogBar
{
    DECLARE_DYNAMIC(CMyDialogBar)

public:
    CMyDialogBar();
    virtual ~CMyDialogBar();

    enum { IDD = IDD_DIALOGBAR };

protected:
    virtual void DoDataExchange(CDataExchange* pDX);
    virtual void PostNcDestroy();

    DECLARE_MESSAGE_MAP()
};
