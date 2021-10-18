#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ITP1_11_A"

#include "../../base.hpp"
#include "../../util/Dice.hpp"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    vector<int> v(6);
    for (int& x : v) cin >> x;
    Dice d(v);
    string S;
    cin >> S;
    for (char& c : S) d.rollc(c);
    cout << d.top() << '\n';
    return 0;
}