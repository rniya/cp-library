#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/2885"

#include "../../base.hpp"
#include "../../graph/BipartiteGraph.hpp"

void solve(int N, int M) {
    BipartiteGraph BG(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        BG.add_edge(--u, --v);
    }
    if (!BG.build()) {
        cout << 0 << '\n';
        return;
    }
    vector<int> cnt(2, 0);
    for (int i = 0; i < N; i++) cnt[BG[i]]++;

    vector<int> ans;
    for (int i = 0; i < 2; i++) {
        if (i && cnt[1] == cnt[0]) continue;
        if (!(cnt[i] & 1)) {
            ans.emplace_back(cnt[i] / 2);
        }
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << '\n';
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, M;
    while (cin >> N >> M, N) {
        solve(N, M);
    }
}