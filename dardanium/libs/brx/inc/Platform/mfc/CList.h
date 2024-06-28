// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

// Windows MFC CList type and functions

#ifndef _BS_CLIST_INCLUDED_
#define _BS_CLIST_INCLUDED_


#include "Platform/mfc/CObject.h"


#ifndef BRXEXPORT // for client build : import
#define BRXEXPORT
#endif


// ========== Platform independent ==========

#ifdef _WIN32
namespace Mfc
{
#endif

template< class TYPE, class ARG_TYPE = const TYPE& > 
class BRXEXPORT CList : public CObject{

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
        TYPE nodeData;
    };
    
    INT_PTR m_Count;
    TNode * m_ptrNodeFree;
    TNode * m_ptrNodeTail;
    TNode * m_ptrNodeHead;

    INT_PTR m_BlockSize;
    CBlock * m_ptrBlocks;


    TNode * NewTNode( TNode * pPrevNode, TNode * pNextNode );
    void FreeTNode( TNode * pNodeToFree);

public:

    CList( INT_PTR nBlockSizeGrowBy = 10 );
    ~CList();

    const TYPE & GetHead() const;
    TYPE & GetHead();
    TYPE& GetTail();
    const TYPE& GetTail() const;

    POSITION AddHead( ARG_TYPE elementToAdd );
    void AddHead( CList * pListToAdd );
    POSITION AddTail( ARG_TYPE elementToAdd );
    void AddTail( CList * pListToAdd );
    void RemoveAll();
    TYPE RemoveHead();
    TYPE RemoveTail();

    POSITION GetHeadPosition() const;
    TYPE & GetNext( POSITION & position );
    const TYPE & GetNext( POSITION & position ) const;

    TYPE & GetPrev( POSITION & position );
    const TYPE & GetPrev( POSITION & position ) const;
    POSITION GetTailPosition() const;

    TYPE & GetAt( POSITION position );
    const TYPE & GetAt( POSITION position ) const;
    void RemoveAt( POSITION position ); 
    void SetAt( POSITION position, ARG_TYPE elementToAdd );

    POSITION InsertAfter( POSITION pos, ARG_TYPE elementToInsert );
    POSITION InsertBefore( POSITION pos, ARG_TYPE elementToInsert );

    POSITION Find( ARG_TYPE valueToSearch, POSITION startPosition = NULL) const; 
    POSITION FindIndex( INT_PTR indexToFind ) const;

    INT_PTR GetCount() const;
    INT_PTR GetSize() const;

    BOOL IsEmpty() const;

};


template< class TYPE, class ARG_TYPE > 
CList<TYPE, ARG_TYPE>::CList( INT_PTR nBlockSizeGrowBy )
{
            ASSERT( 0 < nBlockSizeGrowBy );

    m_Count = 0;
    m_BlockSize = nBlockSizeGrowBy;
    m_ptrNodeHead = m_ptrNodeTail = m_ptrNodeFree = NULL;
    m_ptrBlocks = NULL;
}

template< class TYPE, class ARG_TYPE >
CList<TYPE, ARG_TYPE>::~CList()
{
    RemoveAll();
            ASSERT( 0 == m_Count );
}

template< class TYPE, class ARG_TYPE >
 const TYPE & CList<TYPE, ARG_TYPE>::GetHead() const
{
            ASSERT( NULL != m_ptrNodeHead );
    return ( *m_ptrNodeHead ).nodeData;  
}

template< class TYPE, class ARG_TYPE >
TYPE & CList<TYPE, ARG_TYPE>::GetHead()
{
            ASSERT( NULL != m_ptrNodeHead );
    return ( *m_ptrNodeHead ).nodeData; 
}

template< class TYPE, class ARG_TYPE >
TYPE & CList<TYPE, ARG_TYPE>::GetTail()
{
            ASSERT( NULL != m_ptrNodeTail );
    return ( *m_ptrNodeTail ).nodeData; 
}

template< class TYPE, class ARG_TYPE >
const TYPE & CList<TYPE, ARG_TYPE>::GetTail() const
{
            ASSERT( NULL != m_ptrNodeTail );
    return ( *m_ptrNodeTail ).nodeData; 
}

