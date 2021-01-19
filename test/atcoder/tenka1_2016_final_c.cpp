#define IGNORE

#define PROBLEM "https://atcoder.jp/contests/tenka1-2016-final-open/tasks/tenka1_2016_final_c"

#include "../../base.hpp"
#include "../../string/Trie.hpp"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    int M;
    cin >> S >> M;
    vector<string> P(M);
    vector<int> W(M);
    for (int i = 0; i < M; i++) cin >> P[i];
    for (int i = 0; i < M; i++) cin >> W[i];

    Trie<26> trie([](char c) { return c - 'a'; });
    for (int i = 0; i < M; i++) trie.add(P[i], i);
    int n = S.size();
    vector<int> dp(n + 1, 0);

    for (int i = 0; i < n; i++) {
        dp[i + 1] = max(dp[i + 1], dp[i]);
        auto f = [&](int idx) { dp[i + P[idx].size()] = max(dp[i + P[idx].size()], dp[i] + W[idx]); };
        trie.query(S, f, i);
    }
    cout << dp[n] << '\n';
}