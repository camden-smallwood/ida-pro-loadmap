cmake_minimum_required(VERSION 3.27 FATAL_ERROR)

project(loadmap)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_STANDARD 17)

include($ENV{IDASDK}/ida-cmake/idasdk.cmake)

set(PLUGIN_NAME loadmap)
set(PLUGIN_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}" "${CMAKE_SOURCE_DIR}/source")
set(PLUGIN_SOURCES source/utils.cpp source/LoadMap.cpp source/MAPReader.cpp)
set(PLUGIN_RUN_ARGS "-t -z10000") # Debug messages for the debugger

generate()
disable_ida_warnings(mysample)
