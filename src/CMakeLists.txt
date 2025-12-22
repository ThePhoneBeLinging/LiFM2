cmake_minimum_required(VERSION 3.31)
project(LibLiFM)

set(CMAKE_CXX_STANDARD 23)

add_library(LibLiFM
        LiFM.cpp
        Time/TimeKeeper.cpp
        Time/TimeKeeper.hpp
        Time/TimeEvent.hpp
        models/Club.cpp
        models/League.cpp
        models/League.hpp
        util/ModelStorage.cpp
        util/ModelStorage.hpp
        models/Player.cpp
        models/Player.hpp
        util/MockDataCreator.cpp
        util/MockDataCreator.hpp
        util/MatchSim.cpp
        util/MatchSim.hpp
        util/RandomNumberGenerator.hpp
        models/Match.hpp
        models/Tactic.hpp
        models/Transfer/TransferOffer.cpp
        models/Transfer/TransferOffer.hpp
        models/Transfer/TransferDetails.cpp
        models/Transfer/TransferDetails.hpp
)

target_include_directories(LibLiFM PRIVATE .)
target_include_directories(LibLiFM PUBLIC include)
target_link_libraries(LibLiFM PUBLIC spdlog::spdlog

)
