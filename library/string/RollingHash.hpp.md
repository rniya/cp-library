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


# :heavy_check_mark: Rolling Hash <small>(string/RollingHash.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#b45cffe084dd3d20d928bee85e7b0f21">string</a>
* <a href="{{ site.github.repository_url }}/blob/master/string/RollingHash.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-11 16:00:32+09:00




## 概要

## 計算量

## Depends on

* :heavy_check_mark: <a href="../base.hpp.html">base.hpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/ALDS1_14_B.test.cpp.html">test/aoj/ALDS1_14_B.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @brief Rolling Hash
 * @docs docs/string/RollingHash.md
 */

#pragma once

#include "../base.hpp"

struct RollingHash{
    static const int B1=1007,B2=2009;
    static const int mod1=1000000007,mod2=1000000009;
    vector<long long> hash1,hash2,po1,po2;
    RollingHash(const vector<long long> &vs){init(vs);}
    RollingHash(const string &S){
        vector<long long> vs;
        for (char c:S) vs.emplace_back(c);
        init(vs);
    }
    void init(vector<long long> vs){
        int n=vs.size();
        hash1.assign(n+1,0);
        hash2.assign(n+1,0);
        po1.assign(n+1,1);
        po2.assign(n+1,1);
        for (int i=0;i<n;++i){
            hash1[i+1]=(hash1[i]*B1+vs[i])%mod1;
            hash2[i+1]=(hash2[i]*B2+vs[i])%mod2;
            po1[i+1]=po1[i]*B1%mod1;
            po2[i+1]=po2[i]*B2%mod2;
        }
    }
    inline pair<long long,long long> get(int l,int r) const {
        long long res1=hash1[r]+mod1-hash1[l]*po1[r-l]%mod1
                ,res2=hash2[r]+mod2-hash2[l]*po2[r-l]%mod2;
        return {res1>=mod1?res1-mod1:res1,res2>=mod2?res2-mod2:res2};
    }
    inline int lcp(int a,int b) const {
        int len=min((int)hash1.size()-a,(int)hash1.size()-b);
        int lb=0,ub=len;
        while(ub-lb>1){
            int mid=(lb+ub)>>1;
            (get(a,a+mid)==get(b,b+mid)?lb:ub)=mid;
        }
        return lb;
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
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: string/RollingHash.hpp: line 6: #pragma once found in a non-first line

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

