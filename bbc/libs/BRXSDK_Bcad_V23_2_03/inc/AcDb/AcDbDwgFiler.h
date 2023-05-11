// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "brx_platform_3264.h"
#include "AcDb/AcDbGlobal.h"
#include "AcDb/AcDbHardOwnershipId.h"
#include "AcDb/AcDbHardPointerId.h"
#include "AcDb/AcDbR13ObjectId.h"
#include "AcDb/AcDbSoftOwnershipId.h"
#include "AcDb/AcDbSoftPointerId.h"
#include "AcGe/AcGePoint2d.h"
#include "AcGe/AcGePoint3d.h"
#include "AcGe/AcGeScale3d.h"
#include "AcRx/AcRxObject.h"

/** _ */
class BRX_IMPORTEXPORT AcDbDwgFiler: public AcRxObject
{
public:
    ACRX_DECLARE_MEMBERS(AcDbDwgFiler);

    AcDbDwgFiler();
    virtual ~AcDbDwgFiler();

    virtual Acad::ErrorStatus dwgVersion(AcDb::AcDbDwgVersion&,AcDb::MaintenanceReleaseVersion&) const;
    virtual Acad::ErrorStatus filerStatus() const = 0;
    virtual Acad::ErrorStatus readAcDbHandle(AcDbHandle*) = 0;
    virtual Acad::ErrorStatus readAddress(void**);
    virtual Acad::ErrorStatus readBChunk(ads_binary*) = 0;
    virtual Acad::ErrorStatus readBool(bool*) = 0;
    virtual Acad::ErrorStatus readBoolean(Adesk::Boolean*) = 0;
    virtual Acad::ErrorStatus readBytes(void*,Adesk::UIntPtr) = 0;
    virtual Acad::ErrorStatus readDouble(double*) = 0;
    virtual Acad::ErrorStatus readHardOwnershipId(AcDbHardOwnershipId*) = 0;
    virtual Acad::ErrorStatus readHardPointerId(AcDbHardPointerId*) = 0;
    virtual Acad::ErrorStatus readInt16(Adesk::Int16*) = 0;
    virtual Acad::ErrorStatus readInt32(Adesk::Int32*) = 0;
    virtual Acad::ErrorStatus readInt8(Adesk::Int8*) = 0;
    virtual Acad::ErrorStatus readPoint2d(AcGePoint2d*) = 0;
    virtual Acad::ErrorStatus readPoint3d(AcGePoint3d*) = 0;
    virtual Acad::ErrorStatus readScale3d(AcGeScale3d*) = 0;
    virtual Acad::ErrorStatus readSoftOwnershipId(AcDbSoftOwnershipId*) = 0;
    virtual Acad::ErrorStatus readSoftPointerId(AcDbSoftPointerId*) = 0;
    virtual Acad::ErrorStatus readString(ACHAR**) = 0;
    virtual Acad::ErrorStatus readString(AcString&) = 0;
    virtual Acad::ErrorStatus readUInt16(Adesk::UInt16*) = 0;
    virtual Acad::ErrorStatus readUInt32(Adesk::UInt32*) = 0;
    virtual Acad::ErrorStatus readUInt8(Adesk::UInt8*) = 0;
    virtual Acad::ErrorStatus readVector2d(AcGeVector2d*) = 0;
    virtual Acad::ErrorStatus readVector3d(AcGeVector3d*) = 0;
    virtual Acad::ErrorStatus writeAcDbHandle(const AcDbHandle&) = 0;
    virtual Acad::ErrorStatus writeAddress(const void*);
    virtual Acad::ErrorStatus writeBChunk(const ads_binary&) = 0;
    virtual Acad::ErrorStatus writeBool(bool) = 0;
    virtual Acad::ErrorStatus writeBoolean(Adesk::Boolean) = 0;
    virtual Acad::ErrorStatus writeBytes(const void*,Adesk::UIntPtr) = 0;
    virtual Acad::ErrorStatus writeDouble(double) = 0;
    virtual Acad::ErrorStatus writeHardOwnershipId(const AcDbHardOwnershipId&) = 0;
    virtual Acad::ErrorStatus writeHardPointerId(const AcDbHardPointerId&) = 0;
    virtual Acad::ErrorStatus writeInt16(Adesk::Int16) = 0;
    virtual Acad::ErrorStatus writeInt32(Adesk::Int32) = 0;
    virtual Acad::ErrorStatus writeInt8(Adesk::Int8) = 0;
    virtual Acad::ErrorStatus writePoint2d(const AcGePoint2d&) = 0;
    virtual Acad::ErrorStatus writePoint3d(const AcGePoint3d&) = 0;
    virtual Acad::ErrorStatus writeScale3d(const AcGeScale3d&) = 0;
    virtual Acad::ErrorStatus writeSoftOwnershipId(const AcDbSoftOwnershipId&) = 0;
    virtual Acad::ErrorStatus writeSoftPointerId(const AcDbSoftPointerId&) = 0;
    virtual Acad::ErrorStatus writeString(const ACHAR*) = 0;
    virtual Acad::ErrorStatus writeString(const AcString&) = 0;
    virtual Acad::ErrorStatus writeUInt16(Adesk::UInt16) = 0;
    virtual Acad::ErrorStatus writeUInt32(Adesk::UInt32) = 0;
    virtual Acad::ErrorStatus writeUInt8(Adesk::UInt8) = 0;
    virtual Acad::ErrorStatus writeVector2d(const AcGeVector2d&) = 0;
    virtual Acad::ErrorStatus writeVector3d(const AcGeVector3d&) = 0;
    virtual AcDb::FilerType filerType() const = 0;
    virtual AcDbAuditInfo* getAuditInfo() const;
    virtual bool usesReferences() const;
    virtual void resetFilerStatus() = 0;
    virtual void setFilerStatus(Acad::ErrorStatus) = 0;

