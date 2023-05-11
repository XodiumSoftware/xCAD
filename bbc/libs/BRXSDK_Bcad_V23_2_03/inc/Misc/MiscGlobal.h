// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "brx_importexport.h"  // BRX_IMPORTEXPORT
#include "brx_platform_3264.h" // 32/64 bit detection

//BRX START
//MFC (afx...) headers must be included before windows headers
//to avoid compile error C1189
#ifdef _WIN32 // Windows
  #if defined(_AFXEXT) && defined(__cplusplus)
    #if defined(_DEBUG) && !defined(BRX_BCAD_DEBUG)
      #undef _DEBUG
      #include <afxcoll.h>
      #define _DEBUG
    #else
      #include <afxcoll.h>
    #endif
  #endif
#endif
//BRX END


#ifndef _WIN32  // Linux,Mac
  #ifndef _BS_BRX_PLATFORM_INCLUDED_
  #include "brx_platform_linux.h"
  #endif
#endif


#ifdef _WIN32 // Windows
  #include <assert.h>
  #include <BaseTsd.h> //ULONG_PTR
  #include <stdarg.h>
  #include <stddef.h> //size_t
  #include <stdlib.h>
  #include <wtypes.h>
#else  // Linux/Mac
  #include <assert.h>
  #include <stdarg.h>
  #include <stddef.h> //size_t
  #include <stdlib.h>
#ifdef __APPLE__
  #include <locale>
#endif //__APPLE__
#endif

#pragma pack(push, 8)

#ifdef _WIN32 // Windows
  #if !defined(_NATIVE_WCHAR_T_DEFINED) && defined (__cplusplus)
  #error Compiler option /Zc:wchar_t is required !
  #endif
#endif // _WIN32

#define BRX_PI 3.1415926535897932384626433832795028841971693993751

#define AD_UNICODE 1
typedef wchar_t ACHAR;
#define _ACRX_T(s) L##s
#define ACRX_T(s) _ACRX_T(s)

//common forward declarations
#ifdef __cplusplus
class AcApDocument;
class AcApProfileManager;
class AcDbDatabase;
class AcDbStub;
class AcDbObjectId;
class AcDMMReactor;
class AcEdSSGetFilter;
class AcEdSSGetFilter2;
class AcEdSSGetSubSelectFilter;
class AcFileDependencyManager;
class AcGeVector3d;
class AcPublishReactor;
class AcPublishUIReactor;
class AcString;
class AdCharFormatter;
class AdHostImageAppServices;
class CAcGradientThumbnailEngine;
class CArchive;
class CFile;
class COleClientItem;
class CRect;
#ifndef __APPLE__
namespace std
{
    class locale;
}
#endif //__APPLE__
#endif //__cplusplus

#ifdef __ATLCOM_H__
template <class T> class CProxy_AcadObjectEvents;
template <class T> class CProxy_PropertyNotifySink;
interface IAcadAcCmColorAccess;
interface IAcadBaseDatabase;
interface IAcadBaseObject;
interface IAcadBaseObject2;
interface IAcadBaseSubEntity;
interface IMetaColorSuppressor;
#endif

#ifndef NULL
#define NULL 0
#endif

#ifndef NULLFCN
#define NULLFCN 0
#endif

#ifdef __cplusplus
struct Adesk
{
    enum
    {
        kFalse = 0,
        kTrue
    };

    typedef int Boolean;
    typedef unsigned char uchar;
    typedef unsigned short ushort;
    typedef unsigned int uint;
    typedef unsigned long ulong;
    typedef char Int8;
    typedef short Int16;
    typedef unsigned char UInt8;
    typedef unsigned short UInt16;

#ifdef __SYS_64_BIT__  // 64 bit systems : Windows,Linux,Mac
  #ifdef _WIN32
    typedef long              Int32;
    typedef unsigned long     UInt32;
    typedef __int64           LongPtr;
    typedef unsigned __int64  ULongPtr;
    typedef __int64           IntPtr;
    typedef unsigned __int64  UIntPtr;
    typedef unsigned __int64  Size_t;
    typedef __int64           SSize_t;
  #else //_WIN32
    typedef int32_t           Int32;
    typedef uint32_t          UInt32;
    typedef int64_t           LongPtr;
    typedef uint64_t          ULongPtr;
    typedef int64_t           IntPtr;
    typedef uint64_t          UIntPtr;
    typedef uint64_t          Size_t;
    typedef int64_t           SSize_t;
  #endif //_WIN32
#else                  // 32 bit systems : Windows,Linux,Mac
    typedef long              Int32;
    typedef unsigned long     UInt32;
    typedef long              LongPtr;
    typedef unsigned long     ULongPtr;
    typedef int               IntPtr;
    typedef unsigned int      UIntPtr;
    typedef unsigned long     Size_t;
    typedef long              SSize_t;
#endif

#ifdef _WIN32 // Windows
    typedef __int64           Int64;
    typedef unsigned __int64  UInt64;
#else         // Linux, Mac
    typedef int64_t	          Int64;
    typedef uint64_t	      UInt64;
#endif

    typedef LongPtr IntDbId;
    typedef IntPtr  GsMarker;



    using ColorRef = UInt32;
    using RGBQuad = UInt32;
};
#endif //__cplusplus

enum
{
    kFalse = 0,
    kTrue
};

#ifdef __cplusplus

#ifndef __APPLE__ //type already defined on OS X in MacTypes.h
typedef Adesk::Boolean Boolean;
#endif //__APPLE__

typedef Adesk::uchar uchar;
typedef Adesk::ushort ushort;
typedef Adesk::uint uint;
typedef Adesk::ulong ulong;
typedef Adesk::Int8 Int8;
typedef Adesk::Int16 Int16;
typedef Adesk::Int32 Int32;
typedef Adesk::UInt8 UInt8;
typedef Adesk::UInt16 UInt16;
typedef Adesk::UInt32 UInt32;
#endif //__cplusplus

