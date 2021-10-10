---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/frequency_table_of_tree_distance.test.cpp
    title: test/yosupo/frequency_table_of_tree_distance.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1307.test.cpp
    title: test/yukicoder/1307.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/206.test.cpp
    title: test/yukicoder/206.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/convolution/FastFourierTransform.md
    document_title: Fast Fourier Transform
    links: []
  bundledCode: "#line 2 \"base.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #pragma region Macros\ntypedef long long ll;\ntypedef __int128_t i128;\ntypedef\
    \ unsigned int uint;\ntypedef unsigned long long ull;\n#define ALL(x) (x).begin(),\
    \ (x).end()\n\ntemplate <typename T> istream& operator>>(istream& is, vector<T>&\
    \ v) {\n    for (T& x : v) is >> x;\n    return is;\n}\ntemplate <typename T>\
    \ ostream& operator<<(ostream& os, const vector<T>& v) {\n    for (int i = 0;\
    \ i < (int)v.size(); i++) {\n        os << v[i] << (i + 1 == (int)v.size() ? \"\
    \" : \" \");\n    }\n    return os;\n}\ntemplate <typename T, typename U> ostream&\
    \ operator<<(ostream& os, const pair<T, U>& p) {\n    os << '(' << p.first <<\
    \ ',' << p.second << ')';\n    return os;\n}\ntemplate <typename T, typename U>\
    \ ostream& operator<<(ostream& os, const map<T, U>& m) {\n    os << '{';\n   \
    \ for (auto itr = m.begin(); itr != m.end();) {\n        os << '(' << itr->first\
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
    \" : \" \");\n    }\n    return os;\n}\n\ntemplate <int i, typename T> void print_tuple(ostream&,\
    \ const T&) {}\ntemplate <int i, typename T, typename H, class... Args> void print_tuple(ostream&\
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
    \ true;\n    }\n    return false;\n}\n#pragma endregion\n#line 3 \"convolution/FastFourierTransform.hpp\"\
    \n\n/**\n * @brief Fast Fourier Transform\n * @docs docs/convolution/FastFourierTransform.md\n\
    \ */\nnamespace FastFourierTransform {\nstruct Complex {\n    double x, y;\n \
    \   Complex() : x(0), y(0) {}\n    Complex(double x, double y) : x(x), y(y) {}\n\
    \    inline Complex operator+(const Complex& c) const { return Complex(x + c.x,\
    \ y + c.y); }\n    inline Complex operator-(const Complex& c) const { return Complex(x\
    \ - c.x, y - c.y); }\n    inline Complex operator*(const Complex& c) const { return\
    \ Complex(x * c.x - y * c.y, x * c.y + y * c.x); }\n    inline Complex conj()\
    \ const { return Complex(x, -y); }\n};\nconst double PI = acosl(-1);\nvector<Complex>\
    \ roots = {{0, 0}, {1, 0}};\nvector<int> rev = {0, 1};\nint base = 1;\nvoid ensure_base(int\
    \ nbase) {\n    if (nbase <= base) return;\n    rev.resize(1 << nbase);\n    for\
    \ (int i = 0; i < (1 << nbase); i++) {\n        rev[i] = (rev[i >> 1] >> 1) |\
    \ ((i & 1) << (nbase - 1));\n    }\n    roots.resize(1 << nbase);\n    for (;\
    \ base < nbase; base++) {\n        double angle = PI * 2.0 / (1 << (base + 1));\n\
    \        for (int i = 1 << (base - 1); i < (1 << base); i++) {\n            roots[i\
    \ << 1] = roots[i];\n            double angle_i = angle * ((i << 1 | 1) - (1 <<\
    \ base));\n            roots[i << 1 | 1] = Complex(cos(angle_i), sin(angle_i));\n\
    \        }\n    }\n}\nvoid fft(vector<Complex>& a, int n) {\n    int zeros = __builtin_ctz(n);\n\
    \    ensure_base(zeros);\n    int shift = base - zeros;\n    for (int i = 0; i\
    \ < n; i++) {\n        if (i < (rev[i] >> shift)) {\n            swap(a[i], a[rev[i]\
    \ >> shift]);\n        }\n    }\n    for (int k = 1; k < n; k <<= 1) {\n     \
    \   for (int i = 0; i < n; i += (k << 1)) {\n            for (int j = 0; j < k;\
    \ j++) {\n                Complex z = a[i + j + k] * roots[j + k];\n         \
    \       a[i + j + k] = a[i + j] - z;\n                a[i + j] = a[i + j] + z;\n\
    \            }\n        }\n    }\n}\nvector<long long> multiply(const vector<int>&\
    \ a, const vector<int>& b) {\n    int need = a.size() + b.size() - 1;\n    int\
    \ nbase = 1;\n    while ((1 << nbase) < need) nbase++;\n    ensure_base(nbase);\n\
    \    int sz = 1 << nbase;\n    vector<Complex> C(sz);\n    for (int i = 0; i <\
    \ sz; i++) {\n        int x = (i < a.size() ? a[i] : 0);\n        int y = (i <\
    \ b.size() ? b[i] : 0);\n        C[i] = Complex(x, y);\n    }\n    fft(C, sz);\n\
    \    Complex r(0, -0.25 / (sz >> 1)), s(0, 1), t(0.5, 0);\n    for (int i = 0;\
    \ i <= (sz >> 1); i++) {\n        int j = (sz - i) & (sz - 1);\n        Complex\
    \ z = (C[j] * C[j] - (C[i] * C[i]).conj()) * r;\n        C[j] = (C[i] * C[i] -\
    \ (C[j] * C[j]).conj()) * r;\n        C[i] = z;\n    }\n    for (int i = 0; i\
    \ < (sz >> 1); i++) {\n        Complex C0 = (C[i] + C[i + (sz >> 1)]) * t;\n \
    \       Complex C1 = (C[i] - C[i + (sz >> 1)]) * t * roots[(sz >> 1) + i];\n \
    \       C[i] = C0 + C1 * s;\n    }\n    fft(C, sz >> 1);\n    vector<long long>\
    \ res(need);\n    for (int i = 0; i < need; i++) {\n        res[i] = llround(i\
    \ & 1 ? C[i >> 1].y : C[i >> 1].x);\n    }\n    return res;\n}\n}  // namespace\
    \ FastFourierTransform\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n/**\n * @brief Fast Fourier Transform\n\
    \ * @docs docs/convolution/FastFourierTransform.md\n */\nnamespace FastFourierTransform\
    \ {\nstruct Complex {\n    double x, y;\n    Complex() : x(0), y(0) {}\n    Complex(double\
    \ x, double y) : x(x), y(y) {}\n    inline Complex operator+(const Complex& c)\
    \ const { return Complex(x + c.x, y + c.y); }\n    inline Complex operator-(const\
    \ Complex& c) const { return Complex(x - c.x, y - c.y); }\n    inline Complex\
    \ operator*(const Complex& c) const { return Complex(x * c.x - y * c.y, x * c.y\
    \ + y * c.x); }\n    inline Complex conj() const { return Complex(x, -y); }\n\
    };\nconst double PI = acosl(-1);\nvector<Complex> roots = {{0, 0}, {1, 0}};\n\
    vector<int> rev = {0, 1};\nint base = 1;\nvoid ensure_base(int nbase) {\n    if\
    \ (nbase <= base) return;\n    rev.resize(1 << nbase);\n    for (int i = 0; i\
    \ < (1 << nbase); i++) {\n        rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (nbase\
    \ - 1));\n    }\n    roots.resize(1 << nbase);\n    for (; base < nbase; base++)\
    \ {\n        double angle = PI * 2.0 / (1 << (base + 1));\n        for (int i\
    \ = 1 << (base - 1); i < (1 << base); i++) {\n            roots[i << 1] = roots[i];\n\
    \            double angle_i = angle * ((i << 1 | 1) - (1 << base));\n        \
    \    roots[i << 1 | 1] = Complex(cos(angle_i), sin(angle_i));\n        }\n   \
    \ }\n}\nvoid fft(vector<Complex>& a, int n) {\n    int zeros = __builtin_ctz(n);\n\
    \    ensure_base(zeros);\n    int shift = base - zeros;\n    for (int i = 0; i\
    \ < n; i++) {\n        if (i < (rev[i] >> shift)) {\n            swap(a[i], a[rev[i]\
    \ >> shift]);\n        }\n    }\n    for (int k = 1; k < n; k <<= 1) {\n     \
    \   for (int i = 0; i < n; i += (k << 1)) {\n            for (int j = 0; j < k;\
    \ j++) {\n                Complex z = a[i + j + k] * roots[j + k];\n         \
    \       a[i + j + k] = a[i + j] - z;\n                a[i + j] = a[i + j] + z;\n\
    \            }\n        }\n    }\n}\nvector<long long> multiply(const vector<int>&\
    \ a, const vector<int>& b) {\n    int need = a.size() + b.size() - 1;\n    int\
    \ nbase = 1;\n    while ((1 << nbase) < need) nbase++;\n    ensure_base(nbase);\n\
    \    int sz = 1 << nbase;\n    vector<Complex> C(sz);\n    for (int i = 0; i <\
    \ sz; i++) {\n        int x = (i < a.size() ? a[i] : 0);\n        int y = (i <\
    \ b.size() ? b[i] : 0);\n        C[i] = Complex(x, y);\n    }\n    fft(C, sz);\n\
    \    Complex r(0, -0.25 / (sz >> 1)), s(0, 1), t(0.5, 0);\n    for (int i = 0;\
    \ i <= (sz >> 1); i++) {\n        int j = (sz - i) & (sz - 1);\n        Complex\
    \ z = (C[j] * C[j] - (C[i] * C[i]).conj()) * r;\n        C[j] = (C[i] * C[i] -\
    \ (C[j] * C[j]).conj()) * r;\n        C[i] = z;\n    }\n    for (int i = 0; i\
    \ < (sz >> 1); i++) {\n        Complex C0 = (C[i] + C[i + (sz >> 1)]) * t;\n \
    \       Complex C1 = (C[i] - C[i + (sz >> 1)]) * t * roots[(sz >> 1) + i];\n \
    \       C[i] = C0 + C1 * s;\n    }\n    fft(C, sz >> 1);\n    vector<long long>\
    \ res(need);\n    for (int i = 0; i < need; i++) {\n        res[i] = llround(i\
    \ & 1 ? C[i >> 1].y : C[i >> 1].x);\n    }\n    return res;\n}\n}  // namespace\
    \ FastFourierTransform"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: convolution/FastFourierTransform.hpp
  requiredBy: []
  timestamp: '2021-07-19 14:45:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1307.test.cpp
  - test/yukicoder/206.test.cpp
  - test/yosupo/frequency_table_of_tree_distance.test.cpp
