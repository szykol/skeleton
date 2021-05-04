cmake_minimum_required(VERSION 3.12)

project(Skeleton)

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_EXPORT_COMPILE_COMMANDS ON)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set (RESOURCES_DIR "${CMAKE_CURRENT_SOURCE_DIR}/res")

message(STATUS "Resources directory: ${RESOURCES_DIR}")

IF(CMAKE_BUILD_TYPE MATCHES Debug)
    message("debug mode")
    add_definitions(-DPROJ_DEBUG)
ENDIF(CMAKE_BUILD_TYPE MATCHES Debug)
add_definitions(-DRESOURCES_DIR="${RESOURCES_DIR}") 

find_package(SFML 2.5 COMPONENTS graphics window audio network system REQUIRED)

add_subdirectory(src)
