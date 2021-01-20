#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_B"

#include "../../base.hpp"
#include "../../string/RollingHash.hpp"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S, T;
    cin >> S >> T;

    uint64_t base = RollingHash::generate_base();
    RollingHash RH1(S, base), RH2(T, base);
    int s = S.size(), t = T.size();

    for (int i = 0; i + t <= s; i++) {
        if (RH1.query(i, i + t) == RH2.query(0, t)) {
            cout << i << '\n';
        }
    }
}