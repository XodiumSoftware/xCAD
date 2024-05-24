// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "BmGlobal.h"

namespace AModeler
{

class ImplDarray;

class BM_IMPORTEXPORT Darray
{
private:
    std::shared_ptr<ImplDarray> m_pBrxImp;

public:
    Darray();
    Darray(int);
    Darray(void*);
    Darray(const Darray&);
    ~Darray();

    int add(void*);
    int contains(const void*) const;
    int del(void*);
    int find(const void*,int = 0) const;
    int length() const;
    int length();
    int merge(const Darray&);
    int merge(void*);
    void add(const Darray&);
    void add(int,void*);
    void del(int);
    void fixAfterMemcopy(void*);
    void init();
    void init(int);
    void intersectWith(const Darray&);
    void resize(int);
    void swap(int,int);

    Darray& operator=(const Darray&);
    void* operator[](int) const;
    void*& operator[](int);
};

}
