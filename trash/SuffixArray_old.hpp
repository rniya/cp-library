#pragma once
#include "../base.hpp"

/**
 * @brief Suffix Array
 * @docs docs/string/SuffixArray.md
 */
struct SuffixArray {
    string s;
    vector<int> SA;
    SuffixArray(const string& S) : s(S) {
        int n = s.size();
        s.push_back('$');
        SA.resize(n + 1);
        iota(SA.begin(), SA.end(), 0);
        sort(SA.begin(), SA.end(), [&](int a, int b) { return s[a] == s[b] ? a > b : s[a] < s[b]; });
        vector<int> c(s.begin(), s.end()), cnt(n + 1), nxt(n + 1);
        for (int j = 1; j <= n; j <<= 1) {
            for (int i = 0; i <= n; i++) {
                nxt[SA[i]] =
                    ((i && c[SA[i - 1]] == c[SA[i]] && SA[i - 1] + j < n && c[SA[i - 1] + j / 2] == c[SA[i] + j / 2])
                         ? nxt[SA[i - 1]]
                         : i);
            }
            iota(cnt.begin(), cnt.end(), 0);
            copy(SA.begin(), SA.end(), c.begin());
            for (int i = 0; i <= n; i++) {
                if (c[i] - j >= 0) {
                    SA[cnt[nxt[c[i] - j]]++] = c[i] - j;
                }
            }
            nxt.swap(c);
        }
    }
    bool comp(const string& t, int si = 0, int ti = 0) {
        int sn = s.size(), tn = t.size();
        for (; si < sn && ti < tn; si++, ti++) {
            if (s[si] < t[ti]) return true;
            if (s[si] > t[ti]) return false;
        }
        return si >= sn && ti < tn;
    }
    int lower_bound(const string& t) {
        int lb = -1, ub = SA.size();
        while (ub - lb > 1) {
            int mid = (ub + lb) >> 1;
            (comp(t, SA[mid]) ? lb : ub) = mid;
        }
        return ub;
    }
    pair<int, int> lower_upper_bound(string& t) {
        int l = lower_bound(t);
        int lb = l - 1, ub = SA.size();
        t.back()++;
        while (ub - lb > 1) {
            int mid = (ub + lb) >> 1;
            (comp(t, SA[mid]) ? lb : ub) = mid;
        }
        t.back()--;
        return {l, ub};
    }
    int count(string& t) {
        pair<int, int> p = lower_upper_bound(t);
        return p.second - p.first;
    }
    int operator[](int i) const { return SA[i]; }
    int size() const { return s.size(); }
};