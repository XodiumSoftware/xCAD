// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

// Windows MFC CRect type and functions

#ifndef _BS_MFC_CRECT_INCLUDED_
#define _BS_MFC_CRECT_INCLUDED_

#ifndef BRXEXPORT // for client build : import
#define BRXEXPORT
#endif

// ========== Platform independent ==========

#ifdef _WIN32
namespace Mfc
{
#endif

class CSize;
class CPoint;

class BRXEXPORT CRect : public tagRECT
{
public:
    CRect() noexcept(false);
    CRect(int xLeft, int yTop, int xRight, int yBottom) noexcept(false);
    CRect(const RECT& source) noexcept(false);
    CRect(LPCRECT lpSource) noexcept(false);
    CRect(POINT pt, SIZE size) noexcept(false);
    CRect(POINT topLeft, POINT bottomRight) noexcept(false);

    int Width() const noexcept(false);
    int Height() const noexcept(false);
    CSize Size() const noexcept(false);
    CPoint& TopLeft() noexcept(false);
    CPoint& BottomRight() noexcept(false);
    const CPoint& TopLeft() const noexcept(false);
    const CPoint& BottomRight() const noexcept(false);
    CPoint CenterPoint() const noexcept(false);
    void SwapLeftRight() noexcept(false);
    static void WINAPI SwapLeftRight(LPRECT lpRect) noexcept(false);

    operator LPRECT() noexcept(false);
    operator LPCRECT() const noexcept(false);

    BOOL IsRectEmpty() const noexcept(false);
    BOOL IsRectNull() const noexcept(false);
    BOOL PtInRect(POINT point) const noexcept(false);

    void SetRect(int x1, int y1, int x2, int y2) noexcept(false);
    void SetRect(POINT topLeft, POINT bottomRight) noexcept(false);
    void SetRectEmpty() noexcept(false);
    void CopyRect(LPCRECT lpSrcRect) noexcept(false);
    BOOL EqualRect(LPCRECT lpRect) const noexcept(false);

    void InflateRect(int x, int y) noexcept(false);
    void InflateRect(SIZE size) noexcept(false);
    void InflateRect(LPCRECT lpRect) noexcept(false);
    void InflateRect(int l, int t, int r, int b) noexcept(false);

    void DeflateRect(int x, int y) noexcept(false);
    void DeflateRect(SIZE size) noexcept(false);
    void DeflateRect(LPCRECT lpRect) noexcept(false);
    void DeflateRect(int l, int t, int r, int b) noexcept(false);

    void OffsetRect(int x, int y) noexcept(false);
    void OffsetRect(SIZE size) noexcept(false);
    void OffsetRect(POINT point) noexcept(false);

    void NormalizeRect() noexcept(false);

    void MoveToX(int x) noexcept(false);
    void MoveToY(int y) noexcept(false);    
    void MoveToXY(int x, int y) noexcept(false);
    void MoveToXY(POINT point) noexcept(false);

    BOOL IntersectRect(LPCRECT lpRect1, LPCRECT lpRect2) noexcept(false);
    BOOL UnionRect(LPCRECT lpRect1, LPCRECT lpRect2) noexcept(false);
    BOOL SubtractRect(LPCRECT lpRect1, LPCRECT lpRect2) noexcept(false);

    void operator=(const RECT& srcRect) noexcept(false);
    BOOL operator==(const RECT& rect) const noexcept(false);
    BOOL operator!=(const RECT& rect) const noexcept(false);
    void operator+=(POINT point) noexcept(false);
    void operator+=(SIZE size) noexcept(false);
    void operator+=(LPCRECT lpRect) noexcept(false);
    void operator-=(POINT point) noexcept(false);
    void operator-=(SIZE size) noexcept(false);
    void operator-=(LPCRECT lpRect) noexcept(false);
    void operator&=(const RECT& rect) noexcept(false);
    void operator|=(const RECT& rect) noexcept(false);

    CRect operator+(POINT point) const noexcept(false);
    CRect operator-(POINT point) const noexcept(false);
    CRect operator+(LPCRECT lpRect) const noexcept(false);
    CRect operator+(SIZE size) const noexcept(false);
    CRect operator-(SIZE size) const noexcept(false);
    CRect operator-(LPCRECT lpRect) const noexcept(false);
    CRect operator&(const RECT& rect2) const noexcept(false);
    CRect operator|(const RECT& rect2) const noexcept(false);
    CRect MulDiv(int nMultiplier, int nDivisor) const noexcept(false);
};

#ifdef _WIN32
}; // namespace Mfc
#endif

// ========== Platform specific ==========

#ifdef _WIN32
  typedef Mfc::CRect CMfcRect;
#else  // Linux,Mac
  typedef      CRect CMfcRect;
#endif

#endif // _BS_MFC_CRECT_INCLUDED_
