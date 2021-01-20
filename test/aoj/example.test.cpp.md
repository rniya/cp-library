---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/4/ALDS1_4_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/4/ALDS1_4_B
  bundledCode: "#line 1 \"test/aoj/example.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/4/ALDS1_4_B\"\
    \n#include <algorithm>\n#include <iostream>\n#include <vector>\n#define REP(i,\
    \ n) for (int i = 0; (i) < (int)(n); ++(i))\n#define ALL(x) std::begin(x), std::end(x)\n\
    using namespace std;\n\nint main() {\n    int n;\n    cin >> n;\n    vector<int>\
    \ s(n);\n    REP(i, n) { cin >> s[i]; }\n    int q;\n    cin >> q;\n    int cnt\
    \ = 0;\n    while (q--) {\n        int t_i;\n        cin >> t_i;\n        cnt\
    \ += binary_search(ALL(s), t_i);\n    }\n    cout << cnt << endl;\n    return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/4/ALDS1_4_B\"\
    \n#include <algorithm>\n#include <iostream>\n#include <vector>\n#define REP(i,\
    \ n) for (int i = 0; (i) < (int)(n); ++(i))\n#define ALL(x) std::begin(x), std::end(x)\n\
    using namespace std;\n\nint main() {\n    int n;\n    cin >> n;\n    vector<int>\
    \ s(n);\n    REP(i, n) { cin >> s[i]; }\n    int q;\n    cin >> q;\n    int cnt\
    \ = 0;\n    while (q--) {\n        int t_i;\n        cin >> t_i;\n        cnt\
    \ += binary_search(ALL(s), t_i);\n    }\n    cout << cnt << endl;\n    return\
    \ 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/aoj/example.test.cpp
  requiredBy: []
  timestamp: '2021-01-20 11:24:35+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/example.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/example.test.cpp
- /verify/test/aoj/example.test.cpp.html
title: test/aoj/example.test.cpp
---