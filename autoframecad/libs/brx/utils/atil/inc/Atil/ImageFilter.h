// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "Atil/Defs.h"
#include "Atil/RowProviderInterface.h"


namespace Atil
{;


struct ImagePixel;
class RowInterfaceProviderInputChain;


class ATIL_IMPORTEXPORT ImageFilter : public RowProviderInterface
{
public:
    //RowProviderInterface
    virtual int bytesPerRow() const;
    virtual const DataModel& dataModel() const { return *m_model; }
    virtual void getNextRow(DataBuffer&) = 0;
    virtual bool getNextSpan(int&, int&);
    virtual bool hasSpanInfo() const;
    virtual bool isValid() const;
    virtual int numSpans();
    virtual void restartSpans();
    virtual int rowsRemaining() = 0;
    virtual Size size() const { return m_size; }

public:
    virtual void convertColor(ImagePixel&) const;

protected:
    ImageFilter();
    virtual ~ImageFilter();

    bool connectInput(RowProviderInterface*&);
    bool connectInput(RowProviderInterface*&, const DataModel&);
    void init(const Size&);
    void init(const Size&, const DataModel&);
    RowProviderInterface* input(int) const;
    int numInputs() const { return m_inputs; }

private:
    RowInterfaceProviderInputChain* m_rpis;
    int m_inputs;
    DataModel* m_model;
    Size m_size;
};


} //namespace Atil
