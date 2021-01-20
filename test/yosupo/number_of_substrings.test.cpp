#define PROBLEM "https://judge.yosupo.jp/problem/number_of_substrings"

#include "../../base.hpp"
#include "../../string/LongestCommonPrefixArray.hpp"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    cin >> S;
    int N = S.size();

    LongestCommonPrefixArray LCP(S);

    long long ans = 0;
    for (int i = 0; i < N; i++) {
        ans += N - LCP.SA[i + 1] - LCP[i];
    }

    cout << ans << '\n';
}