// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

class AcRxVariableReactor;
class AcRxVariableImp;

class BRX_IMPORTEXPORT AcRxVariable
{
public:

    enum SecondaryType
    {
        kSecondaryTypeNone = 0,
        kSecondaryTypeBoolean = 1,
        kSecondaryTypeSymbolName = 2,
        kSecondaryTypeArea = 3,
        kSecondaryTypeDistance = 4,
        kSecondaryTypeAngle = 5,
        kSecondaryTypeUnitlessReal = 6,
        kSecondaryTypeLast = 6,
    };

    enum StorageType
    {
        kStoragePerSession = 0,
        kStoragePerUser = 1,
        kStoragePerProfile = 2,
        kStoragePerDatabase = 3,
        kStoragePerViewport = 4
    };

    enum TypeFlags
    {
        kTypeFlagsNone = 0,
        kTypeFlagSpacesAllowed = 1,
        kTypeFlagDotMeansEmpty = 2,
        kTypeFlagNoUndo = 4,
        kTypeFlagsChatty = 8,
        kTypeDeprecated = 16,
    };

    struct Range
    {
        Range();
        Range(int, int);
        int lowerBound;
        int upperBound;
    };
    const ACHAR* name() const;
    void addReactor(AcRxVariableReactor*);
    bool isLocked() const;
    void removeReactor(AcRxVariableReactor*);
    bool isReadOnly(AcString* explanation = NULL) const;
    Acad::ErrorStatus reset();
    short primaryType() const;
    AcRxVariable::SecondaryType secondaryType() const;
    AcRxVariable::StorageType storageType() const;
    short typeFlags() const;
    const Range* range() const;
    Acad::ErrorStatus setValue(const resbuf&, void* id = NULL, AcString* failResult = NULL);
    Acad::ErrorStatus getValue(resbuf&) const;    
    Acad::ErrorStatus setIsReadOnly(bool, void* id, const AcString* explanation = NULL);    

    ~AcRxVariable();
private:
    friend class AcRxVariableImp;
    AcRxVariable(AcRxVariableImp*);
    AcRxVariableImp* m_pImp = nullptr;
};