// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include <share.h> //_SH_DENYWR

#include "AcGe/AcGeContext.h"
#include "AcDb/AcDbBoiler.h"
#include "AcDb/AcDbObjectId.h"
#include "AcFd/AcFdGlobal.h"
#include "Ads/AdsGlobal.h"
#include "Misc/AcArray.h"

#ifdef __cplusplus

//forward declarations, .cpp supported
//-------------------------------------------------------------------------------------------------------
class AcDb2dPolyline;
class AcDb2dVertex;
class AcDb3dPolylineVertex;
class AcDb3dSolid;
class AcDbAbstractViewTable;
class AcDbAbstractViewTableIterator;
class AcDbAbstractViewTableRecord;
class AcDbAppSystemVariables;
class AcDbAttribute;
class AcDbAttributeDefinition;
class AcDbAuditInfo;
class AcDbBlockBegin;
class AcDbBlockChangeIterator;
class AcDbBlockEnd;
class AcDbBlockReference;
class AcDbBlockReferenceIdIterator;
class AcDbBlockTable;
class AcDbBlockTableIterator;
class AcDbBlockTableRecord;
class AcDbBlockTableRecordIterator;
class AcDbBody;
class AcDbCurve;
class AcDbCustomOsnapManager;
class AcDbCustomOsnapMode;
class AcDbDatabase;
class AcDbDatabaseIterator;
class AcDbDatabaseReactor;
class AcDbDatabaseSummaryInfo;
class AcDbDate;
class AcDbDictionary;
class AcDbDictionaryIterator;
class AcDbDictionaryWithDefault;
class AcDbDimData;
class AcDbDimAssoc;
class AcDbDimStyleTable;
class AcDbDimStyleTableIterator;
class AcDbDimStyleTableRecord;
class AcDbDwgFiler;
class AcDbDxfFiler;
class AcDbDynBlockReference;
class AcDbDynBlockReferenceProperty;
class AcDbEllipse;
class AcDbEntity;
class AcDbEntityReactor;
class AcDbEvalConnectable;
class AcDbEvalContext;
class AcDbEvalContextIterator;
class AcDbEvalContextPair;
class AcDbEvalEdgeInfo;
class AcDbEvalExpr;
class AcDbEvalGraph;
class AcDbEvalVariant;
class AcDbExtents;
class AcDbFaceRecord;
class AcDbFcf;
class AcDbField;
class AcDbFilter;
class AcDbFilteredBlockIterator;
class AcDbFullSubentPath;
class AcDbGraph;
class AcDbGraphNode;
class AcDbGripData;
class AcDbGroup;
class AcDbGroupIterator;
class AcDbHandle;
class AcDbHardOwnershipId;
class AcDbHardPointerId;
class AcDbHatch;
class AcDbHostApplicationServices;
class AcDbHyperlink;
class AcDbHyperlinkCollection;
class AcDbIdMapping;
class AcDbIdMappingIter;
class AcDbIndexIterator;
class AcDbIndexUpdateData;
class AcDbLayerFilter;
class AcDbLayerStateManager;
class AcDbLayerTable;
class AcDbLayerTableIterator;
class AcDbLayerTableRecord;
class AcDbLayoutManager;
class AcDbLinetypeTable;
class AcDbLinetypeTableIterator;
class AcDbLinetypeTableRecord;
class AcDbLongTransaction;
class AcDbMline;
class AcDbMlineStyle;
class AcDbMText;
class AcDbObject;
class AcDbObjectId;
class AcDbObjectIdGraph;
class AcDbObjectIterator;
class AcDbObjectReactor;
class AcDbOle2Frame;
class AcDbPlotSettings;
class AcDbPlotSettingsValidator;
class AcDbPolyFaceMeshVertex;
class AcDbPolygonMeshVertex;
class AcDbRecover;
class AcDbRegAppTable;
class AcDbRegAppTableIterator;
class AcDbRegAppTableRecord;
class AcDbRegion;
class AcDbSectionManager;
class AcDbSequenceEnd;
class AcDbSoftOwnershipId;
class AcDbSoftPointerId;
class AcDbSortentsTable;
class AcDbSpatialFilter;
class AcDbSpline;
class AcDbStub;
class AcDbSubentId;
class AcDbSummaryInfoManager;
class AcDbSymbolTable;
class AcDbSymbolTableIterator;
class AcDbSymbolTableRecord;
class AcDbTableStyle;
class AcDbText;
class AcDbTextStyleTable;
class AcDbTextStyleTableIterator;
class AcDbTextStyleTableRecord;
class AcDbTransactionManager;
class AcDbUCSTable;
class AcDbUCSTableIterator;
class AcDbUCSTableRecord;
class AcDbUnderlayHost;
class AcDbVertex;
class AcDbViewport;
class AcDbViewportTable;
class AcDbViewportTableIterator;
class AcDbViewportTableRecord;
class AcDbViewTable;
class AcDbViewTableIterator;
class AcDbViewTableRecord;
class AcDbWblockCloneFiler;
class AcDbXObject;
class AcDbXrefGraph;
class AcDbXrefGraphNode;
class AcDbXrefObjectId;
class AcFdFieldReactor;
class AcGeMatrix3d;
class AcGeVector3d;
class AcGeCurve3d;
class AcGiContext;
class AcGiTextStyle;
class AcRxClass;
struct AcHyperlink;
typedef struct _SYSTEMTIME SYSTEMTIME;
typedef struct tagBITMAPINFO BITMAPINFO;

//typedefs, .cpp supported
//-------------------------------------------------------------------------------------------------------
typedef unsigned long AcDbEvalNodeId;
typedef AcArray< AcDbEvalVariant, AcArrayObjectCopyReallocator<AcDbEvalVariant> > AcDbEvalVariantArray;
typedef AcArray< AcDbDimData*, AcArrayMemCopyReallocator<AcDbDimData*> > AcDbDimDataPtrArray;
typedef AcArray< AcDbDimData, AcArrayObjectCopyReallocator<AcDbDimData> > AcDbDimDataArray;
typedef AcArray<AcDbEvalEdgeInfo*> AcDbEvalEdgeInfoArray;
typedef AcArray<AcDbEvalExpr*> AcDbEvalExprPtrArray;
typedef AcArray<AcDbEvalNodeId> AcDbEvalNodeIdArray;
typedef AcArray< AcDbGripData*, AcArrayMemCopyReallocator<AcDbGripData*> > AcDbGripDataPtrArray;
typedef AcArray< AcDbGripData, AcArrayObjectCopyReallocator<AcDbGripData> > AcDbGripDataArray;
typedef AcArray<void*> AcDbVoidPtrArray;
typedef AcArray<int> AcDbIntArray;
typedef AcArray<Adesk::IntPtr> AcDbIntPtrArray;
typedef AcGeVector3d (*DimDataSetCustomStringFuncPtr)(AcDbDimData*,AcDbEntity*,const ACHAR*,const AcGeVector3d&);
typedef AcGeVector3d (*DimDataSetValueFuncPtr)(AcDbDimData*,AcDbEntity*,double,const AcGeVector3d&);
typedef AcArray< AcString, AcArrayObjectCopyReallocator<AcString> > AcStringArray;


//defines, .cpp supported
//-------------------------------------------------------------------------------------------------------
#define acdbTransactionManager acdbTransactionManagerPtr()

//globals, .cpp supported
//-------------------------------------------------------------------------------------------------------
const ACHAR ACDB_BACKGROUND_DICTIONARY[] = ACRX_T("ACAD_BACKGROUND");
const ACHAR ACDB_MOTIONPATH_DICTIONARY[] = ACRX_T("ACAD_MOTION");
const ACHAR ACDB_NAMEDPATH_DICTIONARY[] = ACRX_T("ACAD_NAMEDPATH");
const ACHAR kszVS2DWireframe[] = ACRX_T("2dWireframe");
const ACHAR kszVS3DWireframe[] = ACRX_T("3dWireframe");
const ACHAR kszVSBasic[] = ACRX_T("Basic");
const ACHAR kszVSBrighten[] = ACRX_T("Brighten");
const ACHAR kszVSColorChange[] = ACRX_T("ColorChange");
const ACHAR kszVSConceptual[] = ACRX_T("Conceptual");
const ACHAR kszVSCustom[] = ACRX_T("Custom");
const ACHAR kszVSDim[] = ACRX_T("Dim");
const ACHAR kszVSFacePattern[] = ACRX_T("Facepattern");
const ACHAR kszVSFlatWithEdges[] = ACRX_T("FlatWithEdges");
const ACHAR kszVSFlat[] = ACRX_T("Flat");
const ACHAR kszVSGouraudWithEdges[] = ACRX_T("GouraudWithEdges");
const ACHAR kszVSGouraud[] = ACRX_T("Gouraud");
const ACHAR kszVSHidden[] = ACRX_T("3D Hidden");
const ACHAR kszVSLinePattern[] = ACRX_T("Linepattern");
const ACHAR kszVSRealistic[] = ACRX_T("Realistic");
const ACHAR kszVSThicken[] = ACRX_T("Thicken");
const ACHAR kszVSTransparent[] = ACRX_T("Transparent");

//enums, .cpp supported
//-------------------------------------------------------------------------------------------------------
struct AcDb
{
    typedef Adesk::Int16 DxfCode;
    typedef Adesk::UInt32 GeomId;
    typedef Adesk::UInt32 SubentType;

