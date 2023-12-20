#ifndef AFC_HPP
#define AFC_HPP

#ifdef _WIN32
// Windows libraries
#include "brx_platform_windows.h"
#include "rxmfcapi.h"
#include "acutads.h"
#elif __linux__
// Linux libraries
#include "brx_platform_linux.h"
#elif __APPLE__
// MacOS libraries
#include "brx_platform_linux.h"
#endif

#endif
