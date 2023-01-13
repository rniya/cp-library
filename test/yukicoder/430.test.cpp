#define PROBLEM "https://yukicoder.me/problems/no/430"

#include "base.hpp"
#include "string/RollingHash.hpp"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    cin >> S;

    RollingHash RH;
    auto v = RH.build(S);
    map<uint64_t, int> mp;
    for (size_t j = 1; j <= 10; j++) {
        for (size_t i = 0; i + j <= S.size(); i++) {
            mp[RH.query(v, i, i + j)]++;
        }
    }

    int M, ans = 0;
    cin >> M;
    for (; M--;) {
        string C;
        cin >> C;
        ans += mp[RH.get(C)];
    }

    cout << ans << '\n';
}