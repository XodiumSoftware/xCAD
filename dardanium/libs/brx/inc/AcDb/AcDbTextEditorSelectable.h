// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

class AcDbTextEditorLocation;

/** _ */
class BRX_IMPORTEXPORT AcDbTextEditorSelectable
{
public:
    virtual ~AcDbTextEditorSelectable() {}
    virtual AcDbTextEditorLocation* startOfText() = 0;
    virtual AcDbTextEditorLocation* endOfText() = 0;
};
