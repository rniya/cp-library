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


# :warning: Convex Hull Trick <small>(datastructure/ConvexHullTrick.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#8dc87745f885a4cc532acd7b15b8b5fe">datastructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/datastructure/ConvexHullTrick.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-09 23:15:02+09:00




## 概要

## 計算量

## Depends on

* :question: <a href="../base.hpp.html">base.hpp</a>


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

template<typename T,bool Mono>
struct ConvexHullTrick{
    typedef function<bool(T,T)> C;
    #define F first
    #define S second
    using Line=pair<T,T>;
    C cmp;
    deque<Line> Lines;
    ConvexHullTrick(C cmp=[](T l,T r){return l>=r;})
        :cmp(cmp){}
    bool check(Line l1,Line l2,Line l3){
        if (l1<l3) swap(l1,l3);
        return (l3.S-l2.S)*(l2.F-l1.F)>=(l2.S-l1.S)*(l3.F-l2.F);
    }
    void add(T a,T b){
        Line line(a,b);
        while(Lines.size()>=2&&check(*(Lines.end()-2)
        ,Lines.back(),line)) Lines.pop_back();
        Lines.emplace_back(line);
    }
    T f(const int &i,const T &x){
        return Lines[i].F*x+Lines[i].S;
    }
    T f(const Line &line,const T &x){
        return line.F*x+line.S;
    }
    T query(T x){
        if (Mono){
            while(Lines.size()>=2
            &&cmp(f(0,x),f(1,x))) Lines.pop_front();
            return f(0,x);
        } else {
            int lb=-1,ub=Lines.size()-1;
            while(ub-lb>1){
                int mid=(lb+ub)>>1;
                (cmp(f(mid,x),f(mid+1,x))?lb:ub)=mid;
            }
            return f(ub,x);
        }
    }
    #undef F
    #undef S
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

