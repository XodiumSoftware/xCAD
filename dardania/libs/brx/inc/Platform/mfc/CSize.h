// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

// Windows MFC CSize type and functions

#ifndef _BS_MFC_CMfcSize_INCLUDED_
#define _BS_MFC_CMfcSize_INCLUDED_

#ifndef BRXEXPORT // for client build : import
#define BRXEXPORT
#endif

// ========== Platform independent ==========

#ifdef _WIN32
namespace Mfc
{
#endif

class CRect;
class CPoint;

class BRXEXPORT CSize : public tagSIZE
{
public:
    CSize() noexcept(false);
    CSize(int cx, int cy) noexcept(false);
    CSize(SIZE setSize) noexcept(false);
    CSize(POINT setPoint) noexcept(false);
    CSize(DWORD setSize) noexcept(false);

    BOOL operator==(SIZE otherSize) const noexcept(false);
    BOOL operator!=(SIZE otherSize) const noexcept(false);
    void operator+=(SIZE otherSize) noexcept(false);
    void operator-=(SIZE otherSize) noexcept(false);
    void SetSize(int cx, int cy) noexcept(false);

    CSize operator-() const noexcept(false);

    CSize operator+(SIZE otherSize) const noexcept(false);
    CSize operator-(SIZE otherSize) const noexcept(false);

    CPoint operator+(POINT pt) const noexcept(false);
    CPoint operator-(POINT pt) const noexcept(false);

    CRect operator+(const RECT* rect) const noexcept(false);
    CRect operator-(const RECT* rect) const noexcept(false);
};

#ifdef _WIN32
}; // namespace Mfc
#endif

// ========== Platform specific ==========

#ifdef _WIN32
  typedef Mfc::CSize CMfcSize;
#else  // Linux,Mac
  typedef      CSize CMfcSize;
#endif

#endif // _BS_MFC_CMfcSize_INCLUDED_
