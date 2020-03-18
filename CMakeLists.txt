cmake_minimum_required(VERSION 3.13.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

# for gdb - remove before prod
# this is left to developer
# run: cmake -DCMAKE_BUILD_TYPE=Debug ..
set(CMAKE_BUILD_TYPE Debug)
add_compile_options(-Wall -Wextra -Wpedantic -g)
# create JSON compilation db
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        release-1.8.0
)

FetchContent_MakeAvailable(googletest)

project(Soundex)
include_directories(
	${PROJECT_SOURCE_DIR}/src
	)

file(GLOB all_srcs
	"${PROJECT_SOURCE_DIR}/src/*.cpp"
	"${PROJECT_SOURCE_DIR}/src/*.hpp"
	)

set(PROJECT_TEST_DIR PROJECT_SOURCE_DIR/test)
file(GLOB test_srcs
	"${PROJECT_TEST_DIR}/*.cpp"
	)



enable_testing()

################################
# Unit Tests 
# Add test cpp file
add_executable(runUnitTests ./src/test/SoundexTest.cpp)

# Link test executable against gtest & gtest_main
target_link_libraries(runUnitTests gtest
                                    gtest_main)

add_test(runUnitTests runUnitTests)
