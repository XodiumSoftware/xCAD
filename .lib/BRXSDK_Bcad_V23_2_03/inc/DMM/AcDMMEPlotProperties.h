// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "DMM/AcDMMEPlotProperty.h"
#include "DMM/AcDMMWideString.h"

class BrxDMMEPlotPropertiesImp;

/** _ */
class BRX_IMPORTEXPORT AcDMMEPlotProperties
{
private:
    //BRX START
    BrxDMMEPlotPropertiesImp* m_pBrxImp;
    //BRX END

public:
    AcDMMEPlotProperties();
    AcDMMEPlotProperties(const AcDMMEPlotProperties&);
    ~AcDMMEPlotProperties();

    const AcDMMEPlotProperty* GetProperty(unsigned long) const;
    const AcDMMEPlotPropertyVec& GetProperties() const;
    const AcDMMStringVec* GetRefs() const;
    const wchar_t* GetId() const;
    void AddProperty(const AcDMMEPlotProperty*);
    void AddProperty(wchar_t*,wchar_t*);
    void SetId(const wchar_t*);
    void SetRefs(const AcDMMStringVec&);

    AcDMMEPlotProperties& operator=(const AcDMMEPlotProperties&);
};
