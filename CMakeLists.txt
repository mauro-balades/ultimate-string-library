cmake_minimum_required(VERSION 3.5)

# Definitions
set(PROJECT_NAME usl)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

project(${PROJECT_NAME})

file(GLOB_RECURSE LIB_INC_FILES src/**.c)

# Include directories
include_directories(src/)

# Library
add_library(${PROJECT_NAME} SHARED ${LIB_INC_FILES})

# Executable for testing
add_executable(${PROJECT_NAME}_TEST test/main.c ${LIB_INC_FILES})
target_link_libraries(${PROJECT_NAME}_TEST ${PROJECT_NAME})

# Install
install(FILES src/usl.h DESTINATION include)
install(TARGETS ${PROJECT_NAME} DESTINATION lib)
