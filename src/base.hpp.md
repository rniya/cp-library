---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/aplusb.test.cpp
    title: test/yosupo/aplusb.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/base.hpp\"\n#include <bits/stdc++.h>\n#ifdef LOCAL\n\
    #include <debug.hpp>\n#else\n#define debug(...) void(0)\n#endif\n\ntemplate <class\
    \ T, class U = T> bool chmin(T& x, U&& y) { return y < x and (x = std::forward<U>(y),\
    \ true); }\n\ntemplate <class T, class U = T> bool chmax(T& x, U&& y) { return\
    \ x < y and (x = std::forward<U>(y), true); }\n\ntemplate <class T> void mkuni(std::vector<T>&\
    \ v) {\n    std::ranges::sort(v);\n    auto result = std::ranges::unique(v);\n\
    \    v.erase(result.begin(), result.end());\n}\n\ntemplate <class T> int lwb(const\
    \ std::vector<T>& v, const T& x) {\n    return std::distance(v.begin(), std::ranges::lower_bound(v,\
    \ x));\n}\n"
  code: "#include <bits/stdc++.h>\n#ifdef LOCAL\n#include <debug.hpp>\n#else\n#define\
    \ debug(...) void(0)\n#endif\n\ntemplate <class T, class U = T> bool chmin(T&\
    \ x, U&& y) { return y < x and (x = std::forward<U>(y), true); }\n\ntemplate <class\
    \ T, class U = T> bool chmax(T& x, U&& y) { return x < y and (x = std::forward<U>(y),\
    \ true); }\n\ntemplate <class T> void mkuni(std::vector<T>& v) {\n    std::ranges::sort(v);\n\
    \    auto result = std::ranges::unique(v);\n    v.erase(result.begin(), result.end());\n\
    }\n\ntemplate <class T> int lwb(const std::vector<T>& v, const T& x) {\n    return\
    \ std::distance(v.begin(), std::ranges::lower_bound(v, x));\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/base.hpp
  requiredBy: []
  timestamp: '2025-05-24 15:06:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/aplusb.test.cpp
documentation_of: src/base.hpp
layout: document
title: template
---
