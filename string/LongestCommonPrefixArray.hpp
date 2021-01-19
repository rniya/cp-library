#pragma once
#include "../base.hpp"
#include "SuffixArray.hpp"

/**
 * @brief Longest Common Prefix Array
 * @docs docs/string/LongestCommonPrefixArray.md
 */
struct LongestCommonPrefixArray {
    SuffixArray SA;
    vector<int> LCP, rank, lookup;
    vector<vector<int>> dat;
    LongestCommonPrefixArray(const string& s) : SA(s) {
        int n = s.size();
        LCP.resize(n);
        rank.resize(n + 1);
        for (int i = 0; i <= n; i++) rank[SA[i]] = i;
        LCP[0] = 0;
        for (int i = 0, t = 0; i < n; i++) {
            if (t) --t;
            for (int j = SA[rank[i] - 1]; max(i, j) + t < n && s[i + t] == s[j + t]; t++)
                ;
            LCP[rank[i] - 1] = t;
        }
        int h = 1;
        while ((1 << h) <= n) h++;
        dat.assign(h, vector<int>(n));
        lookup.assign(n + 1, 0);
        for (int i = 2; i <= n; i++) lookup[i] = lookup[i >> 1] + 1;
        for (int j = 0; j < n; j++) dat[0][j] = LCP[j];
        for (int i = 1, mask = 1; i < h; i++, mask <<= 1) {
            for (int j = 0; j < n; j++) {
                dat[i][j] = min(dat[i - 1][j], dat[i - 1][min(j + mask, n - 1)]);
            }
        }
    }
    int query(int a, int b) {
        if (a > b) swap(a, b);
        int d = lookup[b - a];
        return min(dat[d][a], dat[d][b - (1 << d)]);
    }
    // longest common prefix of s[a...] and s[b...]
    int lcp(int a, int b) { return query(rank[a], rank[b]); }
    int operator[](int i) const { return LCP[i]; }
    int size() const { return LCP.size(); }
};