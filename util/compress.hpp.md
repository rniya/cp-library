---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/static_range_inversions_query.test.cpp
    title: test/yosupo/static_range_inversions_query.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: "compress (\u5EA7\u6A19\u5727\u7E2E)"
    links: []
  bundledCode: "#line 2 \"util/compress.hpp\"\n#include <algorithm>\n#include <map>\n\
    #include <vector>\n\ntemplate <typename T> std::map<T, int> compress(std::vector<T>&\
    \ v) {\n    std::sort(v.begin(), v.end());\n    v.erase(unique(v.begin(), v.end()),\
    \ v.end());\n    std::map<T, int> res;\n    for (size_t i = 0; i < v.size(); i++)\
    \ res[v[i]] = i;\n    return res;\n}\n\n/**\n * @brief compress (\u5EA7\u6A19\u5727\
    \u7E2E)\n */\n"
  code: "#pragma once\n#include <algorithm>\n#include <map>\n#include <vector>\n\n\
    template <typename T> std::map<T, int> compress(std::vector<T>& v) {\n    std::sort(v.begin(),\
    \ v.end());\n    v.erase(unique(v.begin(), v.end()), v.end());\n    std::map<T,\
    \ int> res;\n    for (size_t i = 0; i < v.size(); i++) res[v[i]] = i;\n    return\
    \ res;\n}\n\n/**\n * @brief compress (\u5EA7\u6A19\u5727\u7E2E)\n */"
  dependsOn: []
  isVerificationFile: false
  path: util/compress.hpp
  requiredBy: []
  timestamp: '2021-09-25 17:45:48+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/static_range_inversions_query.test.cpp
documentation_of: util/compress.hpp
layout: document
redirect_from:
- /library/util/compress.hpp
- /library/util/compress.hpp.html
title: "compress (\u5EA7\u6A19\u5727\u7E2E)"
---