template< class TYPE, class ARG_TYPE >
POSITION CList<TYPE, ARG_TYPE>::AddHead( ARG_TYPE elementToAdd )
{
            ASSERT( this );

    TNode * ptrNewNodeToAdd = NewTNode( NULL, m_ptrNodeHead );
    ( *ptrNewNodeToAdd ).nodeData = elementToAdd;
    if ( m_ptrNodeHead )
        ( *m_ptrNodeHead ).ptrPrev = ptrNewNodeToAdd;
    else
        m_ptrNodeTail = ptrNewNodeToAdd;

    m_ptrNodeHead = ptrNewNodeToAdd;
    return ( POSITION ) ptrNewNodeToAdd;
}

template< class TYPE, class ARG_TYPE >
void CList<TYPE, ARG_TYPE>::AddHead( CList * pListToAdd )
{
            ASSERT( this );
            ASSERT( pListToAdd );

    POSITION position = ( *pListToAdd ).GetTailPosition();
    while ( position )
        AddHead( ( *pListToAdd ).GetPrev( position ) );
}

template< class TYPE, class ARG_TYPE >
POSITION CList<TYPE, ARG_TYPE>::AddTail( ARG_TYPE elementToAdd )
{
            ASSERT( this );

    TNode * ptrNewNodeToAdd = NewTNode( m_ptrNodeTail, NULL );
    ( *ptrNewNodeToAdd ).nodeData = elementToAdd;
    if ( m_ptrNodeTail )
        ( *m_ptrNodeTail ).ptrNext = ptrNewNodeToAdd;
    else
        m_ptrNodeHead = ptrNewNodeToAdd;

    m_ptrNodeTail = ptrNewNodeToAdd;
    return (POSITION) ptrNewNodeToAdd;
}

template< class TYPE, class ARG_TYPE >
void CList<TYPE, ARG_TYPE>::AddTail( CList * pListToAdd )
{
            ASSERT( this );
            ASSERT( pListToAdd );

    POSITION position = ( *pListToAdd ).GetHeadPosition();
    while ( position )
        AddTail( ( *pListToAdd ).GetNext( position ) );
}

template< class TYPE, class ARG_TYPE >
void CList<TYPE, ARG_TYPE>::RemoveAll()
{
            ASSERT( this );

    TNode * ptrNode;
    for ( ptrNode = m_ptrNodeHead; ptrNode; ptrNode = ( *ptrNode ).ptrNext)
        ( *ptrNode ).nodeData.~TYPE();

    m_ptrNodeHead = m_ptrNodeTail = m_ptrNodeFree = NULL;
    ( *m_ptrBlocks ).FreeAllDataChain();
    m_Count = 0;
    m_ptrBlocks = NULL;
}

template< class TYPE, class ARG_TYPE >
TYPE CList<TYPE, ARG_TYPE>::RemoveHead()
{
            ASSERT( this );
            ASSERT( m_ptrNodeHead );

    TYPE returnVal = ( *m_ptrNodeHead ).nodeData;
    TNode * ptrOldNode = m_ptrNodeHead;
    m_ptrNodeHead = ( *ptrOldNode ).ptrNext;
    if ( m_ptrNodeHead )
        ( *m_ptrNodeHead ).ptrPrev = NULL;
    else
        m_ptrNodeTail = NULL;

    FreeTNode( ptrOldNode );
    return returnVal;
}

template< class TYPE, class ARG_TYPE >
TYPE CList<TYPE, ARG_TYPE>::RemoveTail()
{
            ASSERT( this );
            ASSERT( m_ptrNodeTail );

    TYPE returnVal = ( *m_ptrNodeTail ).nodeData;
    TNode * ptrOldNode = m_ptrNodeTail;
    m_ptrNodeTail = ( *ptrOldNode ).ptrPrev;
    if ( m_ptrNodeTail )
        ( *m_ptrNodeTail ).ptrNext = NULL;
    else
        m_ptrNodeHead = NULL;

    FreeTNode( ptrOldNode );
    return returnVal;
}

template< class TYPE, class ARG_TYPE >
POSITION CList<TYPE, ARG_TYPE>::GetHeadPosition() const
{
    return ( POSITION ) m_ptrNodeHead;
}

template< class TYPE, class ARG_TYPE >
TYPE & CList<TYPE, ARG_TYPE>::GetNext( POSITION & position )
{
    TNode * ptrNode = ( TNode * ) position;
            ASSERT( ptrNode );
    position = ( POSITION ) ( *ptrNode ).ptrNext;
    return ( *ptrNode ).nodeData;
}

template< class TYPE, class ARG_TYPE >
const TYPE & CList<TYPE, ARG_TYPE>::GetNext( POSITION & position ) const
{
    TNode * ptrNode = ( TNode * ) position;
            ASSERT( ptrNode );
    position = ( POSITION ) ( *ptrNode ).ptrNext;
    return ( *ptrNode ).nodeData;
}

