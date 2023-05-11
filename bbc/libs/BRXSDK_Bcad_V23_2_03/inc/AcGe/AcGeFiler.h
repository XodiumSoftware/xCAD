// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbGlobal.h"
#include "AcGe/AcGeGlobal.h"

/** _ */
class BRX_IMPORTEXPORT AcGeFiler
{
protected:
    AcGeFiler();

public:
    virtual Acad::ErrorStatus readBool(bool*) = 0;
    virtual Acad::ErrorStatus readBoolean(Adesk::Boolean*) = 0;
    virtual Acad::ErrorStatus readBytes(void*,unsigned long) = 0;
    virtual Acad::ErrorStatus readDouble(double*) = 0;
    virtual Acad::ErrorStatus readLong(long*) = 0;
    virtual Acad::ErrorStatus readPoint2d(AcGePoint2d*) = 0;
    virtual Acad::ErrorStatus readPoint3d(AcGePoint3d*) = 0;
    virtual Acad::ErrorStatus readShort(short*) = 0;
    virtual Acad::ErrorStatus readSignedByte(char*) = 0;
    virtual Acad::ErrorStatus readString(AcString&) = 0;
    virtual Acad::ErrorStatus readUChar(unsigned char*) = 0;
    virtual Acad::ErrorStatus readULong(unsigned long*) = 0;
    virtual Acad::ErrorStatus readUShort(unsigned short*) = 0;
    virtual Acad::ErrorStatus readVector2d(AcGeVector2d*) = 0;
    virtual Acad::ErrorStatus readVector3d(AcGeVector3d*) = 0;
    virtual Acad::ErrorStatus writeBool(bool) = 0;
    virtual Acad::ErrorStatus writeBoolean(Adesk::Boolean) = 0;
    virtual Acad::ErrorStatus writeBytes(const void*,unsigned long) = 0;
    virtual Acad::ErrorStatus writeDouble(double) = 0;
    virtual Acad::ErrorStatus writeLong(long) = 0;
    virtual Acad::ErrorStatus writePoint2d(const AcGePoint2d&) = 0;
    virtual Acad::ErrorStatus writePoint3d(const AcGePoint3d&) = 0;
    virtual Acad::ErrorStatus writeShort(short) = 0;
    virtual Acad::ErrorStatus writeSignedByte(char) = 0;
    virtual Acad::ErrorStatus writeString(const AcString&) = 0;
    virtual Acad::ErrorStatus writeUChar(unsigned char) = 0;
    virtual Acad::ErrorStatus writeULong(unsigned long) = 0;
    virtual Acad::ErrorStatus writeUShort(unsigned short) = 0;
    virtual Acad::ErrorStatus writeVector2d(const AcGeVector2d&) = 0;
    virtual Acad::ErrorStatus writeVector3d(const AcGeVector3d&) = 0;
    virtual AcDbDwgFiler* dwgFiler();
};
