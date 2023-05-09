// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbGlobal.h"

//common forward declarations
class AcGeVector3d;
class AcGiDrawable;
class AcGs2DViewLimitManager;
class AcGsClassFactory;
class AcGsConfig;
class AcGsDevice;
class AcGsManager;
class AcGsModel;
class AcGsNode;
class AcGsReactor;
class AcGsScreenShot;
class AcGsView;
class CView;

namespace Atil
{
    class FileReadDescriptor;
    class Image;
};

#define SCALAR_MAX 2147483647
#define SCALAR_MIN (-SCALAR_MAX-1)

namespace GS
{
    enum DeviceType
    {
        kScreenDevice = 0,
        kOffScreenDevice,
        kSelectionDevice
    };

    enum ErrorStatus
    {
        kSuccess = 0,
        kOutOfRange,
        kInvalidInput
    };

    enum HighlightStyle
    {
        kHighlightDashed = 0,
        kHighlightThicken,
        kHighlightDashedAndThicken,
        kHighlightCustom,
        kHighlightDim,
        kHighlightThickDim,
        kHighlightGlow
    };

    enum SyncBehavior
    {
        eSync = 0,
        eAsync,
    };

    enum ImageOrientation
    {
        kTopDown = 0,
        kBottomUp
    };

    enum ImageDataFormat
    {
        kRGBA = 0,
        kBGRA
    };
};

struct AcGs
{
    enum LinePattern
    {
        eSolid = 0,
        eDashed,
        eDotted,
        eDefaultLinePattern = 2,
        eDashDot,
        eShortDash,
        eMediumDash,
        eLongDash,
        eDoubleShortDash,
        eDoubleMediumDash,
        eDoubleLongDash,
        eMediumLongDash,
        eMediumDashShortDashShortDash,
        eLongDashShortDash,
        eLongDashDotDot,
        eLongDashDot,
        eMediumDashDotShortDashDot,
        eSparseDot
    };
};

typedef AcGiDrawable* (*AcGsGetInterfaceFunc)(LONG_PTR, bool);
typedef AcGsClassFactory* (*AcGsCreateClassFactoryFunc)();
typedef void (*acgsCustomUpdateMethod)(void*, int, int, int, int);
typedef void (*AcGsDeleteClassFactoryFunc)(AcGsClassFactory*);
typedef void (*AcGsReleaseInterfaceFunc)(AcGiDrawable*);
typedef void* AcGsWindowingSystemID;

#define ACGS_CREATE_CLASS_FACTORY "CreateClassFactory"
#define ACGS_DELETE_CLASS_FACTORY "DeleteClassFactory"

AcGs2DViewLimitManager* acgsCreate2DViewLimitManager(int);
AcGs::LinePattern acgsGetHighlightLinePattern();
AcGsManager* acgsGetGsManager(CView* = NULL);
AcGsScreenShot* acgsGetScreenShot(int);
AcGsView* acgsGetGsView(int, bool);
AcGsView* acgsGetCurrentAcGsView(int);
Adesk::Boolean acgsDisplayImage(int, long, long, int, int, void const*, int);
Adesk::Boolean acgsGetDisplayInfo(int&, int&, int&, int&);
Adesk::Boolean acgsGetLensLength(int, double&);
Adesk::Boolean acgsGetOrthoViewParameters(int, AcDb::OrthographicView, AcGeVector3d*, AcGeVector3d*);
Adesk::Boolean acgsGetViewParameters(int, AcGsView*);
Adesk::Boolean acgsGetViewportInfo(int, int&, int&, int&, int&);
Adesk::Boolean acgsRemoveAnonymousGraphics(int);
Adesk::Boolean acgsSetCustomUpdateMethod(acgsCustomUpdateMethod, void*);
Adesk::Boolean acgsSetLensLength(int, const double&);
Adesk::Boolean acgsSetView2D(int);
Adesk::Boolean acgsSetViewParameters(int, const AcGsView*, bool, bool, bool = false);
Adesk::UInt16 acgsGetHighlightColor();
Adesk::UInt16 acgsGetHighlightLineWeight();
void acgsDestroy2DViewLimitManager(AcGs2DViewLimitManager*);
void acgsRedrawShortTermGraphics(short, short, short, short);
void acgsSetHighlightColor(Adesk::UInt16);
void acgsSetHighlightLinePattern(AcGs::LinePattern);
void acgsSetHighlightLineWeight(Adesk::UInt16);
void acgsSetViewportRenderFlag(int);
void acgsWriteViewToUndoController(int);