typedef char LEGACY_CHAR;
typedef char* LEGACY_STRING;
typedef char* MEMORY_POINTER;
typedef const char* LEGACY_STRING_CONST;
typedef const char* MEMORY_POINTER_CONST;
typedef const unsigned short* WIDE_STRING_CONST;
typedef unsigned char AC_BYTE;
typedef unsigned long LCID;
typedef unsigned short WIDE_CHAR;
typedef unsigned short* WIDE_STRING;

#ifdef _WIN32
#define AdInt32  long
#else  // Linux, Mac
#define AdInt32  Adesk::Int32
#endif

#define ADESK_NO_VTABLE __declspec(novtable)
#define ADESK_STDCALL __stdcall

#define eNotImplemented eNotImplementedYet

#ifdef __cplusplus
// begin BRX specific
struct BricsCAD
{
    enum LicensedFeature
    {
        eCore = 0, //minimum requirement for BRX apps
        eCommunicator = 1,
        eBim = 2,
        eMechanical = 3,
        eLastLicense,

        //deprecated values from pre-V22 LicenseMode enum
        eStandard = eCore,
        ePlatinumLicense = eCore,
        eCommunicatorLicense = eCommunicator,
        eBimLicense = eBim,
        eSheetMetalLicense = eMechanical,
    };
};
// end BRX specific

