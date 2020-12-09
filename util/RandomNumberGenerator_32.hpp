/**
 * @brief 乱数生成器(32bit)
 * @docs docs/util/RandomNumberGenerator.md
 */

#pragma once

#include "../base.hpp"

struct RandomNumberGenerator{
    mt19937 mt;
    RandomNumberGenerator():mt(chrono::steady_clock::now().time_since_epoch().count()){}
    uint32_t operator()(uint32_t a,uint32_t b){
        uniform_int_distribution<uint32_t> dist(a,b-1);
        return dist(mt);
    }
    uint32_t operator()(uint32_t b){
        return (*this)(0,b);
    }
};