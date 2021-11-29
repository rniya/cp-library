#pragma once
#include <deque>
#include <vector>

template <typename T> std::vector<T> Slide_Min(const std::vector<T>& v, int k) {
    std::deque<int> deq;
    std::vector<T> res;
    for (int i = 0; i < (int)v.size(); i++) {
        while (!deq.empty() and v[deq.back()] >= v[i]) deq.pop_back();
        deq.emplace_back(i);
        if (i - k + 1 >= 0) {
            res.emplace_back(v[deq.front()]);
            if (deq.front() == i - k + 1) deq.pop_front();
        }
    }
    return res;
}

/**
 * @brief スライド最小値
 * @docs docs/datastructure/Slide_Min.md
 */
