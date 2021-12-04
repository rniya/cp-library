---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/665.test.cpp
    title: test/yukicoder/665.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/polynomial/lagrange_interpolation.md
    document_title: Lagrange Interpolation
    links: []
  bundledCode: "#line 2 \"polynomial/lagrange_interpolation.hpp\"\n#include <vector>\n\
    \ntemplate <typename M> M lagrange_interpolation(std::vector<M> x, std::vector<M>\
    \ y, M T) {\n    int n = x.size() - 1;\n    M res = 0;\n    for (int i = 0; i\
    \ <= n; i++) {\n        M c = 1;\n        for (int j = 0; j <= n; j++) {\n   \
    \         if (i == j) continue;\n            (c *= T - x[j]) /= x[i] - x[j];\n\
    \        }\n        res += c * y[i];\n    }\n    return res;\n}\n\ntemplate <typename\
    \ M> M lagrange_interpolation_arithmetic(std::vector<M>& y, M T) {\n    int n\
    \ = y.size() - 1;\n    if (T.val() <= n) return y[T.val()];\n    std::vector<M>\
    \ left(n + 1, 1), right(n + 1, 1), fac(n + 1, 1), finv(n + 1, 1);\n    for (int\
    \ i = 0; i < n; i++) left[i + 1] = left[i] * (T - i);\n    for (int i = n - 1;\
    \ i >= 0; --i) right[i] = right[i + 1] * (T - (i + 1));\n    for (int i = 1; i\
    \ <= n; i++) fac[i] = fac[i - 1] * i;\n    finv[n] = (M)1 / fac[n];\n    for (int\
    \ i = n; i > 0; --i) finv[i - 1] = finv[i] * i;\n    M res = 0;\n    for (int\
    \ i = 0; i <= n; i++) {\n        M add = y[i] * left[i] * right[i] * finv[i] *\
    \ finv[n - i];\n        if ((n - i) & 1)\n            res -= add;\n        else\n\
    \            res += add;\n    }\n    return res;\n}\n\n/**\n * @brief Lagrange\
    \ Interpolation\n * @docs docs/polynomial/lagrange_interpolation.md\n */\n"
  code: "#pragma once\n#include <vector>\n\ntemplate <typename M> M lagrange_interpolation(std::vector<M>\
    \ x, std::vector<M> y, M T) {\n    int n = x.size() - 1;\n    M res = 0;\n   \
    \ for (int i = 0; i <= n; i++) {\n        M c = 1;\n        for (int j = 0; j\
    \ <= n; j++) {\n            if (i == j) continue;\n            (c *= T - x[j])\
    \ /= x[i] - x[j];\n        }\n        res += c * y[i];\n    }\n    return res;\n\
    }\n\ntemplate <typename M> M lagrange_interpolation_arithmetic(std::vector<M>&\
    \ y, M T) {\n    int n = y.size() - 1;\n    if (T.val() <= n) return y[T.val()];\n\
    \    std::vector<M> left(n + 1, 1), right(n + 1, 1), fac(n + 1, 1), finv(n + 1,\
    \ 1);\n    for (int i = 0; i < n; i++) left[i + 1] = left[i] * (T - i);\n    for\
    \ (int i = n - 1; i >= 0; --i) right[i] = right[i + 1] * (T - (i + 1));\n    for\
    \ (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i;\n    finv[n] = (M)1 / fac[n];\n\
    \    for (int i = n; i > 0; --i) finv[i - 1] = finv[i] * i;\n    M res = 0;\n\
    \    for (int i = 0; i <= n; i++) {\n        M add = y[i] * left[i] * right[i]\
    \ * finv[i] * finv[n - i];\n        if ((n - i) & 1)\n            res -= add;\n\
    \        else\n            res += add;\n    }\n    return res;\n}\n\n/**\n * @brief\
    \ Lagrange Interpolation\n * @docs docs/polynomial/lagrange_interpolation.md\n\
    \ */\n"
  dependsOn: []
  isVerificationFile: false
  path: polynomial/lagrange_interpolation.hpp
  requiredBy: []
  timestamp: '2021-12-05 02:04:54+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/665.test.cpp
documentation_of: polynomial/lagrange_interpolation.hpp
layout: document
redirect_from:
- /library/polynomial/lagrange_interpolation.hpp
- /library/polynomial/lagrange_interpolation.hpp.html
title: Lagrange Interpolation
---
## 概要

## 計算量