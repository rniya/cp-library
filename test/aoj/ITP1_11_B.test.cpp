#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ITP1_11_B"

#include "base.hpp"
#include "util/Dice.hpp"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    vector<int> v(6);
    for (int i = 0; i < 6; i++) cin >> v[i];

    Dice d(v);
    auto ds = d.make_all();
    map<pair<int, int>, int> mp;
    for (auto& x : ds) mp[{x.top(), x.front()}] = x.right();

    int q;
    cin >> q;
    for (; q--;) {
        int t, f;
        cin >> t >> f;
        cout << mp[{t, f}] << '\n';
    }
    return 0;
}