cmake_minimum_required(VERSION 3.14)
project(AdventOfCode CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE Debug)

# Fetch Catch2
include(FetchContent)
FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.4.0
)
FetchContent_MakeAvailable(Catch2)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/src)

# Add main executable
file(GLOB DAY_SOURCES "src/day*.cpp")
add_executable(aoc src/main.cpp ${DAY_SOURCES})
target_link_libraries(aoc PRIVATE)

# Add test executable
file(GLOB TEST_SOURCES "tests/*.cpp")
file(GLOB SRC_SOURCES "src/*.cpp")

# Filter out any main.cpp from src when building tests
list(FILTER SRC_SOURCES EXCLUDE REGEX ".*main\\.cpp$")

add_executable(tests ${TEST_SOURCES} ${SRC_SOURCES})
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)

# Enable CTest
include(CTest)
include(Catch)
catch_discover_tests(tests)
