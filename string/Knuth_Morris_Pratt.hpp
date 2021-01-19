#pragma once
#include "../base.hpp"

/**
 * @brief Knuth Moriss Pratt (KMP法)
 * @docs docs/string/Knuth_Morris_Pratt.md
 */
struct Knuth_Morris_Pratt {
    string s;
    int n;
    vector<int> kmp;
    Knuth_Morris_Pratt(const string& s) : s(s) { build(); }
    void build() {
        n = s.size();
        kmp.assign(n + 1, -1);
        for (int i = 0, j = -1; i < n; kmp[++i] = ++j) {
            while (j >= 0 && s[i] != s[j]) j = kmp[j];
        }
    }
    vector<int> KMP() { return kmp; }
    vector<int> next_period() {
        vector<int> np = kmp;
        for (int i = 1; i < kmp.size(); i++) np[i] = i - np[i];
        return np;
    }
    vector<int> pattern_match(const string& t) {
        int m = t.size();
        vector<int> res;
        int i = 0, j = 0;
        while (i + j < m) {
            if (s[j] == t[i + j]) {
                if (++j != n) continue;
                res.emplace_back(i);
            }
            i += j - kmp[j];
            j = max(kmp[j], 0);
        }
        return res;
    }
};