// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

// Windows MFC CObject type and functions

#ifndef _BS_COBJECT_INCLUDED_
#define _BS_COBJECT_INCLUDED_

#ifndef BRXEXPORT // for client build : import
#define BRXEXPORT
#endif

// ========== Platform independent ==========

#ifdef _WIN32
namespace Mfc
{
#endif

class CArchive;
struct CRuntimeClass;
class CDumpContext;

class AFX_NOVTABLE BRXEXPORT CObject
{

    private:

        CObject( const CObject & objSrc );    // no implementation
        void operator=( const CObject& objSrc ); // no implementation

    protected:

        CObject();
        
    public:

        virtual ~CObject() = 0;

        void * PASCAL operator new( size_t size ); 
        void * PASCAL operator new( size_t, void * ptr ) noexcept;
        void * PASCAL operator new( size_t size, LPCSTR fileName, int line ) noexcept;

        void PASCAL operator delete( void * ptr );
        void PASCAL operator delete( void * ptr, void * pBuffer );
        void PASCAL operator delete( void * ptr, LPCSTR fileName, int line );

        virtual void AssertValid() const;
        virtual void Dump( CDumpContext & diagDumpContext ) const;

        BOOL IsSerializable() const;
        virtual void Serialize( CArchive & archive );

        virtual CRuntimeClass * GetRuntimeClass() const;
        BOOL IsKindOf( const CRuntimeClass * pClassOf ) const;
};

#ifdef _WIN32
} // namespace Mfc
#endif

// ========== Platform specific ==========

#ifdef _WIN32
    typedef Mfc::CObject    CMfcObject;
#else
    typedef      CObject    CMfcObject;
#endif

#endif // _BS_COBJECT_INCLUDED_
