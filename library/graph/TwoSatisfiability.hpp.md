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


# :heavy_check_mark: 2-SAT <small>(graph/TwoSatisfiability.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/TwoSatisfiability.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-10 12:32:51+09:00




## Depends on

* :question: <a href="../base.hpp.html">base.hpp</a>
* :heavy_check_mark: <a href="StronglyConnectedComponents.hpp.html">Strongly Connected Components <small>(graph/StronglyConnectedComponents.hpp)</small></a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/yosupo/two_sat.test.cpp.html">test/yosupo/two_sat.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @brief 2-SAT
 * @docs docs/graph/TwoSatisfiability
 */

#pragma once

#include "../base.hpp"
#include "StronglyConnectedComponents.hpp"

struct TwoSatisfiability{
    int n;
    StronglyConnectedComponents SCC;
    TwoSatisfiability(int n):n(n),SCC(n*2){}
    int neg(int v){return (n+v)%(n*2);}
    void add_if(int u,int v){
        SCC.add_edge(u,v);
        SCC.add_edge(neg(v),neg(u));
    }
    void add_or(int u,int v){
        add_if(neg(u),v);
    }
    void add_nand(int u,int v){
        add_if(u,neg(v));
    }
    void set_true(int v){
        SCC.add_edge(neg(v),v);
    }
    void set_false(int v){
        SCC.add_edge(v,neg(v));
    }
    vector<int> build(){
        SCC.build();
        vector<int> res(n);
        for (int i=0;i<n;++i){
            if (SCC[i]==SCC[n+i]) return {};
            res[i]=SCC[i]>SCC[n+i];
        }
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
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: graph/TwoSatisfiability.hpp: line 6: #pragma once found in a non-first line

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

