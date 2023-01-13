#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"

#include "base.hpp"
#include "string/Z_Algorithm.hpp"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    cin >> S;
    vector<int> ans = Z_Algorithm(S);

    for (int i = 0; i < ans.size(); i++) cout << ans[i] << (i + 1 == ans.size() ? '\n' : ' ');
}