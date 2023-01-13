#define PROBLEM "https://yukicoder.me/problems/no/430"

#include "base.hpp"
#include "string/AhoCorasick.hpp"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    int M;
    cin >> S >> M;

    AhoCorasick<26, 'A'> AHO;
    for (; M--;) {
        string C;
        cin >> C;
        AHO.add(C);
    }
    AHO.build();

    cout << AHO.match(S) << '\n';
}