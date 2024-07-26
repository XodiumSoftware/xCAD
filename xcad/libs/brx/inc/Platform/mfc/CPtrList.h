// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

// Windows MFC CPtrList type and functions

#ifndef _BS_CPTRLIST_INCLUDED_
#define _BS_CPTRLIST_INCLUDED_


#include "Platform/mfc/CPtrList.h"


#ifndef BRXEXPORT // for client build : import
#define BRXEXPORT
#endif

// ========== Platform independent ==========

#ifdef _WIN32
namespace Mfc
{
#endif

class BRXEXPORT CPtrList : public CObject{

struct CBlock
{
    CBlock* m_ptrNext;

    // byte align boundary...not used

    /*#ifndef _WIN64
    #if (_AFX_PACKING >= 8)
        DWORD dwReserved[1];    // align on 8 byte boundary
    #endif 
    #endif*/

    void * getData() { return this + 1; }
    
    static CBlock * PASCAL CreateBlock( CBlock *& ptrHead, UINT_PTR nMaxElem,
                                                        UINT_PTR elementSize )
    {
                ASSERT( ( elementSize > 0 ) && ( nMaxElem > 0 ) );
        if ( elementSize == 0 || nMaxElem == 0 )
                AfxThrowInvalidArgException();

        CBlock * ptr = ( CBlock * ) new BYTE[ elementSize * nMaxElem + sizeof( CBlock ) ];
        ( *ptr ).m_ptrNext = ( CBlock * )ptrHead;
        ptrHead = ptr;
        return ptr;
    }
    
    void FreeAllDataChain()
    {
        CBlock * ptr = this;
        while ( ptr )
        {
            BYTE * bytes = ( BYTE * ) ptr;
            CBlock * ptrNext = ( CBlock * )(*ptr).m_ptrNext;
            delete[] bytes;
            ptr = ptrNext;
        }   
    }
};

    struct TNode
    {
        TNode * ptrNext;
        TNode * ptrPrev;
        void * nodeData;
    };

    INT_PTR m_Count;
    TNode * m_ptrNodeFree;
    TNode * m_ptrNodeTail;
    TNode * m_ptrNodeHead;

    INT_PTR m_BlockSize;
    CBlock * m_ptrBlocks;

    TNode * NewTNode( TNode * ptrPrevNode, TNode * ptrNextNode );
    void FreeTNode( TNode * ptrNodeToFree);

public:

     CPtrList( INT_PTR nBlockSizeGrowBy = 10 );
    ~CPtrList();

    const void* GetHead() const;
    void*& GetHead();
    void*& GetTail();
    const void* GetTail() const;

    POSITION AddHead( void * elementToAdd );
    void AddHead( CPtrList * pListToAdd );
    POSITION AddTail( void * elementToAdd );
    void AddTail( CPtrList * pListToAdd );
    void RemoveAll();
    void * RemoveHead();
    void * RemoveTail();

    POSITION GetHeadPosition() const;
    void*& GetNext( POSITION & position );
    const void* GetNext( POSITION & position ) const;

    void*& GetPrev( POSITION & position );
    const void* GetPrev( POSITION & position ) const;
    POSITION GetTailPosition() const;

    void*& GetAt( POSITION position );
    const void* GetAt( POSITION position ) const;
    void RemoveAt( POSITION pos ); 
    void SetAt( POSITION position, void * elementToAdd );

    POSITION InsertAfter( POSITION pos, void * elementToInsert );
    POSITION InsertBefore( POSITION pos, void * elementToInsert );

    POSITION Find( void * valueToSearch, POSITION startPosition = NULL) const; 
    POSITION FindIndex( INT_PTR indexToFind ) const;

    INT_PTR GetCount() const;
    INT_PTR GetSize() const;

    BOOL IsEmpty() const;

};

#ifdef _WIN32
}  // namespace Mfc
#endif


#ifdef _WIN32
typedef  Mfc::CPtrList CMfcPtrList;
#else
typedef       CPtrList CMfcPtrList;
#endif


// ========== Platform specific ==========

#ifndef _WIN32 // on Linux/Mac


#endif // !_WIN32

#endif // _BS_CPTRLIST_INCLUDED_
