---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/dsu.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include <numeric>\n#include <tuple>\n#include \"../atcoder/dsu\"\
    \n\nstruct MergeTree : atcoder::dsu {\n    MergeTree() {}\n\n    MergeTree(int\
    \ n) : atcoder::dsu(n), n(n), vid(n) {}\n\n    std::vector<std::pair<int, int>>\
    \ build(const std::vector<std::tuple<int, int, int>>& qs) {\n        int q = qs.size();\n\
    \        std::vector<int> root(n), idx(q, -1);\n        std::iota(root.begin(),\
    \ root.end(), 0);\n        child.resize(q);\n        range.resize(n + q);\n  \
    \      for (int i = 0; i < q; i++) {\n            auto [type, a, b] = qs[i];\n\
    \            if (type == 0) {\n                if (same(a, b)) continue;\n   \
    \             child[i] = {root[leader(a)], root[leader(b)]};\n               \
    \ root[merge(a, b)] = n + i;\n            } else\n                idx[i] = root[leader(a)];\n\
    \        }\n        int cur = 0;\n        for (int i = 0; i < n; i++) {\n    \
    \        if (leader(i) == i) {\n                dfs(root[i], cur);\n         \
    \   }\n        }\n        std::vector<std::pair<int, int>> res(q);\n        for\
    \ (int i = 0; i < q; i++) {\n            if (idx[i] != -1) {\n               \
    \ res[i] = range[idx[i]];\n            }\n        }\n        return res;\n   \
    \ }\n\n    int operator[](int v) const { return vid[v]; }\n\n  private:\n    int\
    \ n;\n    std::vector<int> vid;\n    std::vector<std::pair<int, int>> child, range;\n\
    \n    void dfs(int v, int& cur) {\n        int l = cur;\n        if (v < n)\n\
    \            vid[v] = cur++;\n        else {\n            auto [a, b] = child[v\
    \ - n];\n            dfs(a, cur);\n            dfs(b, cur);\n        }\n     \
    \   int r = cur;\n        range[v] = {l, r};\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/tree/MergeTree.hpp
  requiredBy: []
  timestamp: '2024-05-22 00:21:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/tree/MergeTree.hpp
layout: document
title: "\u30DE\u30FC\u30B8\u904E\u7A0B\u3092\u8868\u3059\u6728"
---

## 概要
マージ過程を表す木．

| メンバ関数     | 効果                                                                                                                                                                                                              | 時間計算量                     |
| -------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------------------------ |
| `MergeTree(n)` | $n$ 要素について初期化する．                                                                                                                                                                                      | $\mathrm{O}(n)$                |
| `build(qs)`    | タイプ `0` のクエリでは $2$ 要素 $u, v$ が含まれるグループを併合し，タイプ `1` のクエリではその時点での要素 $u$ の含まれるグループの成す区間 $[l, r)$ を求めたい．このとき，タイプ `1` のクエリの返り値を求める． | $\mathrm{O}((n + q)\alpha(n))$ |
| `operator[i]`  | 列の中で頂点 $i$ に対応する位置を返す．                                                                                                                                                                           | $\mathrm{O}(1)$                |



## 問題例
- [Codeforces Round 317 [AimFund Thanks-Round] (Div. 1) D. Campus](https://codeforces.com/contest/571/problem/D)
- [AtCoder Beginner Contest 314 F - A Certain Game](https://atcoder.jp/contests/abc314/tasks/abc314_f)