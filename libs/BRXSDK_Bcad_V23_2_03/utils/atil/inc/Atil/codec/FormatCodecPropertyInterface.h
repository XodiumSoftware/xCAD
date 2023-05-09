// Copyright (C) 2017-2018 Menhirs NV. All rights reserved.
#pragma once

#include "Atil/Defs.h"
#include "Atil/StringBuffer.h"


namespace Atil
{;

class StringBuffer;


class FormatCodecPropertyInterface
{
public:
    enum PropertyDataType
    {
        kCustom = 0,
        kVoid = 1,
        kInteger = 2,
        kDouble = 3,
        kString = 4,
        kInclusiveSet = 5,
        kExclusiveSet = 6,
        kDate = 7,
        kClass = 8
    };

    enum PropertyIdentifier
    {
        kIdCustom = 0,
        kSimpleType = 1,
        kCompression = 2,
        kDensity = 3,
        kDataOrganization = 4,
        kAssociation = 5,
        kTransparency = 6,
        kCorrelation = 7,
        kColor = 8,
        kMultispectralReferenceName = 9,
        kMultispectralBandName = 10,
        kMultispectralBucket = 11,
        kLatLon = 12,
        kPoint = 13,
        kSampleFormat = 14,
        kVoidData = 15,
        kCorrelationSet = 16,
        kChannelOrder = 17
    };

    enum PropertyLevel
    {
        kLevelUnknown = 0,
        kLevelFrame = 1,
        kLevelAssociation = 2,
        kLevelFile = 3
    };

    enum PropertyUsage
    {
        kUsageUnknown = 0,
        kReadOnly = 1,
        kReadWrite = 2,
        kWriteOnly = 3
    };

public:
    virtual ~FormatCodecPropertyInterface() {}
    virtual FormatCodecPropertyInterface* clone() const = 0;
    virtual PropertyDataType getDataType() const { return mType; }
    virtual PropertyIdentifier getIdentifier() const { return mId; }
    virtual const StringBuffer& getDescription() const { return msbDescription; }
    virtual PropertyLevel getLevel() const { return mLevel; }
    virtual const StringBuffer& getName() const { return msbName; }
    virtual PropertyUsage getUsage() const { return mUsage; }
    virtual bool isContextSensitive() const { return mbContextSensitive; }
    virtual bool isRequired() const { return mbRequired; }

private:
    FormatCodecPropertyInterface& operator= (const FormatCodecPropertyInterface& rh);

protected:
    FormatCodecPropertyInterface()
        : mId(kIdCustom), mType(kCustom), mbRequired(false), mbContextSensitive(false), mUsage(kUsageUnknown), mLevel(kLevelUnknown) {}
    FormatCodecPropertyInterface(const FormatCodecPropertyInterface& rh)
    {
        mId = rh.mId;
        mType = rh.mType;
        mbRequired = rh.mbRequired;
        mbContextSensitive = rh.mbContextSensitive;
        msbName = rh.msbName;
        msbDescription = rh.msbDescription;
        mUsage = rh.mUsage;
        mLevel = rh.mLevel;
    }

    PropertyIdentifier mId;
    PropertyDataType mType;
    bool mbRequired;
    bool mbContextSensitive;
    StringBuffer msbName;
    StringBuffer msbDescription;
    PropertyUsage mUsage;
    PropertyLevel mLevel;
};


} //namespace Atil
