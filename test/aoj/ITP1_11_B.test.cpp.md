---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  - icon: ':heavy_check_mark:'
    path: util/Dice.hpp
    title: "\u30B5\u30A4\u30B3\u30ED"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/ITP1_11_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/ITP1_11_B
  bundledCode: "#line 1 \"test/aoj/ITP1_11_B.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_11_B\"\
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
    #line 6 \"util/Dice.hpp\"\n\nstruct Dice {\n    std::array<int, 6> surface;\n\n\
    \    Dice(int TOP = 1, int FRONT = 2) {\n        assert(1 <= TOP and TOP <= 6);\n\
    \        assert(1 <= FRONT and FRONT <= 6);\n        assert(TOP + FRONT != 7);\n\
    \        surface[0] = TOP;\n        surface[1] = FRONT;\n        surface[2] =\
    \ dice[TOP - 1][FRONT - 1];\n        surface[3] = 7 - surface[2];\n        surface[4]\
    \ = 7 - surface[1];\n        surface[5] = 7 - surface[0];\n    }\n\n    Dice(const\
    \ std::vector<int>& v) {\n        assert(v.size() == 6);\n        for (size_t\
    \ i = 0; i < 6; i++) surface[i] = v[i];\n    }\n\n    const int& top() const {\
    \ return surface[0]; }\n    const int& front() const { return surface[1]; }\n\
    \    const int& right() const { return surface[2]; }\n    const int& left() const\
    \ { return surface[3]; }\n    const int& back() const { return surface[4]; }\n\
    \    const int& bottom() const { return surface[5]; }\n    const int& operator[](int\
    \ k) const { return surface[k]; }\n\n    int& top() { return surface[0]; }\n \
    \   int& front() { return surface[1]; }\n    int& right() { return surface[2];\
    \ }\n    int& left() { return surface[3]; }\n    int& back() { return surface[4];\
    \ }\n    int& bottom() { return surface[5]; }\n    int& operator[](int k) { return\
    \ surface[k]; }\n\n    bool operator==(const Dice& d) const { return surface ==\
    \ d.surface; }\n    bool operator!=(const Dice& d) const { return surface != d.surface;\
    \ }\n    bool operator<(const Dice& d) const { return surface < d.surface; }\n\
    \n    int roll(int k) {  // x++, x--, y++, y--, turn right, turn left\n      \
    \  assert(0 <= k and k < 6);\n        int tmp = surface[code[k][0]];\n       \
    \ for (int i = 0; i < 3; i++) surface[code[k][i]] = surface[code[k][i + 1]];\n\
    \        surface[code[k][3]] = tmp;\n        return surface[0];\n    }\n\n   \
    \ int rollc(char c) {\n        for (int k = 0; k < 6; k++) {\n            if (direction[k]\
    \ != c) continue;\n            return roll(k);\n        }\n        assert(false);\n\
    \    }\n\n    int hash() const {\n        int res = 0;\n        for (size_t i\
    \ = 0; i < 6; i++) {\n            assert(1 <= surface[i] and surface[i] <= 6);\n\
    \            (res *= 6) += surface[i] - 1;\n        }\n        return res;\n \
    \   }\n\n    std::vector<Dice> make_all() {\n        std::vector<Dice> res;\n\
    \        for (int i = 0; i < 6; i++) {\n            Dice d(*this);\n         \
    \   if (i == 1) d.roll(2);\n            if (i == 2) d.roll(3);\n            if\
    \ (i == 3) d.roll(3), d.roll(3);\n            if (i == 4) d.roll(5);\n       \
    \     if (i == 5) d.roll(4);\n            for (int j = 0; j < 4; j++) {\n    \
    \            res.emplace_back(d);\n                d.roll(0);\n            }\n\
    \        }\n        return res;\n    }\n\n    Dice identifier() {\n        auto\
    \ dices = make_all();\n        return *min_element(dices.begin(), dices.end());\n\
    \    }\n\nprivate:\n    const int dice[6][6] = {{0, 3, 5, 2, 4, 0}, {4, 0, 1,\
    \ 6, 0, 3}, {2, 6, 0, 0, 1, 5},\n                            {5, 1, 0, 0, 6, 2},\
    \ {3, 0, 6, 1, 0, 4}, {0, 4, 2, 5, 3, 0}};\n    const int code[6][4] = {{0, 3,\
    \ 5, 2}, {0, 2, 5, 3}, {0, 1, 5, 4}, {0, 4, 5, 1}, {1, 2, 4, 3}, {1, 3, 4, 2}};\n\
    \    const char direction[6] = {'E', 'W', 'N', 'S', 'R', 'L'};\n};\n#line 5 \"\
    test/aoj/ITP1_11_B.test.cpp\"\n\nint main() {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n\
    \    vector<int> v(6);\n    for (int i = 0; i < 6; i++) cin >> v[i];\n\n    Dice\
    \ d(v);\n    auto ds = d.make_all();\n    map<pair<int, int>, int> mp;\n    for\
    \ (auto& x : ds) mp[{x.top(), x.front()}] = x.right();\n\n    int q;\n    cin\
    \ >> q;\n    for (; q--;) {\n        int t, f;\n        cin >> t >> f;\n     \
    \   cout << mp[{t, f}] << '\\n';\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_11_B\"\n\
    \n#include \"../../base.hpp\"\n#include \"../../util/Dice.hpp\"\n\nint main()\
    \ {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    vector<int> v(6);\n\
    \    for (int i = 0; i < 6; i++) cin >> v[i];\n\n    Dice d(v);\n    auto ds =\
    \ d.make_all();\n    map<pair<int, int>, int> mp;\n    for (auto& x : ds) mp[{x.top(),\
    \ x.front()}] = x.right();\n\n    int q;\n    cin >> q;\n    for (; q--;) {\n\
    \        int t, f;\n        cin >> t >> f;\n        cout << mp[{t, f}] << '\\\
    n';\n    }\n    return 0;\n}"
  dependsOn:
  - base.hpp
  - util/Dice.hpp
  isVerificationFile: true
  path: test/aoj/ITP1_11_B.test.cpp
  requiredBy: []
  timestamp: '2021-12-30 22:27:29+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/ITP1_11_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/ITP1_11_B.test.cpp
- /verify/test/aoj/ITP1_11_B.test.cpp.html
title: test/aoj/ITP1_11_B.test.cpp
---
