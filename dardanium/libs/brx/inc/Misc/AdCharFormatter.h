// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

/** _ */
class BRX_IMPORTEXPORT AdCharFormatter
{
public:
    enum
    {
        kCIFLen = 7,
        kMIFLen = 8,
        kNoBestFitFlag = 1024
    };

    enum
    {
        kUnknown = 0,
        kAnsi,
        kUtf8,
        kUtf16LE,
        kUtf16BE,
        kUtf32LE,
        kUtf32BE
    };

    AdCharFormatter();
    AdCharFormatter(unsigned,bool,bool);

    bool getExpandLF() const;
    bool getUseCIF() const;
    bool setExpandLF(bool);
    bool setUseCIF(bool);
    int static getBOM(unsigned&,unsigned);
    unsigned getFormat() const;
    unsigned setFormat(unsigned);
    unsigned static lookupBOM(unsigned);
    unsigned wcharToBytes(wchar_t,char*,unsigned) const;

    static int isNativeToCodePage(wchar_t,unsigned,char* = NULL);
    static int wcharFromCIFMIF(const wchar_t*,wchar_t*,int);
    static int wcharNonNativeToCIF(const wchar_t*,wchar_t*,int);
    static int wcharNonNativeToRTF(unsigned,const wchar_t*,int,char*,int*);
    static unsigned char MIFIndexFromWinCodePage(unsigned);
    static unsigned wcharToAnsiOrUtf8(wchar_t,char*,unsigned,bool,bool,bool);
    static unsigned wcharToUtf16(wchar_t,char*,unsigned,bool,bool);
    static unsigned wcsLength(const wchar_t*);
    static unsigned winCodePageFromMIFIndex(unsigned);

private:
    bool m_doLFExpansion;
    bool m_doCIFExpansion;
    unsigned int m_CharacterFmt;    
};
