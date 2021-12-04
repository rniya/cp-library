---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algorithm/Mo.hpp
    title: Mo's algorithm
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_inversions_query
    links:
    - https://judge.yosupo.jp/problem/static_range_inversions_query
  bundledCode: "#line 1 \"test/yosupo/static_range_inversions_query.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/static_range_inversions_query\"\n\n\
    #include <iostream>\n#line 2 \"algorithm/Mo.hpp\"\n#include <algorithm>\n#include\
    \ <cassert>\n#include <cmath>\n#include <numeric>\n#include <vector>\n\nstruct\
    \ Mo {\n    Mo(int n) : n(n) {}\n\n    void add(int l, int r) {\n        assert(l\
    \ <= r);\n        left.emplace_back(l);\n        right.emplace_back(r);\n    }\n\
    \n    template <typename AL, typename AR, typename DL, typename DR, typename REM>\n\
    \    void run(const AL& add_left, const AR& add_right, const DL& del_left, const\
    \ DR del_right, const REM& rem) {\n        int q = left.size(), width = n / std::min(std::max<int>(sqrt(q\
    \ * 2 / 3), 1), n);\n        std::vector<int> order(q);\n        std::iota(order.begin(),\
    \ order.end(), 0);\n        std::sort(order.begin(), order.end(), [&](int a, int\
    \ b) {\n            int ablock = left[a] / width, bblock = left[b] / width;\n\
    \            if (ablock != bblock) return ablock < bblock;\n            return\
    \ (ablock & 1) ? (right[a] > right[b]) : (right[a] < right[b]);\n        });\n\
    \n        int l = 0, r = 0;\n        for (auto idx : order) {\n            while\
    \ (l > left[idx]) add_left(--l);\n            while (r < right[idx]) add_right(r++);\n\
    \            while (l < left[idx]) del_left(l++);\n            while (r > right[idx])\
    \ del_right(--r);\n            rem(idx);\n        }\n    }\n\n    template <typename\
    \ A, typename D, typename REM> void run(const A& add, const D& del, const REM&\
    \ rem) {\n        run(add, add, del, del, rem);\n    }\n\nprivate:\n    int n;\n\
    \    std::vector<int> left, right;\n};\n\n/**\n * @brief Mo's algorithm\n * @docs\
    \ docs/other/Mo.md\n */\n#line 1 \"atcoder/fenwicktree.hpp\"\n\n\n\n#line 6 \"\
    atcoder/fenwicktree.hpp\"\n\n#line 1 \"atcoder/internal_type_traits.hpp\"\n\n\n\
    \n#line 6 \"atcoder/internal_type_traits.hpp\"\n#include <type_traits>\n\nnamespace\
    \ atcoder {\n\nnamespace internal {\n\n#ifndef _MSC_VER\ntemplate <class T>\n\
    using is_signed_int128 =\n    typename std::conditional<std::is_same<T, __int128_t>::value\
    \ ||\n                                  std::is_same<T, __int128>::value,\n  \
    \                            std::true_type,\n                              std::false_type>::type;\n\
    \ntemplate <class T>\nusing is_unsigned_int128 =\n    typename std::conditional<std::is_same<T,\
    \ __uint128_t>::value ||\n                                  std::is_same<T, unsigned\
    \ __int128>::value,\n                              std::true_type,\n         \
    \                     std::false_type>::type;\n\ntemplate <class T>\nusing make_unsigned_int128\
    \ =\n    typename std::conditional<std::is_same<T, __int128_t>::value,\n     \
    \                         __uint128_t,\n                              unsigned\
    \ __int128>;\n\ntemplate <class T>\nusing is_integral = typename std::conditional<std::is_integral<T>::value\
    \ ||\n                                                  is_signed_int128<T>::value\
    \ ||\n                                                  is_unsigned_int128<T>::value,\n\
    \                                              std::true_type,\n             \
    \                                 std::false_type>::type;\n\ntemplate <class T>\n\
    using is_signed_int = typename std::conditional<(is_integral<T>::value &&\n  \
    \                                               std::is_signed<T>::value) ||\n\
    \                                                    is_signed_int128<T>::value,\n\
    \                                                std::true_type,\n           \
    \                                     std::false_type>::type;\n\ntemplate <class\
    \ T>\nusing is_unsigned_int =\n    typename std::conditional<(is_integral<T>::value\
    \ &&\n                               std::is_unsigned<T>::value) ||\n        \
    \                          is_unsigned_int128<T>::value,\n                   \
    \           std::true_type,\n                              std::false_type>::type;\n\
    \ntemplate <class T>\nusing to_unsigned = typename std::conditional<\n    is_signed_int128<T>::value,\n\
    \    make_unsigned_int128<T>,\n    typename std::conditional<std::is_signed<T>::value,\n\
    \                              std::make_unsigned<T>,\n                      \
    \        std::common_type<T>>::type>::type;\n\n#else\n\ntemplate <class T> using\
    \ is_integral = typename std::is_integral<T>;\n\ntemplate <class T>\nusing is_signed_int\
    \ =\n    typename std::conditional<is_integral<T>::value && std::is_signed<T>::value,\n\
    \                              std::true_type,\n                             \
    \ std::false_type>::type;\n\ntemplate <class T>\nusing is_unsigned_int =\n   \
    \ typename std::conditional<is_integral<T>::value &&\n                       \
    \           std::is_unsigned<T>::value,\n                              std::true_type,\n\
    \                              std::false_type>::type;\n\ntemplate <class T>\n\
    using to_unsigned = typename std::conditional<is_signed_int<T>::value,\n     \
    \                                         std::make_unsigned<T>,\n           \
    \                                   std::common_type<T>>::type;\n\n#endif\n\n\
    template <class T>\nusing is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;\n\
    \ntemplate <class T>\nusing is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;\n\
    \ntemplate <class T> using to_unsigned_t = typename to_unsigned<T>::type;\n\n\
    }  // namespace internal\n\n}  // namespace atcoder\n\n\n#line 8 \"atcoder/fenwicktree.hpp\"\
    \n\nnamespace atcoder {\n\n// Reference: https://en.wikipedia.org/wiki/Fenwick_tree\n\
    template <class T> struct fenwick_tree {\n    using U = internal::to_unsigned_t<T>;\n\
    \n  public:\n    fenwick_tree() : _n(0) {}\n    explicit fenwick_tree(int n) :\
    \ _n(n), data(n) {}\n\n    void add(int p, T x) {\n        assert(0 <= p && p\
    \ < _n);\n        p++;\n        while (p <= _n) {\n            data[p - 1] +=\
    \ U(x);\n            p += p & -p;\n        }\n    }\n\n    T sum(int l, int r)\
    \ {\n        assert(0 <= l && l <= r && r <= _n);\n        return sum(r) - sum(l);\n\
    \    }\n\n  private:\n    int _n;\n    std::vector<U> data;\n\n    U sum(int r)\
    \ {\n        U s = 0;\n        while (r > 0) {\n            s += data[r - 1];\n\
    \            r -= r & -r;\n        }\n        return s;\n    }\n};\n\n}  // namespace\
    \ atcoder\n\n\n#line 6 \"test/yosupo/static_range_inversions_query.test.cpp\"\n\
    \nint main() {\n    std::cin.tie(0);\n    std::ios::sync_with_stdio(false);\n\
    \    int N, Q;\n    std::cin >> N >> Q;\n    std::vector<int> A(N);\n    for (int\
    \ i = 0; i < N; i++) std::cin >> A[i];\n\n    Mo mo(N);\n    for (int i = 0; i\
    \ < Q; i++) {\n        int l, r;\n        std::cin >> l >> r;\n        mo.add(l,\
    \ r);\n    }\n\n    std::vector<int> B = A;\n    sort(B.begin(), B.end());\n \
    \   B.erase(unique(B.begin(), B.end()), B.end());\n    for (int i = 0; i < N;\
    \ i++) A[i] = lower_bound(B.begin(), B.end(), A[i]) - B.begin();\n    int n =\
    \ B.size();\n    atcoder::fenwick_tree<int> FT(n);\n    std::vector<long long>\
    \ ans(Q);\n    long long inv = 0;\n    int sum = 0;\n\n    auto add_left = [&](int\
    \ idx) {\n        inv += FT.sum(0, A[idx]);\n        sum++;\n        FT.add(A[idx],\
    \ 1);\n    };\n    auto add_right = [&](int idx) {\n        inv += FT.sum(A[idx]\
    \ + 1, n);\n        sum++;\n        FT.add(A[idx], 1);\n    };\n    auto del_left\
    \ = [&](int idx) {\n        inv -= FT.sum(0, A[idx]);\n        sum--;\n      \
    \  FT.add(A[idx], -1);\n    };\n    auto del_right = [&](int idx) {\n        inv\
    \ -= FT.sum(A[idx] + 1, n);\n        sum--;\n        FT.add(A[idx], -1);\n   \
    \ };\n    auto rem = [&](int idx) { ans[idx] = inv; };\n\n    mo.run(add_left,\
    \ add_right, del_left, del_right, rem);\n\n    for (int i = 0; i < Q; i++) std::cout\
    \ << ans[i] << '\\n';\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_inversions_query\"\
    \n\n#include <iostream>\n#include \"algorithm/Mo.hpp\"\n#include \"atcoder/fenwicktree\"\
    \n\nint main() {\n    std::cin.tie(0);\n    std::ios::sync_with_stdio(false);\n\
    \    int N, Q;\n    std::cin >> N >> Q;\n    std::vector<int> A(N);\n    for (int\
    \ i = 0; i < N; i++) std::cin >> A[i];\n\n    Mo mo(N);\n    for (int i = 0; i\
    \ < Q; i++) {\n        int l, r;\n        std::cin >> l >> r;\n        mo.add(l,\
    \ r);\n    }\n\n    std::vector<int> B = A;\n    sort(B.begin(), B.end());\n \
    \   B.erase(unique(B.begin(), B.end()), B.end());\n    for (int i = 0; i < N;\
    \ i++) A[i] = lower_bound(B.begin(), B.end(), A[i]) - B.begin();\n    int n =\
    \ B.size();\n    atcoder::fenwick_tree<int> FT(n);\n    std::vector<long long>\
    \ ans(Q);\n    long long inv = 0;\n    int sum = 0;\n\n    auto add_left = [&](int\
    \ idx) {\n        inv += FT.sum(0, A[idx]);\n        sum++;\n        FT.add(A[idx],\
    \ 1);\n    };\n    auto add_right = [&](int idx) {\n        inv += FT.sum(A[idx]\
    \ + 1, n);\n        sum++;\n        FT.add(A[idx], 1);\n    };\n    auto del_left\
    \ = [&](int idx) {\n        inv -= FT.sum(0, A[idx]);\n        sum--;\n      \
    \  FT.add(A[idx], -1);\n    };\n    auto del_right = [&](int idx) {\n        inv\
    \ -= FT.sum(A[idx] + 1, n);\n        sum--;\n        FT.add(A[idx], -1);\n   \
    \ };\n    auto rem = [&](int idx) { ans[idx] = inv; };\n\n    mo.run(add_left,\
    \ add_right, del_left, del_right, rem);\n\n    for (int i = 0; i < Q; i++) std::cout\
    \ << ans[i] << '\\n';\n    return 0;\n}"
  dependsOn:
  - algorithm/Mo.hpp
  isVerificationFile: true
  path: test/yosupo/static_range_inversions_query.test.cpp
  requiredBy: []
  timestamp: '2021-12-04 17:03:44+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/static_range_inversions_query.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/static_range_inversions_query.test.cpp
- /verify/test/yosupo/static_range_inversions_query.test.cpp.html
title: test/yosupo/static_range_inversions_query.test.cpp
---