struct Acad
{
    enum ErrorStatus
    {
        eOk = 0,
        eNotImplementedYet,
        eNotApplicable,
        eInvalidInput,
        eAmbiguousInput,
        eAmbiguousOutput,
        eOutOfMemory,
        eBufferTooSmall,
        eInvalidOpenState,
        eEntityInInactiveLayout,
        eHandleExists,
        eNullHandle,
        eBrokenHandle,
        eUnknownHandle,
        eHandleInUse,
        eNullObjectPointer,
        eNullObjectId,
        eNullBlockName,
        eContainerNotEmpty,
        eNullEntityPointer = 20,
        eIllegalEntityType,
        eKeyNotFound,
        eDuplicateKey,
        eInvalidIndex,
        eDuplicateIndex,
        eAlreadyInDb,
        eOutOfDisk,
        eDeletedEntry,
        eNegativeValueNotAllowed,
        eInvalidExtents,
        eInvalidAdsName,
        eInvalidSymbolTableName,
        eInvalidKey,
        eWrongObjectType,
        eWrongDatabase,
        eObjectToBeDeleted,
        eInvalidDwgVersion,
        eAnonymousEntry,
        eIllegalReplacement,
        eEndOfObject,
        eEndOfFile,
        eIsReading,
        eIsWriting,
        eNotOpenForRead,
        eNotOpenForWrite,
        eNotThatKindOfClass,
        eInvalidBlockName,
        eMissingDxfField,
        eDuplicateDxfField,
        eInvalidDxfCode,
        eInvalidResBuf,
        eBadDxfSequence,
        eFilerError,
        eVertexAfterFace,
        eInvalidFaceVertexIndex,
        eInvalidMeshVertexIndex,
        eOtherObjectsBusy,
        eMustFirstAddBlockToDb,
        eCannotNestBlockDefs,
        eDwgRecoveredOK,
        eDwgNotRecoverable,
        eDxfPartiallyRead,
        eDxfReadAborted,
        eDxbPartiallyRead,
        eDwgCRCDoesNotMatch,
        eDwgSentinelDoesNotMatch,
        eDwgObjectImproperlyRead,
        eNoInputFiler,
        eDwgNeedsAFullSave,
        eDxbReadAborted,
        eFileLockedByACAD,
        eFileAccessErr,
        eFileSystemErr,
        eFileInternalErr,
        eFileTooManyOpen,
        eFileNotFound,
        eDwkLockFileFound,
        eWasErased = 80,
        ePermanentlyErased,
        eWasOpenForRead,
        eWasOpenForWrite,
        eWasOpenForUndo,
        eWasNotifying,
        eWasOpenForNotify,
        eOnLockedLayer,
        eMustOpenThruOwner,
        eSubentitiesStillOpen,
        eAtMaxReaders,
        eIsWriteProtected,
        eIsXRefObject,
        eNotAnEntity,
        eHadMultipleReaders,
        eDuplicateRecordName,
        eXRefDependent,
        eSelfReference,
        eMissingSymbolTable,
        eMissingSymbolTableRec,
        eWasNotOpenForWrite,
        eCloseWasNotifying,
        eCloseModifyAborted,
        eClosePartialFailure,
        eCloseFailObjectDamaged,
        eCannotBeErasedByCaller,
        eCannotBeResurrected,
        eWasNotErased,
        eInsertAfter = 110,
        eFixedAllErrors = 120,
        eLeftErrorsUnfixed = 122,
        eUnrecoverableErrors,
        eNoDatabase,
        eXdataSizeExceeded,
        eRegappIdNotFound,
        eRepeatEntity,
        eRecordNotInTable,
        eIteratorDone,
        eNullIterator,
        eNotInBlock,
        eOwnerNotInDatabase,
        eOwnerNotOpenForRead,
        eOwnerNotOpenForWrite,
        eExplodeBeforeTransform,
        eCannotScaleNonUniformly,
        eNotInDatabase,
        eNotCurrentDatabase,
        eIsAnEntity,
        eCannotChangeActiveViewport,
        eNotInPaperspace,
        eCommandWasInProgress,
        eGeneralModelingFailure = 150,
        eOutOfRange,
        eNonCoplanarGeometry,
        eDegenerateGeometry,
        eInvalidAxis,
        ePointNotOnEntity,
        eSingularPoint,
        eInvalidOffset,
        eNonPlanarEntity,
        eCannotExplodeEntity,
        eStringTooLong,
        eInvalidSymTableFlag,
        eUndefinedLineType,
        eInvalidTextStyle,
        eTooFewLineTypeElements,
        eTooManyLineTypeElements,
        eExcessiveItemCount,
        eIgnoredLinetypeRedef,
        eBadUCS,
        eBadPaperspaceView,
        eSomeInputDataLeftUnread,
        eNoInternalSpace,
        eInvalidDimStyle,
        eInvalidLayer,
        eUserBreak = 180,
        eUserUnloaded,
        eDwgNeedsRecovery = 190,
        eDeleteEntity,
        eInvalidFix,
        eFSMError,
        eBadLayerName = 200,
        eLayerGroupCodeMissing,
        eBadColorIndex,
        eBadMaterialName,
        eBadLinetypeName,
        eBadLinetypeScale,
        eBadVisibilityValue,
        eProperClassSeparatorExpected,
        eBadLineWeightValue,
        eBadColor,
        ePagerError = 210,
        eOutOfPagerMemory,
        ePagerWriteError,
        eWasNotForwarding,
        eInvalidIdMap = 220,
        eInvalidOwnerObject,
        eOwnerNotSet,
        eWrongSubentityType = 230,
        eTooManyVertices,
        eTooFewVertices,
        eNoActiveTransactions = 250,
        eNotTopTransaction,
        eTransactionOpenWhileCommandEnded,
        eInProcessOfCommitting,
        eNotNewlyCreated,
        eLongTransReferenceError,
        eNoWorkSet,
        eAlreadyInGroup = 260,
        eNotInGroup,
        eAlreadyInferred,
        eInvalidREFIID = 290,
        eInvalidNormal,
        eInvalidStyle,
        eCannotRestoreFromAcisFile = 300,
        eMakeMeProxy,
        eNLSFileNotAvailable,
        eNotAllowedForThisProxy,
        eNotClonedPrimaryProxy,
        eNotSupportedInDwgApi = 310,
        ePolyWidthLost,
        eNullExtents,
        eExplodeAgain,
        eBadDwgHeader,
        eLockViolation = 320,
        eLockConflict,
        eDatabaseObjectsOpen,
        eLockChangeInProgress,
        eVetoed = 325,
        eNoDocument = 330,
        eNotFromThisDocument,
        eLISPActive,
        eTargetDocNotQuiescent,
        eDocumentSwitchDisabled,
        eInvalidContext,
        eCreateFailed = 337,
        eCreateInvalidName,
        eSetFailed = 340,
        eDelDoesNotExist = 342,
        eDelIsModelSpace,
        eDelLastLayout,
        eDelUnableToSetCurrent,
        eDelUnableToFind,
        eRenameDoesNotExist = 348,
        eRenameIsModelSpace,
        eRenameInvalidLayoutName,
        eRenameLayoutAlreadyExists,
        eRenameInvalidName,
        eCopyDoesNotExist = 354,
        eCopyIsModelSpace,
        eCopyFailed,
        eCopyInvalidName,
        eCopyNameExists,
        eProfileDoesNotExist,
        eInvalidFileExtension,
        eInvalidProfileName,
        eFileExists,
        eProfileIsInUse,
        eCantOpenFile,
        eNoFileName,
        eRegistryAccessError,
        eRegistryCreateError,
        eBadDxfFile,
        eUnknownDxfFileFormat,
        eMissingDxfSection,
        eInvalidDxfSectionName,
        eNotDxfHeaderGroupCode,
        eUndefinedDxfGroupCode,
        eNotInitializedYet,
        eInvalidDxf2dPoint,
        eInvalidDxf3dPoint,
        eBadlyNestedAppData = 378,
        eIncompleteBlockDefinition,
        eIncompleteComplexObject,
        eBlockDefInEntitySection,
        eNoBlockBegin,
        eDuplicateLayerName,
        eBadPlotStyleName,
        eDuplicateBlockName,
        eBadPlotStyleType,
        eBadPlotStyleNameHandle,
        eUndefineShapeName,
        eDuplicateBlockDefinition,
        eMissingBlockName,
        eBinaryDataSizeExceeded,
        eObjectIsReferenced,
        eNoThumbnailBitmap,
        eGuidNoAddress,
        eMustBe0to2,
        eMustBe0to3,
        eMustBe0to4,
        eMustBe0to5,
        eMustBe0to8,
        eMustBe1to8,
        eMustBe1to15,
        eMustBePositive,
        eMustBeNonNegative,
        eMustBeNonZero,
        eMustBe1to6,
        eNoPlotStyleTranslationTable,
        ePlotStyleInColorDependentMode,
        eMaxLayouts,
        eNoClassId,
        eUndoOperationNotAvailable,
        eUndoNoGroupBegin,
        eHatchTooDense = 420,
        eOpenFileCancelled = 430,
        eNotHandled,
        eMakeMeProxyAndResurrect,
        eFileSharingViolation,
        eUnsupportedFileFormat,
        eObsoleteFileFormat,
        eFileMissingSections,
        eRepeatedDwgRead,
        eSilentOpenFileCancelled,
        eWrongCellType = 440,
        eCannotChangeColumnType,
        eRowsMustMatchColumns,
        eNullNodeId = 450,
        eNoNodeActive,
        eGraphContainsProxies,
        eDwgShareDemandLoad = 500,
        eDwgShareReadAccess,
        eDwgShareWriteAccess,
        eLoadFailed,
        eDeviceNotFound,
        eNoCurrentConfig,
        eNullPtr,
        eNoLayout,
        eIncompatiblePlotSettings,
        eNonePlotDevice,
        eNoMatchingMedia,
        eInvalidView,
        eInvalidWindowArea,
        eInvalidPlotArea,
        eCustomSizeNotPossible,
        ePageCancelled,
        ePlotCancelled,
        eInvalidEngineState,
        ePlotAlreadyStarted,
        eNoErrorHandler,
        eInvalidPlotInfo,
        eNumberOfCopiesNotSupported,
        eLayoutNotCurrent,
        eGraphicsNotGenerated,
        eCannotPlotToFile,
        eMustPlotToFile,
        eNotMultiPageCapable,
        eBackgroundPlotInProgress,
        eNotShownInPropertyPalette,
        eSubSelectionSetEmpty = 550,
        eNoIntersections,
        eEmbeddedIntersections,
        // Layer property overrides
        eNoOverride = 570,
        eNoStoredOverrides,
        eUnableToRetrieveOverrides,
        eUnableToStoreOverrides,
        eUnableToRemoveOverrides,
        eNoStoredReconcileStatus = 580,
        eUnableToStoreReconcileStatus,
        eInvalidObjectId = 600,
        eInvalidXrefObjectId,
        eNoViewAssociation,
        eNoLabelBlock,
        eUnableToSetViewAssociation,
        eUnableToGetViewAssociation,
        eUnableToSetLabelBlock,
        eUnableToGetLabelBlock,
        eUnableToRemoveAssociation,
        eUnableToSyncModelView,
        eDataLinkAdapterNotFound = 650,
        eDataLinkInvalidAdapterId,
        eDataLinkNotFound,
        eDataLinkBadConnectionString,
        eDataLinkNotUpdatedYet,
        eDataLinkSourceNotFound,
        eDataLinkConnectionFailed,
        eDataLinkSourceUpdateNotAllowed,
        eDataLinkSourceIsWriteProtected,
        eDataLinkExcelNotFound,
        eDataLinkOtherError,
        eXrefReloaded = 700,
        eXrefReloadImpossibleAtThisTime,
        eSecInitializationFailure = 1001,
        eSecErrorReadingFile,
        eSecErrorWritingFile,
        eSecInvalidDigitalID = 1101,
        eSecErrorGeneratingTimestamp,
        eSecErrorComputingSignature,
        eSecErrorWritingSignature,
        eSecErrorEncryptingData = 1201,
        eSecErrorCipherNotSupported,
        eSecErrorDecryptingData,
        eNoAcDbHostApplication = 1300,
        eNoUnderlayHost,
        ePCUnknown = 1400,
        ePCLargeData,
        ePCUnknownFileType,
        ePCFileNotFound,
        ePCFileNotCreated,
        ePCFileNotOpened,
        ePCFileNotClosed,
        ePCFileNotWritten,
        ePCFileWrongFormat,
        ePCFileDataSelectorInvalid,
        ePCCoordSysReprojectFail,
        ePCDiskSpaceTooSmall,
        ePCThreadTerminated,
        ePCFileNotErased,
        ePCCoordSysAssignFail,
        ePCLastImporterUnfinished,
        ePCNoEngineInfo,
        ePCInProgress,

