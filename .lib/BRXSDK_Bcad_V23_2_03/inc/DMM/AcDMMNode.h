// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

class BrxDMMNodeImp;

/** _ */
class BRX_IMPORTEXPORT AcDMMNode
{
private:
    //BRX START
    BrxDMMNodeImp* m_pBrxImp;
    //BRX END

public:
    AcDMMNode();
    AcDMMNode(int,wchar_t*);
    AcDMMNode(const AcDMMNode&);
    ~AcDMMNode();

    const wchar_t* nodeName();
    int nodeNumber();
    void SetNodeName(const wchar_t*);
    void SetNodeNumber(int);

    AcDMMNode& operator=(const AcDMMNode&);
};