    enum
    {
        kDxfInvalid = -9999,
        kDxfXDictionary = -6,
        kDxfPReactors = -5,
        kDxfOperator = -4,
        kDxfXDataStart = -3,
        kDxfHeaderId = -2,
        kDxfFirstEntId = -2,
        kDxfEnd = -1,
        kDxfStart = 0,
        kDxfText = 1,
        kDxfXRefPath = 1,
        kDxfSymbolTableName = 2,
        kDxfSymTableRecName = 2,
        kDxfBlockName = 2,
        kDxfShapeName = 2,
        kDxfMstyleName = 2,
        kDxfAttributeTag = 2,
        kDxfTextFontFile = 3,
        kDxfDescription = 3,
        kDxfDimPostStr = 3,
        kDxfDimStyleName = 3,
        kDxfLinetypeProse = 3,
        kDxfAttributePrompt = 3,
        kDxfSymTableRecComments = 4,
        kDxfTextBigFontFile = 4,
        kDxfCLShapeName = 4,
        kDxfDimAPostStr = 4,
        kDxfDimBlk = 5,
        kDxfHandle = 5,
        kDxfDimBlk1 = 6,
        kDxfLinetypeName = 6,
        kDxfTextStyleName = 7,
        kDxfDimBlk2 = 7,
        kDxfLayerName = 8,
        kDxfCLShapeText = 9,
        kDxfXCoord = 10,
        kDxfYCoord = 20,
        kDxfZCoord = 30,
        kDxfElevation = 38,
        kDxfThickness = 39,
        kDxfReal = 40,
        kDxfTxtSize = 40,
        kDxfViewportHeight = 40,
        kDxfViewWidth = 41,
        kDxfTxtStyleXScale = 41,
        kDxfViewportAspect = 41,
        kDxfTxtStylePSize = 42,
        kDxfViewLensLength = 42,
        kDxfViewFrontClip = 43,
        kDxfViewBackClip = 44,
        kDxfShapeXOffset = 44,
        kDxfViewHeight = 45,
        kDxfShapeYOffset = 45,
        kDxfShapeScale = 46,
        kDxfPixelScale = 47,
        kDxfLinetypeScale = 48,
        kDxfLinetypeElement = 49,
        kDxfDashLength = 49,
        kDxfMlineOffset = 49,
        kDxfAngle = 50,
        kDxfViewportSnapAngle = 50,
        kDxfViewportTwist = 51,
        kDxfVisibility = 60,
        kDxfViewportGridDisplay = 60,
        kDxfLayerLinetype = 61,
        kDxfViewportGridMajor = 61,
        kDxfColor = 62,
        kDxfHasSubentities = 66,
        kDxfViewportVisibility = 67,
        kDxfViewportActive = 68,
        kDxfViewportNumber = 69,
        kDxfInt16 = 70,
        kDxfViewMode = 71,
        kDxfRegAppFlags = 71,
        kDxfTxtStyleFlags = 71,
        kDxfLinetypeAlign = 72,
        kDxfCircleSides = 72,
        kDxfViewportZoom = 73,
        kDxfLinetypePDC = 73,
        kDxfViewportIcon = 74,
        kDxfViewportSnap = 75,
        kDxfViewportGrid = 76,
        kDxfViewportSnapStyle = 77,
        kDxfViewportSnapPair = 78,
        kDxfInt32 = 90,
        kDxfSubclass = 100,
        kDxfEmbeddedObjectStart = 101,
        kDxfControlString = 102,
        kDxfDimVarHandle = 105,
        kDxfUCSOrg = 110,
        kDxfUCSOriX = 111,
        kDxfUCSOriY = 112,
        kDxfXReal = 140,
        kDxfViewBrightness = 141,
        kDxfViewContrast = 142,
        kDxfInt64 = 160,
        kDxfXInt16 = 170,
        kDxfNormalX = 210,
        kDxfNormalY = 220,
        kDxfNormalZ = 230,
        kDxfXXInt16 = 270,
        kDxfInt8 = 280,
        kDxfRenderMode = 281,
        kDxfDefaultLightingType = 282,
        kDxfShadowFlags = 284,
        kDxfBool = 290,
        kDxfDefaultLightingOn = 292,
        kDxfXTextString = 300,
        kDxfLiveSectionName = 309,
        kDxfBinaryChunk = 310,
        kDxfArbHandle = 320,
        kDxfSoftPointerId = 330,
        kDxfViewBackgroundId = 332,
        kDxfShadePlotId = 333,
        kDxfLiveSectionId = 334,
        kDxfHardPointerId = 340,
        kDxfObjVisualStyleId = 345,
        kDxfVpVisualStyleId = 346,
        kDxfMaterialId = 347,
        kDxfVisualStyleId = 348,
        kDxfDragVisualStyleId = 349,
        kDxfSoftOwnershipId = 350,
        kDxfHardOwnershipId = 360,
        kDxfSunId = 361,
        kDxfLineWeight = 370,
        kDxfPlotStyleNameType = 380,
        kDxfPlotStyleNameId = 390,
        kDxfXXXInt16 = 400,
        kDxfLayoutName = 410,
        kDxfColorRGB = 420,
        kDxfColorName = 430,
        kDxfAlpha = 440,
        kDxfGradientObjType = 450,
        kDxfGradientPatType = 451,
        kDxfGradientTintType = 452,
        kDxfGradientColCount = 453,
        kDxfGradientAngle = 460,
        kDxfGradientShift = 461,
        kDxfGradientTintVal = 462,
        kDxfGradientColVal = 463,
        kDxfGradientName = 470,
        kDxfComment = 999,
        kDxfXdAsciiString = 1000,
        kDxfRegAppName = 1001,
        kDxfXdControlString = 1002,
        kDxfXdLayerName = 1003,
        kDxfXdBinaryChunk = 1004,
        kDxfXdHandle = 1005,
        kDxfXdXCoord = 1010,
        kDxfXdWorldXCoord = 1011,
        kDxfXdWorldXDisp = 1012,
        kDxfXdWorldXDir = 1013,
        kDxfXdYCoord = 1020,
        kDxfXdWorldYCoord = 1021,
        kDxfXdWorldYDisp = 1022,
        kDxfXdWorldYDir = 1023,
        kDxfXdZCoord = 1030,
        kDxfXdWorldZCoord = 1031,
        kDxfXdWorldZDisp = 1032,
        kDxfXdWorldZDir = 1033,
        kDxfXdReal = 1040,
        kDxfXdDist = 1041,
        kDxfXdScale = 1042,
        kDxfXdInteger16 = 1070,
        kDxfXdInteger32 = 1071
    };

    enum
    {
        kNoGeom = 0
    };

    enum
    {
        kNullSubentType = 0,
        kFaceSubentType,
        kEdgeSubentType,
        kVertexSubentType,
        kMlineSubentCache,
        kClassSubentType,
        kAxisSubentType,
        kSilhouetteSubentType
    };

    enum AcDbDwgVersion
    {
        kDHL_MC0_0 = 0,
        kDHL_AC1_2,
        kDHL_AC1_40,
        kDHL_AC1_50,
        kDHL_AC2_20,
        kDHL_AC2_10,
        kDHL_AC2_21,
        kDHL_AC2_22,
        kDHL_1001,
        kDHL_1002,
        kDHL_1003,
        kDHL_1004,
        kDHL_1005,
        kDHL_1006,
        kDHL_1007,
        kDHL_1008,
        kDHL_1009,
        kDHL_1010,
        kDHL_1011,
        kDHL_1012,
        kDHL_1013,
        kDHL_1014,
        kDHL_1500,
        kDHL_1015,
        kDHL_1800a,
        kDHL_1800,
        kDHL_2100a,
        kDHL_1021,
        kDHL_2400a,
        kDHL_1024,
        kDHL_2700a,
        kDHL_1027,         // Dwg 2013 format
        kDHL_3200a,
        kDHL_1032,         // Dwg 2018 format
        kDHL_CURRENT = kDHL_1032,
        kDHL_Newest  = kDHL_1032,
        kDHL_Unknown = 32766,
        kDHL_Max = 32767
    };

    enum BoolOperType
    {
        kBoolUnite = 0,
        kBoolIntersect,
        kBoolSubtract
    };

    enum CellAlignment
    {
        kTopLeft = 1,
        kTopCenter,
        kTopRight,
        kMiddleLeft,
        kMiddleCenter,
        kMiddleRight,
        kBottomLeft,
        kBottomCenter,
        kBottomRight
    };

    enum CellEdgeMask
    {
        kTopMask = 1,
        kRightMask = 2,
        kBottomMask = 4,
        kLeftMask = 8
    };

    enum CellOption
    {
        kCellOptionNone = 0,
        kInheritCellFormat = 1
    };

    enum CellType
    {
        kUnknownCell = 0,
        kTextCell,
        kBlockCell,
        kMultipleContentCell,
    };

    enum CellContentType
    {
        kCellContentTypeUnknown = 0,
        kCellContentTypeValue   = 1,
        kCellContentTypeField   = 2,
        kCellContentTypeBlock   = 4,
    };

    enum CellContentLayout
    {
        kCellContentLayoutFlow              = 1,
        kCellContentLayoutStackedHorizontal = 2,
        kCellContentLayoutStackedVertical   = 4,
    };

    enum CellClass
    {
        kCellClassNone  = 0,
        kCellClassLabel = 1,
        kCellClassData  = 2,
    };

    enum CellMargin
    {
        kCellMarginTop         = 1,
        kCellMarginLeft        = 2,
        kCellMarginBottom      = 4,
        kCellMarginRight       = 8,
        kCellMarginHorzSpacing = 16,
        kCellMarginVertSpacing = 32,
    };

    enum CellState
    {
        kCellStateNone                       = 0,
        kCellStateContentLocked              = 1,
        kCellStateContentReadOnly            = 2,
        kCellStateLinked                     = 4,
        kCellStateContentModifiedAfterUpdate = 8,
        kCellStateFormatLocked               = 16,
        kCellStateFormatReadOnly             = 32,
        kCellStateFormatModifiedAfterUpdate  = 64,

