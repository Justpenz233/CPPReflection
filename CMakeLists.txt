cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 17)

set(BUILD_TOOL_DIR ${CMAKE_CURRENT_SOURCE_DIR}/BuildTool)
set(GENERATED_DIR ${CMAKE_CURRENT_SOURCE_DIR}/TestFiles)

set(BuildHeaders CACHE STRING "Headers to parse")
set(INCLUDE_DIRS "" CACHE STRING "Include search path for parser")

project(EXAMPLE)
add_executable(EXAMPLE main.cpp)

add_subdirectory(TestFiles)
add_subdirectory(BuildTool)

PreCompile(TestLib EXAMPLE)

target_link_libraries(EXAMPLE TestLib)