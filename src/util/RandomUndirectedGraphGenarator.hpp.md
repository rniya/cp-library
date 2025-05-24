---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: src/util/RandomNumberGenerator.hpp
    title: Random Number Generator
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/util/RandomUndirectedGraphGenarator.hpp\"\n#include\
    \ <iostream>\n#line 2 \"src/util/RandomNumberGenerator.hpp\"\n#include <chrono>\n\
    #include <random>\n#include <utility>\n#include <vector>\n\nstruct RandomNumberGenerator\
    \ {\n    std::mt19937 mt;\n\n    RandomNumberGenerator() : mt(std::chrono::steady_clock::now().time_since_epoch().count())\
    \ {}\n\n    uint32_t operator()(uint32_t a, uint32_t b) {\n        std::uniform_int_distribution<uint32_t>\
    \ dist(a, b - 1);\n        return dist(mt);\n    }\n\n    uint32_t operator()(uint32_t\
    \ b) { return (*this)(0, b); }\n\n    template <typename T> void shuffle(std::vector<T>&\
    \ v) {\n        for (int i = 0; i < int(v.size()); i++) std::swap(v[i], v[(*this)(0,\
    \ i + 1)]);\n    }\n};\n\nstruct RandomNumberGenerator64 {\n    std::mt19937_64\
    \ mt;\n\n    RandomNumberGenerator64() : mt(std::chrono::steady_clock::now().time_since_epoch().count())\
    \ {}\n\n    uint64_t operator()(uint64_t a, uint64_t b) {\n        std::uniform_int_distribution<uint64_t>\
    \ dist(a, b - 1);\n        return dist(mt);\n    }\n\n    uint64_t operator()(uint64_t\
    \ b) { return (*this)(0, b); }\n\n    template <typename T> void shuffle(std::vector<T>&\
    \ v) {\n        for (int i = 0; i < int(v.size()); i++) std::swap(v[i], v[(*this)(0,\
    \ i + 1)]);\n    }\n};\n#line 3 \"src/util/RandomUndirectedGraphGenarator.hpp\"\
    \n\ntemplate <typename T> struct Edge {\n    int u, v;\n    T w;\n    Edge(int\
    \ u, int v, T w = 1) : u(u), v(v), w(w) {}\n};\n\ntemplate <typename T> struct\
    \ Graph {\n    int n, m;\n    std::vector<Edge<T>> es;\n    bool weighted;\n\n\
    \    Graph(int n, bool weighted = false) : n(n), m(0), weighted(weighted) {}\n\
    \n    void print_as_tree(std::ostream& os, bool origin_zero = false) const {\n\
    \        os << n << \"\\n\";\n        print_edges(os, origin_zero);\n    }\n\n\
    \    void print(std::ostream& os, bool origin_zero = false) const {\n        os\
    \ << n << \" \" << m << \"\\n\";\n        print_edges(os, origin_zero);\n    }\n\
    \n    friend std::ostream& operator<<(std::ostream& os, const Graph& g) {\n  \
    \      g.print_as_tree(os);\n        return os;\n    }\n\n    void add_edge(int\
    \ u, int v, T w = 1) {\n        assert(0 <= u and u < n);\n        assert(0 <=\
    \ v and v < n);\n        es.emplace_back(u, v, w);\n        m++;\n    }\n\n  private:\n\
    \    void print_edges(std::ostream& os, bool origin_zero = false) const {\n  \
    \      for (const auto& e : es) {\n            os << e.u + (origin_zero ? 0 :\
    \ 1) << \" \" << e.v + (origin_zero ? 0 : 1);\n            if (weighted) {\n \
    \               os << \" \" << e.w;\n            }\n            os << \"\\n\"\
    ;\n        }\n    }\n};\n\ntemplate <typename T> struct RandomUndirectedGraphGenerator\
    \ {\n    Graph<T> tree(int n, bool weighted = false, T _w_min = 1, T _w_max =\
    \ 1) {\n        set_weight(weighted, _w_min, _w_max);\n        Graph<T> G(n, weighted);\n\
    \        if (n == 2) {\n            add_edge(G, 0, 1);\n        }\n        if\
    \ (n <= 2) {\n            return G;\n        }\n        std::vector<int> prufer(n\
    \ - 2), deg(n, 1);\n        for (auto& y : prufer) {\n            y = rng(n);\n\
    \            deg[y]++;\n        }\n        std::set<int> leaves;\n        for\
    \ (int i = 0; i < n; i++) {\n            if (deg[i] == 1) {\n                leaves.emplace(i);\n\
    \            }\n        }\n        for (auto& y : prufer) {\n            int x\
    \ = *leaves.begin();\n            add_edge(G, x, y);\n            leaves.erase(leaves.begin());\n\
    \            if (--deg[y] == 1) {\n                leaves.emplace(y);\n      \
    \      }\n        }\n        int u = *leaves.begin(), v = *next(leaves.begin());\n\
    \        add_edge(G, u, v);\n        return G;\n    }\n\n    Graph<T> path(int\
    \ n, bool weighted = false, T _w_min = 1, T _w_max = 1) {\n        set_weight(weighted,\
    \ _w_min, _w_max);\n        Graph<T> G(n, weighted);\n        std::vector<int>\
    \ ord(n);\n        std::iota(ord.begin(), ord.end(), 0);\n        rng.shuffle(ord);\n\
    \        for (int i = 0; i < n - 1; i++) {\n            add_edge(G, ord[i], ord[i\
    \ + 1]);\n        }\n        return G;\n    }\n\n    Graph<T> star(int n, bool\
    \ weighted = false, T _w_min = 1, T _w_max = 1) {\n        set_weight(weighted,\
    \ _w_min, _w_max);\n        Graph<T> G(n, weighted);\n        int center = rng(n);\n\
    \        for (int i = 0; i < n; i++) {\n            if (i != center) {\n     \
    \           add_edge(G, center, i);\n            }\n        }\n        return\
    \ G;\n    }\n\n    Graph<T> perfect(int n, bool weighted = false, T _w_min = 1,\
    \ T _w_max = 1) {\n        set_weight(weighted, _w_min, _w_max);\n        Graph<T>\
    \ G(n, weighted);\n        for (int i = 0; i < n; i++) {\n            for (int\
    \ j = i + 1; j < n; j++) {\n                add_edge(G, i, j);\n            }\n\
    \        }\n        return G;\n    }\n\n    Graph<T> simple(int n, bool weighted\
    \ = false, T _w_min = 1, T _w_max = 1) {\n        set_weight(weighted, _w_min,\
    \ _w_max);\n        Graph<T> G(n, weighted);\n        for (int i = 0; i < n; i++)\
    \ {\n            for (int j = i + 1; j < n; j++) {\n                if (rng(2))\
    \ {\n                    add_edge(G, i, j);\n                }\n            }\n\
    \        }\n        return G;\n    }\n\n  private:\n    T w_min, w_max;\n    RandomNumberGenerator64\
    \ rng;\n\n    void set_weight(bool weighted, T _w_min, T _w_max) {\n        assert(0\
    \ <= _w_min and _w_min <= _w_max);\n        if (weighted) {\n            w_min\
    \ = _w_min;\n            w_max = _w_max;\n        } else {\n            w_min\
    \ = w_max = 1;\n        }\n    }\n\n    void add_edge(Graph<T>& G, int u, int\
    \ v) {\n        T w = (w_min == w_max ? w_min : rng(w_min, w_max + 1));\n    \
    \    G.add_edge(u, v, w);\n    }\n};\n"
  code: "#include <iostream>\n#include \"RandomNumberGenerator.hpp\"\n\ntemplate <typename\
    \ T> struct Edge {\n    int u, v;\n    T w;\n    Edge(int u, int v, T w = 1) :\
    \ u(u), v(v), w(w) {}\n};\n\ntemplate <typename T> struct Graph {\n    int n,\
    \ m;\n    std::vector<Edge<T>> es;\n    bool weighted;\n\n    Graph(int n, bool\
    \ weighted = false) : n(n), m(0), weighted(weighted) {}\n\n    void print_as_tree(std::ostream&\
    \ os, bool origin_zero = false) const {\n        os << n << \"\\n\";\n       \
    \ print_edges(os, origin_zero);\n    }\n\n    void print(std::ostream& os, bool\
    \ origin_zero = false) const {\n        os << n << \" \" << m << \"\\n\";\n  \
    \      print_edges(os, origin_zero);\n    }\n\n    friend std::ostream& operator<<(std::ostream&\
    \ os, const Graph& g) {\n        g.print_as_tree(os);\n        return os;\n  \
    \  }\n\n    void add_edge(int u, int v, T w = 1) {\n        assert(0 <= u and\
    \ u < n);\n        assert(0 <= v and v < n);\n        es.emplace_back(u, v, w);\n\
    \        m++;\n    }\n\n  private:\n    void print_edges(std::ostream& os, bool\
    \ origin_zero = false) const {\n        for (const auto& e : es) {\n         \
    \   os << e.u + (origin_zero ? 0 : 1) << \" \" << e.v + (origin_zero ? 0 : 1);\n\
    \            if (weighted) {\n                os << \" \" << e.w;\n          \
    \  }\n            os << \"\\n\";\n        }\n    }\n};\n\ntemplate <typename T>\
    \ struct RandomUndirectedGraphGenerator {\n    Graph<T> tree(int n, bool weighted\
    \ = false, T _w_min = 1, T _w_max = 1) {\n        set_weight(weighted, _w_min,\
    \ _w_max);\n        Graph<T> G(n, weighted);\n        if (n == 2) {\n        \
    \    add_edge(G, 0, 1);\n        }\n        if (n <= 2) {\n            return\
    \ G;\n        }\n        std::vector<int> prufer(n - 2), deg(n, 1);\n        for\
    \ (auto& y : prufer) {\n            y = rng(n);\n            deg[y]++;\n     \
    \   }\n        std::set<int> leaves;\n        for (int i = 0; i < n; i++) {\n\
    \            if (deg[i] == 1) {\n                leaves.emplace(i);\n        \
    \    }\n        }\n        for (auto& y : prufer) {\n            int x = *leaves.begin();\n\
    \            add_edge(G, x, y);\n            leaves.erase(leaves.begin());\n \
    \           if (--deg[y] == 1) {\n                leaves.emplace(y);\n       \
    \     }\n        }\n        int u = *leaves.begin(), v = *next(leaves.begin());\n\
    \        add_edge(G, u, v);\n        return G;\n    }\n\n    Graph<T> path(int\
    \ n, bool weighted = false, T _w_min = 1, T _w_max = 1) {\n        set_weight(weighted,\
    \ _w_min, _w_max);\n        Graph<T> G(n, weighted);\n        std::vector<int>\
    \ ord(n);\n        std::iota(ord.begin(), ord.end(), 0);\n        rng.shuffle(ord);\n\
    \        for (int i = 0; i < n - 1; i++) {\n            add_edge(G, ord[i], ord[i\
    \ + 1]);\n        }\n        return G;\n    }\n\n    Graph<T> star(int n, bool\
    \ weighted = false, T _w_min = 1, T _w_max = 1) {\n        set_weight(weighted,\
    \ _w_min, _w_max);\n        Graph<T> G(n, weighted);\n        int center = rng(n);\n\
    \        for (int i = 0; i < n; i++) {\n            if (i != center) {\n     \
    \           add_edge(G, center, i);\n            }\n        }\n        return\
    \ G;\n    }\n\n    Graph<T> perfect(int n, bool weighted = false, T _w_min = 1,\
    \ T _w_max = 1) {\n        set_weight(weighted, _w_min, _w_max);\n        Graph<T>\
    \ G(n, weighted);\n        for (int i = 0; i < n; i++) {\n            for (int\
    \ j = i + 1; j < n; j++) {\n                add_edge(G, i, j);\n            }\n\
    \        }\n        return G;\n    }\n\n    Graph<T> simple(int n, bool weighted\
    \ = false, T _w_min = 1, T _w_max = 1) {\n        set_weight(weighted, _w_min,\
    \ _w_max);\n        Graph<T> G(n, weighted);\n        for (int i = 0; i < n; i++)\
    \ {\n            for (int j = i + 1; j < n; j++) {\n                if (rng(2))\
    \ {\n                    add_edge(G, i, j);\n                }\n            }\n\
    \        }\n        return G;\n    }\n\n  private:\n    T w_min, w_max;\n    RandomNumberGenerator64\
    \ rng;\n\n    void set_weight(bool weighted, T _w_min, T _w_max) {\n        assert(0\
    \ <= _w_min and _w_min <= _w_max);\n        if (weighted) {\n            w_min\
    \ = _w_min;\n            w_max = _w_max;\n        } else {\n            w_min\
    \ = w_max = 1;\n        }\n    }\n\n    void add_edge(Graph<T>& G, int u, int\
    \ v) {\n        T w = (w_min == w_max ? w_min : rng(w_min, w_max + 1));\n    \
    \    G.add_edge(u, v, w);\n    }\n};"
  dependsOn:
  - src/util/RandomNumberGenerator.hpp
  isVerificationFile: false
  path: src/util/RandomUndirectedGraphGenarator.hpp
  requiredBy: []
  timestamp: '2025-05-24 15:05:59+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/util/RandomUndirectedGraphGenarator.hpp
layout: document
redirect_from:
- /library/src/util/RandomUndirectedGraphGenarator.hpp
- /library/src/util/RandomUndirectedGraphGenarator.hpp.html
title: src/util/RandomUndirectedGraphGenarator.hpp
---