        eInetBase = 20000,
        eInetOk = 20000,
        eInetInCache,
        eInetFileNotFound,
        eInetBadPath,
        eInetTooManyOpenFiles,
        eInetFileAccessDenied,
        eInetInvalidFileHandle,
        eInetDirectoryFull,
        eInetHardwareError,
        eInetSharingViolation,
        eInetDiskFull,
        eInetFileGenericError,
        eInetValidURL,
        eInetNotAnURL,
        eInetNoWinInet,
        eInetOldWinInet,
        eInetNoAcadInet,
        eInetNotImplemented,
        eInetProtocolNotSupported,
        eInetCreateInternetSessionFailed,
        eInetInternetSessionConnectFailed,
        eInetInternetSessionOpenFailed,
        eInetInvalidAccessType,
        eInetFileOpenFailed,
        eInetHttpOpenRequestFailed,
        eInetUserCancelledTransfer,
        eInetHttpBadRequest,
        eInetHttpAccessDenied,
        eInetHttpPaymentRequired,
        eInetHttpRequestForbidden,
        eInetHttpObjectNotFound,
        eInetHttpBadMethod,
        eInetHttpNoAcceptableResponse,
        eInetHttpProxyAuthorizationRequired,
        eInetHttpTimedOut,
        eInetHttpConflict,
        eInetHttpResourceGone,
        eInetHttpLengthRequired,
        eInetHttpPreconditionFailure,
        eInetHttpRequestTooLarge,
        eInetHttpUriTooLong,
        eInetHttpUnsupportedMedia,
        eInetHttpServerError,
        eInetHttpNotSupported,
        eInetHttpBadGateway,
        eInetHttpServiceUnavailable,
        eInetHttpGatewayTimeout,
        eInetHttpVersionNotSupported,
        eInetInternetError,
        eInetGenericException,
        eInetUnknownError,
        eAlreadyActive,
        eAlreadyInactive,
        eGraphEdgeNotFound,
        eGraphNodeNotFound,
        eGraphNodeAlreadyExists,
        eGraphEdgeAlreadyExists,
        eGraphCyclesFound,
        eAlreadyHasRepresentation,
        eNoRepresentation,
        eFailedToSetEdgeChamfers,
        eNoConnectedBlendSet,
        eFailedToBlend,
        eFailedToSetEdgeRounds,
        eFailedToSetVertexRounds,
        eVSNotFound,
        eVSTrue,
        eVSFalse,
        eVSAlreadyExists,
        eVSOneOffCreated,
        eVSAPIOnlyValues,
        eVSIsInUse,
        eVSIsAcadDefault,
        eEmptyOperand,
        eNoEntitiesFromPersistentIds,
        eFailedCurveCheck,
        eMaxNodes,
        eFailedToEvaluate,
        eFailedToEvaluateDependents,
        eInvalidExpression,
        eCyclicDependency,
        eInconsistentConstraint,
        eOverDefinedConstraint,
        eAllInSameRigidSet,
        eInvalidParameterName,
        eReferencedInEquation,
        eEntityRestricedInDOF,
        eDataTooLarge,
        eNearSizeLimit,
        eStringNotAllowedInExpression,
        eTooManyActiveCommands,
        eUnableToTrimLastPiece,
        eUnableToTrimSurface,
        eModifyingAssociativeEntity,
        eModifyingDimensionWithExpression,
        eDependentOnObjectErased,
        eSelfIntersecting,
        eNotOnBoundary,
        eNotConnected,
        eNoInputPath,
        eNotAssociative,
        eNotG1Continuous,
        eOwnerToBeTransformed,
        eMustBeInteger,
        eMustBePositiveInteger,
        eChangedAgainstAssociativity,
        eItemCountChanged,
        eGetAdIntImgServicesFailed,
        eReadImageBufferFailed,
        eWriteImageBufferFailed,
        eGetImageBytesFailed,
        eGetImageDIBFailed,
        eConvertImageFormatFailed,
        eGetPreviewImageFailed,
        eInvalidPreviewImage,
        eDelayMore,
        ePreviewFailed,
        eAbortPreview,
        eEndPreview,
        eNoPreviewContext,
        eFileNotInCloud,
        // BRX specific
        eInvalidLicense,
    };

