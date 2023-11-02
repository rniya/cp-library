---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/string/Hash.hpp
    title: "Hash \u69CB\u9020\u4F53 (reversible)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_14_C.test.cpp
    title: test/aoj/ALDS1_14_C.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: string/Hash.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include <string>\n#include \"string/Hash.hpp\"\n\nstruct RollingHash2D\
    \ {\n    using mint = hash_impl::modint;\n\n    static inline uint64_t generate_base()\
    \ {\n        std::mt19937_64 mt(std::chrono::steady_clock::now().time_since_epoch().count());\n\
    \        std::uniform_int_distribution<uint64_t> rand(2, hash_impl::mod - 1);\n\
    \        return rand(mt);\n    }\n\n    RollingHash2D(uint64_t base0 = generate_base(),\
    \ uint64_t base1 = generate_base()) {\n        basis[0] = base0;\n        basis[1]\
    \ = base1;\n        power[0].assign(1, 1);\n        power[1].assign(1, 1);\n \
    \   }\n\n    template <typename T> std::vector<std::vector<mint>> build(const\
    \ T& s) const {\n        int n = s.size(), m = s[0].size();\n        std::vector<std::vector<mint>>\
    \ hash(n + 1, std::vector<mint>(m + 1, 0));\n        for (int i = 0; i < n; i++)\
    \ {\n            for (int j = 0; j < m; j++) {\n                hash[i + 1][j\
    \ + 1] =\n                    hash[i][j + 1] * basis[0] + hash[i + 1][j] * basis[1]\
    \ - hash[i][j] * basis[0] * basis[1] + s[i][j];\n            }\n        }\n  \
    \      return hash;\n    }\n\n    template <typename T> mint get(const T& s) const\
    \ {\n        mint res = 0;\n        for (int i = 0; i < int(s.size()); i++) {\n\
    \            mint sum = 0;\n            for (const auto& x : s[i]) sum = sum *\
    \ basis[1] + x;\n            res = res * basis[0] + sum;\n        }\n        return\
    \ res;\n    }\n\n    mint query(const std::vector<std::vector<mint>>& hash, int\
    \ xl, int xr, int yl, int yr) {\n        assert(0 <= xl and xl <= xr and 0 <=\
    \ yl and yl <= yr);\n        extend(0, xr - xl);\n        extend(1, yr - yl);\n\
    \        return hash[xr][yr] - hash[xl][yr] * power[0][xr - xl] - hash[xr][yl]\
    \ * power[1][yr - yl] +\n               hash[xl][yl] * power[0][xr - xl] * power[1][yr\
    \ - yl];\n    }\n\n  private:\n    mint basis[2];\n    std::vector<mint> power[2];\n\
    \n    inline void extend(int x, int len) {\n        if (int(power[x].size()) >\
    \ len) return;\n        int pre = power[x].size();\n        power[x].resize(len\
    \ + 1);\n        for (int i = pre - 1; i < len; i++) power[x][i + 1] = power[x][i]\
    \ * basis[x];\n    }\n};\n"
  dependsOn:
  - src/string/Hash.hpp
  isVerificationFile: false
  path: src/string/RollingHash2D.hpp
  requiredBy: []
  timestamp: '2023-10-17 23:13:38+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/ALDS1_14_C.test.cpp
documentation_of: src/string/RollingHash2D.hpp
layout: document
title: Rolling Hash 2D
---

## 概要


## 問題例
- [2023牛客暑期多校训练营3 G - Beautiful Matrix](https://ac.nowcoder.com/acm/contest/57357/G)