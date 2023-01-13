#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ITP1_11_C"

#include "base.hpp"
#include "util/Dice.hpp"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    vector<int> u(6), v(6);
    for (int i = 0; i < 6; i++) cin >> u[i];
    for (int i = 0; i < 6; i++) cin >> v[i];

    Dice d1(u), d2(v);
    cout << (d1.identifier() == d2.identifier() ? "Yes" : "No") << '\n';
    return 0;
}