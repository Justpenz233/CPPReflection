cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 17)

project(Reflection)
set(BUILD_TOOL_DIR ${CMAKE_CURRENT_SOURCE_DIR}/BuildTool)
set(ENGINE_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Engine)
set(ENGINE_SOURCE_DIR ${ENGINE_ROOT_DIR}/Source)
set(GENERATED_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(BIN_DIR ${CMAKE_CURRENT_SOURCE_DIR}/bin)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BIN_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${BIN_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${BIN_DIR})

add_executable(EXAMPLE main.cpp)

add_subdirectory(BuildTool)

set(BuildHeaders "${CMAKE_CURRENT_SOURCE_DIR}/test.h")
set(INCLUDE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/test")
include(${BUILD_TOOL_DIR}/precompile/precompile.cmake)
add_dependencies(PiccoloPreCompile PiccoloParser)
add_dependencies(EXAMPLE PiccoloPreCompile)