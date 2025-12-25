cmake_minimum_required(VERSION 3.31)
project(LiFMQt)

set(CMAKE_CXX_STANDARD 23)

find_package(Qt6 6.5 COMPONENTS Quick REQUIRED)
qt_standard_project_setup(REQUIRES 6.5)
qt_add_resources(LiFMQt_RESOURCES resources.qrc)

FILE(COPY resources.qrc DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
FILE(COPY Views/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/Views)

add_library(LiFMQt
        src/LiFMQt.cpp
        ${LiFMQt_RESOURCES}
)

include(FetchContent)
FetchContent_Declare(
        Utility
        GIT_REPOSITORY https://github.com/thephonebelinging/Utility
        GIT_TAG v1.0.0
)
FetchContent_MakeAvailable(Utility)

FetchContent_Declare(
        spdlog
        GIT_REPOSITORY https://github.com/gabime/spdlog
        GIT_TAG v1.16.0
)
FetchContent_MakeAvailable(spdlog)

FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1  # Specify the version you need
)

FetchContent_MakeAvailable(googletest)

target_link_libraries(LiFMQt PUBLIC LibLiFM
        Utility
        spdlog::spdlog
        gtest_main
        Qt6::Quick
)

target_include_directories(LibLiFM PRIVATE src)
target_include_directories(LibLiFM PUBLIC include)
