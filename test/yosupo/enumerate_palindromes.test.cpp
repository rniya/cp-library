#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_palindromes"

#include <iostream>
#include "string/Manacher.hpp"

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    std::string S;
    std::cin >> S;

    std::vector<int> ans = PalindromeTable(S);
    for (int i = 0; i < ans.size(); i++) std::cout << ans[i] << (i + 1 == ans.size() ? '\n' : ' ');
}