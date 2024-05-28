// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
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