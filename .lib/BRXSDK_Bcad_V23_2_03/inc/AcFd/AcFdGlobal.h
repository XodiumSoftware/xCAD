// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#ifdef __cplusplus

//common forward declarations
class AcFdFieldEngine;
class AcFdFieldEvaluator;
class AcFdFieldEvaluatorLoader;
class AcFdFieldResult;
class AcFdFieldValue;

struct AcFd
{
    enum ConvertFieldToText
    {
        kConvertFieldToTextNone = 0,
        kEvaluateBeforeConversion = 1,
        kExcludeEvaluatorsInList = 2,
        kIgnoreEvaluatorVersion = 4
    };

    enum EvalFields
    {
        kEvalRecursive = 1
    };
};

#endif //__cplusplus