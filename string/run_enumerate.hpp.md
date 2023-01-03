---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/runenumerate.test.cpp
    title: test/yosupo/runenumerate.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"string/run_enumerate.hpp\"\n#include <algorithm>\n#include\
    \ <string>\n#include <tuple>\n#include <utility>\n#include <vector>\n\nnamespace\
    \ run_enumerate {\n\n// Reference:\n// D. Gusfield,\n// Algorithms on Strings,\
    \ Trees, and Sequences: Computer Science and\n// Computational Biology\ntemplate\
    \ <class T> std::vector<int> z_algorithm(const std::vector<T>& s) {\n    int n\
    \ = int(s.size());\n    if (n == 0) return {};\n    std::vector<int> z(n);\n \
    \   z[0] = 0;\n    for (int i = 1, j = 0; i < n; i++) {\n        int& k = z[i];\n\
    \        k = (j + z[j] <= i) ? 0 : std::min(j + z[j] - i, z[i - j]);\n       \
    \ while (i + k < n && s[k] == s[i + k]) k++;\n        if (j + z[j] < i + z[i])\
    \ j = i;\n    }\n    z[0] = n;\n    return z;\n}\n\nstd::vector<int> z_algorithm(const\
    \ std::string& s) {\n    int n = int(s.size());\n    std::vector<int> s2(n);\n\
    \    for (int i = 0; i < n; i++) {\n        s2[i] = s[i];\n    }\n    return z_algorithm(s2);\n\
    }\n\ntemplate <class T> std::vector<std::tuple<int, int, int>> enumerate(const\
    \ std::vector<T>& s) {\n    int n = s.size();\n    std::vector<std::tuple<int,\
    \ int, int>> res;\n    auto dfs = [&](auto&& self, int l, int r) -> void {\n \
    \       if (r - l <= 1) return;\n        int m = (l + r) >> 1;\n        self(self,\
    \ l, m);\n        self(self, m, r);\n        std::vector<T> sl(s.rbegin() + n\
    \ - m, s.rbegin() + n - l);\n        sl.insert(sl.end(), s.rbegin() + n - r, s.rbegin()\
    \ + n - l);\n        std::vector<T> sr(s.begin() + m, s.begin() + r);\n      \
    \  sr.insert(sr.end(), s.begin() + l, s.begin() + r);\n        auto zsl = z_algorithm(sl),\
    \ zsr = z_algorithm(sr);\n        for (int t = 1; t <= m - l; t++) {\n       \
    \     int ml = std::max(l, m - t - zsl[t]), mr = std::min(r, m + zsr[r - l - t]);\n\
    \            if (mr - ml >= 2 * t and (ml == 0 or s[ml - 1] != s[ml + t - 1])\
    \ and (mr == n or s[mr] != s[mr - t]))\n                res.emplace_back(ml, mr,\
    \ t);\n        }\n        for (int t = 1; t <= r - m; t++) {\n            int\
    \ ml = std::max(l, m - zsl[r - l - t]), mr = std::min(r, m + t + zsr[t]);\n  \
    \          if (mr - ml >= 2 * t and (ml == 0 or s[ml - 1] != s[ml + t - 1]) and\
    \ (mr == n or s[mr] != s[mr - t]))\n                res.emplace_back(ml, mr, t);\n\
    \        }\n    };\n    dfs(dfs, 0, n);\n    std::sort(res.begin(), res.end());\n\
    \    std::vector<std::tuple<int, int, int>> nres;\n    int pl = -1, pr = -1;\n\
    \    for (auto [l, r, t] : res) {\n        if (l == pl and r == pr) continue;\n\
    \        pl = l, pr = r;\n        nres.emplace_back(t, l, r);\n    }\n    return\
    \ nres;\n}\n\nstd::vector<std::tuple<int, int, int>> enumerate(const std::string&\
    \ s) {\n    return enumerate(std::vector<char>(s.begin(), s.end()));\n}\n\n} \
    \ // namespace run_enumerate\n"
  code: "#include <algorithm>\n#include <string>\n#include <tuple>\n#include <utility>\n\
    #include <vector>\n\nnamespace run_enumerate {\n\n// Reference:\n// D. Gusfield,\n\
    // Algorithms on Strings, Trees, and Sequences: Computer Science and\n// Computational\
    \ Biology\ntemplate <class T> std::vector<int> z_algorithm(const std::vector<T>&\
    \ s) {\n    int n = int(s.size());\n    if (n == 0) return {};\n    std::vector<int>\
    \ z(n);\n    z[0] = 0;\n    for (int i = 1, j = 0; i < n; i++) {\n        int&\
    \ k = z[i];\n        k = (j + z[j] <= i) ? 0 : std::min(j + z[j] - i, z[i - j]);\n\
    \        while (i + k < n && s[k] == s[i + k]) k++;\n        if (j + z[j] < i\
    \ + z[i]) j = i;\n    }\n    z[0] = n;\n    return z;\n}\n\nstd::vector<int> z_algorithm(const\
    \ std::string& s) {\n    int n = int(s.size());\n    std::vector<int> s2(n);\n\
    \    for (int i = 0; i < n; i++) {\n        s2[i] = s[i];\n    }\n    return z_algorithm(s2);\n\
    }\n\ntemplate <class T> std::vector<std::tuple<int, int, int>> enumerate(const\
    \ std::vector<T>& s) {\n    int n = s.size();\n    std::vector<std::tuple<int,\
    \ int, int>> res;\n    auto dfs = [&](auto&& self, int l, int r) -> void {\n \
    \       if (r - l <= 1) return;\n        int m = (l + r) >> 1;\n        self(self,\
    \ l, m);\n        self(self, m, r);\n        std::vector<T> sl(s.rbegin() + n\
    \ - m, s.rbegin() + n - l);\n        sl.insert(sl.end(), s.rbegin() + n - r, s.rbegin()\
    \ + n - l);\n        std::vector<T> sr(s.begin() + m, s.begin() + r);\n      \
    \  sr.insert(sr.end(), s.begin() + l, s.begin() + r);\n        auto zsl = z_algorithm(sl),\
    \ zsr = z_algorithm(sr);\n        for (int t = 1; t <= m - l; t++) {\n       \
    \     int ml = std::max(l, m - t - zsl[t]), mr = std::min(r, m + zsr[r - l - t]);\n\
    \            if (mr - ml >= 2 * t and (ml == 0 or s[ml - 1] != s[ml + t - 1])\
    \ and (mr == n or s[mr] != s[mr - t]))\n                res.emplace_back(ml, mr,\
    \ t);\n        }\n        for (int t = 1; t <= r - m; t++) {\n            int\
    \ ml = std::max(l, m - zsl[r - l - t]), mr = std::min(r, m + t + zsr[t]);\n  \
    \          if (mr - ml >= 2 * t and (ml == 0 or s[ml - 1] != s[ml + t - 1]) and\
    \ (mr == n or s[mr] != s[mr - t]))\n                res.emplace_back(ml, mr, t);\n\
    \        }\n    };\n    dfs(dfs, 0, n);\n    std::sort(res.begin(), res.end());\n\
    \    std::vector<std::tuple<int, int, int>> nres;\n    int pl = -1, pr = -1;\n\
    \    for (auto [l, r, t] : res) {\n        if (l == pl and r == pr) continue;\n\
    \        pl = l, pr = r;\n        nres.emplace_back(t, l, r);\n    }\n    return\
    \ nres;\n}\n\nstd::vector<std::tuple<int, int, int>> enumerate(const std::string&\
    \ s) {\n    return enumerate(std::vector<char>(s.begin(), s.end()));\n}\n\n} \
    \ // namespace run_enumerate\n"
  dependsOn: []
  isVerificationFile: false
  path: string/run_enumerate.hpp
  requiredBy: []
  timestamp: '2023-01-03 16:31:20+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/runenumerate.test.cpp
documentation_of: string/run_enumerate.hpp
layout: document
title: Run Enumerate
---

## 概要
文字列 $S$ 中の run を列挙する．
run とは文字列中の部分文字列の繰り返しであって長さが極大で周期が最小のものを指し，本アルゴリズムでは以下の条件を満たす $(t, l, r)$ を列挙する．
- $S$ の $l$ 文字目から $r - 1$ 文字目の最小周期は $t$ であり，$r - l \geq 2 t$ を満たす．
- 上の条件を満たすもののうち，$l, r$ は極大である．つまり $(t, l - 1, r), (t, l, r + 1)$ は上の条件を満たさない


計算量は $|S| = n$ として $O(n \log n)$．
また，アルゴリズムの存在からこのような $(t, l, r)$ の個数は $O(n \log n)$ 個であることがわかるが，実際は $O(n)$ で列挙するアルゴリズムも存在し，個数はさらに $O(n)$ で抑えることが可能である．

## Links
- [Runの列挙 (Main-Lorentz algorithm) - 迷いませんか？](https://pazzle1230.hatenablog.com/entry/2019/11/27/234632)

## 問題例
- [DMOPC '22 Contest 3 P6 - Compressibility](https://dmoj.ca/problem/dmopc22c3p6)