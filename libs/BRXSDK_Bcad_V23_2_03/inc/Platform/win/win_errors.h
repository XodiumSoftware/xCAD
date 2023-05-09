// Copyright (C) 2010-2014 Menhirs NV. All rights reserved.

// WIN error definitions

#pragma once

#ifndef _BS_WIN_ERRORS_INCLUDED_
#define _BS_WIN_ERRORS_INCLUDED_


#ifndef _WIN32  // on Linux/Mac

  // Windows Registry

  #define ERROR_BADDB                   (0x00001009L)
  #define ERROR_BADKEY                  (0x00001010L)
  #define ERROR_CANTOPEN                (0x00001011L)
  #define ERROR_CANTREAD                (0x00001012L)
  #define ERROR_CANTWRITE               (0x00001013L)
  #define ERROR_REGISTRY_RECOVERED      (0x00001014L)
  #define ERROR_REGISTRY_CORRUPT        (0x00001015L)
  #define ERROR_REGISTRY_IO_FAILED      (0x00001016L)
  #define ERROR_NOT_REGISTRY_FILE       (0x00001017L)
  #define ERROR_KEY_DELETED             (0x00001018L)
  #define ERROR_NO_LOG_SPACE            (0x00001019L)
  #define ERROR_NO_MORE_ITEMS           (0x00000103L)
  #define ERROR_CANNOT_COPY             (0x0000010AL)
  #define ERROR_KEY_HAS_CHILDREN        (0x00001020L)
  #define ERROR_CHILD_MUST_BE_VOLATILE  (0x00001021L)
  #define ERROR_NOTIFY_ENUM_DIR         (0x00001022L)


#endif // !_WIN32

#endif // _BS_WIN_ERRORS_INCLUDED_
