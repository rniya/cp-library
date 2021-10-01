#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_B"

#include "../../base.hpp"
#include "../../string/RollingHash.hpp"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string T, P;
    cin >> T >> P;

    RollingHash RH;
    auto a = RH.build(T), b = RH.build(P);
    int s = T.size(), t = P.size();

    for (int i = 0; i + t <= s; i++) {
        if (RH.query(a, i, i + t) == RH.query(b, 0, t)) {
            cout << i << '\n';
        }
    }
    return 0;
}