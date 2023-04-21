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
  bundledCode: "#line 2 \"src/debug.hpp\"\n#include <bits/stdc++.h>\n\ntemplate <typename\
    \ T, typename U> std::ostream& operator<<(std::ostream& os, const std::pair<T,\
    \ U>& p);\ntemplate <typename T, typename U> std::ostream& operator<<(std::ostream&\
    \ os, const std::map<T, U>& m);\ntemplate <typename T> std::ostream& operator<<(std::ostream&\
    \ os, const std::set<T>& s);\ntemplate <typename T> std::ostream& operator<<(std::ostream&\
    \ os, const std::multiset<T>& s);\ntemplate <typename T> std::ostream& operator<<(std::ostream&\
    \ os, const std::deque<T>& v);\ntemplate <typename... Args> std::ostream& operator<<(std::ostream&\
    \ os, const std::tuple<Args...>& t);\n\ntemplate <typename T, typename U> std::ostream&\
    \ operator<<(std::ostream& os, const std::pair<T, U>& p) {\n    os << '(' << p.first\
    \ << ',' << p.second << ')';\n    return os;\n}\ntemplate <typename T, typename\
    \ U> std::ostream& operator<<(std::ostream& os, const std::map<T, U>& m) {\n \
    \   os << '{';\n    for (auto itr = m.begin(); itr != m.end();) {\n        os\
    \ << '(' << itr->first << ',' << itr->second << ')';\n        if (++itr != m.end())\
    \ os << ',';\n    }\n    os << '}';\n    return os;\n}\ntemplate <typename T>\
    \ std::ostream& operator<<(std::ostream& os, const std::set<T>& s) {\n    os <<\
    \ '{';\n    for (auto itr = s.begin(); itr != s.end();) {\n        os << *itr;\n\
    \        if (++itr != s.end()) os << ',';\n    }\n    os << '}';\n    return os;\n\
    }\ntemplate <typename T> std::ostream& operator<<(std::ostream& os, const std::multiset<T>&\
    \ s) {\n    os << '{';\n    for (auto itr = s.begin(); itr != s.end();) {\n  \
    \      os << *itr;\n        if (++itr != s.end()) os << ',';\n    }\n    os <<\
    \ '}';\n    return os;\n}\ntemplate <typename T> std::ostream& operator<<(std::ostream&\
    \ os, const std::deque<T>& v) {\n    for (size_t i = 0; i < v.size(); i++) {\n\
    \        os << v[i] << (i + 1 == v.size() ? \"\" : \" \");\n    }\n    return\
    \ os;\n}\n\ntemplate <int i, typename T> void print_tuple(std::ostream&, const\
    \ T&) {}\ntemplate <int i, typename T, typename H, class... Args> void print_tuple(std::ostream&\
    \ os, const T& t) {\n    if (i) os << ',';\n    os << get<i>(t);\n    print_tuple<i\
    \ + 1, T, Args...>(os, t);\n}\ntemplate <typename... Args> std::ostream& operator<<(std::ostream&\
    \ os, const std::tuple<Args...>& t) {\n    os << '{';\n    print_tuple<0, std::tuple<Args...>,\
    \ Args...>(os, t);\n    return os << '}';\n}\n\nvoid debug_out() { std::cerr <<\
    \ '\\n'; }\ntemplate <class Head, class... Tail> void debug_out(Head&& head, Tail&&...\
    \ tail) {\n    std::cerr << head;\n    if (sizeof...(Tail) > 0) std::cerr << \"\
    , \";\n    debug_out(std::move(tail)...);\n}\n#define debug(...)             \
    \                                                       \\\n    cerr << \" \"\
    ;                                                                      \\\n  \
    \  cerr << #__VA_ARGS__ << \": [\" << __LINE__ << \": \" << __FUNCTION__ << \"\
    ]\" << '\\n'; \\\n    cerr << \" \";                                         \
    \                             \\\n    debug_out(__VA_ARGS__)\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n\ntemplate <typename T, typename\
    \ U> std::ostream& operator<<(std::ostream& os, const std::pair<T, U>& p);\ntemplate\
    \ <typename T, typename U> std::ostream& operator<<(std::ostream& os, const std::map<T,\
    \ U>& m);\ntemplate <typename T> std::ostream& operator<<(std::ostream& os, const\
    \ std::set<T>& s);\ntemplate <typename T> std::ostream& operator<<(std::ostream&\
    \ os, const std::multiset<T>& s);\ntemplate <typename T> std::ostream& operator<<(std::ostream&\
    \ os, const std::deque<T>& v);\ntemplate <typename... Args> std::ostream& operator<<(std::ostream&\
    \ os, const std::tuple<Args...>& t);\n\ntemplate <typename T, typename U> std::ostream&\
    \ operator<<(std::ostream& os, const std::pair<T, U>& p) {\n    os << '(' << p.first\
    \ << ',' << p.second << ')';\n    return os;\n}\ntemplate <typename T, typename\
    \ U> std::ostream& operator<<(std::ostream& os, const std::map<T, U>& m) {\n \
    \   os << '{';\n    for (auto itr = m.begin(); itr != m.end();) {\n        os\
    \ << '(' << itr->first << ',' << itr->second << ')';\n        if (++itr != m.end())\
    \ os << ',';\n    }\n    os << '}';\n    return os;\n}\ntemplate <typename T>\
    \ std::ostream& operator<<(std::ostream& os, const std::set<T>& s) {\n    os <<\
    \ '{';\n    for (auto itr = s.begin(); itr != s.end();) {\n        os << *itr;\n\
    \        if (++itr != s.end()) os << ',';\n    }\n    os << '}';\n    return os;\n\
    }\ntemplate <typename T> std::ostream& operator<<(std::ostream& os, const std::multiset<T>&\
    \ s) {\n    os << '{';\n    for (auto itr = s.begin(); itr != s.end();) {\n  \
    \      os << *itr;\n        if (++itr != s.end()) os << ',';\n    }\n    os <<\
    \ '}';\n    return os;\n}\ntemplate <typename T> std::ostream& operator<<(std::ostream&\
    \ os, const std::deque<T>& v) {\n    for (size_t i = 0; i < v.size(); i++) {\n\
    \        os << v[i] << (i + 1 == v.size() ? \"\" : \" \");\n    }\n    return\
    \ os;\n}\n\ntemplate <int i, typename T> void print_tuple(std::ostream&, const\
    \ T&) {}\ntemplate <int i, typename T, typename H, class... Args> void print_tuple(std::ostream&\
    \ os, const T& t) {\n    if (i) os << ',';\n    os << get<i>(t);\n    print_tuple<i\
    \ + 1, T, Args...>(os, t);\n}\ntemplate <typename... Args> std::ostream& operator<<(std::ostream&\
    \ os, const std::tuple<Args...>& t) {\n    os << '{';\n    print_tuple<0, std::tuple<Args...>,\
    \ Args...>(os, t);\n    return os << '}';\n}\n\nvoid debug_out() { std::cerr <<\
    \ '\\n'; }\ntemplate <class Head, class... Tail> void debug_out(Head&& head, Tail&&...\
    \ tail) {\n    std::cerr << head;\n    if (sizeof...(Tail) > 0) std::cerr << \"\
    , \";\n    debug_out(std::move(tail)...);\n}\n#define debug(...)             \
    \                                                       \\\n    cerr << \" \"\
    ;                                                                      \\\n  \
    \  cerr << #__VA_ARGS__ << \": [\" << __LINE__ << \": \" << __FUNCTION__ << \"\
    ]\" << '\\n'; \\\n    cerr << \" \";                                         \
    \                             \\\n    debug_out(__VA_ARGS__)\n"
  dependsOn: []
  isVerificationFile: false
  path: src/debug.hpp
  requiredBy: []
  timestamp: '2023-04-22 02:23:28+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/debug.hpp
layout: document
redirect_from:
- /library/src/debug.hpp
- /library/src/debug.hpp.html
title: src/debug.hpp
---