template< class TYPE, class ARG_TYPE >
TYPE & CList<TYPE, ARG_TYPE>::GetPrev( POSITION & position )
{
    TNode * ptrNode = ( TNode * ) position;
            ASSERT( ptrNode );
    position = ( POSITION ) ( *ptrNode ).ptrPrev;
    return ( *ptrNode ).nodeData;
}

template< class TYPE, class ARG_TYPE >
const TYPE & CList<TYPE, ARG_TYPE>::GetPrev( POSITION & position ) const
{
    TNode * ptrNode = ( TNode * ) position;
            ASSERT( ptrNode );
    position = ( POSITION ) ( *ptrNode ).ptrPrev;
    return ( *ptrNode ).nodeData;
}

template< class TYPE, class ARG_TYPE >
POSITION CList<TYPE, ARG_TYPE>::GetTailPosition() const
{
    return ( POSITION ) m_ptrNodeTail;
}

template< class TYPE, class ARG_TYPE >
TYPE & CList<TYPE, ARG_TYPE>::GetAt( POSITION position )
{
    TNode * ptrNode = ( TNode * ) position;
            ASSERT( ptrNode );
    return ( *ptrNode ).nodeData; 
}

template< class TYPE, class ARG_TYPE >
const TYPE & CList<TYPE, ARG_TYPE>::GetAt( POSITION position ) const
{
    TNode * ptrNode = ( TNode * ) position;
            ASSERT( ptrNode );
    return ( *ptrNode ).nodeData; 
}

template< class TYPE, class ARG_TYPE >
void CList<TYPE, ARG_TYPE>::RemoveAt( POSITION pos )
{
            ASSERT( this );

    TNode * ptrOldNode = ( TNode * ) pos;
            ASSERT( ptrOldNode );

    if ( m_ptrNodeTail == ptrOldNode )
        m_ptrNodeTail = ( *ptrOldNode ).ptrPrev;

    else
    {
                ASSERT( ( *ptrOldNode ).ptrNext );
        ( * ( *ptrOldNode ).ptrNext ).ptrPrev = ( *ptrOldNode ).ptrPrev;
    }


    if ( m_ptrNodeHead == ptrOldNode )
        m_ptrNodeHead = ( *ptrOldNode ).ptrNext;

    else
    {
                ASSERT( ( *ptrOldNode ).ptrPrev );
        ( * ( *ptrOldNode ).ptrPrev ).ptrNext = ( *ptrOldNode ).ptrNext;
    }
    
    FreeTNode( ptrOldNode );
}

template< class TYPE, class ARG_TYPE >
void CList<TYPE, ARG_TYPE>::SetAt( POSITION position, ARG_TYPE elementToAdd )
{
    TNode * ptrNode = ( TNode *) position;
            ASSERT( ptrNode );
    ( *ptrNode ).nodeData = elementToAdd;
}

template< class TYPE, class ARG_TYPE >
POSITION CList<TYPE, ARG_TYPE>::InsertAfter( POSITION pos, ARG_TYPE elementToInsert )
{
            ASSERT( this );

    if ( NULL == pos )
        return AddTail( elementToInsert );

    TNode * ptrOldNode = ( TNode* ) pos;
            ASSERT( ptrOldNode );
    TNode * ptrNewNode = NewTNode( ptrOldNode, ( *ptrOldNode ).ptrNext );
    ( *ptrNewNode ).nodeData = elementToInsert;

    if ( ( *ptrOldNode ).ptrNext )
    {
                ASSERT( ( *ptrOldNode ).ptrNext );
        ( *( *ptrOldNode ).ptrNext ).ptrPrev = ptrNewNode;
    }
    else
    {
                ASSERT(  m_ptrNodeTail == ptrOldNode );
        m_ptrNodeTail = ptrNewNode;
    }
    ( *ptrOldNode ).ptrNext = ptrNewNode;
    return ( POSITION ) ptrNewNode;
}

