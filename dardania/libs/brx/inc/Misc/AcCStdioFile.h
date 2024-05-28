// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AdCharFormatter.h"

/** _ */
class BRX_IMPORTEXPORT AcCStdioFile: public CStdioFile
{
public:
    AcCStdioFile();
    AcCStdioFile(FILE*);
    AcCStdioFile(LPCTSTR,UINT);
    virtual ~AcCStdioFile();

    virtual BOOL ReadString(CString&);
    virtual LPTSTR ReadString(LPTSTR,UINT);
    virtual void WriteString(LPCTSTR);

    bool getExpandLF() const;
    bool getUseCIF() const;
    bool readBOM();
    bool setExpandLF(bool);
    bool setUseCIF(bool);
    bool writeBOM();
    unsigned getCharFormat() const;
    unsigned setCharFormat(unsigned);

private:
    AdCharFormatter m_charFormatter;
};
