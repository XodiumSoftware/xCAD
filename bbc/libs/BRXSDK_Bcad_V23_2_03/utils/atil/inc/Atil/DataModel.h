// Copyright (C) 2017-2018 Menhirs NV. All rights reserved.
#pragma once

#include "Atil/Defs.h"
#include "Atil/DataModelAttributes.h"


namespace Atil
{;


class Internal;
class PaletteRep;


class ATIL_IMPORTEXPORT DataModel : public DataModelAttributes
{
public:
    enum TileSize
    {
        k64x64 = 0,
        k128x128 = 1,
        k256x256 = 2,
        k512x512 = 3,
        k1024x1024 = 4,
        kUnspecified = 5,
        kDefault = 6
    };

    static int bytesPerRow(Int32, DataModelAttributes::BitsPerPixel);
    static int bitsPerPixel(DataModelAttributes::BitsPerPixel);
    static void tileSize(TileSize, int&, int&);

public:
    DataModel(DataModelAttributes::DataType, DataModelAttributes::BitsPerPixel, int);
    virtual ~DataModel();

    //DataModelAttributes
    virtual DataModelAttributes::BitFields bitFields() const { return kFull; }
    virtual DataModelAttributes::BitsPerPixel bitsPerPixel() const { return m_bppType; }
    virtual int bitsUsedPerPixel() const { return m_dataBits; }
    virtual DataModelAttributes::ChannelOrder channelOrder() const { return kSingleChannel; }
    virtual DataModelAttributes::DataModelType dataModelType() const { return m_modelType; }
    virtual DataModelAttributes::DataType dataType() const { return m_dataType; }
    virtual DataModelAttributes::PixelType pixelType() const;

    //DataModel
    virtual DataModel* clone() const;
    virtual bool operator==(const DataModel& rh) const;
    virtual bool operator!=(const DataModel& rh) const;

public:
    virtual DataModel::TileSize defaultTileSize() const { return m_defSize; }
    virtual bool isCompatibleDataSize(DataModelAttributes::BitsPerPixel) const;
    virtual bool isCompatibleTileSize(DataModel::TileSize) const;

protected:
    DataModel(DataModelAttributes::DataModelType, DataModelAttributes::DataType, DataModelAttributes::BitsPerPixel);
    DataModel(DataModelAttributes::DataModelType, DataModelAttributes::DataType, DataModelAttributes::BitsPerPixel, int);
    DataModel(const DataModel& rh);

    DataModel& operator=(const DataModel& rh);
    //DataModel();

    DataModelAttributes::DataModelType m_modelType;
    DataModelAttributes::BitsPerPixel m_bppType;
    DataModelAttributes::DataType m_dataType;
    int m_bpp;
    int m_dataBits;
    TileSize m_defSize;

private:
    friend Internal;
    mutable PaletteRep* m_paletteImp;
};


} //namespace Atil
