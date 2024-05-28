// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "IfcApi.h"
#include "AggregationsList.h"
#include "AliasList.h"
#include "AttributesList.h"
#include "EntitiesList.h"
#include "EnumValueList.h"
#include "SelectorsList.h"

namespace Ice
{
namespace IfcApi
{
#define ON_ENTITY(ENT)\
IFCAPI_EXPORT extern EntityDesc ENT;
#define ON_ROOT(ENT) ON_ENTITY(ENT)
#define ON_ABSTRACT(ENT) ON_ENTITY(ENT)
ENTITIES_LIST()
#undef ON_ENTITY
#undef ON_ROOT
#undef ON_ABSTRACT

#define ON_AGGREGATION(ENT)\
IFCAPI_EXPORT extern VectorDesc ENT;
AGGREGATIONS_LIST()
#undef ON_AGGREGATION

#define ON_SELECTOR(ENT)\
IFCAPI_EXPORT extern SelectorDesc ENT;
SELECTORS_LIST()
#undef ON_SELECTOR

#define ON_ALIAS(ENT)\
IFCAPI_EXPORT extern const char* ENT;
ALIAS_LIST()
#undef ON_ALIAS

#define ON_ENUMVALUE(VAL)\
IFCAPI_EXPORT extern const char* e##VAL;
ENUMVALUE_LIST()
#undef ON_ENUMVALUE

#define ON_ATTRIBUTE(ATT)\
IFCAPI_EXPORT extern const char* ATT;
ATTRIBUTES_LIST()
#undef ON_ATTRIBUTE
} // namespace IfcApi
} // namespace Ice
