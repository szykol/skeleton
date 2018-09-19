# thanks to: https://github.com/Hopson97/SFML-Game-Framework/blob/master/CMakeLists.txt

cmake_minimum_required(VERSION 3.8.2)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose debug or release" FORCE)
endif()

project(skeleton)

file(GLOB_RECURSE SOURCES src/*.cpp)
add_executable(skeleton ${SOURCES})

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2.4 REQUIRED graphics window system audio)
target_link_libraries(skeleton ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})

set(CMAKE_CXX_STANDARD 17)

file(COPY ${CMAKE_SOURCE_DIR}/res DESTINATION ${CMAKE_BINARY_DIR})
