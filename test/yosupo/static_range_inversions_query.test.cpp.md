---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  - icon: ':question:'
    path: datastructure/BinaryIndexedTree.hpp
    title: Binary Indexed Tree
  - icon: ':x:'
    path: other/Mo.hpp
    title: Mo's Algorithm
  - icon: ':x:'
    path: util/compress.hpp
    title: compress
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_inversions_query
    links:
    - https://judge.yosupo.jp/problem/static_range_inversions_query
  bundledCode: "#line 1 \"test/yosupo/static_range_inversions_query.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/static_range_inversions_query\"\n\n\
    #line 2 \"base.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\nconst long\
    \ long MOD = 1000000007;\n// const long long MOD=998244353;\nconst int INF = 1e9;\n\
    const long long IINF = 1e18;\nconst int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1,\
    \ 0, -1};\nconst char dir[4] = {'D', 'R', 'U', 'L'};\n#define LOCAL\ntypedef long\
    \ long ll;\ntypedef __int128_t i128;\ntypedef unsigned int uint;\ntypedef unsigned\
    \ long long ull;\n#define ALL(x) (x).begin(), (x).end()\n\ntemplate <typename\
    \ T> istream& operator>>(istream& is, vector<T>& v) {\n    for (T& x : v) is >>\
    \ x;\n    return is;\n}\ntemplate <typename T> ostream& operator<<(ostream& os,\
    \ const vector<T>& v) {\n    for (int i = 0; i < v.size(); i++) {\n        os\
    \ << v[i] << (i + 1 == v.size() ? \"\" : \" \");\n    }\n    return os;\n}\ntemplate\
    \ <typename T, typename U> ostream& operator<<(ostream& os, const pair<T, U>&\
    \ p) {\n    os << '(' << p.first << ',' << p.second << ')';\n    return os;\n\
    }\ntemplate <typename T, typename U, typename V> ostream& operator<<(ostream&\
    \ os, const tuple<T, U, V>& t) {\n    os << '(' << get<0>(t) << ',' << get<1>(t)\
    \ << ',' << get<2>(t) << ')';\n    return os;\n}\ntemplate <typename T, typename\
    \ U, typename V, typename W> ostream& operator<<(ostream& os, const tuple<T, U,\
    \ V, W>& t) {\n    os << '(' << get<0>(t) << ',' << get<1>(t) << ',' << get<2>(t)\
    \ << ',' << get<3>(t) << ')';\n    return os;\n}\ntemplate <typename T, typename\
    \ U> ostream& operator<<(ostream& os, const map<T, U>& m) {\n    os << '{';\n\
    \    for (auto itr = m.begin(); itr != m.end();) {\n        os << '(' << itr->first\
    \ << ',' << itr->second << ')';\n        if (++itr != m.end()) os << ',';\n  \
    \  }\n    os << '}';\n    return os;\n}\ntemplate <typename T, typename U> ostream&\
    \ operator<<(ostream& os, const unordered_map<T, U>& m) {\n    os << '{';\n  \
    \  for (auto itr = m.begin(); itr != m.end();) {\n        os << '(' << itr->first\
    \ << ',' << itr->second << ')';\n        if (++itr != m.end()) os << ',';\n  \
    \  }\n    os << '}';\n    return os;\n}\ntemplate <typename T> ostream& operator<<(ostream&\
    \ os, const set<T>& s) {\n    os << '{';\n    for (auto itr = s.begin(); itr !=\
    \ s.end();) {\n        os << *itr;\n        if (++itr != s.end()) os << ',';\n\
    \    }\n    os << '}';\n    return os;\n}\ntemplate <typename T> ostream& operator<<(ostream&\
    \ os, const multiset<T>& s) {\n    os << '{';\n    for (auto itr = s.begin();\
    \ itr != s.end();) {\n        os << *itr;\n        if (++itr != s.end()) os <<\
    \ ',';\n    }\n    os << '}';\n    return os;\n}\ntemplate <typename T> ostream&\
    \ operator<<(ostream& os, const unordered_set<T>& s) {\n    os << '{';\n    for\
    \ (auto itr = s.begin(); itr != s.end();) {\n        os << *itr;\n        if (++itr\
    \ != s.end()) os << ',';\n    }\n    os << '}';\n    return os;\n}\ntemplate <typename\
    \ T> ostream& operator<<(ostream& os, const deque<T>& v) {\n    for (int i = 0;\
    \ i < v.size(); i++) {\n        os << v[i] << (i + 1 == v.size() ? \"\" : \" \"\
    );\n    }\n    return os;\n}\n\nvoid debug_out() { cerr << '\\n'; }\ntemplate\
    \ <class Head, class... Tail> void debug_out(Head&& head, Tail&&... tail) {\n\
    \    cerr << head;\n    if (sizeof...(Tail) > 0) cerr << \", \";\n    debug_out(move(tail)...);\n\
    }\n#ifdef LOCAL\n#define debug(...)                                          \
    \                         \\\n    cerr << \" \";                             \
    \                                        \\\n    cerr << #__VA_ARGS__ << \" :[\"\
    \ << __LINE__ << \":\" << __FUNCTION__ << \"]\" << '\\n'; \\\n    cerr << \" \"\
    ;                                                                     \\\n   \
    \ debug_out(__VA_ARGS__)\n#else\n#define debug(...) 42\n#endif\n\ntemplate <typename\
    \ T> T gcd(T x, T y) { return y != 0 ? gcd(y, x % y) : x; }\ntemplate <typename\
    \ T> T lcm(T x, T y) { return x / gcd(x, y) * y; }\n\ntemplate <class T1, class\
    \ T2> inline bool chmin(T1& a, T2 b) {\n    if (a > b) {\n        a = b;\n   \
    \     return true;\n    }\n    return false;\n}\ntemplate <class T1, class T2>\
    \ inline bool chmax(T1& a, T2 b) {\n    if (a < b) {\n        a = b;\n       \
    \ return true;\n    }\n    return false;\n}\n#line 3 \"util/compress.hpp\"\n\n\
    /**\n * @brief compress\n */\ntemplate <typename T> map<T, int> compress(vector<T>\
    \ v) {\n    sort(v.begin(), v.end());\n    v.erase(unique(v.begin(), v.end()),\
    \ v.end());\n    map<T, int> res;\n    for (int i = 0; i < v.size(); i++) res[v[i]]\
    \ = i;\n    return res;\n}\n#line 3 \"datastructure/BinaryIndexedTree.hpp\"\n\n\
    /**\n * @brief Binary Indexed Tree\n * @docs docs/datastructure/BinaryIndexedTree.md\n\
    \ */\ntemplate <typename T> class BinaryIndexedTree {\n    T sum(int i) {\n  \
    \      T res = T();\n        for (; i > 0; i -= (i & -i)) res += dat[i];\n   \
    \     return res;\n    }\n\npublic:\n    int n;\n    vector<T> dat;\n    BinaryIndexedTree(int\
    \ n_) : n(n_ + 1), dat(n + 1, 0) {}\n    void add(int i, const T& x) {\n     \
    \   for (++i; i <= n; i += (i & -i)) dat[i] += x;\n    }\n    T query(int l, int\
    \ r) { return sum(r) - sum(l); }\n    int lower_bound(T x) const {\n        if\
    \ (x <= 0) return 0;\n        int pos = 0, k = 1;\n        while (k < n) k <<=\
    \ 1;\n        for (; k > 0; k >>= 1) {\n            if (pos + k <= n && dat[pos\
    \ + k] < x) {\n                x -= dat[pos + k];\n                pos += k;\n\
    \            }\n        }\n        return pos;\n    }\n    int upper_bound(T x)\
    \ const { return lower_bound(x + 1); }\n    T operator[](int i) { return query(i,\
    \ i + 1); }\n};\n#line 3 \"other/Mo.hpp\"\n\n/**\n * @brief Mo's Algorithm\n *\
    \ @docs docs/other/Mo.md\n */\nstruct Mo {\n    int sz;\n    vector<int> left,\
    \ right;\n    Mo(int n) : sz((int)sqrt(n)) {}\n    void insert(int l, int r) {\n\
    \        left.emplace_back(l);\n        right.emplace_back(r);\n    }\n    template\
    \ <typename ADDL, typename ADDR, typename DELL, typename DELR, typename REM>\n\
    \    void build(const ADDL& add_left,\n               const ADDR& add_right,\n\
    \               const DELL& del_left,\n               const DELR& del_right,\n\
    \               const REM& rem) {\n        int q = left.size();\n        vector<int>\
    \ ord(q);\n        iota(ord.begin(), ord.end(), 0);\n        sort(ord.begin(),\
    \ ord.end(),\n             [&](int a, int b) { return (left[a] / sz != left[b]\
    \ / sz ? left[a] < left[b] : right[a] < right[b]); });\n        int l = 0, r =\
    \ 0;\n        for (int idx : ord) {\n            while (l > left[idx]) add_left(--l);\n\
    \            while (r < right[idx]) add_right(r++);\n            while (l < left[idx])\
    \ del_left(l++);\n            while (r > right[idx]) del_right(--r);\n       \
    \     rem(idx);\n        }\n    }\n    template <typename ADD, typename DEL, typename\
    \ REM> void build(const ADD& add, const DEL& del, const REM& rem) {\n        build(add,\
    \ add, del, del, rem);\n    }\n};\n#line 7 \"test/yosupo/static_range_inversions_query.test.cpp\"\
    \n\nint main(){\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    int N,Q;\
    \ cin >> N >> Q;\n    vector<int> A(N);\n    for (int i=0;i<N;++i) cin >> A[i];\n\
    \n    Mo mo(N);\n    for (int i=0;i<Q;++i){\n        int l,r; cin >> l >> r;\n\
    \        mo.insert(l,r);\n    }\n\n    map<int,int> mp=compress(A);\n    for (int\
    \ i=0;i<N;++i) A[i]=mp[A[i]];\n    int n=mp.size();\n    BinaryIndexedTree<int>\
    \ BIT(n);\n    vector<long long> ans(Q);\n    long long inv=0; int sum=0;\n  \
    \  auto add_left=[&](int idx){\n        inv+=BIT.query(0,A[idx]);\n        ++sum;\
    \ BIT.add(A[idx],1);\n    };\n    auto add_right=[&](int idx){\n        inv+=BIT.query(A[idx]+1,n);\n\
    \        ++sum; BIT.add(A[idx],1);\n    };\n    auto del_left=[&](int idx){\n\
    \        inv-=BIT.query(0,A[idx]);\n        --sum; BIT.add(A[idx],-1);\n    };\n\
    \    auto del_right=[&](int idx){\n        inv-=BIT.query(A[idx]+1,n);\n     \
    \   --sum; BIT.add(A[idx],-1);\n    };\n    auto rem=[&](int idx){\n        ans[idx]=inv;\n\
    \    };\n\n    mo.build(add_left,add_right,del_left,del_right,rem);\n\n    for\
    \ (int i=0;i<Q;++i) cout << ans[i] << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_inversions_query\"\
    \n\n#include \"../../base.hpp\"\n#include \"../../util/compress.hpp\"\n#include\
    \ \"../../datastructure/BinaryIndexedTree.hpp\"\n#include \"../../other/Mo.hpp\"\
    \n\nint main(){\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    int N,Q;\
    \ cin >> N >> Q;\n    vector<int> A(N);\n    for (int i=0;i<N;++i) cin >> A[i];\n\
    \n    Mo mo(N);\n    for (int i=0;i<Q;++i){\n        int l,r; cin >> l >> r;\n\
    \        mo.insert(l,r);\n    }\n\n    map<int,int> mp=compress(A);\n    for (int\
    \ i=0;i<N;++i) A[i]=mp[A[i]];\n    int n=mp.size();\n    BinaryIndexedTree<int>\
    \ BIT(n);\n    vector<long long> ans(Q);\n    long long inv=0; int sum=0;\n  \
    \  auto add_left=[&](int idx){\n        inv+=BIT.query(0,A[idx]);\n        ++sum;\
    \ BIT.add(A[idx],1);\n    };\n    auto add_right=[&](int idx){\n        inv+=BIT.query(A[idx]+1,n);\n\
    \        ++sum; BIT.add(A[idx],1);\n    };\n    auto del_left=[&](int idx){\n\
    \        inv-=BIT.query(0,A[idx]);\n        --sum; BIT.add(A[idx],-1);\n    };\n\
    \    auto del_right=[&](int idx){\n        inv-=BIT.query(A[idx]+1,n);\n     \
    \   --sum; BIT.add(A[idx],-1);\n    };\n    auto rem=[&](int idx){\n        ans[idx]=inv;\n\
    \    };\n\n    mo.build(add_left,add_right,del_left,del_right,rem);\n\n    for\
    \ (int i=0;i<Q;++i) cout << ans[i] << '\\n';\n}"
  dependsOn:
  - base.hpp
  - util/compress.hpp
  - datastructure/BinaryIndexedTree.hpp
  - other/Mo.hpp
  isVerificationFile: true
  path: test/yosupo/static_range_inversions_query.test.cpp
  requiredBy: []
  timestamp: '2021-01-19 14:56:35+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/static_range_inversions_query.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/static_range_inversions_query.test.cpp
- /verify/test/yosupo/static_range_inversions_query.test.cpp.html
title: test/yosupo/static_range_inversions_query.test.cpp
---