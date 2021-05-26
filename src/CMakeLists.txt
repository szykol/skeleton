add_subdirectory(Skeleton)

if ("${BUILD_SANDBOX}")
    message(STATUS "Building the Sandbox app")
    add_subdirectory(Sandbox)
else()
    message(STATUS "Not building the Sandbox app")
endif()
