---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/math/quotient_ranges.md
    document_title: "\u5546\u5217\u6319"
    links: []
  bundledCode: "#line 2 \"math/quotient_ranges.hpp\"\n#include <tuple>\n#include <vector>\n\
    \ntemplate <typename T> std::vector<std::tuple<T, T, T>> quotient_ranges(T n)\
    \ {\n    std::vector<std::tuple<T, T, T>> res;\n    T m = 1;\n    for (; m * m\
    \ <= n; m++) res.emplace_back(m, m, n / m);\n    for (; m >= 1; m--) {\n     \
    \   T l = n / (m + 1) + 1, r = n / m;\n        if (l <= r and std::get<1>(res.back())\
    \ < l) res.emplace_back(l, r, n / l);\n    }\n    return res;\n}\n\n/**\n * @brief\
    \ \u5546\u5217\u6319\n * @docs docs/math/quotient_ranges.md\n */\n"
  code: "#pragma once\n#include <tuple>\n#include <vector>\n\ntemplate <typename T>\
    \ std::vector<std::tuple<T, T, T>> quotient_ranges(T n) {\n    std::vector<std::tuple<T,\
    \ T, T>> res;\n    T m = 1;\n    for (; m * m <= n; m++) res.emplace_back(m, m,\
    \ n / m);\n    for (; m >= 1; m--) {\n        T l = n / (m + 1) + 1, r = n / m;\n\
    \        if (l <= r and std::get<1>(res.back()) < l) res.emplace_back(l, r, n\
    \ / l);\n    }\n    return res;\n}\n\n/**\n * @brief \u5546\u5217\u6319\n * @docs\
    \ docs/math/quotient_ranges.md\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: math/quotient_ranges.hpp
  requiredBy: []
  timestamp: '2022-04-14 01:34:39+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/quotient_ranges.hpp
layout: document
title: "\u5546\u5217\u6319"
---

## 概要
$n \in \mathbb{N}$ について，商 $\left\lfloor \frac{n}{i} \right\rfloor$ の種類数は $O(\sqrt{n})$ 程度である．
$\left\lfloor \frac{n}{i} \right\rfloor = k \iff i \in [l,r]$ となるとき，3 数の組 $(l,r,k)$ を $l$ の昇順に列挙する．

## 計算量
$O(\sqrt{n})$
