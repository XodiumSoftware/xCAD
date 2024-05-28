// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

// COM maps definitions

#ifndef _BS_COM_MAPS_INCLUDED_
#define _BS_COM_MAPS_INCLUDED_

// ========== Platform specific ==========

#ifndef _WIN32 // on Linux/Mac


  #define   BEGIN_COM_MAP(x) 
    #define COM_INTERFACE_ENTRY(x)
    #define COM_INTERFACE_ENTRY_IID(iid, x)
    #define COM_INTERFACE_ENTRY2(x, x2)
    #define COM_INTERFACE_ENTRY2_IID(iid, x, x2)
    #define COM_INTERFACE_ENTRY_FUNC(iid, dw, func)
    #define COM_INTERFACE_ENTRY_FUNC_BLIND(dw, func)
    #define COM_INTERFACE_ENTRY_BREAK(x)
    #define COM_INTERFACE_ENTRY_NOINTERFACE(x)
  #define   END_COM_MAP()



#endif // !_WIN32 - Linux/Mac


#endif // _BS_COM_MAPS_INCLUDED_
