#pragma once
#include "../base.hpp"

template <typename T> vector<int> Z_Algorithm(const T& s) {
    int n = s.size();
    vector<int> z(n);
    z[0] = n;
    for (int i = 1, j = 0; i < n;) {
        while (i + j < n && s[j] == s[i + j]) j++;
        z[i] = j;
        if (j == 0) {
            i++;
            continue;
        }
        int k = 1;
        while (i + k < n && k + z[k] < j) z[i + k] = z[k], k++;
        i += k;
        j -= k;
    }
    return z;
}

template <typename T> vector<int> LCP(const T& s, const T& t) {
    T u(s);
    u.insert(u.begin(), t.begin(), t.end());
    vector<int> z = Z_Algorithm(u);
    for (int& i : z) i = min(i, (int)t.size());
    return vector<int>(z.begin() + t.size(), z.end());
}
