// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcPl/AcPlObject.h"
#include "Misc/AcArray.h"

class BrxDSDEntryImp;

/** _ */
class AcPlDSDEntry: public AcPlObject
{
public:

    enum SetupType {
        kOriginalPS = 0,
        kNPSSameDWG,
        kNPSOtherDWG,
        k3dDwf,
        kOverridePS,
    };

    enum SheetType
    {
        kSingleDWF = 0,
        kMultiDWF,
        kOriginalDevice,
        kSingleDWFx,
        kMultiDWFx,
        kSinglePDF,
        kMultiPDF,
    };

    ACRX_DECLARE_MEMBERS(AcPlDSDEntry);

    AcPlDSDEntry();
    AcPlDSDEntry(const AcPlDSDEntry&);
    virtual ~AcPlDSDEntry();

    bool has3dDwfSetup() const;
    const ACHAR* dwgName() const;
    const ACHAR* layout() const;
    const ACHAR* NPS() const;
    const ACHAR* NPSSourceDWG() const;
    const ACHAR* orgSheetPath() const;
    const ACHAR* title() const;
    void setDwgName(const ACHAR*);
    void setHas3dDwfSetup(bool);
    void setLayout(const ACHAR*);
    void setNPS(const ACHAR*);
    void setNPSSourceDWG(const ACHAR*);
    void setTitle(const ACHAR*);
    AcPlDSDEntry::SetupType setupType() const;
    void setSetupType(AcPlDSDEntry::SetupType eType); 

    AcPlDSDEntry& operator=(const AcPlDSDEntry&);

private:
    friend BrxDSDEntryImp;
    BrxDSDEntryImp* m_pImp;
};

typedef AcArray< AcPlDSDEntry, AcArrayObjectCopyReallocator<AcPlDSDEntry> > AcPlDSDEntries;
