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
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :warning: test/aoj/DSL_3_D.SlidingWindowAggregation.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0d0c91c0cca30af9c1c9faef0cf04aa9">test/aoj</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/DSL_3_D.SlidingWindowAggregation.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-12 21:46:40+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_3_D">https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_3_D</a>


## Depends on

* :heavy_check_mark: <a href="../../base.hpp.html">base.hpp</a>
* :heavy_check_mark: <a href="../../datastructure/SlidingWindowAggregation.hpp.html">Sliding Window Aggregation (SWAG) <small>(datastructure/SlidingWindowAggregation.hpp)</small></a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_3_D"

#include "../../base.hpp"
#include "../../datastructure/SlidingWindowAggregation.hpp"

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,L; cin >> N >> L;
    vector<int> a(N);
    for (int i=0;i<N;++i) cin >> a[i];

    SlidingWindowAggregation<int> SWAG([](int a,int b){return min(a,b);},INT_MAX);

    for (int i=0;i<L-1;++i) SWAG.push(a[i]);
    for (int i=L-1;i<N;++i){
        SWAG.push(a[i]);
        cout << SWAG.fold() << (i+1==N?'\n':' ');
        SWAG.pop();
    }
}
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
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 399, in update
    self.update(self._resolve(pathlib.Path(included), included_from=path))
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 310, in update
    raise BundleErrorAt(path, i + 1, "#pragma once found in a non-first line")
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: datastructure/SlidingWindowAggregation.hpp: line 6: #pragma once found in a non-first line

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

