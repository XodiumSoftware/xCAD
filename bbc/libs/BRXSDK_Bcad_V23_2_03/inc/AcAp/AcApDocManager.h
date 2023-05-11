// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcAp/AcApDocManagerReactor.h"
#include "AcAp/AcApDocumentIterator.h"

/** _ */
class BRX_IMPORTEXPORT AcApDocManager: public AcRxObject
{
public:
    struct DocOpenParams
    {
      enum
      {
        kUnknown = 0,
        kDefaultView,
        kLayoutName,
        kViewName,
        kLayoutHandle,
        kViewHandle,
        kViewWorldCoords,
      };
      enum
      {
        kDisallowReadOnly      =  1,
        kRequireReadOnly       =  2,
        kFileNameArgIsUnicode  =  4,
        kViewNameArgIsUnicode  =  8,
        kUseUIOnErrors         = 16,
        kOwnerControlled       = 32,
        kUseUI                 = 64,
      };

      union
      {
        const ACHAR* mpszFileName;
        const wchar_t* mpwszFileName;
      };
      union
      {
        const ACHAR* mpszViewName;
        const wchar_t* mpwszViewName;
        const double* mpCoords;
      };
      BYTE mnInitialViewType;
      int  mnFlags;
      const wchar_t* mpwszPassword;
      void* mpOwnerData;
      void* mpUnused;
      int  mnUnused;
      const wchar_t* mpwszTitle;
    };

public:
    ACRX_DECLARE_MEMBERS(AcApDocManager);

    virtual Acad::ErrorStatus activateDocument(AcApDocument*,bool = false) = 0;
    virtual Acad::ErrorStatus appContextNewDocument(const ACHAR*) = 0;
    virtual Acad::ErrorStatus appContextOpenDocument(const ACHAR*) = 0;
    virtual Acad::ErrorStatus closeDocument(AcApDocument*) = 0;
    virtual Acad::ErrorStatus disableDocumentActivation() = 0;
    virtual Acad::ErrorStatus enableDocumentActivation() = 0;
    virtual Acad::ErrorStatus lockDocument(AcApDocument*,AcAp::DocLockMode = AcAp::kWrite,const ACHAR* = NULL,const ACHAR* = NULL,bool = true) = 0;
    virtual Acad::ErrorStatus newDocument() = 0;
    virtual Acad::ErrorStatus openDocument() = 0;
    virtual Acad::ErrorStatus sendModelessInterrupt(AcApDocument*) = 0;
    virtual Acad::ErrorStatus sendStringToExecute(AcApDocument*,const ACHAR*,bool = true,bool = false,bool = true) = 0;
    virtual Acad::ErrorStatus setCurDocument(AcApDocument*,AcAp::DocLockMode = AcAp::kNone,bool = false) = 0;
    virtual Acad::ErrorStatus setDefaultFormatForSave(AcApDocument::SaveFormat) = 0;
    virtual Acad::ErrorStatus unlockDocument(AcApDocument*) = 0;
    virtual AcApDocument* curDocument() const = 0;
    virtual AcApDocument* document(const AcDbDatabase*) const = 0;
    virtual AcApDocument* mdiActiveDocument() const = 0;
    virtual AcApDocumentIterator* newAcApDocumentIterator() = 0;
    virtual bool isApplicationContext() const = 0;
    virtual bool isDocumentActivationEnabled() = 0;
    virtual int documentCount() const = 0;
    virtual int inputPending(AcApDocument*) = 0;
    virtual void addReactor(AcApDocManagerReactor*) = 0;
    virtual void executeInApplicationContext(void (*fp)(void*),void*) const = 0;
    virtual void popResourceHandle() = 0;
    virtual void pushAcadResourceHandle() = 0;
    virtual void pushResourceHandle(HINSTANCE) = 0;
    virtual void removeReactor(AcApDocManagerReactor*) = 0;

    virtual Acad::ErrorStatus appContextOpenDocument(const DocOpenParams*) = 0;
    virtual AcApDocument::SaveFormat defaultFormatForSave() const = 0;

    Acad::ErrorStatus appContextPromptNewDocument();
    Acad::ErrorStatus appContextPromptOpenDocument();
    Acad::ErrorStatus appContextCloseDocument(AcApDocument*);
};
