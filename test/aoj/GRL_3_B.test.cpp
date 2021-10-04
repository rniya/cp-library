#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_B"

#include "../../base.hpp"
#include "../../graph/BlockCutTree.hpp"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int V, E;
    cin >> V >> E;

    BlockCutTree BCT(V);
    vector<int> s(E), t(E);
    for (int i = 0; i < E; i++) {
        cin >> s[i] >> t[i];
        if (s[i] > t[i]) swap(s[i], t[i]);
        BCT.add_edge(s[i], t[i]);
    }

    BCT.build();
    vector<pair<int, int>> ans;
    for (int i = 0; i < E; i++) {
        if (BCT.is_bridge[i]) {
            ans.emplace_back(s[i], t[i]);
        }
    }
    sort(ans.begin(), ans.end());
    for (auto& e : ans) cout << e.first << ' ' << e.second << '\n';
    return 0;
}