// od_settings_manager.h :

// Copyright © Menhirs NV. All rights reserved.

//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH

#pragma once
#include "od_api_exports.h"
#include "sds_types.h"
#include "RxObject.h"

namespace oa
{
    class ApDatabase;
    class ApDoc;
}

class ODAPI OdEdSettings: public OdRxObject
{
public:
    virtual OdString groupName() const = 0;
    
    // Should return full path to user's xml file
    virtual OdString configFilePath() = 0;

    // if get/set methods are not implemented in derived class, 
    // then BricsCAD is fully responsible for actual value and storage of variables 
    // (in the registry or in the dictionary of drawing depending on SetVar::m_saveMode)
    virtual bool get(const OdString& varName, resbuf& rb) const; 
    virtual bool set(const OdString& varName, const resbuf& rb); 
};

class ODAPI OdEdSettingsReactor
{
public:
    OdEdSettingsReactor() {};
    virtual ~OdEdSettingsReactor() {};

    // groupName is empty, if varName is from the "BricsCAD" group.
    virtual void onSettingChanged(const OdString& groupName, const OdString& varName, oa::ApDoc* pDoc) = 0;
};


//
// Rule1: The name of variable can have a prefix (OdEdSettings::groupName()), 
//        a.g. "BIM/SectionHistory" or "MCAD/SmTargetCAM"; can be created by makeFullName().
// Rule2: If there are several variables with the same name in the base BricsCAD and in the 
//        top-apps settings, and fullVarName doesn't have prefix, then this method returns   
//        variable from base BricsCAD (if exist) or variable from the first top app added.
//
class ODAPI OdEdSettingsManager
{
public:
    typedef OdArray<OdEdSettings*> SettingsArray;

    static OdEdSettingsManager* get();

    virtual bool registerSettings(OdEdSettings* pSettings);
    virtual bool unregisterSettings(OdEdSettings* pSettings);

    virtual void addReactor(OdEdSettingsReactor* pReactor) = 0;
    virtual void removeReactor(OdEdSettingsReactor* pReactor) = 0;

    // Get an array of registred group names.  
    // Returns the number of registred groups. BricsCAD is not included. 
    virtual int getAllRegistredSettings(OdStringArray& groupNames) const = 0;
    // If groupName is empty, then returns all common sysvars for "BricsCAD" group.
    virtual int getAllVarNames(OdStringArray& varNames, const OdString& groupName) const = 0;
    // Returns false if variable was not found. 
    // If method returns true and groupName is empty then variable with this name exist in the base BricsCAD app.
    virtual bool getGroupName(OdString& groupName, const OdString& fullVarName) const = 0;

    // fullVarName can have a prefix (OdEdSettings::groupName()), a.g. "BIM/SectionHistory" or "MCAD/SmTargetCAM"
    virtual bool getValue(const OdString& fullVarName, resbuf& rb, bool* pIsReadOnly = nullptr, bool* pIsPerDoc = nullptr) = 0;
    virtual bool setValue(const OdString& fullVarName, const resbuf& pb) = 0;
 
    // Method for internal use only. It supports undo mechanism for MCAD/BIM settings, but not BricsCAD settings.
    virtual void doSettingUndo(oa::ApDatabase* pDb, OdDbDwgFiler* pFiler, OdRxClass* pClass) = 0;

    // helper methods:
    virtual OdString stringFromResbuf(resbuf& rb) const = 0;
    virtual bool resbufFromString(resbuf& rb, const OdString& str, const int resType) const = 0;

    // returns false if varName is empty
    static bool splitName(const OdString& fullVarName, OdString& groupName, OdString& varName);
    static OdString makeFullName(const OdString& groupName, const OdString& varName);

    static void unInit();

protected:
    OdEdSettingsManager() {}
    virtual ~OdEdSettingsManager() {}

    virtual void init() = 0;
    virtual void clearAll() = 0;

    friend class OdEdSettings;
    // The functions expect that groupName is not empty, otherwise it does not make sense
    virtual bool getFromCache(const OdString& groupName, const OdString& varName, resbuf& rb) = 0;
    virtual bool setToCache(const OdString& groupName, const OdString& varName, const resbuf& rb) = 0;

protected:
    static OdEdSettingsManager* s_pMgr;
    bool m_isInited = false;
};
