// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#ifdef _WIN32
#pragma warning(disable:4786)
#pragma warning(disable:4251)
#endif

#include "Misc/AcArrayMemCopyReallocator.h"
#include "Misc/AcArrayObjectCopyReallocator.h"
#ifndef _DRX_ENTRYPOINT_BUILD
  #include "Misc/MiscGlobal.h"
#endif

#define ACARRAY_GROWTH_THRESHOLD 65536

#ifdef __cplusplus

#include <type_traits>

/** _ */

template<typename T, bool> struct T_AcArrayAllocatorSelector;

template<typename T> struct T_AcArrayAllocatorSelector<T, false> {
  typedef AcArrayObjectCopyReallocator<T> Allocator; };

template<typename T> struct T_AcArrayAllocatorSelector<T, true> {
  typedef AcArrayMemCopyReallocator<T> Allocator; };

template<typename T> struct T_AcArrayAllocatorSafeDefault {
  typedef typename T_AcArrayAllocatorSelector<T, std::is_trivial<T>::value>::Allocator Allocator; };

template <typename T, typename R = typename T_AcArrayAllocatorSafeDefault<T>::Allocator> class AcArray
{
protected:
    T* mpArray;
    int mGrowLen;
    int mLogicalLen;
    int mPhysicalLen;

    bool isValid(int) const;

private:
    int getEagerGrowLength() const;

public:
    AcArray(int = 0,int = 8);
    AcArray(const AcArray<T,R>&);
    ~AcArray();

    AcArray<T,R>& setAt(int,const T&);
    AcArray<T,R>& setAll(const T&);
    AcArray<T,R>& insertAt(int,const T&);
    int append(const T&);
    AcArray<T,R>& append(const AcArray<T,R>&);

    T& at(int);
    const T& at(int) const;

    T& first();
    const T& first() const;
    T& last();
    const T& last() const;

    T* begin();
    T* end();
    const T* begin() const;
    const T* end() const;

    int length() const;
    bool isEmpty() const;

    AcArray<T,R>& setLogicalLength(int);
    int logicalLength() const;
    AcArray<T,R>& setPhysicalLength(int);
    int physicalLength() const;
    AcArray<T,R>& setGrowLength(int);
    int growLength() const;

    bool contains(const T&,int = 0) const;
    int find(const T&) const;
    bool find(const T&,int&,int = 0) const;
    int findFrom(const T&,int) const;

    AcArray<T,R>& removeAt(int);
    bool remove(const T&,int = 0);
    AcArray<T,R>& removeFirst();
    AcArray<T,R>& removeLast();
    AcArray<T,R>& removeAll();
    AcArray<T,R>& removeSubArray(int,int);

    AcArray<T,R>& swap(int,int);
    AcArray<T,R>& reverse();

    T* asArrayPtr();
    const T* asArrayPtr() const;

    AcArray<T,R>& operator=(const AcArray<T,R>&);
    bool operator==(const AcArray<T,R>&) const;

    T& operator[](int);
    const T& operator[](int) const;
};

template<class T,class R>
bool AcArray<T,R>::isValid(int i) const
{
    return (i >= 0) && (i < mLogicalLen);
}

template<class T,class R>
int AcArray<T,R>::getEagerGrowLength() const
{
    int eagerGrowLength = 0;

    if ( (mLogicalLen*sizeof(T)) < ACARRAY_GROWTH_THRESHOLD )
            eagerGrowLength = mLogicalLen;
    else
        eagerGrowLength = ACARRAY_GROWTH_THRESHOLD/sizeof(T);

    if (mGrowLen > eagerGrowLength)
        eagerGrowLength = mGrowLen;

    if (eagerGrowLength == 0)
        eagerGrowLength = (mGrowLen > 0) ? mGrowLen : 8;

    return eagerGrowLength;
}

template<class T,class R>
AcArray<T,R>::AcArray(int phl, int gl)
{
    mpArray = NULL;
    mLogicalLen = 0;
    mPhysicalLen = (phl > 0) ? phl : 0;  // will be 0 for AcArray(-1,0) !
    mGrowLen = (gl > 0) ? gl : 8;        // could be <= 0 for AcArray(0,-1) !

    if (mPhysicalLen <= 0)
        return;

    mpArray = new T[mPhysicalLen];

    if (NULL == mpArray)
        mPhysicalLen = 0;
}

template<class T,class R>
AcArray<T,R>::AcArray(const AcArray<T,R>& other)
{
    mpArray = NULL;
    mLogicalLen = other.mLogicalLen;
    mPhysicalLen = other.mPhysicalLen;
    mGrowLen = other.mGrowLen;

    if (mPhysicalLen > 0)
    {
        mpArray = new T[mPhysicalLen];

        if (NULL == mpArray)
        {
            mLogicalLen = 0;
            mPhysicalLen = 0;
        }
    }

    R::reallocateArray(mpArray,other.mpArray,mLogicalLen);
}

