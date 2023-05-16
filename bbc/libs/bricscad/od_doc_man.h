// od_doc_man.h : OdApDocManager, OdApDocManagerReactor, OdApDocument and OdApDocumentIterator interfaces

// Copyright © Menhirs NV. All rights reserved.

//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH

#pragma once
#include "StringArray.h"

class OdDbDatabase;
class CDocument;
class OdEdInputPointManager;

class OdApDocument
{
public:
    enum EAcadSaveFormat
    {
        eUnknown = -1,
        eR12_dxf = 1,

        eR13_dwg = 4,
        eR13_dxf = 5,

        eR14_dwg = 8,
        eR14_dxf = 9,

        e2000_dwg = 12,
        eR15_dwg = e2000_dwg,
        e2000_dxf = 13,
        eR15_dxf = e2000_dxf,
        e2000_Template = 14,
        eR15_Template = e2000_Template,
        e2000_Standard = 15,
        eR15_Standard = e2000_Standard,
        e2000_xml = 16,
        eR15_xml = e2000_xml,

        e2004_dwg = 24,
        eR18_dwg = e2004_dwg,
        e2004_dxf = 25,
        eR18_dxf = e2004_dxf,
        e2004_Template = 26,
        eR18_Template = e2004_Template,
        e2004_Standard = 27,
        eR18_Standard = e2004_Standard,

        e2007_dwg = 36,
        e2007_dxf = 37,
        e2007_Template = 38,
        e2007_Standard = 39,

        e2010_dwg = 48,
        e2010_dxf = 49,
        e2010_Template = 50,
        e2010_Standard = 51,

        e2013_dwg = 60,
        e2013_dxf = 61,
        e2013_Template = 62,
        e2013_Standard = 63,

        e2018_dwg = 70,
        e2018_dxf = 71,
        e2018_Template = 72,
        e2018_Standard = 73,

        eNative = e2018_dwg,
    };

public:
    virtual ~OdApDocument() noexcept = default;
    virtual OdString fileName() const = 0;
    virtual OdDbDatabase* database() = 0;
    virtual bool save(const OdString &filename = OdString(), bool noUI = false) = 0; // if doc has never been saved and no filename given then the SaveAs dialog comes up
    virtual bool saveAs(const OdString &filename, OdApDocument::EAcadSaveFormat saveFormat = OdApDocument::eNative) = 0;
    virtual CDocument* cDoc() = 0;
    virtual OdApDocument::EAcadSaveFormat formatForSave() = 0;
    virtual OdEdInputPointManager* inputPointManager() = 0;
};

class OdApDocManagerReactor
{
public:
    virtual ~OdApDocManagerReactor() noexcept = default;
    virtual void documentActivated(OdApDocument* pActivatedDoc) {}
    virtual void documentBecameCurrent(OdApDocument* pActivatedDoc) {}
    virtual void documentCreateCanceled(OdApDocument *pDoc) {}
    virtual void documentCreated(OdApDocument *pDoc) {}
    virtual void documentCreateStarted(OdApDocument *pDoc) {}
    virtual void documentDestroyed(const OdString &filename) {}
    virtual void documentToBeActivated(OdApDocument* pDoc) {}
    virtual void documentToBeDeactivated(OdApDocument* pDoc) {}
    virtual void documentToBeDestroyed(OdApDocument* pDoc) {}

    // minimum document locking reactor events :
    // - for BRX implementation
    // - for cancelling a starting command via veto()
    virtual void documentLockWillChange(OdApDocument* pDoc, bool isLocking, 
                                        const OdString &command) {}
    virtual void documentLocked(OdApDocument* pDoc, const OdString &command) {}
    virtual void documentUnlocked(OdApDocument* pDoc, const OdString &command) {}
    virtual void documentLockVetoed(OdApDocument* pDoc, const OdString &command) {}
    void veto() { m_wasVetoed = true; }

public:
    void resetVeto() { m_wasVetoed = false; }
    bool wasVetoed() { return m_wasVetoed; }

private:
    bool m_wasVetoed;
};

/* note about timing of reactors :
Operation                 reactors

NEW/OPEN drawing(D1):     documentCreateStarted (D1, empty filename)
                          documentCreated (D1, filename = drawingN.dwg in case of NEW, N being the next nr of the MDI windows)
                          documentToBeDeActivated (D2, if there was one)
                          documentToBeActivated (D1)
                          documentActivated (D1)
                          documentBecameCurrent (D1)

SWITCH drawing(D1->D2):   documentToBeDeActivated (D1)
                          documentToBeActivated (D2)
                          documentActivated (D2)
                          documentBecameCurrent (D2)

CLOSE drawing(D1):        documentToBeDestroyed(D1)
                          documentToBeDeActivated (D1)
                          documentToBeActivated (D2, if there is one)
                          documentActivated (D2, if there is one)
                          documentBecameCurrent (D2, if there is one)
                          documentDestroyed(filename of D1)

(This last case occurs when you close modal dialog while drawing D1 was open, 
 or when you make the application active after it was made inactive while drawing D1 was open)
Re-activate drawing(D1):  documentToBeActivated (D1)
                          documentActivated (D1)
*/

class OdApDocumentIterator
{
public:
    virtual ~OdApDocumentIterator() {}

    virtual bool done() const = 0;
    virtual void step() = 0;
    virtual OdApDocument * document() = 0;

protected:
    OdApDocumentIterator() {}
};

class OdApDocManager
{
public:
    virtual ~OdApDocManager() {}
    virtual void addReactor(OdApDocManagerReactor*) = 0;
    virtual void removeReactor(OdApDocManagerReactor*) = 0;

    virtual int closeDocument(OdApDocument *pTargetDocument) = 0;
    virtual int activateDocument(OdApDocument *pTargetDocument,bool bPassScript = false) = 0;
    virtual OdApDocument * curDocument() const = 0;
    virtual int documentCount() const = 0;
    virtual OdApDocumentIterator * newOdApDocumentIterator() = 0;
    virtual bool appContextNewDocument( const OdString& templateFilename ) = 0;
    virtual bool appContextOpenDocument( const OdString& filename, bool readOnly = false ) = 0;

    virtual void pushResourceHandle(HINSTANCE newResource) = 0;
    virtual void pushAcadResourceHandle() = 0;
    virtual void popResourceHandle() = 0;

    virtual bool lockDocument(OdApDocument* pTargetDocument, const OdString &command) = 0;
    virtual bool unlockDocument(OdApDocument* pTargetDocument, const OdString &command) = 0;

    virtual bool disableDocumentActivation() = 0;
    virtual bool enableDocumentActivation() = 0;
    virtual bool isDocumentActivationEnabled() = 0;

    virtual bool sendStringToExecute(OdApDocument* pTargetDocument,
                                     const OdString& cmdString,
                                     bool activateDoc = true,
                                     bool wrapUpInactiveDoc = false,
                                     bool echoString = true) = 0;
};

OdApDocManager * odapDocManager();
