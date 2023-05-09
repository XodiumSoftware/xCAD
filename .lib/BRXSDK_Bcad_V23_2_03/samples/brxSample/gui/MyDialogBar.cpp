// Copyright (C) Menhirs NV. All rights reserved.

#include "StdAfx.h"
#include "MyDialogBar.h"

IMPLEMENT_DYNAMIC(CMyDialogBar, CDialogBar)

CMyDialogBar::CMyDialogBar(): CDialogBar()
{
}

CMyDialogBar::~CMyDialogBar()
{
}

void CMyDialogBar::DoDataExchange(CDataExchange* pDX)
{
	CDialogBar::DoDataExchange(pDX);
}

void CMyDialogBar::PostNcDestroy()
{
    delete this;
}

BEGIN_MESSAGE_MAP(CMyDialogBar, CDialogBar)
END_MESSAGE_MAP()