template<class T,class R>
AcArray<T,R>::~AcArray()
{
    if (NULL == mpArray)
        return;

    delete[] mpArray;
}

template<class T,class R>
AcArray<T,R>& AcArray<T,R>::setAt(int i,const T& obj)
{
    mpArray[i] = obj;
    return *this;
}

template<class T,class R>
AcArray<T,R>& AcArray<T,R>::setAll(const T& obj)
{
    for (int i = 0; i < mLogicalLen; ++i)
    {
        mpArray[i] = obj;
    }
    return *this;
}

template<class T,class R>
AcArray<T,R>& AcArray<T,R>::insertAt(int i,const T& obj)
{
    T myObj;
    myObj = obj;
    if (mLogicalLen >= mPhysicalLen)
    {
        setPhysicalLength(mLogicalLen + getEagerGrowLength());
    }

    if (i < mLogicalLen)
    {
        for (int j = mLogicalLen; j > i; --j)
        {
            mpArray[j] = mpArray[j-1];
        }
    }

    mpArray[i] = myObj;
    ++mLogicalLen;
    return *this;
}

template<class T,class R>
int AcArray<T,R>::append(const T& obj)
{
    insertAt(mLogicalLen,obj);
    return mLogicalLen-1;
}

template<class T,class R>
AcArray<T,R>& AcArray<T,R>::append(const AcArray<T,R>& other)
{
    int otherLength = other.logicalLength();
    if (0 == otherLength)
        return *this;

    int newLength = mLogicalLen+otherLength;
    if (newLength > mPhysicalLen)
        setPhysicalLength(mLogicalLen + ((mGrowLen > otherLength) ? mGrowLen : otherLength));

    R::reallocateArray(mpArray+mLogicalLen,other.mpArray,otherLength);

    mLogicalLen = newLength;
    return *this;
}

template<class T,class R>
T& AcArray<T,R>::at(int i)
{
    return mpArray[i];
}

template<class T,class R>
const T& AcArray<T,R>::at(int i) const
{
    return mpArray[i];
}

template<class T,class R>
T& AcArray<T,R>::first()
{
    return mpArray[0];
}

template<class T,class R>
const T& AcArray<T,R>::first() const
{
    return mpArray[0];
}

template<class T,class R>
T& AcArray<T,R>::last()
{
    return mpArray[mLogicalLen-1];
}

template<class T,class R>
const T& AcArray<T,R>::last() const
{
    return mpArray[mLogicalLen-1];
}

template<class T,class R>
T* AcArray<T,R>::begin()
{
    return &mpArray[0];
}

template<class T,class R>
T* AcArray<T,R>::end()
{
    return &mpArray[mLogicalLen];
}

template<class T,class R>
const T* AcArray<T,R>::begin() const
{
    return &mpArray[0];
}

template<class T,class R>
const T* AcArray<T,R>::end() const
{
    return &mpArray[mLogicalLen];
}

template<class T,class R>
int AcArray<T,R>::length() const
{
    return mLogicalLen;
}

template<class T,class R>
bool AcArray<T,R>::isEmpty() const
{
    return (0 == mLogicalLen);
}

template<class T,class R>
AcArray<T,R>& AcArray<T,R>::setLogicalLength(int newLogicalLength)
{
    if (newLogicalLength > mPhysicalLen)
    {
        int newPhysicalLength = mPhysicalLen + getEagerGrowLength();
        if (newLogicalLength > newPhysicalLength)
            newPhysicalLength = newLogicalLength;
        setPhysicalLength(newPhysicalLength);
    }
    mLogicalLen = (newLogicalLength >= 0) ? newLogicalLength : 0;
    return *this;
}

template<class T,class R>
int AcArray<T,R>::logicalLength() const
{
    return mLogicalLen;
}

template<class T,class R>
AcArray<T,R>& AcArray<T,R>::setPhysicalLength(int newPhysicalLength)
{
    if (newPhysicalLength == mPhysicalLen)
        return *this;

    if (0 == newPhysicalLength)
    {
        if (NULL != mpArray)
            delete[] mpArray;
        mpArray = NULL;
        mPhysicalLen = 0;
        mLogicalLen = 0;
        return *this;
    }

    T* pNewArray = new T[newPhysicalLength];
    if (NULL == pNewArray)
    {
        if (NULL != mpArray)
            delete[] mpArray;
        mpArray = NULL;
        mPhysicalLen = 0;
        mLogicalLen = 0;
        return *this;
    }

    int reallocateLength = mLogicalLen;
    if (newPhysicalLength < mLogicalLen)
        reallocateLength = newPhysicalLength;
    R::reallocateArray(pNewArray,mpArray,reallocateLength);
    mPhysicalLen = newPhysicalLength;

    if (NULL != mpArray)
        delete[] mpArray;
    mpArray = pNewArray;

    if (mPhysicalLen < mLogicalLen)
        mLogicalLen = mPhysicalLen;

    return *this;
}

