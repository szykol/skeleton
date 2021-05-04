set(LIBRARY_NAME SkeletonLib)

set(SKELETON_INCLUDE_DIR ../../include/Skeleton)

file(GLOB SKELETON_PUB_HEADERS
    "${SKELETON_INCLUDE_DIR}/*.h"
    "${SKELETON_INCLUDE_DIR}/GUI/*.h"
    "${SKELETON_INCLUDE_DIR}/Managers/*.h"
    "${SKELETON_INCLUDE_DIR}/States/*.h"
    "${SKELETON_INCLUDE_DIR}/Util/*.h"
)

file(GLOB SKELETON_SRC
    "*.cpp"
    "GUI/*.cpp"
    "Managers/*.cpp"
    "States/*.cpp"
    "Util/*.cpp"
)

add_library(${LIBRARY_NAME} STATIC ${SKELETON_SRC} ${SKELETON_PUB_HEADERS})
target_include_directories(${LIBRARY_NAME} PRIVATE ${SKELETON_INCLUDE_DIR})
target_link_libraries(${LIBRARY_NAME} PUBLIC sfml-graphics sfml-window sfml-audio sfml-network sfml-system)
