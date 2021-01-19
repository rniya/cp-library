#pragma once
#include "../base.hpp"

/**
 * @brief compress
 */
template <typename T> map<T, int> compress(vector<T> v) {
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    map<T, int> res;
    for (int i = 0; i < v.size(); i++) res[v[i]] = i;
    return res;
}