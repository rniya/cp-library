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


# :warning: Project Selection Problem <small>(flow/ProjectSelectionProblem.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#cff5497121104c2b8e0cb41ed2083a9b">flow</a>
* <a href="{{ site.github.repository_url }}/blob/master/flow/ProjectSelectionProblem.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-11 18:26:48+09:00




## 概要

## 計算量

## Depends on

* :heavy_check_mark: <a href="../base.hpp.html">base.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @brief Project Selection Problem
 * @docs docs/flow/ProjectSelectionProblem.md
 */

#pragma once

#include "../base.hpp"

template<typename T>
struct ProjectSelectionProblem{
    int s,t;
    T sum=0;
    const T inf=numeric_limits<T>::max()/2;
    Dinic<T,true> D;
    ProjectSelectionProblem(int n):s(n),t(n+1),D(n+2){}
    void x_false_loss(int x,T z){
        D.add_edge(x,t,z);
    }
    void x_false_profit(int x,T z){
        sum+=z;
        x_true_loss(x,z);
    }
    void x_true_loss(int x,T z){
        D.add_edge(s,x,z);
    }
    void x_true_profit(int x,T z){
        sum+=z;
        x_false_loss(x,z);
    }
    void x_false_y_true_loss(int x,int y,T z){
        D.add_edge(x,y,z);
    }
    void x_true_y_false_loss(int x,int y,T z){
        D.add_edge(y,x,z);
    }
    void x_true_y_true_profit(int x,int y,T z){
        sum+=z;
        int w=D.add_vertex();
        x_false_loss(w,z);
        x_true_y_false_loss(w,x,inf);
        x_true_y_false_loss(w,y,inf);
    }
    void x_false_y_false_profit(int x,int y,T z){
        sum+=z;
        int w=D.add_vertex();
        x_true_loss(w,z);
        x_false_y_true_loss(w,x,inf);
        x_false_y_true_loss(w,y,inf);
    }
    T build(){
        return D.max_flow(s,t)-sum;
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
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: flow/ProjectSelectionProblem.hpp: line 6: #pragma once found in a non-first line

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

