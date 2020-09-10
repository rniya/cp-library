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


# :warning: Number Theoretic Transform <small>(convolution/NumberTheoreticTransform.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#a9595c1c24c33b16056d2ad07e71682d">convolution</a>
* <a href="{{ site.github.repository_url }}/blob/master/convolution/NumberTheoreticTransform.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-10 10:17:21+09:00




## 概要

## 計算量

## Depends on

* :heavy_check_mark: <a href="../base.hpp.html">base.hpp</a>
* :warning: <a href="../modulo/modint.hpp.html">modint <small>(modulo/modint.hpp)</small></a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @brief Number Theoretic Transform
 * @docs docs/convolution/NumberTheoreticTransform.md
 */

#pragma once

#include "../base.hpp"
#include "../modulo/modint.hpp"

template<int mod>
struct NumberTheoreticTransform{
    using Mint=modint<mod>;
    vector<Mint> roots;
    vector<int> rev;
    int base,max_base;
    Mint root;
    NumberTheoreticTransform():base(1),rev{0,1},roots{Mint(0),Mint(1)}{
        int tmp=mod-1;
        for (max_base=0;tmp%2==0;++max_base) tmp>>=1;
        root=2;
        while(pow(root,(mod-1)>>1)==1) ++root;
        root=pow(root,(mod-1)>>max_base);
    }
    void ensure_base(int nbase){
        if (nbase<=base) return;
        rev.resize(1<<nbase);
        for (int i=0;i<(1<<nbase);++i){
            rev[i]=(rev[i>>1]>>1)|((i&1)<<(nbase-1));
        }
        roots.resize(1<<nbase);
        for (;base<nbase;++base){
            Mint z=pow(root,1<<(max_base-1-base));
            for (int i=1<<(base-1);i<(1<<base);++i){
                roots[i<<1]=roots[i];
                roots[i<<1|1]=roots[i]*z;
            }
        }
    }
    void ntt(vector<Mint> &a){
        const int n=a.size();
        int zeros=__builtin_ctz(n);
        ensure_base(zeros);
        int shift=base-zeros;
        for (int i=0;i<n;++i){
            if (i<(rev[i]>>shift)){
                swap(a[i],a[rev[i]>>shift]);
            }
        }
        for (int k=1;k<n;k<<=1){
            for (int i=0;i<n;i+=(k<<1)){
                for (int j=0;j<k;++j){
                    Mint z=a[i+j+k]*roots[j+k];
                    a[i+j+k]=a[i+j]-z;
                    a[i+j]=a[i+j]+z;
                }
            }
        }
    }
    vector<Mint> multiply(vector<Mint> a,vector<Mint> b){
        int need=a.size()+b.size()-1;
        int nbase=1;
        while((1<<nbase)<need) ++nbase;
        ensure_base(nbase);
        int sz=1<<nbase;
        a.resize(sz,Mint(0)); b.resize(sz,Mint(0));
        ntt(a); ntt(b);
        Mint inv_sz=1/Mint(sz);
        for (int i=0;i<sz;++i) a[i]*=b[i]*inv_sz;
        reverse(a.begin()+1,a.end());
        ntt(a);
        a.resize(need);
        return a;
    }
    vector<int> multiply(vector<int> a,vector<int> b){
        vector<Mint> A(a.size()),B(b.size());
        for (int i=0;i<a.size();++i) A[i]=Mint(a[i]);
        for (int i=0;i<b.size();++i) B[i]=Mint(b[i]);
        vector<Mint> C=multiply(A,B);
        vector<int> res(C.size());
        for (int i=0;i<C.size();++i) res[i]=C[i].a;
        return res;
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
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: convolution/NumberTheoreticTransform.hpp: line 6: #pragma once found in a non-first line

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

