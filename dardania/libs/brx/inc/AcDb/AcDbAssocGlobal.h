// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbAssocEvaluationCallback.h"
#include "AcDb/AcDbActionsToEvaluateCallback.h"
#include "AcDb/AcDbSubEntGeometry.h"


class AcDbAssocDependency;
class AcDbAssocDependencyBody;
class AcDbAssocGeomDependency;
class AcDbAssoc2dConstraintGroup;
class AcDbAssocPersSubentId;
class AcDbAssocSimplePersSubentId;
class AcDbAssocSingleEdgePersSubentId;
class AcDbAssocIndexPersSubentId;
class AcDbAssocExternalIndexPersSubentId;
class AcDbAssocPersSubentIdPE;
class AcDbAssocVariable;
class AcDbAssocValueDependency;
class AcDbAssocValueProviderPE;
class AcDbEvalContext;
class AcDbAssocPersSubentManager;
class AcDbAssocPersSubentManagerPE;
class AcDbAssocPersSubentManagerCloner;
class AcDbAssocNotificationData;

class AcGeCurve3d;
class AcString;
class AcDbEvalVariant;

namespace PersSubEntNaming
{
    class AnnotationData;
    class PersSubentManager;

}

class ENTITY;
class COEDGE;
class EDGE;
class LOOP;
class FACE;
class SHELL;
class LUMP;
class BODY;
typedef AcArray<BODY*> AcDbAsmBodyArray;
typedef AcArray<ENTITY*> AcDbAsmEntityArray;
typedef AcArray<EDGE*> AcDbAsmEdgeArray;
typedef AcArray<FACE*> AcDbAsmFaceArray;
typedef AcArray<AcDbAsmEdgeArray> AcDbAsmEdgeArray2d;



enum AcDbAssocEvaluationPriority
{
    kCannotBeEvaluatedAssocEvaluationPriority = -1000,
    kCannotDermineAssocEvaluationPriority = 0,
    kCanBeEvaluatedAssocEvaluationPriority = 1000,
};

enum AcDbAssocCreateImpObject
{
    kAcDbAssocCreateImpObject = 0,
    kAcDbAssocDoNotCreateImpObject = 1,
};

typedef unsigned AcDbPersElemId;
typedef AcDbPersElemId AcDbPersStepId;
typedef AcDbPersElemId AcDbPersSubentId;
typedef AcArray<AcDbPersElemId> AcDbPersElemIdArray;
typedef AcArray<AcDbPersStepId> AcDbPersStepIdArray;
typedef AcArray<AcDbPersSubentId> AcDbPersSubentIdArray;
typedef AcArray<AcDbPersElemIdArray> AcDbPersElemIdArray2d;

const AcDbPersElemId kAcDbPersNullId = 0;

Acad::ErrorStatus checkTopLevelNetworkIntegrity(const AcDbDatabase*);

enum AcDbAssocConstraintType
{
    kNoneAssocConstraintType = 0,
    kDistanceAssocConstraintType = 1,
    kHorizontalDistanceAssocConstraintType = 2,
    kVerticalDistanceAssocConstraintType = 3,
    kAngle0AssocConstraintType = 4,
    kAngle1AssocConstraintType = 5,
    kAngle2AssocConstraintType = 6,
    kAngle3AssocConstraintType = 7,
    kRadiusAssocConstraintType = 8,
    kDiameterAssocConstraintType = 9,
};

bool acdbIsExpressionAConstant(const AcString&, AcDbEvalVariant&);
bool acdbIsExpressionANegativeConstant(const AcString&);
bool acdbIsIdentifier(const AcString&);
