#pragma once
#include <algorithm>
#include <map>
#include <vector>

template <typename T> std::map<T, int> compress(std::vector<T>& v) {
    std::sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    std::map<T, int> res;
    for (size_t i = 0; i < v.size(); i++) res[v[i]] = i;
    return res;
}

/**
 * @brief compress (座標圧縮)
 */