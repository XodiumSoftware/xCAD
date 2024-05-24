// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "Misc/AcColorSettings.h"

class CDialogBar;

/** _ */
struct AcChildFrmSettings
{
    AcColorSettings m_ColorSettings;
    bool m_bShowLayoutBar;
    bool m_bShowScrollBar;
    CDialogBar* m_pDialogBar;
};