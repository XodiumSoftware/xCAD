// Copyright (C) 2010-2011 Menhirs NV. All rights reserved.
#pragma once

#include "AcBr/AcBrMesh2dControl.h"

#ifdef _WIN32 // hide Linux/Mac GCC specifics
  #ifdef  __attribute__
  #undef  __attribute__
  #endif
  #define __attribute__(x)   /* emptry define under Windows */
#endif

class AcBrEntity;

struct pair
{
    AcBrEntity* first;
    AcBrMesh2dControl second;

    pair(): first(NULL) {}
    pair(const AcBrEntity*& pEnt, const AcBrMesh2dControl& mctrl): first((AcBrEntity*)(pEnt)), second(mctrl) {}
};

typedef pair value_type;
typedef void iterator;

pair make_pair(const AcBrEntity*&, const AcBrMesh2dControl&);

class AcBrMesh2dFilter
{
    friend class AcBrMesh2d;

private:
    pair m_pair; 

public:
    AcBrMesh2dFilter();
    ~AcBrMesh2dFilter();

    void insert(const pair&);

private:
    AcBrMesh2dFilter(const AcBrMesh2dFilter&);
    AcBrMesh2dFilter& operator=(const AcBrMesh2dFilter&);
};