    virtual Acad::ErrorStatus readInt64(Adesk::Int64*) = 0;
    virtual Acad::ErrorStatus readUInt64(Adesk::UInt64*) = 0;
    virtual Acad::ErrorStatus writeInt64(Adesk::Int64) = 0;
    virtual Acad::ErrorStatus writeUInt64(Adesk::UInt64) = 0;

    virtual Acad::ErrorStatus seek(Adesk::Int64,int) = 0;
    virtual Adesk::Int64 tell() const = 0;

    Acad::ErrorStatus readChar(Adesk::Int8*);
    Acad::ErrorStatus readItem(AcDbHandle*);
    Acad::ErrorStatus readItem(AcDbHardOwnershipId*);
    Acad::ErrorStatus readItem(AcDbHardPointerId*);
    Acad::ErrorStatus readItem(AcDbSoftOwnershipId*);
    Acad::ErrorStatus readItem(AcDbSoftPointerId*);
    Acad::ErrorStatus readItem(AcGePoint2d*);
    Acad::ErrorStatus readItem(AcGePoint3d*);
    Acad::ErrorStatus readItem(AcGeScale3d*);
    Acad::ErrorStatus readItem(AcGeVector2d*);
    Acad::ErrorStatus readItem(AcGeVector3d*);
    Acad::ErrorStatus readItem(ACHAR**);
    Acad::ErrorStatus readItem(Adesk::Int16*);
    Acad::ErrorStatus readItem(Adesk::Int32*);
    Acad::ErrorStatus readItem(Adesk::Int8*);
    Acad::ErrorStatus readItem(Adesk::UInt16*);
    Acad::ErrorStatus readItem(Adesk::UInt32*);
    Acad::ErrorStatus readItem(Adesk::UInt8*);
    Acad::ErrorStatus readItem(ads_binary*);
    Acad::ErrorStatus readItem(bool*);
    Acad::ErrorStatus readItem(double*);
    Acad::ErrorStatus readItem(void**);
    Acad::ErrorStatus readItem(void*,Adesk::ULongPtr);
    Acad::ErrorStatus readItem(Adesk::Int64*);
    Acad::ErrorStatus readItem(Adesk::UInt64*);

    Acad::ErrorStatus writeChar(Adesk::Int8);
    Acad::ErrorStatus writeItem(Adesk::Int16);
    Acad::ErrorStatus writeItem(Adesk::Int32);
    Acad::ErrorStatus writeItem(Adesk::Int8);
    Acad::ErrorStatus writeItem(Adesk::UInt16);
    Acad::ErrorStatus writeItem(Adesk::UInt32);
    Acad::ErrorStatus writeItem(Adesk::UInt8);
    Acad::ErrorStatus writeItem(bool);
    Acad::ErrorStatus writeItem(const AcDbHandle&);
    Acad::ErrorStatus writeItem(const AcDbHardOwnershipId&);
    Acad::ErrorStatus writeItem(const AcDbHardPointerId&);
    Acad::ErrorStatus writeItem(const AcDbSoftOwnershipId&);
    Acad::ErrorStatus writeItem(const AcDbSoftPointerId&);
    Acad::ErrorStatus writeItem(const AcGePoint2d&);
    Acad::ErrorStatus writeItem(const AcGePoint3d&);
    Acad::ErrorStatus writeItem(const AcGeScale3d&);
    Acad::ErrorStatus writeItem(const AcGeVector2d&);
    Acad::ErrorStatus writeItem(const AcGeVector3d&);
    Acad::ErrorStatus writeItem(const ACHAR*);
    Acad::ErrorStatus writeItem(const ads_binary&);
    Acad::ErrorStatus writeItem(const void*);
    Acad::ErrorStatus writeItem(const void*,Adesk::ULongPtr);
    Acad::ErrorStatus writeItem(double);
    Acad::ErrorStatus writeItem(Adesk::Int64);
    Acad::ErrorStatus writeItem(Adesk::UInt64);

#ifndef _LINUXMAC64
    Acad::ErrorStatus readItem(Adesk::Boolean*);
    Acad::ErrorStatus writeItem(Adesk::Boolean);
#endif //!_LINUXMAC64

    // BRX additions

    /* returns the database used by this AcDbDwgFiler */
    AcDbDatabase* database() const;

    // end of BRX additions
};
