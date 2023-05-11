// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbGlobal.h"
#include "AcDb/AcDbHostApplicationProgressMeter.h"
#include "AcRx/AcRxObject.h"

struct _EXCEPTION_POINTERS;

class AcDbUndoController;

typedef Acad::ErrorStatus (*REMAPPROC)(ACHAR*&,const ACHAR*,int,void*);
typedef Acad::ErrorStatus (*SELECTFILEPROC)(short*,ACHAR*&,void*,const int,const ACHAR*,const ACHAR*,const ACHAR*,const ACHAR*,int*,bool*,const ACHAR*,void*);
typedef void (*MAPFILENOTIFYPROC)(const ACHAR*,const ACHAR*,int,void*);

/** _ */
class BRX_IMPORTEXPORT AcDbHostApplicationServices: public AcRxObject
{
public:
    enum FindFileHint
    {
        kDefault            =  0,
        kFontFile           =  1,
        kCompiledShapeFile  =  2,
        kTrueTypeFontFile   =  3,
        kEmbeddedImageFile  =  4,
        kXRefDrawing        =  5,
        kPatternFile        =  6,
        kARXApplication     =  7,
        kFontMapFile        =  8,
        kUnderlayFile       =  9,
        kDataLinkFile       = 10,
        kPhotometricWebFile = 11,
        kMaterialMapFile    = 12,
        kCloudOrProjectFile = 13,
    };

    enum ModelerFlavor
    {
        kModelerFull = 0,
        kModelerRegionsOnly,
        kModelerObjectsOnly
    };

    enum PasswordOptions
    {
        kPasswordOptionDefault = 0,
        kPasswordOptionUpperCase,
        kPasswordOptionIsExternalReference
    };

    enum RemapFileContext
    {
        kDrawingOpen = 0,
        kXrefResolution,
        kRasterResolution,
        kAfterXrefResolution
    };

    enum RequiredVersionFlags
    {
        kNoOpen = 0,
        kReadOnly,
        kWriteAllowed,
    };

    ACRX_DECLARE_MEMBERS(AcDbHostApplicationServices);

    AcDbHostApplicationServices(int = 1);
    virtual ~AcDbHostApplicationServices();

