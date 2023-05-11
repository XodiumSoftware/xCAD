// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include <stdio.h>
#include <tchar.h>

/** _ */
class BRX_IMPORTEXPORT AcFILE
{
public:
    AcFILE();
    AcFILE(FILE*);
    ~AcFILE();

    bool getExpandLF() const;
    bool getUseCIF() const;
    bool isOpen() const;
    bool readBOM();
    bool setExpandLF(bool);
    bool setUseCIF(bool);
    bool writeBOM();
    FILE* detach();
    FILE* fopen(const TCHAR*,const TCHAR*);
    FILE* fsopen(const TCHAR*,const TCHAR*,int);
    FILE* pFILE() const;
    int fclose();
    int fgetc();
    int fprintf(const TCHAR*,...);
    int fputc(TCHAR);
    int fputs(const TCHAR*);
    int fscanf(const TCHAR*,...);
    int ungetc(TCHAR);
    int vfprintf(const TCHAR*,va_list);
    TCHAR* fgets(TCHAR*,int);
    unsigned getCharFormat() const;
    unsigned setCharFormat(unsigned);
    void attach(FILE*);
};