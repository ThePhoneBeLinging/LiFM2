//
// Created by eal on 21/12-2025.
//

#ifndef RANDOMNUMBERGENERATOR_HPP
#define RANDOMNUMBERGENERATOR_HPP
#include <random>
#include <algorithm>

class RandomNumberGenerator
{
public:
    static int randomInt(int min, int max)
    {
        if (min > max) std::swap(min, max);
        static std::mt19937 rng(std::random_device{}());
        std::uniform_int_distribution<int> dist(min, max);
        return dist(rng);
    }
};

#endif //RANDOMNUMBERGENERATOR_HPP
