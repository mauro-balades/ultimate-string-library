cmake_minimum_required(VERSION 3.5)

# Definitions
set(PROJECT_NAME ultimate_string_lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

project(${PROJECT_NAME})

file(GLOB_RECURSE LIB_INC_FILES src/*.c)

# Include directories
include_directories(src/usl.h)

# Library
add_library(${PROJECT_NAME}_LIB SHARED ${LIB_INC_FILES})

# Install
install(FILES src/usl.h DESTINATION include)
install(TARGETS ${PROJECT_NAME}_LIB DESTINATION lib)
