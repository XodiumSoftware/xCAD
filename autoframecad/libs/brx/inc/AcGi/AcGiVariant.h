// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcRx/AcRxObject.h"
#include "AcCm/AcCmGlobal.h"
#include "AcDb/AcDbGlobal.h"


/** _ */
class BRX_IMPORTEXPORT AcGiVariant: public AcRxObject
{
public:
    enum VariantType
    {
        kUndefined = 0,
        kBoolean   = 1,
        kInt       = 2,
        kDouble    = 3,
        kColor     = 4,
        kString    = 5,
        kTable     = 6,
    };

    class EnumType
    {
    public:
      explicit EnumType(int val) : m_value(val) { }

      template <typename T>
      operator T () { return static_cast<T>(m_value); }

      template <typename T>
      bool operator == (T other) const { return this->m_value == static_cast<int>(other); }

      template <typename T>
      bool operator != (T other) const { return !(other == *this); }

    protected:
      int m_value;
    };

public:
    ACRX_DECLARE_MEMBERS(AcGiVariant);

    AcGiVariant();
    virtual ~AcGiVariant();

    virtual bool  operator== (const AcGiVariant&) const;
    virtual Acad::ErrorStatus copyFrom(const AcRxObject*);

    AcGiVariant(bool);
    AcGiVariant(Adesk::Int32);
    AcGiVariant(double);
    AcGiVariant(const ACHAR*);
    AcGiVariant(const AcCmColor&);
    AcGiVariant(const AcGiVariant&);

    AcGiVariant& operator= (const AcGiVariant&);

    VariantType type() const;

    char           asChar() const;
    unsigned char  asUchar() const;
    short          asShort() const;
    unsigned short asUshort() const;
    unsigned int   asUint() const;
    int            asInt() const;
    float          asFloat() const;
    double         asDouble() const;
    bool           asBoolean() const;
    Adesk::Int32   asLong() const;
    Adesk::UInt32  asUlong() const;
    AcCmColor      asColor() const;
    AcString       asString() const;
    EnumType       asEnum() const;

    void  set(bool);
    void  set(Adesk::Int32);
    void  set(double);
    void  set(const AcCmColor&);
    void  set(const ACHAR*);

    void               setElem(const ACHAR*, const AcGiVariant&);
    Acad::ErrorStatus  getElem(const ACHAR*, AcGiVariant&) const;
    const AcGiVariant* getElem(const ACHAR*) const;

    int                getElemCount() const;
    void               deleteElem(const ACHAR*);

    AcGiVariant*       getElemAt(const int, ACHAR*&) const;
    Acad::ErrorStatus  getElemAt(const int, ACHAR*&, AcGiVariant &) const;

    static bool isEquivalent(AcGiVariant*, AcGiVariant*);
};

template <typename T>
inline bool operator!= (T me, const AcGiVariant::EnumType other)
{
    return (me != other);
}

template <typename T>
inline bool operator== (T me, const AcGiVariant::EnumType other)
{
    return (me == other);
}
