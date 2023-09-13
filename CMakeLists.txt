cmake_minimum_required(VERSION 3.5)

# Definitions
set(PROJECT_NAME usl)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

project(${PROJECT_NAME})

file(GLOB_RECURSE LIB_INC_FILES src/*.c)

# Include directories
include_directories(src/)

# Library
add_library(${PROJECT_NAME} SHARED ${LIB_INC_FILES})

# Executable for testing
add_executable(${PROJECT_NAME}_TEST test/main.cc)

# Install
install(FILES src/usl.h DESTINATION include)
install(TARGETS ${PROJECT_NAME} DESTINATION lib)

# google test

enable_testing()

include(FetchContent)
FetchContent_Declare(gtest
  URL https://github.com/google/googletest/archive/release-1.11.0.tar.gz
)
# configure build of googletest
FetchContent_MakeAvailable(gtest)

# automatic discovery of unit tests
include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME}_TEST
  PROPERTIES
    LABELS "unit"
  DISCOVERY_TIMEOUT  # how long to wait (in seconds) before crashing
    240
  )

target_link_libraries(${PROJECT_NAME}_TEST ${PROJECT_NAME} gtest_main)

