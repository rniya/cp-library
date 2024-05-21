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
    \ T> std::istream& operator>>(std::istream& is, std::vector<T>& v) {\n    for\
    \ (auto& e : v) {\n        is >> e;\n    }\n    return is;\n}\n\ntemplate <class\
    \ T> std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) {\n \
    \   for (std::string_view sep = \"\"; const auto& e : v) {\n        os << std::exchange(sep,\
    \ \" \") << e;\n    }\n    return os;\n}\n\ntemplate <class T, class U = T> bool\
    \ chmin(T& x, U&& y) {\n    return y < x and (x = std::forward<U>(y), true);\n\
    }\n\ntemplate <class T, class U = T> bool chmax(T& x, U&& y) {\n    return x <\
    \ y and (x = std::forward<U>(y), true);\n}\n\ntemplate <class T> void mkuni(std::vector<T>&\
    \ v) {\n    std::ranges::sort(v);\n    auto result = std::ranges::unique(v);\n\
    \    v.erase(result.begin(), result.end());\n}\n\ntemplate <class T> int lwb(const\
    \ std::vector<T>& v, const T& x) {\n    return std::distance(v.begin(), std::ranges::lower_bound(v,\
    \ x));\n}\n"
  code: "#include <bits/stdc++.h>\n#ifdef LOCAL\n#include <debug.hpp>\n#else\n#define\
    \ debug(...) void(0)\n#endif\n\ntemplate <class T> std::istream& operator>>(std::istream&\
    \ is, std::vector<T>& v) {\n    for (auto& e : v) {\n        is >> e;\n    }\n\
    \    return is;\n}\n\ntemplate <class T> std::ostream& operator<<(std::ostream&\
    \ os, const std::vector<T>& v) {\n    for (std::string_view sep = \"\"; const\
    \ auto& e : v) {\n        os << std::exchange(sep, \" \") << e;\n    }\n    return\
    \ os;\n}\n\ntemplate <class T, class U = T> bool chmin(T& x, U&& y) {\n    return\
    \ y < x and (x = std::forward<U>(y), true);\n}\n\ntemplate <class T, class U =\
    \ T> bool chmax(T& x, U&& y) {\n    return x < y and (x = std::forward<U>(y),\
    \ true);\n}\n\ntemplate <class T> void mkuni(std::vector<T>& v) {\n    std::ranges::sort(v);\n\
    \    auto result = std::ranges::unique(v);\n    v.erase(result.begin(), result.end());\n\
    }\n\ntemplate <class T> int lwb(const std::vector<T>& v, const T& x) {\n    return\
    \ std::distance(v.begin(), std::ranges::lower_bound(v, x));\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/base.hpp
  requiredBy: []
  timestamp: '2024-05-12 03:06:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/aplusb.test.cpp
documentation_of: src/base.hpp
layout: document
redirect_from:
- /library/src/base.hpp
- /library/src/base.hpp.html
title: src/base.hpp
---
