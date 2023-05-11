// Copyright (C) Menhirs NV. All rights reserved.
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
