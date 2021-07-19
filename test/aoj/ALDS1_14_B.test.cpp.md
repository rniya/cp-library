---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  - icon: ':heavy_check_mark:'
    path: string/RollingHash.hpp
    title: Rolling Hash
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_B
  bundledCode: "#line 1 \"test/aoj/ALDS1_14_B.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_B\"\
    \n\n#line 2 \"base.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n#pragma\
    \ region Macros\ntypedef long long ll;\ntypedef __int128_t i128;\ntypedef unsigned\
    \ int uint;\ntypedef unsigned long long ull;\n#define ALL(x) (x).begin(), (x).end()\n\
    \ntemplate <typename T> istream& operator>>(istream& is, vector<T>& v) {\n   \
    \ for (T& x : v) is >> x;\n    return is;\n}\ntemplate <typename T> ostream& operator<<(ostream&\
    \ os, const vector<T>& v) {\n    for (int i = 0; i < (int)v.size(); i++) {\n \
    \       os << v[i] << (i + 1 == (int)v.size() ? \"\" : \" \");\n    }\n    return\
    \ os;\n}\ntemplate <typename T, typename U> ostream& operator<<(ostream& os, const\
    \ pair<T, U>& p) {\n    os << '(' << p.first << ',' << p.second << ')';\n    return\
    \ os;\n}\ntemplate <typename T, typename U> ostream& operator<<(ostream& os, const\
    \ map<T, U>& m) {\n    os << '{';\n    for (auto itr = m.begin(); itr != m.end();)\
    \ {\n        os << '(' << itr->first << ',' << itr->second << ')';\n        if\
    \ (++itr != m.end()) os << ',';\n    }\n    os << '}';\n    return os;\n}\ntemplate\
    \ <typename T, typename U> ostream& operator<<(ostream& os, const unordered_map<T,\
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
    \ os;\n}\n\ntemplate <int i, typename T> void print_tuple(ostream&, const T&)\
    \ {}\ntemplate <int i, typename T, typename H, class... Args> void print_tuple(ostream&\
    \ os, const T& t) {\n    if (i) os << ',';\n    os << get<i>(t);\n    print_tuple<i\
    \ + 1, T, Args...>(os, t);\n}\ntemplate <typename... Args> ostream& operator<<(ostream&\
    \ os, const tuple<Args...>& t) {\n    os << '{';\n    print_tuple<0, tuple<Args...>,\
    \ Args...>(os, t);\n    return os << '}';\n}\n\nvoid debug_out() { cerr << '\\\
    n'; }\ntemplate <class Head, class... Tail> void debug_out(Head&& head, Tail&&...\
    \ tail) {\n    cerr << head;\n    if (sizeof...(Tail) > 0) cerr << \", \";\n \
    \   debug_out(move(tail)...);\n}\n#ifdef LOCAL\n#define debug(...)           \
    \                                                        \\\n    cerr << \" \"\
    ;                                                                     \\\n   \
    \ cerr << #__VA_ARGS__ << \" :[\" << __LINE__ << \":\" << __FUNCTION__ << \"]\"\
    \ << '\\n'; \\\n    cerr << \" \";                                           \
    \                          \\\n    debug_out(__VA_ARGS__)\n#else\n#define debug(...)\
    \ 42\n#endif\n\ntemplate <typename T> T gcd(T x, T y) { return y != 0 ? gcd(y,\
    \ x % y) : x; }\ntemplate <typename T> T lcm(T x, T y) { return x / gcd(x, y)\
    \ * y; }\n\nint topbit(signed t) { return t == 0 ? -1 : 31 - __builtin_clz(t);\
    \ }\nint topbit(long long t) { return t == 0 ? -1 : 63 - __builtin_clzll(t); }\n\
    int botbit(signed a) { return a == 0 ? 32 : __builtin_ctz(a); }\nint botbit(long\
    \ long a) { return a == 0 ? 64 : __builtin_ctzll(a); }\nint popcount(signed t)\
    \ { return __builtin_popcount(t); }\nint popcount(long long t) { return __builtin_popcountll(t);\
    \ }\nbool ispow2(int i) { return i && (i & -i) == i; }\n\ntemplate <class T> T\
    \ ceil(T x, T y) {\n    assert(y >= 1);\n    return (x > 0 ? (x + y - 1) / y :\
    \ x / y);\n}\ntemplate <class T> T floor(T x, T y) {\n    assert(y >= 1);\n  \
    \  return (x > 0 ? x / y : (x - y + 1) / y);\n}\n\ntemplate <class T1, class T2>\
    \ inline bool chmin(T1& a, T2 b) {\n    if (a > b) {\n        a = b;\n       \
    \ return true;\n    }\n    return false;\n}\ntemplate <class T1, class T2> inline\
    \ bool chmax(T1& a, T2 b) {\n    if (a < b) {\n        a = b;\n        return\
    \ true;\n    }\n    return false;\n}\n#pragma endregion\n#line 3 \"string/RollingHash.hpp\"\
    \n\n/**\n * @brief Rolling Hash\n * @docs docs/string/RollingHash.md\n */\nclass\
    \ RollingHash {\n    using u64 = uint64_t;\n    using u128 = __uint128_t;\n  \
    \  static const u64 mod = (1ULL << 61) - 1;\n    const u64 base;\n    vector<u64>\
    \ hash, power;\n    static inline u64 add(u64 a, u64 b) {\n        if ((a += b)\
    \ >= mod) a -= mod;\n        return a;\n    }\n    static inline u64 mul(u64 a,\
    \ u64 b) {\n        u128 c = (u128)a * b;\n        return add(c >> 61, c & mod);\n\
    \    }\n\npublic:\n    static inline u64 generate_base() {\n        mt19937_64\
    \ mt(chrono::steady_clock::now().time_since_epoch().count());\n        uniform_int_distribution<u64>\
    \ rand(2, RollingHash::mod - 1);\n        return rand(mt);\n    }\n    RollingHash(u64\
    \ base = generate_base()) : base(base) {}\n    template <typename T> RollingHash(const\
    \ T& s, u64 base = generate_base()) : base(base) {\n        int n = s.size();\n\
    \        hash.assign(n + 1, 0);\n        power.assign(n + 1, 0);\n        power[0]\
    \ = 1;\n        for (int i = 0; i < n; i++) {\n            hash[i + 1] = add(mul(hash[i],\
    \ base), s[i]);\n            power[i + 1] = mul(power[i], base);\n        }\n\
    \    }\n    u64 query(int l, int r) const { return add(hash[r], mod - mul(hash[l],\
    \ power[r - l])); }\n    int lcp(int a, int b) const {\n        int len = min(hash.size()\
    \ - a, hash.size() - b);\n        int lb = 0, ub = len;\n        while (ub - lb\
    \ > 1) {\n            int mid = (lb + ub) >> 1;\n            (query(a, a + mid)\
    \ == query(b, b + mid) ? lb : ub) = mid;\n        }\n        return lb;\n    }\n\
    \    template <typename T> u64 get(const T& t) {\n        u64 res = 0;\n     \
    \   for (int i = 0; i < (int)t.size(); i++) res = add(mul(res, base), t[i]);\n\
    \        return res;\n    }\n};\n#line 5 \"test/aoj/ALDS1_14_B.test.cpp\"\n\n\
    int main() {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    string S,\
    \ T;\n    cin >> S >> T;\n\n    uint64_t base = RollingHash::generate_base();\n\
    \    RollingHash RH1(S, base), RH2(T, base);\n    int s = S.size(), t = T.size();\n\
    \n    for (int i = 0; i + t <= s; i++) {\n        if (RH1.query(i, i + t) == RH2.query(0,\
    \ t)) {\n            cout << i << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_B\"\
    \n\n#include \"../../base.hpp\"\n#include \"../../string/RollingHash.hpp\"\n\n\
    int main() {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    string S,\
    \ T;\n    cin >> S >> T;\n\n    uint64_t base = RollingHash::generate_base();\n\
    \    RollingHash RH1(S, base), RH2(T, base);\n    int s = S.size(), t = T.size();\n\
    \n    for (int i = 0; i + t <= s; i++) {\n        if (RH1.query(i, i + t) == RH2.query(0,\
    \ t)) {\n            cout << i << '\\n';\n        }\n    }\n}"
  dependsOn:
  - base.hpp
  - string/RollingHash.hpp
  isVerificationFile: true
  path: test/aoj/ALDS1_14_B.test.cpp
  requiredBy: []
  timestamp: '2021-07-19 14:45:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/ALDS1_14_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/ALDS1_14_B.test.cpp
- /verify/test/aoj/ALDS1_14_B.test.cpp.html
title: test/aoj/ALDS1_14_B.test.cpp
---