    enum PointHistory
    {
        eDidNotPick = 0,
        eTablet = 1,
        eNotDigitizer = 2,
        eLastPt = 4,
        eGripped = 8,
        eCartSnapped = 16,
        eOrtho = 32,
        eCyclingPt = 64,
        eOsnapped = 128,
        ePolarAngle = 256,
        eAligned = 1024,
        eAppFiltered = 2048,
        eForcedPick = 4096,
        eUsedPickBox = 8192,
        eUsedOsnapBox = 16384,
        ePickAborted = 32768,
        ePickMask = 57344,
        eXPending = 65536,
        eYPending = 131072,
        eZPending = 262144,
        eCoordPending = 458752,
        eFromKeyboard = 524288,
        eNotInteractive = 1048576,
        eDirectDistance = 2097152,
        eGizmoConstrainted = 4194304,
    };

    enum PromptStatus
    {
        eDirect = -5999,
        eKeyword = -5005,
        eFailed = -5004,
        eRejected = -5003,
        eCancel = -5002,
        eError = -5001,
        eNone = 5000,
        eNormal = 5100,
        eModeless =  5027,
    };
};
#endif //__cplusplus

#ifdef __cplusplus
extern "C"
{
#endif //__cplusplus
    ACHAR* acad__strdup(const ACHAR*);
    size_t acad__msize(void*);
    void acad_free(void*);
    void acad__assert(const ACHAR*,const ACHAR*,int);
    void* acad_calloc(size_t,size_t);
    void* acad_malloc(size_t);
    void* acad_realloc(void*,size_t);
#ifdef __cplusplus
}
#endif //__cplusplus

#ifdef __cplusplus
struct AcadApp
{
    enum ErrorStatus
    {
        eOk = 0,
        eInvalidKey,
        eInvalidSubKey,
        eKeyNotFound,
        eOutOfMemory,
        eInvalidValue,
        eValueNotFound,
        eKeyExists,
        eRegAccessDenied,
        eRejected,
        eUnknownError
    };

    enum LoadReasons
    {
        kOnProxyDetection = 1,
        kOnAutoCADStartup = 2,
        kOnCommandInvocation = 4,
        kOnLoadRequest = 8,
        kLoadDisabled = 16,
        kTransparentlyLoadable = 32
    };
};
#endif //__cplusplus

enum AcXrefSubCommand
{
    kAttach = 0,
    kBind,
    kDetach,
    kOverlay,
    kPath,
    kReload,
    kResolve,
    kUnload,
    kXBind
};

#define AC_SRCH_BLOCK 1
#define AC_SRCH_DIM_TEXT 2
#define AC_SRCH_TEXT 4
#define AC_SRCH_LINK_DESC 8
#define AC_SRCH_LINK_URL 16
#define AC_SRCH_DEFAULT 31
#define AC_SRCH_MATCH_CASE 32
#define AC_SRCH_WHOLE_WORD 64

#ifdef __cplusplus
bool c4ObjIdIsEqualTo(ULONG_PTR,ULONG_PTR);
bool c4ObjIdNotEqualTo(ULONG_PTR,ULONG_PTR);
bool c4ObjIdIsLessThan(ULONG_PTR,ULONG_PTR);
bool c4ObjIdLessThanOrEqual(ULONG_PTR,ULONG_PTR);
bool c4ObjIdIsGreaterThan(ULONG_PTR,ULONG_PTR);
bool c4ObjIdGreaterThanOrEqual(ULONG_PTR,ULONG_PTR);
bool c5ObjIdIsEqualTo(const AcDbStub*,const AcDbStub*);
bool c5ObjIdIsLessThan(const AcDbStub*,const AcDbStub*);
bool c5ObjIdLessThanOrEqual(const AcDbStub*,const AcDbStub*);
bool c5ObjIdIsGreaterThan(const AcDbStub*,const AcDbStub*);
bool c5ObjIdGreaterThanOrEqual(const AcDbStub*,const AcDbStub*);
#endif //__cplusplus

enum
{
    SECURITYPARAMS_ENCRYPT_DATA = 1,
    SECURITYPARAMS_ENCRYPT_PROPS = 2,
    SECURITYPARAMS_SIGN_DATA = 16,
    SECURITYPARAMS_ADD_TIMESTAMP = 32,
    SECURITYPARAMS_ALGID_RC4 = 26625
};

struct SecurityParams
{
    ACHAR* wszCertIssuer;
    ACHAR* wszCertSerialNum;
    ACHAR* wszCertSubject;
    ACHAR* wszComment;
    ACHAR* wszPassword;
    ACHAR* wszProvName;
    ACHAR* wszTimeServer;
    unsigned long cbSize;
    unsigned long ulAlgId;
    unsigned long ulFlags;
    unsigned long ulKeyLength;
    unsigned long ulProvType;
};

#ifdef __cplusplus
Acad::ErrorStatus applyCurDwgLayerTableChanges();
#endif //__cplusplus

