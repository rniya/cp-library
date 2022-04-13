#pragma once
#include <string>
#include <vector>

std::vector<int> Manacher(const std::string& s) {
    int n = s.size();
    std::vector<int> res(n);
    for (int i = 0, j = 0; i < n;) {
        while (i - j >= 0 and i + j < n and s[i - j] == s[i + j]) j++;
        res[i] = j;
        int k = 1;
        while (i - k >= 0 and i + k < n and k + res[i - k] < j) res[i + k] = res[i - k], k++;
        i += k;
        j -= k;
    }
    return res;
}

std::vector<int> PalindromeTable(const std::string& s) {
    int n = s.size();
    std::string t(n * 2 + 1, '$');
    for (int i = 0; i < n; i++) t[i * 2 + 1] = s[i];
    std::vector<int> v = Manacher(t), res;
    for (int i = 1; i < n * 2; i++) res.emplace_back(v[i] - 1);
    return res;
}
