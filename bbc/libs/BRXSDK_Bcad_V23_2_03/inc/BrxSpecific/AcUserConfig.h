#pragma once

#include "brx_importexport.h"
#include "AcDb/AcDbGlobal.h"


//==============================================================================
// User configuration API exposes access to in-memory copy of persisted user
// profile settings. In the API, "path" is a slash delimited path relative to
// product root key. For example, the path "Profiles/Drafting/Config/BASEFILE"
// refers to the BASEFILE system variable in the Drafting user profile. The
// configuration API functions return kTrue on success, kFalse otherwise.
// 
//==============================================================================
// Examples
//
// Get the current user profile name:
//     AcString sCurProfile;
//     AcUserConfig::readString(ACRX_T("Profiles/CurProfile"), sCurProfile);
//
// Get a list of all configuration values saved in the Drafting user profile:
//     AcStringArray sValNames;
//     AcUserConfig::listValues(ACRX_T("Profiles/Drafting/Config/"), sValNames);
//==============================================================================

class AcUserConfig
{
public:
    enum ConfigValueType
    {
        kTypeUnknown,
        kTypeString,
        kTypeLong,
        kTypeDouble,
    };
    static ConfigValueType valueType(const ACHAR* pathToValue);

    static Adesk::Boolean readLong(const ACHAR* pathToValue, long& val);
    static Adesk::Boolean readDouble(const ACHAR* pathToValue, double& val);
    static Adesk::Boolean readString(const ACHAR* pathToValue, AcString& val);

    static Adesk::Boolean writeLong(const ACHAR* pathToValue, long val);
    static Adesk::Boolean writeDouble(const ACHAR* pathToValue, double val);
    static Adesk::Boolean writeString(const ACHAR* pathToValue, const ACHAR* val);

    static Adesk::Boolean listSubsections(const ACHAR* pathToSubsection, AcStringArray& subsections);
    static Adesk::Boolean listValues(const ACHAR* pathToSubsection, AcStringArray& values);

    static Adesk::Boolean deleteSubsection(const ACHAR* pathToSubsection);
    static Adesk::Boolean deleteValue(const ACHAR* pathToValue);

    static Adesk::Boolean hasSubsection(const ACHAR* pathToSubsection);
    static Adesk::Boolean hasValue(const ACHAR* pathToValue);
};
