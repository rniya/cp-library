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


# :warning: Kitamasa <small>(linearalgebra/Kitamasa.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#1bbf1d9f5340fa94bf2c5fb5ce73a5f5">linearalgebra</a>
* <a href="{{ site.github.repository_url }}/blob/master/linearalgebra/Kitamasa.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-11 16:00:32+09:00




## 概要

## 計算量

## Depends on

* :heavy_check_mark: <a href="../base.hpp.html">base.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @brief Kitamasa
 * @docs docs/linearalgebra/Kitamasa.md
 */

#pragma once

#include "../base.hpp"

template<typename K>
struct Kitamasa{
    int k;
    vector<K> cs;
    vector<vector<K>> pcs;
    Kitamasa(const vector<K> &C):cs(C),pcs(1),k(C.size()){
        pcs[0].assign(2*k+1,K(0));
        pcs[0][1]=K(1);
    }
    vector<K> merge(const vector<K> &xs,const vector<K> &ys){
        vector<K> zs(2*k+1,K(0));
        for (int i=1;i<=k;++i)
            for (int j=1;j<=k;++j)
                zs[i+j]+=xs[i]*ys[j];
        for (int i=2*k;i>k;zs[i--]=K(0))
            for (int j=1;j<=k;++j)
                zs[i-j]+=cs[k-j]*zs[i];
        return zs;
    }
    //Be careful n is 0-indexed
    K calc(const vector<K> &A,long long n){
        vector<K> res(pcs[0]);
        for (int i=0;n;++i,n>>=1){
            if ((int)pcs.size()<=i)
                pcs.emplace_back(merge(pcs[i-1],pcs[i-1]));
            if (~n&1) continue;
            res=merge(res,pcs[i]);
        }
        K ans=K(0);
        for (int i=1;i<=k;++i) ans+=res[i]*A[i-1];
        return ans;
    }
};
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
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: linearalgebra/Kitamasa.hpp: line 6: #pragma once found in a non-first line

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