        kAllCellStates = ( kCellStateContentLocked |
                           kCellStateContentReadOnly |
                           kCellStateLinked |
                           kCellStateContentModifiedAfterUpdate |
                           kCellStateFormatLocked |
                           kCellStateFormatReadOnly |
                           kCellStateFormatModifiedAfterUpdate),
    };

    enum CellProperty
    {
        kCellPropInvalid           = 0,
        kCellPropDataType          = 1,
        kCellPropDataFormat        = 2,
        kCellPropRotation          = 4,
        kCellPropScale             = 8,
        kCellPropAlignment         = 16,
        kCellPropContentColor      = 32,
        kCellPropTextStyle         = 64,
        kCellPropTextHeight        = 128,
        kCellPropAutoScale         = 256,
        kCellPropBackgroundColor   = 512,
        kCellPropMarginLeft        = 1024,
        kCellPropMarginTop         = 2048,
        kCellPropMarginRight       = 4096,
        kCellPropMarginBottom      = 8192,
        kCellPropContentLayout     = 16384,
        kCellPropMergeAll          = 32768,
        kCellPropFlowDirBtoT       = 0x10000,
        kCellPropMarginHorzSpacing = 0x20000,
        kCellPropMarginVertSpacing = 0x40000,
        kCellPropDataTypeAndFormat = ( kCellPropDataType |
                                       kCellPropDataFormat ),

        kCellPropContent = ( kCellPropDataType |
                             kCellPropDataFormat |
                             kCellPropRotation |
                             kCellPropScale |
                             kCellPropContentColor |
                             kCellPropTextStyle |
                             kCellPropTextHeight |
                             kCellPropAutoScale ),

        kCellPropBitProperties = ( kCellPropAutoScale |
                                   kCellPropMergeAll |
                                   kCellPropFlowDirBtoT ),

        kCellPropAll = ( kCellPropDataType |
                         kCellPropDataFormat |
                         kCellPropRotation |
                         kCellPropScale |
                         kCellPropAlignment |
                         kCellPropContentColor |
                         kCellPropBackgroundColor |
                         kCellPropTextStyle |
                         kCellPropTextHeight |
                         kCellPropMarginLeft |
                         kCellPropMarginTop |
                         kCellPropMarginRight |
                         kCellPropMarginBottom |
                         kCellPropMarginHorzSpacing |
                         kCellPropMarginVertSpacing |
                         kCellPropAutoScale |
                         kCellPropMergeAll |
                         kCellPropFlowDirBtoT |
                         kCellPropContentLayout),
    };

    enum CollisionType
    {
        kCollisionTypeNone = 0,
        kCollisionTypeSolid
    };

    enum CoordAxis
    {
        kX = 0,
        kY,
        kZ
    };

    enum CoordSystem
    {
        kWorldCS = 0,
        kUserCS,
        kCurDisplayCS,
        kPaperDisplayCS,
        kEntityCS
    };

    enum DataLinkGetSourceContext
    {
        kDataLinkGetSourceContextUnknown = 0,
        kDataLinkGetSourceContextEtransmit = 1,
        kDataLinkGetSourceContextXrefManager = 2,
        kDataLinkGetSourceContextFileWatcher = 3,
        kDataLinkGetSourceContextOther = 4,
        kDataLinkGetSourceContextOrignalPath = 256
    };

    enum DataLinkOption
    {
        kDataLinkOptionNone = 0,
        kDataLinkOptionAnonymous = 1,
        kDataLinkOptionPersistCache = 2,
        kDataLinkOptionObsolete = 4, //unused
        kDataLinkHasCustomData = 8 //unused
    };

    enum DeepCloneType
    {
        kDcCopy = 0,
        kDcExplode,
        kDcBlock,
        kDcXrefBind,
        kDcSymTableMerge,
        kDcInsert = 6,
        kDcWblock,
        kDcObjects,
        kDcXrefInsert,
        kDcInsertCopy,
        kDcWblkObjects
    };

    enum DimArrowFlags
    {
        kFirstArrow = 0,
        kSecondArrow
    };

    enum DimblkFlags
    {
        kDimblk = 0,
        kDimblk1,
        kDimblk2,
        kDimLdrBlk
    };

    enum DragStat
    {
        kDragStart = 0,
        kDragEnd,
        kDragAbort
    };

    enum DrawOrderFlags
    {
        kDrawOrderInPlaceEditOn = 1,
        kDrawOrderInheritanceOn
    };

    enum DuplicateRecordCloning
    {
        kDrcNotApplicable = 0,
        kDrcIgnore,
        kDrcReplace,
        kDrcXrefMangleName,
        kDrcMangleName,
        kDrcUnmangleName
    };

    enum DwgDataType
    {
        kDwgNull = 0,
        kDwgReal,
        kDwgInt32,
        kDwgInt16,
        kDwgInt8,
        kDwgText,
        kDwgBChunk,
        kDwgHandle,
        kDwgHardOwnershipId,
        kDwgSoftOwnershipId,
        kDwgHardPointerId,
        kDwgSoftPointerId,
        kDwg3Real,
        kDwgInt64,
        kDwgNotRecognized = 19
    };

    enum EdgeIndex
    {
        kMEdge1 = 0,
        kMEdge2,
        kMEdge3,
        kMEdge4
    };

    enum EndCaps
    {
        kEndCapNone = 0,
        kEndCapRound,
        kEndCapAngle,
        kEndCapSquare
    };

    enum EnhancedBlockEvalType
    {
        kInitialization = 1,
        kForUpdate,
        kForRefresh
    };

    enum FilerSeekType
    {
        kSeekFromStart = 0,
        kSeekFromCurrent,
        kSeekFromEnd
    };

    enum FilerType
    {
        kFileFiler = 0,
        kCopyFiler,
        kUndoFiler,
        kBagFiler,
        kIdXlateFiler,
        kPageFiler,
        kDeepCloneFiler,
        kIdFiler,
        kPurgeFiler,
        kWblockCloneFiler
    };

    enum FlowDirection
    {
        kTtoB = 0,
        kBtoT
    };

    enum GeomType
    {
        kInvalidGeom = 0,
        kPointGeom,
        kLineGeom,
        kCircleGeom,
        kPlaneGeom
    };

    enum GridLineTypes
    {
        kAllGridLines = 63
    };

    enum GripStat
    {
        kGripsDone = 0,
        kGripsToBeDeleted,
        kDimDataToBeDeleted
    };

    enum GroupOperType
    {
        kNoOp = 0,
        kAdd,
        kRemove,
        kRename,
        kOrdered,
        kGrpDesc,
        kSelect,
        kCreate,
        kPrepend,
        kInsert,
        kGrpFlags
    };

    enum Intersect
    {
        kOnBothOperands = 0,
        kExtendThis,
        kExtendArg,
        kExtendBoth
    };

    enum JoinStyle
    {
        kJnStylNone = 0,
        kJnStylRound,
        kJnStylAngle,
        kJnStylFlat
    };

    enum LineSpacingStyle
    {
        kAtLeast = 1,
        kExactly
    };

    enum LineWeight
    {
        kLnWtByLwDefault = -3,
        kLnWtByBlock = -2,
        kLnWtByLayer = -1,
        kLnWt000 = 0,
        kLnWt005 = 5,
        kLnWt009 = 9,
        kLnWt013 = 13,
        kLnWt015 = 15,
        kLnWt018 = 18,
        kLnWt020 = 20,
        kLnWt025 = 25,
        kLnWt030 = 30,
        kLnWt035 = 35,
        kLnWt040 = 40,
        kLnWt050 = 50,
        kLnWt053 = 53,
        kLnWt060 = 60,
        kLnWt070 = 70,
        kLnWt080 = 80,
        kLnWt090 = 90,
        kLnWt100 = 100,
        kLnWt106 = 106,
        kLnWt120 = 120,
        kLnWt140 = 140,
        kLnWt158 = 158,
        kLnWt200 = 200,
        kLnWt211 = 211
    };

    enum LoftNormalsType
    {
        kLoftRuled = 0,
        kLoftSmooth,
        kLoftFirstNormal,
        kLoftLastNormal,
        kLoftEndsNormal,
        kLoftAllNormal,
        kLoftUseDraftAngles
    };

    enum LoftParamType
    {
        kLoftNoParam = 0,
        kLoftNoTwist = 1,
        kLoftAlignDirection = 2,
        kLoftSimplify = 4,
        kLoftDefault = 7,
        kLoftClose = 8
    };

