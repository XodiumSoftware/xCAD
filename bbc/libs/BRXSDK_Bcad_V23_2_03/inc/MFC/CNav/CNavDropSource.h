// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

class CNavListCtrl;

/** _ */
class CNavDropSource: public COleDropSource
{
public:
    CNavDropSource();
    CNavListCtrl* m_pListCtrl;
    SCODE GiveFeedback(DROPEFFECT);
};