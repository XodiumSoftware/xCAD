// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbObject.h"

/** _ */
class BRX_EXPORT AcDbRenderGlobal: public AcDbObject
{
public:
    enum Destination
    {
        krWindow = 0,
        krViewport
    };

    enum Procedure
    {
        krView = 0,
        krCrop,
        krSelected
    };

    ACRX_DECLARE_MEMBERS(AcDbRenderGlobal);

    AcDbRenderGlobal();
    virtual ~AcDbRenderGlobal();

    virtual Acad::ErrorStatus dwgInFields(AcDbDwgFiler*);
    virtual Acad::ErrorStatus dwgOutFields(AcDbDwgFiler*) const;
    virtual Acad::ErrorStatus dxfInFields(AcDbDxfFiler*);
    virtual Acad::ErrorStatus dxfOutFields(AcDbDxfFiler*) const;

    Acad::ErrorStatus copyFrom(const AcRxObject*);
    Acad::ErrorStatus setDimensions(int,int);
    Acad::ErrorStatus setSaveFileName(const AcString&);
    AcString saveFileName() const;
    bool highInfoLevel() const;
    bool predefinedPresetsFirst() const;
    bool saveEnabled() const;
    void dimensions(int&,int&) const;
    void procedureAndDestination(Procedure&,Destination&) const;
    void setHighInfoLevel(bool);
    void setPredefinedPresetsFirst(bool);
    void setProcedureAndDestination(Procedure,Destination);
    void setSaveEnabled(bool);
};
