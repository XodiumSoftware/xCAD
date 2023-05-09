// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

class AcDbViewportTableRecord;
class AcGiDrawable;
class AcGsDevice;
class AcGsModel;
class AcGsView;
class AcGsConfig;
class AcGsGraphicsKernel;
class AcGsKernelDescriptor;

class AcGsClassFactory; //V16 compatibility

/** _ */
class BRX_IMPORTEXPORT AcGsManager
{
public:
    AcGsManager();
    virtual ~AcGsManager();

    //V17
    static AcGsGraphicsKernel* acquireGraphicsKernel(const AcGsKernelDescriptor&);
    static void releaseGraphicsKernel(AcGsGraphicsKernel*);
    static AcGsConfig* getConfig();

    virtual AcGsModel* createAutoCADModel(AcGsGraphicsKernel&) = 0;
    virtual AcGsView* createAutoCADViewport(AcGsGraphicsKernel&, AcDbViewportTableRecord*) = 0;
    virtual AcGsView* createAutoCADView(AcGsGraphicsKernel&, AcGiDrawable*) = 0;
    virtual AcGsDevice* createAutoCADDevice(AcGsGraphicsKernel&, HWND hWnd) = 0;
    virtual AcGsDevice* createAutoCADOffScreenDevice(AcGsGraphicsKernel&) = 0;
    virtual void destroyAutoCADModel(AcGsModel*) = 0;
    virtual void destroyAutoCADView(AcGsView*) = 0;
    virtual void destroyAutoCADDevice(AcGsDevice*) = 0;
    virtual AcGsModel* getDBModel(AcGsGraphicsKernel&) = 0;
    virtual AcGsDevice* getGUIDevice(AcGsGraphicsKernel&) = 0;

    //V16 compatibility
    virtual AcGsClassFactory* getGSClassFactory() = 0;
    virtual AcGsDevice* createAutoCADDevice(HWND) = 0;
    virtual AcGsDevice* createAutoCADOffScreenDevice() = 0;
    virtual AcGsDevice* getGUIDevice() = 0;
    virtual AcGsModel* createAutoCADModel() = 0;
    virtual AcGsModel* getDBModel() = 0;
    virtual AcGsView* createAutoCADView(AcGiDrawable*) = 0;
    virtual AcGsView* createAutoCADViewport(AcDbViewportTableRecord*) = 0;
};
