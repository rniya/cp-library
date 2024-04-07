---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/datastructure/RectangleSet.hpp
    title: Rectangle Set
  - icon: ':x:'
    path: src/math/fast_factorize.hpp
    title: "\u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3 (Miller-Rabin primality test\
      \ + Pollard's rho algorithm)"
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/DSL_3_D.test.cpp
    title: test/aoj/DSL_3_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/aplusb.test.cpp
    title: test/yosupo/aplusb.test.cpp
  - icon: ':x:'
    path: test/yosupo/factorize.test.cpp
    title: test/yosupo/factorize.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/base.hpp\"\n#include <bits/stdc++.h>\n#ifdef LOCAL\n\
    #include <debug.hpp>\n#else\n#define debug(...) void(0)\n#endif\n\ntemplate <class\
    \ T> std::istream& operator>>(std::istream& is, std::vector<T>& v) {\n    for\
    \ (auto& x : v) is >> x;\n    return is;\n}\n\ntemplate <class T> std::ostream&\
    \ operator<<(std::ostream& os, const std::vector<T>& v) {\n    auto sep = \"\"\
    ;\n    for (const auto& x : v) os << std::exchange(sep, \" \") << x;\n    return\
    \ os;\n}\n\ntemplate <class T, class U = T> bool chmin(T& x, U&& y) { return y\
    \ < x and (x = std::forward<U>(y), true); }\n\ntemplate <class T, class U = T>\
    \ bool chmax(T& x, U&& y) { return x < y and (x = std::forward<U>(y), true); }\n\
    \ntemplate <class T> void mkuni(std::vector<T>& v) {\n    std::sort(begin(v),\
    \ end(v));\n    v.erase(unique(begin(v), end(v)), end(v));\n}\n\ntemplate <class\
    \ T> int lwb(const std::vector<T>& v, const T& x) {\n    return std::lower_bound(begin(v),\
    \ end(v), x) - begin(v);\n}\n"
  code: "#include <bits/stdc++.h>\n#ifdef LOCAL\n#include <debug.hpp>\n#else\n#define\
    \ debug(...) void(0)\n#endif\n\ntemplate <class T> std::istream& operator>>(std::istream&\
    \ is, std::vector<T>& v) {\n    for (auto& x : v) is >> x;\n    return is;\n}\n\
    \ntemplate <class T> std::ostream& operator<<(std::ostream& os, const std::vector<T>&\
    \ v) {\n    auto sep = \"\";\n    for (const auto& x : v) os << std::exchange(sep,\
    \ \" \") << x;\n    return os;\n}\n\ntemplate <class T, class U = T> bool chmin(T&\
    \ x, U&& y) { return y < x and (x = std::forward<U>(y), true); }\n\ntemplate <class\
    \ T, class U = T> bool chmax(T& x, U&& y) { return x < y and (x = std::forward<U>(y),\
    \ true); }\n\ntemplate <class T> void mkuni(std::vector<T>& v) {\n    std::sort(begin(v),\
    \ end(v));\n    v.erase(unique(begin(v), end(v)), end(v));\n}\n\ntemplate <class\
    \ T> int lwb(const std::vector<T>& v, const T& x) {\n    return std::lower_bound(begin(v),\
    \ end(v), x) - begin(v);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/base.hpp
  requiredBy:
  - src/datastructure/RectangleSet.hpp
  - src/math/fast_factorize.hpp
  timestamp: '2024-04-07 16:52:23+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/aoj/DSL_3_D.test.cpp
  - test/yosupo/aplusb.test.cpp
  - test/yosupo/factorize.test.cpp
documentation_of: src/base.hpp
layout: document
redirect_from:
- /library/src/base.hpp
- /library/src/base.hpp.html
title: src/base.hpp
---
