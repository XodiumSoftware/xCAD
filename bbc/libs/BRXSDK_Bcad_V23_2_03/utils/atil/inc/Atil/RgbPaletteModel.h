// Copyright (C) 2017-2018 Menhirs NV. All rights reserved.
#pragma once

#include "Atil/Defs.h"
#include "Atil/RgbModel.h"
#include "Atil/RgbColor.h"


namespace Atil
{;


class Internal;


class ATIL_IMPORTEXPORT RgbPaletteModel : public RgbModel
{
public:
    RgbPaletteModel(int entries = 256);
    RgbPaletteModel(int entries, const RgbColor* palette);
    RgbPaletteModel(int usedBpp, int entries, const RgbColor* palette);
    RgbPaletteModel(int entries, DataModelAttributes::ChannelOrder co, const RgbColor* palette);
    virtual ~RgbPaletteModel() {}

    //DataModelAttributes
    virtual DataModelAttributes::ChannelOrder channelOrder() const { return RgbModel::channelOrder(); }
    virtual DataModelAttributes::DataModelType dataModelType() const { return DataModelAttributes::kPalettedRgbModel; }
    virtual DataModelAttributes::PixelType pixelType() const { return DataModelAttributes::kPalettedRgb; }

    //DataModel
    virtual DataModel* clone() const;
    virtual bool operator==(const DataModel& rh) const;
    virtual bool operator!=(const DataModel& rh) const;

    //ColorModelInterface
    virtual bool canConvertFrom(const ColorModelInterface* cm) const;
    virtual bool canConvertTo(const ColorModelInterface* cm) const;
    virtual RowProviderInterface* getModelConversionFrom(const ColorModelInterface* cm, RowProviderInterface* rp) const;
    virtual RowProviderInterface* getModelConversionTo(const ColorModelInterface* cm, RowProviderInterface* rp) const;

public:
    virtual void getEntries(int start, int entries, RgbColor* palette) const;
    virtual int numEntries() const { return m_entries; }
    virtual void setEntries(int start, int entries, const RgbColor* palette);

    Data8 alpha(int idx) const;
    bool isOpaque(int idx) const;
    bool isTransparent(int idx) const;
    Atil::UInt8 nearestColorIndex(Atil::RgbColor color) const;
    void setAlpha(int idx, Data8 alpha) const;
    void setOpaque(int idx) const;
    void setTransparent(int idx) const;

protected:
    friend Internal;
    RgbPaletteModel(DataModelAttributes::DataModelType model, DataModelAttributes::BitsPerPixel bp, int entries);

    mutable RgbColor m_palette[256];
    int m_entries;
};


} //namespace Atil
