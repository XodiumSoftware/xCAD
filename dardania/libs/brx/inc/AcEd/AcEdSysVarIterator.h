// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

class AcEdSysVarIteratorImp;
class AcRxVariable;

class BRX_IMPORTEXPORT AcEdSysVarIterator
{
public:
    AcEdSysVarIterator();
    ~AcEdSysVarIterator();
    bool done() const;
    const AcRxVariable* getSysVar();
    void reset();
    void step();

private:
    AcEdSysVarIteratorImp* m_pImp = nullptr;
};