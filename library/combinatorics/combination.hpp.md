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


# :warning: combination <small>(combinatorics/combination.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#ac1ed416572b96a9f5d69740d174ef3d">combinatorics</a>
* <a href="{{ site.github.repository_url }}/blob/master/combinatorics/combination.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-10 15:03:02+09:00




## Depends on

* :question: <a href="../base.hpp.html">base.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @brief combination
 * @docs @docs/combinatorics/combination.md
 */

#pragma once

#include "../base.hpp"

template<class M>
struct Combination{
    vector<M> _fac,_inv,_finv;
    Combination(int n):_fac(n+1),_inv(n+1),_finv(n+1){
        _fac[0]=_finv[n]=_inv[0]=1;
        for (int i=1;i<=n;++i) _fac[i]=_fac[i-1]*i;
        _finv[n]/=_fac[n];
        for (int i=n-1;i>=0;--i) _finv[i]=_finv[i+1]*(i+1);
        for (int i=1;i<=n;++i) _inv[i]=_finv[i]*_finv[i-1];
    }
    M fac(int k) const {return _fac[k];}
    M finv(int k) const {return _finv[k];}
    M inv(int k) const {return _inv[k];}
    M P(int n,int r) const {
        if (n<0||r<0||n<r) return 0;
        return _fac[n]*_finv[n-r];
    }
    M C(int n,int r) const {
        if (n<0||r<0||n<r) return 0;
        return _fac[n]*_finv[r]*_finv[n-r];
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
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: combinatorics/combination.hpp: line 6: #pragma once found in a non-first line

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

