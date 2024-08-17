cmake_minimum_required(VERSION 3.27 FATAL_ERROR)

project(loadmap)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)

include($ENV{IDASDK}/ida-cmake/idasdk.cmake)

set(PLUGIN_NAME loadmap)

set(PLUGIN_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}" "${CMAKE_SOURCE_DIR}/source")

set(PLUGIN_SOURCES source/utils.cpp source/LoadMap.cpp source/MAPReader.cpp)

set(PLUGIN_RUN_ARGS "-t -z10000") # Debug messages for the debugger

generate()
disable_ida_warnings(mysample)

# add_library(loadmap SHARED ${PLUGIN_SOURCES})
# target_compile_definitions(loadmap PRIVATE -DUSE_DANGEROUS_FUNCTIONS -DIDALDR)
# target_link_libraries(loadmap PRIVATE ${IDALIB})
# target_include_directories(loadmap PRIVATE ${IDAPROINCLUDE} ${PLUGIN_INCLUDE_DIRECTORIES})
# target_compile_definitions(loadmap PRIVATE ${IDAPROPLAT}=1 ${IDAEA64})
