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


# :heavy_check_mark: Longest Common Prefix Array <small>(string/LongestCommonPrefixArray.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#b45cffe084dd3d20d928bee85e7b0f21">string</a>
* <a href="{{ site.github.repository_url }}/blob/master/string/LongestCommonPrefixArray.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-13 14:01:02+09:00




## Depends on

* :heavy_check_mark: <a href="../base.hpp.html">base.hpp</a>
* :heavy_check_mark: <a href="SuffixArray.hpp.html">Suffix Array <small>(string/SuffixArray.hpp)</small></a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/yosupo/number_of_substrings.test.cpp.html">test/yosupo/number_of_substrings.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @brief Longest Common Prefix Array
 * @docs docs/string/LongestCommonPrefixArray.md
 */

#include "../base.hpp"
#include "../string/SuffixArray.hpp"

struct LongestCommonPrefixArray{
    SuffixArray SA;
    vector<int> LCP,rank,lookup;
    vector<vector<int>> dat;
    LongestCommonPrefixArray(const string &s):SA(s){
        int n=s.size();
        LCP.resize(n); rank.resize(n+1);
        for (int i=0;i<=n;++i) rank[SA[i]]=i;
        LCP[0]=0;
        for (int i=0,t=0;i<n;++i){
            if (t) --t;
            for (int j=SA[rank[i]-1];max(i,j)+t<n&&s[i+t]==s[j+t];++t);
            LCP[rank[i]-1]=t;
        }
        int h=1;
        while((1<<h)<=n) ++h;
        dat.assign(h,vector<int>(n));
        lookup.assign(n+1,0);
        for (int i=2;i<=n;++i) lookup[i]=lookup[i>>1]+1;
        for (int j=0;j<n;++j) dat[0][j]=LCP[j];
        for (int i=1,mask=1;i<h;++i,mask<<=1){
            for (int j=0;j<n;++j){
                dat[i][j]=min(dat[i-1][j],dat[i-1][min(j+mask,n-1)]);
            }
        }
    }
    int query(int a,int b){
        if (a>b) swap(a,b);
        int d=lookup[b-a];
        return min(dat[d][a],dat[d][b-(1<<d)]);
    }
    // longest common prefix of s[a...] and s[b...]
    int lcp(int a,int b){
        return query(rank[a],rank[b]);
    }
    int operator[](int i) const {return LCP[i];}
    int size() const {return LCP.size();}
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
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 399, in update
    self.update(self._resolve(pathlib.Path(included), included_from=path))
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 310, in update
    raise BundleErrorAt(path, i + 1, "#pragma once found in a non-first line")
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: string/SuffixArray.hpp: line 6: #pragma once found in a non-first line

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

