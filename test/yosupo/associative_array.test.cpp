#define PROBLEM "https://judge.yosupo.jp/problem/associative_array"

#include "base.hpp"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int Q;
    cin >> Q;

    map<long long, long long> a;
    for (; Q--;) {
        int t;
        long long k;
        cin >> t >> k;
        if (!t) {
            long long v;
            cin >> v;
            a[k] = v;
        } else
            cout << a[k] << '\n';
    }
}