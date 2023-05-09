// AcEdSettings.h
//
// Copyright © Menhirs NV. All rights reserved.
//
//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH

#pragma once

#ifndef _AcEdSettings_h_Included
#define _AcEdSettings_h_Included

#include "brx_importexport.h"
#include "Misc/AcString.h"
#include "AcDb/AcDbGlobal.h"

// class to register and access application's custom settings;
// applications need to derive from AcEdSettings, and implement the "groupName()" and "configFilePath()"
// functions;
// example for a settings definition file : see "inc/BrxSpecific/AcEdSettings-Sample.xml" sample;
//
// customisable properties : <save> <type> <mode>
//
// <var prog="b" ...>
//    fixed value "b", specifies that this setting is BricsCAD-specific, mandatory
//
// <save>
//    allowed values :
//    dwg - saved in drawing
//    reg - saved in registry
//    prf - preference, saved in registry, not available as system variable
//    not - not saved across sessions
//    ws  - saved in workspace
//    usr - uUser setting
//
// <type>
//    allowed values :
//    bool - boolean
//    int  - short
//    long - long
//    p2d  - 2D point
//    p3d  - 3D point
//    real - double
//    str  - string
//
// <mode>
//    writable - setting can be changed via acedSetVar or Settings dialog
//    readonly - setting is fixed, can not be changed
//

class BRX_IMPORTEXPORT AcEdSettings
{
    class AcEdSettingsImpl;
    AcEdSettingsImpl *m_pImpl = nullptr;

public:
    AcEdSettings();
    AcEdSettings(const AcEdSettings&) = delete;
    AcEdSettings& operator=(const AcEdSettings&) = delete;
    virtual ~AcEdSettings();

    // provide a settings group name, as to be used in Settings dialog, for the custom settings
    virtual AcString groupName() const = 0;

    // Path to the application's settings xml file, see "inc/BrxSpecific/AcEdSettings-Sample.xml"
    virtual AcString configFilePath() = 0;

    // if get/set methods are not implemented in derived class, 
    // then BricsCAD is fully responsible for actual value and storage of variables 
    // (in the registry or in the dictionary of drawing depending on SetVar::m_saveMode)
    virtual bool get(const AcString& varName, resbuf& rb) const;
    virtual bool set(const AcString& varName, const resbuf& rb);

    // register and unregister the application's custom "AcEdSettings" instance
    static bool registerSettings(AcEdSettings* pSettings);
    static bool unregisterSettings(AcEdSettings* pSettings);
};

#endif // _AcEdSettings_h_Included
