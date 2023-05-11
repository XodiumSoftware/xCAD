// Copyright (C) Menhirs NV. All rights reserved.
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
