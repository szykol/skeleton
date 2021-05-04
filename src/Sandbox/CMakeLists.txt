set(PUB_HEADERS ../../include)

file(GLOB SANDBOX_SRC
    "*.h"
    "*.cpp"
)

add_executable(Sandbox ${SANDBOX_SRC})
target_include_directories(Sandbox PUBLIC ${PUB_HEADERS})

target_link_libraries(Sandbox SkeletonLib)
