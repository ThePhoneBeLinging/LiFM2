cmake_minimum_required(VERSION 3.31)
project(LiFMTests)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1  # Specify the version you need
)

FetchContent_MakeAvailable(googletest)

add_executable(LiFMTests
        LiFMLibTest.cpp
)

target_link_libraries(LiFMTests PUBLIC LibLiFM
        LibLiFM
        gtest_main
        spdlog::spdlog
)