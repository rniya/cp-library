---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  - icon: ':heavy_check_mark:'
    path: math/floor_sum.hpp
    title: Sum of Floor of Linear
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/sum_of_floor_of_linear
    links:
    - https://judge.yosupo.jp/problem/sum_of_floor_of_linear
  bundledCode: "#line 1 \"test/yosupo/sum_of_floor_of_linear.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/sum_of_floor_of_linear\"\n\n#line 2 \"base.hpp\"\
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
    \ return true;\n    }\n    return false;\n}\n#line 3 \"math/floor_sum.hpp\"\n\n\
    /**\n * @brief Sum of Floor of Linear\n * docs docs/math/floor_sum.hpp\n */\n\
    long long floor_sum(long long n, long long m, long long a, long long b) {\n  \
    \  long long ans = 0;\n    if (a >= m) {\n        ans += (n - 1) * n * (a / m)\
    \ / 2;\n        a %= m;\n    }\n    if (b >= m) {\n        ans += n * (b / m);\n\
    \        b %= m;\n    }\n    long long y_max = (a * n + b) / m, x_max = y_max\
    \ * m - b;\n    if (y_max == 0) return ans;\n    ans += (n - (x_max + a - 1) /\
    \ a) * y_max;\n    ans += floor_sum(y_max, a, m, (a - x_max % a) % a);\n    return\
    \ ans;\n}\n#line 5 \"test/yosupo/sum_of_floor_of_linear.test.cpp\"\n\nint main()\
    \ {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    int T;\n    cin >>\
    \ T;\n\n    for (; T--;) {\n        int N, M, A, B;\n        cin >> N >> M >>\
    \ A >> B;\n        cout << floor_sum(N, M, A, B) << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_floor_of_linear\"\
    \n\n#include \"../../base.hpp\"\n#include \"../../math/floor_sum.hpp\"\n\nint\
    \ main() {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    int T;\n  \
    \  cin >> T;\n\n    for (; T--;) {\n        int N, M, A, B;\n        cin >> N\
    \ >> M >> A >> B;\n        cout << floor_sum(N, M, A, B) << '\\n';\n    }\n}"
  dependsOn:
  - base.hpp
  - math/floor_sum.hpp
  isVerificationFile: true
  path: test/yosupo/sum_of_floor_of_linear.test.cpp
  requiredBy: []
  timestamp: '2021-01-20 20:25:59+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/sum_of_floor_of_linear.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/sum_of_floor_of_linear.test.cpp
- /verify/test/yosupo/sum_of_floor_of_linear.test.cpp.html
title: test/yosupo/sum_of_floor_of_linear.test.cpp
---
