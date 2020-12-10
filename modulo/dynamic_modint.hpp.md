---
data:
  _extendedDependsOn:
  - icon: ':question:'
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
    _deprecated_at_docs: docs/modulo/modint.md
    document_title: "\u5B9F\u884C\u6642 modint"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 310, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ modulo/dynamic_modint.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/**\n * @brief \u5B9F\u884C\u6642 modint\n * @docs docs/modulo/modint.md\n\
    \ */\n\n#pragma once\n\n#include \"../base.hpp\"\n\nclass dynamic_modint{\n  \
    \  using i64=int64_t;\n    using u32=uint32_t;\n    using u64=uint64_t;\n    static\
    \ u32 &mod(){\n        static u32 mod_=0;\n        return mod_;\n    }\npublic:\n\
    \    u32 v;\n    static void set_mod(const u32 x){\n        assert(x<(u32(1)<<31));\n\
    \        mod()=x;\n    }\n    static u32 get_mod(){return mod();}\n    dynamic_modint(const\
    \ i64 x=0):v(x<0?get_mod()-1-(-(x+1)%get_mod()):x%get_mod()){}\n    u32 &value()\
    \ noexcept {return v;}\n    const u32 &value() const noexcept {return v;}\n  \
    \  dynamic_modint operator+(const dynamic_modint &rhs) const {return dynamic_modint(*this)+=rhs;}\n\
    \    dynamic_modint operator-(const dynamic_modint &rhs) const {return dynamic_modint(*this)-=rhs;}\n\
    \    dynamic_modint operator*(const dynamic_modint &rhs) const {return dynamic_modint(*this)*=rhs;}\n\
    \    dynamic_modint operator/(const dynamic_modint &rhs) const {return dynamic_modint(*this)/=rhs;}\n\
    \    dynamic_modint &operator+=(const dynamic_modint &rhs){\n        v+=rhs.v;\n\
    \        if (v>=get_mod()) v-=get_mod();\n        return *this;\n    }\n    dynamic_modint\
    \ &operator-=(const dynamic_modint &rhs){\n        if (v<rhs.v) v+=get_mod();\n\
    \        v-=rhs.v;\n        return *this;\n    }\n    dynamic_modint &operator*=(const\
    \ dynamic_modint &rhs){\n        v=(u64)v*rhs.v%get_mod();\n        return *this;\n\
    \    }\n    dynamic_modint &operator/=(const dynamic_modint &rhs){\n        return\
    \ *this*=rhs.pow(get_mod()-2);\n    }\n    dynamic_modint pow(u64 exp) const {\n\
    \        dynamic_modint self(*this),res(1);\n        while (exp>0){\n        \
    \    if (exp&1) res*=self;\n            self*=self; exp>>=1;\n        }\n    \
    \    return res;\n    }\n    dynamic_modint &operator++(){if (++v==get_mod())\
    \ v=0; return *this;}\n    dynamic_modint &operator--(){if (v==0) v=get_mod();\
    \ return --v,*this;}\n    dynamic_modint operator++(int){dynamic_modint t=*this;\
    \ return ++*this,t;}\n    dynamic_modint operator--(int){dynamic_modint t=*this;\
    \ return --*this,t;}\n    dynamic_modint operator-(){return dynamic_modint(get_mod()-v);}\n\
    \    template<class T> friend dynamic_modint operator+(T x,dynamic_modint y){return\
    \ dynamic_modint(x)+y;}\n    template<class T> friend dynamic_modint operator-(T\
    \ x,dynamic_modint y){return dynamic_modint(x)-y;}\n    template<class T> friend\
    \ dynamic_modint operator*(T x,dynamic_modint y){return dynamic_modint(x)*y;}\n\
    \    template<class T> friend dynamic_modint operator/(T x,dynamic_modint y){return\
    \ dynamic_modint(x)/y;}\n    bool operator==(const dynamic_modint &rhs){return\
    \ v==rhs.v;}\n    bool operator!=(const dynamic_modint &rhs){return v!=rhs.v;}\n\
    \    bool operator!(){return !v;}\n    friend istream &operator>>(istream &s,dynamic_modint\
    \ &rhs){\n        i64 v; rhs=dynamic_modint{(s>>v,v)}; return s;\n    }\n    friend\
    \ ostream &operator<<(ostream &s,const dynamic_modint &rhs){\n        return s<<rhs.v;\n\
    \    }\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: modulo/dynamic_modint.hpp
  requiredBy: []
  timestamp: '2020-11-19 22:07:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/526.test.cpp
documentation_of: modulo/dynamic_modint.hpp
layout: document
redirect_from:
- /library/modulo/dynamic_modint.hpp
- /library/modulo/dynamic_modint.hpp.html
title: "\u5B9F\u884C\u6642 modint"
---
## 概要
- 各種演算子(`operator++, operator--, operator-(), operator==, `等)に対応
- `std::cin, std::cout`への対応
- 負数に対応したコンストラクタ
- 内部を32bit符号なし整数で保存

## 参照
[modint 構造体を使ってみませんか？ (C++) - noshi91のメモ](https://noshi91.hatenablog.com/entry/2019/03/31/174006)