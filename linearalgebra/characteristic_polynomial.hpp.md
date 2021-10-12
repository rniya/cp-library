---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/characteristic_polynomial.test.cpp
    title: test/yosupo/characteristic_polynomial.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/matrix/characteristic_polynomial.md
    document_title: Characteristic Polynomial
    links:
    - https://arxiv.org/abs/1104.3769
  bundledCode: "#line 2 \"linearalgebra/characteristic_polynomial.hpp\"\n#include\
    \ <cassert>\n#include <vector>\n\ntemplate <typename T> std::vector<T> characteristic_polynomial(std::vector<std::vector<T>>\
    \ M) {\n    assert(M.empty() or M.size() == M[0].size());\n    int n = M.size();\n\
    \    // reduce M to upper Hessenberg form\n    for (int j = 0; j < n - 2; j++)\
    \ {\n        for (int i = j + 2; i < n; i++) {\n            if (M[i][j] != 0)\
    \ {\n                std::swap(M[j + 1], M[i]);\n                for (int k =\
    \ 0; k < n; k++) std::swap(M[k][j + 1], M[k][i]);\n                break;\n  \
    \          }\n        }\n        if (M[j + 1][j] == 0) continue;\n        auto\
    \ inv = T(1) / M[j + 1][j];\n        for (int i = j + 2; i < n; i++) {\n     \
    \       auto coef = M[i][j] * inv;\n            for (int k = j; k < n; k++) M[i][k]\
    \ -= coef * M[j + 1][k];\n            for (int k = 0; k < n; k++) M[k][j + 1]\
    \ += coef * M[k][i];\n        }\n    }\n\n    // compute the characteristic polynomial\
    \ of upper Hessenberg matrix M\n    std::vector<std::vector<T>> p(n + 1);\n  \
    \  p[0] = {T(1)};\n    for (int i = 0; i < n; i++) {\n        p[i + 1].resize(i\
    \ + 2);\n        for (int j = 0; j <= i; j++) {\n            p[i + 1][j + 1] +=\
    \ p[i][j];\n            p[i + 1][j] -= p[i][j] * M[i][i];\n        }\n       \
    \ T betas = 1;\n        for (int j = i - 1; j >= 0; j--) {\n            betas\
    \ *= M[j + 1][j];\n            T coef = -betas * M[j][i];\n            for (int\
    \ k = 0; k <= j; k++) p[i + 1][k] += coef * p[j][k];\n        }\n    }\n    return\
    \ p[n];\n}\n\n/**\n * @brief Characteristic Polynomial\n * @docs docs/matrix/characteristic_polynomial.md\n\
    \ * @see https://arxiv.org/abs/1104.3769\n */\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\n\ntemplate <typename\
    \ T> std::vector<T> characteristic_polynomial(std::vector<std::vector<T>> M) {\n\
    \    assert(M.empty() or M.size() == M[0].size());\n    int n = M.size();\n  \
    \  // reduce M to upper Hessenberg form\n    for (int j = 0; j < n - 2; j++) {\n\
    \        for (int i = j + 2; i < n; i++) {\n            if (M[i][j] != 0) {\n\
    \                std::swap(M[j + 1], M[i]);\n                for (int k = 0; k\
    \ < n; k++) std::swap(M[k][j + 1], M[k][i]);\n                break;\n       \
    \     }\n        }\n        if (M[j + 1][j] == 0) continue;\n        auto inv\
    \ = T(1) / M[j + 1][j];\n        for (int i = j + 2; i < n; i++) {\n         \
    \   auto coef = M[i][j] * inv;\n            for (int k = j; k < n; k++) M[i][k]\
    \ -= coef * M[j + 1][k];\n            for (int k = 0; k < n; k++) M[k][j + 1]\
    \ += coef * M[k][i];\n        }\n    }\n\n    // compute the characteristic polynomial\
    \ of upper Hessenberg matrix M\n    std::vector<std::vector<T>> p(n + 1);\n  \
    \  p[0] = {T(1)};\n    for (int i = 0; i < n; i++) {\n        p[i + 1].resize(i\
    \ + 2);\n        for (int j = 0; j <= i; j++) {\n            p[i + 1][j + 1] +=\
    \ p[i][j];\n            p[i + 1][j] -= p[i][j] * M[i][i];\n        }\n       \
    \ T betas = 1;\n        for (int j = i - 1; j >= 0; j--) {\n            betas\
    \ *= M[j + 1][j];\n            T coef = -betas * M[j][i];\n            for (int\
    \ k = 0; k <= j; k++) p[i + 1][k] += coef * p[j][k];\n        }\n    }\n    return\
    \ p[n];\n}\n\n/**\n * @brief Characteristic Polynomial\n * @docs docs/matrix/characteristic_polynomial.md\n\
    \ * @see https://arxiv.org/abs/1104.3769\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: linearalgebra/characteristic_polynomial.hpp
  requiredBy: []
  timestamp: '2021-10-12 17:52:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/characteristic_polynomial.test.cpp
documentation_of: linearalgebra/characteristic_polynomial.hpp
layout: document
redirect_from:
- /library/linearalgebra/characteristic_polynomial.hpp
- /library/linearalgebra/characteristic_polynomial.hpp.html
title: Characteristic Polynomial
---
