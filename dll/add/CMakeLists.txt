cmake_minimum_required(VERSION 3.1.0)

project(add)

file(GLOB LIB_SOURCES "src/*.cpp")
include_directories("include")
add_library(${PROJECT_NAME} SHARED ${LIB_SOURCES})

target_link_libraries(${PROJECT_NAME} spdlog::spdlog)

# set(PARENT_PROJECT_NAME ${PROJECT_NAME})
# add_subdirectory(test)
