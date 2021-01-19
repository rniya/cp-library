---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/associative_array
    links:
    - https://judge.yosupo.jp/problem/associative_array
  bundledCode: "#line 1 \"test/yosupo/associative_array.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/associative_array\"\n\n#line 2 \"base.hpp\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\nconst long long MOD = 1000000007;\n\
    // const long long MOD=998244353;\nconst int INF = 1e9;\nconst long long IINF\
    \ = 1e18;\nconst int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};\nconst char\
    \ dir[4] = {'D', 'R', 'U', 'L'};\n#define LOCAL\ntypedef long long ll;\ntypedef\
    \ __int128_t i128;\ntypedef unsigned int uint;\ntypedef unsigned long long ull;\n\
    #define ALL(x) (x).begin(), (x).end()\n\ntemplate <typename T> istream& operator>>(istream&\
    \ is, vector<T>& v) {\n    for (T& x : v) is >> x;\n    return is;\n}\ntemplate\
    \ <typename T> ostream& operator<<(ostream& os, const vector<T>& v) {\n    for\
    \ (int i = 0; i < v.size(); i++) {\n        os << v[i] << (i + 1 == v.size() ?\
    \ \"\" : \" \");\n    }\n    return os;\n}\ntemplate <typename T, typename U>\
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
    \ os, const deque<T>& v) {\n    for (int i = 0; i < v.size(); i++) {\n       \
    \ os << v[i] << (i + 1 == v.size() ? \"\" : \" \");\n    }\n    return os;\n}\n\
    \nvoid debug_out() { cerr << '\\n'; }\ntemplate <class Head, class... Tail> void\
    \ debug_out(Head&& head, Tail&&... tail) {\n    cerr << head;\n    if (sizeof...(Tail)\
    \ > 0) cerr << \", \";\n    debug_out(move(tail)...);\n}\n#ifdef LOCAL\n#define\
    \ debug(...)                                                                 \
    \  \\\n    cerr << \" \";                                                    \
    \                 \\\n    cerr << #__VA_ARGS__ << \" :[\" << __LINE__ << \":\"\
    \ << __FUNCTION__ << \"]\" << '\\n'; \\\n    cerr << \" \";                  \
    \                                                   \\\n    debug_out(__VA_ARGS__)\n\
    #else\n#define debug(...) 42\n#endif\n\ntemplate <typename T> T gcd(T x, T y)\
    \ { return y != 0 ? gcd(y, x % y) : x; }\ntemplate <typename T> T lcm(T x, T y)\
    \ { return x / gcd(x, y) * y; }\n\ntemplate <class T1, class T2> inline bool chmin(T1&\
    \ a, T2 b) {\n    if (a > b) {\n        a = b;\n        return true;\n    }\n\
    \    return false;\n}\ntemplate <class T1, class T2> inline bool chmax(T1& a,\
    \ T2 b) {\n    if (a < b) {\n        a = b;\n        return true;\n    }\n   \
    \ return false;\n}\n#line 4 \"test/yosupo/associative_array.test.cpp\"\n\nint\
    \ main(){\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    int Q; cin >>\
    \ Q;\n\n    map<long long,long long> a;\n    for (;Q--;){\n        int t; long\
    \ long k; cin >> t >> k;\n        if (!t){\n            long long v; cin >> v;\n\
    \            a[k]=v;\n        } else cout << a[k] << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/associative_array\"\n\n\
    #include \"../../base.hpp\"\n\nint main(){\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n\
    \    int Q; cin >> Q;\n\n    map<long long,long long> a;\n    for (;Q--;){\n \
    \       int t; long long k; cin >> t >> k;\n        if (!t){\n            long\
    \ long v; cin >> v;\n            a[k]=v;\n        } else cout << a[k] << '\\n';\n\
    \    }\n}"
  dependsOn:
  - base.hpp
  isVerificationFile: true
  path: test/yosupo/associative_array.test.cpp
  requiredBy: []
  timestamp: '2021-01-19 13:16:33+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/associative_array.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/associative_array.test.cpp
- /verify/test/yosupo/associative_array.test.cpp.html
title: test/yosupo/associative_array.test.cpp
---