template<class T,class R>
int AcArray<T,R>::physicalLength() const
{
    return mPhysicalLen;
}

template<class T,class R>
AcArray<T,R>& AcArray<T,R>::setGrowLength(int newGrowLength)
{
    mGrowLen = newGrowLength;
    return *this;
}

template<class T,class R>
int AcArray<T,R>::growLength() const
{
    return mGrowLen;
}

template<class T,class R>
bool AcArray<T,R>::contains(const T& obj, int from) const
{
    return (findFrom(obj,from) >= 0);
}

template<class T,class R>
int AcArray<T,R>::find(const T& obj) const
{
    return findFrom(obj,0);
}

template<class T,class R>
bool AcArray<T,R>::find(const T& obj,int& i,int from) const
{
    int j = findFrom(obj,from);
    if (j < 0)
        return false;
    i = j;
    return true;
}

template<class T,class R>
int AcArray<T,R>::findFrom(const T& obj,int from) const
{
    for (int i=from; i < mLogicalLen; ++i)
    {
        if (obj == mpArray[i])
            return i;
    }
    return -1;
}

template<class T,class R>
AcArray<T,R>& AcArray<T,R>::removeAt(int i)
{
    if (i < (mLogicalLen-1) )
    {
        for (int j = i; j < (mLogicalLen-1); ++j)
        {
            mpArray[j] = mpArray[j+1];
        }
    }

    --mLogicalLen;
    return *this;
}

template<class T,class R>
bool AcArray<T,R>::remove(const T& obj,int from)
{
    int i = findFrom(obj,from);
    if (i < 0)
        return false;
    removeAt(i);
    return true;
}

template<class T,class R>
AcArray<T,R>& AcArray<T,R>::removeFirst()
{
    return removeAt(0);
}

template<class T,class R>
AcArray<T,R>& AcArray<T,R>::removeLast()
{
    if (!isEmpty())
        --mLogicalLen;
    return *this;
}

template<class T,class R>
AcArray<T,R>& AcArray<T,R>::removeAll()
{
    mLogicalLen = 0;
    return *this;
}

template<class T,class R>
AcArray<T,R>& AcArray<T,R>::removeSubArray(int from, int to)
{
    if (to >= (mLogicalLen-1))
    {
        mLogicalLen = from;
        return *this;
    }

    int indexLeft = from;
    for (int indexRight = to + 1; indexRight < mLogicalLen; ++indexRight)
    {
        mpArray[indexLeft] = mpArray[indexRight];
        ++indexLeft;
    }

    int numRemoved = to - from + 1;
    mLogicalLen = mLogicalLen - numRemoved;
    return *this;
}

template<class T,class R>
AcArray<T,R>& AcArray<T,R>::swap(int i,int j)
{
    if (i == j)
        return *this;

    T buffer = mpArray[i];
    mpArray[i] = mpArray[j];
    mpArray[j] = buffer;
    return *this;
}

template<class T,class R>
AcArray<T,R>& AcArray<T,R>::reverse()
{
    int left = 0;
    int right = mLogicalLen-1;
    while (left < right)
    {
        swap(left,right);
        ++left;
        --right;
    }
    return *this;
}

template<class T,class R>
T* AcArray<T,R>::asArrayPtr()
{
    return mpArray;
}

template<class T,class R>
const T* AcArray<T,R>::asArrayPtr() const
{
    return mpArray;
}

template<class T,class R>
AcArray<T,R>& AcArray<T,R>::operator=(const AcArray<T,R>& other)
{
    if (&other == this)
        return *this;

    if (other.mLogicalLen > mPhysicalLen)
    {
        if (NULL != mpArray)
        {
            delete[] mpArray;
            mpArray = NULL;
        }

        mpArray = new T[other.mLogicalLen];
        mPhysicalLen = other.mLogicalLen;

        if (NULL == mpArray)
        {
            mLogicalLen = 0;
            mPhysicalLen = 0;
            return *this;
        }
    }

    R::reallocateArray(mpArray,other.mpArray,other.mLogicalLen);

    mLogicalLen = other.mLogicalLen;
    return *this;
}

template<class T,class R>
bool AcArray<T,R>::operator==(const AcArray<T,R>& other) const
{
    if (other.mLogicalLen != mLogicalLen)
        return false;

    for (int i = 0; i < mLogicalLen; ++i)
    {
        if (other.mpArray[i] != mpArray[i])
            return false;
    }

    return true;
}

template<class T,class R>
T& AcArray<T,R>::operator[](int i)
{
    return mpArray[i];
}

template<class T,class R>
const T& AcArray<T,R>::operator[](int i) const
{
    return mpArray[i];
}

#endif //__cplusplus
