/*
 * Copyright (c) 2019 Bricsys NV
 * All rights reserved.
 */

#pragma once

namespace Ice
{;

/**
 * Supported schemas
 * @author <a href="mailto:natalia.shakhalova@bricsys.com">Natalia Shakhalova</a>
 */
enum EIfcSchemaId : int
{
    eIFC2X3,
    eIFC4,
    eIFC4X1,
    eIfcSchemaLast = eIFC4X1
};

} // namespace Ice

#define IFC_SCHEMA_LIST()\
    IFC_SCHEMA(2X3)\
    IFC_SCHEMA(4)\
    IFC_SCHEMA(4X1)