enum undoSubcommandActivities
{
    kNone = 0,
    kOne,
    kAll
};

enum xrefSubcommandActivities
{
    kStart = 0,
    kStartItem = 2,
    kEndItem,
    kEnd,
    kWillAbort,
    kAborted,
    kStartXBindBlock,
    kStartXBindSymbol
};

enum AcadContextMenuMode
{
    kDefault = 0,
    kEdit,
    kCommand,
    kHotGrip,
    kOsnap
};

enum code_page_id
{
    CODE_PAGE_UNDEFINED = 0,
    CODE_PAGE_ASCII,
    CODE_PAGE_8859_1,
    CODE_PAGE_8859_2,
    CODE_PAGE_8859_3,
    CODE_PAGE_8859_4,
    CODE_PAGE_8859_5,
    CODE_PAGE_8859_6,
    CODE_PAGE_8859_7,
    CODE_PAGE_8859_8,
    CODE_PAGE_8859_9,
    CODE_PAGE_DOS437,
    CODE_PAGE_DOS850,
    CODE_PAGE_DOS852,
    CODE_PAGE_DOS855,
    CODE_PAGE_DOS857,
    CODE_PAGE_DOS860,
    CODE_PAGE_DOS861,
    CODE_PAGE_DOS863,
    CODE_PAGE_DOS864,
    CODE_PAGE_DOS865,
    CODE_PAGE_DOS869,
    CODE_PAGE_DOS932,
    CODE_PAGE_MACINTOSH,
    CODE_PAGE_BIG5,
    CODE_PAGE_KSC5601,
    CODE_PAGE_JOHAB,
    CODE_PAGE_DOS866,
    CODE_PAGE_ANSI_1250,
    CODE_PAGE_ANSI_1251,
    CODE_PAGE_ANSI_1252,
    CODE_PAGE_GB2312,
    CODE_PAGE_ANSI_1253,
    CODE_PAGE_ANSI_1254,
    CODE_PAGE_ANSI_1255,
    CODE_PAGE_ANSI_1256,
    CODE_PAGE_ANSI_1257,
    CODE_PAGE_ANSI_874,
    CODE_PAGE_ANSI_932,
    CODE_PAGE_ANSI_936,
    CODE_PAGE_ANSI_949,
    CODE_PAGE_ANSI_950,
    CODE_PAGE_ANSI_1361,
    CODE_PAGE_ANSI_1200,
    CODE_PAGE_ANSI_1258,
    CODE_PAGE_CNT
};

enum Charset
{
    kUndefinedCharset = -1,
    kAnsiCharset = 0,
    kUnicodeCharset = 1,
    kSymbolCharset = 2,
    kJapaneseCharset = 128,
    kKoreanCharset = 129,
    kChineseSimpCharset = 134,
    kChineseTradCharset = 136,
    kJohabCharset = 130,
    kHebrewCharset = 177,
    kArabicCharset = 178,
    kGreekCharset = 161,
    kTurkishCharset = 162,
    kVietnameseCharset = 163,
    kThaiCharset = 222,
    kEastEuropeCharset = 238,
    kRussianCharset = 204,
    kBalticCharset = 186,
    kDefaultCharset = kUnicodeCharset,
    kINTERNALCHARSET = 256,
    kBengaliCharset = kINTERNALCHARSET,
    kGurmukhiCharset,
    kGujaratiCharset,
    kTamilCharset,
    kTeluguCharset,
    kKannadaCharset,
    kMalayalamCharset,
    kDevanagariCharset,
    kOriyaCharset,
    kMarathiCharset = kDevanagariCharset,
    kHindiCharset = kDevanagariCharset,
    kKonkaniCharset = kDevanagariCharset,
    kSanskritCharset = kDevanagariCharset,
    kPunjabiharset = kGurmukhiCharset,
    kAssameseCharset = kUnicodeCharset,
    kFinnishCharset = kUnicodeCharset,
    kBelgianCharset = kUnicodeCharset,
    kGeorgianCharset = kUnicodeCharset
};

#ifndef HIMAGELIST
struct _IMAGELIST;
typedef struct _IMAGELIST* HIMAGELIST;
#endif

enum AcSDIValues
{
    kMDIEnabled = 0,
    kSDIUserEnforced,
    kSDIAppEnforced,
    kSDIUserAndAppEnforced
};

enum ProdIdCode
{
    kProd_ACAD = 1,
    kProd_LT,
    kProd_OEM,
    kProd_AcDb
};

enum ClassVersion
{
    kVersion1 = 0,
    kVersion2,
    kVersion3
};

#ifdef __cplusplus

const double kEpsilon = 1.e-7;

struct Mline
{
    enum
    {
        kTop = 0,
        kZero,
        kBottom
    };

    enum
    {
        kOpen = 0,
        kClosed,
        kMerged
    };

    typedef Adesk::Int8 MlineJustification;
};

AcGeVector3d ucsXDir();
AcGeVector3d ucsYDir();
void ucsNormalVector(AcGeVector3d&);

const ACHAR* acadErrorStatusText(Acad::ErrorStatus);

AcApProfileManager* acProfileManagerPtr();
#define acProfileManager acProfileManagerPtr()

CAcGradientThumbnailEngine* createGradientThumbnailEngine();

#endif //__cplusplus

enum eClipInfoFlags
{
    kbDragGeometry = 1
};

enum eExpandedClipDataTypes
{
    kDcPlotStyles = 1,
    kDcXrefs,
    kDcLayouts,
    kDcBlocks,
    kDcLayers,
    kDcDrawings,
    kDcLinetypes,
    kDcTextStyles,
    kDcDimStyles,
    kDcBlocksWithAttdef,
    kDcHatches,
    kTpXrefs,
    kTpImages,
    kTpTable,
    kDcTableStyles
};

