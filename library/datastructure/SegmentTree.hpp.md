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


# :heavy_check_mark: Segment Tree <small>(datastructure/SegmentTree.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#8dc87745f885a4cc532acd7b15b8b5fe">datastructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/datastructure/SegmentTree.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-09 23:15:02+09:00




## 概要

## 計算量

## Depends on

* :heavy_check_mark: <a href="../base.hpp.html">base.hpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/DSL_2_A.test.cpp.html">test/aoj/DSL_2_A.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/point_add_range_sum.test.cpp.html">test/yosupo/point_add_range_sum.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/point_set_range_composite.test.cpp.html">test/yosupo/point_set_range_composite.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/vertex_add_path_sum.test.cpp.html">test/yosupo/vertex_add_path_sum.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @brief Segment Tree
 * @docs docs/datastructure/SegmentTree.md
 */

#pragma once

#include "../base.hpp"

template<typename Monoid>
struct SegmentTree{
    typedef function<Monoid(Monoid,Monoid)> F;
    int n;
    F f;
    Monoid id;
    vector<Monoid> dat;
    SegmentTree(int n_,F f,Monoid id):f(f),id(id){init(n_);}
    void init(int n_){
        n=1;
        while(n<n_) n<<=1;
        dat.assign(n<<1,id);
    }
    void build(const vector<Monoid> &v){
        for (int i=0;i<v.size();++i) dat[i+n]=v[i];
        for (int i=n-1;i;--i) dat[i]=f(dat[i<<1|0],dat[i<<1|1]);
    }
    void update(int k,Monoid x){
        dat[k+=n]=x;
        while(k>>=1) dat[k]=f(dat[k<<1|0],dat[k<<1|1]);
    }
    Monoid query(int a,int b){
        if (a>=b) return id;
        Monoid vl=id,vr=id;
        for (int l=a+n,r=b+n;l<r;l>>=1,r>>=1){
            if (l&1) vl=f(vl,dat[l++]);
            if (r&1) vr=f(dat[--r],vr);
        }
        return f(vl,vr);
    }
    template<typename C>
    int find_subtree(int k,const C &check,Monoid &M,bool type){
        while(k<n){
            Monoid nxt=type?f(dat[k<<1|type],M):f(M,dat[k<<1|type]);
            if (check(nxt)) k=k<<1|type;
            else M=nxt,k=k<<1|(type^1);
        }
        return k-n;
    }
    // min i s.t. f(seg[a],seg[a+1],...,seg[i]) satisfy "check"
    template<typename C>
    int find_first(int a,const C &check){
        Monoid L=id;
        if (a<=0){
            if (check(f(L,dat[1]))) return find_subtree(1,check,L,false);
            return -1;
        }
        int b=n;
        for (int l=a+n,r=b+n;l<r;l>>=1,r>>=1){
            if (l&1){
                Monoid nxt=f(L,dat[l]);
                if (check(nxt)) return find_subtree(l,check,L,false);
                L=nxt; ++l;
            }
        }
        return -1;
    }
    // max i s.t. f(seg[i],...,seg[b-2],seg[b-1]) satisfy "check"
    template<typename C>
    int find_last(int b,const C &check){
        Monoid R=id;
        if (b>=n){
            if (check(f(dat[1],R))) return find_subtree(1,check,R,true);
            return -1;
        }
        int a=n;
        for (int l=a,r=b+n;l<r;l>>=1,r>>=1){
            if (r&1){
                Monoid nxt=f(dat[--r],R);
                if (check(nxt)) return find_subtree(r,check,R,true);
                R=nxt;
            }
        }
        return -1;
    }
    Monoid operator[](int i){return dat[i+n];}
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
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: datastructure/SegmentTree.hpp: line 6: #pragma once found in a non-first line

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