    enum MaintenanceReleaseVersion
    {
        kMRelease0 = 0,
        kMRelease1 = 1,
        kMRelease2,
        kMRelease3,
        kMRelease4,
        kMRelease5,
        kMRelease6,
        kMRelease7,
        kMRelease8,
        kMRelease9,
        kMRelease10,
        kMRelease11,
        kMRelease12,
        kMRelease13,
        kMRelease14,
        kMRelease15,
        kMRelease16,
        kMRelease17,
        kMRelease18,
        kMRelease19,
        kMRelease20,
        kMRelease21,
        kMRelease22,
        kMRelease23,
        kMRelease24,
        kMRelease25,
        kMRelease26,
        kMRelease27,
        kMRelease28,
        kMRelease29,
        kMRelease30,
        kMRelease31,
        kMRelease32,
        kMRelease33,
        kMRelease34,
        kMRelease35,
        kMRelease36,
        kMRelease37,
        kMRelease38,
        kMRelease39,
        kMRelease40,
        kMRelease41,
        kMReleaseFirstValid1500 = 41,
        kMRelease42,
        kMRelease43,
        kMRelease44,
        kMRelease45,
        kMRelease46,
        kMRelease47,
        kMRelease48,
        kMRelease49,
        kMRelease55 = 55,
        kMRelease56,
        kMRelease57,
        kMRelease58,
        kMRelease59,
        kMRelease60,
        kMRelease61,
        kMRelease62,
        kMRelease63,
        kMRelease64,
        kMRelease65,
        kMRelease66,
        kMRelease67,
        kMRelease68,
        kMRelease69,
        kMRelease70,
        kMRelease71,
        kMRelease72,
        kMRelease73,
        kMRelease74,
        kMRelease75,
        kMRelease76,
        kMRelease77,
        kMRelease78,
        kMRelease79,
        kMRelease80,
        kMRelease81,
        kMRelease82,
        kMRelease83,
        kMRelease84,
        kMRelease85,
        kMRelease86,
        kMRelease87,
        kMRelease88,
        kMRelease89,
        kMRelease90,
        kMRelease91,
        kMRelease92,
        kMRelease93,
        kMRelease94,
        kMRelease95,
        kMRelease96,
        kMRelease97,
        kMRelease98,
        kMRelease99,
        kMRelease100 = 100,
        kMRelease101,
        kMRelease102,
        kMRelease103,
        kMRelease104,

        kMRelease105,
        kMRelease106,
        kMRelease107,
        kMRelease108,
        kMRelease109,
        kMRelease110,
        kMRelease111,
        kMRelease112,
        kMRelease113,
        kMRelease114,
        kMRelease115,
        kMRelease116,
        kMRelease117,
        kMRelease118,
        kMRelease119,
        kMRelease120,
        kMRelease121,
        kMRelease122,
        kMRelease123,
        kMRelease124,
        kMRelease125,
        kMRelease126,
        kMRelease127,
        kMRelease128,
        kMRelease129,
        kMRelease130,
        kMRelease131,
        kMRelease132,
        kMRelease133,
        kMRelease134,
        kMRelease135,
        kMRelease136,
        kMRelease137,
        kMRelease138,
        kMRelease139,
        kMRelease140,
        kMRelease141,
        kMRelease142,
        kMRelease143,
        kMRelease144,
        kMRelease145,
        kMRelease146,
        kMRelease147,
        kMRelease148,
        kMRelease149,
        kMRelease150,
        kMRelease151,
        kMRelease152,
        kMRelease153,
        kMRelease154,
        kMRelease155,
        kMRelease156,
        kMRelease157,
        kMRelease158,
        kMRelease159,
        kMRelease160,
        kMRelease161,
        kMRelease162,
        kMRelease163,
        kMRelease164,
        kMRelease165,
        kMRelease166,
        kMRelease167,
        kMRelease168,
        kMRelease169,
        kMRelease170,
        kMRelease171,
        kMRelease172,
        kMRelease173,
        kMRelease174,
        kMRelease175,
        kMRelease176,
        kMRelease177,
        kMRelease178,
        kMRelease179,
        kMRelease180,
        kMRelease181,
        kMRelease182,
        kMRelease183,
        kMRelease184,
        kMRelease185,
        kMRelease186,
        kMRelease187,
        kMRelease188,
        kMRelease189,
        kMRelease190,
        kMRelease191,
        kMRelease192,
        kMRelease193,
        kMRelease194,
        kMRelease195,
        kMRelease196,
        kMRelease197,
        kMRelease198,
        kMRelease199,
        kMRelease200,
        kMRelease201,
        kMRelease202,
        kMRelease203,
        kMRelease204,
        kMRelease205,
        kMRelease206,
        kMRelease207,
        kMRelease208,
        kMRelease209,
        kMRelease210,
        kMRelease211,
        kMRelease212,
        kMRelease213,
        kMRelease214,
        kMRelease215,
        kMRelease216,
        kMRelease217,
        kMRelease218,
        kMRelease219,
        kMRelease220,
        kMRelease221,
        kMRelease222,
        kMRelease223,
        kMRelease224,
        kMRelease225,
        kMRelease226,
        kMRelease227,
        kMRelease228,
        kMRelease229,
        kMRelease230,
        kMRelease231,
        kMRelease232,
        kMRelease233,
        kMRelease234,
        kMRelease235,
        kMRelease236,
        kMRelease237,
        kMRelease238,
        kMRelease239,
        kMRelease240,
        kMRelease241,
        kMRelease242,
        kMRelease243,
        kMRelease244,
        kMRelease245,
        kMRelease246,
        kMRelease247,
        kMRelease248,
        kMRelease249,
        kMRelease250,
        kMRelease251,
        kMRelease252,
        kMRelease253,
        kMRelease254,
        kMRelease255,

        kMRelease2010Newest = kMRelease225,
        kMRelease2010Max    = kMRelease255,
        kMReleaseNewest     = kMRelease125,
        kMReleaseCurrent    = kMReleaseNewest,

        kMReleaseUnknown = 126,
        kMReleaseMax = 127
    };

    enum MeasurementValue
    {
        kEnglish = 0,
        kMetric
    };

    enum OpenMode
    {
        kForRead = 0,
        kForWrite,
        kForNotify
    };

    enum OrthographicView
    {
        kNonOrthoView = 0,
        kTopView,
        kBottomView,
        kFrontView,
        kBackView,
        kLeftView,
        kRightView
    };

    enum OsnapMask
    {
        kOsMaskEnd = 1,
        kOsMaskMid = 2,
        kOsMaskCen = 4,
        kOsMaskNode = 8,
        kOsMaskQuad = 16,
        kOsMaskInt = 32,
        kOsMaskIns = 64,
        kOsMaskPerp = 128,
        kOsMaskTan = 256,
        kOsMaskNear = 512,
        kOsMaskQuick = 1024,
        kOsMaskApint = 2048,
        kOsMaskImmediate = 65536,
        kOsMaskAllowTan = 131072,
        kOsMaskDisablePerp = 262144,
        kOsMaskRelCartesian = 524288,
        kOsMaskRelPolar = 1048576,
        kOsMaskNoneOverride = 2097152
    };

    enum OsnapMode
    {
        kOsModeNone = 0, // BRX specific : no osnap
        kOsModeEnd = 1,
        kOsModeMid,
        kOsModeCen,
        kOsModeNode,
        kOsModeQuad,
        kOsModeIns = 7,
        kOsModePerp,
        kOsModeTan,
        kOsModeNear,
        kOsModeCentroid
    };

    enum PathOption
    {
        kNoPath = 1,
        kRelativePath = 2,
        kAbsolutePath = 3,
        kPathAndFile = 4
    };

    enum Planarity
    {
        kNonPlanar = 0,
        kPlanar,
        kLinear
    };

    enum PlotStyleNameType
    {
        kPlotStyleNameByLayer = 0,
        kPlotStyleNameByBlock,
        kPlotStyleNameIsDictDefault,
        kPlotStyleNameById
    };

    enum PointIndex
    {
        kMPoint1 = 0,
        kMPoint2,
        kMPoint3,
        kMPoint4
    };

    enum Poly2dType
    {
        k2dSimplePoly = 0,
        k2dFitCurvePoly,
        k2dQuadSplinePoly,
        k2dCubicSplinePoly
    };

    enum Poly3dType
    {
        k3dSimplePoly = 0,
        k3dQuadSplinePoly,
        k3dCubicSplinePoly
    };

    enum PolyMeshType
    {
        kSimpleMesh = 0,
        kQuadSurfaceMesh = 5,
        kCubicSurfaceMesh = 6,
        kBezierSurfaceMesh = 8
    };

    enum reservedStringEnumType
    {
        kByLayer = 0,
        kByBlock,
        kNone,
        kContinuous,
        kStandard,
        kNormal,
        kDefPoints,
        kDefault,
        kMissing,
        kByColor,
        kModel,
        kGlobal,
        kVS2DWireframe,
        kVS3DWireframe,
        kVS3DHidden,
        kVSRealistic,
        kVSConceptual,
        kTitle,   // Table : style for Title cell
        kHeader,  // Table : style for Header cell
        kData,    // Table : style for Data cell
        kVSShadesOfGray,
        kVSSketchy,
        kVSXRay,
        kVSShadedWithEdges,
        kVSShaded,
        kReservedStringCount
    };

    enum RotationAngle
    {
        kDegreesUnknown = -1,
        kDegrees000,
        kDegrees090,
        kDegrees180,
        kDegrees270
    };

    enum RowType
    {
        kUnknownRow = 0,
        kDataRow = 1,
        kTitleRow = 2,
        kHeaderRow = 4
    };

    enum RowTypes
    {
        kAllRows = 7
    };

    enum SaveImagesMode
    {
        kNeverSave = 0,
        kAlwaysSave
    };

    enum SaveType
    {
        kNoSave = 0,
        kR12Save,
        kR13Save,
        kR14Save,
        k2000Save,
        k2004Save,
        k2007Save,
        k2010Save,
        k2013Save,
        k2018Save
    };

    enum OdaSaveType
    {
        kUnknown = -1,
        kDwg, 
        kDxf,
        kDxb        
    };

    enum SelectType
    {
        kWindow = 1,
        kCrossing
    };

    enum ShadowFlags
    {
        kShadowsCastAndReceive = 0,
        kShadowsDoesNotReceive,
        kShadowsDoesNotCast,
        kShadowsIgnore
    };

    enum ShowImagesMode
    {
        kNeverShow = 0,
        kAlwaysShow,
        kBoundingBoxShow
    };

    enum SliceModelType
    {
        kKeepBothSides = 1,
        kUseCurrentColor
    };