template< class TYPE, class ARG_TYPE >
POSITION CList<TYPE, ARG_TYPE>::InsertBefore( POSITION pos, ARG_TYPE elementToInsert )
{
            ASSERT( this );

    if (NULL == pos )
        return AddHead( elementToInsert );

    TNode * ptrOldNode = ( TNode * ) pos;
    TNode * ptrNewNode = NewTNode( ( *ptrOldNode ).ptrPrev, ptrOldNode );
    ( *ptrNewNode ).nodeData = elementToInsert;

    if ( ( *ptrOldNode).ptrPrev )
    {
                ASSERT( ( *ptrOldNode ).ptrPrev );
        ( *( *ptrOldNode).ptrPrev ).ptrNext = ptrNewNode;
    }
    else
    {
                ASSERT( m_ptrNodeHead == ptrOldNode );
        m_ptrNodeHead = ptrNewNode;
    }
    (* ptrOldNode ).ptrPrev = ptrNewNode;
    return ( POSITION ) ptrNewNode;
}

template< class TYPE, class ARG_TYPE >
POSITION CList<TYPE, ARG_TYPE>::Find( ARG_TYPE valueToSearch, 
                                        POSITION startPosition ) const
{
            ASSERT( this );

    TNode * pNode = ( TNode * ) startPosition;
    if ( !pNode )
        pNode = m_ptrNodeHead;

    else
    {
                ASSERT( pNode );
        pNode = ( *pNode ).ptrNext;
    }

    for (; pNode; pNode = ( *pNode ).ptrNext)
    {
        if( ( *pNode ).nodeData == valueToSearch )
            return (POSITION)pNode;
    }
    return NULL;
}

template< class TYPE, class ARG_TYPE >
POSITION CList<TYPE, ARG_TYPE>::FindIndex( INT_PTR indexToFind ) const
{
            ASSERT( this );

    if ( indexToFind < 0 || indexToFind >= m_Count )
        return NULL;

    TNode * ptrNode = m_ptrNodeHead;
    while ( indexToFind -- )
    {
                ASSERT( ptrNode );
        ptrNode = ( *ptrNode ).ptrNext;
    }
    return (POSITION) ptrNode;
}

template< class TYPE, class ARG_TYPE >
INT_PTR CList<TYPE, ARG_TYPE>::GetCount() const
{
    return m_Count;
}

template< class TYPE, class ARG_TYPE >
INT_PTR CList<TYPE, ARG_TYPE>::GetSize() const
{
    return m_Count;
}

template< class TYPE, class ARG_TYPE >
BOOL CList<TYPE, ARG_TYPE>::IsEmpty() const
{
     return 0 == m_Count;
}

template< class TYPE, class ARG_TYPE >
typename CList<TYPE, ARG_TYPE>::TNode *
CList<TYPE, ARG_TYPE>::NewTNode( TNode * ptrPrevNode, TNode * ptrNextNode )
{
    if ( !m_ptrNodeFree )
    {
        CBlock * ptrNewBlock = CBlock::CreateBlock( m_ptrBlocks, m_BlockSize, 
                                                                 sizeof( TNode ) );
        TNode * ptrNode = ( TNode * ) ( *ptrNewBlock ).getData();
        ptrNode += m_BlockSize - 1;
        for (INT_PTR ix = m_BlockSize - 1; ix >= 0; ix --, ptrNode -- )
        {
            ( *ptrNode ).ptrNext = m_ptrNodeFree;
            m_ptrNodeFree = ptrNode;
        }
    }
            ASSERT( m_ptrNodeFree );

    CList::TNode * ptrNode = m_ptrNodeFree;
    m_ptrNodeFree = ( *m_ptrNodeFree ).ptrNext;
    ( *ptrNode ).ptrPrev = ptrPrevNode;
    ( *ptrNode ).ptrNext = ptrNextNode;
    ++ m_Count;

            ASSERT( ( 0 < m_Count ) );

    new( ( void * )( &( *ptrNode ).nodeData ) ) TYPE;
    return ptrNode;
}

template< class TYPE, class ARG_TYPE >
void CList<TYPE, ARG_TYPE>::FreeTNode( TNode * ptrNodeToFree )
{
    ( *ptrNodeToFree ).nodeData.~TYPE();
    ( *ptrNodeToFree ).ptrNext = m_ptrNodeFree;
    m_ptrNodeFree = ptrNodeToFree;
    -- m_Count;
            ASSERT( ( 0 <= m_Count ) );

    if ( !m_Count )
        RemoveAll();
}


#ifdef _WIN32
}  // namespace Mfc
#endif


#ifdef _WIN32
#define CMfcList Mfc::CList
#else
#define CMfcList CList
#endif


// ========== Platform specific ==========

#ifndef _WIN32 // on Linux/Mac


#endif // !_WIN32

#endif // _BS_CLIST_INCLUDED_
