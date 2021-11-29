---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  - icon: ':heavy_check_mark:'
    path: string/RollingHash2D.hpp
    title: Rolling Hash 2D
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_14_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_14_C
  bundledCode: "#line 1 \"test/aoj/ALDS1_14_C.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_14_C\"\
    \n\n#line 2 \"base.hpp\"\n#define LOCAL\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n#pragma region Macros\ntypedef long long ll;\ntypedef __int128_t i128;\n\
    typedef unsigned int uint;\ntypedef unsigned long long ull;\n#define ALL(x) (x).begin(),\
    \ (x).end()\n\ntemplate <typename T> istream& operator>>(istream& is, vector<T>&\
    \ v) {\n    for (T& x : v) is >> x;\n    return is;\n}\ntemplate <typename T>\
    \ ostream& operator<<(ostream& os, const vector<T>& v) {\n    for (size_t i =\
    \ 0; i < v.size(); i++) {\n        os << v[i] << (i + 1 == v.size() ? \"\" : \"\
    \ \");\n    }\n    return os;\n}\ntemplate <typename T, typename U> ostream& operator<<(ostream&\
    \ os, const pair<T, U>& p) {\n    os << '(' << p.first << ',' << p.second << ')';\n\
    \    return os;\n}\ntemplate <typename T, typename U> ostream& operator<<(ostream&\
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
    \ os, const deque<T>& v) {\n    for (size_t i = 0; i < v.size(); i++) {\n    \
    \    os << v[i] << (i + 1 == v.size() ? \"\" : \" \");\n    }\n    return os;\n\
    }\ntemplate <typename T, size_t N> ostream& operator<<(ostream& os, const array<T,\
    \ N>& v) {\n    for (size_t i = 0; i < N; i++) {\n        os << v[i] << (i + 1\
    \ == N ? \"\" : \" \");\n    }\n    return os;\n}\n\ntemplate <int i, typename\
    \ T> void print_tuple(ostream&, const T&) {}\ntemplate <int i, typename T, typename\
    \ H, class... Args> void print_tuple(ostream& os, const T& t) {\n    if (i) os\
    \ << ',';\n    os << get<i>(t);\n    print_tuple<i + 1, T, Args...>(os, t);\n\
    }\ntemplate <typename... Args> ostream& operator<<(ostream& os, const tuple<Args...>&\
    \ t) {\n    os << '{';\n    print_tuple<0, tuple<Args...>, Args...>(os, t);\n\
    \    return os << '}';\n}\n\nvoid debug_out() { cerr << '\\n'; }\ntemplate <class\
    \ Head, class... Tail> void debug_out(Head&& head, Tail&&... tail) {\n    cerr\
    \ << head;\n    if (sizeof...(Tail) > 0) cerr << \", \";\n    debug_out(move(tail)...);\n\
    }\n#ifdef LOCAL\n#define debug(...)                                          \
    \                         \\\n    cerr << \" \";                             \
    \                                        \\\n    cerr << #__VA_ARGS__ << \" :[\"\
    \ << __LINE__ << \":\" << __FUNCTION__ << \"]\" << '\\n'; \\\n    cerr << \" \"\
    ;                                                                     \\\n   \
    \ debug_out(__VA_ARGS__)\n#else\n#define debug(...) void(0)\n#endif\n\ntemplate\
    \ <typename T> T gcd(T x, T y) { return y != 0 ? gcd(y, x % y) : x; }\ntemplate\
    \ <typename T> T lcm(T x, T y) { return x / gcd(x, y) * y; }\n\nint topbit(signed\
    \ t) { return t == 0 ? -1 : 31 - __builtin_clz(t); }\nint topbit(long long t)\
    \ { return t == 0 ? -1 : 63 - __builtin_clzll(t); }\nint botbit(signed a) { return\
    \ a == 0 ? 32 : __builtin_ctz(a); }\nint botbit(long long a) { return a == 0 ?\
    \ 64 : __builtin_ctzll(a); }\nint popcount(signed t) { return __builtin_popcount(t);\
    \ }\nint popcount(long long t) { return __builtin_popcountll(t); }\nbool ispow2(int\
    \ i) { return i && (i & -i) == i; }\nlong long MSK(int n) { return (1LL << n)\
    \ - 1; }\n\ntemplate <class T> T ceil(T x, T y) {\n    assert(y >= 1);\n    return\
    \ (x > 0 ? (x + y - 1) / y : x / y);\n}\ntemplate <class T> T floor(T x, T y)\
    \ {\n    assert(y >= 1);\n    return (x > 0 ? x / y : (x - y + 1) / y);\n}\n\n\
    template <class T1, class T2> inline bool chmin(T1& a, T2 b) {\n    if (a > b)\
    \ {\n        a = b;\n        return true;\n    }\n    return false;\n}\ntemplate\
    \ <class T1, class T2> inline bool chmax(T1& a, T2 b) {\n    if (a < b) {\n  \
    \      a = b;\n        return true;\n    }\n    return false;\n}\n\ntemplate <typename\
    \ T> void mkuni(vector<T>& v) {\n    sort(v.begin(), v.end());\n    v.erase(unique(v.begin(),\
    \ v.end()), v.end());\n}\ntemplate <typename T> int lwb(const vector<T>& v, const\
    \ T& x) { return lower_bound(v.begin(), v.end(), x) - v.begin(); }\n#pragma endregion\n\
    #line 7 \"string/RollingHash2D.hpp\"\n\nstruct RollingHash2D {\n    static inline\
    \ uint64_t generate_base() {\n        std::mt19937_64 mt(std::chrono::steady_clock::now().time_since_epoch().count());\n\
    \        std::uniform_int_distribution<uint64_t> rand(2, RollingHash2D::mod -\
    \ 1);\n        return rand(mt);\n    }\n\n    RollingHash2D(uint64_t base0 = generate_base(),\
    \ uint64_t base1 = generate_base()) {\n        basis[0] = base0;\n        basis[1]\
    \ = base1;\n        power[0].assign(1, 1);\n        power[1].assign(1, 1);\n \
    \   }\n\n    template <typename T> std::vector<std::vector<uint64_t>> build(const\
    \ T& s) const {\n        int n = s.size(), m = s[0].size();\n        std::vector<std::vector<uint64_t>>\
    \ hash(n + 1, std::vector<uint64_t>(m + 1, 0));\n        for (int i = 0; i < n;\
    \ i++) {\n            for (int j = 0; j < m; j++) {\n                hash[i +\
    \ 1][j + 1] = add(sub(add(mul(hash[i][j + 1], basis[0]), mul(hash[i + 1][j], basis[1])),\n\
    \                                             mul(hash[i][j], mul(basis[0], basis[1]))),\n\
    \                                         s[i][j]);\n            }\n        }\n\
    \        return hash;\n    }\n\n    template <typename T> uint64_t get(const T&\
    \ s) const {\n        uint64_t res = 0;\n        for (size_t i = 0; i < s.size();\
    \ i++) {\n            uint64_t sum = 0;\n            for (const auto& x : s[i])\
    \ sum = add(mul(sum, basis[1]), x);\n            res = add(mul(res, basis[0]),\
    \ sum);\n        }\n        return res;\n    }\n\n    uint64_t query(const std::vector<std::vector<uint64_t>>&\
    \ hash, int xl, int xr, int yl, int yr) {\n        assert(0 <= xl and xl <= xr\
    \ and 0 <= yl and yl <= yr);\n        extend(0, xr - xl);\n        extend(1, yr\
    \ - yl);\n        return add(sub(sub(hash[xr][yr], mul(hash[xl][yr], power[0][xr\
    \ - xl])), mul(hash[xr][yl], power[1][yr - yl])),\n                   mul(hash[xl][yl],\
    \ mul(power[0][xr - xl], power[1][yr - yl])));\n    }\n\nprivate:\n    static\
    \ constexpr uint64_t mod = (1ULL << 61) - 1;\n    uint64_t basis[2];\n    std::vector<uint64_t>\
    \ power[2];\n\n    static inline uint64_t add(uint64_t a, uint64_t b) {\n    \
    \    if ((a += b) >= mod) a -= mod;\n        return a;\n    }\n\n    static inline\
    \ uint64_t sub(uint64_t a, uint64_t b) { return b == 0 ? a : add(a, mod - b);\
    \ }\n\n    static inline uint64_t mul(uint64_t a, uint64_t b) {\n        __uint128_t\
    \ c = (__uint128_t)a * b;\n        return add(c >> 61, c & mod);\n    }\n\n  \
    \  inline void extend(int x, size_t len) {\n        if (power[x].size() > len)\
    \ return;\n        size_t pre = power[x].size();\n        power[x].resize(len\
    \ + 1);\n        for (size_t i = pre - 1; i < len; i++) power[x][i + 1] = mul(power[x][i],\
    \ basis[x]);\n    }\n};\n\n/**\n * @brief Rolling Hash 2D\n * @docs docs/string/RollingHash2D.md\n\
    \ */\n#line 5 \"test/aoj/ALDS1_14_C.test.cpp\"\n\nint main() {\n    cin.tie(0);\n\
    \    ios::sync_with_stdio(false);\n    int H, W;\n    cin >> H >> W;\n    vector<string>\
    \ S(H);\n    for (auto& s : S) cin >> s;\n    int R, C;\n    cin >> R >> C;\n\
    \    vector<string> T(R);\n    for (auto& t : T) cin >> t;\n\n    RollingHash2D\
    \ RH;\n    auto a = RH.build(S);\n    auto correct = RH.get(T);\n\n    for (int\
    \ i = 0; i + R <= H; i++) {\n        for (int j = 0; j + C <= W; j++) {\n    \
    \        if (RH.query(a, i, i + R, j, j + C) == correct) {\n                cout\
    \ << i << ' ' << j << '\\n';\n            }\n        }\n    }\n    return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_14_C\"\n\
    \n#include \"../../base.hpp\"\n#include \"../../string/RollingHash2D.hpp\"\n\n\
    int main() {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    int H, W;\n\
    \    cin >> H >> W;\n    vector<string> S(H);\n    for (auto& s : S) cin >> s;\n\
    \    int R, C;\n    cin >> R >> C;\n    vector<string> T(R);\n    for (auto& t\
    \ : T) cin >> t;\n\n    RollingHash2D RH;\n    auto a = RH.build(S);\n    auto\
    \ correct = RH.get(T);\n\n    for (int i = 0; i + R <= H; i++) {\n        for\
    \ (int j = 0; j + C <= W; j++) {\n            if (RH.query(a, i, i + R, j, j +\
    \ C) == correct) {\n                cout << i << ' ' << j << '\\n';\n        \
    \    }\n        }\n    }\n    return 0;\n}"
  dependsOn:
  - base.hpp
  - string/RollingHash2D.hpp
  isVerificationFile: true
  path: test/aoj/ALDS1_14_C.test.cpp
  requiredBy: []
  timestamp: '2021-10-31 14:57:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/ALDS1_14_C.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/ALDS1_14_C.test.cpp
- /verify/test/aoj/ALDS1_14_C.test.cpp.html
title: test/aoj/ALDS1_14_C.test.cpp
---
