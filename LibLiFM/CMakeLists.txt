cmake_minimum_required(VERSION 3.31)
project(LibLiFM)

set(CMAKE_CXX_STANDARD 23)

add_library(LibLiFM
        src/LiFM.cpp
        src/Time/TimeKeeper.cpp
        src/Time/TimeKeeper.hpp
        src/Time/TimeEvent.hpp
        src/models/Club.cpp
        src/models/League.cpp
        src/models/League.hpp
        src/util/ModelStorage.cpp
        src/util/ModelStorage.hpp
        src/models/Player.cpp
        src/models/Player.hpp
        src/util/MockDataCreator.cpp
        src/util/MockDataCreator.hpp
        src/util/MatchSim.cpp
        src/util/MatchSim.hpp
        src/util/RandomNumberGenerator.hpp
        src/models/Match.hpp
        src/models/Tactics/Tactic.hpp
        src/models/Transfer/TransferOffer.cpp
        src/models/Transfer/TransferOffer.hpp
        src/models/Transfer/TransferDetails.cpp
        src/models/Transfer/TransferDetails.hpp
        src/models/Transfer/TransferState.hpp
        src/models/Tactics/Positions/Position.hpp
        src/models/Tactics/Positions/LeftBack.cpp
        src/models/Tactics/Positions/LeftBack.hpp
)

add_subdirectory(tests)

target_include_directories(LibLiFM PUBLIC src)
target_include_directories(LibLiFM PUBLIC src/include)
target_link_libraries(LibLiFM PUBLIC spdlog::spdlog)
