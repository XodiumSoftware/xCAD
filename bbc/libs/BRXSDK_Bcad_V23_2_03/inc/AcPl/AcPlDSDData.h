// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcPl/AcPl3dDwfOptions.h"
#include "AcPl/AcPlDSDEntry.h"

class BrxDSDDataImp;

/** _ */
class AcPlDSDData: public AcPlObject
{
public:
    ACRX_DECLARE_MEMBERS(AcPlDSDData);

    AcPlDSDData();
    AcPlDSDData(const AcPlDSDData&);
    virtual ~AcPlDSDData();

    AcPlDSDEntry& DSDEntryAt(int);
    AcPlDSDEntry::SheetType sheetType() const;
    bool isHomogeneous() const;
    bool isSheetSet() const;
    bool plotStampOn() const;
    bool readDSD(const ACHAR*);
    bool writeDSD(const ACHAR*);
    const ACHAR* categoryName() const;
    const ACHAR* destinationName() const;
    const ACHAR* logFilePath() const;
    const ACHAR* password() const;
    const ACHAR* projectPath() const;
    const ACHAR* selectionSetName() const;
    const ACHAR* sheetSetName() const;
    const AcPl3dDwfOptions& get3dDwfOptions() const;
    int numberOfDSDEntries() const;
    unsigned int majorVersion() const;
    unsigned int minorVersion() const;
    unsigned int noOfCopies() const;
    void getDSDEntries(AcPlDSDEntries&) const;
    void getUnrecognizedData(AcArray<ACHAR*>&,AcArray<ACHAR*>&) const;
    void set3dDwfOptions(const AcPl3dDwfOptions&);
    void setCategoryName(const ACHAR*);
    void setDestinationName(const ACHAR*);
    void setDSDEntries(const AcPlDSDEntries&);
    void setIsHomogeneous(bool);
    void setIsSheetSet(bool);
    void setLogFilePath(const ACHAR*);
    void setMajorVersion(unsigned int);
    void setMinorVersion(unsigned int);
    void setNoOfCopies(unsigned int);
    void setPassword(const ACHAR*);
    void setPlotStampOn(bool);
    void setProjectPath(const ACHAR*);
    void setSelectionSetName(const ACHAR*);
    void setSheetSetName(const ACHAR*);
    void setSheetType(AcPlDSDEntry::SheetType);
    void setUnrecognizedData(const AcArray<ACHAR*>&,const AcArray<ACHAR*>&);
    void setUnrecognizedData(const ACHAR*,const ACHAR*);

    AcPlDSDData& operator=(const AcPlDSDData&);

private:
    friend BrxDSDDataImp;
    BrxDSDDataImp* m_pImp;
};