#ifdef __cplusplus
typedef void (*ACGLOBADDDMMREACTOR)(AcDMMReactor*);
typedef void (*ACGLOBREMOVEDMMREACTOR)(AcDMMReactor*);
void AcGlobalAddDMMReactor(AcDMMReactor*);
void AcGlobalRemoveDMMReactor(AcDMMReactor*);

typedef void (*ACGLOBADDPUBLISHREACTOR)(AcPublishReactor*);
typedef void (*ACGLOBREMOVEPUBLISHREACTOR)(AcPublishReactor*);
void AcGlobAddPublishReactor(AcPublishReactor*);
void AcGlobRemovePublishReactor(AcPublishReactor*);

typedef void (*ACGLOBADDPUBLISHUIREACTOR)(AcPublishUIReactor*);
typedef void (*ACGLOBREMOVEPUBLISHUIREACTOR)(AcPublishUIReactor*);
void AcGlobAddPublishUIReactor(AcPublishUIReactor*);
void AcGlobRemovePublishUIReactor(AcPublishUIReactor*);
#endif //__cplusplus

#define WM_ACAD_KEEPFOCUS 28929

#ifdef __cplusplus
Acad::ErrorStatus addSSgetFilterInputContextReactor(AcApDocument*,AcEdSSGetFilter*);
Acad::ErrorStatus addSSgetFilterInputContextReactor(AcApDocument*,AcEdSSGetFilter2*);
Acad::ErrorStatus addSSgetFilterInputContextReactor(AcApDocument*,AcEdSSGetSubSelectFilter*);
Acad::ErrorStatus removeSSgetFilterInputContextReactor(AcApDocument*,AcEdSSGetFilter*);
Acad::ErrorStatus removeSSgetFilterInputContextReactor(AcApDocument*,AcEdSSGetFilter2*);
Acad::ErrorStatus removeSSgetFilterInputContextReactor(AcApDocument*,AcEdSSGetSubSelectFilter*);
typedef unsigned char boolean;
Acad::ErrorStatus setAllowDuplicateSelection(AcApDocument*,boolean);
bool duplicateSelectionsAllowed(AcApDocument*);

unsigned acCheckCFileCharFormat(CFile*);
bool acReadAnsiCharFromCFile(CFile*,wchar_t&,AdCharFormatter*);
bool acReadCIFFromCFile(CFile*,wchar_t&);
bool acReadUtf16CharFromCFile(CFile*,wchar_t&,AdCharFormatter*);
bool acReadUtf8CharFromCFile(CFile*,wchar_t&,AdCharFormatter*);
void acByteSwap(wchar_t&);
void acWriteWCharToCFile(wchar_t,CFile*,unsigned,bool);
void acWriteWCharToCFile(wchar_t,CFile*,const AdCharFormatter&);

int AcFStream_wideToMulti(const wchar_t*,int,char*,int);
std::locale AcFStream_curLocale();

AdHostImageAppServices* getAdHostImageAppServices();

AcApDocument* curDoc();

// begin BRX specific
bool isLicenseAvailable(BricsCAD::LicensedFeature feature);
// end BRX specific
#endif //__cplusplus

enum AcDefaultPane
{
    ACSBPANE_APP_MODEMACRO = 0,
    ACSBPANE_APP_CURSORCOORD,
    ACSBPANE_APP_SNAP,
    ACSBPANE_APP_GRID,
    ACSBPANE_APP_ORTHO,
    ACSBPANE_APP_POLAR,
    ACSBPANE_APP_OTRACK,
    ACSBPANE_APP_LINEWEIGHT,
    ACSBPANE_APP_PAPERMODEL,
    ACSBPANE_APP_PAPER,
    ACSBPANE_APP_MODEL,
    ACSBPANE_APP_OSNAP,
    ACSBPANE_APP_FLOAT,
    ACSBPANE_APP_TABLET,
    ACSBPANE_APP_SPACER,
    ACSBPANE_APP_VPMAX_PREV,
    ACSBPANE_APP_VPMAX,
    ACSBPANE_APP_VPMAX_NEXT,
    ACSBPANE_APP_DYNINPUT,
    ACSBPANE_APP_DYNAMICUCS,
    ACSBPANE_APP_LAYOUTMODELICONS,
    ACSBPANE_APP_MODEL_ICON,
    ACSBPANE_APP_LAYOUT_ICON,
    ACSBPANE_APP_LAYOUTMORE_ICON, //deprecated
    ACSBPANE_APP_ALL,
    ACSBPANE_ANNO_STRETCH,
    ACSBPANE_ANNO_AUTOSCALE,
    ACSBPANE_ANNO_VIEWPORT_SCALE_LABEL, //deprecated
    ACSBPANE_ANNO_VIEWPORT_SCALE,
    ACSBPANE_ANNO_VIEWPORT_LOCK_STATE,
    ACSBPANE_ANNO_ANNOTATION_SCALE_LABEL, //deprecated
    ACSBPANE_ANNO_ANNOTATION_SCALE,
    ACSBPANE_ANNO_ANNO_ALL_VISIBLE,
    ACSBPANE_ANNO_EMPTY,
    ACSBPANE_APP_STRETCH,
    ACSBPANE_APP_WORKSPACE,
    ACSBPANE_APP_WORKSPACE_LOCK,
    ACSBPANE_APP_QPROPERTIES,
    ACSBPANE_ANNO_SYNCHSCALES,
    ACSBPANE_APP_QV_LAYOUTS,
    ACSBPANE_APP_QV_DRAWINGS,
    ACSBPANE_APP_QV_SPACER, //deprecated
    ACSBPANE_APP_QV_PAN, //deprecated
    ACSBPANE_APP_QV_ZOOM, //deprecated
    ACSBPANE_APP_QV_STEERINGWHEEL, //deprecated
    ACSBPANE_APP_QV_SHOWMOTION, //deprecated
    ACSBPANE_APP_QV_ANNO_SPACER,
    ACSBPANE_APP_3DOSNAP,
    ACSBPANE_APP_WORKSPACE_PERFORMANCE,
    ACSBPANE_APP_SELECTIONCYCLING,
    ACSBPANE_APP_TRANSPARENCY,
    ACSBPANE_APP_INFER,
    ACSBPANE_APP_ANNOMONITOR,
    ACSBPANE_APP_SELECTION_FILTER,
    ACSBPANE_APP_GIZMO,
    ACSBPANE_APP_UNITS,
    ACSBPANE_APP_GEO_SPACER,
    ACSBPANE_APP_GEO_MARKERVISIBILITY,
    ACSBPANE_APP_GEO_COORDSYS,
    ACSBPANE_APP_ISODRAFT,
    ACSBPANE_APP_HARDWAREACCELERATION,
    ACSBPANE_APP_ADD_CLEANSCREEN,
    ACSBPANE_APP_ADD_CUSTOMIZATION,
    ACSBPANE_MAX
};

