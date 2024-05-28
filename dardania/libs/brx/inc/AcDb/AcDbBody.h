// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbEntity.h"

/** _ */
class BRX_EXPORT AcDbBody: public AcDbEntity
{
public:
    ACDB_DECLARE_MEMBERS(AcDbBody);

    AcDbBody();
    virtual ~AcDbBody();

    virtual Adesk::Boolean isNull() const;
    virtual Adesk::UInt32 numChanges() const;

    static Acad::ErrorStatus acisIn(const ACHAR*,AcDbVoidPtrArray&);
    static Acad::ErrorStatus acisOut(const ACHAR*,const AcDbVoidPtrArray&);

    //V10
    virtual Acad::ErrorStatus setBody(const void*);
    virtual AcDbSubentId internalSubentId(void*) const;
    virtual void* body() const;
    virtual void* internalSubentPtr(const AcDbSubentId&) const;

protected:
    virtual Acad::ErrorStatus subGetGsMarkersAtSubentPath(const AcDbFullSubentPath&,AcArray<Adesk::GsMarker>&) const;
    virtual Acad::ErrorStatus subGetSubentPathsAtGsMarker(AcDb::SubentType,Adesk::GsMarker,const AcGePoint3d&,const AcGeMatrix3d&,int&,AcDbFullSubentPath*&,int = 0,AcDbObjectId* = NULL) const;
    virtual void subList() const;
    virtual AcDbEntity* subSubentPtr(const AcDbFullSubentPath&) const;
};
