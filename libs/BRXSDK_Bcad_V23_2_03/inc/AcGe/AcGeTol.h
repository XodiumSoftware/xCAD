// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "Misc/MiscGlobal.h"

#ifdef __cplusplus

/** _ */
class BRX_IMPORTEXPORT AcGeTol
{
private:
    double m_tolPoint;
    double m_tolVector;

public:
    AcGeTol();
    AcGeTol(const AcGeTol& other);
    AcGeTol& operator=(const AcGeTol& other);

    void setEqualPoint(double);
    double equalPoint() const;

    void setEqualVector(double);
    double equalVector() const;
};

#endif //__cplusplus
