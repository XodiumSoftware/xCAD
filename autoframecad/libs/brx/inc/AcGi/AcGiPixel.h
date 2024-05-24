// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

/** _ */
class AcGiPixelBGRA32
{
public:
    AcGiPixelBGRA32() {}
    AcGiPixelBGRA32(Adesk::UInt32 bgra) : m_bgra32(bgra) {}
    AcGiPixelBGRA32(Adesk::UInt8 b, Adesk::UInt8 g, Adesk::UInt8 r, Adesk::UInt8 a) : m_bgra32(b, g, r, a) {}

    Adesk::UInt8 alpha() const { return m_bgra32.a(); }
    Adesk::UInt8 blue() const { return m_bgra32.b(); }
    Adesk::UInt8 green() const { return m_bgra32.g(); }
    Adesk::UInt8 red() const { return m_bgra32.r(); }
    Adesk::UInt32 getBGRA() const { return m_bgra32; }
    Adesk::UInt32 getRGBA() const { return m_bgra32.asRGBA(); }
    void setAlpha(Adesk::UInt8 a) { m_bgra32.a() = a; }
    void setBlue(Adesk::UInt8 b) { m_bgra32.b() = b; }
    void setGreen(Adesk::UInt8 g) { m_bgra32.g() = g; }
    void setRed(Adesk::UInt8 r) { m_bgra32.r() = r; }
    void setBGRA(Adesk::UInt32 bgra) { m_bgra32 = bgra; }
    void setBGRA(Adesk::UInt8 b, Adesk::UInt8 g, Adesk::UInt8 r, Adesk::UInt8 a) { m_bgra32 = b4(b, g, r, a); }
    void setRGBA(Adesk::UInt32 rgba) { b4& n = *(b4*)&rgba; m_bgra32 = b4(n._3, n._2, n._1, n._4); }
    void setRGBA(Adesk::UInt8 r, Adesk::UInt8 g, Adesk::UInt8 b, Adesk::UInt8 a) { m_bgra32 = b4(b, g, r, a); }

private:
    struct b4
    {
        Adesk::UInt8 _1, _2, _3, _4;
        b4(Adesk::UInt32 n) { *this = n; }
        b4(Adesk::UInt8 b1, Adesk::UInt8 b2, Adesk::UInt8 b3, Adesk::UInt8 b4) : _1(b1), _2(b2), _3(b3), _4(b4) {}
        operator Adesk::UInt32() const { return *(Adesk::UInt32*)this; }
        b4& operator= (Adesk::UInt32 n) { *(Adesk::UInt32*)this = n; return *this; }
    };
    struct bgra32 : public b4
    {
        bgra32() : b4(0, 0, 0, 0xff) {}
        bgra32(Adesk::UInt32 bgra) : b4(bgra) {}
        bgra32(Adesk::UInt8 b, Adesk::UInt8 g, Adesk::UInt8 r, Adesk::UInt8 a) : b4(b, g, r, a) {}
        bgra32& operator=(Adesk::UInt32 bgra) { b4::operator=(bgra); return *this; }
        Adesk::UInt8 b() const { return _1; }
        Adesk::UInt8 g() const { return _2; }
        Adesk::UInt8 r() const { return _3; }
        Adesk::UInt8 a() const { return _4; }
        Adesk::UInt8& b() { return _1; }
        Adesk::UInt8& g() { return _2; }
        Adesk::UInt8& r() { return _3; }
        Adesk::UInt8& a() { return _4; }
        b4 asRGBA() const { return b4(r(), g(), b(), a()); }
    } m_bgra32;
};
