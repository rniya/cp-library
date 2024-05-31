#pragma once
#include <algorithm>
#include <iterator>
#include <vector>

template <typename T> int longest_increasing_subsequence(const std::vector<T>& a, bool strict = true) {
    std::vector<T> lis;
    for (const auto& x : a) {
        auto it = (strict ? lower_bound(lis.begin(), lis.end(), x) : upper_bound(lis.begin(), lis.end(), x));
        if (it == lis.end())
            lis.emplace_back(x);
        else
            *it = x;
    }
    return lis.size();
}

template <typename T>
std::vector<int> longest_increasing_subsequence_restore(const std::vector<T>& a, bool strict = true) {
    int n = a.size();
    std::vector<T> lis;
    std::vector<int> pre(n, -1);
    lis.reserve(n);
    for (int i = 0; i < n; i++) {
        auto it = (strict ? lower_bound(lis.begin(), lis.end(), i, [&](int x, int y) { return a[x] < a[y]; })
                          : upper_bound(lis.begin(), lis.end(), i, [&](int x, int y) { return a[x] < a[y]; }));
        if (it == lis.end())
            lis.emplace_back(i);
        else
            *it = i;
        if (it != lis.begin()) pre[i] = *std::prev(it);
    }
    std::vector<int> res;
    for (int cur = lis.back(); cur != -1; cur = pre[cur]) res.emplace_back(cur);
    std::reverse(res.begin(), res.end());
    return res;
}
