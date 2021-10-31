---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  - icon: ':heavy_check_mark:'
    path: math/elementary_math.hpp
    title: elementary math
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E
  bundledCode: "#line 1 \"test/aoj/NTL_1_E.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E\"\
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
    #line 4 \"math/elementary_math.hpp\"\n\nnamespace elementary_math {\n\ntemplate\
    \ <typename T> std::vector<T> divisor(T n) {\n    std::vector<T> res;\n    for\
    \ (T i = 1; i * i <= n; i++) {\n        if (n % i == 0) {\n            res.emplace_back(i);\n\
    \            if (i * i != n) res.emplace_back(n / i);\n        }\n    }\n    return\
    \ res;\n}\n\ntemplate <typename T> std::vector<std::pair<T, int>> prime_factor(T\
    \ n) {\n    std::vector<std::pair<T, int>> res;\n    for (T p = 2; p * p <= n;\
    \ p++) {\n        if (n % p == 0) {\n            res.emplace_back(p, 0);\n   \
    \         while (n % p == 0) {\n                res.back().second++;\n       \
    \         n /= p;\n            }\n        }\n    }\n    if (n > 1) res.emplace_back(n,\
    \ 1);\n    return res;\n}\n\nstd::vector<int> osa_k(int n) {\n    std::vector<int>\
    \ min_factor(n + 1, 0);\n    for (int i = 2; i <= n; i++) {\n        if (min_factor[i])\
    \ continue;\n        for (int j = i; j <= n; j += i) {\n            if (!min_factor[j])\
    \ {\n                min_factor[j] = i;\n            }\n        }\n    }\n   \
    \ return min_factor;\n}\n\nstd::vector<int> prime_factor(const std::vector<int>&\
    \ min_factor, int n) {\n    std::vector<int> res;\n    while (n > 1) {\n     \
    \   res.emplace_back(min_factor[n]);\n        n /= min_factor[n];\n    }\n   \
    \ return res;\n}\n\nlong long modpow(long long x, long long n, long long mod)\
    \ {\n    assert(0 <= n && 1 <= mod && mod < (1LL << 31));\n    if (mod == 1) return\
    \ 0;\n    x %= mod;\n    long long res = 1;\n    while (n > 0) {\n        if (n\
    \ & 1) res = res * x % mod;\n        x = x * x % mod;\n        n >>= 1;\n    }\n\
    \    return res;\n}\n\nlong long extgcd(long long a, long long b, long long& x,\
    \ long long& y) {\n    long long d = a;\n    if (b != 0) {\n        d = extgcd(b,\
    \ a % b, y, x);\n        y -= (a / b) * x;\n    } else\n        x = 1, y = 0;\n\
    \    return d;\n}\n\nlong long inv_mod(long long a, long long mod) {\n    assert(1\
    \ <= mod);\n    long long x, y;\n    if (extgcd(a, mod, x, y) != 1) return -1;\n\
    \    return (mod + x % mod) % mod;\n}\n\ntemplate <typename T> T euler_phi(T n)\
    \ {\n    auto pf = prime_factor(n);\n    T res = n;\n    for (const auto& p :\
    \ pf) {\n        res /= p.first;\n        res *= p.first - 1;\n    }\n    return\
    \ res;\n}\n\nstd::vector<int> euler_phi_table(int n) {\n    std::vector<int> res(n\
    \ + 1, 0);\n    iota(res.begin(), res.end(), 0);\n    for (int i = 2; i <= n;\
    \ i++) {\n        if (res[i] != i) continue;\n        for (int j = i; j <= n;\
    \ j += i) res[j] = res[j] / i * (i - 1);\n    }\n    return res;\n}\n\n// minimum\
    \ i > 0 s.t. x^i \\equiv 1 \\pmod{m}\ntemplate <typename T> T order(T x, T m)\
    \ {\n    T n = euler_phi(m);\n    auto cand = divisor(n);\n    sort(cand.begin(),\
    \ cand.end());\n    for (auto& i : cand) {\n        if (modpow(x, i, m) == 1)\
    \ {\n            return i;\n        }\n    }\n    return -1;\n}\n\n}  // namespace\
    \ elementary_math\n\n/**\n * @brief elementary math\n * @docs docs/math/elementary_math.md\n\
    \ */\n#line 5 \"test/aoj/NTL_1_E.test.cpp\"\n\nint main() {\n    cin.tie(0);\n\
    \    ios::sync_with_stdio(false);\n    long long a, b, x, y;\n    cin >> a >>\
    \ b;\n    elementary_math::extgcd(a, b, x, y);\n    cout << x << ' ' << y << '\\\
    n';\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E\"\
    \n\n#include \"../../base.hpp\"\n#include \"../../math/elementary_math.hpp\"\n\
    \nint main() {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    long long\
    \ a, b, x, y;\n    cin >> a >> b;\n    elementary_math::extgcd(a, b, x, y);\n\
    \    cout << x << ' ' << y << '\\n';\n}"
  dependsOn:
  - base.hpp
  - math/elementary_math.hpp
  isVerificationFile: true
  path: test/aoj/NTL_1_E.test.cpp
  requiredBy: []
  timestamp: '2021-10-31 14:57:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/NTL_1_E.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/NTL_1_E.test.cpp
- /verify/test/aoj/NTL_1_E.test.cpp.html
title: test/aoj/NTL_1_E.test.cpp
---
