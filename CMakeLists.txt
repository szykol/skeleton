cmake_minimum_required(VERSION 3.5)

project(Skeleton)

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_EXPORT_COMPILE_COMMANDS ON)

IF(CMAKE_BUILD_TYPE MATCHES Debug)
    message("debug mode")
    add_definitions(-DPROJ_DEBUG)
ENDIF(CMAKE_BUILD_TYPE MATCHES Debug)

file(GLOB SKELETON_SRC
    "Skeleton/src/*.h"
    "Skeleton/src/*.cpp"
    "Skeleton/src/GUI/*.cpp"
    "Skeleton/src/GUI/*.h"
    "Skeleton/src/Managers/*.cpp"
    "Skeleton/src/Managers/*.h"
    "Skeleton/src/States/*.cpp"
    "Skeleton/src/States/*.h"
    "Skeleton/src/Util/*.cpp"
    "Skeleton/src/Util/*.h"
)

file(GLOB SANDBOX_SRC
    "Sandbox/src/*.h"
    "Sandbox/src/*.cpp"
)

find_package(SFML 2.5 COMPONENTS graphics window audio network system REQUIRED)

add_executable(Sandbox ${SANDBOX_SRC})

add_library(SkeletonLib STATIC ${SKELETON_SRC})

target_include_directories(Sandbox PUBLIC "Skeleton/src")

target_link_libraries(SkeletonLib sfml-graphics sfml-window sfml-audio sfml-network sfml-system)
target_link_libraries(Sandbox SkeletonLib)
