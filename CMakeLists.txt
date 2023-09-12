cmake_minimum_required(VERSION 3.5)

# Definitions
set(PROJECT_NAME ultimate_string_lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

project(${PROJECT_NAME})

file(GLOB_RECURSE LIB_INC_FILES src/*.h)

add_library(${PROJECT_NAME}_LIB SHARED ${LIB_INC_FILES})
