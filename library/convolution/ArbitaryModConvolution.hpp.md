---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :heavy_check_mark: Arbirary Mod Convolution (任意mod畳み込み) <small>(convolution/ArbitaryModConvolution.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#a9595c1c24c33b16056d2ad07e71682d">convolution</a>
* <a href="{{ site.github.repository_url }}/blob/master/convolution/ArbitaryModConvolution.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-13 15:43:48+09:00




## 概要

## 計算量

## Depends on

* :heavy_check_mark: <a href="../base.hpp.html">base.hpp</a>
* :heavy_check_mark: <a href="NumberTheoreticTransform.hpp.html">Number Theoretic Transform <small>(convolution/NumberTheoreticTransform.hpp)</small></a>
* :heavy_check_mark: <a href="../modulo/modint.hpp.html">modint <small>(modulo/modint.hpp)</small></a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/yosupo/convolution_mod_1000000007.test.cpp.html">test/yosupo/convolution_mod_1000000007.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @brief Arbirary Mod Convolution (任意mod畳み込み)
 * @docs docs/convolution/ArbitaryModConvolution.md
 */

#pragma once

#include "../base.hpp"
#include "../modulo/modint.hpp"
#include "../convolution/NumberTheoreticTransform.hpp"

template<typename M>
vector<M> ArbitaryModConvolution(const vector<M> &a,const vector<M> &b){
    int n=a.size(),m=b.size();
    static constexpr int mod0=167772161,mod1=469762049,mod2=1224736769;
    using mint0=modint<mod0>;
    using mint1=modint<mod1>;
    using mint2=modint<mod2>;
    NumberTheoreticTransform<mod0> ntt0;
    NumberTheoreticTransform<mod1> ntt1;
    NumberTheoreticTransform<mod2> ntt2;
    vector<mint0> a0(n),b0(m);
    vector<mint1> a1(n),b1(m);
    vector<mint2> a2(n),b2(m);
    for (int i=0;i<n;++i) a0[i]=a[i].a,a1[i]=a[i].a,a2[i]=a[i].a;
    for (int i=0;i<m;++i) b0[i]=b[i].a,b1[i]=b[i].a,b2[i]=b[i].a;
    auto c0=ntt0.multiply(a0,b0);
    auto c1=ntt1.multiply(a1,b1);
    auto c2=ntt2.multiply(a2,b2);
    static const mint1 inv0=(mint1)1/mod0;
    static const mint2 inv1=(mint2)1/mod1,inv0inv1=inv1/mod0;
    static const M m0=mod0,m0m1=m0*mod1;
    vector<M> res(n+m-1);
    for (int i=0;i<n+m-1;++i){
        int v0=c0[i].a;
        int v1=(inv0*(c1[i]-v0)).a;
        int v2=(inv0inv1*(c2[i]-v0)-inv1*v1).a;
        res[i]=v0+m0*v1+m0m1*v2;
    }
    return res;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 349, in write_contents
    bundled_code = language.bundle(self.file_class.file_path, basedir=pathlib.Path.cwd())
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py", line 185, in bundle
    bundler.update(path)
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 310, in update
    raise BundleErrorAt(path, i + 1, "#pragma once found in a non-first line")
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: convolution/ArbitaryModConvolution.hpp: line 6: #pragma once found in a non-first line

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

