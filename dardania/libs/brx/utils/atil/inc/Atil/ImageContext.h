// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "Atil/Defs.h"
#include "Atil/DataModelAttributes.h"
#include "Atil/ImagePixel.h"


namespace Atil
{;


class CellRequestor;
class ImageContextRep;
class Image;
class Internal;


class ATIL_IMPORTEXPORT ImageContext
{
public:
    enum Access
    {
        kRead = 0,
        kWrite = 1
    };
    enum Behavior
    {
        kDefaultColor = 0,
        kException = 1,
        kAutoExpand = 2
    };

public:
    ~ImageContext();

    CellRequestor* constructCellRequestor(int);
    void flush();
    int get1(Int32, Int32);
    UInt8 get8(Int32, Int32);
    UInt16 get16(Int32, Int32);
    UInt32 get24(Int32, Int32); //BRX only
    UInt32 get32(Int32, Int32);
    UInt64 get64(Int32, Int32);
    Data128 get128(Int32, Int32);
    ImagePixel getPixel(Int32, Int32);
    bool getTile(int, int, UInt8*&);
    DataModelAttributes::PixelType getPixelType() const;
    void getRow(Int32, Int32, int, void*);
    void put1(Int32, Int32, int);
    void put8(Int32, Int32, UInt8);
    void put16(Int32, Int32, UInt16);
    void put24(Int32, Int32, UInt32); //BRX only
    void put32(Int32, Int32, UInt32);
    void put64(Int32, Int32, UInt64);
    void put128(Int32, Int32, Data128);
    void putPixel(Int32, Int32, ImagePixel);
    bool putTile();
    void putRow(Int32, Int32, int, void*);
    void releaseTile();
    void setOutOfBoundsBehavior(Behavior);
    void setOutOfBoundsColor(ImagePixel);
    void setRow(Int32, Int32, int, ImagePixel);
    bool tileHasData(int, int);

private:
    friend Image;
    friend Internal;
    ImageContext(ImageContextRep*);
    ImageContextRep* m_pImp;
};


} //namespace Atil
