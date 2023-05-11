// Copyright (C) 2010-2014 Menhirs NV. All rights reserved.

// Windows MFC CArray type and functions

#pragma once

#ifndef _BS_MFC_CARRAY_INCLUDED_
#define _BS_MFC_CARRAY_INCLUDED_

#include "Platform/mfc/CObject.h"
#include "Platform/win/win_defs.h"

#ifndef BRXEXPORT // for client build : import
#define BRXEXPORT
#endif

// ========== Platform independent ==========
#ifdef __SYS_64_BIT__
  #define BRX_SIZE_MAX  0xFFFFFFFFFFFFFFFF  /* maximum unsigned int 64 bit */
#else
  #define BRX_SIZE_MAX  0xFFFFFFFF          /* maximum unsigned int 32 bit */
#endif

template <class TYPE, class ARG_TYPE = const TYPE>
class BRXEXPORT CMfcArray : public CObject
{
public:
    CMfcArray() {
        m_pArrayData = NULL;
        m_arraySize = 0;
        m_arrayMaxSize = 0;
        m_sizeGrowBy = 0; }

    ~CMfcArray() {
        delete[] (BYTE*)m_pArrayData; }

    INT_PTR GetCount() const { return m_arraySize; }
    INT_PTR GetSize() const { return m_arraySize; }
    INT_PTR GetUpperBound() const { return m_arraySize - 1; }
    BOOL IsEmpty() const { return m_arraySize == 0; }
    void SetSize( INT_PTR size, INT_PTR sizeGrowBy = -1 );

    void FreeExtra() {
        if (m_arraySize != m_arrayMaxSize)
        {
            // shrink to desired size
#ifdef BRX_SIZE_MAX
            ASSERT(m_arraySize <= (INT_PTR)(BRX_SIZE_MAX/sizeof(TYPE))); // no overflow
#endif

            if (m_arraySize != 0)
            {
                m_pArrayData = (TYPE*)realloc(m_pArrayData,m_arraySize * sizeof(TYPE));
            }
            m_arrayMaxSize = m_arraySize;
        }
    }
    void RemoveAll() { SetSize(0, -1); }
    AFX_INLINE void RelocateElements( TYPE * pNewBufferData,
                                      const TYPE * pOldBufferData, INT_PTR count ) { }

    TYPE & ElementAt( INT_PTR index );
    const TYPE & ElementAt( INT_PTR index ) const;
    TYPE & GetAt( INT_PTR index )
    {
        if ((index >= 0) && (index < m_arraySize))
            return m_pArrayData[index];
        AfxThrowInvalidArgException();
#ifndef _WIN32
        return m_pArrayData[0]; // just to make GCC happy
#endif
    }
    const TYPE & GetAt( INT_PTR index ) const;
    const TYPE * GetData() const;
    TYPE * GetData();
    void SetAt( INT_PTR index, ARG_TYPE newElementToSet ) {
        if(m_arraySize > index)
            if(index >= 0)
                m_pArrayData[index] = newElementToSet; }

    INT_PTR Add( ARG_TYPE newElementToAdd ) {
        INT_PTR index = m_arraySize;
        SetAtGrow(index, newElementToAdd);
        return index;
    }
    INT_PTR Append( const CMfcArray & srcArray );
    void Copy( const CMfcArray & srcArray );
    void SetAtGrow( INT_PTR index, ARG_TYPE newElementToAdd ) {
        if(index < 0)
            AfxThrowInvalidArgException();

        if (index >= m_arraySize)
            SetSize(index+1);
        SetAt(index,newElementToAdd);
    }

    void InsertAt( INT_PTR index, ARG_TYPE newElementToInsert, INT_PTR insCount = 1 );
    void InsertAt( INT_PTR startIndex, CMfcArray * pSrcArray );
    void RemoveAt( INT_PTR index, INT_PTR rmCount = 1 );

    TYPE & operator[]( INT_PTR index );
    const TYPE & operator[]( INT_PTR index ) const;

protected:
    TYPE * m_pArrayData;     // actual data
    INT_PTR m_arraySize;     // current number of elements in the array
    INT_PTR m_arrayMaxSize;  // maxim number of elements in the array
    INT_PTR m_sizeGrowBy;    // grow amount in the array
};

