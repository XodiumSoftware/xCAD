// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "MFC/CAdUi/CAdUiListCtrl.h"
#include "MFC/CNav/CNavDropSource.h"

/** _ */
class CNavListCtrl: public CAdUiListCtrl
{
public:
    CNavListCtrl();
protected:
    afx_msg LRESULT OnHandleDrag(UINT_PTR,LPARAM);
    afx_msg void OnBeginDrag(NMHDR*,LRESULT*);

    CImageList* m_pDragImage;
    CNavDropSource m_dropSource;

    DECLARE_MESSAGE_MAP()
};
