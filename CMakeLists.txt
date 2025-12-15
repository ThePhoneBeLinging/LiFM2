cmake_minimum_required(VERSION 3.31)
project(LiFM)

set(CMAKE_CXX_STANDARD 23)

#find_package(Qt6 6.5 COMPONENTS Quick REQUIRED)
#qt_standard_project_setup(REQUIRES 6.5)
#qt_add_resources(LiFM_RESOURCES resources.qrc)
add_executable(LiFM
        main.cpp
        #${LiFM_RESOURCES}
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

add_subdirectory(src)


target_link_libraries(LiFM PUBLIC LibLiFM
    Utility
    spdlog::spdlog
)