    enum SortEntsFlags
    {
        kSortEntsSelection = 1,
        kSortEntsOsnap = 2,
        kSortEntsRedraw = 4,
        kSortEntsSlide = 8,
        kSortEntsRegen = 16,
        kSortEntsPlot = 32,
        kSortEntsPsout = 64
    };

    enum SpaceValueType
    {
        kUndefined = 0,
        kStubPtr,
        kEndOfFile,
        kBackwardBranch,
        kForwardBranch,
        kDetour
    };

    enum TableStyleFlags
    {
        kHorzInsideLineFirst = 1,
        kHorzInsideLineSecond = 2,
        kHorzInsideLineThird = 4,
        kTableStyleModified = 8
    };

    enum TextHorzMode
    {
        kTextLeft = 0,
        kTextCenter,
        kTextRight,
        kTextAlign,
        kTextMid,
        kTextFit
    };

    enum TextVertMode
    {
        kTextBase = 0,
        kTextBottom,
        kTextVertMid,
        kTextTop
    };

    enum TimeZone
    {
        kInternationalDateLine = -12000,
        kMidwayIsland = -11000,
        kHawaii = -10000,
        kAlaska = -9000,
        kPacific = -8000,
        kMazatlan = -7002,
        kArizona = -7001,
        kMountain = -7000,
        kSaskatchewan = -6003,
        kMexicoCity = -6002,
        kCentralAmerica = -6001,
        kCentral = -6000,
        kBogota = -5002,
        kIndiana = -5001,
        kEastern = -5000,
        kSantiago = -4002,
        kCaracas = -4001,
        kAtlanticCanada = -4000,
        kNewfoundland = -3300,
        kGreenland = -3002,
        kBuenosAires = -3001,
        kBrasilia = -3000,
        kMidAtlantic = -2000,
        kCapeVerde = -1001,
        kAzores = -1000,
        kUTC = 0,
        kGMT = 1,
        kMonrovia = 2,
        kBerlin = 1000,
        kParis = 1001,
        kPrague = 1002,
        kSarajevo = 1003,
        kWestCentralAfrica = 1004,
        kAthens = 2000,
        kEasternEurope = 2001,
        kCairo = 2002,
        kHarare = 2003,
        kHelsinki = 2004,
        kJerusalem = 2005,
        kMoscow = 3000,
        kRiyadh = 3001,
        kBaghdad = 3002,
        kEastAfrica = 3003,
        kTehran = 3300,
        kAbuDhabi = 4000,
        kCaucasus = 4001,
        kKabul = 4300,
        kEkaterinburg = 5000,
        kIslamabad = 5001,
        kKolkata = 5300,
        kKathmandu = 5450,
        kAlmaty = 6000,
        kDhaka = 6001,
        kSriLanka = 6002,
        kRangoon = 6300,
        kBangkok = 7000,
        kKrasnoyarsk = 7001,
        kBeijing = 8000,
        kSingapore = 8001,
        kTaipei = 8002,
        kIrkutsk = 8003,
        kPerth = 8004,
        kTokyo = 9000,
        kSeoul = 9001,
        kYakutsk = 9002,
        kAdelaide = 9300,
        kDarwin = 9301,
        kSydney = 10000,
        kGuam = 10001,
        kBrisbane = 10002,
        kHobart = 10003,
        kVladivostock = 10004,
        kMagadan = 11000,
        kWellington = 12000,
        kFiji = 12001,
        kTonga = 13000
    };

    enum UnitsValue
    {
        kUnitsUndefined = 0,
        kUnitsInches,
        kUnitsFeet,
        kUnitsMiles,
        kUnitsMillimeters,
        kUnitsCentimeters,
        kUnitsMeters,
        kUnitsKilometers,
        kUnitsMicroinches,
        kUnitsMils,
        kUnitsYards,
        kUnitsAngstroms,
        kUnitsNanometers,
        kUnitsMicrons,
        kUnitsDecimeters,
        kUnitsDekameters,
        kUnitsHectometers,
        kUnitsGigameters,
        kUnitsAstronomical,
        kUnitsLightYears,
        kUnitsParsecs,
        kUnitsUSSurveyFeet,
        kUnitsUSSurveyInch,
        kUnitsUSSurveyYard,
        kUnitsUSSurveyMile,
        kUnitsMax = 24
    };

    enum UpdateThumbnailFlags
    {
        kUpdateModelViews = 1,
        kUpdateSheetViews = 2,
        kUpdateSheets = 4,
        kUpdateWhenAccessed = 8,
        kUpdateWhenSaving = 16
    };

    enum Vertex2dType
    {
        k2dVertex = 0,
        k2dSplineCtlVertex,
        k2dSplineFitVertex,
        k2dCurveFitVertex
    };

    enum Vertex3dType
    {
        k3dSimpleVertex = 0,
        k3dControlVertex,
        k3dFitVertex
    };

    enum Visibility
    {
        kVisible = 0,
        kInvisible
    };

    enum VpFreezeOps
    {
        kFreeze = 0,
        kThaw,
        kReset
    };

    enum XrefNotificationStatus
    {
        kXrfNotifyNone = 0,
        kXrfNotifyResolvedMatch,
        kXrfNotifyResolvedElsewhere,
        kXrfNotifyResolvedWithUpdate,
        kXrfNotifyResolvedUpdateAvailable
    };

    enum XrefStatus
    {
        kXrfNotAnXref = 0,
        kXrfResolved,
        kXrfUnloaded,
        kXrfUnreferenced,
        kXrfFileNotFound,
        kXrfUnresolved
    };

    enum UpdateDirection
    {
        kUpdateDirSourceToData = 1,
        kUpdateDirDataToSource
    };

    enum UpdateOption
    {
        kUpdateOptionNone = 0,
        kUpdateOptionSkipFormat = 131072,
        kUpdateOptionUpdateRowHeight = 262144,
        kUpdateOptionUpdateColumnWidth = 524288,
        kUpdateOptionAllowSourceUpdate = 1048576,
        kUpdateOptionForceFullSourceUpdate = 2097152,
        kUpdateOptionOverwriteContentModifiedAfterUpdate = 4194304,
        kUpdateOptionOverwriteFormatModifiedAfterUpdate = 8388608,
        kUpdateOptionForPreview = 16777216,
        kUpdateOptionIncludeXrefs = 33554432,
        kSkipFormatAfterFirstUpdate = 67108864,
    };

    enum TableBreakOption
    {
        kTableBreakNone = 0,
        kTableBreakEnableBreaking = 1,
        kTableBreakRepeatTopLabels = 2,
        kTableBreakRepeatBottomLabels = 4,
        kTableBreakAllowManualPositions = 8,
        kTableBreakAllowManualHeights = 16
    };

    enum TableBreakFlowDirection
    {
        kTableBreakFlowRight = 1,
        kTableBreakFlowDownOrUp = 2,
        kTableBreakFlowLeft = 4
    };

    enum TableFillOption
    {
        kTableFillNone = 0,
        kTableFillRow = 1,
        kTableFillReverse = 2,
        kTableFillGenerateSeries = 4,
        kTableFillCopyContent = 8,
        kTableFillCopyFormat = 16,
        kTableFillOverwriteReadOnlyContent = 32,
        kTableFillOverwriteReadOnlyFormat = 64
    };

    enum TableCopyOption
    {
        kTableCopyNone = 0,
        kTableCopyExpandOrContractTable = 1,
        kTableCopySkipContent = 2,
        kTableCopySkipValue = 4,
        kTableCopySkipField = 8,
        kTableCopySkipFormula = 16,
        kTableCopySkipBlock = 32,
        kTableCopySkipDataLink = 64,
        kTableCopySkipLabelCell = 128,
        kTableCopySkipDataCell = 256,
        kTableCopySkipFormat = 512,
        kTableCopySkipCellStyle = 1024,
        kTableCopyConvertFormatToOverrides = 2048,
        kTableCopySkipCellState = 4096,
        kTableCopySkipContentFormat = 8192,
        kTableCopySkipDissimilarContentFormat = 16384,
        kTableCopySkipGeometry = 32768,
        kTableCopySkipMerges = 65536,
        kTableCopyFillTarget = 131072,
        kTableCopyOverwriteReadOnlyContent = 262144,
        kTableCopyOverwriteReadOnlyFormat = 524288,
        kTableCopyOverwriteContentModifiedAfterUpdate = 1048576,
        kTableCopyOverwriteFormatModifiedAfterUpdate = 2097152,
        kTableCopyOnlyContentModifiedAfterUpdate = 4194304,
        kTableCopyOnlyFormatModifiedAfterUpdate = 8388608,
        kTableCopyRowHeight = 16777216,
        kTableCopyColumnWidth = 33554432,
        kTableCopyFullCellState = 67108864,
        kTableCopyForRountrip = 134217728,
        kTableCopyConvertFieldToValue = 268435456,
        kTableCopySkipFieldTranslation = 536870912
    };

    enum TableIteratorOption
    {
        kTableIteratorNone = 0,
        kTableIteratorIterateSelection = 1,
        kTableIteratorIterateRows = 2,
        kTableIteratorIterateColumns = 4,
        kTableIteratorReverseOrder = 8,
        kTableIteratorSkipReadOnlyContent = 16,
        kTableIteratorSkipReadOnlyFormat = 32,
        kTableIteratorSkipMerged = 64,
        kTableIteratorIterateDataLinks = 128
    };

    enum MergeCellStyleOption
    {
        kMergeCellStyleNone = 0,
        kMergeCellStyleCopyDuplicates = 1,
        kMergeCellStyleOverwriteDuplicates = 2,
        kMergeCellStyleConvertDuplicatesToOverrides = 4,
        kMergeCellStyleIgnoreNewStyles = 8,
    };

