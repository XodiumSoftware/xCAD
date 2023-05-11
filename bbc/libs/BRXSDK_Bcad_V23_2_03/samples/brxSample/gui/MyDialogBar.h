// Copyright (C) Menhirs NV. All rights reserved.

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
