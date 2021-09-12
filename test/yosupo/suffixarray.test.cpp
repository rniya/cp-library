#define PROBLEM "https://judge.yosupo.jp/problem/suffixarray"

#include "../../string/SuffixArray.hpp"
#include "../../base.hpp"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    cin >> S;

    auto ans = SuffixArray::suffix_array(S);
    for (size_t i = 0; i < ans.size(); i++) cout << ans[i] << (i + 1 == ans.size() ? '\n' : ' ');
}