// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

// Windows MFC CStringList type and functions

#ifndef _BS_CSTRINGLIST_INCLUDED_
#define _BS_CSTRINGLIST_INCLUDED_


#include "Platform/mfc/CObject.h"
#include "Platform/mfc/CString.h"


#ifndef BRXEXPORT // for client build : import
#define BRXEXPORT
#endif

// ========== Platform independent ==========

#ifdef _WIN32
namespace Mfc
{
#endif

class BRXEXPORT CStringList : public CObject{

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
        CString nodeData;
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

     CStringList( INT_PTR nBlockSizeGrowBy = 10 );
    ~CStringList();

    const CString& GetHead() const;
    CString& GetHead();
    CString& GetTail();
    const CString& GetTail() const;

    POSITION AddHead( LPCTSTR elementToAdd );
    POSITION AddHead( const CString& elementToAdd );
    void AddHead( CStringList * pListToAdd );
    POSITION AddTail( LPCTSTR elementToAdd );
    POSITION AddTail( const CString& elementToAdd );
    void AddTail( CStringList * pListToAdd );
    void RemoveAll();
    CString RemoveHead();
    CString RemoveTail();

    POSITION GetHeadPosition() const;
    CString& GetNext( POSITION & position );
    const CString& GetNext( POSITION & position ) const;

    CString& GetPrev( POSITION & position );
    const CString& GetPrev( POSITION & position ) const;
    POSITION GetTailPosition() const;

    CString& GetAt( POSITION position );
    const CString& GetAt( POSITION position ) const;
    void RemoveAt( POSITION pos ); 
    void SetAt( POSITION position, const CString& elementToAdd );

    POSITION InsertAfter( POSITION pos, LPCTSTR elementToInsert );
    POSITION InsertAfter( POSITION pos, const CString& elementToInsert );
    POSITION InsertBefore( POSITION pos, LPCTSTR elementToInsert );
    POSITION InsertBefore( POSITION pos, const CString& elementToInsert );

    POSITION Find( LPCTSTR valueToSearch, POSITION startPosition = NULL) const; 
    POSITION FindIndex( INT_PTR indexToFind ) const;

    INT_PTR GetCount() const { return m_Count; };
    INT_PTR GetSize() const { return m_Count; };
    BOOL IsEmpty() const { return 0 == m_Count; };
};

#ifdef _WIN32
}  // namespace Mfc
#endif


#ifdef _WIN32
typedef  Mfc::CStringList CMfcStringList;
#else
typedef CStringList CMfcStringList;
#endif


// ========== Platform specific ==========

#ifndef _WIN32 // on Linux/Mac


#endif // !_WIN32

#endif // _BS_CSTRINGLIST_INCLUDED_
