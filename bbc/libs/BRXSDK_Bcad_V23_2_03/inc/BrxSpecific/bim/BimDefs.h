// Copyright (C) Menhirs NV. All rights reserved.

// BimDefs.h
// common definitions for all BIM related functionality + interfaces

#pragma once

namespace BimApi
{

///////////////////////////////////////////////////////////////////////////////
// BIM result / error status
enum ResultStatus
{
    eOk = 0,
    eNoDbResidentObject,
    eDbNotAccessible,
    eDbObjectNotSupported,
    eDbNotOpenForWrite,
    eModelSpaceNotAccessible,
    eProjectDbNotAccessible,
    eAssociatedLibraryNotAccessible,
    eNotApplicableForTheseParameters,
    eInvalidSpatialLocation,
    eInvalidMaterial,
    eInvalidMaterialComposition,
    eObjectAlreadyExists,
    eObjectCouldNotBeDeleted,
    eXmlFileCouldNotBeParsed,
    eInvalidXmlFormat,
    eInvalidName,
    eNotLinearBuildingElement,
    eInvalidValue,
    eNotAssignedToLibrary,
    //
    eNullObject,
    eNullObjectId,
    eNullDatabase,
    eNullDocument,
    eNullString,
    eObjectNotExisting,
    eObjectNotSupported,
    eNoProfileAssigned,
    eNoData,
    eUnknownData,
    eWrongDataType,
    eUnassignedEntity,
    eBimNotImplementedYet,
    eBimNotAvailable,
    eInternalError,
    eUnknownError,
    eInvalidIndex,
    eInvalidInput,
    eNoNameSpace,
    eNameSpaceAlreadyExists,
    eNoPropertySet,
    ePropertySetAlreadyExists,
    eNoProperty,
    //
    eNotImplemented,
    eInvalidArgument
};


// utility function to verify that BIM is available
// (if not, it is usually a License problem, or RUNASLEVEL is set to a different value than 3 or 5)
BRX_IMPORTEXPORT bool isBimAvailable();

}; // namespace BimApi
