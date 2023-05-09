// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcEd/AcEdGlobal.h"

/** _ */
class AcEdInputPointManager
{
public:
    virtual ~AcEdInputPointManager() {};

    virtual Acad::ErrorStatus addInputContextReactor(AcEdInputContextReactor*) = 0;
    virtual Acad::ErrorStatus addPointMonitor(AcEdInputPointMonitor*) = 0;
    virtual Acad::ErrorStatus addSubSelectFilter(AcEdSubSelectFilter*) = 0;
    virtual Acad::ErrorStatus disableSystemCursorGraphics() = 0;
    virtual Acad::ErrorStatus enableSystemCursorGraphics() = 0;
    virtual Acad::ErrorStatus registerPointFilter(AcEdInputPointFilter*) = 0;
    virtual Acad::ErrorStatus removeInputContextReactor(AcEdInputContextReactor*) = 0;
    virtual Acad::ErrorStatus removePointMonitor(AcEdInputPointMonitor*) = 0;
    virtual Acad::ErrorStatus removeSubSelectFilter(AcEdSubSelectFilter*) = 0;
    virtual Acad::ErrorStatus revokePointFilter() = 0;
    virtual Acad::ErrorStatus turnOffForcedPick() = 0;
    virtual Acad::ErrorStatus turnOffSubentityWindowSelection() = 0;
    virtual Acad::ErrorStatus turnOnForcedPick() = 0;
    virtual Acad::ErrorStatus turnOnSubentityWindowSelection() = 0;
    virtual AcEdInputPointFilter* currentPointFilter() const = 0;
    virtual int forcedPickCount() const = 0;
    virtual int mouseHasMoved() const = 0;
    virtual int systemCursorDisableCount() const = 0;
    virtual void enableMultiSubentPathSelection(bool) = 0;
};