#define OL_GOOD 0
#define OL_ESNVALID 1
#define OL_ENAMEVALID 2
#define OL_ESSMAX 3
#define OL_ESSVALID 4
#define OL_EBDEVALID 5
#define OL_EXDEVALID 6
#define OL_ENTSELPICK 7
#define OL_EEOEF 8
#define OL_EEOBD 9
#define OL_EEMPDB 10
#define OL_EDELVPORT 11
#define OL_EACQPLINE 12
#define OL_EHANDLE 13
#define OL_ENOHAND 14
#define OL_ETRANS 15
#define OL_EXSPACE 16
#define OL_EDELENT 17
#define OL_ETBLNAME 18
#define OL_ETBLARG 19
#define OL_ERDONLY 20
#define OL_ENONZERO 21
#define OL_ERANGE 22
#define OL_ERGBUSY 23
#define OL_EMMTYPE 24
#define OL_EMMLAY 25
#define OL_EMMLT 26
#define OL_EMMCOLOR 27
#define OL_EMMSTYLE 28
#define OL_EMMSHAPE 29
#define OL_EMMFTYPE 30
#define OL_EMODDEL 31
#define OL_EMODSEQ 32
#define OL_EMODHAND 33
#define OL_EMODVPVIS 34
#define OL_EMMLL 35
#define OL_EMKTYPE 36
#define OL_EMKPLINE 37
#define OL_EMKCMPLX 38
#define OL_EMKBNAME 39
#define OL_EMKBFLAG 40
#define OL_EMKDBNAME 41
#define OL_EMKNORM 42
#define OL_EMKNOBNM 43
#define OL_EMKNOBFLG 44
#define OL_EMKANON 45
#define OL_EMKBLOCK 46
#define OL_EMKMANDF 47
#define OL_EMMXDTYPE 48
#define OL_EMMXDNEST 49
#define OL_EMMXDAPPID 50
#define OL_EMMXDSIZE 51
#define OL_ENTSELNULL 52
#define OL_EMXDAPPID 53
#define OL_EMMVPORT 54
#define OL_INVEXT 55
#define OL_EFLTR1 56
#define OL_EFLTR2 57
#define OL_EFLTR3 58
#define OL_EFLTR4 59
#define OL_EFLTR5 60
#define OL_EFLTR6 61
#define OL_EFLTR7 62
#define OL_EFLTR8 63
#define OL_EFLTR9 64
#define OL_EFLTR10 65
#define OL_EFLTR11 66
#define OL_EFLTR12 67
#define OL_TABNOT 68
#define OL_TABNOCAL 69
#define OL_TABERR 70
#define OL_ENEWRB 71
#define OL_ENULLPTR 72
#define OL_EOPEN 73
#define OL_ELOADED 74
#define OL_EMAXAPP 75
#define OL_EEXEC 76
#define OL_EVERSION 77
#define OL_EDENIED 78
#define OL_EREFUSE 79
#define OL_ENOTLOADED 80
#define OL_ENOMEM 81
#define OL_EXFMVALID 82
#define OL_ESYMNAM 83
#define OL_ESYMVAL 84
#define OL_NONDIALOG 85
#define OL_ECMDINP 92
#define OL_EBADTYPE 93
#define OL_EBADVPID 94
#define OL_EBADVIEW 95
#define OL_EGCODE 96
#define OL_EGDUP 97
#define OL_EBADSSMOD 98
#define OL_EARGMATCH 99
#define OL_SVRECURSE 100
#define OL_MODOPEN 101
#define OL_NOTENTITY 102
#define OL_BADPLMOD 103
#define OL_BADCTLSTR 104
#define OL_EXDICT_PR 105
#define MAX_OL_ERRNO 105

//BRX START
#ifndef BRX_API
  #ifdef _WIN32 // Windows
    #pragma comment(lib ,"brx23.lib")
    #pragma comment(lib ,"drx_entrypoint.lib")
    #pragma comment(lib ,"TD_Root.lib")
    #pragma comment(lib ,"TD_Alloc.lib")
    #ifndef _OD_RXDYNAMICMODULE_H_ // if ODA module was not yet included
      #ifdef __SYS_64_BIT__
        #pragma comment(linker ,"/EXPORT:odrxCreateModuleObject,PRIVATE")
        #pragma comment(linker ,"/EXPORT:odrxGetAPIVersion,PRIVATE")
      #else
        #pragma comment(linker ,"/EXPORT:_odrxCreateModuleObject,PRIVATE")
        #pragma comment(linker ,"/EXPORT:_odrxGetAPIVersion,PRIVATE")
      #endif
    #endif  // _OD_RXDYNAMICMODULE_H_
  #else  // Linux/Mac
  #endif
#endif

#define PlotPaperUnits BRX_PlotPaperUnits
#define PlotRotation BRX_PlotRotation
#define PlotType BRX_PlotType
#define StdScaleType BRX_StdScaleType
//BRX END

#pragma pack(pop)
