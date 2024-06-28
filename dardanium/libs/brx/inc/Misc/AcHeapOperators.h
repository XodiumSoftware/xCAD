// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include <stddef.h> //NULL

#undef new
#undef delete

/** _ */
class AcHeapOperators
{
public:
    static void* operator new(size_t);
    static void operator delete(void*);
    static void* operator new(size_t, void* p) { return p; }
    static void operator delete(void*, void*) {}
    static void* operator new[](size_t);
    static void operator delete[](void*);

    static void* operator new(size_t,const char*,int);
    static void operator delete(void*,const char*,int);
    static void* operator new[](size_t,const char*,int);
    static void operator delete[](void*,const char*,int);
};
