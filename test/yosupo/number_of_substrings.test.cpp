#define PROBLEM "https://judge.yosupo.jp/problem/number_of_substrings"

#include "../../base.hpp"
#include "../../string/SuffixArray.hpp"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    cin >> S;

    int N = S.size();
    auto sa = SuffixArray::suffix_array(S);
    auto lcp = SuffixArray::lcp_array(S, sa);
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        ans += N - sa[i];
        if (i < N - 1) ans -= lcp[i];
    }

    cout << ans << '\n';
    return 0;
}