// Copyright (C) 2017-2018 Menhirs NV. All rights reserved.
#pragma once

#include "Atil/Defs.h"
#include "Atil/RgbGrayModel.h"
#include "Atil/RgbColor.h"


namespace Atil
{;


class Internal;


class ATIL_IMPORTEXPORT BitonalModel : public RgbGrayModel
{
public:
    BitonalModel();
    BitonalModel(int entries, const RgbColor* palette);
    virtual ~BitonalModel() {}

    //DataModelAttributes
    virtual DataModelAttributes::DataModelType dataModelType() const { return DataModelAttributes::kBitonalModel; }
    virtual DataModelAttributes::PixelType pixelType() const { return DataModelAttributes::kBitonal; }

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
    virtual void getEntries(int entries, RgbColor* palette) const;
    virtual int numEntries() const { return m_entries; }

protected:
    friend Internal;
    mutable RgbColor m_palette[2];
    int m_entries;
};


} //namespace Atil