    enum TableHitItem
    {
        kTableHitNone = 0,
        kTableHitCell = 1,
        kTableHitRowIndicator = 2,
        kTableHitColumnIndicator = 4,
        kTableHitGridLine = 8
    };

    enum GridProperty
    {
        kGridPropInvalid = 0,
        kGridPropLineStyle = 1,
        kGridPropLineWeight = 2,
        kGridPropLinetype = 4,
        kGridPropColor = 8,
        kGridPropVisibility = 16,
        kGridPropDoubleLineSpacing = 32,
        kGridPropAll = (kGridPropLineStyle | kGridPropLineWeight | kGridPropLinetype | kGridPropColor | kGridPropVisibility | kGridPropDoubleLineSpacing)
    };

    enum GridLineType
    {
        kInvalidGridLine = 0,
        kHorzTop = 1,
        kHorzInside = 2,
        kHorzBottom = 4,
        kVertLeft = 8,
        kVertInside = 16,
        kVertRight = 32,
        kVertGridLineTypes  = kVertLeft | kVertRight | kVertInside,
        kHorzGridLineTypes  = kHorzTop | kHorzBottom | kHorzInside,        
        kInnerGridLineTypes = kHorzInside | kVertInside,
        kOuterGridLineTypes = kHorzTop | kHorzBottom | kVertLeft | kVertRight,        
        kAllGridLineTypes   = kOuterGridLineTypes | kInnerGridLineTypes
    };

    enum GridLineStyle
    {
        kGridLineStyleSingle = 1,
        kGridLineStyleDouble = 2
    };

}; //struct AcDb

namespace AcDbGripOperations
{
    enum DrawType
    {
        kWarmGrip = 0,
        kHoverGrip,
        kHotGrip,
        kDragImageGrip
    };

    enum GetGripPointsFlags
    {
        kGripPointsOnly = 1,
        kCyclableGripsOnly = 2,
        kDynamicDimMode = 4
    };

    enum GripContextFlags
    {
        kSharedGrip = 1,
        kMultiHotGrip
    };

    enum GripFlags
    {
        kSkipWhenShared = 1,
        kDisableRubberBandLine = 2,
        kDisableModeKeywords = 4,
        kDrawAtDragImageGripPoint = 8,
        kTriggerGrip = 16,
        kTurnOnForcedPick = 32,
        kMapGripHotToRtClk = 64,
        kGizmosEnabled = 128
    };

    enum GripStatus
    {
        kGripStart = 0,
        kGripEnd,
        kGripAbort,
        kStretch,
        kMove,
        kRotate,
        kScale,
        kMirror,
        kDimFocusChanged,
        kPopUpMenu
    };

    enum MoveGripPointsFlags
    {
        kOsnapped = 1,
        kPolar = 2,
        kOtrack = 4,
        kZdir = 8,
        kKeyboard = 16
    };

    enum ReturnValue
    {
        eOk = 0,
        eFailure,
        eNoRedrawGrip,
        eGripHotToWarm,
        eGetNewGripPoints
    };

};

//C functions, .cpp supported
//-------------------------------------------------------------------------------------------------------
extern "C"
{
    Adesk::Boolean acdbAcisGetDeleteBulletins();
    Adesk::Boolean acdbIsModelerStarted();
    Adesk::Boolean acdbSetAcisDwgVer(int);
    void acdbAcisSetDeleteBulletins(Adesk::Boolean);
}

//C++ functions, .cpp supported
//-------------------------------------------------------------------------------------------------------
Acad::ErrorStatus acdbAddFieldReactor(AcFdFieldReactor*);
Acad::ErrorStatus acdbAttachXref(AcDbDatabase*,const ACHAR*,const ACHAR*,AcDbObjectId&);
Acad::ErrorStatus acdbCleanUp();
Acad::ErrorStatus acdbClearSetupForLayouts(UINT_PTR);
Acad::ErrorStatus acdbConvertFieldsToText(AcDbDatabase*,const AcStringArray*,AcFd::ConvertFieldToText);
Acad::ErrorStatus acdbConvertFieldsToText(const AcDbObjectIdArray&,const AcStringArray*,AcFd::ConvertFieldToText);
Acad::ErrorStatus acdbCreateViewByViewport(AcDbDatabase*,AcDbObjectId,const ACHAR*,const ACHAR*,AcDbObjectId,AcDbObjectId&);
Acad::ErrorStatus acdbDetachXref(AcDbDatabase*,const AcDbObjectId&);
Acad::ErrorStatus acdbDoSetupForLayouts(AcDbDatabase*,UINT_PTR&);
Acad::ErrorStatus acdbDxfOutAs2000(AcDbDatabase*,const ACHAR*,const int = 16);
Acad::ErrorStatus acdbDxfOutAs2004(AcDbDatabase*,const ACHAR*,const int = 16);
Acad::ErrorStatus acdbDxfOutAsR12(AcDbDatabase*,const ACHAR*,const int = 16);
Acad::ErrorStatus acdbEvaluateFields(const AcDbObjectId&,int,const AcDbObjectIdArray*,const ACHAR*,AcDbDatabase*,AcFd::EvalFields,int*,int*);
Acad::ErrorStatus acdbEvaluateFields(const AcDbObjectId&,int,const ACHAR* = NULL,AcDbDatabase* = NULL,AcFd::EvalFields = AcFd::kEvalRecursive,int* = NULL,int* = NULL);
Acad::ErrorStatus acdbEvaluateFields(const AcDbObjectIdArray&,int,const AcDbObjectIdArray*,const ACHAR*,AcDbDatabase*,AcFd::EvalFields,int*,int*);
Acad::ErrorStatus acdbEvaluateFields(const AcDbObjectIdArray&,int,const ACHAR* = NULL,AcDbDatabase* = NULL,AcFd::EvalFields = AcFd::kEvalRecursive,int* = NULL,int* = NULL);
Acad::ErrorStatus acdbForceTextAdjust(const AcDbObjectIdArray&);
Acad::ErrorStatus acdbGetAdsName(ads_name&,AcDbObjectId);
Acad::ErrorStatus acdbGetExtnames(bool&,AcDbDatabase*);
Acad::ErrorStatus acdbGetHostDwgXrefGraph(AcDbDatabase*,AcDbXrefGraph&,Adesk::Boolean = Adesk::kFalse);
Acad::ErrorStatus acdbGetMotionPathDictionary(AcDbDatabase*,AcDbDictionary*&,AcDb::OpenMode);
Acad::ErrorStatus acdbGetMotionPathDictionary(AcDbDatabase*,AcDbDictionary*&,AcDb::OpenMode,bool);
Acad::ErrorStatus acdbGetNamedPathDictionary(AcDbDatabase*,AcDbDictionary*&,AcDb::OpenMode);
Acad::ErrorStatus acdbGetNamedPathDictionary(AcDbDatabase*,AcDbDictionary*&,AcDb::OpenMode,bool);
Acad::ErrorStatus acdbGetObjectId(AcDbObjectId&,const ads_name);
Acad::ErrorStatus acdbGetProxyInfo(AcDbObject*,ACHAR*&,ACHAR*&,ACHAR*&);
Acad::ErrorStatus acdbGetThumbnailBitmapFromDxfFile(const ACHAR*,void*&);
Acad::ErrorStatus acdbGetUnitsConversion(AcDb::UnitsValue,AcDb::UnitsValue,double&);
Acad::ErrorStatus acdbLoadLineTypeFile(const ACHAR*,const ACHAR*,AcDbDatabase*);
Acad::ErrorStatus acdbLoadMlineStyleFile(const ACHAR*,const ACHAR*);
Acad::ErrorStatus acdbMakeFieldCode(const ACHAR*,ACHAR*&);
Acad::ErrorStatus acdbMakeFieldCode(const ACHAR*,ACHAR*&,const ACHAR*,const ACHAR*,const AcHyperlink*);
Acad::ErrorStatus acdbOpenAcDbEntity(AcDbEntity*&,AcDbObjectId,AcDb::OpenMode,bool = false);
Acad::ErrorStatus acdbOpenAcDbObject(AcDbObject*&,AcDbObjectId,AcDb::OpenMode = AcDb::kForRead,bool = false);
Acad::ErrorStatus acdbOpenObject(AcDbEntity*&,AcDbObjectId,AcDb::OpenMode = AcDb::kForRead,bool = false);
Acad::ErrorStatus acdbOpenObject(AcDbObject*&,AcDbObjectId,AcDb::OpenMode = AcDb::kForRead,bool = false);
Acad::ErrorStatus acdbOverlayXref(AcDbDatabase*,const ACHAR*,const ACHAR*,AcDbObjectId&);
Acad::ErrorStatus acdbPutSummaryInfo(const AcDbDatabaseSummaryInfo*);
Acad::ErrorStatus acdbReloadXrefs(AcDbDatabase*, const AcDbObjectIdArray&,bool = true);
Acad::ErrorStatus acdbRemoveFieldReactor(AcFdFieldReactor*);
Acad::ErrorStatus acdbResolveCurrentXRefs(AcDbDatabase*,bool = true,bool = false);
Acad::ErrorStatus acdbResurrectMeNow(const AcDbObjectId&);
Acad::ErrorStatus acdbSaveAs2000(AcDbDatabase*,const ACHAR*);
Acad::ErrorStatus acdbSaveAs2004(AcDbDatabase*,const ACHAR*);
Acad::ErrorStatus acdbSaveAsR14(AcDbDatabase*,const ACHAR*);
Acad::ErrorStatus acdbSendInitialDwgFileOpenComplete(AcDbDatabase*);
Acad::ErrorStatus acdbSetExtnames(AcDbDatabase*,bool);
Acad::ErrorStatus acdbSetHostApplicationServices(AcDbHostApplicationServices*);
Acad::ErrorStatus acdbSetReferenced(AcDbObjectId);
Acad::ErrorStatus acdbSetViewportVisualStyle(AcDbObjectId);
Acad::ErrorStatus acdbValidateSetup(long);
Acad::ErrorStatus fromAcDbTextStyle(AcGiTextStyle&,const AcDbObjectId&);
Acad::ErrorStatus fromAcDbTextStyle(AcGiTextStyle&,const ACHAR*);
Acad::ErrorStatus getBackgroundDictionary(AcDbDatabase*,AcDbDictionary*&,AcDb::OpenMode);
Acad::ErrorStatus getBackgroundDictionary(AcDbDatabase*,AcDbDictionary*&,AcDb::OpenMode,bool);
Acad::ErrorStatus toAcDbTextStyle(AcGiTextStyle&);
Acad::ErrorStatus toAcDbTextStyle(AcGiTextStyle&,AcDbObjectId&);
Acad::ErrorStatus toAcDbTextStyle(AcGiTextStyle&,const ACHAR*);
Acad::ErrorStatus toAcDbTextStyle(AcGiTextStyle&,const ACHAR*,AcDbObjectId&);
Acad::ErrorStatus toAcDbTextStyle(const AcDbObjectId,AcGiTextStyle&);
Acad::ErrorStatus __stdcall acdbGetSummaryInfo(AcDbDatabase*,AcDbDatabaseSummaryInfo*&);
Acad::ErrorStatus __stdcall acdbOpenAcDbObject(AcDbObject*&,AcDbObjectId,AcDb::OpenMode,const AcRxClass*,bool = false);
Acad::ErrorStatus __stdcall acdbPutSummaryInfo(const AcDbDatabaseSummaryInfo*,AcDbDatabase*);
Acad::ErrorStatus acdbPostDimAssoc(AcDbObjectId, AcDbDimAssoc*, AcDbObjectId&, bool = true);
Acad::ErrorStatus acdbUpdateDimension(AcDbObjectId);
Acad::ErrorStatus acdbUpdateAllDimensions(AcDbDatabase*);
Acad::ErrorStatus acdbGetDimAssocId(AcDbObjectId, AcDbObjectId&);
Acad::ErrorStatus acdbGetDimAssocIds(AcDbObjectId, AcDbObjectIdArray&);
Acad::ErrorStatus acdbGetAssocAnnotationActionBody(const AcDbObjectId&, AcDbObjectId&);
Acad::ErrorStatus acdbGetNonAssocAnnotations(AcDbDatabase*, bool, AcDbObjectId&, AcDbObjectIdArray&, bool = false);
Acad::ErrorStatus acdbUnloadXrefs(AcDbDatabase*, const AcDbObjectIdArray&, const bool = true);
Acad::ErrorStatus acdbBindXrefs(AcDbDatabase*, const AcDbObjectIdArray&, const bool, const bool = false, const bool = true);
AcDb::DwgDataType acdbGroupCodeToType(AcDb::DxfCode);
AcDbCustomOsnapManager* acdbCustomOsnapManager();
AcDbHostApplicationServices* acdbHostApplicationServices();
AcDbObjectId acdbGetCurVportId(AcDbDatabase*);
AcDbObjectId acdbGetCurVportTableRecordId(AcDbDatabase*);
AcDbObjectId acdbGetDynDimStyleId(AcDbDatabase* = NULL);
AcDbObjectId acdbGetViewportVisualStyle();
AcDbObjectId acdbPersistentReactorObjectId(void*);
AcDbSummaryInfoManager* __stdcall acdbSummaryInfoManager();
AcDbTransactionManager* acdbTransactionManagerPtr();
AcDbUnderlayHost* acdbGetCurrentDgnHost();
AcDbUnderlayHost* acdbGetCurrentDwfHost();
AcDbUnderlayHost* acdbSetCurrentDgnHost(AcDbUnderlayHost*);
AcDbUnderlayHost* acdbSetCurrentDwfHost(AcDbUnderlayHost*);
const AcArray<AcDbDatabase*>& acdbActiveDatabaseArray();
AcFdFieldEngine* acdbGetFieldEngine();
AcGiContext* acdbSetDefaultAcGiContext(AcGiContext*);
bool acdbDisplayPreviewFromDwg(const ACHAR*,void*,const Adesk::UInt32* = NULL);
bool acdbEcs2Ucs(ads_point,ads_point,ads_point,bool);
bool acdbEcs2Wcs(ads_point,ads_point,ads_point,bool);
bool acdbFindField(const ACHAR*,int,int&,int&);
bool acdbGetExemptCheckFlag(AcDbObject*,int&);
bool acdbGetFieldMarkers(const ACHAR*&,const ACHAR*&);
bool acdbHasFields(const ACHAR*);
bool acdbIsCustomObject(const AcDbObjectId&);
bool acdbIsGsWorkerThread();
bool acdbIsPersistentReactor(void*);
bool acdbIsReservedString(const ACHAR*,AcDb::reservedStringEnumType);
bool acdbSetExemptCheckFlag(AcDbObject*,int);
bool acdbIsAnnoMonitorOn();
bool acdbIsAssociativityAlertIconDisabled(AcDbEntity*);
bool acdbGetAssociativityOverride(AcDbEntity*, int&);
bool acdbSetAssociativityOverride(AcDbEntity*, int); 
bool acdbIsEntityInBlockOrXref(const AcDbEntity*);
bool acdbDisableAssociativityAlertIcon(AcDbEntity*, bool);
bool acdbIsAssociativeAnnotation(AcDbObject*, bool* = NULL);
bool acdbIsTransSpatial(const AcDbFullSubentPath&);
Acad::ErrorStatus acdbConvertForSave(const AcDbObjectId&, AcDb::AcDbDwgVersion);
Acad::ErrorStatus acdbEnableDimAssocForEntity(const AcRxClass*);
Acad::ErrorStatus acdbDisableDimAssocForEntity(const AcRxClass*);

