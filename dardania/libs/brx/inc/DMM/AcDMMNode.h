// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
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