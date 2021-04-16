---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1181.test.cpp
    title: test/aoj/1181.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/util/Dice.md
    document_title: "\u30B5\u30A4\u30B3\u30ED"
    links: []
  bundledCode: "#line 2 \"base.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    typedef long long ll;\ntypedef __int128_t i128;\ntypedef unsigned int uint;\n\
    typedef unsigned long long ull;\n#define ALL(x) (x).begin(), (x).end()\n\ntemplate\
    \ <typename T> istream& operator>>(istream& is, vector<T>& v) {\n    for (T& x\
    \ : v) is >> x;\n    return is;\n}\ntemplate <typename T> ostream& operator<<(ostream&\
    \ os, const vector<T>& v) {\n    for (int i = 0; i < (int)v.size(); i++) {\n \
    \       os << v[i] << (i + 1 == (int)v.size() ? \"\" : \" \");\n    }\n    return\
    \ os;\n}\ntemplate <typename T, typename U> ostream& operator<<(ostream& os, const\
    \ pair<T, U>& p) {\n    os << '(' << p.first << ',' << p.second << ')';\n    return\
    \ os;\n}\ntemplate <typename T, typename U, typename V> ostream& operator<<(ostream&\
    \ os, const tuple<T, U, V>& t) {\n    os << '(' << get<0>(t) << ',' << get<1>(t)\
    \ << ',' << get<2>(t) << ')';\n    return os;\n}\ntemplate <typename T, typename\
    \ U, typename V, typename W> ostream& operator<<(ostream& os, const tuple<T, U,\
    \ V, W>& t) {\n    os << '(' << get<0>(t) << ',' << get<1>(t) << ',' << get<2>(t)\
    \ << ',' << get<3>(t) << ')';\n    return os;\n}\ntemplate <typename T, typename\
    \ U> ostream& operator<<(ostream& os, const map<T, U>& m) {\n    os << '{';\n\
    \    for (auto itr = m.begin(); itr != m.end();) {\n        os << '(' << itr->first\
    \ << ',' << itr->second << ')';\n        if (++itr != m.end()) os << ',';\n  \
    \  }\n    os << '}';\n    return os;\n}\ntemplate <typename T, typename U> ostream&\
    \ operator<<(ostream& os, const unordered_map<T, U>& m) {\n    os << '{';\n  \
    \  for (auto itr = m.begin(); itr != m.end();) {\n        os << '(' << itr->first\
    \ << ',' << itr->second << ')';\n        if (++itr != m.end()) os << ',';\n  \
    \  }\n    os << '}';\n    return os;\n}\ntemplate <typename T> ostream& operator<<(ostream&\
    \ os, const set<T>& s) {\n    os << '{';\n    for (auto itr = s.begin(); itr !=\
    \ s.end();) {\n        os << *itr;\n        if (++itr != s.end()) os << ',';\n\
    \    }\n    os << '}';\n    return os;\n}\ntemplate <typename T> ostream& operator<<(ostream&\
    \ os, const multiset<T>& s) {\n    os << '{';\n    for (auto itr = s.begin();\
    \ itr != s.end();) {\n        os << *itr;\n        if (++itr != s.end()) os <<\
    \ ',';\n    }\n    os << '}';\n    return os;\n}\ntemplate <typename T> ostream&\
    \ operator<<(ostream& os, const unordered_set<T>& s) {\n    os << '{';\n    for\
    \ (auto itr = s.begin(); itr != s.end();) {\n        os << *itr;\n        if (++itr\
    \ != s.end()) os << ',';\n    }\n    os << '}';\n    return os;\n}\ntemplate <typename\
    \ T> ostream& operator<<(ostream& os, const deque<T>& v) {\n    for (int i = 0;\
    \ i < (int)v.size(); i++) {\n        os << v[i] << (i + 1 == (int)v.size() ? \"\
    \" : \" \");\n    }\n    return os;\n}\n\nvoid debug_out() { cerr << '\\n'; }\n\
    template <class Head, class... Tail> void debug_out(Head&& head, Tail&&... tail)\
    \ {\n    cerr << head;\n    if (sizeof...(Tail) > 0) cerr << \", \";\n    debug_out(move(tail)...);\n\
    }\n#ifdef LOCAL\n#define debug(...)                                          \
    \                         \\\n    cerr << \" \";                             \
    \                                        \\\n    cerr << #__VA_ARGS__ << \" :[\"\
    \ << __LINE__ << \":\" << __FUNCTION__ << \"]\" << '\\n'; \\\n    cerr << \" \"\
    ;                                                                     \\\n   \
    \ debug_out(__VA_ARGS__)\n#else\n#define debug(...) 42\n#endif\n\ntemplate <typename\
    \ T> T gcd(T x, T y) { return y != 0 ? gcd(y, x % y) : x; }\ntemplate <typename\
    \ T> T lcm(T x, T y) { return x / gcd(x, y) * y; }\n\ntemplate <class T1, class\
    \ T2> inline bool chmin(T1& a, T2 b) {\n    if (a > b) {\n        a = b;\n   \
    \     return true;\n    }\n    return false;\n}\ntemplate <class T1, class T2>\
    \ inline bool chmax(T1& a, T2 b) {\n    if (a < b) {\n        a = b;\n       \
    \ return true;\n    }\n    return false;\n}\n#line 3 \"util/Dice.hpp\"\n\n/**\n\
    \ * @brief \u30B5\u30A4\u30B3\u30ED\n * @docs docs/util/Dice.md\n */\nstruct Dice\
    \ {\n    int surface[6];\n    int top() { return surface[0]; }\n    int south()\
    \ { return surface[1]; }\n    int east() { return surface[2]; }\n    int west()\
    \ { return surface[3]; }\n    int north() { return surface[4]; }\n    int bottom()\
    \ { return surface[5]; }\n    int operator[](int i) const { return surface[i];\
    \ }\n    const int dice[6][6] = {{0, 3, 5, 2, 4, 0}, {4, 0, 1, 6, 0, 3}, {2, 6,\
    \ 0, 0, 1, 5},\n                            {5, 1, 0, 0, 6, 2}, {3, 0, 6, 1, 0,\
    \ 4}, {0, 4, 2, 5, 3, 0}};\n    const int code[6][4] = {{0, 3, 5, 2}, {0, 2, 5,\
    \ 3}, {0, 1, 5, 4}, {0, 4, 5, 1}, {1, 2, 4, 3}, {1, 3, 4, 2}};\n    const string\
    \ direction = \"EWNSRL\";\n    Dice(int TOP, int FRONT) {\n        surface[0]\
    \ = TOP;\n        surface[1] = FRONT;\n        surface[2] = dice[TOP - 1][FRONT\
    \ - 1];\n        surface[3] = 7 - surface[2];\n        surface[4] = 7 - surface[1];\n\
    \        surface[5] = 7 - surface[0];\n    }\n    void roll(char c) {\n      \
    \  for (int i = 0; i < 6; i++) {\n            if (direction[i] != c) continue;\n\
    \            int tmp = surface[code[i][0]];\n            surface[code[i][0]] =\
    \ surface[code[i][1]];\n            surface[code[i][1]] = surface[code[i][2]];\n\
    \            surface[code[i][2]] = surface[code[i][3]];\n            surface[code[i][3]]\
    \ = tmp;\n        }\n    }\n};\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n/**\n * @brief \u30B5\u30A4\u30B3\
    \u30ED\n * @docs docs/util/Dice.md\n */\nstruct Dice {\n    int surface[6];\n\
    \    int top() { return surface[0]; }\n    int south() { return surface[1]; }\n\
    \    int east() { return surface[2]; }\n    int west() { return surface[3]; }\n\
    \    int north() { return surface[4]; }\n    int bottom() { return surface[5];\
    \ }\n    int operator[](int i) const { return surface[i]; }\n    const int dice[6][6]\
    \ = {{0, 3, 5, 2, 4, 0}, {4, 0, 1, 6, 0, 3}, {2, 6, 0, 0, 1, 5},\n           \
    \                 {5, 1, 0, 0, 6, 2}, {3, 0, 6, 1, 0, 4}, {0, 4, 2, 5, 3, 0}};\n\
    \    const int code[6][4] = {{0, 3, 5, 2}, {0, 2, 5, 3}, {0, 1, 5, 4}, {0, 4,\
    \ 5, 1}, {1, 2, 4, 3}, {1, 3, 4, 2}};\n    const string direction = \"EWNSRL\"\
    ;\n    Dice(int TOP, int FRONT) {\n        surface[0] = TOP;\n        surface[1]\
    \ = FRONT;\n        surface[2] = dice[TOP - 1][FRONT - 1];\n        surface[3]\
    \ = 7 - surface[2];\n        surface[4] = 7 - surface[1];\n        surface[5]\
    \ = 7 - surface[0];\n    }\n    void roll(char c) {\n        for (int i = 0; i\
    \ < 6; i++) {\n            if (direction[i] != c) continue;\n            int tmp\
    \ = surface[code[i][0]];\n            surface[code[i][0]] = surface[code[i][1]];\n\
    \            surface[code[i][1]] = surface[code[i][2]];\n            surface[code[i][2]]\
    \ = surface[code[i][3]];\n            surface[code[i][3]] = tmp;\n        }\n\
    \    }\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: util/Dice.hpp
  requiredBy: []
  timestamp: '2021-01-20 20:25:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/1181.test.cpp
documentation_of: util/Dice.hpp
layout: document
redirect_from:
- /library/util/Dice.hpp
- /library/util/Dice.hpp.html
title: "\u30B5\u30A4\u30B3\u30ED"
---
## 概要
サイコロを転がす.

- `Dice(TOP, FRONT)`：上面と前面の数字を引数に全ての面の数字を復元するコンストラクタ.
- `roll(c)`：サイコロを転がしたり回転させたりする. 引数`c`としてはそのオプションとなる以下の文字をとる.
    - `E`：サイコロを東の方向に転がす. $(x,y)\rightarrow (x+1,y)$
    - `W`：サイコロを西の方向に転がす. $(x,y)\rightarrow (x-1,y)$
    - `N`：サイコロを北の方向に転がす. $(x,y)\rightarrow (x,y+1)$
    - `S`：サイコロを南の方向に転がす. $(x,y)\rightarrow (x,y-1)$
    - `R`：サイコロをその場で時計回りに回転させる.
    - `L`：サイコロをその場で反時計回りに回転させる.

## 計算量
$O(1)$