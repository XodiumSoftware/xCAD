// Copyright (C) 2010-2014 Menhirs NV. All rights reserved.

// Windows MFC CPoint type and functions

#pragma once

#ifndef _BS_MFC_CPOINT_INCLUDED_
#define _BS_MFC_CPOINT_INCLUDED_

#ifndef BRXEXPORT // for client build : import
#define BRXEXPORT
#endif

// ========== Platform independent ==========

#ifndef GET_X_LPARAM
  #define GET_X_LPARAM(lparam) ((int)(short)LOWORD(lparam))
#endif
#ifndef GET_Y_LPARAM
  #define GET_Y_LPARAM(lparam) ((int)(short)HIWORD(lparam))
#endif


#ifdef _WIN32
namespace Mfc
{
#endif

class CSize;
class CRect;

class BRXEXPORT CPoint : public tagPOINT
{
public:
    CPoint() noexcept(false);
    CPoint(int ptX, int ptY) noexcept(false);
    CPoint(POINT ptInit) noexcept(false);
    CPoint(SIZE sizeInit) noexcept(false);
    CPoint(LPARAM dwPointInit) noexcept(false);

    void Offset(int offsetX, int OffsetY) noexcept(false);
    void Offset(POINT setPoint) noexcept(false);
    void Offset(SIZE setSize) noexcept(false);
    void SetPoint(int ptx, int pty) noexcept(false);

    BOOL operator==(POINT otherPoint) const noexcept(false);
    BOOL operator!=(POINT otherPoint) const noexcept(false);
    void operator+=(SIZE otherSize) noexcept(false);
    void operator-=(SIZE otherSize) noexcept(false);
    void operator+=(POINT otherPoint) noexcept(false);
    void operator-=(POINT otherPoint) noexcept(false);

    CPoint operator+(SIZE otherSize) const noexcept(false);
    CPoint operator+(POINT otherPoint) const noexcept(false);
    CRect operator+(const RECT* otherRect) const noexcept(false);

    CPoint operator-(SIZE otherSize) const noexcept(false);
    CSize operator-(POINT otherPoint) const noexcept(false);
    CRect operator-(const RECT* otherRect) const noexcept(false);

    CPoint operator-() const noexcept(false);
};

#ifdef _WIN32
}; // namespace Mfc
#endif

// ========== Platform specific ==========

#ifdef _WIN32
  typedef Mfc::CPoint CMfcPoint;
#else  // Linux,Mac
  typedef      CPoint CMfcPoint;
#endif

#endif // _BS_MFC_CPOINT_INCLUDED_
