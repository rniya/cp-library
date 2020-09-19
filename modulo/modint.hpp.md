---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: test/atcoder/tdpc_fibonacci.cpp
    title: test/atcoder/tdpc_fibonacci.cpp
  - icon: ':heavy_check_mark:'
    path: convolution/NumberTheoreticTransform.hpp
    title: Number Theoretic Transform
  - icon: ':heavy_check_mark:'
    path: convolution/ArbitaryModConvolution.hpp
    title: "Arbirary Mod Convolution (\u4EFB\u610Fmod\u7573\u307F\u8FBC\u307F)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1068.test.cpp
    title: test/yukicoder/1068.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1050.test.cpp
    title: test/yukicoder/1050.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/665.test.cpp
    title: test/yukicoder/665.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/convolution_mod.test.cpp
    title: test/yosupo/convolution_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/convolution_mod_1000000007.test.cpp
    title: test/yosupo/convolution_mod_1000000007.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/queue_operate_all_composite.test.cpp
    title: test/yosupo/queue_operate_all_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/range_affine_range_sum.test.cpp
    title: test/yosupo/range_affine_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/point_set_range_composite.test.cpp
    title: test/yosupo/point_set_range_composite.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: modint
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 70, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 310, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ modulo/modint.hpp: line 5: #pragma once found in a non-first line\n"
  code: "/**\n * @brief modint\n */\n\n#pragma once\n\n#include \"../base.hpp\"\n\n\
    template<uint_fast64_t Modulus> class modint{\n    using u64=uint_fast64_t;\n\
    public:\n    u64 a;\n    constexpr modint(const u64 x=0) noexcept:a(x%Modulus){}\n\
    \    constexpr u64 &value() noexcept{return a;}\n    constexpr const u64 &value()\
    \ const noexcept{return a;}\n    constexpr modint &operator+=(const modint &rhs)\
    \ noexcept{\n        a+=rhs.a;\n        if (a>=Modulus) a-=Modulus;\n        return\
    \ *this;\n    }\n    constexpr modint operator+(const modint &rhs) const noexcept{\n\
    \        return modint(*this)+=rhs;\n    }\n    constexpr modint &operator++()\
    \ noexcept{\n        return ++a,*this;\n    }\n    constexpr modint operator++(int)\
    \ noexcept{\n        modint t=*this; return ++a,t;\n    }\n    constexpr modint\
    \ &operator-=(const modint &rhs) noexcept{\n        if (a<rhs.a) a+=Modulus;\n\
    \        a-=rhs.a;\n        return *this;\n    }\n    constexpr modint operator-(const\
    \ modint &rhs) const noexcept{\n        return modint(*this)-=rhs;\n    }\n  \
    \  constexpr modint &operator--() noexcept{\n        return --a,*this;\n    }\n\
    \    constexpr modint operator--(int) noexcept{\n        modint t=*this; return\
    \ --a,t;\n    }\n    constexpr modint &operator*=(const modint &rhs) noexcept{\n\
    \        a=a*rhs.a%Modulus;\n        return *this;\n    }\n    constexpr modint\
    \ operator*(const modint &rhs) const noexcept{\n        return modint(*this)*=rhs;\n\
    \    }\n    constexpr modint &operator/=(modint rhs) noexcept{\n        u64 exp=Modulus-2;\n\
    \        while(exp){\n            if (exp&1) *this*=rhs;\n            rhs*=rhs;\
    \ exp>>=1;\n        }\n        return *this;\n    }\n    constexpr modint operator/(const\
    \ modint &rhs) const noexcept{\n        return modint(*this)/=rhs;\n    }\n  \
    \  constexpr modint operator-() const noexcept{\n        return modint(Modulus-a);\n\
    \    }\n    constexpr bool operator==(const modint &rhs) const noexcept{\n   \
    \     return a==rhs.a;\n    }\n    constexpr bool operator!=(const modint &rhs)\
    \ const noexcept{\n        return a!=rhs.a;\n    }\n    constexpr bool operator!()\
    \ const noexcept{return !a;}\n    friend constexpr modint pow(modint rhs,long\
    \ long exp) noexcept{\n        modint res{1};\n        while(exp){\n         \
    \   if (exp&1) res*=rhs;\n            rhs*=rhs; exp>>=1;\n        }\n        return\
    \ res;\n    }\n    template<class T> friend constexpr modint operator+(T x,modint\
    \ y) noexcept{\n        return modint(x)+y;\n    }\n    template<class T> friend\
    \ constexpr modint operator-(T x,modint y) noexcept{\n        return modint(x)-y;\n\
    \    }\n    template<class T> friend constexpr modint operator*(T x,modint y)\
    \ noexcept{\n        return modint(x)*y;\n    }\n    template<class T> friend\
    \ constexpr modint operator/(T x,modint y) noexcept{\n        return modint(x)/y;\n\
    \    }\n    friend ostream &operator<<(ostream &s,const modint &rhs) noexcept{\n\
    \        return s << rhs.a;\n    }\n    friend istream &operator>>(istream &s,modint\
    \ &rhs) noexcept{\n        u64 a; rhs=modint{(s >> a,a)}; return s;\n    }\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: modulo/modint.hpp
  requiredBy:
  - test/atcoder/tdpc_fibonacci.cpp
  - convolution/NumberTheoreticTransform.hpp
  - convolution/ArbitaryModConvolution.hpp
  timestamp: '2020-09-10 10:17:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1068.test.cpp
  - test/yukicoder/1050.test.cpp
  - test/yukicoder/665.test.cpp
  - test/yosupo/convolution_mod.test.cpp
  - test/yosupo/convolution_mod_1000000007.test.cpp
  - test/yosupo/queue_operate_all_composite.test.cpp
  - test/yosupo/range_affine_range_sum.test.cpp
  - test/yosupo/point_set_range_composite.test.cpp
documentation_of: modulo/modint.hpp
layout: document
redirect_from:
- /library/modulo/modint.hpp
- /library/modulo/modint.hpp.html
title: modint
---
