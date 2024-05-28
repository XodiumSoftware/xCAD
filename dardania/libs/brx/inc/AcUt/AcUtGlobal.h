// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "Ads/AdsGlobal.h"

#ifdef __cplusplus
extern "C"
{
#endif //__cplusplus
    ads_real acutAngle(const ads_point,const ads_point);
    ads_real acutDistance(const ads_point,const ads_point);
    int acutCvUnit(ads_real,const ACHAR*,const ACHAR*,ads_real*);
    int acutIsAlNum(int);
    int acutIsAlpha(int);
    int acutIsCntrl(int);
    int acutIsDigit(int);
    int acutIsGraph(int);
    int acutIsLower(int);
    int acutIsPrint(int);
    int acutIsPunct(int);
    int acutIsSpace(int);
    int acutIsUpper(int);
    int acutIsXDigit(int);
    int acutPrintf(const ACHAR*,...);
    int acutRelRb(struct resbuf*);
    int acutSPrintf(ACHAR*,const ACHAR*,...);
    int acutToLower(int);
    int acutToUpper(int);
    int acutWcMatch(const ACHAR*,const ACHAR*);
    struct resbuf* acutBuildList(int,...);
    struct resbuf* acutNewRb(int);
    void acutPolar(const ads_point,ads_real,ads_real,ads_point);
#ifdef __cplusplus
} //extern "C"
#endif //__cplusplus

#ifdef __cplusplus
Acad::ErrorStatus acutNewBuffer(char*&,size_t);
Acad::ErrorStatus acutNewBuffer(void*&,size_t);
Acad::ErrorStatus acutNewString(ACHAR*&,int);
Acad::ErrorStatus acutNewString(const ACHAR*,ACHAR*&);
Acad::ErrorStatus acutUpdString(const ACHAR*,ACHAR*&);
Acad::ErrorStatus acutXStrNormalize(ACHAR*&,bool);
Acad::ErrorStatus acutXStrUppercase(ACHAR*&);
Acad::ErrorStatus newBuffer(char*&,size_t);
Acad::ErrorStatus newString(ACHAR*&,int);
Acad::ErrorStatus newString(const ACHAR*,ACHAR*&);
Acad::ErrorStatus updString(const ACHAR*,ACHAR*&);
bool acutSplitString(size_t&,const ACHAR*&,const ACHAR*,unsigned int);
bool acutWcMatchEx(const ACHAR*,const ACHAR*,bool);
void acutDelBuffer(char*&);
void acutDelBuffer(void*&);
void acutDelString(char*&);
void acutDelString(wchar_t*&);
void delBuffer(char*&);
void delString(ACHAR*&);
#endif //__cplusplus

size_t acutXStrLength(const ACHAR*);
void acutAssertMessage(const ACHAR*,const ACHAR*,int,const ACHAR*);
void acutTrimWhiteSpace(ACHAR*);

#ifdef __cplusplus
struct AcUt
{
    enum QFormatBitFlags
    {
        kSuppressZeroFeet = 256,
        kSuppressZeroInches = 512,
        kSuppressLeadingZero = 1024,
        kSuppressTrailingZero = 2048,
        kIgnoreUnitMode = 4096,
        kUseAltUnits = 8192
    };
};
#endif //__cplusplus