---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  - icon: ':heavy_check_mark:'
    path: string/LongestCommonPrefixArray.hpp
    title: Longest Common Prefix Array
  - icon: ':heavy_check_mark:'
    path: string/SuffixArray.hpp
    title: Suffix Array
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/number_of_substrings
    links:
    - https://judge.yosupo.jp/problem/number_of_substrings
  bundledCode: "#line 1 \"test/yosupo/number_of_substrings.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/number_of_substrings\"\n\n#line 2 \"base.hpp\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\ntypedef long long ll;\ntypedef\
    \ __int128_t i128;\ntypedef unsigned int uint;\ntypedef unsigned long long ull;\n\
    #define ALL(x) (x).begin(), (x).end()\n\ntemplate <typename T> istream& operator>>(istream&\
    \ is, vector<T>& v) {\n    for (T& x : v) is >> x;\n    return is;\n}\ntemplate\
    \ <typename T> ostream& operator<<(ostream& os, const vector<T>& v) {\n    for\
    \ (int i = 0; i < (int)v.size(); i++) {\n        os << v[i] << (i + 1 == (int)v.size()\
    \ ? \"\" : \" \");\n    }\n    return os;\n}\ntemplate <typename T, typename U>\
    \ ostream& operator<<(ostream& os, const pair<T, U>& p) {\n    os << '(' << p.first\
    \ << ',' << p.second << ')';\n    return os;\n}\ntemplate <typename T, typename\
    \ U, typename V> ostream& operator<<(ostream& os, const tuple<T, U, V>& t) {\n\
    \    os << '(' << get<0>(t) << ',' << get<1>(t) << ',' << get<2>(t) << ')';\n\
    \    return os;\n}\ntemplate <typename T, typename U, typename V, typename W>\
    \ ostream& operator<<(ostream& os, const tuple<T, U, V, W>& t) {\n    os << '('\
    \ << get<0>(t) << ',' << get<1>(t) << ',' << get<2>(t) << ',' << get<3>(t) <<\
    \ ')';\n    return os;\n}\ntemplate <typename T, typename U> ostream& operator<<(ostream&\
    \ os, const map<T, U>& m) {\n    os << '{';\n    for (auto itr = m.begin(); itr\
    \ != m.end();) {\n        os << '(' << itr->first << ',' << itr->second << ')';\n\
    \        if (++itr != m.end()) os << ',';\n    }\n    os << '}';\n    return os;\n\
    }\ntemplate <typename T, typename U> ostream& operator<<(ostream& os, const unordered_map<T,\
    \ U>& m) {\n    os << '{';\n    for (auto itr = m.begin(); itr != m.end();) {\n\
    \        os << '(' << itr->first << ',' << itr->second << ')';\n        if (++itr\
    \ != m.end()) os << ',';\n    }\n    os << '}';\n    return os;\n}\ntemplate <typename\
    \ T> ostream& operator<<(ostream& os, const set<T>& s) {\n    os << '{';\n   \
    \ for (auto itr = s.begin(); itr != s.end();) {\n        os << *itr;\n       \
    \ if (++itr != s.end()) os << ',';\n    }\n    os << '}';\n    return os;\n}\n\
    template <typename T> ostream& operator<<(ostream& os, const multiset<T>& s) {\n\
    \    os << '{';\n    for (auto itr = s.begin(); itr != s.end();) {\n        os\
    \ << *itr;\n        if (++itr != s.end()) os << ',';\n    }\n    os << '}';\n\
    \    return os;\n}\ntemplate <typename T> ostream& operator<<(ostream& os, const\
    \ unordered_set<T>& s) {\n    os << '{';\n    for (auto itr = s.begin(); itr !=\
    \ s.end();) {\n        os << *itr;\n        if (++itr != s.end()) os << ',';\n\
    \    }\n    os << '}';\n    return os;\n}\ntemplate <typename T> ostream& operator<<(ostream&\
    \ os, const deque<T>& v) {\n    for (int i = 0; i < (int)v.size(); i++) {\n  \
    \      os << v[i] << (i + 1 == (int)v.size() ? \"\" : \" \");\n    }\n    return\
    \ os;\n}\n\nvoid debug_out() { cerr << '\\n'; }\ntemplate <class Head, class...\
    \ Tail> void debug_out(Head&& head, Tail&&... tail) {\n    cerr << head;\n   \
    \ if (sizeof...(Tail) > 0) cerr << \", \";\n    debug_out(move(tail)...);\n}\n\
    #ifdef LOCAL\n#define debug(...)                                             \
    \                      \\\n    cerr << \" \";                                \
    \                                     \\\n    cerr << #__VA_ARGS__ << \" :[\"\
    \ << __LINE__ << \":\" << __FUNCTION__ << \"]\" << '\\n'; \\\n    cerr << \" \"\
    ;                                                                     \\\n   \
    \ debug_out(__VA_ARGS__)\n#else\n#define debug(...) 42\n#endif\n\ntemplate <typename\
    \ T> T gcd(T x, T y) { return y != 0 ? gcd(y, x % y) : x; }\ntemplate <typename\
    \ T> T lcm(T x, T y) { return x / gcd(x, y) * y; }\n\ntemplate <class T1, class\
    \ T2> inline bool chmin(T1& a, T2 b) {\n    if (a > b) {\n        a = b;\n   \
    \     return true;\n    }\n    return false;\n}\ntemplate <class T1, class T2>\
    \ inline bool chmax(T1& a, T2 b) {\n    if (a < b) {\n        a = b;\n       \
    \ return true;\n    }\n    return false;\n}\n#line 3 \"string/SuffixArray.hpp\"\
    \n\n/**\n * @brief Suffix Array\n * @docs docs/string/SuffixArray.md\n */\nstruct\
    \ SuffixArray {\n    string s;\n    vector<int> SA;\n    SuffixArray(const string&\
    \ S) : s(S) {\n        int n = s.size();\n        s.push_back('$');\n        SA.resize(n\
    \ + 1);\n        iota(SA.begin(), SA.end(), 0);\n        sort(SA.begin(), SA.end(),\
    \ [&](int a, int b) { return s[a] == s[b] ? a > b : s[a] < s[b]; });\n       \
    \ vector<int> c(s.begin(), s.end()), cnt(n + 1), nxt(n + 1);\n        for (int\
    \ j = 1; j <= n; j <<= 1) {\n            for (int i = 0; i <= n; i++) {\n    \
    \            nxt[SA[i]] =\n                    ((i && c[SA[i - 1]] == c[SA[i]]\
    \ && SA[i - 1] + j < n && c[SA[i - 1] + j / 2] == c[SA[i] + j / 2])\n        \
    \                 ? nxt[SA[i - 1]]\n                         : i);\n         \
    \   }\n            iota(cnt.begin(), cnt.end(), 0);\n            copy(SA.begin(),\
    \ SA.end(), c.begin());\n            for (int i = 0; i <= n; i++) {\n        \
    \        if (c[i] - j >= 0) {\n                    SA[cnt[nxt[c[i] - j]]++] =\
    \ c[i] - j;\n                }\n            }\n            nxt.swap(c);\n    \
    \    }\n    }\n    bool comp(const string& t, int si = 0, int ti = 0) {\n    \
    \    int sn = s.size(), tn = t.size();\n        for (; si < sn && ti < tn; si++,\
    \ ti++) {\n            if (s[si] < t[ti]) return true;\n            if (s[si]\
    \ > t[ti]) return false;\n        }\n        return si >= sn && ti < tn;\n   \
    \ }\n    int lower_bound(const string& t) {\n        int lb = -1, ub = SA.size();\n\
    \        while (ub - lb > 1) {\n            int mid = (ub + lb) >> 1;\n      \
    \      (comp(t, SA[mid]) ? lb : ub) = mid;\n        }\n        return ub;\n  \
    \  }\n    pair<int, int> lower_upper_bound(string& t) {\n        int l = lower_bound(t);\n\
    \        int lb = l - 1, ub = SA.size();\n        t.back()++;\n        while (ub\
    \ - lb > 1) {\n            int mid = (ub + lb) >> 1;\n            (comp(t, SA[mid])\
    \ ? lb : ub) = mid;\n        }\n        t.back()--;\n        return {l, ub};\n\
    \    }\n    int count(string& t) {\n        pair<int, int> p = lower_upper_bound(t);\n\
    \        return p.second - p.first;\n    }\n    int operator[](int i) const {\
    \ return SA[i]; }\n    int size() const { return s.size(); }\n};\n#line 4 \"string/LongestCommonPrefixArray.hpp\"\
    \n\n/**\n * @brief Longest Common Prefix Array\n * @docs docs/string/LongestCommonPrefixArray.md\n\
    \ */\nstruct LongestCommonPrefixArray {\n    SuffixArray SA;\n    vector<int>\
    \ LCP, rank, lookup;\n    vector<vector<int>> dat;\n    LongestCommonPrefixArray(const\
    \ string& s) : SA(s) {\n        int n = s.size();\n        LCP.resize(n);\n  \
    \      rank.resize(n + 1);\n        for (int i = 0; i <= n; i++) rank[SA[i]] =\
    \ i;\n        LCP[0] = 0;\n        for (int i = 0, t = 0; i < n; i++) {\n    \
    \        if (t) --t;\n            for (int j = SA[rank[i] - 1]; max(i, j) + t\
    \ < n && s[i + t] == s[j + t]; t++)\n                ;\n            LCP[rank[i]\
    \ - 1] = t;\n        }\n        int h = 1;\n        while ((1 << h) <= n) h++;\n\
    \        dat.assign(h, vector<int>(n));\n        lookup.assign(n + 1, 0);\n  \
    \      for (int i = 2; i <= n; i++) lookup[i] = lookup[i >> 1] + 1;\n        for\
    \ (int j = 0; j < n; j++) dat[0][j] = LCP[j];\n        for (int i = 1, mask =\
    \ 1; i < h; i++, mask <<= 1) {\n            for (int j = 0; j < n; j++) {\n  \
    \              dat[i][j] = min(dat[i - 1][j], dat[i - 1][min(j + mask, n - 1)]);\n\
    \            }\n        }\n    }\n    int query(int a, int b) {\n        if (a\
    \ > b) swap(a, b);\n        int d = lookup[b - a];\n        return min(dat[d][a],\
    \ dat[d][b - (1 << d)]);\n    }\n    // longest common prefix of s[a...] and s[b...]\n\
    \    int lcp(int a, int b) { return query(rank[a], rank[b]); }\n    int operator[](int\
    \ i) const { return LCP[i]; }\n    int size() const { return LCP.size(); }\n};\n\
    #line 5 \"test/yosupo/number_of_substrings.test.cpp\"\n\nint main() {\n    cin.tie(0);\n\
    \    ios::sync_with_stdio(false);\n    string S;\n    cin >> S;\n    int N = S.size();\n\
    \n    LongestCommonPrefixArray LCP(S);\n\n    long long ans = 0;\n    for (int\
    \ i = 0; i < N; i++) {\n        ans += N - LCP.SA[i + 1] - LCP[i];\n    }\n\n\
    \    cout << ans << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/number_of_substrings\"\n\
    \n#include \"../../base.hpp\"\n#include \"../../string/LongestCommonPrefixArray.hpp\"\
    \n\nint main() {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    string\
    \ S;\n    cin >> S;\n    int N = S.size();\n\n    LongestCommonPrefixArray LCP(S);\n\
    \n    long long ans = 0;\n    for (int i = 0; i < N; i++) {\n        ans += N\
    \ - LCP.SA[i + 1] - LCP[i];\n    }\n\n    cout << ans << '\\n';\n}"
  dependsOn:
  - base.hpp
  - string/LongestCommonPrefixArray.hpp
  - string/SuffixArray.hpp
  isVerificationFile: true
  path: test/yosupo/number_of_substrings.test.cpp
  requiredBy: []
  timestamp: '2021-01-20 20:25:59+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/number_of_substrings.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/number_of_substrings.test.cpp
- /verify/test/yosupo/number_of_substrings.test.cpp.html
title: test/yosupo/number_of_substrings.test.cpp
---
