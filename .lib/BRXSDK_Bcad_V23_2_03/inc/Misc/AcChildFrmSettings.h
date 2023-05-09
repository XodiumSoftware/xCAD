// Copyright (C) Menhirs NV. All rights reserved.
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