    virtual Acad::ErrorStatus findFile(ACHAR*,int,const ACHAR*,AcDbDatabase* = NULL,FindFileHint = kDefault) = 0;
    virtual Acad::ErrorStatus getLocalRootFolder(const ACHAR*&);
    virtual Acad::ErrorStatus getNewOleClientItem(COleClientItem*&);
    virtual Acad::ErrorStatus getRegisteredFileMapClients(AcArray<const ACHAR*>&);
    virtual Acad::ErrorStatus getRegisteredSelectFileClients(AcArray<const ACHAR*>&);
    virtual Acad::ErrorStatus getRemoteFile(const ACHAR*,ACHAR*,Adesk::Boolean = Adesk::kFalse) const;
    virtual Acad::ErrorStatus getRoamableRootFolder(const ACHAR*&);
    virtual Acad::ErrorStatus mapFile(ACHAR*&,const ACHAR*,int,void*);
    virtual Acad::ErrorStatus putRemoteFile(const ACHAR*,const ACHAR*) const;
    virtual Acad::ErrorStatus registerMapFileCallback(const ACHAR*,REMAPPROC,bool = false,bool = false);
    virtual Acad::ErrorStatus registerMapFileNotification(const ACHAR*,MAPFILENOTIFYPROC,bool = false);
    virtual Acad::ErrorStatus registerSelectFileCallback(const ACHAR*,SELECTFILEPROC,bool = false,bool = false);
    virtual Acad::ErrorStatus selectFile(short*,ACHAR*&,void*,const int,const ACHAR*,const ACHAR*,const ACHAR*,const ACHAR*,int*,bool*,const ACHAR*,void*);
    virtual Acad::ErrorStatus serializeOleItem(COleClientItem*,CArchive*);
    virtual Acad::ErrorStatus signingComplete(Acad::ErrorStatus,const ACHAR*,bool*);
    virtual AcDbHostApplicationProgressMeter* newProgressMeter();
    virtual AcDbLayoutManager* layoutManager() const;
    virtual AcDbPlotSettingsValidator* plotSettingsValidator() const;
    virtual AcDbTransactionManager* workingTransactionManager();
    virtual ACHAR* getAlternateFontName() const;
    virtual ACHAR* getFontMapFileName() const;
    virtual Adesk::Boolean doFullCRCCheck();
    virtual Adesk::Boolean getSubstituteFont(ACHAR**,ACHAR*,int,int);
    virtual Adesk::Boolean isRemoteFile(const ACHAR*,ACHAR*) const;
    virtual Adesk::Boolean isURL(const ACHAR*) const;
    virtual Adesk::Boolean launchBrowserDialog(ACHAR*,const ACHAR*,const ACHAR*,const ACHAR*,const ACHAR* = NULL,Adesk::Boolean = Adesk::kFalse) const;
    virtual Adesk::Boolean readyToDisplayMessages();
    virtual Adesk::Boolean userBreak(bool = true) const;
    virtual bool cacheSymbolIndices() const;
    virtual bool getPassword(const ACHAR*,PasswordOptions,ACHAR*,const size_t);
    virtual bool loadApp(const ACHAR*,AcadApp::LoadReasons,bool,bool);
    virtual bool setMapFlag(bool);
    virtual bool supportsMultiRedo() const;
    virtual const ACHAR* companyName();
    virtual const ACHAR* getColorBookLocation() const;
    virtual const ACHAR* getEnv(const ACHAR*);
    virtual const ACHAR* getRegistryProductRootKey();
    virtual const ACHAR* primaryClientForMapFileCallback();
    virtual const ACHAR* primaryClientForSelectFileCallback();
    virtual const ACHAR* product();
    virtual const ACHAR* program();
    virtual const ACHAR* releaseMajorMinorString();
    virtual const ACHAR* versionString();
    virtual const ProdIdCode prodcode();
    virtual int releaseMajorVersion();
    virtual int releaseMinorVersion();
    virtual LCID getRegistryProductLCID();
    virtual ModelerFlavor getModelerFlavor() const;
    virtual unsigned int getTempPath(Adesk::UInt32,ACHAR*);
    virtual void alert(const ACHAR*) const;
    virtual void auditPrintReport(AcDbAuditInfo*,const ACHAR*,int) const;
    virtual void displayChar(ACHAR) const;
    virtual void displayString(const ACHAR*,int) const;
    virtual void drawOleOwnerDrawItem(COleClientItem*,Adesk::LongPtr,Adesk::Int32,Adesk::Int32,Adesk::Int32,Adesk::Int32);
    virtual void enableMessageDisplay(Adesk::Boolean);
    virtual void fatalError(const ACHAR*,...);
    virtual void getDefaultPlotCfgInfo(ACHAR*,ACHAR*);
    virtual void missingCryptoProviderMsg();
    virtual void reportUnhandledArxException(const _EXCEPTION_POINTERS*,const ACHAR*);
    virtual void terminateScript();
    virtual void usedPasswordFromCacheMsg(const ACHAR*);

    AcDbDatabase* workingDatabase() const;
    code_page_id getSystemCodePage() const;
    void setSystemCodePage(code_page_id);
    void setWorkingDatabase(AcDbDatabase*);
    void setWorkingProgressMeter(AcDbHostApplicationProgressMeter*);
    void setWorkingTransactionManager(AcDbTransactionManager*);

    //V10
    virtual AcDbUndoController* defaultUndoController();
    void setDefaultUndoController(AcDbUndoController*);

    //V13
    virtual const ACHAR* getMachineProductRegistryRootKey();
    virtual const ACHAR* getUserProductRegistryRootKey();

    //V14
    virtual Acad::ErrorStatus getAllUsersRootFolder(const ACHAR*&);
    virtual Acad::ErrorStatus getGraphicsCacheFolder(const ACHAR*&);
    virtual const ACHAR* releaseMarketVersion();
    virtual Adesk::Boolean isCloudFile(const ACHAR*) const;
    virtual short getKeyState(int) const;
    virtual bool requiredVersionNotAvailable(AcDbHostApplicationServices::RequiredVersionFlags, AcDbDatabase*) const;
    virtual bool notifyCorruptDrawingFoundOnOpen(AcDbObjectId, Acad::ErrorStatus);
    virtual const ACHAR* getUserRegistryProductRootKey();
    virtual const ACHAR* getMachineRegistryProductRootKey();

    //V22
    Acad::ErrorStatus findFile(AcString& fileOut, const ACHAR* pcFilename, AcDbDatabase* pDb = nullptr, AcDbHostApplicationServices::FindFileHint hint = AcDbHostApplicationServices::kDefault);
};
