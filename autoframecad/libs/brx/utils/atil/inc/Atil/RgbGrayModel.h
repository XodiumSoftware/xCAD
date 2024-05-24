// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "Atil/Defs.h"
#include "Atil/RgbModel.h"


namespace Atil
{;


class Internal;


class ATIL_IMPORTEXPORT RgbGrayModel : public RgbModel
{
public:
    RgbGrayModel();
    RgbGrayModel(DataModelAttributes::DataModelType model, DataModelAttributes::BitsPerPixel bp);
    virtual ~RgbGrayModel() {}

    //DataModelAttributes
    virtual DataModelAttributes::DataModelType dataModelType() const { return DataModelAttributes::kGrayModel; }
    virtual DataModelAttributes::PixelType pixelType() const { return DataModelAttributes::kGray; }

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
    Data8 alpha(Data8 idx) const;
    bool isOpaque(Data8 idx) const;
    bool isTransparent(Data8 idx) const;
    void setAlpha(Data8 idx, Data8 alpha) const;
    void setOpaque(Data8 idx) const;
    void setTransparent(Data8 idx) const;

protected:
    friend Internal;
    mutable Data8 m_alpha[256];
};


} //namespace Atil
