#pragma once
#include "../base.hpp"

/**
 * @brief スライド最小値
 * @docs docs/datastructure/Slide_Min.md
 */
template <typename T> vector<T> Slide_Min(const vector<T>& v, int k) {
    deque<int> deq;
    vector<T> res;
    for (int i = 0; i < (int)v.size(); i++) {
        while (!deq.empty() && v[deq.back()] >= v[i]) deq.pop_back();
        deq.push_back(i);
        if (i - k + 1 >= 0) {
            res.push_back(v[deq.front()]);
            if (deq.front() == i - k + 1) deq.pop_front();
        }
    }
    return res;
}