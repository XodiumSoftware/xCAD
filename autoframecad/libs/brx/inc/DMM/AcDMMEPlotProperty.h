// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "DMM/AcDMMXMLAttribute.h"

class BrxDMMEPlotPropertyImp;

/** _ */
class BRX_IMPORTEXPORT AcDMMEPlotProperty
{
private:
    //BRX START
    BrxDMMEPlotPropertyImp* m_pBrxImp;
    //BRX END

public:
    AcDMMEPlotProperty();
    AcDMMEPlotProperty(const wchar_t*,const wchar_t*);
    AcDMMEPlotProperty(const AcDMMEPlotProperty&);
    ~AcDMMEPlotProperty();

    const AcDMMXMLAttributeVec& GetXMLAttributes() const;
    const wchar_t* GetCategory() const;
    const wchar_t* GetName() const;
    const wchar_t* GetType() const;
    const wchar_t* GetUnits() const;
    const wchar_t* GetValue() const;
    void AddXMLAttribute(const AcDMMXMLAttribute*);
    void AddXMLAttribute(const wchar_t*,const wchar_t*,const wchar_t*,const wchar_t*);
    void SetCategory(const wchar_t*);
    void SetName(const wchar_t*);
    void SetType(const wchar_t*);
    void SetUnits(const wchar_t*);
    void SetValue(const wchar_t*);

    AcDMMEPlotProperty& operator=(const AcDMMEPlotProperty&);
};

typedef AcArray<AcDMMEPlotProperty, AcArrayObjectCopyReallocator<AcDMMEPlotProperty> > AcDMMEPlotPropertyVec;
