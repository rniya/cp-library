#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_palindromes"

#include "../../base.hpp"
#include "../../string/Manacher.hpp"

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S; cin >> S;

    vector<int> ans=PalindromeTable(S);
    for (int i=0;i<ans.size();++i) cout << ans[i] << (i+1==ans.size()?'\n':' ');
}