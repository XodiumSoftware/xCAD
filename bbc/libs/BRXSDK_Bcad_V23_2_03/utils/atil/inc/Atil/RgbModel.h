// Copyright (C) 2017-2018 Menhirs NV. All rights reserved.
#pragma once

#include "Atil/Defs.h"
#include "Atil/DataModel.h"
#include "Atil/ColorModelInterface.h"


namespace Atil
{;


class ATIL_IMPORTEXPORT RgbModel : public DataModel, public ColorModelInterface
{
public:
    static bool isRgb(DataModelAttributes::DataModelType mt);
    static RowProviderInterface* convertToRgba(RowProviderInterface* pipe);

public:
    RgbModel();
    RgbModel(RgbModelAttributes::Channels channels, DataModelAttributes::ChannelOrder co);
    RgbModel(RgbModelAttributes::Channels channels, DataModelAttributes::ChannelOrder co, DataModelAttributes::BitsPerPixel bp, int dataBits);
    RgbModel(int usedBpp);
    RgbModel(const RgbModel &model);
    virtual ~RgbModel() {}

    //DataModelAttributes
    virtual DataModelAttributes::ChannelOrder channelOrder() const { return m_order; }
    virtual DataModelAttributes::DataModelType dataModelType() const { return DataModelAttributes::kRgbModel; }
    virtual DataModelAttributes::PixelType pixelType() const { return DataModelAttributes::kRgba; }

    //DataModel
    virtual DataModel* clone() const;
    virtual bool operator==(const DataModel& rh) const;
    virtual bool operator!=(const DataModel& rh) const;

    //ColorModelInterface
    virtual bool canConvertFrom(const ColorModelInterface* cm) const;
    virtual bool canConvertTo(const ColorModelInterface* cm) const;
    virtual RowProviderInterface* getModelConversionFrom(const ColorModelInterface* cm, RowProviderInterface* rp) const;
    virtual RowProviderInterface* getModelConversionTo(const ColorModelInterface* cm, RowProviderInterface* rp) const;

protected:
    RgbModel(DataModelAttributes::DataModelType type, DataModelAttributes::BitsPerPixel bp);
    RgbModel(DataModelAttributes::DataModelType type, DataModelAttributes::BitsPerPixel bp, int usedBpp);

    DataModelAttributes::ChannelOrder m_order;
};


class ATIL_IMPORTEXPORT Rgb24Model : public RgbModel //BRX only
{
public:
    Rgb24Model()
        : RgbModel(RgbModelAttributes::k3Channels, DataModelAttributes::kRedGreenBlueAlpha, DataModelAttributes::k24, 24) {}
    Rgb24Model(DataModelAttributes::ChannelOrder co)
        : RgbModel(RgbModelAttributes::k3Channels, co, DataModelAttributes::k24, 24) {}
};


} //namespace Atil
