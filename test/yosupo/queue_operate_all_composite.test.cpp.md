---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  - icon: ':heavy_check_mark:'
    path: datastructure/SlidingWindowAggregation.hpp
    title: Sliding Window Aggregation (SWAG)
  - icon: ':heavy_check_mark:'
    path: modulo/modint.hpp
    title: modint
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/queue_operate_all_composite
    links:
    - https://judge.yosupo.jp/problem/queue_operate_all_composite
  bundledCode: "#line 1 \"test/yosupo/queue_operate_all_composite.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/queue_operate_all_composite\"\n\n\
    #line 2 \"base.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n#pragma\
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
    \ true;\n    }\n    return false;\n}\n#pragma endregion\n#line 3 \"datastructure/SlidingWindowAggregation.hpp\"\
    \n\n/**\n * @brief Sliding Window Aggregation (SWAG)\n * @docs docs/datastructure/SlidingWindowAggregation.md\n\
    \ */\ntemplate <typename Monoid> struct SlidingWindowAggregation {\n    typedef\
    \ function<Monoid(Monoid, Monoid)> F;\n    stack<pair<Monoid, Monoid>> front_stack,\
    \ back_stack;\n    F f;\n    Monoid id;\n    SlidingWindowAggregation(F f, Monoid\
    \ id) : f(f), id(id), front_stack(), back_stack() {\n        front_stack.emplace(id,\
    \ id);\n        back_stack.emplace(id, id);\n    }\n    void push(const Monoid&\
    \ x) { back_stack.emplace(x, f(back_stack.top().second, x)); }\n    void pop()\
    \ {\n        if (front_stack.size() == 1) {\n            while (1 < (int)back_stack.size())\
    \ {\n                Monoid t = back_stack.top().first;\n                Monoid\
    \ calc = f(t, front_stack.top().second);\n                front_stack.emplace(t,\
    \ calc);\n                back_stack.pop();\n            }\n        }\n      \
    \  front_stack.pop();\n    }\n    Monoid fold() { return f(front_stack.top().second,\
    \ back_stack.top().second); }\n};\n#line 5 \"modulo/modint.hpp\"\n\ntemplate <uint64_t\
    \ Modulus> class modint {\n    using i64 = int64_t;\n    using u32 = uint32_t;\n\
    \    using u64 = uint64_t;\n\n    static_assert(Modulus < static_cast<uint32_t>(1)\
    \ << 31, \"Modulus must be less than 2**31\");\n    static constexpr u32 mod =\
    \ Modulus;\n    u32 v;\n\npublic:\n    constexpr modint(const i64 x = 0) noexcept\
    \ : v(x < 0 ? mod - 1 - (-(x + 1) % mod) : x % mod) {}\n    constexpr u32& value()\
    \ noexcept { return v; }\n    constexpr const u32& value() const noexcept { return\
    \ v; }\n    constexpr modint operator+(const modint& rhs) const noexcept { return\
    \ modint(*this) += rhs; }\n    constexpr modint operator-(const modint& rhs) const\
    \ noexcept { return modint(*this) -= rhs; }\n    constexpr modint operator*(const\
    \ modint& rhs) const noexcept { return modint(*this) *= rhs; }\n    constexpr\
    \ modint operator/(const modint& rhs) const noexcept { return modint(*this) /=\
    \ rhs; }\n    constexpr modint& operator+=(const modint& rhs) noexcept {\n   \
    \     v += rhs.v;\n        if (v >= mod) v -= mod;\n        return *this;\n  \
    \  }\n    constexpr modint& operator-=(const modint& rhs) noexcept {\n       \
    \ if (v < rhs.v) v += mod;\n        v -= rhs.v;\n        return *this;\n    }\n\
    \    constexpr modint& operator*=(const modint& rhs) noexcept {\n        v = (u64)v\
    \ * rhs.v % mod;\n        return *this;\n    }\n    constexpr modint& operator/=(const\
    \ modint& rhs) noexcept { return *this *= rhs.inv(); }\n    constexpr modint pow(u64\
    \ exp) const noexcept {\n        assert(0 <= exp);\n        modint self(*this),\
    \ res(1);\n        while (exp > 0) {\n            if (exp & 1) res *= self;\n\
    \            self *= self;\n            exp >>= 1;\n        }\n        return\
    \ res;\n    }\n    constexpr modint inv() const noexcept {\n        assert(*this\
    \ != 0);\n        return pow(mod - 2);\n    }\n    constexpr modint& operator++()\
    \ noexcept {\n        if (++v == mod) v = 0;\n        return *this;\n    }\n \
    \   constexpr modint& operator--() noexcept {\n        if (v == 0) v = mod;\n\
    \        return --v, *this;\n    }\n    constexpr modint operator++(int) noexcept\
    \ {\n        modint t = *this;\n        return ++*this, t;\n    }\n    constexpr\
    \ modint operator--(int) noexcept {\n        modint t = *this;\n        return\
    \ --*this, t;\n    }\n    constexpr modint operator-() const noexcept { return\
    \ modint(mod - v); }\n    template <class T> friend constexpr modint operator+(T\
    \ x, modint y) noexcept { return modint(x) + y; }\n    template <class T> friend\
    \ constexpr modint operator-(T x, modint y) noexcept { return modint(x) - y; }\n\
    \    template <class T> friend constexpr modint operator*(T x, modint y) noexcept\
    \ { return modint(x) * y; }\n    template <class T> friend constexpr modint operator/(T\
    \ x, modint y) noexcept { return modint(x) / y; }\n    constexpr bool operator==(const\
    \ modint& rhs) const noexcept { return v == rhs.v; }\n    constexpr bool operator!=(const\
    \ modint& rhs) const noexcept { return v != rhs.v; }\n    constexpr bool operator!()\
    \ const noexcept { return !v; }\n    friend std::istream& operator>>(std::istream&\
    \ s, modint& rhs) noexcept {\n        i64 v;\n        rhs = modint{(s >> v, v)};\n\
    \        return s;\n    }\n    friend std::ostream& operator<<(std::ostream& s,\
    \ const modint& rhs) noexcept { return s << rhs.v; }\n};\n\n/**\n * @brief modint\n\
    \ * @docs docs/modulo/modint.md\n */\n#line 6 \"test/yosupo/queue_operate_all_composite.test.cpp\"\
    \n\nusing mint = modint<998244353>;\n\nint main() {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n\
    \    struct node {\n        mint a, b;\n        node(mint a, mint b) : a(a), b(b)\
    \ {}\n    };\n    auto f = [](node a, node b) { return node(a.a * b.a, a.b * b.a\
    \ + b.b); };\n    SlidingWindowAggregation<node> SWAG(f, node(1, 0));\n\n    int\
    \ Q;\n    cin >> Q;\n    for (; Q--;) {\n        int t;\n        cin >> t;\n \
    \       if (t == 0) {\n            int a, b;\n            cin >> a >> b;\n   \
    \         SWAG.push(node(a, b));\n        } else if (t == 1) {\n            SWAG.pop();\n\
    \        } else {\n            int x;\n            cin >> x;\n            node\
    \ ans = SWAG.fold();\n            cout << ans.a * x + ans.b << '\\n';\n      \
    \  }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/queue_operate_all_composite\"\
    \n\n#include \"../../base.hpp\"\n#include \"../../datastructure/SlidingWindowAggregation.hpp\"\
    \n#include \"../../modulo/modint.hpp\"\n\nusing mint = modint<998244353>;\n\n\
    int main() {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    struct node\
    \ {\n        mint a, b;\n        node(mint a, mint b) : a(a), b(b) {}\n    };\n\
    \    auto f = [](node a, node b) { return node(a.a * b.a, a.b * b.a + b.b); };\n\
    \    SlidingWindowAggregation<node> SWAG(f, node(1, 0));\n\n    int Q;\n    cin\
    \ >> Q;\n    for (; Q--;) {\n        int t;\n        cin >> t;\n        if (t\
    \ == 0) {\n            int a, b;\n            cin >> a >> b;\n            SWAG.push(node(a,\
    \ b));\n        } else if (t == 1) {\n            SWAG.pop();\n        } else\
    \ {\n            int x;\n            cin >> x;\n            node ans = SWAG.fold();\n\
    \            cout << ans.a * x + ans.b << '\\n';\n        }\n    }\n}"
  dependsOn:
  - base.hpp
  - datastructure/SlidingWindowAggregation.hpp
  - modulo/modint.hpp
  isVerificationFile: true
  path: test/yosupo/queue_operate_all_composite.test.cpp
  requiredBy: []
  timestamp: '2021-09-21 14:56:05+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/queue_operate_all_composite.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/queue_operate_all_composite.test.cpp
- /verify/test/yosupo/queue_operate_all_composite.test.cpp.html
title: test/yosupo/queue_operate_all_composite.test.cpp
---
