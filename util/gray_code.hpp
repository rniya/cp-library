#pragma once
#include "../base.hpp"

/**
 * @brief グレイコード
 * @docs docs/util/gray_code.md
 */
vector<int> gray_code(int n) {
    vector<int> res(1 << n);
    for (int i = 0; i < (int)res.size(); i++) res[i] = i ^ (i >> 1);
    return res;
}