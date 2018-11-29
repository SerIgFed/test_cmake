cmake_minimum_required(VERSION 3.0)

project(TestCmake)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

##set(BUILD_SHARED_LIBS ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${TestCmake_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${TestCmake_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${TestCmake_BINARY_DIR}/lib)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(build_options)

set(BUILD_GTEST ON  CACHE BOOL "" FORCE)
set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
add_subdirectory(dependencies/googletest)

#------------------------------------------------------------------------------
#  Setup subdirectories
#------------------------------------------------------------------------------

add_subdirectory(lib1)
add_subdirectory(tools)
