// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbObjectId.h"
#include "AcGe/AcGePoint3d.h"

struct resbuf;

/** _ */
class BRX_IMPORTEXPORT AcEdInputContextReactor
{
public:
//BRX START
    AcEdInputContextReactor();
//BRX_END

    virtual ~AcEdInputContextReactor();

    virtual void beginDragSequence(const ACHAR*) {}
    virtual void beginEntsel(const ACHAR*,int,const ACHAR*) {}
    virtual void beginGetAngle(const AcGePoint3d*,const ACHAR*,int,const ACHAR*) {}
    virtual void beginGetColor(const int*,const ACHAR*,int,const ACHAR*) {}
    virtual void beginGetCorner(const AcGePoint3d*,const ACHAR*,int,const ACHAR*) {}
    virtual void beginGetDistance(const AcGePoint3d*,const ACHAR*,int,const ACHAR*) {}
    virtual void beginGetInteger(const int*,const ACHAR*,int,const ACHAR*) {}
    virtual void beginGetKeyword(const ACHAR*,int,const ACHAR*) {}
    virtual void beginGetOrientation(const AcGePoint3d*,const ACHAR*,int,const ACHAR*) {}
    virtual void beginGetPoint(const AcGePoint3d*,const ACHAR*,int,const ACHAR*) {}
    virtual void beginGetReal(const double*,const ACHAR*,int,const ACHAR*) {}
    virtual void beginGetScaleFactor(const AcGePoint3d*,const ACHAR*,int,const ACHAR*) {}
    virtual void beginGetString(const ACHAR*,int) {}
    virtual void beginNentsel(const ACHAR*,Adesk::Boolean,int,const ACHAR*) {}
    virtual void beginQuiescentState() {}
    virtual void beginSSGet(const ACHAR*,int,const ACHAR*,const ACHAR*,const AcGePoint3dArray&,const resbuf*) {}
    virtual void endDragSequence(Acad::PromptStatus,AcGePoint3d&,AcGeVector3d&) {}
    virtual void endEntsel(Acad::PromptStatus,AcDbObjectId&,AcGePoint3d&,const ACHAR*) {}
    virtual void endGetAngle(Acad::PromptStatus,double&,const ACHAR*&) {}
    virtual void endGetColor(Acad::PromptStatus,int&,const ACHAR*&) {}
    virtual void endGetCorner(Acad::PromptStatus,AcGePoint3d&,const ACHAR*&) {}
    virtual void endGetDistance(Acad::PromptStatus,double&,const ACHAR*&) {}
    virtual void endGetInteger(Acad::PromptStatus,int&,const ACHAR*&) {}
    virtual void endGetKeyword (Acad::PromptStatus,const ACHAR*&) {}
    virtual void endGetOrientation(Acad::PromptStatus,double&,const ACHAR*&) {}
    virtual void endGetPoint(Acad::PromptStatus,const AcGePoint3d&,const ACHAR*&) {}
    virtual void endGetReal(Acad::PromptStatus,double&,const ACHAR*&) {}
    virtual void endGetScaleFactor(Acad::PromptStatus,double&,const ACHAR*&) {}
    virtual void endGetString (Acad::PromptStatus,ACHAR*) {}
    virtual void endNentsel(Acad::PromptStatus,AcDbObjectId,const AcGePoint3d&,const AcGeMatrix3d&,const resbuf*,const ACHAR*) {}
    virtual void endQuiescentState() {}
    virtual void endSSGet(Acad::PromptStatus,const AcDbObjectIdArray&) {}

//BRX START
private:
    friend class AcEdInputPointManagerImp;
    friend class BrxEdInputContextReactor;
    friend class AcEdSSGetFilter;
    friend class AcEdSSGetFilter2;
    class BrxEdInputContextReactor* m_pBrxImp;
//BRX END

};