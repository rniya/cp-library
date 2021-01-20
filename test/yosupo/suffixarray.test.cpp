#define PROBLEM "https://judge.yosupo.jp/problem/suffixarray"

#include "../../base.hpp"
#include "../../string/SuffixArray.hpp"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    cin >> S;

    SuffixArray SA(S);

    for (int i = 0; i < S.size(); i++) cout << SA[i + 1] << (i + 1 == S.size() ? '\n' : ' ');
}