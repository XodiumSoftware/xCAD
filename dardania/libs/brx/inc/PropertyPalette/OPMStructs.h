// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

typedef struct tagOPMLPOLESTR
{
    ULONG cElems;
    LPOLESTR __RPC_FAR *pElems;
} OPMLPOLESTR;
typedef struct tagOPMLPOLESTR __RPC_FAR* LPOPMLPOLESTR;

typedef struct tagOPMDWORD
{
    ULONG cElems;
    DWORD __RPC_FAR *pElems;
} OPMDWORD;
typedef struct tagOPMDWORD __RPC_FAR* LPOPMDWORD;