Acad::ErrorStatus acdbConvertAcDbCurveToGelibCurve(const AcDbCurve*, AcGeCurve3d*&, const AcGeTol& = AcGeContext::gTol);
Acad::ErrorStatus acdbConvertGelibCurveToAcDbCurve(const AcGeCurve3d&, AcDbCurve*&, AcGeVector3d* = NULL, const AcGeTol& = AcGeContext::gTol);
Acad::ErrorStatus acdbAssignGelibCurveToAcDbCurve(const AcGeCurve3d&, AcDbCurve*, AcGeVector3d* = NULL, const AcGeTol& = AcGeContext::gTol);

static const AcDbObjectIdArray acdbObjectIdArrayEmpty__;
bool acdbTextFind(AcDbDatabase*,AcDbObjectIdArray&,const ACHAR*,const ACHAR* = NULL,Adesk::UInt8 = AC_SRCH_DEFAULT,const AcDbObjectIdArray& = acdbObjectIdArrayEmpty__);

bool acdbUcs2Ecs(ads_point,ads_point,ads_point,bool);
bool acdbUcs2Wcs(ads_point,ads_point,bool);
bool acdbUcsMatrix(AcGeMatrix3d&,AcDbDatabase* = NULL);
bool acdbWcs2Ecs(ads_point,ads_point,ads_point,bool);
bool acdbWcs2Ucs(ads_point,ads_point,bool);
bool __stdcall acdbDwkFileExists(const ACHAR*);
const ACHAR* acdbGetReservedString(AcDb::reservedStringEnumType,bool = true);
const ACHAR* acdbOriginalXrefFullPathFor(const AcDbDatabase*);
const ACHAR* acdbXlateReservedString(const ACHAR*,bool = true);
int acdbHostAppMinorVersion();
int __stdcall acdbQueueForRegen(const AcDbObjectId*,int);
void acdbConvertHslToRgb(const AcGeVector3d&,AcGeVector3d&);
void acdbConvertRgbToHsl(const AcGeVector3d&,AcGeVector3d&);
void acdbFreeResBufContents(resbuf*);
void acdbReleaseHostDwg(AcDbDatabase*);
void deleteAcDbSummaryInfoManager();
void initAcDbSummaryInfoManager();

#ifdef _WINDOWS_
bool acdbGetPreviewBitmapFromDwg(const ACHAR*,HBITMAP*,HPALETTE*);
#endif

template<class OBJECT_TYPE>
Acad::ErrorStatus acdbOpenObject(OBJECT_TYPE* &pObject,AcDbObjectId id,AcDb::OpenMode eMode = AcDb::kForRead,bool erased = false)
{
    return ::acdbOpenAcDbObject((AcDbObject*&) pObject,id,eMode,OBJECT_TYPE::desc(),erased);
}

//smart pointer utility functions
Acad::ErrorStatus accessAcDbObjectForRead(AcDbObject*&, AcDbObjectId, AcRxClass*(*)(), bool&, bool);
Acad::ErrorStatus accessAcDbObjectForWrite(AcDbObject*, bool&, bool&, int&, bool);
Acad::ErrorStatus revertAcDbObjectFromWrite(AcDbObject*, Acad::ErrorStatus, bool, bool, int);

#endif //__cplusplus

//forward declarations, .c and .cpp supported
//-------------------------------------------------------------------------------------------------------
#undef CLSID
struct _GUID;
typedef struct _GUID CLSID;

