cmake_minimum_required(VERSION 3.5.0)
project(laba_6 VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror=maybe-uninitialized")

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.15.2
        TLS_VERIFY false
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

enable_testing()

set(SubProjectName "laba_6")

add_library(${SubProjectName}_lib npc.cpp
        npc.h
        dragon.cpp
        dragon.h
        pegas.cpp
        pegas.h
        knight.cpp
        knight.h
)

add_executable(${SubProjectName}_exe main.cpp)

target_link_libraries(${SubProjectName}_exe PRIVATE ${SubProjectName}_lib)

# add_executable(${SubProjectName}_tests tests.cpp)
# target_link_libraries(${SubProjectName}_tests ${SubProjectName}_lib gtest_main)

# add_test(NAME ${SubProjectName}_Tests COMMAND ${SubProjectName}_tests)
