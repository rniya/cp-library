---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/optimization/monge_d_edge_shortest_path.hpp
    title: $d$-edge Shortest Path on Monge Graph
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/optimization/golden_section_search.hpp\"\n#include <cassert>\n\
    #include <functional>\n#include <utility>\n\ntemplate <typename T, bool get_min\
    \ = true>\nstd::pair<long long, T> golden_section_search(const std::function<T(long\
    \ long)>& f, long long mini, long long maxi) {\n    assert(mini <= maxi);\n  \
    \  long long a = mini - 1, x, b;\n    {\n        long long s = 1, t = 2;\n   \
    \     while (t < maxi - mini + 2) std::swap(s += t, t);\n        x = a + t - s,\
    \ b = a + t;\n    }\n    T fx = f(x), fy;\n    while (a + b != 2 * x) {\n    \
    \    long long y = a + b - x;\n        fy = f(y);\n        if (maxi < y or (get_min\
    \ ? fx < fy : fx > fy)) {\n            b = a;\n            a = y;\n        } else\
    \ {\n            a = x;\n            x = y;\n            fx = fy;\n        }\n\
    \    }\n    return {x, fx};\n}\n"
  code: "#include <cassert>\n#include <functional>\n#include <utility>\n\ntemplate\
    \ <typename T, bool get_min = true>\nstd::pair<long long, T> golden_section_search(const\
    \ std::function<T(long long)>& f, long long mini, long long maxi) {\n    assert(mini\
    \ <= maxi);\n    long long a = mini - 1, x, b;\n    {\n        long long s = 1,\
    \ t = 2;\n        while (t < maxi - mini + 2) std::swap(s += t, t);\n        x\
    \ = a + t - s, b = a + t;\n    }\n    T fx = f(x), fy;\n    while (a + b != 2\
    \ * x) {\n        long long y = a + b - x;\n        fy = f(y);\n        if (maxi\
    \ < y or (get_min ? fx < fy : fx > fy)) {\n            b = a;\n            a =\
    \ y;\n        } else {\n            a = x;\n            x = y;\n            fx\
    \ = fy;\n        }\n    }\n    return {x, fx};\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/optimization/golden_section_search.hpp
  requiredBy:
  - src/optimization/monge_d_edge_shortest_path.hpp
  timestamp: '2024-06-01 01:35:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/optimization/golden_section_search.hpp
layout: document
title: Golden Section Search
---

## Links
- https://twitter.com/noshi91/status/1399003086362865673
