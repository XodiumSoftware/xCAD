// Copyright (C) Menhirs NV. All rights reserved.
#pragma once
#include "AdCharFormatter.h"

/** _ */
class BRX_IMPORTEXPORT AcCFile: public CFile
{
public:
    AcCFile();
    AcCFile(HANDLE);
    AcCFile(LPCTSTR,UINT);
    virtual ~AcCFile();

    virtual UINT Read(LPTSTR,UINT);
    virtual UINT Read(void*,UINT);
    virtual void Write(const void*,UINT);
    virtual void Write(LPCTSTR);
    virtual void Write(LPCTSTR,UINT);

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