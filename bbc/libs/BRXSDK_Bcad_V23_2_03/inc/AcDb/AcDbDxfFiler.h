// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "brx_platform_3264.h"
#include "AcDb/AcDbGlobal.h"
#include "AcDb/AcDbObjectId.h"
#include "AcGe/AcGePoint2d.h"
#include "AcGe/AcGePoint3d.h"
#include "AcGe/AcGeScale3d.h"
#include "AcRx/AcRxObject.h"

/** _ */
class BRX_IMPORTEXPORT AcDbDxfFiler: public AcRxObject
{
public:
    enum
    {
        kDfltPrec = -1,
        kMaxPrec = 16
    };

    ACRX_DECLARE_MEMBERS(AcDbDxfFiler);

    AcDbDxfFiler();
    virtual ~AcDbDxfFiler();

    virtual Acad::ErrorStatus dwgVersion(AcDb::AcDbDwgVersion&,AcDb::MaintenanceReleaseVersion&) const;
    virtual Acad::ErrorStatus filerStatus() const = 0;
    virtual Acad::ErrorStatus pushBackItem();
    virtual Acad::ErrorStatus readResBuf(resbuf*);
    virtual Acad::ErrorStatus setError(Acad::ErrorStatus,const ACHAR*,...);
    virtual Acad::ErrorStatus setError(const ACHAR*,...);
    virtual Acad::ErrorStatus writeAcDbHandle(AcDb::DxfCode,const AcDbHandle&) = 0;
    virtual Acad::ErrorStatus writeBChunk(AcDb::DxfCode,const ads_binary&) = 0;
    virtual Acad::ErrorStatus writeBool(AcDb::DxfCode,bool) = 0;
    virtual Acad::ErrorStatus writeBoolean(AcDb::DxfCode,Adesk::Boolean) = 0;
    virtual Acad::ErrorStatus writeDouble(AcDb::DxfCode,double,int = kDfltPrec) = 0;
    virtual Acad::ErrorStatus writeEmbeddedObjectStart();
    virtual Acad::ErrorStatus writeInt16(AcDb::DxfCode,Adesk::Int16) = 0;
    virtual Acad::ErrorStatus writeInt32(AcDb::DxfCode,Adesk::Int32) = 0;
    virtual Acad::ErrorStatus writeInt64(AcDb::DxfCode, Adesk::Int64) = 0;
    virtual Acad::ErrorStatus writeUInt64(AcDb::DxfCode, Adesk::UInt64) = 0;
    virtual Acad::ErrorStatus writeInt8(AcDb::DxfCode,Adesk::Int8) = 0;
    virtual Acad::ErrorStatus writeObjectId(AcDb::DxfCode,const AcDbObjectId&) = 0;
    virtual Acad::ErrorStatus writePoint2d(AcDb::DxfCode,const AcGePoint2d&,int = kDfltPrec) = 0;
    virtual Acad::ErrorStatus writePoint3d(AcDb::DxfCode,const AcGePoint3d&,int = kDfltPrec) = 0;
    virtual Acad::ErrorStatus writeResBuf(const resbuf&);
    virtual Acad::ErrorStatus writeScale3d(AcDb::DxfCode,const AcGeScale3d&,int = kDfltPrec) = 0;
    virtual Acad::ErrorStatus writeString(AcDb::DxfCode,const ACHAR*) = 0;
    virtual Acad::ErrorStatus writeString(AcDb::DxfCode,const AcString&) = 0;
    virtual Acad::ErrorStatus writeUInt16(AcDb::DxfCode,Adesk::UInt16) = 0;
    virtual Acad::ErrorStatus writeUInt32(AcDb::DxfCode,Adesk::UInt32) = 0;
    virtual Acad::ErrorStatus writeUInt8(AcDb::DxfCode,Adesk::UInt8) = 0;
    virtual Acad::ErrorStatus writeVector2d(AcDb::DxfCode,const AcGeVector2d&,int = kDfltPrec) = 0;
    virtual Acad::ErrorStatus writeVector3d(AcDb::DxfCode,const AcGeVector3d&,int = kDfltPrec) = 0;
    virtual Acad::ErrorStatus writeXDataStart();
    virtual AcDb::FilerType filerType() const = 0;
    virtual AcDbDatabase* database() const = 0;
    virtual bool atEmbeddedObjectStart();
    virtual bool atEndOfObject();
    virtual bool atEOF();
    virtual bool atExtendedData();
    virtual bool atSubclassData(const ACHAR*);
    virtual bool includesDefaultValues() const = 0;
    virtual bool isModifyingExistingObject() const;
    virtual const ACHAR* errorMessage() const;
    virtual double elevation() const;
    virtual double thickness() const;
    virtual int precision() const;
    virtual int rewindFiler() = 0;
    virtual void haltAtClassBoundries(bool);
    virtual void resetFilerStatus() = 0;
    virtual void setPrecision(int);

    Acad::ErrorStatus readItem(resbuf*);
    Acad::ErrorStatus writeChar(AcDb::DxfCode,Adesk::Int8);
    Acad::ErrorStatus writeItem(AcDb::DxfCode,Adesk::Int16);
    Acad::ErrorStatus writeItem(AcDb::DxfCode,Adesk::Int32);
    Acad::ErrorStatus writeItem(AcDb::DxfCode,Adesk::Int8);
    Acad::ErrorStatus writeItem(AcDb::DxfCode,Adesk::UInt16);
    Acad::ErrorStatus writeItem(AcDb::DxfCode,Adesk::UInt32);
    Acad::ErrorStatus writeItem(AcDb::DxfCode,Adesk::UInt8);
    Acad::ErrorStatus writeItem(AcDb::DxfCode,bool);
    Acad::ErrorStatus writeItem(AcDb::DxfCode,const AcDbHandle&);
    Acad::ErrorStatus writeItem(AcDb::DxfCode,const AcDbObjectId&);
    Acad::ErrorStatus writeItem(AcDb::DxfCode,const AcGePoint2d&,int = kDfltPrec);
    Acad::ErrorStatus writeItem(AcDb::DxfCode,const AcGePoint3d&,int = kDfltPrec);
    Acad::ErrorStatus writeItem(AcDb::DxfCode,const AcGeScale3d&,int = kDfltPrec);
    Acad::ErrorStatus writeItem(AcDb::DxfCode,const AcGeVector2d&,int = kDfltPrec);
    Acad::ErrorStatus writeItem(AcDb::DxfCode,const AcGeVector3d&,int = kDfltPrec);
    Acad::ErrorStatus writeItem(AcDb::DxfCode,const ACHAR*);
    Acad::ErrorStatus writeItem(AcDb::DxfCode,const ads_binary&);
    Acad::ErrorStatus writeItem(AcDb::DxfCode,double,int = kDfltPrec);
    Acad::ErrorStatus writeItem(const resbuf&);

#ifndef _LINUXMAC64
    Acad::ErrorStatus writeItem(AcDb::DxfCode,Adesk::Boolean);
#endif //!_LINUXMAC64
};
