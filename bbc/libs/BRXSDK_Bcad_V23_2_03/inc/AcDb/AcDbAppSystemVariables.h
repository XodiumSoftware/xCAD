// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbGlobal.h"

/** _ */
class BRX_IMPORTEXPORT AcDbAppSystemVariables
{
private:
    AcDb::LineWeight m_LWDEFAULT;
    bool m_ATTDIA;
    bool m_ATTREQ;
    bool m_BLIPMODE;
    bool m_HPASSOC;
    short m_COORDS;
    short m_DELOBJ;
    short m_DRAGMODE;
    short m_OSMODE;
    short m_PICKSTYLE;

public:
    AcDbAppSystemVariables();
    ~AcDbAppSystemVariables();

    Acad::ErrorStatus setAttdia(bool,bool = false);
    Acad::ErrorStatus setAttreq(bool,bool = false);
    Acad::ErrorStatus setBlipmode(bool,bool = false);
    Acad::ErrorStatus setCoords(Adesk::Int16,bool = false);
    Acad::ErrorStatus setDelUsedObj(Adesk::Int16,bool = false);
    Acad::ErrorStatus setDragmode(Adesk::Int16,bool = false);
    Acad::ErrorStatus setHpassoc(bool,bool = false);
    Acad::ErrorStatus setLwdefault(AcDb::LineWeight,bool = false);
    Acad::ErrorStatus setOsmode(Adesk::Int16,bool = false);
    Acad::ErrorStatus setPickstyle(Adesk::Int16,bool = false);
    AcDb::LineWeight lwdefault() const;
    Adesk::Int16 coords() const;
    Adesk::Int16 delUsedObj() const;
    Adesk::Int16 dragmode() const;
    Adesk::Int16 osmode() const;
    Adesk::Int16 pickstyle() const;
    bool attdia() const;
    bool attreq() const;
    bool blipmode() const;
    bool hpassoc() const;
};