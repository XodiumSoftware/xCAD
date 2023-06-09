cmake_minimum_required(VERSION 3.0)
project(AUTOFRAMECAD)

# Add your project source files
set(SOURCES
    src/main.cpp
    src/foo.cpp
    src/bar.cpp
)

# Add an executable target
add_executable(MyExecutable ${SOURCES})

# Add any additional CMake commands or configuration options as needed
