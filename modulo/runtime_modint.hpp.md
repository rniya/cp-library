---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/526.test.cpp
    title: test/yukicoder/526.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: "\u5B9F\u884C\u6642 modint"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 70, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 310, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ modulo/runtime_modint.hpp: line 5: #pragma once found in a non-first line\n"
  code: "/**\n * @brief \u5B9F\u884C\u6642 modint\n */\n\n#pragma once\n\n#include\
    \ \"../base.hpp\"\n\nclass runtime_modint{\n    using u64=uint_fast64_t;\n   \
    \ static u64 &mod(){\n        static u64 mod_=0;\n        return mod_;\n    }\n\
    public:\n    u64 a;\n    static void set_mod(const u64 x){mod()=x;}\n    static\
    \ u64 get_mod(){return mod();}\n    runtime_modint(const u64 x=0):a(x%get_mod()){}\n\
    \    u64 &balue() noexcept{return a;}\n    const u64 &value() const noexcept{return\
    \ a;}\n    runtime_modint &operator+=(const runtime_modint &rhs){\n        a+=rhs.a;\n\
    \        if (a>=get_mod()) a-=get_mod();\n        return *this;\n    }\n    runtime_modint\
    \ operator+(const runtime_modint &rhs) const{\n        return runtime_modint(*this)+=rhs;\n\
    \    }\n    runtime_modint &operator-=(const runtime_modint &rhs){\n        if\
    \ (a<rhs.a) a+=get_mod();\n        a-=rhs.a;\n        return *this;\n    }\n \
    \   runtime_modint operator-(const runtime_modint &rhs) const{\n        return\
    \ runtime_modint(*this)-=rhs;\n    }\n    runtime_modint &operator*=(const runtime_modint\
    \ &rhs){\n        a=a*rhs.a%get_mod();\n        return *this;\n    }\n    runtime_modint\
    \ operator*(const runtime_modint &rhs) const{\n        return runtime_modint(*this)*=rhs;\n\
    \    }\n    runtime_modint &operator/=(runtime_modint rhs){\n        u64 exp=get_mod()-2;\n\
    \        while(exp){\n            if (exp&1) *this*=rhs;\n            rhs*=rhs;\
    \ exp>>=1;\n        }\n        return *this;\n    }\n    runtime_modint operator/(const\
    \ runtime_modint &rhs) const{\n        return runtime_modint(*this)/=rhs;\n  \
    \  }\n    friend runtime_modint pow(runtime_modint rhs,long long exp) noexcept{\n\
    \        runtime_modint res{1};\n        while(exp){\n            if (exp&1) res*=rhs;\n\
    \            rhs*=rhs; exp>>=1;\n        }\n        return res;\n    }\n    friend\
    \ ostream &operator<<(ostream &s,const runtime_modint &rhs){\n        return s\
    \ << rhs.a;\n    }\n    friend istream &operator>>(istream &s,runtime_modint &rhs){\n\
    \        u64 a; rhs=runtime_modint{(s >> a,a)}; return s;\n    }\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: modulo/runtime_modint.hpp
  requiredBy: []
  timestamp: '2020-09-10 15:23:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/526.test.cpp
documentation_of: modulo/runtime_modint.hpp
layout: document
redirect_from:
- /library/modulo/runtime_modint.hpp
- /library/modulo/runtime_modint.hpp.html
title: "\u5B9F\u884C\u6642 modint"
---
