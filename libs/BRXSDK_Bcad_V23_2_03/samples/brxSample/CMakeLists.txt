cmake_minimum_required(VERSION 3.10)

project(BrxSample LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set (FILES
dbx/MyOPMExtension.cpp
dbx/MyEntity.cpp
gui/MyQuadExtension.cpp
gui/MyRibbonContent.cpp
cmd/cmdDbx.cpp
acrxEntryPoint.cpp
StdAfx.cpp
Sample.cpp
)

add_library(Sample SHARED
  ${FILES}
)

target_compile_options(
  Sample
  PRIVATE
  -D_UNICODE -DUNICODE -D_DEBUG -D_AFXEXT -D_ACRXAPP -DBRX_APP -D_FILE_OFFSET_BITS=64 -D_LARGE_FILES -D__BRXTARGET=23
)

target_link_options(
  Sample
  PRIVATE
  -Wl,-whole-archive $ENV{BRX_SDK_PATH}/lib64/libdrx_entrypoint.a -Wl,-no-whole-archive
)

target_include_directories(
  Sample
  PRIVATE
  $ENV{BRX_SDK_PATH}/inc
  $ENV{BRX_SDK_PATH}/inc/Platform/substitutes
)

target_link_directories(
  Sample
  PRIVATE
  $ENV{BRX_SDK_PATH}/lib64
  # The code blocks file doesn't have this directory, it's not needed?
  # $ENV{DDCAD_PATH}/bin/gcc4/x64/Debug
)

target_link_libraries(
  Sample
  PRIVATE
  brx23
  TD_Alloc
  TD_Root
)
