---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/tree/CentroidDecomposition.hpp
    title: Centroid Decomposition
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/frequency_table_of_tree_distance
    links:
    - https://judge.yosupo.jp/problem/frequency_table_of_tree_distance
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/convolution:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/frequency_table_of_tree_distance\"\
    \n\n#include <iostream>\n#include \"atcoder/convolution\"\n#include \"tree/CentroidDecomposition.hpp\"\
    \n\nint main() {\n    std::cin.tie(0);\n    std::ios::sync_with_stdio(false);\n\
    \    int N;\n    std::cin >> N;\n    CentroidDecomposition CD(N);\n    for (int\
    \ i = 0; i < N - 1; i++) {\n        int a, b;\n        std::cin >> a >> b;\n \
    \       CD.add_edge(a, b);\n    }\n\n    std::vector<int> alive(N, true);\n  \
    \  auto& G = CD.G;\n    auto calc = [&](auto self, int v, int p, int d, std::vector<long\
    \ long>& cnt) -> void {\n        while ((int)cnt.size() <= d) cnt.emplace_back(0);\n\
    \        cnt[d]++;\n        for (int& u : G[v]) {\n            if (u == p || !alive[u])\
    \ continue;\n            self(self, u, v, d + 1, cnt);\n        }\n    };\n\n\
    \    auto cs = CD.build();\n    std::vector<long long> ans(2 * N, 0);\n\n    for\
    \ (int& root : cs) {\n        alive[root] = 0;\n        std::vector<long long>\
    \ sum{1};\n        for (int& ch : G[root]) {\n            if (!alive[ch]) continue;\n\
    \            std::vector<long long> cnt;\n            calc(calc, ch, root, 1,\
    \ cnt);\n            auto sub = atcoder::convolution_ll(cnt, cnt);\n         \
    \   for (size_t i = 0; i < sub.size(); i++) ans[i] -= sub[i];\n            while\
    \ (sum.size() < cnt.size()) sum.emplace_back(0);\n            for (size_t i =\
    \ 0; i < cnt.size(); i++) sum[i] += cnt[i];\n        }\n        auto add = atcoder::convolution_ll(sum,\
    \ sum);\n        for (size_t i = 0; i < add.size(); i++) ans[i] += add[i];\n \
    \   }\n\n    for (int i = 1; i < N; i++) std::cout << ans[i] / 2 << (i + 1 ==\
    \ N ? '\\n' : ' ');\n}"
  dependsOn:
  - src/tree/CentroidDecomposition.hpp
  isVerificationFile: true
  path: test/yosupo/frequency_table_of_tree_distance.test.cpp
  requiredBy: []
  timestamp: '2024-03-31 18:08:00+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/frequency_table_of_tree_distance.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/frequency_table_of_tree_distance.test.cpp
- /verify/test/yosupo/frequency_table_of_tree_distance.test.cpp.html
title: test/yosupo/frequency_table_of_tree_distance.test.cpp
---
