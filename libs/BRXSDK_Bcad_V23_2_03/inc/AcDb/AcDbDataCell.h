// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbGlobal.h"
#include "AcGe/AcGePoint3d.h"
#include "AcRx/AcRxObject.h"

/** _ */
class AcDbDataCell: public AcRxObject
{
public:
    enum CellType
    {
        kUnknown = 0,
        kInteger,
        kDouble,
        kCharPtr,
        kPoint,
        kObjectId,
        kHardOwnerId,
        kSoftOwnerId,
        kHardPtrId,
        kSoftPtrId,
        kBool,
        kVector
    };

    ACRX_DECLARE_MEMBERS(AcDbDataCell);

    AcDbDataCell();
    AcDbDataCell(const AcDbDataCell&);
    AcDbDataCell(bool);
    AcDbDataCell(const AcDbHardOwnershipId&);
    AcDbDataCell(const AcDbHardPointerId&);
    AcDbDataCell(const AcDbObjectId&);
    AcDbDataCell(const AcDbSoftOwnershipId&);
    AcDbDataCell(const AcDbSoftPointerId&);
    AcDbDataCell(const AcGePoint3d&);
    AcDbDataCell(const AcGeVector3d&);
    AcDbDataCell(const ACHAR*);
    AcDbDataCell(double);
    AcDbDataCell(int);
    virtual ~AcDbDataCell();

    virtual AcDbDataCell& operator=(bool);
    virtual AcDbDataCell& operator=(const AcDbDataCell&);
    virtual AcDbDataCell& operator=(const AcDbHardOwnershipId&);
    virtual AcDbDataCell& operator=(const AcDbHardPointerId&);
    virtual AcDbDataCell& operator=(const AcDbObjectId&);
    virtual AcDbDataCell& operator=(const AcDbSoftOwnershipId&);
    virtual AcDbDataCell& operator=(const AcDbSoftPointerId&);
    virtual AcDbDataCell& operator=(const AcGePoint3d&);
    virtual AcDbDataCell& operator=(const AcGeVector3d&);
    virtual AcDbDataCell& operator=(const ACHAR*);
    virtual AcDbDataCell& operator=(double);
    virtual AcDbDataCell& operator=(int);
    virtual bool operator!=(const AcDbDataCell&) const;
    virtual bool operator==(const AcDbDataCell&) const;
    virtual CellType type() const;
    virtual operator AcDbHardOwnershipId&() const;
    virtual operator AcDbHardPointerId&() const;
    virtual operator AcDbObjectId&() const;
    virtual operator AcDbSoftOwnershipId&() const;
    virtual operator AcDbSoftPointerId&() const;
    virtual operator AcGePoint3d&() const;
    virtual operator AcGeVector3d&() const;
    virtual operator bool() const;
    virtual operator const ACHAR*() const;
    virtual operator double() const;
    virtual operator int() const;
    virtual void init();
};

typedef AcArray< AcDbDataCell, AcArrayObjectCopyReallocator<AcDbDataCell> > AcDbDataCellArray;
