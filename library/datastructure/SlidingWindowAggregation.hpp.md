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


# :warning: Sliding Window Aggregation (SWAG) <small>(datastructure/SlidingWindowAggregation.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#8dc87745f885a4cc532acd7b15b8b5fe">datastructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/datastructure/SlidingWindowAggregation.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-09 22:12:38+09:00




## 概要

## 計算量

## Depends on

* :heavy_check_mark: <a href="../base.hpp.html">base.hpp</a>


## Required by

* :warning: <a href="../test/aoj/DSL_3_D.SlidingWindowAggregation.cpp.html">test/aoj/DSL_3_D.SlidingWindowAggregation.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @brief Sliding Window Aggregation (SWAG)
 * @docs docs/datastructure/SlidingWindowAggregation.md
 */

#pragma once

#include "../base.hpp"

template<typename Monoid>
struct SlidingWindowAggregation{
    typedef function<Monoid(Monoid,Monoid)> F;
    stack<pair<Monoid,Monoid>> front_stack,back_stack;
    F f;
    Monoid id;
    SlidingWindowAggregation(F f,Monoid id):
        f(f),id(id),front_stack(),back_stack(){
        front_stack.emplace(id,id);
        back_stack.emplace(id,id);
    }
    void push(const Monoid &x){
        back_stack.emplace(x,f(back_stack.top().second,x));
    }
    void pop(){
        if (front_stack.size()==1){
            while(1<back_stack.size()){
                Monoid t=back_stack.top().first;
                Monoid calc=f(t,front_stack.top().second);
                front_stack.emplace(t,calc);
                back_stack.pop();
            }
        }
        front_stack.pop();
    }
    Monoid fold(){
        return f(front_stack.top().second,back_stack.top().second);
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
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: datastructure/SlidingWindowAggregation.hpp: line 6: #pragma once found in a non-first line

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

