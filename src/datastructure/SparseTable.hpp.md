---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/staticrmq.test.cpp
    title: test/yosupo/staticrmq.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ src/base.hpp: line 7: unable to process #include in #if / #ifdef / #ifndef other\
    \ than include guards\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\ntemplate <typename T> struct SparseTable\
    \ {\n    typedef function<T(T, T)> F;\n    vector<vector<T>> dat;\n    vector<int>\
    \ lookup;\n    const F f;\n    SparseTable(F f) : f(f) {}\n    void build(const\
    \ vector<T>& v) {\n        int n = v.size(), h = 1;\n        while ((1 << h) <=\
    \ n) h++;\n        dat.assign(h, vector<T>(n));\n        lookup.assign(n + 1,\
    \ 0);\n        for (int i = 2; i <= n; i++) lookup[i] = lookup[i >> 1] + 1;\n\
    \        for (int j = 0; j < n; j++) dat[0][j] = v[j];\n        for (int i = 1,\
    \ mask = 1; i < h; i++, mask <<= 1) {\n            for (int j = 0; j < n; j++)\
    \ {\n                dat[i][j] = f(dat[i - 1][j], dat[i - 1][min(j + mask, n -\
    \ 1)]);\n            }\n        }\n    }\n    T query(int a, int b) {\n      \
    \  int d = lookup[b - a];\n        return f(dat[d][a], dat[d][b - (1 << d)]);\n\
    \    }\n};"
  dependsOn:
  - src/base.hpp
  isVerificationFile: false
  path: src/datastructure/SparseTable.hpp
  requiredBy: []
  timestamp: '2023-01-12 22:28:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/staticrmq.test.cpp
documentation_of: src/datastructure/SparseTable.hpp
layout: document
title: Sparse Table
---

## 概要