documentation_of: convolution/FastFourierTransform.hpp
layout: document
redirect_from:
- /library/convolution/FastFourierTransform.hpp
- /library/convolution/FastFourierTransform.hpp.html
title: Fast Fourier Transform
---
## 概要
2つの数列$a,b$の畳み込み, すなわち,
$$c_k=\sum_{i=0}^k a_ib_{k-i}$$
を計算する. バタフライ演算を利用した非再帰のものを実装している. 誤差に注意が必要だが, NTTよりもこちらの方が速いので, TLが厳しい場合であればこちらを使う方が無難.
## 計算量
$O(n\log n)$

## 問題例
[Codeforces Round #296 (Div. 1) D. Fuzzy Search](https://codeforces.com/contest/528/problem/D)
2つの文字列$S,T$について, 特に特定の1種類の文字に着目して2つの文字列をbit列に変換すると, それらを畳み込むことで一致しているかどうかを判定することができる.

## 参照
- [高速フーリエ変換](https://www.slideshare.net/chokudai/fft-49066791)
- [高速フーリエ変換 (FFT) - ゆるふわブログ](http://ysmr-ry.hatenablog.com/entry/2017/11/09/102008)
- [競プロのための高速フーリエ変換](https://www.creativ.xyz/fast-fourier-transform/)
- [Cooley-Tukeyのアルゴリズム - Mister雑記](https://misteer.hatenablog.com/entry/cooley-tukey)