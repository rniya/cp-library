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


# :heavy_check_mark: test/yosupo/queue_operate_all_composite.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0b58406058f6619a0f31a172defc0230">test/yosupo</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo/queue_operate_all_composite.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-14 16:34:26+09:00


* see: <a href="https://judge.yosupo.jp/problem/queue_operate_all_composite">https://judge.yosupo.jp/problem/queue_operate_all_composite</a>


## Depends on

* :question: <a href="../../../library/base.hpp.html">base.hpp</a>
* :heavy_check_mark: <a href="../../../library/datastructure/SlidingWindowAggregation.hpp.html">Sliding Window Aggregation (SWAG) <small>(datastructure/SlidingWindowAggregation.hpp)</small></a>
* :heavy_check_mark: <a href="../../../library/modulo/modint.hpp.html">modint <small>(modulo/modint.hpp)</small></a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/queue_operate_all_composite"

#include "../../base.hpp"
#include "../../modulo/modint.hpp"
#include "../../datastructure/SlidingWindowAggregation.hpp"

using mint=modint<998244353>;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    struct node{
        mint a,b;
        node(mint a,mint b):a(a),b(b){}
    };
    auto f=[](node a,node b){return node(a.a*b.a,a.b*b.a+b.b);};
    SlidingWindowAggregation<node> SWAG(f,node(1,0));

    int Q; cin >> Q;
    for (;Q--;){
        int t; cin >> t;
        if (t==0){
            int a,b; cin >> a >> b;
            SWAG.push(node(a,b));
        } else if (t==1){
            SWAG.pop();
        } else {
            int x; cin >> x;
            node ans=SWAG.fold();
            cout << ans.a*x+ans.b << '\n';
        }
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
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: modulo/modint.hpp: line 5: #pragma once found in a non-first line

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

