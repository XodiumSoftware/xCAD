// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbObject.h"

/** _ */
class BRX_EXPORT AcDbRenderSettings: public AcDbObject
{
public:
    ACRX_DECLARE_MEMBERS(AcDbRenderSettings);

    AcDbRenderSettings();
    virtual ~AcDbRenderSettings();

    virtual Acad::ErrorStatus copyFrom(const AcRxObject*);
    virtual Acad::ErrorStatus dwgInFields(AcDbDwgFiler*);
    virtual Acad::ErrorStatus dwgOutFields(AcDbDwgFiler*) const;
    virtual Acad::ErrorStatus dxfInFields(AcDbDxfFiler*);
    virtual Acad::ErrorStatus dxfOutFields(AcDbDxfFiler*) const;
    virtual AcGiDrawable* drawable();
    virtual bool operator==(const AcDbRenderSettings&);

    Acad::ErrorStatus setName(const AcString&);
    Acad::ErrorStatus setPreviewImageFileName(const AcString&);
    AcString description() const;
    AcString name() const;
    AcString previewImageFileName() const;
    bool backFacesEnabled() const;
    bool diagnosticBackgroundEnabled() const;
    bool materialsEnabled() const;
    bool shadowsEnabled() const;
    bool textureSampling() const;
    int displayIndex() const;
    void setBackFacesEnabled(bool);
    void setDescription(const AcString&);
    void setDiagnosticBackgroundEnabled(bool);
    void setDisplayIndex(int);
    void setMaterialsEnabled(bool);
    void setShadowsEnabled(bool);
    void setTextureSampling(bool);

protected:
    virtual Adesk::UInt32 subSetAttributes(AcGiDrawableTraits*);
};
