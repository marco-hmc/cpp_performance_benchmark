project(benchmark)

file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE HEADERS "include/*.h")

include_directories(${CMAKE_SOURCE_DIR}/utils)

add_executable(${PROJECT_NAME} ${SOURCES})

find_package(benchmark REQUIRED)
target_link_libraries(${PROJECT_NAME} benchmark::benchmark benchmark::benchmark_main)

