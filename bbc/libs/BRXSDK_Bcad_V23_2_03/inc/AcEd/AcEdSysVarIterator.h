// Copyright (C) Menhirs NV. All rights reserved.
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