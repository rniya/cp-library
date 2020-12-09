/**
 * @brief 乱数生成器(64bit)
 * @docs docs/util/RandomNumberGenerator.md
 */

#pragma once

#include "../base.hpp"

struct RandomNumberGenerator{
    mt19937_64 mt;
    RandomNumberGenerator():mt(chrono::steady_clock::now().time_since_epoch().count()){}
    uint64_t operator()(uint64_t a,uint64_t b){
        uniform_int_distribution<uint64_t> dist(a,b-1);
        return dist(mt);
    }
    uint64_t operator()(uint64_t b){
        return (*this)(0,b);
    }
};