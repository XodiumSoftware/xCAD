// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

enum PathErr
{
    PATH_NOERR = 0,
    PATH_INVALID,
    PATH_BADOP,
    PATH_REFUSED,
    PATH_ERR
};

enum path_category
{
    DRIVE_TYPE = 0,
    UNC_TYPE,
    ROOT_TYPE,
    RELATIVE_TYPE
};

enum path_type
{
    NO_PATH = 0,
    NEW_PATH,
    WC_PATH,
    FILE_PATH,
    DIR_PATH,
    DEV_PATH,
};