//defines, .c and .cpp supported
//-------------------------------------------------------------------------------------------------------
#define ACDB_BROKEN_HANDLE ACRX_T("FFFFFFFF")
#define ACDB_CLOSE_BRACE_CHAR ACRX_T('}')
#define ACDB_CLOSE_BRACE_STR ACRX_T("}")
#define ACDB_COLOR_DICTIONARY ACRX_T("ACAD_COLOR")
#define ACDB_EMBEDDED_OBJECT_STR ACRX_T("Embedded Object")
#define ACDB_ENHANCED_BLOCK ACRX_T("ACAD_ENHANCEDBLOCK")
#define ACDB_ENHANCED_BLOCK_EVALKEY ACRX_T("ACAD_ENHANCEDBLOCKEVALKEY")
#define ACDB_ENHANCED_BLOCK_REF ACRX_T("ACAD_ENHANCEDBLOCK_REFERENCE")
#define ACDB_FIELDLIST ACRX_T("ACAD_FIELDLIST")
#define ACDB_FIELD_DICTIONARY ACRX_T("ACAD_FIELD")
#define ACDB_GROUP_DICTIONARY ACRX_T("ACAD_GROUP")
#define ACDB_INFINITE_XCLIP_DEPTH (1.e+300)
#define ACDB_LAYERSTATES_DICTIONARY ACRX_T("ACAD_LAYERSTATES")
#define ACDB_LAYOUT_DICTIONARY ACRX_T("ACAD_LAYOUT")
#define ACDB_MATERIAL_DICTIONARY ACRX_T("ACAD_MATERIAL")
#define ACDB_MLINESTYLE_DICTIONARY ACRX_T("ACAD_MLINESTYLE")
#define ACDB_MODEL_SPACE ACRX_T("*Model_Space")
#define ACDB_NULL_HANDLE ACRX_T("\0\0\0\0\0\0\0")
#define ACDB_OPEN_BRACE_CHAR ACRX_T('{')
#define ACDB_OPEN_BRACE_STR ACRX_T("{")
#define ACDB_PAPER_SPACE ACRX_T("*Paper_Space")
#define ACDB_PLOTSETTINGS_DICTIONARY ACRX_T("ACAD_PLOTSETTINGS")
#define ACDB_PLOTSTYLENAME_DICTIONARY ACRX_T("ACAD_PLOTSTYLENAME")
#define ACDB_MLEADERSTYLE_DICTIONARY ACRX_T("ACAD_MLEADERSTYLE")
#define ACDB_SCALELIST_DICTIONARY ACRX_T("ACAD_SCALELIST")
#define ACDB_SECTION_MANAGER ACRX_T("ACAD_SECTION_MANAGER")
#define ACDB_SERVICES ACRX_T("AcDbServices")
#define ACDB_TABLESTYLE_DICTIONARY ACRX_T("ACAD_TABLESTYLE")
#define ACDB_VISUALSTYLE_DICTIONARY ACRX_T("ACAD_VISUALSTYLE")
#define ACDB_XRECORD_CLASS ACRX_T("AcDbXrecord")
#define ACDB_XRECORD_ITERATOR_CLASS ACRX_T("AcDbXrecordClass")
#define HAPI_SERVICE ACRX_T("AcadHyperlinks")
#define ACDB_DETAILSTYLE_DICTIONARY ACRX_T("ACAD_DETAILVIEWSTYLE")
#define ACDB_SECTIONSTYLE_DICTIONARY ACRX_T("ACAD_SECTIONVIEWSTYLE")
#define ACDB_ASSOCNETWORK_DICTIONARY ACRX_T("ACAD_ASSOCNETWORK")

#define GRADIENT_PATTERN_NAME_LENGTH 32
#define HATCH_PATTERN_NAME_LENGTH 32

#define acdbCurDwg acdbHostApplicationServices()->workingDatabase
#define acdbGetCurrentSelectionSet acedGetCurrentSelectionSet
#define acdbGetCurViewportObjectId acedGetCurViewportObjectId
#define acdbGetRGB acedGetRGB
#define acdbSetCurrentVPort acedSetCurrentVPort
#define getCurDwgXrefGraph acedGetCurDwgXrefGraph

#define acdbNameClear(n) (n[0] = n[1] = 0)
#define acdbNameEqual(n1,n2) (n1[0] == n2[0] && n1[1] == n2[1])
#define acdbNameNil(n) (0 == n[0] && 0 == n[1])
#ifdef __STDC__
#define acdbNameSet(src,dest) (memcpy(dest,src,sizeof(ads_name)))
#define acdbPointSet(src,dest) (memcpy(dest,src,sizeof(ads_point)))
#else
#define acdbNameSet(src,dest) ((dest)[0]=(src)[0],(dest)[1]=(src)[1])
#define acdbPointSet(src,dest) ((dest)[0]=(src)[0],(dest)[1]=(src)[1],(dest)[2]=(src)[2])
#endif

//enums, .c and .cpp supported
//-------------------------------------------------------------------------------------------------------
enum
{
    kGroupsOn = 1,
    kHatchAssocOn
};

//C functions, .c and .cpp supported
//-------------------------------------------------------------------------------------------------------
#ifdef __cplusplus
extern "C"
{
#endif //__cplusplus
    ACHAR* acdbXStrSave(ACHAR*,ACHAR**);
    int acdbAngToF(const ACHAR*,int,ads_real*);
    int acdbAngToS(ads_real,int,int,ACHAR*,size_t);
    int acdbDictAdd(const ads_name,const ACHAR*,const ads_name);
    int acdbDictRemove(const ads_name,const ACHAR*);
    int acdbDictRename(const ads_name,const ACHAR*,const ACHAR*);
    int acdbDisToF(const ACHAR*,int,ads_real*);
    int acdbEntDel(const ads_name);
    int acdbEntLast(ads_name);
    int acdbEntMake(const struct resbuf*);
    int acdbEntMakeX(const struct resbuf*,ads_name);
    int acdbEntMod(const struct resbuf*);
    int acdbEntNext(const ads_name,ads_name);
    int acdbEntUpd(const ads_name);
    int acdbHandEnt(const ACHAR*,ads_name);
    int acdbInters(const ads_point,const ads_point,const ads_point,const ads_point,int,ads_point);
    int acdbNamedObjDict(ads_name);
    int acdbRawAngToS(ads_real,int,int,ACHAR*,size_t);
    int acdbRegApp(const ACHAR*);
    int acdbRToS(ads_real,int,int,ACHAR*,size_t);
    int acdbSNValid(const ACHAR*,int);
    int acdbTblObjName(const ACHAR*,const ACHAR*,ads_name);
#ifdef __cplusplus
    int acdbXdRoom(const ads_name,Adesk::Int32*);
    int acdbXdSize(const struct resbuf*,Adesk::Int32*);
#else
    int acdbXdRoom(const ads_name,long*);
    int acdbXdSize(const struct resbuf*,long*);
#endif
    int acdbXStrCase(ACHAR*,size_t);
    struct resbuf* acdbDictNext(const ads_name,int);
    struct resbuf* acdbDictSearch(const ads_name,const ACHAR*,int);
    struct resbuf* acdbEntGet(const ads_name);
    struct resbuf* acdbEntGetX(const ads_name,const struct resbuf*);
    struct resbuf* acdbTblNext(const ACHAR*,int);
    struct resbuf* acdbTblSearch(const ACHAR*,const ACHAR*,int);
    void acdbAcisDeleteModelerBulletins();
    void acdbFail(const ACHAR*);
    void acdbModelerEnd();
    void acdbModelerStart();
    int ads_queueexpr (const ACHAR*);
#ifdef __cplusplus
} //extern "C"
#endif //__cplusplus

#ifdef __cplusplus

// Templatized helpers to deduce buffer size arguments
template<size_t cch> inline int acdbAngToS(ads_real a, int u,int p, ACHAR(&sbuf)[cch]) { return acdbAngToS(a, u, p, sbuf, cch); }
template<size_t cch> inline int acdbRawAngToS(ads_real a, int u,int p, ACHAR(&sbuf)[cch]) { return acdbRawAngToS(a, u, p, sbuf, cch); }
template<size_t cch> inline int acdbRToS(ads_real r, int u,int p, ACHAR(&sbuf)[cch]) { return acdbRToS(r, u, p, sbuf, cch); }

// BRX specific
// allows to register a specific entity class, to hide/unhide the "undo per entity" PropertiesPanel entry
bool acdbDisableOpmUndoHistoryForClass(const AcRxClass* pClass, bool isBaseClass);
bool acdbEnableOpmUndoHistoryForClass(const AcRxClass* pClass);

// This RAII class ensures that the modeler is loaded while the class instance is alive.
// Instantiate it at the beginning of code blocks that might use the solid modeling kernel.
class BRX_IMPORTEXPORT AcDbModelerLock
{
public:
    AcDbModelerLock() { acdbModelerStart(); }
    ~AcDbModelerLock() { acdbModelerEnd(); }
private:
    AcDbModelerLock(const AcDbModelerLock&);
    AcDbModelerLock& operator=(const AcDbModelerLock&);
};

// This RAII class ensures that the modeler is safe to use from an externally created
// worker thread while the class instance is alive. Instantiate it at the beginning of
// code blocks in worker threads that might use the solid modeling kernel. When this
// class is instantiated from the main thread, it behaves exactly like AcDbModelerLock.
class AcDbModelerThreadLockImp;
class BRX_IMPORTEXPORT AcDbModelerThreadLock
{
    AcDbModelerThreadLockImp* m_pImp;
public:
    AcDbModelerThreadLock();
    ~AcDbModelerThreadLock();
private:
    AcDbModelerThreadLock(const AcDbModelerThreadLock&);
    AcDbModelerThreadLock& operator=(const AcDbModelerThreadLock&);
};
// BRX specific end

#endif //__cplusplus

//C++ functions, .c and .cpp supported
//-------------------------------------------------------------------------------------------------------
void acdbFree(void*);
void* acdbAlloc(size_t);
void* acdbRealloc(void*,size_t);
