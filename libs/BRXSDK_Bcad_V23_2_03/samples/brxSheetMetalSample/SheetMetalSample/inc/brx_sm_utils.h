// Utility functions for the commands

/////////////////////////////////////////////////////////////////////////

#pragma once

#if (__BRXVER < 21)
#error "This sample requires BricsCAD/BRX V21"
#endif

#ifndef _INC_LEAGACY_HEADERS_ 
#define _INC_LEAGACY_HEADERS_ 
#endif // !_INC_LEAGACY_HEADERS_ 
#include "arxHeaders.h"

#include "AcBrEdge.h"
#include "AcBrFace.h"
#include "AcBrFaceLoopTraverser.h"
#include "AcBrLoopEdgeTraverser.h"

#include "Misc/MiscGlobal.h"

#include "BrxSpecific/sheetmetal/SheetMetal.h"
#include "BrxSpecific/sheetmetal/SheetMetalOperations.h"

#include <algorithm>
#include <cassert>
#include <map>
#include <memory>
#include <set>

namespace BrxSheetMetalSample {

/**
 * Comparator for full subentity paths. Used to store full
 * subentity paths in std::map container as a key
 */
class FspComparator
{
public:

    bool operator()(const AcDbFullSubentPath & lhs, const AcDbFullSubentPath & rhs) const;
};

/**
 * Decides whether the command was failed or not
 * @param rt
 *   return code from command call via ads_command
 * @return
 *   true if command call failed
 */
bool isCommandFailed(int rt);

/**
 * Decides whether the command was finished with warnings or not
 * @param rt
 *   return code from command call via ads_command
 * @return
 *   true if command call was finished with warnings
 */
bool isCommandFinishedWithWarnings(int rt);

AcString getSolidName(const AcDbObjectId & solidId);

/**
 * Extracts all the faces of sheet metal body that lie on the same side
 * as given side face
 * @param sideFaceFsp
 *   side face of one of the following features:
 *   a) bend
 *   b) flange
 *   c) form feature
 *   d) lofted bend
 *   e) wrong bend
 *   f) wrong flange
 * @param aSideFacesFsp
 *   reference where sheet metal body side faces will be put if operation succeeded
 * @return
 *   Acad::eOk if succeeded
 */
Acad::ErrorStatus getSideFaces(const AcDbFullSubentPath & sideFaceFsp,
                               AcDbFullSubentPathArray & aSideFacesFsp);

/**
 * Extracts the face of existing sheet metal body external side. Since bottom flange faces
 * do not change in case of thickness changing, converter tries to assign bottom faces of
 * recognized flanges to external side of sheet metal body. That is why external side is
 * assumed to be the one with largest bottom flange faces area if body has flanges or simply
 * the one with largest side area if there are no flanges
 * @param blockId
 *   id of block table record
 * @param solidId
 *   Id of the solid
 * @param externalSideFaceFsp
 *   reference where either full subentity path to face of external side which may be lofted
 *   bend face or flange face will be put or AcDbFullSubentPath() if there are no flange or
 *   lofted bend features on existing sheet metal body
 * @return
 *   Acad::eOk if succeeded
 */
Acad::ErrorStatus getExternalSideFace(const AcDbObjectId & blockId,
    const AcDbObjectId & solidId,
    AcDbFullSubentPath & externalSideFaceFsp);

/**
 * Returns faces of Sheet Metal part from same side
 * @param blockId
 *   Owner block
 * @param solidId
 *   Solid to search
 * @param aSideFacesFsp
 *   Result where sheet metal body side faces will be put if operation succeeded
 * @return
 *   Acad::eOk if succeeded
 */
Acad::ErrorStatus getExternalSideFaces(const AcDbObjectId & blockId,
                                       const AcDbObjectId & solidId,
                                       AcDbFullSubentPathArray & aSideFacesFsp);

/**
 * Extracts flange bottom faces of sheet metal body that lie on the same side
 * as given side face
 * @param sideFaceFsp
 *   side face of one of the following features:
 *   a) bend
 *   b) flange
 *   c) form feature
 *   d) lofted bend
 *   e) wrong bend
 *   f) wrong flange
 * @param aFlangeIds
 *   ids of flanges
 * @param aSideBottomFlangeFaces
 *   reference where side sheet metal body bottom flange faces will be put if operation succeeded
 * @return
 *   Acad::eOk if succeeded
 */
Acad::ErrorStatus getSideBottomFlangeFaces(const AcDbFullSubentPath & sideFaceFsp,
                                           const AcDbObjectIdArray & aFlangeIds,
                                           AcDbFullSubentPathArray & aSideBottomFlangeFaces);

using FeatureAdjacencyMap = std::map<AcDbObjectId, BrxSheetMetal::BrxFeatureAdjacencyArray>;

/**
 * Extract complete information how features are adjacent to each other
 * @param blockId
 *   Owner block
 * @param solidId
 *   Solid to search
 * @param featureAdjacencyMap
 *   Result adjacency map if operation succeeded
 * @return
 *   Acad::eOk if succeeded
 */
Acad::ErrorStatus buildAdjacencyMap(const AcDbObjectId & blockId,
                                    const AcDbObjectId & solidId,
                                    FeatureAdjacencyMap & featureAdjacencyMap);

/**
 * Calculates surface area of given face
 * @param faceFsp
 *   face which area will be calculated
 * @param surfaceArea
 *   reference where calculated area will be put if succeeded or
 *   -1.0 will be assigned if error occurred during area calculation
 * @return
 *   Acad::eOk if succeeded
 */
Acad::ErrorStatus getArea(AcDbFullSubentPath faceFsp, double & surfaceArea);

/**
 * Calculates surface area of given faces
 * @param aFacesFsp
 *   faces which areas will be calculated and summed
 * @param sideSurfaceArea
 *   reference where sum of calculated areas will be put if succeeded or
 *   -1.0 will be assigned if error occurred during area calculation
 * @return
 *   Acad::eOk if succeeded
 */
Acad::ErrorStatus getSideArea(const AcDbFullSubentPathArray & aFacesFsp, double & sideSurfaceArea);

/**
 * Adds entity to modelspace of target database and returns its id
 * @param pDb
 *   Database to add to
 * @param pEnt
 *   Entity to add
 * @param objId
 *   Result id if succeeded
 * @return
 *   Acad::eOk if succeeded
 */
Acad::ErrorStatus addToDatabase(AcDbDatabase * pDb, AcDbEntity* pEnt, AcDbObjectId& objId);

/**
 * Clones given entity and returns clone id
 * @param entId
 *   Entity to clone
 * @param cloneId
 *   Clone id
 * @param featureMap
 *   Maps original features to features on clone
 * @return
 *   Acad::eOk if succeeded
 */
Acad::ErrorStatus cloneEntity(const AcDbObjectId& blockId,
    const AcDbObjectId& entId, AcDbObjectId& cloneId,
    std::map<AcDbObjectId, AcDbObjectId> & featureMap);

/**
 * For given database extracts id of its model space
 * @param pDb
 *   pointer to database
 * @param blockId
 *   reference where id of given database model space will be put
 * @return
 *   Acad::eOk if succeeded
 */
Acad::ErrorStatus getModelSpaceId(AcDbDatabase * pDb, AcDbObjectId & blockId);

/**
 * For given block table record extracts corresponding iterator
 * @param pBTR
 *   pointer to block table record
 * @parampUniqueBTRIter
 *   reference where unique pointer to iterator of this block table record will be put
 * @return
 *   Acad::eOk if succeeded
 */
Acad::ErrorStatus getBlockTableRecordIterator(const AcDbBlockTableRecord * pBTR,
                                              std::unique_ptr<AcDbBlockTableRecordIterator> & pUniqueBTRIter);

/**
 * Extracts all the solids of given database
 * @param pDb
 *   pointer to database
 * @param aSolidIds
 *   reference where array of solid ids will be put
 * @return
 *   Acad::eOk if succeeded
 */
Acad::ErrorStatus getSolidIdsFromDatabase(AcDbDatabase * pDb, AcDbObjectIdArray & aSolidIds);

/**
 * Template function that returns all the features of given kind
 * @template parameter Feature
 *   type of feature, e.g. BrxSmFlangeFeature, BrxSmBendFeature etc.
 * @parameter blockId
 *   id of block table record
 * @return
 *   array of feature ids of given kind
 */
template <class Feature> AcDbObjectIdArray getFeatures(const AcDbObjectId & blockId,
    const AcDbObjectId & solidId)
{
    AcDbObjectIdArray aAllFeatureIds = BrxIFeature::getAllFeatures(blockId);
    AcDbObjectIdArray aFeatureIds;
    for (const AcDbObjectId & featureId : aAllFeatureIds)
    {
        Feature feature(featureId);
        if (feature.isNull())
            continue;
        bool bAddFeature = true;
        if (!solidId.isNull())
        {
            bAddFeature = false;
            const auto aFSP = feature.getFeatureEntities();
            for (const auto & fsp : aFSP)
            {
                const auto & aObjectIds = fsp.objectIds();
                if (aObjectIds.isEmpty())
                {
                    continue;
                }
                if (solidId == aObjectIds.last())
                {
                    bAddFeature = true;
                    break;
                }
            }
        }
        if (bAddFeature)
            aFeatureIds.append(featureId);
    }
    return aFeatureIds;
}

/**
 * Extracts all the hard edges for existing sheet metal body.
 * @param blockId
 *   id of block table record
 * @param solidId
 *   id of solid to retrieve features
 * @param aHardEdges
 *   reference where array of hard edges full subentity paths will be put
 * @return
 *   Acad::eOk if succeeded
 */
Acad::ErrorStatus getHardEdges(const AcDbObjectId & blockId,
    const AcDbObjectId & solidId,
    AcDbFullSubentPathArray & aHardEdges);

/**
 * Dissolves all the sheet metal features in given block table record
 * and erases sheet metal context if there is existing one
 * @param blockId
 *   id of block table record
 * @return
 *   Acad::eOk if succeeded
 */
Acad::ErrorStatus dissolveAllSheetMetalFeatures(const AcDbObjectId & blockId,
    const AcDbObjectId & solidId);

/**
 * Dissolves sheet metal features for given solid
 * and erases sheet metal context if there is existing one
 * @param solidId
 *   id of solid
 * @param aKeepTheseFeatures
 *   Defines features which will not be dissolved
 * @return
 *   Acad::eOk if succeeded
 */
Acad::ErrorStatus dissolveSheetMetalFeatures(const AcDbObjectId & blockId,
    const AcDbObjectId & solidId,
    const AcDbObjectIdArray & aKeepTheseFeatures);

/**
 * Recognizes features on given solid
 * @param solidId
 *   id of solid
 * @return
 *   Acad::eOk if solid feature recognition succeeded
 */
Acad::ErrorStatus recognizeFeatures(const AcDbObjectId & solidId);

/**
 * Repairs external side of existing sheet metal body. If there are
 * no flange or lofted bend features on existing sheet metal body
 * then just quits and returns Acad:eInvalidInput.
 * @param blockId
 *   id of block table record
 * @param solidId
 *   Id of the solid
 * @param pDesiredFSP
 *   Non obligatory parameter choosing the side of Sheet Metal part
 * @return
 *   Acad::eOk if existing sheet metal body was successfully repaired
 */
Acad::ErrorStatus repairModel(const AcDbObjectId & blockId, const AcDbObjectId & solidId,
    AcDbFullSubentPath * pDesiredFSP = nullptr);

/**
 * Creates bends from hard edges on existing sheet metal body
 * @param blockId
 *   id of block table record
 * @param solidId
 *   Id of the solid
 * @return
 *   Acad::eOk if bend creation succeeded
 */
Acad::ErrorStatus createBends(const AcDbObjectId & blockId, const AcDbObjectId & solidId);

using LoftedBendToSideMap = std::map<AcDbObjectId, BrxSmLoftedBendFeature::ELoftedBendFaceType>;
/**
 * Splits parts with lofted bends into separate solids
 * @param blockId
 *   id of block table record
 * @param solidId
 *   Id of the solid
 * @param loftedBendToSideMap
 *   Defines which side of each lofted bend to user for repairing
 * @param oldToNewMap
 *   Contains mapping for features to new features
 * @return
 *   Acad::eOk if separation succeeded
 */
Acad::ErrorStatus separateLoftedBends(const AcDbObjectId & blockId, const AcDbObjectId & solidId,
    const LoftedBendToSideMap & loftedBendToSideMap,
    std::map<AcDbObjectId, AcDbObjectId> & oldToNewFeatureMap);

/**
 * Unfolds existing sheet metal body. If there are no flange or lofted bend
 * features on existing sheet metal body then just quits and returns Acad:eOk.
 * Unfolded block has insertion coordinates equal to insertion point.
 * @param blockId
 *   id of block table record
 * @param solidId
 *   Id of the solid
 * @param insertionPoint
 *   point where unfolded block will be inserted
 * @param unfoldedBlockYDim
 *  reference where unfolded block length along y coordinate will be put
 * @return
 *   Acad::eOk if solid was successfully unfolded
 */
Acad::ErrorStatus unfoldModel(const AcDbObjectId & blockId,
                              const AcDbObjectId & solidId,
                              const AcGePoint3d & insertionPoint,
                              double & unfoldedBlockYDim);

}
