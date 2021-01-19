#pragma once
#include "../base.hpp"

/**
 * @brief Zobrist Hash
 */
vector<uint64_t> ZobristHash(int n) {
    random_device seed_gen;
    mt19937_64 engine(seed_gen());
    vector<uint64_t> base(n);
    for (int i = 0; i < n; i++) base[i] = engine();
    return base;
}