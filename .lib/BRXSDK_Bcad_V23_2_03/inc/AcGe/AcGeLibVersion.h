// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "Misc/MiscGlobal.h"

#define IMAGE_CORRECTIVE_VER 0
#define IMAGE_INTERNAL_VER 0
#define IMAGE_MAJOR_VER 2
#define IMAGE_MINOR_VER 0

/** _ */
class BRX_IMPORTEXPORT AcGeLibVersion
{
public:
    static const AcGeLibVersion kRelease0_95;
    static const AcGeLibVersion kReleaseSed;
    static const AcGeLibVersion kReleaseTah;

    AcGeLibVersion();
    AcGeLibVersion(Adesk::UInt8,Adesk::UInt8,Adesk::UInt8,Adesk::UInt8);
    AcGeLibVersion(const AcGeLibVersion&);

    AcGeLibVersion& setCorrectiveVersion(Adesk::UInt8);
    AcGeLibVersion& setMajorVersion(Adesk::UInt8);
    AcGeLibVersion& setMinorVersion(Adesk::UInt8);
    AcGeLibVersion& setSchemaVersion(Adesk::UInt8);
    Adesk::UInt8 correctiveVersion() const;
    Adesk::UInt8 majorVersion() const;
    Adesk::UInt8 minorVersion() const;
    Adesk::UInt8 schemaVersion() const;

    Adesk::Boolean operator!=(const AcGeLibVersion&) const;
    Adesk::Boolean operator<(const AcGeLibVersion&) const;
    Adesk::Boolean operator<=(const AcGeLibVersion&) const;
    Adesk::Boolean operator==(const AcGeLibVersion&) const;
    Adesk::Boolean operator>(const AcGeLibVersion&) const;
    Adesk::Boolean operator>=(const AcGeLibVersion&) const;
};
