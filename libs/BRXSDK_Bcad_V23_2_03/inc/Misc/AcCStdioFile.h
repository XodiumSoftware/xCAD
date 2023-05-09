// Copyright (C) Menhirs NV. All rights reserved.
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
