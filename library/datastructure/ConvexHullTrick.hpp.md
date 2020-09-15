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


# :heavy_check_mark: Convex Hull Trick <small>(datastructure/ConvexHullTrick.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#8dc87745f885a4cc532acd7b15b8b5fe">datastructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/datastructure/ConvexHullTrick.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-13 02:18:42+09:00




## 概要

## 計算量

## Depends on

* :question: <a href="../base.hpp.html">base.hpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/yukicoder/952.test.cpp.html">test/yukicoder/952.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @brief Convex Hull Trick
 * @docs docs/datastructure/ConvexHullTrick.md
 */

#pragma once

#include "../base.hpp"

template<typename T,bool isMin=true>
struct ConvexHullTrick{
    struct Line{
        T a,b;
        Line(T a,T b):a(a),b(b){}
    };
    deque<Line> Lines;
    bool empty() const {return Lines.empty();}
    inline int sgn(T a){return a==0?0:(a<0?-1:1);}
    inline bool check(const Line &a,const Line &b,const Line &c){
        if (b.b==a.b||c.b==b.b) return sgn(b.a-a.a)*sgn(c.b-b.b)>=sgn(c.a-b.a)*sgn(b.b-a.b);
        return (long double)(b.a-a.a)*sgn(c.b-b.b)/(long double)abs(b.b-a.b)>=(long double)(c.a-b.a)*sgn(b.b-a.b)/(long double)abs(c.b-b.b);
    }
    void add(T a,T b){
        if (!isMin) a*=-1,b*=-1;
        Line l(a,b);
        if (empty()){
            Lines.emplace_back(l);
            return;
        }
        if (Lines.front().a<=a){
            if (Lines.front().a==a){
                if (Lines.front().b<=b) return;
                Lines.pop_front();
            }
            while(Lines.size()>=2&&check(l,Lines.front(),Lines[1])) Lines.pop_front();
            Lines.emplace_front(l);
        } else {
            if (Lines.back().a==a){
                if (Lines.back().b<=b) return;
                Lines.pop_back();
            }
            while(Lines.size()>=2&&check(Lines[Lines.size()-2],Lines.back(),l)) Lines.pop_back();
            Lines.emplace_back(l);
        }
    }
    inline T f(const Line &l,const T &x){
        return l.a*x+l.b;
    }
    T query(T x){
        int lb=-1,ub=Lines.size()-1;
        while(ub-lb>1){
            int mid=(ub+lb)>>1;
            (f(Lines[mid],x)>=f(Lines[mid+1],x)?lb:ub)=mid;
        }
        return (isMin?f(Lines[ub],x):-f(Lines[ub],x));
    }
    T query_monotone_inc(T x){
        while(Lines.size()>=2&&f(Lines.front(),x)>=f(Lines[1],x)) Lines.pop_front();
        return (isMin?f(Lines.front(),x):-f(Lines.front(),x));
    }
    T query_monotone_dec(T x){
        while(Lines.size()>=2&&f(Lines.back(),x)>=f(Lines[Lines.size()-2],x)) Lines.pop_back();
        return (isMin?f(Lines.back(),x):-f(Lines.back(),x));
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
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: datastructure/ConvexHullTrick.hpp: line 6: #pragma once found in a non-first line

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

