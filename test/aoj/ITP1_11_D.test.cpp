#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ITP1_11_D"

#include "../../base.hpp"
#include "../../util/Dice.hpp"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    size_t n;
    cin >> n;
    set<Dice> s;
    vector<int> v(6);
    for (size_t i = 0; i < n; i++) {
        for (int j = 0; j < 6; j++) cin >> v[j];
        Dice d(v);
        s.emplace(d.identifier());
    }
    cout << (s.size() == n ? "Yes" : "No") << '\n';
    return 0;
}