cmake_minimum_required(VERSION 3.31)
project(LibLiFM)

set(CMAKE_CXX_STANDARD 23)

add_library(LibLiFM
        LiFM.cpp
        Time/TimeKeeper.cpp
        Time/TimeKeeper.hpp
        Time/TimeEvent.hpp
        Club.cpp
        Club.hpp
)

target_link_libraries(LibLiFM PUBLIC spdlog::spdlog)
target_include_directories(LibLiFM PUBLIC include)
