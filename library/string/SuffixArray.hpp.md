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


# :heavy_check_mark: Suffix Array <small>(string/SuffixArray.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#b45cffe084dd3d20d928bee85e7b0f21">string</a>
* <a href="{{ site.github.repository_url }}/blob/master/string/SuffixArray.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-13 14:01:02+09:00




## Depends on

* :question: <a href="../base.hpp.html">base.hpp</a>


## Required by

* :heavy_check_mark: <a href="LongestCommonPrefixArray.hpp.html">Longest Common Prefix Array <small>(string/LongestCommonPrefixArray.hpp)</small></a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/ALDS1_14_D.test.cpp.html">test/aoj/ALDS1_14_D.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/number_of_substrings.test.cpp.html">test/yosupo/number_of_substrings.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/suffixarray.test.cpp.html">test/yosupo/suffixarray.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @brief Suffix Array
 * @docs docs/string/SuffixArray.hpp
 */

#pragma once

#include "../base.hpp"

struct SuffixArray{
    string s;
    vector<int> SA;
    SuffixArray(const string &S):s(S){
        int n=s.size();
        s.push_back('$');
        SA.resize(n+1);
        iota(SA.begin(),SA.end(),0);
        sort(SA.begin(),SA.end(),[&](int a,int b){
            return s[a]==s[b]?a>b:s[a]<s[b];
        });
        vector<int> c(s.begin(),s.end()),cnt(n+1),nxt(n+1);
        for (int j=1;j<=n;j<<=1){
            for (int i=0;i<=n;++i){
                nxt[SA[i]]=((i&&c[SA[i-1]]==c[SA[i]]&&SA[i-1]+j<n&&c[SA[i-1]+j/2]==c[SA[i]+j/2])?nxt[SA[i-1]]:i);
            }
            iota(cnt.begin(),cnt.end(),0);
            copy(SA.begin(),SA.end(),c.begin());
            for (int i=0;i<=n;++i){
                if (c[i]-j>=0){
                    SA[cnt[nxt[c[i]-j]]++]=c[i]-j;
                }
            }
            nxt.swap(c);
        }
    }
    bool comp(const string &t,int si=0,int ti=0){
        int sn=s.size(),tn=t.size();
        for (;si<sn&&ti<tn;++si,++ti){
            if (s[si]<t[ti]) return true;
            if (s[si]>t[ti]) return false;
        }
        return si>=sn&&ti<tn;
    }
    int lower_bound(const string &t){
        int lb=-1,ub=SA.size();
        while(ub-lb>1){
            int mid=(ub+lb)>>1;
            (comp(t,SA[mid])?lb:ub)=mid;
        }
        return ub;
    }
    pair<int,int> lower_upper_bound(string &t){
        int l=lower_bound(t);
        int lb=l-1,ub=SA.size();
        ++t.back();
        while(ub-lb>1){
            int mid=(ub+lb)>>1;
            (comp(t,SA[mid])?lb:ub)=mid;
        }
        --t.back();
        return {l,ub};
    }
    int count(string &t){
        pair<int,int> p=lower_upper_bound(t);
        return p.second-p.first;
    }
    int operator[](int i) const {return SA[i];}
    int size() const {return s.size();}
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
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: string/SuffixArray.hpp: line 6: #pragma once found in a non-first line

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