template <class TYPE, class ARG_TYPE>
void CMfcArray<TYPE, ARG_TYPE>::SetSize( INT_PTR size, INT_PTR sizeGrowBy )
{
    ASSERT(this);
    ASSERT(size >= 0);

    if (sizeGrowBy >= 0)
        m_sizeGrowBy = sizeGrowBy;

    if(size < 0 )
        AfxThrowInvalidArgException();

    if (size == 0)
    {
        m_arraySize = 0;
        m_arrayMaxSize = 0;
        delete[] (BYTE*)m_pArrayData;
        m_pArrayData = NULL;
    }
    else if (m_pArrayData == NULL)
    {
        // create m_pArrayData with size size
#ifdef SIZE_T_MAX
        ASSERT(size <= SIZE_T_MAX/sizeof(TYPE));
#endif
        m_pArrayData = (TYPE*) new BYTE[size * sizeof(TYPE)];

        memset(m_pArrayData, 0, size * sizeof(TYPE));
        m_arraySize = size;
        m_arrayMaxSize = size;
    }
    else if (size <= m_arrayMaxSize)
    {
        if (size > m_arraySize)
            memset(&m_pArrayData[m_arraySize], 0, (size-m_arraySize) * sizeof(TYPE));
        m_arraySize = size;
    }
    else
    {
        INT_PTR sizeGrowBySize = m_sizeGrowBy;
        if (sizeGrowBySize == 0)
            sizeGrowBySize = MIN(1024, MAX(4, m_arraySize / 8));

        INT_PTR nNewMax;
        if (size < m_arrayMaxSize + sizeGrowBySize)
            nNewMax = m_arrayMaxSize + sizeGrowBySize;
        else
            nNewMax = size;

        ASSERT(nNewMax >= m_arrayMaxSize);  // no wrap around

        if(nNewMax  < m_arrayMaxSize)
            AfxThrowInvalidArgException();

#ifdef SIZE_T_MAX
        ASSERT(nNewMax <= SIZE_T_MAX/sizeof(TYPE)); // no overflow
#endif
        m_pArrayData = (TYPE*)realloc(m_pArrayData,nNewMax * sizeof(TYPE));

        ASSERT(size > m_arraySize);
        memset(&m_pArrayData[m_arraySize], 0, (m_arrayMaxSize-m_arraySize) * sizeof(TYPE));
        m_arraySize = size;
        m_arrayMaxSize = nNewMax;
    }
}

template<class TYPE, class ARG_TYPE>
INT_PTR CMfcArray<TYPE, ARG_TYPE>::Append( const CMfcArray & srcArray )
{
    ASSERT(this != &srcArray);   // cannot append to itself

    if(this == &srcArray)
        AfxThrowInvalidArgException();

    INT_PTR nOldSize = m_arraySize;
    SetSize(m_arraySize + srcArray.m_arraySize);
    memcpy(m_pArrayData + nOldSize, srcArray.m_pArrayData
        ,srcArray.m_arraySize * sizeof(TYPE));
    return nOldSize;
}
template<class TYPE, class ARG_TYPE>
void CMfcArray<TYPE, ARG_TYPE>::Copy( const CMfcArray & srcArray )
{
    ASSERT(this);
    ASSERT(this != &srcArray);
    if(this != &srcArray)
    {
        SetSize(srcArray.m_arraySize);
        memcpy(m_pArrayData, srcArray.m_pArrayData ,
            srcArray.m_arraySize * sizeof(TYPE));
    }
}

template<class TYPE, class ARG_TYPE>
AFX_INLINE const TYPE* CMfcArray<TYPE, ARG_TYPE>::GetData() const
{
    return (const TYPE*)m_pArrayData;
}

template<class TYPE, class ARG_TYPE>
AFX_INLINE TYPE* CMfcArray<TYPE, ARG_TYPE>::GetData()
{ return (TYPE*)m_pArrayData; }

template <class TYPE, class ARG_TYPE>
void CMfcArray<TYPE, ARG_TYPE>::RemoveAt( INT_PTR index, INT_PTR rmCount /* = 1 */ )
{
    ASSERT(this);
    ASSERT(index >= 0);
    ASSERT(rmCount >= 0);
    INT_PTR last = index + rmCount;
    ASSERT(last <= m_arraySize && last >= index && last >= rmCount);

    if(index < 0 || rmCount < 0 || (last > m_arraySize) ||
        (last < index) || (last < rmCount))
        AfxThrowInvalidArgException();

    // just remove a range
    INT_PTR nMoveCount = m_arraySize - (last);
    m_arraySize = m_arraySize - rmCount;
    if (nMoveCount)
    {
        INT_PTR i = index;
        for( ; i < m_arraySize; i++)
            m_pArrayData[i] = m_pArrayData[i + rmCount];
        memset(&m_pArrayData[m_arraySize], 0, (m_arrayMaxSize-m_arraySize) * sizeof(DWORD));
    }
}

template <class TYPE, class ARG_TYPE>
void CMfcArray<TYPE, ARG_TYPE>::InsertAt( INT_PTR index, ARG_TYPE newElementToInsert,
                                                              INT_PTR insCount /* = 1 */ )
{
    ASSERT(this != NULL);
    ASSERT(index >= 0);
    ASSERT(insCount > 0);

    if(index < 0 || insCount <= 0)
        return;

    if (index >= m_arraySize)
    {
        SetSize(index + insCount);
    }
    else
    {
        SetSize(m_arraySize + insCount);
        m_pArrayData = (TYPE*)realloc(m_pArrayData,m_arrayMaxSize * sizeof(TYPE));
    }
    ASSERT(index + insCount <= m_arraySize);

    //copy rest of elements
    INT_PTR i = m_arraySize;
    for( ; i > index ; i--)
        m_pArrayData[i] = m_pArrayData[i - insCount];
    for( i = 0 ; i < insCount ; i++ )
        m_pArrayData[index + i] = newElementToInsert;
}

// ========== Platform specific ==========
#ifndef _WIN32 // on Linux/Mac

template <class TYPE, class ARG_TYPE = const TYPE>
class BRXEXPORT CArray : public CMfcArray<TYPE, ARG_TYPE>
{
public:
    CArray() : CMfcArray<TYPE, ARG_TYPE>() {};
};

#endif // !_WIN32

#endif // _BS_MFC_CARRAY_INCLUDED_
