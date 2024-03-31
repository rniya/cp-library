---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/maxflow:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include <fstream>\n#include \"atcoder/maxflow\"\n#include\
    \ \"atcoder/mincostflow\"\n\nnamespace atcoder {\n\ntemplate <class Cap> void\
    \ dump_graphviz(mf_graph<Cap> graph, std::string filename = \"maxflow\") {\n \
    \   std::ofstream ofs(filename + \".dot\");\n    ofs << \"digraph {\\n\";\n  \
    \  auto edges = graph.edges();\n    for (const auto& e : edges) {\n        ofs\
    \ << e.from << \" -> \" << e.to << \" [label = \\\"\" << e.flow << \"/\" << e.cap\
    \ << \"\\\", color = \"\n            << (e.flow == e.cap ? \"red\"\n         \
    \       : e.flow > 0    ? \"blue\"\n                                : \"black\"\
    )\n            << \"];\\n\";\n    }\n    ofs << \"}\\n\";\n    ofs.close();\n\
    \    return;\n}\n\ntemplate <class Cap, class Cost> void dump_graphviz(mcf_graph<Cap,\
    \ Cost> graph, std::string filename = \"mincostflow\") {\n    std::ofstream ofs(filename\
    \ + \".dot\");\n    ofs << \"digraph {\\n\";\n    auto edges = graph.edges();\n\
    \    for (const auto& e : edges) {\n        ofs << e.from << \" -> \" << e.to\
    \ << \" [label = \\\"\" << e.flow << \"/\" << e.cap << \"(\" << e.flow << \"*\"\
    \ << e.cost\n            << \")\"\n            << \"\\\", color = \"\n       \
    \     << (e.flow == e.cap ? \"red\"\n                : e.flow > 0    ? \"blue\"\
    \n                                : \"black\")\n            << \"];\\n\";\n  \
    \  }\n    ofs << \"}\\n\";\n    ofs.close();\n    return;\n}\n\n}  // namespace\
    \ atcoder\n"
  dependsOn: []
  isVerificationFile: false
  path: src/util/flow_graphviz.hpp
  requiredBy: []
  timestamp: '2023-01-12 23:01:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/util/flow_graphviz.hpp
layout: document
title: "\u6700\u5927\u6D41\u30FB\u6700\u5C0F\u8CBB\u7528\u6D41\u306E\u56F3\u793A"
---
