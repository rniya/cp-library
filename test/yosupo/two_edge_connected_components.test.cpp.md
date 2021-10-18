---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  - icon: ':heavy_check_mark:'
    path: graph/BlockCutTree.hpp
    title: Block Cut Tree (with Lowlink, Two Edge Connected Components, Bi Connected
      Components)
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/two_edge_connected_components
    links:
    - https://judge.yosupo.jp/problem/two_edge_connected_components
  bundledCode: "#line 1 \"test/yosupo/two_edge_connected_components.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/two_edge_connected_components\"\n\n\
    #line 2 \"base.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n#pragma\
    \ region Macros\ntypedef long long ll;\ntypedef __int128_t i128;\ntypedef unsigned\
    \ int uint;\ntypedef unsigned long long ull;\n#define ALL(x) (x).begin(), (x).end()\n\
    \ntemplate <typename T> istream& operator>>(istream& is, vector<T>& v) {\n   \
    \ for (T& x : v) is >> x;\n    return is;\n}\ntemplate <typename T> ostream& operator<<(ostream&\
    \ os, const vector<T>& v) {\n    for (int i = 0; i < (int)v.size(); i++) {\n \
    \       os << v[i] << (i + 1 == (int)v.size() ? \"\" : \" \");\n    }\n    return\
    \ os;\n}\ntemplate <typename T, typename U> ostream& operator<<(ostream& os, const\
    \ pair<T, U>& p) {\n    os << '(' << p.first << ',' << p.second << ')';\n    return\
    \ os;\n}\ntemplate <typename T, typename U> ostream& operator<<(ostream& os, const\
    \ map<T, U>& m) {\n    os << '{';\n    for (auto itr = m.begin(); itr != m.end();)\
    \ {\n        os << '(' << itr->first << ',' << itr->second << ')';\n        if\
    \ (++itr != m.end()) os << ',';\n    }\n    os << '}';\n    return os;\n}\ntemplate\
    \ <typename T, typename U> ostream& operator<<(ostream& os, const unordered_map<T,\
    \ U>& m) {\n    os << '{';\n    for (auto itr = m.begin(); itr != m.end();) {\n\
    \        os << '(' << itr->first << ',' << itr->second << ')';\n        if (++itr\
    \ != m.end()) os << ',';\n    }\n    os << '}';\n    return os;\n}\ntemplate <typename\
    \ T> ostream& operator<<(ostream& os, const set<T>& s) {\n    os << '{';\n   \
    \ for (auto itr = s.begin(); itr != s.end();) {\n        os << *itr;\n       \
    \ if (++itr != s.end()) os << ',';\n    }\n    os << '}';\n    return os;\n}\n\
    template <typename T> ostream& operator<<(ostream& os, const multiset<T>& s) {\n\
    \    os << '{';\n    for (auto itr = s.begin(); itr != s.end();) {\n        os\
    \ << *itr;\n        if (++itr != s.end()) os << ',';\n    }\n    os << '}';\n\
    \    return os;\n}\ntemplate <typename T> ostream& operator<<(ostream& os, const\
    \ unordered_set<T>& s) {\n    os << '{';\n    for (auto itr = s.begin(); itr !=\
    \ s.end();) {\n        os << *itr;\n        if (++itr != s.end()) os << ',';\n\
    \    }\n    os << '}';\n    return os;\n}\ntemplate <typename T> ostream& operator<<(ostream&\
    \ os, const deque<T>& v) {\n    for (int i = 0; i < (int)v.size(); i++) {\n  \
    \      os << v[i] << (i + 1 == (int)v.size() ? \"\" : \" \");\n    }\n    return\
    \ os;\n}\n\ntemplate <int i, typename T> void print_tuple(ostream&, const T&)\
    \ {}\ntemplate <int i, typename T, typename H, class... Args> void print_tuple(ostream&\
    \ os, const T& t) {\n    if (i) os << ',';\n    os << get<i>(t);\n    print_tuple<i\
    \ + 1, T, Args...>(os, t);\n}\ntemplate <typename... Args> ostream& operator<<(ostream&\
    \ os, const tuple<Args...>& t) {\n    os << '{';\n    print_tuple<0, tuple<Args...>,\
    \ Args...>(os, t);\n    return os << '}';\n}\n\nvoid debug_out() { cerr << '\\\
    n'; }\ntemplate <class Head, class... Tail> void debug_out(Head&& head, Tail&&...\
    \ tail) {\n    cerr << head;\n    if (sizeof...(Tail) > 0) cerr << \", \";\n \
    \   debug_out(move(tail)...);\n}\n#ifdef LOCAL\n#define debug(...)           \
    \                                                        \\\n    cerr << \" \"\
    ;                                                                     \\\n   \
    \ cerr << #__VA_ARGS__ << \" :[\" << __LINE__ << \":\" << __FUNCTION__ << \"]\"\
    \ << '\\n'; \\\n    cerr << \" \";                                           \
    \                          \\\n    debug_out(__VA_ARGS__)\n#else\n#define debug(...)\
    \ 42\n#endif\n\ntemplate <typename T> T gcd(T x, T y) { return y != 0 ? gcd(y,\
    \ x % y) : x; }\ntemplate <typename T> T lcm(T x, T y) { return x / gcd(x, y)\
    \ * y; }\n\nint topbit(signed t) { return t == 0 ? -1 : 31 - __builtin_clz(t);\
    \ }\nint topbit(long long t) { return t == 0 ? -1 : 63 - __builtin_clzll(t); }\n\
    int botbit(signed a) { return a == 0 ? 32 : __builtin_ctz(a); }\nint botbit(long\
    \ long a) { return a == 0 ? 64 : __builtin_ctzll(a); }\nint popcount(signed t)\
    \ { return __builtin_popcount(t); }\nint popcount(long long t) { return __builtin_popcountll(t);\
    \ }\nbool ispow2(int i) { return i && (i & -i) == i; }\n\ntemplate <class T> T\
    \ ceil(T x, T y) {\n    assert(y >= 1);\n    return (x > 0 ? (x + y - 1) / y :\
    \ x / y);\n}\ntemplate <class T> T floor(T x, T y) {\n    assert(y >= 1);\n  \
    \  return (x > 0 ? x / y : (x - y + 1) / y);\n}\n\ntemplate <class T1, class T2>\
    \ inline bool chmin(T1& a, T2 b) {\n    if (a > b) {\n        a = b;\n       \
    \ return true;\n    }\n    return false;\n}\ntemplate <class T1, class T2> inline\
    \ bool chmax(T1& a, T2 b) {\n    if (a < b) {\n        a = b;\n        return\
    \ true;\n    }\n    return false;\n}\n#pragma endregion\n#line 6 \"graph/BlockCutTree.hpp\"\
    \n\nstruct BlockCutTree {\n    std::vector<std::vector<std::pair<int, int>>> G;\n\
    \    std::vector<std::vector<int>> tecc_tree,    // tree that consists of two-edge-connected-component\n\
    \        bct;                                    // tree that consists of bi-connected-component\
    \ and articulation\n    std::vector<bool> is_articulation,          // whether\
    \ vertex i is articulation or not\n        is_bridge;                        \
    \      // whether edge i is bridge or not\n    std::vector<int> tecc_id;     \
    \              // id of two-edge-connected-component vertex i belongs to\n   \
    \ std::vector<std::vector<int>> tecc_groups;  // vertices belongs to i-th two-edge-connected-component\n\
    \    std::vector<int> bcc_id;                    // id of bi-connected-component\
    \ edge i belongs to\n    std::vector<std::vector<std::pair<int, int>>> bcc_groups;\
    \  // edges belongs to i-th bi-connected-component\n    std::vector<int> bct_id;\
    \  // id of component on block-cut-tree vertex i belongs to (order : bcc -> articulation)\n\
    \    std::vector<std::vector<int>> bct_groups;  // vertices belongs to i-th component\
    \ on block-cut-tree\n\n    BlockCutTree(int n)\n        : G(n), is_articulation(n,\
    \ false), n(n), m(0), time(0), bcc_num(0), order(n, -1), lowlink(n, -1) {}\n\n\
    \    void add_edge(int u, int v) {\n        assert(0 <= u && u < n);\n       \
    \ assert(0 <= v && v < n);\n        G[u].emplace_back(v, m);\n        G[v].emplace_back(u,\
    \ m);\n        if (u > v) std::swap(u, v);\n        edges.emplace_back(u, v);\n\
    \        is_bridge.emplace_back(false);\n        is_dfstree_edge.emplace_back(false);\n\
    \        bcc_id.emplace_back(-1);\n        m++;\n    }\n\n    void build() {\n\
    \        called_build = true;\n        for (int i = 0; i < n; i++) {\n       \
    \     if (order[i] == -1) {\n                dfs_lowlink(i);\n            }\n\
    \        }\n        for (int i = 0; i < m; i++) {\n            int u = edges[i].first,\
    \ v = edges[i].second;\n            if (order[u] > order[v]) std::swap(u, v);\n\
    \            if (order[u] < lowlink[v]) is_bridge[i] = true;\n        }\n    }\n\
    \n    std::vector<std::vector<int>> two_edge_connected_components() {\n      \
    \  assert(called_build);\n        called_two_connected_components = true;\n  \
    \      tecc_num = 0;\n        tecc_id.assign(n, -1);\n        for (int i = 0;\
    \ i < n; i++) {\n            if (tecc_id[i] >= 0) continue;\n            tecc_id[i]\
    \ = tecc_num;\n            std::queue<int> que;\n            que.emplace(i);\n\
    \            while (!que.empty()) {\n                int v = que.front();\n  \
    \              que.pop();\n                for (const auto& e : G[v]) {\n    \
    \                int u = e.first;\n                    if (tecc_id[u] >= 0 ||\
    \ is_bridge[e.second]) continue;\n                    tecc_id[u] = tecc_num;\n\
    \                    que.emplace(u);\n                }\n            }\n     \
    \       tecc_num++;\n        }\n        tecc_groups.resize(tecc_num);\n      \
    \  for (int i = 0; i < n; i++) tecc_groups[tecc_id[i]].emplace_back(i);\n    \
    \    return tecc_groups;\n    }\n\n    std::vector<std::vector<int>> tecc_make_tree()\
    \ {\n        assert(called_two_connected_components);\n        tecc_tree.resize(tecc_num);\n\
    \        for (int i = 0; i < m; i++) {\n            if (!is_bridge[i]) continue;\n\
    \            int u = tecc_id[edges[i].first], v = tecc_id[edges[i].second];\n\
    \            tecc_tree[u].emplace_back(v);\n            tecc_tree[v].emplace_back(u);\n\
    \        }\n        return tecc_tree;\n    }\n\n    std::vector<std::vector<std::pair<int,\
    \ int>>> bi_connected_components() {\n        assert(called_build);\n        called_bi_connected_components\
    \ = true;\n        bcc_groups.resize(bcc_num);\n        for (int i = 0; i < m;\
    \ i++) bcc_groups[bcc_id[i]].emplace_back(edges[i]);\n        return bcc_groups;\n\
    \    }\n\n    std::vector<std::vector<int>> block_cut_tree() {\n        assert(called_bi_connected_components);\n\
    \        int bct_num = bcc_num;\n        for (int i = 0; i < n; i++) {\n     \
    \       if (is_articulation[i]) {\n                bct_id[i] = bct_num++;\n  \
    \          }\n        }\n        bct.resize(bct_num);\n        std::vector<int>\
    \ last_adjacent(bct_num, -1);\n        for (int i = 0; i < bcc_num; i++) {\n \
    \           for (auto& e : bcc_groups[i]) {\n                for (auto& v : {e.first,\
    \ e.second}) {\n                    if (is_articulation[v]) {\n              \
    \          if (std::exchange(last_adjacent[bct_id[v]], i) != i) {\n          \
    \                  bct[i].emplace_back(bct_id[v]);\n                         \
    \   bct[bct_id[v]].emplace_back(i);\n                        }\n             \
    \       } else\n                        bct_id[v] = i;\n                }\n  \
    \          }\n        }\n        return bct;\n    }\n\nprivate:\n    int n, m,\
    \ time, tecc_num, bcc_num;\n    bool called_build, called_two_connected_components,\
    \ called_bi_connected_components;\n    std::vector<std::pair<int, int>> edges;\n\
    \    std::vector<int> order;             // visiting order of dfs-tree\n    std::vector<int>\
    \ lowlink;           // min of order of u which can be visited from v by using\
    \ dfs-tree edge any\n                                        // times and back\
    \ edge at most once\n    std::vector<bool> is_dfstree_edge;  // whether edge is\
    \ used in dfs-tree or not\n\n    std::vector<int> edge_stack;\n\n    void dfs_lowlink(int\
    \ v, int pre_eid = -1) {\n        order[v] = lowlink[v] = time++;\n        for\
    \ (const auto& e : G[v]) {\n            int u = e.first;\n            if (e.second\
    \ != pre_eid) {\n                if (order[u] < order[v]) edge_stack.emplace_back(e.second);\n\
    \                if (order[u] >= 0)\n                    lowlink[v] = std::min(lowlink[v],\
    \ order[u]);\n                else {\n                    is_dfstree_edge[e.second]\
    \ = true;\n                    dfs_lowlink(u, e.second);\n                   \
    \ lowlink[v] = std::min(lowlink[v], lowlink[u]);\n                    if (pre_eid\
    \ == -1 && order[u] != order[v] + 1) is_articulation[v] = true;\n            \
    \        if (pre_eid != -1 && order[v] <= lowlink[u]) is_articulation[v] = true;\n\
    \                    if (order[v] <= lowlink[u]) {\n                        while\
    \ (true) {\n                            int cur = edge_stack.back();\n       \
    \                     edge_stack.pop_back();\n                            bcc_id[cur]\
    \ = bcc_num;\n                            if (edges[cur] == edges[e.second]) break;\n\
    \                        }\n                        bcc_num++;\n             \
    \       }\n                }\n            }\n        }\n    }\n};\n\n/**\n * @brief\
    \ Block Cut Tree (with Lowlink, Two Edge Connected Components, Bi Connected Components)\n\
    \ * @docs docs/graph/BlockCutTree.md\n */\n#line 5 \"test/yosupo/two_edge_connected_components.test.cpp\"\
    \n\nint main() {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    int N,\
    \ M;\n    cin >> N >> M;\n\n    BlockCutTree BCT(N);\n    for (; M--;) {\n   \
    \     int a, b;\n        cin >> a >> b;\n        BCT.add_edge(a, b);\n    }\n\n\
    \    BCT.build();\n    auto ans = BCT.two_edge_connected_components();\n    cout\
    \ << ans.size() << '\\n';\n    for (auto& v : ans) {\n        cout << v.size();\n\
    \        for (int& x : v) cout << ' ' << x;\n        cout << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/two_edge_connected_components\"\
    \n\n#include \"../../base.hpp\"\n#include \"../../graph/BlockCutTree.hpp\"\n\n\
    int main() {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    int N, M;\n\
    \    cin >> N >> M;\n\n    BlockCutTree BCT(N);\n    for (; M--;) {\n        int\
    \ a, b;\n        cin >> a >> b;\n        BCT.add_edge(a, b);\n    }\n\n    BCT.build();\n\
    \    auto ans = BCT.two_edge_connected_components();\n    cout << ans.size() <<\
    \ '\\n';\n    for (auto& v : ans) {\n        cout << v.size();\n        for (int&\
    \ x : v) cout << ' ' << x;\n        cout << '\\n';\n    }\n}"
  dependsOn:
  - base.hpp
  - graph/BlockCutTree.hpp
  isVerificationFile: true
  path: test/yosupo/two_edge_connected_components.test.cpp
  requiredBy: []
  timestamp: '2021-10-04 21:58:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/two_edge_connected_components.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/two_edge_connected_components.test.cpp
- /verify/test/yosupo/two_edge_connected_components.test.cpp.html
title: test/yosupo/two_edge_connected_components.test.cpp
---
