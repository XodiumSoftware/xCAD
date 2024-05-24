// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

// Windows MFC CObList type and functions

#ifndef _BS_COBLIST_INCLUDED_
#define _BS_COBLIST_INCLUDED_


#include "Platform/mfc/CObject.h"


#ifndef BRXEXPORT // for client build : import
#define BRXEXPORT
#endif

// ========== Platform independent ==========

#ifdef _WIN32
namespace Mfc
{
#endif

class BRXEXPORT CObList : public CObject{

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
        CObject * nodeData;
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

     CObList( INT_PTR nBlockSizeGrowBy = 10 );
    ~CObList();

    const CObject* GetHead() const;
    CObject*& GetHead();
    const CObject* GetTail() const;
    CObject*& GetTail();

    POSITION AddHead( CObject * elementToAdd );
    void AddHead( CObList * pListToAdd );
    POSITION AddTail( CObject * elementToAdd );
    void AddTail( CObList * pListToAdd );
    void RemoveAll();
    CObject * RemoveHead();
    CObject * RemoveTail();

    POSITION GetHeadPosition() const;
    CObject*& GetNext( POSITION & position );
    const CObject* GetNext( POSITION & position ) const;

    CObject*& GetPrev( POSITION & position );
    const CObject* GetPrev( POSITION & position ) const;
    POSITION GetTailPosition() const;

    CObject*& GetAt( POSITION position );
    const CObject* GetAt( POSITION position ) const;
    void RemoveAt( POSITION pos ); 
    void SetAt( POSITION position, CObject * elementToAdd );

    POSITION InsertAfter( POSITION pos, CObject * elementToInsert );
    POSITION InsertBefore( POSITION pos, CObject * elementToInsert );

    POSITION Find( CObject * valueToSearch, POSITION startPosition = NULL) const; 
    POSITION FindIndex( INT_PTR indexToFind ) const;

    INT_PTR GetCount() const;
    INT_PTR GetSize() const;

    BOOL IsEmpty() const;

};

#ifdef _WIN32
}  // namespace Mfc
#endif


#ifdef _WIN32
typedef  Mfc::CObList CMfcObList;
#else
typedef       CObList CMfcObList;
#endif


// ========== Platform specific ==========

#ifndef _WIN32 // on Linux/Mac


#endif // !_WIN32

#endif // _BS_COBLIST_INCLUDED_
